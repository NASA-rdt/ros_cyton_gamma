#ifndef ecSystemVrml97Loader_H_
#define ecSystemVrml97Loader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemVrml97Loader.h
/// @class EcSystemVrml97Loader
/// @brief VRML97 file loader
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseSystemLoader.h"
#include "ecVisualizableStatedSystem.h"

/// VRML97 file loader
class EC_FOUNDATION_CONVERTSYSTEM_DECL EcSystemVrml97Loader : public EcBaseSystemLoader
{
public:
   /// constructor
   EcSystemVrml97Loader
      (
      );

   /// destructor
   virtual ~EcSystemVrml97Loader
      (
      );

   /// copy constructor
   EcSystemVrml97Loader
      (
      const EcSystemVrml97Loader& orig
      );

   /// assignment operator
   EcSystemVrml97Loader& operator=
      (
      const EcSystemVrml97Loader& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemVrml97Loader& orig
      ) const;

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

   /// load a file and build a visualizable stated system
   /**
       \param visStatedSystem stated system
       \param filename filename for building stated system
       \retval error status
   */
   virtual EcBoolean loadVisualizableStatedSystemFromFile
      (
      EcVisualizableStatedSystem&  visStatedSystem,
      const EcString& filename
      ) const;

   /// a token unique to this class
   static const EcToken& classToken
      (
      );

   /// get an empty object
   static EcSystemVrml97Loader nullObject
      (
      );
};

#endif // ecSystemVrml97Loader_H_
