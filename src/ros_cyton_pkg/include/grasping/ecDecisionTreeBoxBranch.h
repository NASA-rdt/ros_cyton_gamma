#ifndef ecDecisionTreeBoxBranch_H_
#define ecDecisionTreeBoxBranch_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecDecisionTreeBoxBranch.h
/// @class EcDecisionTreeBoxBranch
/// @brief This class tests an object for a box
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspingDecisionTreeBranch.h"

class EcStatedSystem;

/** This class tests an object for a box
*/
class EC_ACTIN_GRASPING_DECL EcDecisionTreeBoxBranch : public EcGraspingDecisionTreeBranch
{
public:
   /// default constructor
   EcDecisionTreeBoxBranch
      (
      );

   /// destructor
   virtual ~EcDecisionTreeBoxBranch
      (
      );

   /// copy constructor
   EcDecisionTreeBoxBranch
      (
      const EcDecisionTreeBoxBranch& orig
      );

   /// assignment operator
   EcDecisionTreeBoxBranch& operator=
      (
      const EcDecisionTreeBoxBranch& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDecisionTreeBoxBranch& orig
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
   static EcDecisionTreeBoxBranch nullObject
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

#endif // ecDecisionTreeBoxBranch_H_
