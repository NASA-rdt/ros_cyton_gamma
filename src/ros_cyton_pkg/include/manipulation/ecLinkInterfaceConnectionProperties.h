#ifndef EcLinkInterfaceConnectionProperties_H_
#define EcLinkInterfaceConnectionProperties_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file EcLinkInterfaceConnectionProperties.h
/// @class EcLinkInterfaceConnectionProperties
/// @brief This represents the connection properties between two link interfaces derived from EcBaseLinkInterface
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecManipulationAction.h"
#include "ecManipulationSequence.h"

#include <foundCommon/ecFoundCommonTypes.h>
#include <foundCommon/ecCoordSysXForm.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>
#include <xml/ecXmlPairType.h>

/// The connection properties that define how to connect two compatible link interfaces.
class EC_ACTIN_MANIPULATION_DECL EcLinkInterfaceConnectionProperties : public EcXmlCompoundType
{
public:

   /// default constructor
   EcLinkInterfaceConnectionProperties
      (
      );

   /// destructor
   virtual ~EcLinkInterfaceConnectionProperties
      (
      );

   /// copy constructor
   EcLinkInterfaceConnectionProperties
      (
      const EcLinkInterfaceConnectionProperties& orig
      );

   /// assignment operator
   EcLinkInterfaceConnectionProperties& operator=
      (
      const EcLinkInterfaceConnectionProperties& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinkInterfaceConnectionProperties& orig
      ) const;

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

  
   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// get the class token
   virtual const EcToken& token
      (
      ) const;
   
   /// A static function to return the class token
   static const EcToken& classToken
      (
      );

   /// A static creator function.  This is registered using the class token.
   static EcXmlObject* creator
      (
      );

protected:
  
   // XML data
   EcXmlPairType<EcXmlString, EcXmlString>               m_InterfaceTypePair;     ///< The two interface type to which these poperties pertain
   EcManipulationSequence                                m_ConnectionSequence;    ///< The Action Sequence used to connect the two interfaces 
};

#endif // EcLinkInterfaceConnectionProperties_H_
