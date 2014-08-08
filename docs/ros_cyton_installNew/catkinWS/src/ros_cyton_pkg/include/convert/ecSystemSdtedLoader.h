#ifndef ecSystemSdtedLoader_H_
#define ecSystemSdtedLoader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemSdtedLoader.h
/// @class EcSystemSdtedLoader
/// @brief Loader for multiple DTED files
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include "ecSystemDtedLoader.h"
#include <convertSystem/ecVisualizableStatedSystem.h>

/// Loader for multiple DTED files
class EC_RENDER_CONVERT_DECL EcSystemSdtedLoader : public EcSystemDtedLoader
{
public:
   /// constructor
	EcSystemSdtedLoader
      (
      );

   /// destructor
	virtual ~EcSystemSdtedLoader
      (
      );

   /// copy constructor
   EcSystemSdtedLoader
      (
      const EcSystemSdtedLoader& orig
      );

   /// assignment operator
   EcSystemSdtedLoader& operator=
      (
      const EcSystemSdtedLoader& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemSdtedLoader& orig
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
   static EcSystemSdtedLoader nullObject
      (
      );

protected:
   /// load from file
   /**
       \param filename dted filename
       \retval error status
   */
	virtual EcBoolean loadFromFile
      (
      const char *filename
      ) const;
};

#endif // ecSystemSdtedLoader_H_
