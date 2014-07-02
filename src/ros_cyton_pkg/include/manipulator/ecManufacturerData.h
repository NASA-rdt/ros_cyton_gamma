#ifndef ecManufacturerData_H_
#define ecManufacturerData_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecManufacturerData.h
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

/// The class defining manufacturer data
class EC_FOUNDATION_MANIPULATOR_DECL EcManufacturerData : public EcXmlCompoundType
{
public:
   /// Macro declares a constructor, destructor,
   /// copy constructor, equal operator, and equality operator
   ECDECLARE_BIGFOUR(EcManufacturerData);

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

   /// gets the manufacturer name
   virtual const EcString& manufacturer
      (
      ) const;

   /// sets the manufacturer name
   virtual void setManufacturer
      (
      const EcString& value
      );

   /// gets the part number which is unique for each manufacturer
   virtual const EcString& partNumber
      (
      ) const;

   /// sets the part number
   virtual void setPartNumber
      (
      const EcString& value
      );

   /// return if this manufacturer data is valid. True only if both manufacturer and partNumber are not empty
   virtual EcBoolean isValid
      (
      ) const;

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;
protected:
   EcXmlString    m_Manufacturer;   ///< the manufacturer name or brand
   EcXmlString    m_PartNumber;     ///< the part number which is unique for each manufacturer
};

/// an XML vector of manufacturer data
typedef EcXmlVectorType<EcManufacturerData>  EcManufacturerDataVector;

#endif // ecManufacturerData_H_
