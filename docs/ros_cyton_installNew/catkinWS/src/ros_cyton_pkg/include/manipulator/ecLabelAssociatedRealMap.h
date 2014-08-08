#ifndef ecLabelAssociatedRealMap_H_
#define ecLabelAssociatedRealMap_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecLabelAssociatedRealMap.h
/// @class EcLabelAssociatedRealMap
/// @brief Holds a label associated real map.  This allows indexing
///        into a 2D array of Reals by string labels.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecGeneralMotion.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>
#include "ecLabelAssociatedMap.h"

///  frwd declarations
class EcIndividualManipulator;

/** Holds a label associated real map.  This allows indexing
 *  into a 2D array of Reals by string labels.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcLabelAssociatedRealMap : public EcLabelAssociatedMap<EcXmlReal>
{
public:
   /// default constructor
   EcLabelAssociatedRealMap
      (
      );

   /// destructor
   virtual ~EcLabelAssociatedRealMap
      (
      );

   /// copy constructor
   EcLabelAssociatedRealMap
      (
      const EcLabelAssociatedRealMap& orig
      );

   /// assignment operator
   EcLabelAssociatedRealMap& operator=
      (
      const EcLabelAssociatedRealMap& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLabelAssociatedRealMap& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

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

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   static EcLabelAssociatedRealMap nullObject
      (
      );
};

#endif // ecLabelAssociatedRealMap_H_
