#ifndef ecGeneralBoundObjectVector_H_
#define ecGeneralBoundObjectVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecGeneralBoundObjectVector.h
/// @class EcGeneralBoundObjectVector
/// @brief implementation of the EcGeneralBoundObjectVector class.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseGeneralBoundObject.h"
#include <xml/ecXmlVarVectType.h>

/// type definition of XML variable vector of EcBaseGeneralBoundObject to be used as a base class
typedef EcXmlVariableVectorType<EcBaseGeneralBoundObject> EcBaseGeneralBoundObjectVector;

class EC_FOUNDATION_MANIPULATOR_DECL EcGeneralBoundObjectVector: public EcBaseGeneralBoundObjectVector
{
public:
   /// constructor
	EcGeneralBoundObjectVector();

   /// destructor
	virtual ~EcGeneralBoundObjectVector();

   /// copy constructor
   EcGeneralBoundObjectVector
      (
      const EcGeneralBoundObjectVector& orig
      );

   /// assignment operator
   EcGeneralBoundObjectVector& operator=
      (
      const EcGeneralBoundObjectVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGeneralBoundObjectVector& orig
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
   static EcGeneralBoundObjectVector nullObject
      (
      );
};

#endif // ecGeneralBoundObjectVector_H_
