#ifndef ecContExpEndErrorFilter_H_
#define ecContExpEndErrorFilter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpEndErrorFilter.h
/// @class EcControlExpressionEndEffectorErrorFilter
/// @brief This limits the two-norm of the end-effector velocity error.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecContExpContainer.h"
#include "ecEndEffectorTool.h"
#include "ecExpElement.h"
#include "ecJacobianTool.h"
#include "ecManipEndEffectorVel.h"

#include <manipulator/ecManipulatorProximityTool.h>

/// Holds the description of the end-effector error filter
class EC_ACTIN_CONTROL_DECL EcControlExpressionEndEffectorErrorFilter : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionEndEffectorErrorFilter
      (
      );

   /// constructor from an EcControlExpressionContainer pointer
   EcControlExpressionEndEffectorErrorFilter
      (
      const EcControlExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionEndEffectorErrorFilter
      (
      );

   /// copy constructor
   EcControlExpressionEndEffectorErrorFilter
      (
      const EcControlExpressionEndEffectorErrorFilter& orig
      );

   /// assignment operator
   EcControlExpressionEndEffectorErrorFilter& operator=
      (
      const EcControlExpressionEndEffectorErrorFilter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionEndEffectorErrorFilter& orig
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
   /// @return (EcVelocityControlData&) The velocity cotrol data object
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// sets the container
   /// @param[in] container (EcXmlBaseVariableCompoundType*) vale to set
   virtual void setContainer
      (
      const EcXmlBaseVariableCompoundType* container
      );

   /// gets the weights
   /// @return The control expression controller weights
   virtual const EcControlExpressionContainer& weights
      (
      ) const;

   /// sets the weights container
   /// @param[in] weightsContainer (EcControlExpressionContainer&) The control expression container
   virtual void setWeightsContainer
      (
      const EcControlExpressionContainer& weightsContainer
      );

   /// sets the weights element
   /// @param[in] weightsElement value to set
   virtual void setWeightsElement
      (
      const EcExpressionElement& weightsElement
      );

   /// gets the default weight
   /// @return The default weight
   virtual EcReal defaultWeight
      (
      ) const;

   /// sets the default weight
   /// @param[in] defaultWeight Value to set
   virtual void setDefaultWeight
      (
      EcReal defaultWeight
      );

   /// gets the unfiltered rates
   /// @return TODO
   virtual const EcControlExpressionContainer& unfilteredRates
      (
      ) const;

   /// sets the unfiltered rates
   /// @param[in] unfilteredRatesContainer value to set
   virtual void setUnfilteredRatesContainer
      (
      const EcControlExpressionContainer& unfilteredRatesContainer
      );

   /// sets the unfiltered rates element
   virtual void setUnfilteredRatesElement
      (
      const EcExpressionElement& unfilteredRatesElement
      );

   /// gets the threshold
   /// @return the threshold
   virtual EcReal threshold
      (
      ) const;

   /// sets the threshold
   /// @param[in] threshold (EcReal) value to set
   virtual void setThreshold
      (
      EcReal threshold
      );

   /// gets the stops-at-limits flag
   /// @return the stops-at-limits flag
   virtual EcBoolean stopsAtLimits
      (
      ) const;

   /// sets the stops-at-limits flag
   /// @param[in] stopsAtLimits (EcBoolean)  value to set (default value true)
   virtual void setStopsAtLimits
      (
      EcBoolean stopsAtLimits=EcTrue
      );

   /// gets the stops-at-collisions flag
   /// @return The stop-at-collision flag
   virtual EcBoolean stopsAtCollisions
      (
      ) const;

   /// sets the stops-at-collisions flag
   /// @param[in] stopsAtCollision value to set
   virtual void setStopsAtCollisions
      (
      EcBoolean stopsAtCollision=EcTrue
      );

   /// gets the precision level
   /// @return the bounding volume hierarchy precision level used in collision detection
   virtual EcU32 bvhPrecisionLevel
      (
      ) const;

   /// sets the  precision level
   /// @param[in] level The bounding volume hierarchy precision level used in collision detection
   virtual void setBvhPrecisionLevel
      (
      EcU32 level
      );

   /// return a token
   /// @return (EcToken&) The xml token
   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   /// @param[in] stream (EcXmlReader&) Stream to be read
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   /// @param[in] stream (EcXmlWriter&) Xml stream to be writtern into file
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   /// @return (EcControlExpressionEndEffectorErrorFilter) The null object
   static EcControlExpressionEndEffectorErrorFilter nullObject
      (
      );

   /// token for this class
   /// @return (EcToken&) The class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The cml objecct creator
   static EcXmlObject* creator
      (
      );

   /// set the collision stopping threshold
   /// @param[in] value (EcReal&) value to set
   virtual void setCollisionStoppingThreshold
      (
      const EcReal& value
      );

   /// get the collision stopping threshold
   /// @return const EcReal& TODO(What is collision stopping threshold?)
   virtual const EcReal& collisionStoppingThreshold
      (
      )const;

protected:
   /// calculate the end-effector velocity at the start of the time step
   /// @param[in] jointRates (EcVelocityControlData&) The joint rates of the manipulator
   virtual void calculateInitialHandVelocity
      (
      const EcVelocityControlData& jointRates
      ) const;

   /// calculate the end-effector velocity at the end of the time step
   /// @param[in] jointRates (EcVelocityControlData&) The joint rates of the manipulator
   virtual void calculateFinalHandVelocity
      (
      const EcVelocityControlData& jointRates
      ) const;

   /// calculate the filtered rates
   /// @param[in] jointRates (EcVelocityControlData&) The joint rates of the manipulator
   /// @param[in] weights (EcReArray&) The weights
   virtual EcBoolean calculateFilteredRates
      (
      const EcVelocityControlData& jointRates,
      const EcReArray& weights
      ) const;

   /// check to see if a joint limit is active.  That is, do the unfiltered rates push any joint beyond an upper or lower limit?
   /// @param[in] jointRates (EcReArray&) The joint rates of the manipulator
   /// @param[in] normalizedTransitionTime (EcReal&) Normalized transition time (0-1) of when the
   ///                       first joint limit is crossed.
   virtual EcBoolean jointLimitActive
      (
      const EcReArray& jointRates,
      EcReal& normalizedTransitionTime
      ) const;

   /// check to see if a collision is active.  That is, do the unfiltered rates push any link into collision.
   /// @param[in] jointRates (EcReArray&) The joint rates of the manipulator
   virtual EcBoolean collisionActive
      (
      const EcReArray& jointRates
      ) const;

   /// adjust the joint rates using the null-space component to avoid joint limits
   /// @param[in, out] jointRates (EcReArray&) The joint rates of the manipulator
   virtual EcBoolean adjustWithNullSpaceComponent
      (
      EcReArray& jointRates
      ) const;

   /// remove the null-space component of the joint rates
   /// @param[in, out] jointRates (EcReArray&) The joint rates of the manipulator
   virtual EcBoolean removeNullSpaceComponent
      (
      EcReArray& jointRates
      ) const;

protected:
   /// the weights
   EcControlExpressionContainer  m_Weights;

   /// a default weight value (used when DOC > size of m_Weights);
   EcXmlReal                     m_DefaultWeight;

   /// the unfiltered joint rates
   EcControlExpressionContainer  m_UnfilteredRates;

   /// the threshold
   EcXmlReal                     m_Threshold;

   /// a flag indicating whether or not to stop at joint-limit boundaries
   EcXmlBoolean                  m_StopsAtLimits;

   /// a flag indicating whether or not to stop at collisions
   EcXmlBoolean                  m_StopsAtCollisions;

   /// the level in the BVH to use for collision detection
   EcXmlU32                      m_BVHPrecision;

   /// Collision stopping threshold.  Distance from a collision where the control system should stop
   /// The default for this is 0
   EcXmlReal                                     m_CollisionStoppingThreshold;

   /// non-XML data below
   // utility values for speed (avoid reuse in derived classes)
   mutable EcManipulatorEndEffectorVelocity m_InitialHandVelocity;   ///< initial hand velocity
   mutable EcManipulatorEndEffectorVelocity m_FinalHandVelocity;     ///< final hand velocity
   mutable EcEndEffectorTool                m_EeTool;                ///< end-effector tool
   mutable EcVelocityState                  m_NewVelocityState;      ///< new velocity state
   mutable EcPositionState                  m_NewPositionState;      ///< new position state
   mutable EcRealVector                     m_EndEffectorError;      ///< end-effector error
   mutable EcReArray                        m_EndEffectorVelocity;   ///< end-effector velocity
   mutable EcJacobianTool                   m_JTool;                 ///< Jacobian tool
   mutable EcRealVector                     m_BaseComponent;         ///< base component
   mutable EcRealVector                     m_NullSpaceComponent;    ///< null-space component
   mutable EcManipulatorJacobian            m_Jacobian;              ///< Jacobian

   // utility values for collision detection
   mutable EcManipulatorSystemState         m_UtilityState;          ///< utility state
   mutable EcPropagationResultDataVector    m_UtilityPropagationResults;   ///< propagation results
   mutable EcManipulatorProximityTool       m_ProximityTool;         ///< proximity tool
};

#endif // ecContExpEndErrorFilter_H_
