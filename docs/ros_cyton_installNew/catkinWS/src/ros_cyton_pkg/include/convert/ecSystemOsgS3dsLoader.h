#ifndef ecSystemOsgS3dsLoader_H_
#define ecSystemOsgS3dsLoader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemOsgS3dsLoader.h
/// @class EcSystemOsgS3dsLoader
/// @brief Holds a tool for loading system from s3ds files,
///        which define the .p3ds,.sys, .state, and .txtr files.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <convertSystem/ecSystemS3dsLoader.h>

/** Holds a tool for loading system from s3ds files, which define
    the .p3ds,.sys, .state, and .txtr files.
*/
class EC_RENDER_CONVERT_DECL EcSystemOsgS3dsLoader : public EcSystemS3dsLoader
{
public:
   /// default constructor
   EcSystemOsgS3dsLoader
      (
      );

   /// destructor
   virtual ~EcSystemOsgS3dsLoader
      (
      );

   /// copy constructor
   EcSystemOsgS3dsLoader
      (
      const EcSystemOsgS3dsLoader& orig
      );

   /// assignment operator
   EcSystemOsgS3dsLoader& operator=
      (
      const EcSystemOsgS3dsLoader& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemOsgS3dsLoader& orig
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

   // load a vis system from a pntp stream
   // Input vis system reference, path, and stream, Output status
   virtual EcBoolean loadVisualizableStatedSystemFromStream
      (
      EcVisualizableStatedSystem&  visSys,
      const EcString& path,
      std::ifstream&  stream
      ) const;

   /// a token unique to this class
   static const EcToken& classToken
      (
      );

   /// get an empty object
   static EcSystemOsgS3dsLoader nullObject
      (
      );
};

#endif // ecSystemOsgS3dsLoader_H_
