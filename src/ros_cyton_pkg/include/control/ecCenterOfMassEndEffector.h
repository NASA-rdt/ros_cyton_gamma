#ifndef ecCenterOfMassEndEffector_H_
#define ecCenterOfMassEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecCenterOfMassEndEffector.h
/// @class EcCenterOfMassEndEffector
/// @brief A center-of-mass constraint.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecPointBasedEndEffector.h"

/// A center-of-mass constraint.
class EC_ACTIN_CONTROL_DECL EcCenterOfMassEndEffector : public EcPointBasedEndEffector
{
public:
   /// default constructor
   EcCenterOfMassEndEffector
      (
      );

   /// destructor
   virtual ~EcCenterOfMassEndEffector
      (
      );

   /// copy constructor
   EcCenterOfMassEndEffector
      (
      const EcCenterOfMassEndEffector& orig
      );

   /// assignment operator
   EcCenterOfMassEndEffector& operator=
      (
      const EcCenterOfMassEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCenterOfMassEndEffector& orig
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

   /// gets the error weight
   virtual const EcReal& errorWeight
      (
      ) const;

   /// sets the error weight
   virtual void setErrorWeight
      (
      const EcReal& errorWeight
      );

   /// @copydoc EcEndEffector::doc()
   /// For this end effector, it returns 3.
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

   /// calculate a vector placement value for the end effector
   /// @param[in] manip The manipulator for this end effector
   /// @param[in,out] activeState The manipulator active state
   /// @param[out] pointPlacement The point placement
   virtual void calculatePointPlacement
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcVector& pointPlacement
      ) const;

   /// calculate a placement value for the center of mass
   /// @copydoc EcEndEffector::calculatePlacement
   virtual void calculatePlacement
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcEndEffectorPlacement& placement
      ) const;

   /// calculate center-of-mass velocity.
   /// @copydoc EcEndEffector::calculateVelocity
   virtual void calculateVelocity
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& velocity,
      EcU32 startInsertionIndex=0
      ) const;

   /// calculate center-of-mass acceleration.
   /// @copydoc EcEndEffector::calculateAcceleration
   virtual void calculateAcceleration
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& acceleration,
      EcU32 startInsertionIndex=0
      ) const;

   /// read this object from an XML stream
   /// param[in] stream   (EcXmlReader&) input stream to be read into.
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   /// param[in] stream   (EcXmlWriter&) stream to be written into file
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null point end effector
   /// @return The center of mass end effector
   static EcCenterOfMassEndEffector nullObject
      (
      );

   /// token for this class
   /// @return The class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return   (EcXmlObject*) The xml object
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

   /// get the labels of all editable components
   /// @return   (EcXmlStringVector&) The editing label values TODO
   virtual const EcXmlStringVector& editingLabels
      (
      ) const;

   /// get the values of all editable components
   /// @return   (EcXmlStringVector&) The editable label values TODO
   virtual const EcXmlStringVector& editableValues
      (
      ) const;

   /// @copydoc EcEndEffector::setEditableValues()
   virtual void setEditableValues
      (
      const EcXmlStringVector& values
      );

protected:
   /// calculate the velocity of the center of mass in the link's
   /// kinematic frame due to unit joint motion of the inboard link.
   /// @param[in] link (EcManipulatorLink&) TODO
   /// @param[in] activeState (EcManipulatorActiveState&) TODO
   virtual EcVector firstMomentRate
      (
      const EcManipulatorLink& link,
      EcManipulatorActiveState& activeState
      ) const;


protected:
   /// the error weight for this end effector
   EcXmlReal             m_ErrorWeight;
};

/// a vector of point end effectors
typedef EcXmlVectorType<EcCenterOfMassEndEffector> EcCenterOfMassEndEffectorVector;

#endif // ecCenterOfMassEndEffector_H_
