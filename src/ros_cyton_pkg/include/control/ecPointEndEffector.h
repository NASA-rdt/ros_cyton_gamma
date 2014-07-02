#ifndef ecPointEndEffector_H_
#define ecPointEndEffector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecPointEndEffector.h
/// @class EcPointEndEffector
/// @brief A point end effector.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecPointBasedEndEffector.h"

/** Holds a description of a frame end-effector, which has 3 degrees of translational constraints.
*/
class EC_ACTIN_CONTROL_DECL EcPointEndEffector : public EcPointBasedEndEffector
{
public:
   /// default constructor
   EcPointEndEffector
      (
      );

   /// destructor
   virtual ~EcPointEndEffector
      (
      );

   /// copy constructor
   EcPointEndEffector
      (
      const EcPointEndEffector& orig
      );

   /// assignment operator
   EcPointEndEffector& operator=
      (
      const EcPointEndEffector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPointEndEffector& orig
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

   /// gets the point
   virtual const EcVector& point
      (
      ) const;
   /// sets the point
   virtual void setPoint
      (
      const EcVector& point
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
   virtual void calculatePointPlacement
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcVector& pointPlacement
      ) const;

   /// For this end effector, it's the 3D position of the end effector. @n
   /// @copydoc EcEndEffector::calculatePlacement
   virtual void calculatePlacement
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcEndEffectorPlacement& placement
      ) const;

   /// For this end effector, it's the linear velocity of the end effector. @n
   /// @copydoc EcEndEffector::calculateVelocity
   virtual void calculateVelocity
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& velocity,
      EcU32 startInsertionIndex=0
      ) const;

   /// For this end effector, it's the linear acceleration of the end effector. @n
   /// @copydoc EcEndEffector::calculateAcceleration
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
   static EcPointEndEffector nullObject
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

protected:
   /// return either the local point or total pint depending on whether external offset is used
   const EcVector pointOffset
      (
      ) const;

   /// the point describing the end effector
   EcXmlVector           m_Point;

   /// the error weight for this end effector
   EcXmlReal             m_ErrorWeight;
};

/// a vector of point end effectors
typedef EcXmlVectorType<EcPointEndEffector> EcPointEndEffectorVector;

#endif // ecPointEndEffector_H_
