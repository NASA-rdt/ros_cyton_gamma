#ifndef ecLinearTrajGenerator_H_
#define ecLinearTrajGenerator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinearTrajGenerator.h
/// @class EcLinearTrajectoryGenerator
/// @brief Class for generating linear trajectory
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseTrajGenerator.h"

#include <foundCommon/ecCoordSysXForm.h>

/**
\class EcLinearTrajectoryGenerator
\brief Class for generating a linear trajectory.
*/
class EC_ACTIN_WALKING_DECL EcLinearTrajectoryGenerator : public EcBaseTrajectoryGenerator
{
public:
   /// default constructor
   EcLinearTrajectoryGenerator
      (
      );

   /// destructor
   virtual ~EcLinearTrajectoryGenerator
      (
      );

   /// copy constructor
   EcLinearTrajectoryGenerator
      (
      const EcLinearTrajectoryGenerator& orig
      );

   /// assignment operator
   EcLinearTrajectoryGenerator& operator=
      (
      const EcLinearTrajectoryGenerator& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinearTrajectoryGenerator& orig
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

   /// generates the desired trajectory between two locations, given the total time and time step.
   /**
   It simply does the linear interpolation between the two points.
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
   static EcLinearTrajectoryGenerator nullObject
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
};

#endif // ecLinearTrajGenerator_H_
