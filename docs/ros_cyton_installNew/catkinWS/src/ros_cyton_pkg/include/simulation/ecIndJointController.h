#ifndef ecIndJointController_H_
#define ecIndJointController_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecIndJointController.h
/// @class EcIndividualJointController
/// @brief Holds a description of a feedback controller for a single joint.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseIndJointController.h"

/// Holds a description of a feedback controller for a single joint.
class EC_ACTIN_SIMULATION_DECL EcIndividualJointController : public EcBaseIndividualJointController
{
public:
   /// default constructor
   EcIndividualJointController
      (
      );

   /// destructor
   virtual ~EcIndividualJointController
      (
      );

   /// copy constructor
   EcIndividualJointController
      (
      const EcIndividualJointController& orig
      );

   /// assignment operator
   EcIndividualJointController& operator=
      (
      const EcIndividualJointController& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcIndividualJointController& orig
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

   /// gets the damping ratio
   virtual EcReal dampingRatio
      (
      ) const;

   /// sets the damping ratio
   virtual void setDampingRatio
      (
      EcReal dampingRatio
      );

   /// gets the controller frequency
   virtual EcReal undampedFrequency
      (
      ) const;

   /// sets the controller frequency
   virtual void setUndampedFrequency
      (
      EcReal undampedFrequency
      );

   /// gets the assumed inertia
   virtual EcReal assumedInertia
      (
      ) const;

   /// sets the assumed inertia
   virtual void setAssumedInertia
      (
      EcReal assumedInertia
      );

   /// gets the minimum output
   virtual EcReal minimumOutput
      (
      ) const;

   /// sets the minimum output
   virtual void setMinimumOutput
      (
      EcReal minimumOutput
      );

   /// gets the maximum output
   virtual EcReal maximumOutput
      (
      ) const;

   /// sets the maximum output
   virtual void setMaximumOutput
      (
      EcReal maximumOutput
      );

   /// gets position gain
   virtual EcReal explicitPositionGain
      (
      ) const;

   /// sets position gain
   virtual void setExplicitPositionGain
      (
      EcReal explicitPositionGain
      );

   /// gets velocity gain
   virtual EcReal explicitVelocityGain
      (
      ) const;

   /// sets velocity gain
   virtual void setExplicitVelocityGain
      (
      EcReal explicitVelocityGain
      );

   /// gets explicit flag
   virtual EcBoolean useExplicitGainsIgnoreDampingRatioAndFrequency
      (
      ) const;

   /// sets velocity gain
   virtual void setUseExplicitGainsIgnoreDampingRatioAndFrequency
      (
      EcBoolean useExplicitGainsIgnoreDampingRatioAndFrequency
      );

   /// calculates the control torque/force
   virtual EcReal control
      (
      EcReal actualPosition,
      EcReal desiredPosition,
      EcReal actualVelocity,
      EcReal desiredVelocity=0.0,
      EcReal extraneousInput=0.0
      ) const;

   /// calculate the 2% settling time bound
   virtual EcReal settlingTimeBound
      (
      ) const;

   /// gets the xml token used for writing out
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
   static EcIndividualJointController nullObject
      (
      );

   /// create an object with default values
   static EcIndividualJointController defaultObject
      (
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// the control parameters
   EcXmlReal             m_DampingRatio;              ///< damping ration
   EcXmlReal             m_UndampedFrequency;         ///< undamped frequency
   EcXmlReal             m_AssumedInertia;            ///< assmued inertia
   EcXmlReal             m_MinimumOutput;             ///< minimum output
   EcXmlReal             m_MaximumOutput;             ///< maximum output
   EcXmlReal             m_ExplicitPositionGain;      ///< explicit position gain
   EcXmlReal             m_ExplicitVelocityGain;      ///< explicit velocity gain
   /// if use explicit gains and ignore damping ration and frequency
   EcXmlBoolean          m_UseExplicitGainsIgnoreDampingRatioAndFrequency;
};

#include <xml/ecXmlMapType.h>
/// type definition of EcIndividualJointControllerCollection
typedef EcXmlMapType< EcXmlString, EcIndividualJointController>   EcIndividualJointControllerCollection;

#endif // ecIndJointController_H_
