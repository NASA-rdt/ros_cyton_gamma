#ifndef ecTableFunctionVectorSearch_H_
#define ecTableFunctionVectorSearch_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecTableFunctionVectorSearch.h
/// @class EcTableFunctionVectorSearch
/// @brief This class give XML file access to EcVectorSearch
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

#include "ecVectorSearch.h"
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlEnumType.h>
#include <xml/ecXmlVectorType.h>

/// Independent variable class for table functions
/**
   Holds a description of an independent variable with read/write XML access
*/
class EC_FOUNDATION_FUNCTION_DECL EcTableFunctionVectorSearch : public EcXmlCompoundType
{
public:
   /// default constructor
   EcTableFunctionVectorSearch
      (
      );

   /// destructor
   virtual ~EcTableFunctionVectorSearch
      (
      );

   /// copy constructor
   EcTableFunctionVectorSearch
      (
      const EcTableFunctionVectorSearch& orig
      );

   /// assignment operator
   EcTableFunctionVectorSearch& operator=
      (
      const EcTableFunctionVectorSearch& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcTableFunctionVectorSearch& orig
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

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// return a string token
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

   /// init object
   virtual EcBoolean init
      (
      );

   /// set independent data vector
   virtual void independentVector
      (
      const EcRealVector& vIndependentVector
      );

   /// set boundary option
   virtual void lowerBoundaryOption
      (
      const EcVectorSearchEnums::BOUNDARY_OPTION& boundaryOption
      );

   /// set boundary option
   virtual void upperBoundaryOption
      (
      const EcVectorSearchEnums::BOUNDARY_OPTION& boundaryOption
      );

   /// set search option
   virtual void searchOption
      (
      const EcVectorSearchEnums::SEARCH_OPTION& searchOption
      );

   /// get a vector of dimensions
   virtual EcVectorSearch<EcReal>& dimension
      (
      ) const;

   /// get a null object
   static EcTableFunctionVectorSearch nullObject
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
   /// XML vector containing independent data
   EcXmlRealVector m_IndependentVector;

   /// XML vector containing boundary search option
   EcXmlEnumU16 m_LowerBoundaryOption;

   /// XML vector containing boundary search option
   EcXmlEnumU16 m_UpperBoundaryOption;

   /// XML vector containing internal search option
   EcXmlEnumU16 m_SearchOption;

   /// independent variable object
   mutable EcVectorSearch<EcReal> m_Dimension;
};

#endif // ecTableFunctionVectorSearch_H_
