#ifndef ecManipulationActionManager_H_
#define ecManipulationActionManager_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationActionManager.h
/// @class EcManipulationActionManager
/// @brief Manages multiple manipulation actions.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationActionContainer.h"

#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>

// Forward declarations

class EC_ACTIN_MANIPULATION_DECL EcManipulationActionManager : public EcXmlCompoundType
{
public:
   /// type definition of StringActionMap
   typedef EcXmlMapType<EcXmlString, EcManipulationActionContainer> StringActionMap;

   /// default constructor
   EcManipulationActionManager
      (
      );

   /// destructor
   virtual ~EcManipulationActionManager
      (
      );

   /// copy constructor
   EcManipulationActionManager
      (
      const EcManipulationActionManager& orig
      );

   /// assignment operator
   EcManipulationActionManager& operator=
      (
      const EcManipulationActionManager& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationActionManager& orig
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

   /// return a true if there there are no actions to manage
   EcBoolean empty
      (
      ) const;

   /// get the action map
   const StringActionMap& actionMap
      (
      ) const;

   /// set the action map
   void setActionMap
      (
      const StringActionMap& map
      );

   /// get the action order
   const EcXmlStringVector& actionOrder
      (
      ) const;

   /// set the action order
   void setActionOrder
      (
      const EcXmlStringVector& order
      );

   /// add a action to the map of managed actions
   virtual EcBoolean addAction
      (
      const EcString&        key,
      const EcManipulationAction& action
      );

   /// add a action to the map of managed actions
   virtual EcBoolean addAction
      (
      const EcString&                      key,
      const EcManipulationActionContainer& action
      );

   /// delete a action from the map of managed actions
   virtual EcBoolean deleteAction
      (
      const EcString& key
      );

   /// update an existing named action
   virtual EcBoolean updateAction
      (
      const EcString& key,
      const EcManipulationAction& action
      );

   /// rename an existing named action
   virtual EcBoolean renameAction
      (
      const EcString& currentName,
      const EcString& newName
      );

   /// get the pointer to manipulation action at a given order index
   const EcManipulationAction* manipulationAction
      (
      EcU32 orderIndex
      ) const;

   /// get the token
   virtual const EcToken& token
      (
      ) const;

   /// returns the number of actions
   EcU32 size
      (
      );

   /// returns the manipulation action container for the given name
   const EcManipulationActionContainer& action
      (
      const EcString& itemName
      )const;

   /// append order
   void appendOrder
      (
      const EcString& itemName
      );

protected:
   /// the order of action execution
   EcXmlStringVector    m_ActionOrder;

   /// the actions being managed
   StringActionMap      m_ActionMap;
};

#endif // ecManipulationActionManager_H_
