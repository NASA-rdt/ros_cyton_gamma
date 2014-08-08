#ifndef ecDamperProperties_H_
#define ecDamperProperties_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecDamperProperties.h
/// @class EcDamperProperties
/// @brief Defines the damper force on a joint as a function of
///        its rate and the rates of other joints.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

// forward declarations
class EcVelocityState;
class EcManipulatorActiveState;
class EcIndividualManipulator;

/**  Defines the damper force on a joint as a function of
 *   its rate and the rates of other joints.
 */
class EC_FOUNDATION_MANIPULATOR_DECL EcDamperProperties : public EcXmlCompoundType
{
public:
   /// constructor
   EcDamperProperties
      (
      );

   /// destructor
   virtual ~EcDamperProperties
      (
      );

   /// copy constructor
   EcDamperProperties
      (
      const EcDamperProperties& orig
      );

   /// assignment operator
   EcDamperProperties& operator=
      (
      const EcDamperProperties& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDamperProperties& orig
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

   /// get set functions of member variables
   virtual const EcXmlReal& damperConstant
      (
      ) const;

   /// set damper constant
   virtual void setDamperConstant
      (
      EcReal dConst
      );

   /// get weighting factors
   virtual const EcXmlRealVector& weightingFactors
      (
      ) const;

   /// set weighting factors
   virtual void setWeightingFactors
      (
      EcXmlRealVector wFactors
      );

   /// get associated Joints
   virtual const EcXmlStringVector& associatedJoints
      (
      ) const;

   /// set associated Joints
   virtual void setAssociatedJoints
      (
      EcXmlStringVector joints
      );

   /// calculate torque
   virtual EcReal torque
      (
      const EcIndividualManipulator& manipulator,
      const EcVelocityState& velocityState
      ) const;

   /// calculate torque
   virtual EcReal torque
      (
      const EcIndividualManipulator& manipulator,
      const EcManipulatorActiveState& activeState
      ) const;

   /// get a null object
   static EcDamperProperties nullObject
      (
      );

protected:
   /// the force on the joint is calculated as:
   /// torque = k(a1*v1+a2*v2+...)
   /// where k is the damper constant
   ///       ai is the weighting factor of the ith associated link/joint
   ///       vi is the joint velocity of ith associated link/joint.

   /// damping constant
   EcXmlReal           m_DamperConstant;

   /// vector weighting factor
   EcXmlRealVector     m_WeightingFactors;

   /// vector link list
   EcXmlStringVector   m_AssociatedJoints;
};

#endif // ecDamperProperties_H_
