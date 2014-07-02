#ifndef ecCleverPositionControlMethod_H_
#define ecCleverPositionControlMethod_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecCleverPositionControlMethod.h
/// @class EcCleverPositionControlMethod
/// @brief Holds a description of a position control method, which
///        automatically adjusts the soft constraint weight as the
///        robot move closer to the goals
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecPositionControlMethod.h"
#include <xml/ecXmlBasicType.h>

class EC_ACTIN_CONTROL_DECL EcCleverPositionControlMethod : public EcPositionControlMethod
{
public:
   /// default constructor
   EcCleverPositionControlMethod
      (
      );

   /// destructor
   virtual ~EcCleverPositionControlMethod
      (
      );

   /// copy constructor
   EcCleverPositionControlMethod
      (
      const EcCleverPositionControlMethod& orig
      );

   /// assignment operator
   EcCleverPositionControlMethod& operator=
      (
      const EcCleverPositionControlMethod& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCleverPositionControlMethod& orig
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

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// get the distance within which the soft constraint multiplier is adjusted
   /// @return The soft constraint value
   virtual EcReal softConstraintDistance
      (
      ) const;

   /// set the distance within which the soft constraint multiplier is adjusted
   /// param[in] value (EcReal) value to set
   virtual void setSoftConstraintDistance
      (
      EcReal value
      );

   /// get the maximum value of the soft constraint multiplier
   /// @return (EcReal) The maimum multiplier TODO
   virtual EcReal maxMultiplier
      (
      ) const;

   /// set the maximum value of the soft constraint multiplier
   /// @return value (EcReal) value to set
   virtual void setMaxMultiplier
      (
      EcReal value
      );

   /// gets the exponent
   /// @return (EcReal) The exponent value
   virtual EcInt32 exponent
      (
      ) const;

   /// sets the exponent
   /// @param[in] exponent (EcReal) value to set, (Must be between 0 and 1 inclusive)
   virtual void setExponent
      (
      EcInt32 exponent
      );

   /// return a token
   /// @return (EcToken&) The token value
   virtual const EcToken& token
      (
      ) const;

   /// token for this class
   /// @return (EcToken&) The class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The object
   static EcXmlObject* creator
      (
      );

   /// copydoc EcPositionControlMethod::postCalculateStateCondition()
   virtual void postCalculateStateCondition
      (
      );

protected:
   /// adjust the soft constraint multipliers of end-effectors in a manipulator specified by the index
   virtual void adjustSoftConstraintMultipliers
      (
      );

   /// compute the multiplier given the distance between actual and goal
   /// @param[in] distance (EcReal) (TODO.What distance?)
   /// @return distance (EcReal) TODO
   virtual EcReal computeMultiplier
      (
      EcReal distance
      ) const;

   /// reset the multiplier to 1 for all end-effectors in all manipulators
   virtual void resetSoftConstraintMultipliers
      (
      );

protected:
   /// the distance (between actual and goal) within which the soft constraint multipliers is adjusted
   EcXmlReal            m_SoftConstraintDistance;
   /// the maximum value of multiplier TODO
   EcXmlReal            m_MaxMultiplier;
   /// the exponent
   EcXmlInt32           m_Exponent;
};

#endif // ecCleverPositionControlMethod_H_
