#ifndef ecRenderLink_H_
#define ecRenderLink_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderLink.h
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include "ecRenderTypes.h"

#include <boost/shared_ptr.hpp>
#include <osg/MatrixTransform>

/// Forward declarations.
class EcIndividualManipulator;
class EcLinkKinematics;
class EcManipulatorLink;
class EcRenderManipulator;

class EcDataMap;
template <typename T> class EcXmlBasicType;
typedef EcXmlBasicType<EcString> EcXmlString;
template <typename T1, typename T2> class EcXmlMapType;
typedef EcXmlMapType<EcXmlString,EcDataMap> EcStringDataMapMap;

class EC_RENDER_RENDCORE_DECL EcRenderLink : public osg::MatrixTransform
{
public:
   /// Convenient handle to a reference-counted matrix transformation
   typedef osg::ref_ptr<osg::MatrixTransform> RefTransform;
   /// Used to map joint positions to their render component for updating.
   typedef std::vector<osg::ref_ptr<EcRenderLink> > RenderLinkVector;

   /// Constructor
   /// \param[in] pRenderMan Pointer to base manipulator render geometry
   explicit EcRenderLink
      (
      const EcRenderManipulator* pRenderMan
      );

   /// Constructor
   /// \param[in] link Handle to link that represents this group.
   /// \param[in] manIndex Specify an index to use if referenced
   EcRenderLink
      (
      const EcManipulatorLink& link,
      const EcU32 manIndex = 0xffffffff
      );

   /// Copy constructor.
   /// \param[in] orig   Object to copy
   /// \param[in] copyop Type of copy to perform
   EcRenderLink
      (
      const EcRenderLink& orig,
      const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY
      );

   /** clone an object of the same type as the EcRenderLink.*/
   virtual osg::Object* cloneType() const { return new EcRenderLink(*this); }

   /** return a clone of a node, with Object* return type.*/
   virtual osg::Object* clone(const osg::CopyOp& copyop) const { return new EcRenderLink(*this,copyop); }

   /** return true if this and obj are of the same kind of object.*/
   virtual bool isSameKindAs(const osg::Object* obj) const { return dynamic_cast<const EcRenderLink*>(obj)!=EcNULL; }

   /// Return handle to link.
   virtual const EcManipulatorLink &getLink
      (
      ) const;

   /// Retrieve a handle to the DH transform.
   virtual RefTransform getDhFrame
      (
      ) const;

   /// Updates state for a non-base link
   /// @param[in] jointValue Value to set
   virtual void update
      (
      const EcReal jointValue
      );

   /// Retrieve the joint index.
   EcU32 getJointIndex
      (
      ) const;

   /// Retrieve the manipulator index.
   EcU32 getManIndex
      (
      ) const;

   /// These are needed for proper osgDB serialization.
   const char* className() const { return "EcRenderLink"; }
   const char* libraryName() const { return ""; }

protected:
   /// Protected to disallow explicit destruction.
   virtual ~EcRenderLink
      (
      );

   /// Process this link and create geometry.
   virtual void addLinkGeometry
      (
      const EcManipulatorLink &link,
      const EcStringDataMapMap &manSurfaces
      );

   const EcRenderManipulator* m_pRenderMan;
   const EcManipulatorLink* m_pLink; ///< Handle to sim data for this link
   EcU32 m_ManIndex;                 ///< Manipulator index
   EcU32 m_LinkIndex;                ///< EcPositionState index for this link
   RefTransform m_DhFrame;           ///< DH frame for child links
   boost::shared_ptr<EcLinkKinematics> m_pLinkKinematics; ///< Converts joint angles to matrix rotation
};

#endif // ecRenderLink_H_
