#ifndef ecWaypointSequenceDatabase_H_
#define ecWaypointSequenceDatabase_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecWaypointSequenceDatabase.h
/// @class EcWaypointSequenceDatabase
/// @brief This class is a collection of waypoint sequences
//
//------------------------------------------------------------------------------


#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>
#include <xml/ecXmlVectorType.h>
#include "ecWaypointSequence.h"

class EC_ACTIN_MANIPULATION_DECL EcWaypointSequenceDatabase : public EcXmlCompoundType
{
public:
   /// type definition of StringWaypointSequenceMap
   typedef EcXmlMapType< EcXmlString, EcWaypointSequence> StringWaypointSequenceMap;

   /// default constructor
   EcWaypointSequenceDatabase
      (
      );

   /// destructor
   virtual ~EcWaypointSequenceDatabase
      (
      );

   /// copy constructor
   EcWaypointSequenceDatabase
      (
      const EcWaypointSequenceDatabase& orig
      );

   /// assignment operator
   EcWaypointSequenceDatabase& operator=
      (
      const EcWaypointSequenceDatabase& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcWaypointSequenceDatabase& orig
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

   /// the token
   virtual const EcToken& token
      (
      ) const;

   /// get the name
   virtual const EcString& name
      (
      ) const;

   /// set the name
   virtual void setName
      (
      const EcString& value
      );

   /// get the WaypointSequence map
   virtual const StringWaypointSequenceMap& waypointSequenceMap
      (
      ) const;

   /// set the WaypointSequence map
   virtual void setWaypointSequenceMap
      (
      const StringWaypointSequenceMap& value
      );

   /// add a WaypointSequence with name
   virtual EcBoolean addWaypointSequence
      (
      const EcXmlString& name,
      const EcWaypointSequence& waypointSequence
      );

   /// update an existing named WaypointSequence
   virtual EcBoolean updateWaypointSequence
      (
      const EcXmlString& name,
      const EcWaypointSequence& waypointSequence
      );

   /// delete the WaypointSequence associated with the name
   virtual EcBoolean deleteWaypointSequence
      (
      const EcXmlString& name
      );

   /// get the waypoint sequence given sequence name
   EcWaypointSequence waypointSequence
      (
      const EcString& itemName
      );

   /// get the size of the waypoint map
   EcU32 size
      (
      );

   /// rename waypoint sequence
   virtual EcBoolean renameWayPointSequence
      (
      const EcString& curName,
      const EcString& newName
      );

protected:
   EcXmlString                   m_Name;     ///< name of the set
   StringWaypointSequenceMap     m_WaypointSequenceMap;  ///< map containing WaypointSequences with name of each WaypointSequence as the key
};

/// type definition of EcWaypointSequenceDatabaseVector
typedef EcXmlVectorType< EcWaypointSequenceDatabase >   EcWaypointSequenceDatabaseVector;

#endif // ecWaypointSequenceDatabase_H_
