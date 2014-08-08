#ifndef ecSystemPntpLoader_H_
#define ecSystemPntpLoader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemPntpLoader.h
/// @class EcSystemPntpLoader
/// @brief Holds a tool for loading system from pntp files,
///        which define the .pp,.sys, and .state files for the manipulator.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseSystemLoader.h"

/// Holds a tool for loading system from pntp files, which define
/// the .pp,.sys, and .state files for the manipulator.
class EC_FOUNDATION_CONVERTSYSTEM_DECL EcSystemPntpLoader : public EcBaseSystemLoader
{
public:
   /// default constructor
   EcSystemPntpLoader
      (
      );

   /// destructor
   virtual ~EcSystemPntpLoader
      (
      );

   /// copy constructor
   EcSystemPntpLoader
      (
      const EcSystemPntpLoader& orig
      );

   /// assignment operator
   EcSystemPntpLoader& operator=
      (
      const EcSystemPntpLoader& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemPntpLoader& orig
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
       \param[out] visStatedSystem stated system
       \param[in] filename filename for building stated system
       \retval error status
   */
   virtual EcBoolean loadVisualizableStatedSystemFromFile
      (
      EcVisualizableStatedSystem&  visStatedSystem,
      const EcString& filename
      ) const;

   /// load a vis stated system from a pntp stream
   /**
       \param[out] visSystem visualizable stated system
       \param[in] path path to files
       \param[in] stream file stream
       \retval error status
   */
   EcBoolean loadVisualizableStatedSystemFromStream
      (
      EcVisualizableStatedSystem&  visSystem,
      const EcString& path,
      std::ifstream&  stream
      ) const;

   /// a token unique to this class
   static const EcToken& classToken
      (
      );

   /// get an empty object
   static EcSystemPntpLoader nullObject
      (
      );
};

#endif // ecSystemPntpLoader_H_
