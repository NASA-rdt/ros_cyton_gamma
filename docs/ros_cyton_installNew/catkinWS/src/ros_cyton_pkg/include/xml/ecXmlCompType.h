#ifndef ecXmlCompType_H_
#define ecXmlCompType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlCompType.h
/// @class EcXmlCompoundType
/// @brief An XML object that holds a compound set of XML data.
/// @details EcXmlCompoundType holds a compound set of XML data. This class can
/// serve as a base class for user defined XML objects. It can have any number
/// of XML child components.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecXmlObject.h"

typedef std::map<EcToken, EcXmlObject*> EcXmlComponentMap;   ///< EcXmlComponentMap typedef of std::map
typedef std::map<EcToken, EcU32> EcXmlSpecialDescriptorMap;  ///< EcXmlSpecialDescriptorMap typedef of std::map

class EC_STABLE_XML_DECL EcXmlCompoundType : public EcXmlObject
{
public:
   /// #ECDECLARE_BIGFOUR(EcCls) Macro declares a constructor, destructor,
   /// copy constructor, equal operator, and equality operator
   ECDECLARE_BIGFOUR(EcXmlCompoundType);
   ECXMLOBJECT_ACCEPT(EcXmlCompoundType)

   /// special-descriptor codes
   enum
   {
      /// this tag signals a component that should be read but not written
      READONLYCOMPONENT = 0,

      /// this tag signals an attribute that should be read but not written
      READONLYATTRIBUTE
   };

   /// xmlInitialize
   virtual EcBoolean xmlInit
      (
      );

   /// read object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// read object attributes from an XML stream
   virtual EcBoolean readAttributes
      (
      EcXmlReader& stream
      );

   /// read object elements from an XML stream
   virtual EcBoolean readElements
      (
      EcXmlReader& stream
      );

   /// write object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// write object attributes to an XML stream
   virtual EcBoolean writeAttributes
      (
      EcXmlWriter& stream
      ) const;

   /// write object elements to an XML stream
   virtual EcBoolean writeElements
      (
      EcXmlWriter& stream
      ) const;

   /// write schema
   virtual EcBoolean writeSchema
      (
      EcXmlSchema& stream
      ) const;

   /// write schema attributes
   virtual EcBoolean writeSchemaAttributes
      (
      EcXmlSchema& stream
      ) const;

   /// write schema elements
   virtual EcBoolean writeSchemaElements
      (
      EcXmlSchema& stream
      ) const;

   /// register components
   /**
   This is a pure virtual function. The derived class should use this method register all its relevant components.
   */
   virtual void registerComponents
      (
      )=0;

   /// register a single component
   /**
   \brief Registers a child component into the component map using a token.
   \param[in] token The token used as the key for registering a component.
   \param[in] obj A component to be registered.
   */
   virtual void registerComponent
      (
      const EcToken& token,
      EcXmlObject* obj
      );

   /// register a single component as read-only
   /**
   \brief Registers a child component into the component map using a token.  Also
          registers it as read-only.
   \param[in] token The token used as the key for registering a component.
   \param[in] obj A component to be registered.
   */
   virtual void registerComponentReadOnly
      (
      const EcToken& token,
      EcXmlObject* obj
      );

   /// get a reference to the component map
   virtual const EcXmlComponentMap& componentMap
      (
      ) const;

   /// register a single attribute component
   /**
   \brief Registers an attribute component into the attribute component map using a token.
   \param[in] AttribToken The token used as the key for registering an attribute component.
   \param[in] Obj A attribute component to be registered.
   */
   virtual void registerAttributeComponent
      (
      const EcToken &AttribToken,
      EcXmlObject *Obj
      );

   /// register a single attribute component read-only
   /**
   \brief Registers an attribute component into the attribute component map using a token.
   \brief Restisters the component as a read-only member.
   \param[in] AttribToken The token used as the key for registering an attribute component.
   \param[in] Obj A attribute component to be registered.
   */
   virtual void registerAttributeComponentReadOnly
      (
      const EcToken &AttribToken,
      EcXmlObject *Obj
      );

   /// get a reference to the component attribute map
   virtual const EcXmlComponentMap& attributeComponentMap
      (
      );

   /// get a reference to the special-descriptor map
   virtual const EcXmlSpecialDescriptorMap& specialDescriptorMap
      (
      );

   /// return EcTrue if there are children components or EcFalse if an empty element.
   virtual EcBoolean hasChildren
      (
      ) const;

   /// return EcTrue if there are attributes in the element.
   virtual EcBoolean hasAttributes
      (
      ) const;

protected:

   /// read an XML object from a stream after reading the start tag
   /// return value signals success or failure
   virtual EcBoolean readValueFromToken
      (
      const EcToken& token,
      EcXmlReader& stream
      );

   /// read value from unregistered token
   virtual EcBoolean readValueFromSpecialToken
      (
      const EcToken& token,
      EcXmlReader& stream
      );

   /// read an XML attribute from a stream after reading the start tag
   /// return value signals success or failure
   virtual EcBoolean readAttributeFromToken
      (
      const EcToken& token,
      EcXmlReader& stream
      );

   /// allocate a new componentMap
   virtual EcXmlComponentMap* newComponentMap
      (
      ) const;

   /// allocate a new specialDescriptorsMap
   virtual EcXmlSpecialDescriptorMap* newSpecialDescriptorMap
      (
      );

   /// create component map
   virtual void createComponentMap
      (
      ) const;

   /// create attribute component map
   virtual void createAttributeComponentMap
      (
      );

   /// create special-descriptors map
   virtual void createSpecialDescriptorMap
      (
      );

   /// check to see if the token corresponds to a read-only component
   virtual EcBoolean isReadOnlyComponent
      (
      const EcToken token
      ) const;

   /// check to see if the token corresponds to a read-only attribute
   virtual EcBoolean isReadOnlyAttribute
      (
      const EcToken token
      ) const;

protected:
   /// A map holding the element relationship between string labels
   /// and subcomponents.
   mutable EcXmlComponentMap* m_pComponentMap;

   /// A map holding the attribute relationship between string labels
   /// and subcomponents.
   EcXmlComponentMap* m_pAttributeComponentMap;

   /// A string set holding special descriptors, such as read-only flags.
   /// Read-only members are read but not written.
   EcXmlSpecialDescriptorMap* m_pSpecialDescriptorMap;
};

#endif // ecXmlCompType_H_
