#ifndef ecGraspFrameContainer_H_
#define ecGraspFrameContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspFrameContainer.h
/// @class EcGraspFrameContainer
/// @brief Container for grasp frames
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>

class EcGraspFrame;

/// Container for grasp frames
class EC_ACTIN_GRASPING_DECL EcGraspFrameContainer :
   public EcXmlVariableElementType<EcGraspFrame>
{
public:
   /// default constructor
   EcGraspFrameContainer
      (
      );

   /// destructor
   virtual ~EcGraspFrameContainer
      (
      );

   /// copy constructor
   EcGraspFrameContainer
      (
      const EcGraspFrameContainer& orig
      );

   /// assignment operator
   EcGraspFrameContainer& operator=
      (
      const EcGraspFrameContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspFrameContainer& orig
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
   static EcGraspFrameContainer nullObject
      (
      );
};


/// an XML readable/writable vector of EcGraspFrameContainer objects
typedef EcXmlVectorType<EcGraspFrameContainer> EcGraspFrameContainerVector;

#endif // ecGraspFrameContainer_H_
