#ifndef ecDecisionTreeCapsuleBranch_H_
#define ecDecisionTreeCapsuleBranch_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecDecisionTreeCapsuleBranch.h
/// @class EcDecisionTreeCapsuleBranch
/// @brief This class tests an object for a capsule
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspingDecisionTreeBranch.h"

class EcStatedSystem;

/** This class tests an object for a capsule
*/
class EC_ACTIN_GRASPING_DECL EcDecisionTreeCapsuleBranch : public EcGraspingDecisionTreeBranch
{
public:
   /// default constructor
   EcDecisionTreeCapsuleBranch
      (
      );

   /// destructor
   virtual ~EcDecisionTreeCapsuleBranch
      (
      );

   /// copy constructor
   EcDecisionTreeCapsuleBranch
      (
      const EcDecisionTreeCapsuleBranch& orig
      );

   /// assignment operator
   EcDecisionTreeCapsuleBranch& operator=
      (
      const EcDecisionTreeCapsuleBranch& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDecisionTreeCapsuleBranch& orig
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

   /// register XML member variables
   void registerComponents
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

   /// get a null object
   static EcDecisionTreeCapsuleBranch nullObject
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

   /// test the object for traversing the decision tree
   virtual EcReal test
      (
      const EcGraspInitParams& params
      ) const;
};

#endif // ecDecisionTreeCapsuleBranch_H_
