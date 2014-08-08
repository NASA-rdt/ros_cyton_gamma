#ifndef ecLinkKinematicsRandomVariation_H_
#define ecLinkKinematicsRandomVariation_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkKinematicsRandomVariation.h
/// @brief Description of random variation of link kinematics property
/// @details EcLinkKinematicsRandomVariation
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

// forward declarations
class EcLinkKinematics;
class EcCoordinateSystemTransformation;

/// The class for generating random variations of link kinematics properties that can be used
/// in Monte-Carlo simulation
class EC_FOUNDATION_MANIPULATOR_DECL EcLinkKinematicsRandomVariation : public EcXmlCompoundType
{
public:
   /// Macro for declaring methods required to make a derived
   /// EcXmlObject concrete.
   ECXMLOBJECT(EcLinkKinematicsRandomVariation);

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets the random variation of linear measurement.
   /**
   This translation value is the one sigma value describing the uncertainty in the linear measurement of link geometry. This includes all x, y, and z directions.
   */
   virtual EcReal translationOneSigma
      (
      ) const;

   /// sets the random variation of linear measurement.
   virtual void setTranslationOneSigma
      (
      EcReal value
      );

   /// gets the random variation of angular measurement.
   /**
   This angle value is the one sigma value describing the uncertainty in the angular measurement of link geometry. This includes all x, y, and z directions.
   */
   virtual EcReal angleOneSigma
      (
      ) const;

   /// sets the random variation of angular measurement.
   virtual void setAngleOneSigma
      (
      EcReal value
      );

   /// get a randomized offset for link kinematics based on the random variations of this object.
   /**
   \param[out] random The randomized offset of link kinematics
   */
   virtual void getRandomLinkKinematicsOffset
      (
      EcCoordinateSystemTransformation& random
      ) const;

   /// get a randomized link kinematics based on a nominal link kinematics and the random variations of this object.
   /**
   \param[in] nominal The nominal link kinematics
   \param[out] random The randomized link kinematics
   */
   virtual void getRandomLinkKinematics
      (
      const EcLinkKinematics& nominal,
      EcLinkKinematics& random
      ) const;

   /// create an object with default values
   static EcLinkKinematicsRandomVariation defaultObject
      (
      );

protected:
   /// the one sigma value of random variation of translation
   EcXmlReal      m_TranslationOneSigma;

   /// the one sigma value of random variation of orientation
   EcXmlReal      m_AngleOneSigma;
};

#endif // ecLinkKinematicsRandomVariation_H_
