#ifndef ecPowerUnitaryMap_H_
#define ecPowerUnitaryMap_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecPowerUnitaryMap.h
/// @class EcPowerUnitaryMap
/// @brief Holds a description of a unitary map that is defined
///        by a power function.  I.e., f= pow(x,e).
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlBasicType.h>
#include "ecBaseUnitaryMap.h"

/** Holds a description of a unitary map that is defined
    by a power function.  I.e., f= pow(x,e).
*/
class EC_FOUNDATION_FUNCTION_DECL EcPowerUnitaryMap : public EcBaseUnitaryMap
{
public:
   /// default constructor
   EcPowerUnitaryMap
      (
      );

   /// destructor
   virtual ~EcPowerUnitaryMap
      (
      );

   /// copy constructor
   EcPowerUnitaryMap
      (
      const EcPowerUnitaryMap& orig
      );

   /// assignment operator
   EcPowerUnitaryMap& operator=
      (
      const EcPowerUnitaryMap& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPowerUnitaryMap& orig
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

   /// get exponent
   virtual EcReal exponent
      (
      ) const;

   /// set exponent
   virtual void setExponent
      (
      EcReal exponent
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
   static EcPowerUnitaryMap nullObject
      (
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcBaseUnitaryMap* creator
      (
      );

   /// static creator function to an xml object pointer
   static EcXmlObject* xmlObjectCreator
      (
      );

protected:
   /// the exponent
   EcXmlReal                      m_Exponent;
};

#endif // ecPowerUnitaryMap_H_
