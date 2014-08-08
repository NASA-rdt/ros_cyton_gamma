#ifndef ecWlsSoftConstraintHandler_H_
#define ecWlsSoftConstraintHandler_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecWlsSoftConstraintHandler.h
/// @class EcWlsSoftConstraintHandler
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include "ecBaseSoftConstraintHandler.h"
#include <xml/ecXmlBasicType.h>
#include <matrixUtilities/ecReArray.h>

class EcTargetTypeInformation;
class EcTargetState;
class EcManipulatorActivePositionState;
class EcEndEffectorSet;

/** Holds a description of a soft-constraint handler that minimizes the
weighted least squares of the desired end-effector velocity error.  If
e_old is the old optimization criterion, then this soft constraint
handler optimizes e=e_old+weight*(Jq_dot-V)^T W (Jq_dot-V).
*/
class EC_ACTIN_CONTROL_DECL EcWlsSoftConstraintHandler : public EcBaseSoftConstraintHandler
{
public:
   /// default constructor
   EcWlsSoftConstraintHandler
      (
      );

   /// constructor with a weight
   EcWlsSoftConstraintHandler
      (
      const EcReal& weight
      );

   /// destructor
   virtual ~EcWlsSoftConstraintHandler
      (
      );

   /// copy constructor
   EcWlsSoftConstraintHandler
      (
      const EcWlsSoftConstraintHandler& orig
      );

   /// assignment operator
   EcWlsSoftConstraintHandler& operator=
      (
      const EcWlsSoftConstraintHandler& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcWlsSoftConstraintHandler& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components with the parent
   virtual void registerComponents
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

   /// get weight
   virtual EcReal weight
      (
      ) const;

   /// set weight
   virtual void setWeight
      (
      EcReal weight
      );

   /// take the input values and integrate soft-constraint optimization
   /// this method is for use with the primary core
   virtual void integrateSoftConstraints
      (
      const EcReArray& matrixIn,
      const EcReArray& vectorIn,
      const EcReArray& scalarIn,
      const EcControlExpressionContainer* pContainerIn,
      const EcReArray*& pMatrixOut,
      const EcReArray*& pVectorOut,
      const EcReArray*& pScalarOut
      ) const;

   /// take the input values and integrate soft-constraint optimization
   /// this method is for use with the AB core.
   virtual void integrateSoftConstraintsAB
      (
      const EcReArray& matrixIn,
      const EcReArray& vectorIn,
      const EcReArray& scalarIn,
      const EcControlExpressionContainer* pContainerIn,
      const EcReArray*& pMatrixOut,
      const EcReArray*& pVectorOut,
      const EcReArray*& pScalarOut
      ) const;

   /// get the pointers needed for velocity control access
   /// assume the container pointer is valid
   virtual void getPointers
      (
      const EcControlExpressionContainer*& pContainer,
      EcManipulatorActivePositionState*& pActPosState,
      const EcEndEffectorSet*& pEndEffectorSet
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
   static EcWlsSoftConstraintHandler nullObject
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
   /// the weight used to scale the influence of the soft-constraint optimization
   EcXmlReal                                m_Weight;

   // non-XML data below

   // general control parameters
   mutable EcReArray                        m_Matrix; ///< Matrix used in general control
   mutable EcReArray                        m_Vector; ///< Vector used in general control
   mutable EcReArray                        m_Scalar; ///< Scalar used in general control

   // special AB control parameters
   mutable EcReArray                        m_JSNJ;      ///< the soft-Jacobian null space
   mutable EcReArray                        m_MatrixAB;  ///< Matrix used in AB control
   mutable EcReArray                        m_VectorAB;  ///< Vector used in AB control
   mutable EcReArray                        m_ScalarAB;  ///< Scalar used in AB control

   // utility hand-motion vectors
   mutable EcRealVector m_UtilityHandMotion;          ///< utility hand motion
   mutable EcRealVector m_WeightedUtilityHandMotion;  ///< weighted utility hand motion

   /// utility weights
   mutable EcReArray    m_UtilityWeights;

   /// a utility array for representing W*J
   mutable EcReArray    m_WJ;
};

#endif // ecWlsSoftConstraintHandler_H_
