#ifndef ecSystemS3dsLoader_H_
#define ecSystemS3dsLoader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemS3dsLoader.h
/// @class EcSystemS3dsLoader
/// @brief Holds a tool for loading system from s3ds files,
///        which define the .p3ds,.sys, .state, and .txtr files.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseSystemLoader.h"

/// Holds a tool for loading system from s3ds files, which define
/// the .p3ds,.sys, .state, and .txtr files.
class EC_FOUNDATION_CONVERTSYSTEM_DECL EcSystemS3dsLoader : public EcBaseSystemLoader
{
public:
   /// default constructor
   EcSystemS3dsLoader
      (
      );

   /// destructor
   virtual ~EcSystemS3dsLoader
      (
      );

   /// copy constructor
   EcSystemS3dsLoader
      (
      const EcSystemS3dsLoader& orig
      );

   /// assignment operator
   EcSystemS3dsLoader& operator=
      (
      const EcSystemS3dsLoader& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemS3dsLoader& orig
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

   // load a vis system from a pntp stream
   /**
       \param[out] visSystem visualizable stated system
       \param[in] path path to files
       \param[in] stream file stream
       \retval error status
   */
   virtual EcBoolean loadVisualizableStatedSystemFromStream
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
   static EcSystemS3dsLoader nullObject
      (
      );
};

#endif // ecSystemS3dsLoader_H_
