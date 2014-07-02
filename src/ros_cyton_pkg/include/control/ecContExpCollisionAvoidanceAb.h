#ifndef ecContExpCollisionAvoidanceAb_H_
#define ecContExpCollisionAvoidanceAb_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpCollisionAvoidanceAb.h
/// @class EcControlExpressionCollisionAvoidanceAB
/// @brief This expression returns a vector that can be used in
///        the velocity control system to drive the manipulator away from obstacles.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"
#include "ecExpContainer.h"
#include "ecFiniteDifferenceTool.h"
#include <measure/ecCollisionProxFunction.h>

class EC_ACTIN_CONTROL_DECL EcControlExpressionCollisionAvoidanceAB : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionCollisionAvoidanceAB
      (
      );

   /// constructor from an EcExpressionContainer pointer
   /// @param[in] containerPointer (EcExpressionContainer*)
   EcControlExpressionCollisionAvoidanceAB
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionCollisionAvoidanceAB
      (
      );

   /// copy constructor
   /// @param[in] orig (EcControlExpressionCollisionAvoidanceAB&) value to set
   EcControlExpressionCollisionAvoidanceAB
      (
      const EcControlExpressionCollisionAvoidanceAB& orig
      );

   /// assignment operator
   EcControlExpressionCollisionAvoidanceAB& operator=
      (
      const EcControlExpressionCollisionAvoidanceAB& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionCollisionAvoidanceAB& orig
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
   /// @return (EcVelocityControlData&) The velocity control data.
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

   /// gets the avoidance distance, this is the distance
   /// beyond which we ignore collision avoidance
   /// @return The maximum collision avoidance distance
   virtual EcReal avoidanceDistance
      (
      ) const;

   /// sets the avoidance distance, this is the distance
   /// beyond which we ignore collision avoidance
   /// @param[in] avoidanceDistance (EcReal) set the avoidance distance
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
   /// @param[in] boundaryValue (EcReal) value to set
   virtual void setBoundaryValue
      (
      EcReal boundaryValue
      );

   /// set flag indicating whether to check for manipulator self-collisions
   /// @param[in] val (EcBoolean) value to set
   virtual void setCheckSelfCollision
      (
         EcBoolean val
      );

   /// get flag indicating whether to check for manipulator self-collisions
   /// @return (EcBoolean)   The self collision flag
   virtual EcBoolean checkSelfCollision
      (
      ) const;

   /// set flag indicating whether to check for environmental collisions
   /// param[in] val (EcBoolean) value to set
   virtual void setCheckEnvironmentCollisions
      (
         EcBoolean val
      );

   /// get flag indicating whether to check for environmental collisions
   /// @return (EcBoolean) The environment collision flag
   virtual EcBoolean checkEnvironmentCollisions
      (
      ) const;

   /// gets the precision level, this is the level in the BVH to anchor on
   /// @return (EcU32&) The precision level
   virtual const EcU32& precisionLevel
      (
      );

   /// sets the precision level.  this is the level in the BVH to
   /// anchor on
   /// @param[in] precLeve (EcU32&) value to set
   virtual void setPrecisionLevel
      (
      const EcU32 & precLeve
      );

   /// set the interval processing (TODO:What is interval processing?)
   /// @param[in] flag (EcBoolean) value to set
   virtual void setUseIntervalProcessing
      (
      EcBoolean flag
      );

   /// get the interval processing
   /// @return EcBoolean The interval processing flag
   virtual EcBoolean useIntervalProcessing
      (
      ) const;

   /// read this object from an XML stream
   /// @param[in] stream   Read the input stream from xml file
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   /// @param[in] stream Write the stream to xml file
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   /// @return The EcControlExpressionCollisionAvoidanceAB object
   static EcControlExpressionCollisionAvoidanceAB nullObject
      (
      );

   /// token for this class
   /// @return (EcToken&) The class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The xml object creator
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

   /// check for manipulator self-collisions
   EcXmlBoolean                        m_CheckSelfCollisions;

   /// check for collisions with the environment (this includes other manipulators)
   EcXmlBoolean                        m_CheckEnvironmentCollisions;

   /// the use interval processing flag
   EcXmlBoolean                        m_UseIntervalProcessing;

   /// the precision to use for the collision avoidance distance query the equates to the level in the bounding volume heiarchy
   EcXmlU32                            m_PrecisionLevel;

   // non-XML data below

   /// utility finite-difference tool
   mutable EcFiniteDifferenceTool      m_FiniteDifferenceTool;

   /// utility function
   mutable EcCollisionProximityFunction m_CollisionProximityFunction;
};

#endif // ecContExpCollisionAvoidanceAb_H_
