#ifndef ecDataCaptureTypeVector_H_
#define ecDataCaptureTypeVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecDataCaptureTypeVector.h
/// @class EcDataCaptureTypeVector
/// @brief Holds a description of a vector of general data capture configurations.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarVectType.h>

#include "ecDataCaptureType.h"

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/**
\class EcDataCaptureTypeVector
\author Chalongath Pholsiri
\brief Holds a description of a vector of general data capture configurations.
*/
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcDataCaptureTypeVector : public EcXmlVariableVectorType<EcDataCaptureType>
{
public:
   /// default constructor
   EcDataCaptureTypeVector
      (
      );

   /// destructor
   virtual ~EcDataCaptureTypeVector
      (
      );

   /// copy constructor
   EcDataCaptureTypeVector
      (
      const EcDataCaptureTypeVector& orig
      );

   /// assignment operator
   EcDataCaptureTypeVector& operator=
      (
      const EcDataCaptureTypeVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDataCaptureTypeVector& orig
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

   /// return a data capture configuration object for the specified tokens or NULL if token is invalid or no configuration object for that token
   /**
   \param[in] token The string token.
   \param[out] pIndex If provided, upon return, it will point to the index of the returned data capture in the vector.
   */
   virtual const EcDataCaptureType* findDataCaptureByToken
      (
      const EcToken& token,
      EcU32* pIndex = EcNULL
      ) const;

   /// return a NEW data capture configuration given a token
   virtual EcDataCaptureType* newDataCaptureByToken
      (
      const EcToken& token
      );

   /// get a null object
   static EcDataCaptureTypeVector nullObject
      (
      );
};

#endif // ecDataCaptureTypeVector_H_
