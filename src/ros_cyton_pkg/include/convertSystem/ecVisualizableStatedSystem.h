#ifndef ecVisualizableStatedSystem_H_
#define ecVisualizableStatedSystem_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecVisualizableStatedSystem.h
/// @class EcVisualizableStatedSystem
/// @brief Holds a description of a stated system and all the parameters
///        needed to visualize it.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <manipulator/ecStatedSystem.h>
#include <visualization/ecVisualizationParameters.h>
#include <xml/ecXmlCompType.h>

/// Holds a description of a stated system and all the parameters needed to visualize it.
class EC_FOUNDATION_CONVERTSYSTEM_DECL EcVisualizableStatedSystem : public EcXmlCompoundType
{
public:
   /// default constructor
   EcVisualizableStatedSystem
      (
      );

   /// destructor
   virtual ~EcVisualizableStatedSystem
      (
      );

   /// copy constructor
   EcVisualizableStatedSystem
      (
      const EcVisualizableStatedSystem& orig
      );

   /// assignment operator
   EcVisualizableStatedSystem& operator=
      (
      const EcVisualizableStatedSystem& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcVisualizableStatedSystem& orig
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

   /// gets the visualization parameters
   virtual const EcVisualizationParameters& visualizationParameters
      (
      ) const;

   /// sets the visualization parameters
   virtual void setVisualizationParameters
      (
      const EcVisualizationParameters& visualizationParameters
      );

   /// gets the stated system
   virtual const EcStatedSystem& statedSystem
      (
      ) const;

   /// sets the stated system
   virtual void setStatedSystem
      (
      const EcStatedSystem& statedSystem
      );

   /// sets all data from a stated system.  Visualization parameters
   /// are calculated from the bounding sphere.  The eye distance ratio
   /// is the distance of the eye to the bounding sphere center
   /// divided by the bounding-spere radius.
   virtual void setFromStatedSystem
      (
      const EcStatedSystem& statedSystem,
      EcReal eyeDistanceRatio=2.0
      );

   /// sets the state
   virtual void setState
      (
      const EcManipulatorSystemState& state
      );

   /// add a state that has each joint position halfway between joint limits.
   virtual void setToMidpointState
      (
      );

   /// Set shape surface properties by the key.
   virtual EcBoolean setSurfacesByKey
      (
      const EcShapeStateCacheKey& key,
      const EcStringDataMapMap& surfaces
      );

   /// merge operation
   virtual EcBoolean mergeWith
      (
      const EcVisualizableStatedSystem& other
      );

   /// scale an individual manipulator by the given distance factor
   /// scaleFactor 1.0 leaves the manipulator unchanged.
   virtual EcBoolean scaleManipulatorBy
      (
      EcU32 manipulatorIndex,
      EcReal scaleFactor
      );

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

   /// get a null object
   static EcVisualizableStatedSystem nullObject
      (
      );

protected:
   /// the visualization parameters that can be used to
   /// view the system
   EcVisualizationParameters m_VisualizationParameters;

   /// the stated system
   EcStatedSystem            m_StatedSystem;
};

#endif // ecVisualizableStatedSystem_H_
