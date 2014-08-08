#ifndef ecStageIGraspingContainer_H_
#define ecStageIGraspingContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecStageIGraspingContainer.h
/// @class EcStageIGraspingContainer
/// @brief Container for stage I grasping
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCommon/ecCoordSysXForm.h>
#include <xml/ecXmlVarElemType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

// Forward declarations
class EcBaseStageIGraspingModule;
class EcGraspInitParams;

/// Container for stage I grasping
class EC_ACTIN_GRASPING_DECL EcStageIGraspingContainer :
   public EcXmlVariableElementType<EcBaseStageIGraspingModule>
{
public:
   /// default constructor
   EcStageIGraspingContainer
      (
      );

   /// destructor
   virtual ~EcStageIGraspingContainer
      (
      );

   /// copy constructor
   EcStageIGraspingContainer
      (
      const EcStageIGraspingContainer& orig
      );

   /// assignment operator
   EcStageIGraspingContainer& operator=
      (
      const EcStageIGraspingContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStageIGraspingContainer& orig
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
   static EcStageIGraspingContainer nullObject
      (
      );

   /// initialize the grasp calculation for the specified object and manipulator
   virtual EcBoolean calculateGrasp
      (
      const EcGraspInitParams& params
      );
};

#endif // ecStageIGraspingContainer_H_
