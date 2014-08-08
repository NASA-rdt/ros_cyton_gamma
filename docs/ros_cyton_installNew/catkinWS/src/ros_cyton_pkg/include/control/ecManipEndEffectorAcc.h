#ifndef ecManipEndEffectorAcc_H_
#define ecManipEndEffectorAcc_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipEndEffectorAcc.h
/// @class EcManipulatorEndEffectorAcceleration
/// @brief Holds a description of the accelerations of all end effectors
///        on a manipulator.  The accelerations of frames are general
///        accelerations and of points are vector accelerations.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCommon/ecCoordSysXForm.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

/// Holds a description of the accelerations of all end effectors on a manipulator.
/** The accelerations of frames are general accelerations and of points are vector accelerations.
*/
class EC_ACTIN_CONTROL_DECL EcManipulatorEndEffectorAcceleration : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorEndEffectorAcceleration
      (
      );

   /// destructor
   virtual ~EcManipulatorEndEffectorAcceleration
      (
      );

   /// copy constructor
   EcManipulatorEndEffectorAcceleration
      (
      const EcManipulatorEndEffectorAcceleration& orig
      );

   /// assignment operator
   EcManipulatorEndEffectorAcceleration& operator=
      (
      const EcManipulatorEndEffectorAcceleration& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorEndEffectorAcceleration& orig
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

   /// gets vector of general end-effector accelerations - const version
   virtual const EcXmlRealVectorVector& generalEndEffectorAccelerations
      (
      ) const;

   /// gets vector of general end-effector accelerations - nonconst version
   virtual EcXmlRealVectorVector& generalEndEffectorAccelerations
      (
      );

   /// sets vector of general end-effector accelerations
   virtual void setGeneralEndEffectorAccelerations
      (
      const EcXmlRealVectorVector& generalEndEffectorAccelerations
      );

   /// gets the motion as a single vector, with the
   /// point accelerations in order first, followed by the frame
   /// accelerations
   virtual void getSingleVector
      (
      EcRealVector& singleVector
      ) const;

   /// gets the degrees of constraint (i.e., the degrees of freedom
   /// in hand motion
   virtual EcU32 doc
      (
      ) const;

   /// get transformation of offset to the primary frame of the relative link
   virtual const EcCoordinateSystemTransformationVector& offsetTransformations
      (
      ) const;

   /// set transformation of offset to the primary frame of the relative link
   virtual void setOffsetTransformations
      (
      const EcCoordinateSystemTransformationVector& offsetTransformation
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

   /// get a null link
   static EcManipulatorEndEffectorAcceleration nullObject
      (
      );

protected:
   /// an transformation of offset to the primary frame of the relative link
   EcCoordinateSystemTransformationVector m_OffsetTransformations;

   /// a vector of acceleration descriptions for general end effectors
   EcXmlRealVectorVector                   m_GeneralEndEffectorAccelerations;
};

/// a vector of end-effector sets
typedef EcXmlVectorType<EcManipulatorEndEffectorAcceleration>
   EcManipulatorEndEffectorAccelerationVector;

#endif // ecManipEndEffectorAcc_H_
