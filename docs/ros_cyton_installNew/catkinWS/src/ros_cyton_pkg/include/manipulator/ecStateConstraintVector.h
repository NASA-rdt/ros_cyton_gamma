#ifndef ecStateConstraintVector_H_
#define ecStateConstraintVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecStateConstraintVector.h
/// @class EcStateConstraintVector
/// @brief Vector of state constraints
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseStateConstraint.h"
#include <xml/ecXmlVarVectType.h>
#include <matrixUtilities/ecReArray.h>


/// type definition of XML variable vector of EcBaseStateConstraint to be used as a base class
typedef EcXmlVariableVectorType<EcBaseStateConstraint> EcBaseStateConstraintVector;

/// Vector of EcBaseStateConstraint
class EC_FOUNDATION_MANIPULATOR_DECL EcStateConstraintVector :
   public EcBaseStateConstraintVector
{
public:
   /// default constructor
   EcStateConstraintVector
      (
      );

   /// destructor
   virtual ~EcStateConstraintVector
      (
      );

   /// copy constructor
   EcStateConstraintVector
      (
      const EcStateConstraintVector& orig
      );

   /// assignment operator
   EcStateConstraintVector& operator=
      (
      const EcStateConstraintVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStateConstraintVector& orig
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
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

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

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
   static EcStateConstraintVector nullObject
      (
      );

protected:
   mutable EcReArray    m_Jacobian;    ///< The Jacobian
};

#endif // ecStateConstraintVector_H_
