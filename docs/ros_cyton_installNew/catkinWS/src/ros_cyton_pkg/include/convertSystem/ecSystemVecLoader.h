#ifndef ecSystemVecLoader_H_
#define ecSystemVecLoader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemVecLoader.h
/// @class EcSystemVecLoader
/// @brief Holds a tool for loading system from .vec file types.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseSystemLoader.h"
#include "ecVecPhysicalExtentConverter.h"

/// Holds a tool for loading system from NASA .vec file types.
class EC_FOUNDATION_CONVERTSYSTEM_DECL EcSystemVecLoader : public EcBaseSystemLoader
{
public:
   /// default constructor
   EcSystemVecLoader
      (
      );

   /// destructor
   virtual ~EcSystemVecLoader
      (
      );

   /// copy constructor
   EcSystemVecLoader
      (
      const EcSystemVecLoader& orig
      );

   /// assignment operator
   EcSystemVecLoader& operator=
      (
      const EcSystemVecLoader& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemVecLoader& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;


   /// gets the vec physical extent converter
   virtual const EcVecPhysicalExtentConverter& vecPhysicalExtentConverter
      (
      ) const;

   /// sets the vec physical extent converter
   virtual void setVecPhysicalExtentConverter
      (
      const EcVecPhysicalExtentConverter& vecPhysicalExtentConverter
      );

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

   /// a token unique to this class
   static const EcToken& classToken
      (
      );

   /// get an empty object
   static EcSystemVecLoader nullObject
      (
      );

protected:
   EcVecPhysicalExtentConverter m_VecPhysicalExtentConverter;   ///< physical extent converter
};

#endif // ecSystemVecLoader_H_
