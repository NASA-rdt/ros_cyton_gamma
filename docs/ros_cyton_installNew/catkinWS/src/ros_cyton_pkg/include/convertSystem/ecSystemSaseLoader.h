#ifndef ecSystemSaseLoader_H_
#define ecSystemSaseLoader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemSaseLoader.h
/// @class EcSystemSaseLoader
/// @brief Holds a tool for loading system from sase files,
///        which define the .pase,.sys, .state, and .txtr files.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseSystemLoader.h"

/// Holds a tool for loading system from sase files, which define
/// the .pase,.sys, .state, and .txtr files.
class EC_FOUNDATION_CONVERTSYSTEM_DECL EcSystemSaseLoader : public EcBaseSystemLoader
{
public:
   /// default constructor
   EcSystemSaseLoader
      (
      );

   /// destructor
   virtual ~EcSystemSaseLoader
      (
      );

   /// copy constructor
   EcSystemSaseLoader
      (
      const EcSystemSaseLoader& orig
      );

   /// assignment operator
   EcSystemSaseLoader& operator=
      (
      const EcSystemSaseLoader& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemSaseLoader& orig
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
   static EcSystemSaseLoader nullObject
      (
      );
};

#endif // ecSystemSaseLoader_H_
