#ifndef ecBaseTrajGenerator_H_
#define ecBaseTrajGenerator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseTrajGenerator.h
/// @class EcBaseTrajectoryGenerator
/// @brief Base class for trajectory generator
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <deque>
#include <foundCommon/ecGeneralMotion.h>
#include <foundCommon/ecCoordSysXForm.h>
#include <xml/ecXmlCompType.h>

/// define a trajectory type
typedef std::deque<EcCoordinateSystemTransformation>  EcTrajectoryType;

/**
\class EcBaseTrajectoryGenerator
\brief Base class for trajectory generator.
*/
class EC_ACTIN_WALKING_DECL EcBaseTrajectoryGenerator : public EcXmlCompoundType
{
public:
   /// default constructor
   EcBaseTrajectoryGenerator
      (
      );

   /// destructor
   virtual ~EcBaseTrajectoryGenerator
      (
      );

   /// copy constructor
   EcBaseTrajectoryGenerator
      (
      const EcBaseTrajectoryGenerator& orig
      );

   /// assignment operator
   EcBaseTrajectoryGenerator& operator=
      (
      const EcBaseTrajectoryGenerator& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseTrajectoryGenerator& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// returns the token for this class
   virtual const EcToken& token
      (
      ) const = 0;

   /// gets whether to generate orientation trajectory
   virtual EcBoolean generateOrientationFlag
      (
      ) const;

   /// sets whether to generate orientation trajectory
   virtual void setGenerateOrientationFlag
      (
      EcBoolean value
      );

   /// generates the desired trajectory between two locations, given the total time and time step
   /**
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
      ) = 0;

protected:
   /// A flag indicating whether to generate orientation trajectory
   EcXmlBoolean         m_GenerateOrientationFlag;
};

#endif // ecBaseTrajGenerator_H_
