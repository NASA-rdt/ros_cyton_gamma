#ifndef ecDecisionTreeFamilyBranch_H_
#define ecDecisionTreeFamilyBranch_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecDecisionTreeFamilyBranch.h
/// @class EcDecisionTreeFamilyBranch
/// @brief This class tests an object for edges
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspingDecisionTreeBranch.h"

class EcStatedSystem;

/** This class tests an object for edges
*/
class EC_ACTIN_GRASPING_DECL EcDecisionTreeFamilyBranch : public EcGraspingDecisionTreeBranch
{
public:
   /// default constructor
   EcDecisionTreeFamilyBranch
      (
      );

   /// destructor
   virtual ~EcDecisionTreeFamilyBranch
      (
      );

   /// copy constructor
   EcDecisionTreeFamilyBranch
      (
      const EcDecisionTreeFamilyBranch& orig
      );

   /// assignment operator
   EcDecisionTreeFamilyBranch& operator=
      (
      const EcDecisionTreeFamilyBranch& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDecisionTreeFamilyBranch& orig
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

   /// get the family
   virtual const EcString& family
      (
      ) const;

   /// set the family
   virtual void setFamily
      (
      const EcString& family
      );

   /// get the index
   virtual EcU32 index
      (
      ) const;

   /// set the index
   virtual void setIndex
      (
      EcU32 index
      );

   /// get whether to use index instead family for testing
   virtual EcBoolean useIndex
      (
      ) const;

   /// set whether to use index instead family for testing
   virtual void setUseIndex
      (
      EcBoolean useIndex
      );

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
   static EcDecisionTreeFamilyBranch nullObject
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
   /// If useIndex() is true, then if the index in the grasp descriptor is greater than or equal to the index in this branch, it will traverse right. Otherwise, it will the left.
   /// If useIndex() is false, then if the family name in the grasp descriptor is equal to the family name in this branch (case sensitive), it will traverse right. Otherwise, it will traverse left.
   virtual EcReal test
      (
      const EcGraspInitParams& params
      ) const;

protected:
   /// Family name used in the test
   EcXmlString m_Family;

   /// Index used in the test
   EcXmlU32    m_Index;

   /// Signify that it should use index for testing instead of family name
   EcXmlBoolean   m_UseIndex;
};

#endif // ecDecisionTreeFamilyBranch_H_
