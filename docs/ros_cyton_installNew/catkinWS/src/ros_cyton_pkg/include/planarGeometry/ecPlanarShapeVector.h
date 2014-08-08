#ifndef ecPlanarShapeVector_H_
#define ecPlanarShapeVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecPlanarShapeVector.h
/// @class EcPlanarShapeVector
/// @brief implementation of the EcPlanarShapeVector class.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecPlanarShapeContainer.h"

#include <xml/ecXmlVectorType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// type definition of EcBasePlanarShapeVector
typedef EcXmlVectorType<EcPlanarShapeContainer> EcBasePlanarShapeVector;

class EC_FOUNDATION_PLANARGEOMETRY_DECL EcPlanarShapeVector: public EcBasePlanarShapeVector
{
public:
   /// constructor
   EcPlanarShapeVector
      (
      );

   /// destructor
   virtual ~EcPlanarShapeVector
      (
      );

   /// copy constructor
   EcPlanarShapeVector
      (
      const EcPlanarShapeVector& orig
      );

   /// assignment operator
   EcPlanarShapeVector& operator=
      (
      const EcPlanarShapeVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPlanarShapeVector& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
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

   /// get a null object
   static EcPlanarShapeVector nullObject
      (
      );

   /// returns a class token
   static const EcToken& classToken
      (
      );

   /// return a string token
   virtual const EcToken& token
      (
      ) const;
};

#endif // ecPlanarShapeVector_H_
