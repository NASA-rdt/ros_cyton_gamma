varying vec3 viewVec;
varying vec3 tx;
varying vec3 ty;
varying vec3 tz;

/* The goal of the vertex shader is to calculate the viewing unit vector
 * between the eyepoint and the vertex.  The vector will be interpolated
 * during rasterization to correspond to the fragment location.
 */
void main()
{
   // Set the default information for the vertex shader
   gl_Position = ftransform();
   gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;
   
   // Calculate the eye-space position of our vertex.
   viewVec = -vec3(gl_ModelViewMatrix * gl_Vertex);
      
   // Save the transformed texture coordinate vector.
   tx = mat3(gl_ModelViewMatrix) * vec3(1.0,0.0,0.0);
   ty = mat3(gl_ModelViewMatrix) * vec3(0.0,1.0,0.0);
   tz = mat3(gl_ModelViewMatrix) * vec3(0.0,0.0,1.0);
}
