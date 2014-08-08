#ifndef ecManipulatorConstraintTool_H_
#define ecManipulatorConstraintTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulatorConstraintTool.h
/// @class EcManipulatorConstraintTool
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecStatedSystem.h"
#include <function/ecScalarFunctionContainer.h>
#include <xml/ecXmlCompType.h>

/// Manipulator constraints
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorConstraintTool  : public EcXmlCompoundType
{
public:
   EcManipulatorConstraintTool
      (
      );

   virtual ~EcManipulatorConstraintTool
      (
      );

   /// copy constructor
   EcManipulatorConstraintTool
      (
      const EcManipulatorConstraintTool& orig
      );

   /// assignment operator
   EcManipulatorConstraintTool& operator=
      (
      const EcManipulatorConstraintTool& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorConstraintTool& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

   /// get function for manipulatorConstraint
   virtual const EcXmlConstraintVectorVectorType& manipulatorConstraints
      (
      ) const;

   /// set function for manipulatorConstraint
   virtual void setManipulatorConstraints
      (
      const EcXmlConstraintVectorVectorType& manipulatorConstraints
      );

   /// convert articulation state to joint state
   virtual EcBoolean convert
      (
      const EcRealVector& articulationStates,
      const EcStatedSystem& statedSystem,
      EcManipulatorSystemState& state
      );

   /// set the m_ManipulatorConstraints to joint limit
   virtual EcBoolean setConstraintToJointLimit
      (
      const EcStatedSystem& statedSystem
      );

   /// set the constraints so all joints move together
   virtual EcBoolean setToOneGroup
      (
      const EcStatedSystem& statedSystem
      );

protected:
   /// the manipulator constraints
   EcXmlConstraintVectorVectorType m_ManipulatorConstraints;
};

#endif // ecManipulatorConstraintTool_H_
