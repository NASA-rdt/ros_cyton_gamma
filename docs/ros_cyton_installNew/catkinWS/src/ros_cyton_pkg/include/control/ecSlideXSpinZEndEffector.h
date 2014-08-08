#ifndef ecSlideXSpinZEndEffector_H_
#define ecSlideXSpinZEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecSlideXSpinZEndEffector.h
/// @class EcSlideXSpinZEndEffector
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecFrameBasedEndEffector.h"

/** Holds an end effector that is free to move along the X direction and rotate around Z axis
 * but constrained in other directions
*/

class EC_ACTIN_CONTROL_DECL EcSlideXSpinZEndEffector : public EcFrameBasedEndEffector
{
public:

   /// default constructor
   EcSlideXSpinZEndEffector
      (
      );

   /// destructor
   virtual ~EcSlideXSpinZEndEffector
      (
      );

   /// copy constructor
   EcSlideXSpinZEndEffector
      (
      const EcSlideXSpinZEndEffector& orig
      );

   /// assignment operator
   EcSlideXSpinZEndEffector& operator=
      (
      const EcSlideXSpinZEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSlideXSpinZEndEffector& orig
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
   /// For this end effector, it returns 4. It's free to move along the X direction and rotate around Z axis
   /// but constrained in other directions
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
   static EcSlideXSpinZEndEffector nullObject
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

private:

   /// the end-effector frame with respect to the system
   mutable EcCoordinateSystemTransformation  m_FrameInSystem;

   /// temporary jacobian used to store jacobian in the system coordinates,
   /// we then convert everything into the end effector frame and then skip
   /// the x components.
   mutable EcManipulatorJacobian m_JacobianInSystem;

   /// temporary jacobian used to store jacobian in the EE frame coordinates,
   mutable EcManipulatorJacobian m_JacobianInEE;

   /// temp rotational matrix
   mutable EcReArray             m_R;

};

/// a vector of frame end effectors
typedef EcXmlVectorType<EcSlideXSpinZEndEffector> EcSlideXSpinZEndEffectorVector;

#endif // ecSlideXSpinZEndEffector_H_
