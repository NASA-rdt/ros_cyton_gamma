#ifndef ecContExpObstAvoid_H_
#define ecContExpObstAvoid_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpObstAvoid.h
/// @class EcControlExpressionObstacleAvoidance
/// @brief This expression returns a vector that will drive
///        joints away from limits.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"
#include "ecExpContainer.h"
#include "ecFiniteDifferenceTool.h"
#include <measure/ecObstProxFunction.h>

/// This expression returns a vector that can be used in the velocity control system to drive the manipulator away from obstacles.
class EC_ACTIN_CONTROL_DECL EcControlExpressionObstacleAvoidance : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionObstacleAvoidance
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcControlExpressionObstacleAvoidance
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionObstacleAvoidance
      (
      );

   /// copy constructor
   EcControlExpressionObstacleAvoidance
      (
      const EcControlExpressionObstacleAvoidance& orig
      );

   /// assignment operator
   EcControlExpressionObstacleAvoidance& operator=
      (
      const EcControlExpressionObstacleAvoidance& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionObstacleAvoidance& orig
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
   /// @return (EcVelocityControlData&) The velocity control data
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// return a token
   /// @return (EcToken&) The xml token
   virtual const EcToken& token
      (
      ) const;

   /// gets the exponent
   /// @return (EcReal) The exponent value
   virtual EcReal exponent
      (
      ) const;

   /// sets the exponent
   /// @param[in] exponent   (EcReal) value to set, (Must be between 0 and 1 inclusive)
   virtual void setExponent
      (
      EcReal exponent
      );

   /// gets the avoidance distance
   /// @return (EcReal) the avoidance distance from the obstacle
   virtual EcReal avoidanceDistance
      (
      ) const;

   /// sets the avoidance distance
   /// @param[in] avoidanceDistance (EcReal) Set the avoidance distance from the obstacle
   virtual void setAvoidanceDistance
      (
      EcReal avoidanceDistance
      );

   /// gets the boundary value
   /// @return (EcReal) The boundary value
   virtual EcReal boundaryValue
      (
      ) const;

   /// sets the boundary value
   /// @param[in] boundaryValue (EcReal) Set the boundary value
   virtual void setBoundaryValue
      (
      EcReal boundaryValue
      );

   /// gets the boundary value
   /// @return (EcReal) The vector of capsules enclosing obstacles
   virtual const EcCapsuleVector& capsules
      (
      ) const;

   /// Set the vector of capsules enclosing obstacles
   /// @param[in] capsules (EcCapsuleVector&) The vector of capsulex enclosing obstacles
   virtual void setCapsules
      (
      const EcCapsuleVector& capsules
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
   /// @return (EcControlExpressionObstacleAvoidance) The null object
   static EcControlExpressionObstacleAvoidance nullObject
      (
      );

   /// token for this class
   /// @return (EcToken&) the xml token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The cml object pointer
   static EcXmlObject* creator
      (
      );

protected:
   /// the exponent of a polynomial avoidance function
   EcXmlReal                           m_Exponent;

   /// the zone in which to avoid an obstacle
   EcXmlReal                           m_AvoidanceDistance;

   /// the function value at the obstacle boundary
   EcXmlReal                           m_BoundaryValue;

   /// a vector of capsules enclosing obstacles.  These are
   /// the avoided objects.
   EcCapsuleVector                     m_Capsules;

   // non-XML data below

   /// utility finite-difference tool
   mutable EcFiniteDifferenceTool      m_FiniteDifferenceTool;

   /// utility function
   mutable EcObstacleProximityFunction m_ObstacleProximityFunction;
};

#endif // ecContExpObstAvoid_H_
