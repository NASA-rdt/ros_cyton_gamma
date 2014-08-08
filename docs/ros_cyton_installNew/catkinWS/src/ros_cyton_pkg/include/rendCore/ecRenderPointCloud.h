#ifndef EcRenderPointCloud_H_
#define EcRenderPointCloud_H_
//     Copyright (c) 2009-2013 Energid Technologies. All rights reserved. ////
//
// Filename:    ecRenderPointCloud.h
//
// Description: Point cloud object for 3D rendering in OSG
//
// Contents:    EcRenderPointCloud class
//
/////////////////////////////////////////////////////////////////////////

#include <render/render_config.h>

#include <foundCommon/ecCoordSysXForm.h>
#include <foundCore/ecMacros.h>
#include <foundCore/ecTypes.h>
#include <foundCore/ecVector.h>

#include <osg/Geometry>
#include <osg/Geode>
#include <osg/ref_ptr>

/**
* @brief The EcRenderPointCloud class
* This class provides functionality to render a vector of 3D point locations
* in openSceneGraph
*/
class EC_RENDER_RENDCORE_DECL EcRenderPointCloud
{
public: 

   /// constructor
   EcRenderPointCloud
      (
      );

   /// destructor
   virtual ~EcRenderPointCloud
      (
      );

   /**
   * Sets the visiblity of the point cloud
   * @param[in] isVisible equals true to set visible, false to hide
   */
   virtual void setVisibility
      (
      EcBoolean isVisible
      );

   /**
   * Checks if the point cloud is currently visible
   * @return (EcBoolean) true if the point cloud is currently visible
   */
   virtual EcBoolean isVisible
      (
      ) const;

   /**
   * Adds points to the point cloud
   * @param[in] vector of 3D locations (const std::vector<EcVector>&)
   * @param[in] stride of the sample to be taken, (ie: sample every stride values)
   * @return void
   */
   virtual void addPointsToCloud
      (
      const std::vector<EcVector>& pointVec,
      EcU32 stride = 1
      );

   /**
   * Gets the coordinate system transformation being applied to the point cloud
   * @return EcCoordinateSystemTransformation
   */
   virtual const EcCoordinateSystemTransformation& coordSysXForm
      (
      ) const;

   /**
   * Sets the coordinate system transformation being applied to the point cloud
   * @param[in] coordSysXForm (EcCoordinateSystemTransformation)
   */
   virtual void setCoordSysXForm
      (
      const EcCoordinateSystemTransformation& coordSysXForm
      );

   /**
   * Gets the color of the point cloud
   * @return color (EcVector)
   */
   virtual EcVector color
      (
      ) const;

   /**
   * Sets the color of the point cloud
   * @param[in] color (EcVector)
   */
   virtual void setColor
      (
      const EcVector& color
      );

   /**
   * Gets the size of the point cloud
   * @return size (EcU32) the number of points in the cloud
   */
   virtual EcU32 pointCloudSize
      (
      ) const;

   /**
   * updates the point cloud
   * This must be called after setColor, setCoordSysXForm, or setPointCloud has been called.
   */
   virtual void update
      (
      );

   /**
   * Gets the osg geode for rendering the point cloud
   * @return geode (osg::Geode*)  the geode containing the point cloud
   */
   virtual osg::Geode* geode
      (
      );

protected:
   osg::ref_ptr<osg::Geode>            m_Geode;                  ///< the point cloud geode
   osg::ref_ptr<osg::Geometry>         m_Geometry;               ///< the Geometry
   osg::ref_ptr<osg::Vec3Array>        m_Vertices;               ///< the 3D point locations
   osg::ref_ptr<osg::Vec4Array>        m_Colors;                 ///< the colors
   osg::ref_ptr<osg::DrawArrays>       m_DrawArraysPrimitiveSet; ///< the primitive set for rendering
   EcU32                               m_PointCount;             ///< the current point count
   EcCoordinateSystemTransformation    m_CoordSysXForm;          ///< the coordinate system transformation applied to points
};

#endif // EcRenderPointCloud_H_
