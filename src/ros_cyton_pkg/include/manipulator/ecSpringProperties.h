#ifndef ecSpringProperties_H_
#define ecSpringProperties_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecSpringProperties.h
/// @class EcSpringProperties
/// @brief Defines the spring force on a joint as a function of
///        this and other joint values.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

// forward declarations
class EcPositionState;
class EcManipulatorActiveState;
class EcIndividualManipulator;

/// Defines the spring force on a joint as a function of this and other joint values
class EC_FOUNDATION_MANIPULATOR_DECL EcSpringProperties : public EcXmlCompoundType
{
public:
   /// constructor
   EcSpringProperties
      (
      );

   /// destructor
   virtual ~EcSpringProperties
      (
      );

   /// copy constructor
   EcSpringProperties
      (
      const EcSpringProperties& orig
      );

   /// assignment operator
   EcSpringProperties& operator=
      (
      const EcSpringProperties& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSpringProperties& orig
      ) const;

   /// XML-initializes the class by registering the components
   virtual EcBoolean xmlInit
      (
      );

   /// A virtual constructor that returns an EcXmlObject.
   virtual EcXmlObject* clone
      (
      ) const;

   /// registers all the components for this class that are
   /// read and written to XML files.
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

   /// Reads class data from an XML stream.
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// Writes class data to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// return null object for spring properties
   static EcSpringProperties nullObject
      (
      );

   /// get set functions of member variables
   virtual const EcXmlReal& springConstant
      (
      ) const;

   /// set Spring Constant
   virtual void setSpringConstant
      (
      EcReal sConst
      );

   /// get weighting Factors
   virtual const EcXmlRealVector& weightingFactors
      (
      ) const;

   /// set Weighting Factors
   virtual void setWeightingFactors
      (
      EcXmlRealVector wFactors
      );

   /// get spring Offsets
   virtual const EcXmlRealVector& springOffsets
      (
      ) const;

   /// set Spring Offsets
   virtual void setSpringOffsets
      (
      EcXmlRealVector sOffsets
      );

   /// get associated Joints
   virtual const EcXmlStringVector& associatedJoints
      (
      ) const;

   /// set Associated Joints
   virtual void setAssociatedJoints
      (
      EcXmlStringVector links
      );

   /// calculate torque
   virtual EcReal torque
      (
      const EcIndividualManipulator& manipulator,
      const EcPositionState& positionState
      ) const;

   /// calculate torque
   virtual EcReal torque
      (
      const EcIndividualManipulator& manipulator,
      const EcManipulatorActiveState& activeState
      ) const;

protected:

   /// the force on the joint is calculated as:
   /// torq = k(a1*(t1-o1)+a2*(t2-o2)+...)
   /// where k is spring constant
   ///       ai is the weighting factor of the ith associated link/joint
   ///       oi is the offset of the spring.

   /// spring constant
   EcXmlReal           m_SpringConstant;

   /// vector weighting factor
   EcXmlRealVector     m_WeightingFactors;

   /// vector offset
   EcXmlRealVector     m_SpringOffsets;

   /// vector link list
   EcXmlStringVector   m_AssociatedJoints;
};

#endif // ecSpringProperties_H_
