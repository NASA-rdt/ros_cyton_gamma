#ifndef ecLookAtEndEffector_H_
#define ecLookAtEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecLookAtEndEffector.h
/// @class EcLookAtEndEffector
/// @brief A look-at end effector.  This end effector is defined by a point on the link
///        and a vector looking down the x-axis of the link to a point (focalLength)
///        away from the point on the link.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecFrameBasedEndEffector.h"

/** Holds a look-at end-effector component. This end effector is defined by a point on the link
 * and a vector looking down the x-axis of the link to a point (focalLength) away from the point on the link.
*/
class EC_ACTIN_CONTROL_DECL EcLookAtEndEffector : public EcFrameBasedEndEffector
{
public:
   /// default constructor
   EcLookAtEndEffector
      (
      );

   /// destructor
   virtual ~EcLookAtEndEffector
      (
      );

   /// copy constructor
   EcLookAtEndEffector
      (
      const EcLookAtEndEffector& orig
      );

   /// assignment operator
   EcLookAtEndEffector& operator=
      (
      const EcLookAtEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLookAtEndEffector& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// @copydoc EcEndEffector::doc()
   /// For this end effector, it returns 2 for look at--points to camera (pan/tilt)
   virtual EcU32 doc
      (
      ) const;

   /// @copydoc EcEndEffector::insertJacobianComponent
   virtual void insertJacobianComponent
      (
      const EcIndividualManipulator& manip,
      const EcU32 startRow,
      const EcEndEffectorRelativeLinkData& relativeLinkData,
      EcBoolean isFixedBase,
      EcManipulatorActiveState&  activeState,
      EcManipulatorJacobian& jacobian
      ) const;

   /// @copydoc EcEndEffector::insertSparsityComponent
   virtual void insertSparsityComponent
      (
      const EcIndividualManipulator& manip,
      const EcU32 startRow,
      const EcEndEffectorRelativeLinkData& relativeLinkData,
      EcBoolean isFixedBase,
      EcBooleanVectorVector& sparsityDescriptionMatrix
      ) const;

   /// @copydoc EcEndEffector::insertErrorWeightComponent
   virtual void insertErrorWeightComponent
      (
      const EcU32 startRow,
      EcReArray& weights
      ) const;

   /// @copydoc EcEndEffector::calculatePlacement
   virtual void calculatePlacement
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcEndEffectorPlacement& placement
      ) const;

   /// @copydoc EcEndEffector::calculateVelocity
   virtual void calculateVelocity
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& velocity,
      EcU32 startInsertionIndex=0
      ) const;

   /// @copydoc EcEndEffector::calculateAcceleration
   virtual void calculateAcceleration
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& acceleration,
      EcU32 startInsertionIndex=0
      ) const;

   using EcFrameBasedEndEffector::filterFrameEndEffectorVelocity;
   /// @copydoc EcFrameBasedEndEffector::filterFrameEndEffectorVelocity
   virtual void filterFrameEndEffectorVelocity
      (
      const EcIndividualManipulator& manip,
      const EcCoordinateSystemTransformation& guide,
      const EcGeneralVelocity& inputFrameVelocity,
      const EcGeneralVelocity& lastFrameVelocity,
      EcReal timeStep,
      EcManipulatorActiveState&  activeState,
      EcGeneralVelocity& filteredFrameVelocity
      ) const;

   /// @copydoc EcEndEffector::filterEndEffectorVelocity
   virtual void filterEndEffectorVelocity
      (
      const EcIndividualManipulator& manip,
      const EcEndEffectorPlacement& guide,
      const EcXmlRealVector& inputVelocity,
      const EcXmlRealVector& lastVelocity,
      EcReal timeStep,
      EcManipulatorActiveState&  activeState,
      EcXmlRealVector& filteredVelocity
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

   /// get a null point end effector
   static EcLookAtEndEffector nullObject
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

   /// @copydoc EcEndEffector::minimumTime
   virtual EcReal minimumTime
      (
      const EcEndEffectorPlacement& actual,
      const EcEndEffectorPlacement& desired
      ) const;

   /// @copydoc EcEndEffector::difference
   virtual EcReal difference
      (
      const EcEndEffectorPlacement& actual,
      const EcEndEffectorPlacement& desired
      ) const;

   /// get the values of all editable components
   virtual const EcXmlStringVector& editableValues
      (
      ) const;

   /// set the values of the editable components
   virtual void setEditableValues
      (
      const EcXmlStringVector& values
      );

   /// get the focus distance.  This is the distance the sensor is
   virtual const EcReal& focusDistance
      (
      );

   /// set the focus distance.  This is the distance the sensor is
   virtual void setFocusDistance
      (
      const EcReal& value
      );

protected:
   /// the error weight for the angular components
   EcXmlReal             m_AngularErrorWeight;

   /// the distance to the object we are focusing on
   EcXmlReal             m_FocusDistance;
};

/// a vector of frame end effectors
typedef EcXmlVectorType<EcLookAtEndEffector> EcLookAtEndEffectorVector;

#endif // ecLookAtEndEffector_H_
