#ifndef ecManipEndEffectorForce_H_
#define ecManipEndEffectorForce_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipEndEffectorForce.h
/// @class EcManipulatorEndEffectorForce
/// @brief Holds a description of the forces on all end effectors
///        on a manipulator.  The forces of frames are general
///        forces and of points are vector forcees.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

/// Holds a description of the forces of all end effectors on a manipulator.
/** The forces of frames are general forces. Those of points are vector forces.
*/
class EC_ACTIN_CONTROL_DECL EcManipulatorEndEffectorForce : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorEndEffectorForce
      (
      );

   /// destructor
   virtual ~EcManipulatorEndEffectorForce
      (
      );

   /// copy constructor
   EcManipulatorEndEffectorForce
      (
      const EcManipulatorEndEffectorForce& orig
      );

   /// assignment operator
   EcManipulatorEndEffectorForce& operator=
      (
      const EcManipulatorEndEffectorForce& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorEndEffectorForce& orig
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

   /// gets vector of general end-effector forces - const version
   virtual const EcXmlRealVectorVector& generalEndEffectorForces
      (
      ) const;

   /// gets vector of general end-effector forces - nonconst version
   virtual EcXmlRealVectorVector& generalEndEffectorForces
      (
      );

   /// sets vector of general end-effector forces
   virtual void setGeneralEndEffectorForces
      (
      const EcXmlRealVectorVector& generalEndEffectorForces
      );

   /// gets the force as a single vector
   virtual void getSingleVector
      (
      EcRealVector& singleVector
      ) const;

   /// gets the degrees of constraint (i.e., the degrees of freedom
   /// in hand motion
   virtual EcU32 doc
      (
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
   static EcManipulatorEndEffectorForce nullObject
      (
      );

protected:
   /// a vector of force descriptions for general end effectors
   EcXmlRealVectorVector         m_GeneralEndEffectorForces;
};

/// a vector of end-effector sets
typedef EcXmlVectorType<EcManipulatorEndEffectorForce>
   EcManipulatorEndEffectorForceVector;

#endif // ecManipEndEffectorForce_H_
