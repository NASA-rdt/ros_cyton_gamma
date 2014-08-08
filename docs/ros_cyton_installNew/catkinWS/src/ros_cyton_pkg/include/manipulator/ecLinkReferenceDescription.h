#ifndef ecLinkReferenceDescription_H_
#define ecLinkReferenceDescription_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkReferenceDescription.h
/// @class EcLinkReferenceDescription
/// @brief Holds a description of references made by this link.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlEnumType.h>

/** Holds a description of references made by this link.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcLinkReferenceDescription : public EcXmlCompoundType
{
public:
   /// default constructor
   EcLinkReferenceDescription
      (
      );

   /// destructor
   virtual ~EcLinkReferenceDescription
      (
      );

   /// copy constructor
   EcLinkReferenceDescription
      (
      const EcLinkReferenceDescription& orig
      );

   /// assignment operator
   EcLinkReferenceDescription& operator=
      (
      const EcLinkReferenceDescription& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinkReferenceDescription& orig
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

   /// gets the shape-reference flag
   virtual EcBoolean isShapeReferenced
      (
      ) const;

   /// sets the shape-reference flag
   virtual void setIsShapeReferenced
      (
      EcBoolean isShapeReferenced
      );

   /// gets the label for the referenced link
   virtual const EcString& referencedLinkLabel
      (
      ) const;

   /// sets the label for the referenced link
   virtual void setReferencedLinkLabel
      (
      const EcString& referencedLinkLabel
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
   static EcLinkReferenceDescription nullObject
      (
      );

protected:
   /// a flag indicating whether or not the shape is referenced
   EcXmlBoolean         m_IsShapeReferenced;

   /// the label for the referenced link
   EcXmlString          m_ReferencedLinkLabel;
};

#endif // ecLinkReferenceDescription_H_
