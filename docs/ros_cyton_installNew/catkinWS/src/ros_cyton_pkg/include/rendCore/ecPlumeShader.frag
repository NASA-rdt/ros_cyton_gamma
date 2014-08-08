
///////////////////////////////////////////////////////////////////////
// Incoming variables from Vertex Shader.  These change every frame. //
///////////////////////////////////////////////////////////////////////

// Unit vector in eye-space coordinate system from eyepoint to current fragment.
varying vec3 viewVec;

// Unit vector along X-axis transformed into eye-space.
varying vec3 tx;

// Unit vector along Y-axis transformed into eye-space.
varying vec3 ty;

// Unit vector along Z-axis transformed into eye-space.
varying vec3 tz;



///////////////////////////////////////////////////////////////////////////
// Input variables from application.  These are typically only set once. //
///////////////////////////////////////////////////////////////////////////

// 3-D texture used to hold raw volume data.
uniform sampler3D texture0;

// 1-D texture used as a Look-Up Table (LUT) to convert integrated value to
// desired pixel color.
uniform sampler1D texture1;

// 3 element vector giving the number of cells in the volume along each dim.
uniform vec3 texSize;

// Conversion factor used to convert from unit coordinates to real-world
// values.  Used in two places to convert texture rate of change and to
// multiply cell size for proper distance calculation.
uniform vec3 scaleFactor;

// Allows arbitrary scaling of the final result by a common factor to get
// it to fall within a certain output range before using the LUT.
uniform float lutFactor;

// Main body of fragment shader run by GPU
void main
   (
   )
{
   /* The data is rendered as a 6-sided rectangular geometry.  Each face
    * should contain the 3D texture coordinates in the range [0,1].
    */

   /* Algorithm:
    *
    * The inputs that are required for this method are:
    *
    * 1.  gl_TexCoord - represents starting position in eye space.
    * 2.  viewVec     - Normalized vector from eye to location of gl_TexCoord.
    * 3.  tx,ty,tz    - Unit vectors transformed by the modelview matrix.
    * 4.  texture0    - 3D luminance texture holding the cell's data.
    * 5.  texture1    - 1D RGB LUT transforming result to color value.
    * 6.  texSize     - Number of cells in the 3D texture.
    * 7.  scaleFactor - Converts data to the final result.  This restores
    *                   the normalized cell size back into meters.
    * 8.  lutFactor   - Back-end multiplier to get integrated results within
    *                   certain range.
    *
    * The incoming texture coordinate (gl_TexCoord) is the starting point for
    * this method.  It is provided by OpenGL during the rasterization phase.
    * It provides the relative position of the viewing vector along
    * the face of the volume in X,Y and Z in the range [0,1].
    *
    * After getting the initial starting position, the method marches along
    * the view vector through the cells until the last one is reached.  For
    * each cell, the following is calculated:
    * 1.  minTexCoord   - minimum bounding box coordinate for this cell.
    * 2.  maxTexCoord   - maximum bounding box coordinate for this cell.
    * 3.  cellSize      - size of the current cell in a normalized unit.
    * 4.  cellCoordRate - Normalized rate at which the size changes for this
    *                     cell.
    * 5.  boundary      - Per-component Axis-Aligned exit point.  It uses
    *                     the sign of view vector to determine if it is going
    *                     to cross the min or max bound.
    * 6.  perAxisRayDurationToBoundary - Calculates the amount of "time" from
    *                     the current position to the boundary.  The minimum of
    *                     the 3 is the actual boundary that will be reached
    *                     first.
    * 7.  rayDistance   - Minimum distance multiplied by the rate as a vector.
    *
    * The length of rayDistance is the desired component used to multiply by
    * the data value to get the computed result for the current cell.
    *
    * The direction of travel is determined by looking at the per-component
    * boundary values and taking the minimum 'time' with which it takes to reach
    * that position.  We use this direction along with the sign of the view
    * vector to determine if we are incrementing or decrementing the cell
    * coordinates.  This continues until the exit criteria is reached.
    *
    * After completing the loop, the resulting color value should contain the
    * sum of all the traversed cell values each multiplied by their respective
    * penetration lengths.
    */

   // The dot product of the view vector and the texture values gives a normalized
   // vector of the rate at which the texture coordinates change along this ray.
   // Divide by the scaleFactor to convert from eye-space.
   vec3 texCoordRate = normalize(
                                 vec3(
                                      dot(tx, viewVec),
                                      dot(ty, viewVec),
                                      dot(tz, viewVec)
                                     ) / scaleFactor
                                );

   // Initial cell entry point to incoming intersected value
   vec3 cellEnterCoord = gl_TexCoord[0].xyz;

   // Designate which component values are at max value. (would be decreasing)
   vec3 which = vec3(equal(vec3(1.0), cellEnterCoord));

   // Designate which component values have rates which are 0 or increasing.
   // Used in calculating max cell boundary condition.  Make test use >= so
   // that zero values get clamped to max value.  This fixes the boundary
   // check to unattainable values when traveling parallel to an axis.
   // Additional check is used (!which), which removes rare occurence where we
   // intersect the volume along a single point (edge) with a positive rate,
   // but at max value.  This removes those components from causing the
   // algorithm to go astray.
   vec3 cellPositiveOffset = vec3(greaterThanEqual(texCoordRate, vec3(0.0))) *
                             vec3(!bvec3(which));

   // Initialize integration result variable.
   vec3 color = vec3(0.0);

   // Initialize minimum cell boundary based off of starting intersection.
   // Use nearest cell boundary that is smaller than our starting point.
   // For cases where we are going from 1->0 we need to subtract a half cell to
   // get the correct min case.  Use a half cell to avoid subtracting too much.
   vec3 minTexCoord = floor(
                            (cellEnterCoord - which * 0.5 / texSize) *
                            texSize
                           ) / texSize;
   
   // Bypass loop if initial criteria is not met.  If the texcoordrate of the
   // entry point is going in the opposite direction, then we will never
   // finish.  This happens when the viewing vector intersects the volume at an
   // edge or corner - only a single point is ever touched.  Bail out in this
   // case without processing.
   vec3 zero_entry = vec3(equal(vec3(0.0), cellEnterCoord));

   if(any(lessThan(zero_entry * texCoordRate, vec3(0.0))) ||
      any(greaterThan(which * texCoordRate, vec3(0.0))))
   {
      discard;
   }

   // Initialize exit criteria
   bool done = false;

   while(!done)
   {
      // Determine max cell dimension.
      vec3 maxTexCoord = minTexCoord + (1.0 / texSize);

      // Calculate relative size of cell (in unit coords).
      vec3 cellSize = (maxTexCoord - minTexCoord);

      // Calculate the normalized cell texCoord rate.
      vec3 cellCoordRate = normalize(texCoordRate * cellSize);

      // Find the per-component boundary values.  Do this by using the min
      // cell bounds and adding to it according to the view direction as given
      // by cellPositiveOffset.
      vec3 boundary = minTexCoord + cellPositiveOffset * cellSize;

      // Figure out if there are any 0 values.  Used to remove division by 0.
      which = vec3(equal(vec3(0.0), cellCoordRate));

      // Get the per-component "time" to the boundary.  The which variable
      // will be non-zero for entries of 0 value.  This turns the 0 values
      // into a large number, removing the div by zero and as a potential match
      // as the minimum distance to boundary.  Use abs() to ensure a positive
      // result, since it is possible to have a negative value due to roundoff.
      vec3 perAxisRayDurationToBoundary = abs(
                                              (boundary - cellEnterCoord) /
                                              (which * 0.001 + cellCoordRate)
                                             );
      
      // The minimum of the 3 components (closest to 0) is the desired one.
      vec3 rayDuration = vec3(
                              min(perAxisRayDurationToBoundary[0],
                                  min(perAxisRayDurationToBoundary[1],
                                      perAxisRayDurationToBoundary[2]
                                     )
                                 )
                             );

      // Get which component is the direction of boundary crossing.
      which = vec3(equal(rayDuration, perAxisRayDurationToBoundary));

      // Calculate the actual distance traveled (in unit coords).
      vec3 rayDistance = rayDuration * cellCoordRate;

      // Calculate boundary exit point.
      vec3 cellExitCoord = cellEnterCoord + rayDistance;

      // Perform lookup of current cell's value.  Use the halfway point along
      // the ray between start and end.
      vec3 cellValue = texture3D(texture0,
                                 cellEnterCoord + rayDistance / 2.0 ).xyz;
      
      // Calculate final distance traveled - scaled back to normal.
      rayDistance = (cellExitCoord - cellEnterCoord) * scaleFactor;

      // Add this cell's contribution to the running total.
      color += cellValue * length(rayDistance);
      
      // Update entrance point along ray.
      cellEnterCoord = cellExitCoord;

      // Update minimum cell dimension along direction of movement.
      minTexCoord += which * sign(texCoordRate) / texSize;

      // Determine if we have finished with all cells.  Need to be able to
      // handle both transition points (going from 0->1 and from 1->0), so
      // we use the sign function to turn -1 or +1 into 0 or 1.  Look at the
      // axis we have progressed along ('which' variable) only, causing the
      // other components to be 0.
      // For positive rates, this becomes (1 - ~1)
      // For negative rates, this becomes (0 + ~0)
      vec3 value = which * (
                            (sign(texCoordRate) + 1.0) / 2.0 -
                             sign(texCoordRate) * cellExitCoord
                           );

      // Compare it against a cushion of a half cell around exit boundary.
      // If the value in this range or below, then we have finished processing.
      done = all(lessThan(value, 0.5 / texSize));
   }

   // Now that we have finished integrating the value along the ray, we need to
   // represent it back in a usable form.  Map the result to a look-up table
   // for display purposes after scaling by lutFactor.
   gl_FragColor = texture1D(texture1, lutFactor * color.r);
}
