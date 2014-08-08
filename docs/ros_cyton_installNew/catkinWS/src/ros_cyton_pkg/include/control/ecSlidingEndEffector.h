#ifndef ecSlidingEndEffector_H_
#define ecSlidingEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecSlidingEndEffector.h
/// @class EcSlidingEndEffector
/// @brief A sliding end effector.  Modified from frame endeffector.  We will let it
///        move along x but fix everything else.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecFrameBasedEndEffector.h"

/** A sliding end effector.  Modified from frame endeffector.  We will let it
 * move along x but fix everything else.
*/
class EC_ACTIN_CONTROL_DECL EcSlidingEndEffector : public EcFrameBasedEndEffector
{
public:
   /// default constructor
   EcSlidingEndEffector
      (
      );

   /// destructor
   virtual ~EcSlidingEndEffector
      (
      );

   /// copy constructor
   EcSlidingEndEffector
      (
      const EcSlidingEndEffector& orig
      );

   /// assignment operator
   EcSlidingEndEffector& operator=
      (
      const EcSlidingEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSlidingEndEffector& orig
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
   /// For this end effector, it returns 5. It's free to move along the X direction
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
   static EcSlidingEndEffector nullObject
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

   /// calculate the frame in system
   virtual EcBoolean calculateFrameInSystem
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcCoordinateSystemTransformation& frameInSystem
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
typedef EcXmlVectorType<EcSlidingEndEffector> EcSlidingEndEffectorVector;

#endif // ecSlidingEndEffector_H_
