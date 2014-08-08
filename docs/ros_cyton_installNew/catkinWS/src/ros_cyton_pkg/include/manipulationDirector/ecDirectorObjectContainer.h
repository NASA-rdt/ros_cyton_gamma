#ifndef ecDirectorObjectContainer_H_
#define ecDirectorObjectContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecDirectorObjectContainer.h
/// @class EcDirectorObjectContainer
/// @brief Container for manipulation director objects
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>

class EcDirectorObject;

/// Container for manipulation director objects
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcDirectorObjectContainer :
   public EcXmlVariableElementType<EcDirectorObject>
{
public:
   /// default constructor
   EcDirectorObjectContainer
      (
      );

   /// destructor
   virtual ~EcDirectorObjectContainer
      (
      );

   /// copy constructor
   EcDirectorObjectContainer
      (
      const EcDirectorObjectContainer& orig
      );

   /// assignment operator
   EcDirectorObjectContainer& operator=
      (
      const EcDirectorObjectContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDirectorObjectContainer& orig
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

   /// null object
   static EcDirectorObjectContainer nullObject
      (
      );
};

#endif // ecDirectorObjectContainer_H_
