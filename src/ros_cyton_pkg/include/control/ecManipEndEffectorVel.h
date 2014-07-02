#ifndef ecManipEndEffectorVel_H_
#define ecManipEndEffectorVel_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipEndEffectorVel.h
/// @class EcManipulatorEndEffectorVelocity
/// @brief Holds a description of the velocities of all end effectors
///        on a manipulator.  The velocities of frames are general
///        velocities and of points are vector velocities.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

/// Holds a description of the velocities of all end effectors on a manipulator.
/** The velocities of frames are general velocities
 and of points are vector velocities.
*/
class EC_ACTIN_CONTROL_DECL EcManipulatorEndEffectorVelocity : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorEndEffectorVelocity
      (
      );

   /// constructor from values
   EcManipulatorEndEffectorVelocity
      (
      const EcXmlRealVectorVector& generalEndEffectorVelocities
      );

   /// destructor
   virtual ~EcManipulatorEndEffectorVelocity
      (
      );

   /// copy constructor
   EcManipulatorEndEffectorVelocity
      (
      const EcManipulatorEndEffectorVelocity& orig
      );

   /// assignment operator
   EcManipulatorEndEffectorVelocity& operator=
      (
      const EcManipulatorEndEffectorVelocity& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorEndEffectorVelocity& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

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

   /// gets vector of general end-effector velocities - const version
   virtual const EcXmlRealVectorVector& generalEndEffectorVelocities
      (
      ) const;

   /// gets vector of general end-effector velocities - nonconst version
   virtual EcXmlRealVectorVector& generalEndEffectorVelocities
      (
      );

   /// sets vector of general end-effector velocities
   virtual void setGeneralEndEffectorVelocities
      (
      const EcXmlRealVectorVector& generalEndEffectorVelocities
      );

   /// sets a single general end-effector velocity
   virtual EcBoolean setGeneralEndEffectorVelocity
      (
      const EcU32 endEffectorIndex,
      const EcXmlRealVector& generalEndEffectorVelocity
      );

   /// gets the motion as a single vector for all velocities
   virtual void getSingleVector
      (
      EcRealVector& singleVector
      ) const;

   /// gets the motion as a single vector for a subset of velocities
   virtual void getSingleVector
      (
      const EcU32Vector& endEffectorIndices,
      EcRealVector& singleVector
      ) const;

   /// gets the degrees of constraint (i.e., the degrees of freedom
   /// in hand motion) for all
   virtual EcU32 doc
      (
      ) const;

   /// gets the degrees of constraint (i.e., the degrees of freedom
   /// in hand motion) for the specified set of indices
   virtual EcU32 doc
      (
      const EcU32Vector& endEffectorIndices
      ) const;

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null link
   static EcManipulatorEndEffectorVelocity nullObject
      (
      );

protected:
   /// a vector of velocity descriptions for general end effectors
   EcXmlRealVectorVector                   m_GeneralEndEffectorVelocities;
};

/// a vector of end-effector sets
typedef EcXmlVectorType<EcManipulatorEndEffectorVelocity>
   EcManipulatorEndEffectorVelocityVector;

#endif // ecManipEndEffectorVel_H_
