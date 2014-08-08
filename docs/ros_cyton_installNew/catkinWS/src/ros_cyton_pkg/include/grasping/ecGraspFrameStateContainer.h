#ifndef ecGraspFrameStateContainer_H_
#define ecGraspFrameStateContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspFrameStateContainer.h
/// @class EcGraspFrameStateContainer
/// @brief Container for grasp frames
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EcGraspFrameState;

/// Container for grasp frames
class EC_ACTIN_GRASPING_DECL EcGraspFrameStateContainer :
   public EcXmlVariableElementType<EcGraspFrameState>
{
public:
   /// default constructor
   EcGraspFrameStateContainer
      (
      );

   /// destructor
   virtual ~EcGraspFrameStateContainer
      (
      );

   /// copy constructor
   EcGraspFrameStateContainer
      (
      const EcGraspFrameStateContainer& orig
      );

   /// assignment operator
   EcGraspFrameStateContainer& operator=
      (
      const EcGraspFrameStateContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspFrameStateContainer& orig
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

   /// null object
   static EcGraspFrameStateContainer nullObject
      (
      );
};

/// an XML readable/writable vector of EcGraspFrameStateContainer objects
typedef EcXmlVectorType<EcGraspFrameStateContainer> EcGraspFrameStateContainerVector;

#endif // ecGraspFrameStateContainer_H_
