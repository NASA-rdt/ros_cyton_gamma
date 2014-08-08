#ifndef ecShapeVector_H_
#define ecShapeVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeVector.h
/// @class EcShapeVector
/// @brief implementation of the EcShapeVector class.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecShape.h"
#include <xml/ecXmlVarVectType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// A vector of base EcShape
typedef EcXmlVariableVectorType<EcShape> EcBaseShapeVector;

class EC_FOUNDATION_GEOMETRY_DECL EcShapeVector: public EcBaseShapeVector
{
public:
   /// constructor
   EcShapeVector
      (
      );

   /// destructor
   virtual ~EcShapeVector
      (
      );

   /// copy constructor
   EcShapeVector
      (
      const EcShapeVector& orig
      );

   /// assignment operator
   EcShapeVector& operator=
      (
      const EcShapeVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcShapeVector& orig
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

   /// scale the object in the container by the specified value
   /// (scaleFactor=1.0 does not change the object)
   virtual void scaleBy
      (
      EcReal scaleFactor
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
   static EcShapeVector nullObject
      (
      );
};

#endif // ecShapeVector_H_
