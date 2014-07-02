#ifndef ecSystemOsgLoader_H_
#define ecSystemOsgLoader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemOsgLoader.h
/// @class EcSystemOsgLoader
/// @brief OSG file loader
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <convertSystem/ecBaseSystemLoader.h>

class EcVisualizableStatedSystem;

/// OSG file loader
class EC_RENDER_CONVERT_DECL EcSystemOsgLoader : public EcBaseSystemLoader
{
public:
   /// constructor
   EcSystemOsgLoader
      (
      );

   /// destructor
   virtual ~EcSystemOsgLoader
      (
      );

   /// copy constructor
   EcSystemOsgLoader
      (
      const EcSystemOsgLoader& orig
      );

   /// assignment operator
   EcSystemOsgLoader& operator=
      (
      const EcSystemOsgLoader& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemOsgLoader& orig
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
   static EcSystemOsgLoader nullObject
      (
      );

   /// get scale factor
   virtual EcReal scaleFactor
      (
      ) const;

   /// set scale factor
   virtual void setScaleFactor
      (
      EcReal scaleFactor
      );

protected:
   EcReal              m_ScaleFactor;     /// scale factor for model size
};

#endif // ecSystemOsgLoader_H_
