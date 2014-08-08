#ifndef ecDecisionTreePassThroughBranch_H_
#define ecDecisionTreePassThroughBranch_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecDecisionTreePassThroughBranch.h
/// @class EcDecisionTreePassThroughBranch
/// @brief This class tests an object for edges
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspingDecisionTreeBranch.h"

class EcStatedSystem;

/** This class tests an object for edges
*/
class EC_ACTIN_GRASPING_DECL EcDecisionTreePassThroughBranch : public EcGraspingDecisionTreeBranch
{
public:
   /// default constructor
   EcDecisionTreePassThroughBranch
      (
      );

   /// destructor
   virtual ~EcDecisionTreePassThroughBranch
      (
      );

   /// copy constructor
   EcDecisionTreePassThroughBranch
      (
      const EcDecisionTreePassThroughBranch& orig
      );

   /// assignment operator
   EcDecisionTreePassThroughBranch& operator=
      (
      const EcDecisionTreePassThroughBranch& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDecisionTreePassThroughBranch& orig
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
   static EcDecisionTreePassThroughBranch nullObject
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

#endif // ecDecisionTreePassThroughBranch_H_
