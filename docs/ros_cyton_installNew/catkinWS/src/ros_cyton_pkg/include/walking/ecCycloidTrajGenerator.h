#ifndef ecCycloidTrajGenerator_H_
#define ecCycloidTrajGenerator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecCycloidTrajGenerator.h
/// @class EcCycloidTrajectoryGenerator
/// @brief Base class for end-effector placement converter
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseTrajGenerator.h"

#include <foundCommon/ecCoordSysXForm.h>

/**
\class EcCycloidTrajectoryGenerator
\brief Base class for end-effector placement converter
*/
class EC_ACTIN_WALKING_DECL EcCycloidTrajectoryGenerator : public EcBaseTrajectoryGenerator
{
public:
   /// default constructor
   EcCycloidTrajectoryGenerator
      (
      );

   /// destructor
   virtual ~EcCycloidTrajectoryGenerator
      (
      );

   /// copy constructor
   EcCycloidTrajectoryGenerator
      (
      const EcCycloidTrajectoryGenerator& orig
      );

   /// assignment operator
   EcCycloidTrajectoryGenerator& operator=
      (
      const EcCycloidTrajectoryGenerator& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCycloidTrajectoryGenerator& orig
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

   /// returns the token for this class
   virtual const EcToken& token
      (
      ) const;

   /// gets the trajectory height
   virtual EcReal trajectoryHeight
      (
      ) const;

   /// sets the trajectory height
   virtual void setTrajectoryHeight
      (
      EcReal value
      );

   /// gets the unit vector in the direction of the trajectory height
   virtual const EcVector& directionVector
      (
      ) const;

   /// sets the unit vector in the direction of the trajectory height
   virtual void setDirectionVector
      (
      const EcVector& value
      );

   /// generates the desired trajectory between two locations, given the total time and time step.
   /**
   For translation, this generates a cycloidal trajectory between the two points. For orientation, it simply does the linear interpolcation between the two orientations.
   \param[in] from The starting placement of the trajectory.
   \param[in] to The ending placement of the trajectory.
   \param[in] totalTime The total time of the trajectory.
   \param[in] timeStep The time step.
   \param[out] trajectory The generated trajectory.
   \return True if successful or false otherwise.
   */
   virtual EcBoolean generateTrajectory
      (
      const EcCoordinateSystemTransformation& from,
      const EcCoordinateSystemTransformation& to,
      EcReal totalTime,
      EcReal timeStep,
      EcTrajectoryType& trajectory
      );

   /// get a null object
   static EcCycloidTrajectoryGenerator nullObject
      (
      );

   /// token for this class
   /**
   \return a unique string token.
   */
   static const EcToken& classToken
      (
      );

   /// static creator function
   /**
   \return a pointer to a new'ed object.
   */
   static EcXmlObject* creator
      (
      );

protected:
   /// the height of the trajectory
   EcXmlReal               m_TrajectoryHeight;

   /// the unit vector in the direction of the height
   EcXmlVector             m_DirectionVector;
};

#endif // ecCycloidTrajGenerator_H_
