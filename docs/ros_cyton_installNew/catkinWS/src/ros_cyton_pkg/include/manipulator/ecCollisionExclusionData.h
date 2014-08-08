#ifndef ecCollisionExclusionData_H_
#define ecCollisionExclusionData_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecCollisionExclusionData.h
/// @class EcCollisionExclusionData
/// @brief Holds description of collision exclusion data
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.

#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>
#include <xml/ecXmlSetType.h>

#include "ecSystemCollisionExclusionMap.h"
#include "ecManipSelfCollisionLinkMap.h"

// forward declarations
class EcManipulatorSelfCollisionLinkMap;
class EcSystemCollisionExclusionMap;


/// type definition of XML vector of EcManipulatorSelfCollisionLinkMap
typedef EcXmlVectorType<EcManipulatorSelfCollisionLinkMap > EcSelfCollisionVector;


/**
\class EcCollisionExclusionData
\brief Holds description of collision exclusion data
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcCollisionExclusionData : public EcXmlCompoundType
{
public:

   /// default constructor
   EcCollisionExclusionData
      (
      );

   /// destructor
   virtual ~EcCollisionExclusionData
      (
      );

   /// copy constructor
   EcCollisionExclusionData
      (
      const EcCollisionExclusionData& orig
      );

   /// assignment operator
   EcCollisionExclusionData& operator=
      (
      const EcCollisionExclusionData& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCollisionExclusionData& orig
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;


   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets the xml token used for writing out.
   const EcToken& token
      (
      ) const;

   /// set system collision exclusion map
   void setSystemCollisionExclusionMap
      (
      const EcSystemCollisionExclusionMap& systemCollision
      );

   /// returns system collision exclusion map
   const EcSystemCollisionExclusionMap& systemCollisionExclusionMap
      (
      );

   /// sets self collision data
   void setSelfCollision
      (
      const EcSelfCollisionVector& selfCollision
      );

   /// returns self collision data
   const EcSelfCollisionVector& selfCollision
      (
      );

protected:

protected:
   /// map for excluding collision between all links of manipulators
   EcSystemCollisionExclusionMap     m_SystemCollisionExclusionMap;

   /// vector of  collision data within the links of a manipulator
   EcSelfCollisionVector             m_SelfCollisionVector;


};

#endif // ecSystemCollisionExclusionMap_H_
