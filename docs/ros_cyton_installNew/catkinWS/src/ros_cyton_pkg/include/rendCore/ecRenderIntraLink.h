#ifndef ecRenderIntraLink_H_
#define ecRenderIntraLink_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderIntraLink.h
/// @brief Intr-link rendering class.  Data for this class is held within an
///        EcIndividualManipulator.  This class uses an OSG update visitor
///        node to traverse the already-built scene graph.  It looks for nodes
///        of type EcRenderManipulator, which contains a handle to the manipulator.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include "ecRenderLink.h"

class EcManipulatorActiveState;
class EcBaseGeneralBoundObject;

class EC_RENDER_RENDCORE_DECL EcRenderIntraLink : public EcRenderLink
{
public:
   typedef std::vector<osg::ref_ptr<osg::MatrixTransform> > GboVec;

   /// Constructor
   /// \param[in] pRenderMan Pointer to base manipulator.
   EcRenderIntraLink
      (
      EcRenderManipulator* pRenderMan
      );

   /// Copy constructor.
   /// \param[in] orig   Object to copy
   /// \param[in] copyop Type of copy to perform
   EcRenderIntraLink
      (
      const EcRenderIntraLink& orig,
      const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY
      );

   /// Updates the matrices for this node
   /// \param[in] jointValue Unneeded, but overloads base class usage
   virtual void update
      (
      const EcReal jointValue
      );

   /// This is needed for proper osgDB serialization.
   const char* className() const { return "EcRenderIntraLink"; }

protected:
   typedef boost::shared_ptr<EcBaseGeneralBoundObject> SharedGbo;

   /// Handle to EcGeneralBoundObject tranformation matrix vector.
   GboVec m_GboVector;
   std::vector<SharedGbo> m_vpGeneralBoundObjects;
   mutable boost::shared_ptr<EcManipulatorActiveState> m_pActiveState; ///< Utility active state
};

#endif // ecRenderIntraLink_H_
