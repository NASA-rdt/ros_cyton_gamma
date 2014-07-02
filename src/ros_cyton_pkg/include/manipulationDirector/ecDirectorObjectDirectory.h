#ifndef ecDirectorObjectDirectory_H_
#define ecDirectorObjectDirectory_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecDirectorObjectDirectory.h
/// @class EcDirectorObjectDirectory
/// @brief Organizes multiple manipulation director objects into a directory hierarchy
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecDirectorObjectContainer.h"

#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>

// Forward declarations
class EcManipulationAction;

/// Organizes multiple manipulation director objects into a directory hierarchy
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcDirectorObjectDirectory : public EcXmlCompoundType
{
public:
   typedef EcXmlMapType<EcXmlString, EcDirectorObjectDirectory> StringDirectoryMap;
   typedef EcXmlMapType<EcXmlString, EcDirectorObjectContainer> StringObjectMap;

   /// default constructor
   EcDirectorObjectDirectory
      (
      );

   /// destructor
   virtual ~EcDirectorObjectDirectory
      (
      );

   /// copy constructor
   EcDirectorObjectDirectory
      (
      const EcDirectorObjectDirectory& orig
      );

   /// assignment operator
   EcDirectorObjectDirectory& operator=
      (
      const EcDirectorObjectDirectory& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDirectorObjectDirectory& orig
      ) const;

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

   /// return true if there there are no subdirectories or objects in this directory
   virtual EcBoolean empty
      (
      ) const;

   /// clear this directory of all subdirectories and objects
   virtual void clear
      (
      );

   /// add an action
   virtual EcBoolean add
      (
      const EcString&             aname,
      const EcManipulationAction& action
      );

   /// add a object
   virtual EcBoolean add
      (
      const EcString&         oname,
      const EcDirectorObject& object
      );

   virtual EcBoolean updateAction
      (
      const EcString&             aname,
      const EcManipulationAction& action
      );

   /// add a subdirectory
   virtual EcBoolean add
      (
      const EcString&                  dname,
      const EcDirectorObjectDirectory& directory
      );

   /// remove a object or subdirectory
   virtual EcBoolean remove
      (
      const EcString& name
      );

   /// return true if this directory has objects
   EcBoolean hasObjects
      (
      ) const;

   /// get an action from this directory
   virtual const EcManipulationAction* action
      (
      const EcString& aname
      ) const;

   /// get an object from this directory
   virtual const EcDirectorObject* object
      (
      const EcString& oname
      ) const;

   /// return true if this directory has subdirectories
   EcBoolean hasSubdirectories
      (
      ) const;

   /// get a subdirectory from this directory
   virtual const EcDirectorObjectDirectory* subdirectory
      (
      const EcString& dname
      ) const;

   /// get a full listing of all directories included in this directory
   EcStringVector directoryListing
      (
      ) const;

   /// get a listing of the subdirectories included in this directory
   EcStringVector subdirectoryListing
      (
      ) const;

   /// get a full listing of all objects included in this directory
   EcStringVector objectListing
      (
      ) const;

   /// get a listing of the subobjects included in this directory
   EcStringVector subobjectListing
      (
      ) const;

   /// get the token
   virtual const EcToken& token
      (
      ) const;

   static EcBoolean splitObjectName
      (
      const EcString& oname,
      EcString& subdirectoryName,
      EcString& objectName
      );

   static EcBoolean splitDirectoryName
      (
      const EcString& dname,
      EcString& subdirectoryName,
      EcString& directoryName
      );

   static void loadFromFilesystem
      (
      EcDirectorObjectDirectory& dod,
      const EcString&            directory
      );

   static EcBoolean loadFromFilesystem
      (
      EcDirectorObjectDirectory& dod,
      const EcString&            oname,
      const EcString&            fileName
      );

   static EcBoolean saveToFilesystem
      (
      const EcDirectorObjectDirectory& dod,
      const EcString&                  directory
      );

protected:
   EcDirectorObjectDirectory* createSubdirectory
      (
      const EcString& dname
      );

   void directoryListing
      (
      EcStringVector& listing,
      const EcString& prefix = ""
      ) const;

   void objectListing
      (
      EcStringVector& listing,
      const EcString& prefix = ""
      ) const;

   /// subdirectories of this directory
   StringDirectoryMap m_SubdirectoryMap;

   /// objects located in this directory
   StringObjectMap m_ObjectMap;
};

#endif // ecDirectorObjectDirectory_H_
