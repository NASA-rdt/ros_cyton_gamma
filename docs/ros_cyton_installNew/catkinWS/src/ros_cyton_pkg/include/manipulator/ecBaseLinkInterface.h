#ifndef EcBaseLinkInterface_H_
#define EcBaseLinkInterface_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseLinkInterface.h
/// @class EcBaseLinkInterface
/// @brief A base class describing a link interface used to attach objects to links
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.

#include <foundCommon/ecFoundCommonTypes.h>
#include <foundCommon/ecCoordSysXForm.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>
#include <xml/ecXmlBasicType.h>

/** Holds a description of a base link interface.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcBaseLinkInterface : public EcXmlCompoundType
{
public:
   /// default constructor
   EcBaseLinkInterface
      (
      );

   /// destructor
   virtual ~EcBaseLinkInterface
      (
      );

   /// copy constructor
   EcBaseLinkInterface
      (
      const EcBaseLinkInterface& orig
      );

   /// assignment operator
   EcBaseLinkInterface& operator=
      (
      const EcBaseLinkInterface& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseLinkInterface& orig
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
   
   /// returns the class token
   virtual const EcToken& token
      (
      ) const;

protected:
   EcXmlString                       m_InterfaceType;   ///< Designates the type of the interface, this is used to determine compatibility
   EcXmlString                       m_Identifier;      ///< The identifier of the interface, this is unique among interfaces on a link
   EcCoordinateSystemTransformation  m_InterfaceFrame;  ///< Frame of the interface relative to the link's primary frame
   EcXmlBoolean                      m_InUse;           ///< Flag showing if the interface is in use
};

/// type definition of XML vector of pointers to EcBaseLinkInterface
typedef std::vector<EcBaseLinkInterface*> EcLinkInterfacePtrVector;

#endif // EcBaseLinkInterface_H_
