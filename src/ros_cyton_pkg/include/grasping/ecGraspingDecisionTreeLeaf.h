#ifndef ecGraspingDecisionTreeLeaf_H_
#define ecGraspingDecisionTreeLeaf_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspingDecisionTreeLeaf.h
/// @class EcGraspingDecisionTreeLeaf
/// @brief Leaf node in the grasping tree
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspingDecisionTreeElement.h"

class EcGraspingDecisionTreeContainer;

/// Leaf node in the grasping tree
class EC_ACTIN_GRASPING_DECL EcGraspingDecisionTreeLeaf : public EcGraspingDecisionTreeElement
{
public:
   /// default constructor
   EcGraspingDecisionTreeLeaf
      (
      );

   /// constructor with container pointer
   explicit EcGraspingDecisionTreeLeaf
      (
      const EcGraspingDecisionTreeContainer*  containerPointer
      );

   /// destructor
   virtual ~EcGraspingDecisionTreeLeaf
      (
      );

   /// copy constructor
   EcGraspingDecisionTreeLeaf
      (
      const EcGraspingDecisionTreeLeaf& orig
      );

   /// assignment operator
   EcGraspingDecisionTreeLeaf& operator=
      (
      const EcGraspingDecisionTreeLeaf& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspingDecisionTreeLeaf& orig
      ) const;

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

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// return a string token
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

   /// perform an search through decision tree
   /**
       Get grasping model from tree
       \param params grasp initialization parameters
       \param objectGraspingModule return module for grasping object
       \retval status of search
   */
   virtual EcBoolean search
      (
      const EcGraspInitParams& params,
      EcObjectGraspingModule& objectGraspingModule
      ) const;

   /// get a null object
   static EcGraspingDecisionTreeLeaf nullObject
      (
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );
};

#endif // ecGraspingDecisionTreeLeaf_H_
