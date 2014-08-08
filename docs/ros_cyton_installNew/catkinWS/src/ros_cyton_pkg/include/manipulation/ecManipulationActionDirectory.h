#ifndef ecManipulationActionDirectory_H_
#define ecManipulationActionDirectory_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationActionDirectory.h
/// @class EcManipulationActionDirectory
/// @brief Organizes multiple manipulation actions into a directory hierarchy
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationActionContainer.h"

#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// Organizes multiple manipulation actions into a directory hierarchy
class EC_ACTIN_MANIPULATION_DECL EcManipulationActionDirectory : public EcXmlCompoundType
{
public:
   /// type definition of StringDirectoryMap
   typedef EcXmlMapType<EcXmlString, EcManipulationActionDirectory> StringDirectoryMap;
   /// type definition of StringActionMap
   typedef EcXmlMapType<EcXmlString, EcManipulationActionContainer> StringActionMap;

   /// default constructor
   EcManipulationActionDirectory
      (
      );

   /// destructor
   virtual ~EcManipulationActionDirectory
      (
      );

   /// copy constructor
   EcManipulationActionDirectory
      (
      const EcManipulationActionDirectory& orig
      );

   /// assignment operator
   EcManipulationActionDirectory& operator=
      (
      const EcManipulationActionDirectory& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationActionDirectory& orig
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

   /// return true if there there are no subdirectories or actions in this directory
   virtual EcBoolean empty
      (
      ) const;

   /// clear this directory of all subdirectories and actions
   virtual void clear
      (
      );

   /// add a action
   virtual EcBoolean add
      (
      const EcString&             aname,
      const EcManipulationAction& action
      );

   /// add a subdirectory
   virtual EcBoolean add
      (
      const EcString&                      dname,
      const EcManipulationActionDirectory& directory
      );

   /// remove a action or subdirectory
   virtual EcBoolean remove
      (
      const EcString& name
      );

   /// return true if this directory has actions
   EcBoolean hasActions
      (
      ) const;

   /// get an action from this directory
   virtual const EcManipulationAction* action
      (
      const EcString& aname
      ) const;

   /// return true if this directory has subdirectories
   EcBoolean hasSubdirectories
      (
      ) const;

   /// get a subdirectory from this directory
   virtual const EcManipulationActionDirectory* subdirectory
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

   /// get a full listing of all actions included in this directory
   EcStringVector actionListing
      (
      ) const;

   /// get a listing of the subactions included in this directory
   EcStringVector subactionListing
      (
      ) const;

   /// get the token
   virtual const EcToken& token
      (
      ) const;

   /// split action name
   static EcBoolean splitActionName
      (
      const EcString& aname,
      EcString& subdirectoryName,
      EcString& actionName
      );

   /// split directory name
   static EcBoolean splitDirectoryName
      (
      const EcString& dname,
      EcString& subdirectoryName,
      EcString& directoryName
      );

   /// load from file system
   static void loadFromFilesystem
      (
      EcManipulationActionDirectory& mad,
      const EcString&                directory
      );

   /// load from file system
   static EcBoolean loadFromFilesystem
      (
      EcManipulationActionDirectory& mad,
      const EcString&                aname,
      const EcString&                fileName
      );

   /// save to file system
   static EcBoolean saveToFilesystem
      (
      const EcManipulationActionDirectory& mad,
      const EcString&                      directory
      );

protected:
   /// create sub-directory
   EcManipulationActionDirectory* createSubdirectory
      (
      const EcString& dname
      );

   /// get a full listing of all directories included in this directory
   void directoryListing
      (
      EcStringVector& listing,
      const EcString& prefix = ""
      ) const;

   /// get a full listing of all actions included in this directory
   void actionListing
      (
      EcStringVector& listing,
      const EcString& prefix = ""
      ) const;

   /// subdirectories of this directory
   StringDirectoryMap m_SubdirectoryMap;

   /// actions located in this directory
   StringActionMap m_ActionMap;
};

#endif // ecManipulationActionDirectory_H_
