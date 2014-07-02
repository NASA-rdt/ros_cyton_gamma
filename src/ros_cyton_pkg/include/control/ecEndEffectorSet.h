#ifndef ecEndEffectorSet_H_
#define ecEndEffectorSet_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecEndEffectorSet.h
/// @class EcEndEffectorSet
/// @brief A set of point and frame end effectors for a single
///        manipulator.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecContExpContainer.h"
#include "ecEndEffectorVector.h"
#include "ecJacobianTool.h"
#include "ecManipEndEffectorForce.h"
#include "ecManipEndEffectorVel.h"
#include <xml/ecXmlCompType.h>

/// Holds a description of all end effectors on a manipulator.
class EC_ACTIN_CONTROL_DECL EcEndEffectorSet : public EcXmlCompoundType
{
public:
   /// default constructor
   EcEndEffectorSet
      (
      );

   /// destructor
   virtual ~EcEndEffectorSet
      (
      );

   /// copy constructor
   EcEndEffectorSet
      (
      const EcEndEffectorSet& orig
      );

   /// assignment operator
   EcEndEffectorSet& operator=
      (
      const EcEndEffectorSet& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcEndEffectorSet& orig
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

   /// gets the label
   virtual const EcXmlString& label
      (
      ) const;

   /// sets the label
   virtual void setLabel
      (
      const EcXmlString& label
      );

   /// gets vector of general end effectors
   virtual const EcEndEffectorVector& endEffectors
      (
      ) const;

   /// sets vector of general end effectors
   virtual void setEndEffectors
      (
      const EcEndEffectorVector& endEffectors
      );

   /// sets size of general end effectors to zero
   virtual void setEndEffectorsSizeToZero
      (
      );

   /// pushes back a single end effector
   virtual void addEndEffector
      (
      const EcEndEffector& endEffector
      );

   /// remove a single end effector
   virtual void removeEndEffector
      (
      const EcU32 index
      );

   /// exchange an end effector with a new one, if the old one exists
   virtual EcBoolean exchange
      (
      EcU32 index,
      const EcEndEffector& endEffector
      );

   /// get the number of end effectors
   virtual EcU32 size
      (
      ) const;

   /// sets relative link data
   virtual EcBoolean setRelativeLinkData
      (
      EcU32 endEffectorIndex,
      const EcEndEffectorRelativeLinkData& relData
      );

   /// gets relative link data
   virtual const EcEndEffectorRelativeLinkData& relativeLinkData
      (
      EcU32 endEffectorIndex
      ) const;

   /// gets Jacobian tool
   virtual const EcJacobianTool& jacobianTool
      (
      ) const;

   /// build a matrix of end-effector error weights for the hard constraints.
   virtual void getHardErrorWeights
      (
      EcReArray& weights
      ) const;

   /// build a matrix of end-effector error weights for the soft constraints.
   virtual void getSoftErrorWeights
      (
      EcReArray& weights
      ) const;

   /// build a matrix of end-effector error weights for all constraints.
   virtual void getAllErrorWeights
      (
      EcReArray& weights
      ) const;

   /// build a matrix of end-effector error weights for the specified indices
   virtual void getErrorWeights
      (
      const EcU32Vector& endEffectorIndices,
      EcReArray& weights
      ) const;

   /// get the degrees of hard constraint
   virtual EcU32 hardDoc
      (
      ) const;

   /// get the degrees of soft constraint
   virtual EcU32 softDoc
      (
      ) const;

   /// get the total degrees of constraint
   virtual EcU32 allDoc
      (
      ) const;

   /// get the degrees of freedom of all specified end effectors
   virtual EcU32 doc
      (
      const EcU32Vector& endEffectorIndices
      ) const;

   /// create a compatible, zero end-effector velocity for hard constraints
   virtual EcManipulatorEndEffectorVelocity hardCompatibleZeroVelocity
      (
      ) const;

   /// create a compatible, zero end-effector velocity for soft constraints
   virtual EcManipulatorEndEffectorVelocity softCompatibleZeroVelocity
      (
      ) const;

   /// create a compatible, zero end-effector velocity for all constraints
   virtual EcManipulatorEndEffectorVelocity allCompatibleZeroVelocity
      (
      ) const;

   /// create a compatible, zero end-effector velocity based on the indices given
   virtual EcManipulatorEndEffectorVelocity compatibleZeroVelocity
      (
      const EcU32Vector& endEffectorIndices
      ) const;

   /// create a compatible, zero end-effector force for the hard constraints
   virtual EcManipulatorEndEffectorForce hardCompatibleZeroForce
      (
      ) const ;

   /// create a compatible, zero end-effector force for the soft constraints
   virtual EcManipulatorEndEffectorForce softCompatibleZeroForce
      (
      ) const ;

   /// create a compatible, zero end-effector force for all constraints
   virtual EcManipulatorEndEffectorForce allCompatibleZeroForce
      (
      ) const ;

   /// create a compatible, zero end-effector force based on the indices given
   virtual EcManipulatorEndEffectorForce compatibleZeroForce
      (
      const EcU32Vector& endEffectorIndices
      ) const ;

   /// set the end-effector data structure from a column array for hard constraints
   virtual void setHardVelocityFromColumn
      (
      EcManipulatorEndEffectorVelocity& handVelocity,
      const EcReArray& handVelocityColumn
      ) const;

   /// set the end-effector data structure from a column array for soft constraints
   virtual void setSoftVelocityFromColumn
      (
      EcManipulatorEndEffectorVelocity& handVelocity,
      const EcReArray& handVelocityColumn
      ) const;

   /// set the end-effector data structure from a column array for all constraints
   virtual void setAllVelocityFromColumn
      (
      EcManipulatorEndEffectorVelocity& handVelocity,
      const EcReArray& handVelocityColumn
      ) const;

   /// set the end-effector data structure from a column array using the
   /// end-effector indices provided.
   virtual void setVelocityFromColumn
      (
      const EcU32Vector& endEffectorIndices,
      EcManipulatorEndEffectorVelocity& handVelocity,
      const EcReArray& handVelocityColumn
      ) const;

   /// calculate manipulator Jacobian for the hard constraints.  If given a container,
   /// initialize the jacobian parameters.
   virtual EcBoolean getHardJacobian
      (
      const EcControlExpressionContainer* container,
      EcManipulatorJacobian& jacobian
      ) const;

   /// calculate manipulator Jacobian for the soft constraints.  If given a container,
   /// initialize the jacobian parameters.
   virtual EcBoolean getSoftJacobian
      (
      const EcControlExpressionContainer* container,
      EcManipulatorJacobian& jacobian
      ) const;

   /// calculate manipulator Jacobian for all constraints.  If given a container,
   /// initialize the jacobian parameters.
   virtual EcBoolean getAllJacobian
      (
      const EcControlExpressionContainer* container,
      EcManipulatorJacobian& jacobian
      ) const;

   /// calculate manipulator Jacobian from the specified indices.  If given a container,
   /// initialize the jacobian parameters.
   virtual EcBoolean getJacobian
      (
      const EcU32Vector& endEffectorIndices,
      const EcControlExpressionContainer* container,
      EcManipulatorJacobian& jacobian
      ) const;

   /// gets the indices, in order, of the hard constraints
   virtual const EcU32Vector& hardConstraintIndices
      (
      ) const;

   /// gets the indices, in order, of the soft constraints
   virtual const EcU32Vector& softConstraintIndices
      (
      ) const;

   /// gets the indices, in order, of the all constraints
   virtual const EcU32Vector& allConstraintIndices
      (
      ) const;

   /// set the speed factor for all end-effectors in the set
   virtual void setSpeedFactor
      (
      EcReal value
      );

   /// set the speed factor for the end-effector specified by index.
   /// Returns false if index is not valid or true otherwise.
   virtual EcBoolean setSpeedFactor
      (
      EcU32 index,
      EcReal value
      );

   /// set whether filtering is active for all end-effectors in the set
   virtual void setFilteringActive
      (
      EcBoolean value
      );

   /// set the external offset pointer for the end-effector specified by index
   /// Returns false if index is not valid or true otherwise.
   virtual EcBoolean setExternalOffsetPointer
      (
      EcU32 index,
      const EcCoordinateSystemTransformation* offset
      );
   
   /// set filtering of end-effector specified by index to be active or inactive
   virtual EcBoolean setFilteringActive
      (
      EcU32 index,
      EcBoolean value
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
   static EcEndEffectorSet nullObject
      (
      );

   /// Initializes sparsity matrix
   virtual void initializeSparsityMatrix
      (
      const EcControlExpressionContainer& container
      );

   /// create a default end-effector set from a manipulator
   static EcEndEffectorSet createDefaultFromManipulator
      (
      const EcIndividualManipulator& manipulator
      );

protected:

   /// create vectors holding information on the hard and soft constraints
   virtual void trackHardAndSoftContstraints
      (
      );

   /// the label
   EcXmlString         m_Label;

   /// a vector of general end effectors
   EcEndEffectorVector m_EndEffectors;

   /// a tracker for hard constraints
   EcU32Vector         m_HardConstraintIndices;

   /// a tracker for soft constraints
   EcU32Vector         m_SoftConstraintIndices;

   /// a tracker for all constraint indices
   EcU32Vector         m_AllConstraintIndices;

   /// utility Jacobian tool
   mutable EcJacobianTool m_JacobianTool;
};

/// a vector of end-effector sets
typedef EcXmlVectorType<EcEndEffectorSet> EcEndEffectorSetVector;

#endif // ecEndEffectorSet_H_
