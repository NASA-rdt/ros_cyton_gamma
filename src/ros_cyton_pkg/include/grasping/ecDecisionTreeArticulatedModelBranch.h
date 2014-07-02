#ifndef ecDecisionTreeArticulatedModelBranch_H_
#define ecDecisionTreeArticulatedModelBranch_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecDecisionTreeArticulatedModelBranch.h
/// @class EcDecisionTreeArticulatedModelBranch
/// @brief This class tests an object for an articulated model
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspingDecisionTreeBranch.h"

class EcStatedSystem;

/** This class tests an object for an articulated model using the joint positions. If the joint positions of all the specified links in the articulated model fall within their ranges, then the test passes (return value of 1) otherwise the test fails (returns 0). If there's no specified link, then the test also fails.
*/
class EC_ACTIN_GRASPING_DECL EcDecisionTreeArticulatedModelBranch : public EcGraspingDecisionTreeBranch
{
public:
   /// default constructor
   EcDecisionTreeArticulatedModelBranch
      (
      );

   /// destructor
   virtual ~EcDecisionTreeArticulatedModelBranch
      (
      );

   /// copy constructor
   EcDecisionTreeArticulatedModelBranch
      (
      const EcDecisionTreeArticulatedModelBranch& orig
      );

   /// assignment operator
   EcDecisionTreeArticulatedModelBranch& operator=
      (
      const EcDecisionTreeArticulatedModelBranch& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDecisionTreeArticulatedModelBranch& orig
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
   static EcDecisionTreeArticulatedModelBranch nullObject
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

   /// get the link labels
   virtual const EcXmlStringVector& linkLabels
      (
      ) const;

   /// set the link labels
   virtual void setLinkLabels
      (
      const EcXmlStringVector& labels
      );

   /// get the joint position ranges
   virtual const EcXmlRealRealPairVector& jointPositionRanges
      (
      ) const;

   /// set the joint position ranges
   virtual void setJointPositionRanges
      (
      const EcXmlRealRealPairVector& ranges
      );

   /// test the object for traversing the decision tree
   virtual EcReal test
      (
      const EcGraspInitParams& params
      ) const;

protected:

   /// a vector of string identifiers for the joint values to be checked
   EcXmlStringVector       m_LinkLabels;

   /// a vector of max and min values for each joint value used in comparison
   EcXmlRealRealPairVector m_JointPositionRanges;
};

#endif // ecDecisionTreeArticulatedModelBranch_H_
