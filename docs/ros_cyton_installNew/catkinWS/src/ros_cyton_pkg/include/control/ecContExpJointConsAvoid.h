#ifndef ecContExpJointConsAvoid_H_
#define ecContExpJointConsAvoid_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpJointConsAvoid.h
/// @class EcControlExpressionJointConstraintAvoidance
/// @brief This expression returns a vector that will drive
///        joints away from constraints.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecExpElement.h"
#include "ecExpContainer.h"
#include <xml/ecXmlBasicType.h>

class EcBaseStateConstraint;
class EcPositionState;

/// This expression returns a vector that will drive joints away from constraints. The constraints are
/// defined in the manipulator.
class EC_ACTIN_CONTROL_DECL EcControlExpressionJointConstraintAvoidance : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionJointConstraintAvoidance
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcControlExpressionJointConstraintAvoidance
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionJointConstraintAvoidance
      (
      );

   /// copy constructor
   EcControlExpressionJointConstraintAvoidance
      (
      const EcControlExpressionJointConstraintAvoidance& orig
      );

   /// assignment operator
   EcControlExpressionJointConstraintAvoidance& operator=
      (
      const EcControlExpressionJointConstraintAvoidance& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionJointConstraintAvoidance& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return the value
   /// @return The velocity control data
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// return a token
   /// @return The xml token
   virtual const EcToken& token
      (
      ) const;

   /// gets the exponent
   /// @return The exponent value
   virtual EcReal exponent
      (
      ) const;

   /// sets the exponent
   /// @param[in] exponent   (EcReal) value to set, (Must be between 0 and 1 inclusive)
   virtual void setExponent
      (
      EcReal exponent
      );

   /// gets the avoidance zone
   /// @return (EcReal) The avoidance region
   virtual EcReal avoidanceZone
      (
      ) const;

   /// sets the avoidance zone
   /// @param[in] avoidanceZone (EcReal) The avoidance region
   virtual void setAvoidanceZone
      (
      EcReal avoidanceZone
      );

   /// gets the maximum value of any entry.  This occurs when the joint is at a limit
   /// @return the maximum value
   virtual EcReal maximum
      (
      ) const;

   /// sets the maximum value of any entry.  This occurs when the joint is at a limit
   /// @param[in] maximum  the maximum value
   virtual void setMaximum
      (
      EcReal maximum
      );

   /// read this object from an XML stream
   /// @param[in] stream (EcXmlReader&) stream to be read from xml file
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   /// @param[in] stream (EcXmlWriter&) stream to be written into xml file
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   /// @return The control expression joint constraint avoidance null object
   static EcControlExpressionJointConstraintAvoidance nullObject
      (
      );

   /// token for this class
   /// @return The xml class object
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The xml object
   static EcXmlObject* creator
      (
      );

protected:
   /// Add repulsive force from the constraint
   /// @param[in] constraint (EcBaseStateConstraint&) The constraint
   /// @param[in] posState (EcPositionState&) The position state
   /// @param[in] isFixedBase Flag indicating if the manipulator is fixed base
   /// @param[out] zone (EcReal) The avoidance region
   virtual void addForceFromConstraint
      (
      const EcBaseStateConstraint& constraint,
      const EcPositionState& posState,
      EcBoolean isFixedBase,
      EcReal zone
      ) const;
protected:
   /// the exponent of a polynomial function
   EcXmlReal                       m_Exponent;

   /// the zone in which to avoid a limit
   EcXmlReal                       m_AvoidanceZone;

   /// the maximum value of any entry.  This occurs when the joint is at a limit
   EcXmlReal                       m_Maximum;
};

#endif // ecContExpJointConsAvoid_H_
