#ifndef ecRenderManipulator_H_
#define ecRenderManipulator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderManipulator.h
/// @class EcRenderManipulator
/// @brief Implementation of the EcRenderManipulator class.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include "ecRenderLink.h"

#include <boost/scoped_ptr.hpp>

class EcPositionState;

class EC_RENDER_RENDCORE_DECL EcRenderManipulator : public osg::MatrixTransform
{
public:
   /// Constructor that traverses all child links from this manipulator and
   /// creates geometry.
   /// \param[in] man   The manipulator to traverse.
   EcRenderManipulator
      (
      const EcIndividualManipulator &man
      );

   /// Copy constructor.
   /// \param[in] orig   Object to copy
   /// \param[in] copyop Type of copy to perform
   EcRenderManipulator
      (
      const EcRenderManipulator& orig,
      const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY
      );

   /** clone an object of the same type as the node.*/
   virtual osg::Object* cloneType() const { return new EcRenderManipulator(m_Manip); }

   /** return a clone of a node, with Object* return type.*/
   virtual osg::Object* clone(const osg::CopyOp& copyop) const { return new EcRenderManipulator(*this,copyop); }

   /** return true if this and obj are of the same kind of object.*/
   virtual bool isSameKindAs(const osg::Object* obj) const { return dynamic_cast<const EcRenderManipulator*>(obj)!=EcNULL; }

   virtual void updateState
     (
     const EcPositionState& posState
     );

   virtual const EcIndividualManipulator &getManipulator
      (
      ) const;

   EcU32 getManipulatorIndex
      (
      ) const;

   EcU32 getNumTotalLinks
      (
      ) const;

   const EcPositionState& positionState
      (
      ) const;

   void setInitState
      (
      const EcRenderTypes::DisplayMask initState
      );

   void unsetInitState
      (
      const EcRenderTypes::DisplayMask initState
      );

   EcRenderTypes::DisplayMask getInitState
      (
      ) const;

   /// These are needed for proper osgDB serialization.
   const char* className() const { return "EcRenderManipulator"; }
   const char* libraryName() const { return ""; }

protected:
   /// Protected to disallow explicit destruction.
   virtual ~EcRenderManipulator
      (
      );

   /// Traverses links and builds up geometry for each.
   /// \param[in,out] parent      Parent node to attach to.
   virtual void processChildren
      (
      EcRenderLink *parent
      );

   /// Current running link index when building node graph.  After init it is total number of child links.
   mutable EcU32 m_JointIndex;
   /// Convenience handle to manipulator index
   EcU32 m_ManipIndex;
   /// Handle to internal structure of manipulator.
   const EcIndividualManipulator &m_Manip;
   boost::scoped_ptr<EcPositionState> m_pJointPositions; ///< Last set of joint states for this man
   EcRenderTypes::DisplayMask m_InitState;  ///< Flag to denote initialization status
};

#endif // ecRenderManipulator_H_
