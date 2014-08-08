#ifndef ecRenderLight_H_
#define ecRenderLight_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderLight.h
/// @class EcRenderLight
/// @brief implementation of the EcRenderLight class. Handling OSG
///        lighting.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <visualization/ecLight.h>

#include <osg/MatrixTransform>

/// Forward declarations.
class EcSGWindow;

namespace osg
{
class Group;
class Geode;
class LightSource;
class Material;
}


/** implementation of the EcRenderLight class. Handling OSG lighting.
*/
class EC_RENDER_RENDCORE_DECL EcRenderLight : public osg::MatrixTransform
{
public:
   /// constructor
   EcRenderLight
      (
      const EcLight light,
      const EcU32 lightNumber
      );

   /// destructor
   virtual ~EcRenderLight
      (
      );

   /// Copy constructor.
   /// \param[in] orig   Object to copy
   /// \param[in] copyop Type of copy to perform
   EcRenderLight
      (
      const EcRenderLight& orig,
      const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY
      );

   /// clone an object of the same type as the EcRenderLink.
   virtual osg::Object* cloneType() const { return new EcRenderLight(*this); }

   /// return a clone of a node, with Object* return type.
   virtual osg::Object* clone(const osg::CopyOp& copyop) const { return new EcRenderLight(*this,copyop); }

   /// return true if this and obj are of the same kind of object.
   virtual bool isSameKindAs(const osg::Object* obj) const { return dynamic_cast<const EcRenderLight*>(obj)!=EcNULL; }

   /// get coordinate system transformation
   const EcCoordinateSystemTransformation coordSysXform
      (
       );

   /// set coordinate system transformation
   void setCoordSysXform
      (
      const EcCoordinateSystemTransformation& coordSysXform
      );

   /// get is positional flag
   EcBoolean isPositional
      (
      )const;

   /// set is positional flag
   void setIsPositional
      (
      EcBoolean isPositional
      );

   /// pass the parameters of this light to OSG
   void initializeAndAddToSceneGraph
      (
      EcSGWindow* pWin
      );

   /// returns the openGL light number of this light
   EcU32 lightNumber
      (
      ) const;

   /// returns a non-const pointer to the lightSource created
   osg::LightSource* lightSource
      (
      );

   /// used for shadows
   EcBoolean usedForShadows
     (
     );

   /// returns the EcLight
   const EcLight& light
      (
      );

   /// returns on/off state of light
   EcBoolean isOn
      (
      ) const;

   /// turns the light on or off
   void setIsOn
      (
      EcBoolean isOn
      );

   /// return true if the light marker is visible in the scene
   EcBoolean isMarkerVisible
      (
      );

   /// set show Light marker
   void setIsMarkerVisible
      (
      EcBoolean show
      );

   /// These are needed for proper osgDB serialization.
   const char* className() const { return "EcRenderLight"; }
   const char* libraryName() const { return ""; }

protected:
   EcLight                              m_Light;             ///< Where light parameters come from
   osg::Group*                          m_Root;              ///< The root node where any state attribute callbacks are added
   EcInt32                              m_LightNumber;       ///< Corresponds to an OpenGL light number (0-7)
   osg::ref_ptr<osg::LightSource>       m_pLightSource;      ///< Handle to light placement in scene
   osg::ref_ptr<osg::Geode>             m_pLightMarkerGeode; ///< Visual representation of a light
};

/// Convenient vector of light properties.
typedef std::vector<osg::ref_ptr<EcRenderLight> > EcRenderLightVector;

#endif // ecRenderLight_H_
