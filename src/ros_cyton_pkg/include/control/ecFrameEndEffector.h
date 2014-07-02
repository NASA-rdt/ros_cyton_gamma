#ifndef ecFrameEndEffector_H_
#define ecFrameEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecFrameEndEffector.h
/// @class EcFrameEndEffector
/// @brief A frame end effector.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecFrameBasedEndEffector.h"

/** Holds a description of a frame end-effector, which has 6 degrees of constraints -
 * 3 translations and 3 rotations. This is what typical users consider an end-effector
 * in general sense.
*/
class EC_ACTIN_CONTROL_DECL EcFrameEndEffector : public EcFrameBasedEndEffector
{
public:
   /// default constructor
   EcFrameEndEffector
      (
      );

   /// destructor
   virtual ~EcFrameEndEffector
      (
      );

   /// copy constructor
   EcFrameEndEffector
      (
      const EcFrameEndEffector& orig
      );

   /// assignment operator
   EcFrameEndEffector& operator=
      (
      const EcFrameEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcFrameEndEffector& orig
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
   /// For this end effector, it returns 6.
   virtual EcU32 doc
      (
      ) const;

   /// @copydoc EcEndEffector::insertJacobianComponent()
   virtual void insertJacobianComponent
      (
      const EcIndividualManipulator& manip,
      const EcU32 startRow,
      const EcEndEffectorRelativeLinkData& relativeLinkData,
      EcBoolean isFixedBase,
      EcManipulatorActiveState&  activeState,
      EcManipulatorJacobian& jacobian
      ) const;

   /// @copydoc EcEndEffector::insertSparsityComponent()
   virtual void insertSparsityComponent
      (
      const EcIndividualManipulator& manip,
      const EcU32 startRow,
      const EcEndEffectorRelativeLinkData& relativeLinkData,
      EcBoolean isFixedBase,
      EcBooleanVectorVector& sparsityDescriptionMatrix
      ) const;

   /// @copydoc EcEndEffector::insertErrorWeightComponent()
   virtual void insertErrorWeightComponent
      (
      const EcU32 startRow,
      EcReArray& weights
      ) const;

   /// For this end effector, it's the coordinate system transformation of the end effector @n
   /// @copydoc EcEndEffector::calculatePlacement()
   virtual void calculatePlacement
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcEndEffectorPlacement& placement
      ) const;

   /// For this end effector, it's the 6-dof general velocity of the end effector @n
   /// @copydoc EcEndEffector::calculateVelocity()
   virtual void calculateVelocity
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& velocity,
      EcU32 startInsertionIndex=0
      ) const;

   /// For this end effector, it's the 6-dof general acceleration of the end effector @n
   /// @copydoc EcEndEffector::calculateAcceleration()
   virtual void calculateAcceleration
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& acceleration,
      EcU32 startInsertionIndex=0
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
   static EcFrameEndEffector nullObject
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

   /// @copydoc EcEndEffector::minimumTime()
   virtual EcReal minimumTime
      (
      const EcEndEffectorPlacement& actual,
      const EcEndEffectorPlacement& desired
      ) const;

   /// @copydoc EcEndEffector::difference()
   virtual EcReal difference
      (
      const EcEndEffectorPlacement& actual,
      const EcEndEffectorPlacement& desired
      ) const;

};

/// a vector of frame end effectors
typedef EcXmlVectorType<EcFrameEndEffector> EcFrameEndEffectorVector;

#endif // ecFrameEndEffector_H_
