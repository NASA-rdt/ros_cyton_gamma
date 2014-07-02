#ifndef ecPositionState_H_
#define ecPositionState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecPositionState.h
/// @class EcPositionState
/// @brief A description of the positional state of an
///        individual manipulator.  The coordinate system
///        transformation describes the position and orientation
///        of the base represented in system coordinates.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecCoordSysXForm.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

/// Holds a description of the position state of a manipulator.
/** This includes the joint positions and the position of the base.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcPositionState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcPositionState
      (
      );

   /// destructor
   virtual ~EcPositionState
      (
      );

   /// copy constructor
   EcPositionState
      (
      const EcPositionState& orig
      );

   /// assignment operator
   EcPositionState& operator=
      (
      const EcPositionState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPositionState& orig
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

   /// gets joint positions - const version
   virtual const EcXmlRealVector& jointPositions
      (
      ) const;

   /// gets joint positions - nonconst version
   virtual EcXmlRealVector& jointPositions
      (
      );

   /// sets joint positiions
   virtual void setJointPositions
      (
      const EcXmlRealVector& jointPositions
      );

   /// gets coordinate system transformation - const version
   virtual const EcCoordinateSystemTransformation& coordSysXForm
      (
      ) const;

   /// gets coordinate system transformation - nonconst version
   virtual EcCoordinateSystemTransformation& coordSysXForm
      (
      );

   /// sets coordinate system transformation
   virtual void setCoordSysXForm
      (
      const EcCoordinateSystemTransformation& coordSysXForm
      );

   /// test for approximate equality
   virtual EcBoolean approxEq
      (
      const EcPositionState& posState2,
      EcReal tol
      ) const;

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

   /// read this object from a binary stream
   virtual EcBoolean readBin
      (
      std::istream& stream
      );

   /// write this object to a binary stream
   virtual EcBoolean writeBin
      (
      std::ostream& stream
      ) const;

   /// get a null link
   static EcPositionState nullObject
      (
      );

   /// interpolation between two position states.  The
   /// interpolation is linear for the joint values and base position.
   /// it is essentially linear over the surface of the hypersphere
   /// for base orientation.
   virtual EcBoolean linearInterpolation
      (
      const EcPositionState& positionState1,
      const EcPositionState& positionState2,
      const EcReal& factor
      );

protected:
   /// the vector of joint positions
   EcXmlRealVector                    m_JointPositions;

   /// the position and orientation of the base, represented
   /// in system coordinates.
   EcCoordinateSystemTransformation   m_CoordSysXForm;
};

/// a vector of manipulator position states
typedef EcXmlVectorType<EcPositionState> EcPositionStateVector;

#endif // ecPositionState_H_
