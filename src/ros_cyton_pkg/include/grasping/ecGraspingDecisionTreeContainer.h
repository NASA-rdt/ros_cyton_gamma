#ifndef ecGraspingDecisionTreeContainer_H_
#define ecGraspingDecisionTreeContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspingDecisionTreeContainer.h
/// @class EcGraspingDecisionTreeContainer
/// @brief Container for grasping decision tree
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecBaseExpTreeContainer.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

// Forward declarations
class EcGraspInitParams;
class EcGraspingDecisionTreeElement;
class EcObjectGraspingModule;

/// Container for grasping decision tree
class EC_ACTIN_GRASPING_DECL EcGraspingDecisionTreeContainer :
   public EcBaseExpressionTreeContainer<EcGraspingDecisionTreeElement>
{
public:
   /// default constructor
   EcGraspingDecisionTreeContainer
      (
      );

   /// destructor
   virtual ~EcGraspingDecisionTreeContainer
      (
      );

   /// copy constructor
   EcGraspingDecisionTreeContainer
      (
      const EcGraspingDecisionTreeContainer& orig
      );

   /// assignment operator
   EcGraspingDecisionTreeContainer& operator=
      (
      const EcGraspingDecisionTreeContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspingDecisionTreeContainer& orig
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

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
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

   /// set top element
   virtual void setTopElement
      (
      const EcGraspingDecisionTreeElement& topElement
      );

   /// perform an search through decision tree
   virtual EcBoolean search
      (
      const EcGraspInitParams& params,
      EcObjectGraspingModule& objectGraspingModule
      ) const;

   /// null object
   static EcGraspingDecisionTreeContainer nullObject
      (
      );

protected:
   /// set the container pointer for the top element to this
   virtual void setTopElementContainerToThis
      (
      );
};

#endif // ecGraspingDecisionTreeContainer_H_
