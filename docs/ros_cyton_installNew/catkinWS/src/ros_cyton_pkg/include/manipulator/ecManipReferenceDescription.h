#ifndef ecManipReferenceDescription_H_
#define ecManipReferenceDescription_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipReferenceDescription.h
/// @class EcManipulatorReferenceDescription
/// @brief Holds a description of references made by this manipulator.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlEnumType.h>

/// Holds a description of references made by this manipulator.
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorReferenceDescription : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorReferenceDescription
      (
      );

   /// destructor
   virtual ~EcManipulatorReferenceDescription
      (
      );

   /// copy constructor
   EcManipulatorReferenceDescription
      (
      const EcManipulatorReferenceDescription& orig
      );

   /// assignment operator
   EcManipulatorReferenceDescription& operator=
      (
      const EcManipulatorReferenceDescription& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorReferenceDescription& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

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

   /// gets the reference flag
   virtual EcBoolean isManipulatorReferenced
      (
      ) const;

   /// sets the reference flag
   virtual void setIsManipulatorReferenced
      (
      EcBoolean isManipulatorReferenced
      );

   /// gets the label for the referenced manipulator
   virtual const EcString& referencedManipulatorLabel
      (
      ) const;

   /// sets the label for the referenced manipulator
   virtual void setReferencedManipulatorLabel
      (
      const EcString& referencedManipulatorLabel
      );

   /// @copydoc EcXmlObject::token()
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

   /// get a null object
   static EcManipulatorReferenceDescription nullObject
      (
      );

protected:
   /// a flag indicating whether or not the shape is referenced
   EcXmlBoolean         m_IsManipulatorReferenced;

   /// the label for the referenced link
   EcXmlString          m_ReferencedManipulatorLabel;
};

#endif // ecManipReferenceDescription_H_
