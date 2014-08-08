#ifndef ecUnitaryMapContainer_H_
#define ecUnitaryMapContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecUnitaryMapContainer.h
/// @class EcUnitaryMapContainer
/// @brief A container for a unitary map (a scalar function
///        mapping 0-1 to 0-1).
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecBaseExpTreeContainer.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EcBaseUnitaryMap;

/** A container for a unitary map (a scalar function mapping 0-1 to 0-1).
*/
class EC_FOUNDATION_FUNCTION_DECL EcUnitaryMapContainer : public EcBaseExpressionTreeContainer<EcBaseUnitaryMap>
{
public:
   /// default constructor
   EcUnitaryMapContainer
      (
      );

   /// destructor
   virtual ~EcUnitaryMapContainer
      (
      );

   /// copy constructor
   EcUnitaryMapContainer
      (
      const EcUnitaryMapContainer& orig
      );

   /// assignment operator
   EcUnitaryMapContainer& operator=
      (
      const EcUnitaryMapContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcUnitaryMapContainer& orig
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

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// evaluate the function
   virtual EcReal evaluate
      (
      const EcReal& domainValue
      )const;

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
   static EcUnitaryMapContainer nullObject
      (
      );
};

#endif // ecUnitaryMapContainer_H_
