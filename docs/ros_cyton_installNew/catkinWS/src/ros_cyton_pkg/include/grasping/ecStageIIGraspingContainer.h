#ifndef ecStageIIGraspingContainer_H_
#define ecStageIIGraspingContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecStageIIGraspingContainer.h
/// @class EcStageIIGraspingContainer
/// @brief Container for stage I grasping
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EcBaseStageIGraspingModule;
class EcBaseStageIIGraspingModule;
class EcGraspInitParams;
class EcStatedSystem;
class EcManipulatorEndEffectorPlacement;

/// Container for stage I grasping
class EC_ACTIN_GRASPING_DECL EcStageIIGraspingContainer :
   public EcXmlVariableElementType<EcBaseStageIIGraspingModule>
{
public:
   /// default constructor
   EcStageIIGraspingContainer
      (
      );

   /// destructor
   virtual ~EcStageIIGraspingContainer
      (
      );

   /// copy constructor
   EcStageIIGraspingContainer
      (
      const EcStageIIGraspingContainer& orig
      );

   /// assignment operator
   EcStageIIGraspingContainer& operator=
      (
      const EcStageIIGraspingContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStageIIGraspingContainer& orig
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

   /// set the pointer to the Stage I module
   virtual void setPrecursorPointer
      (
      EcBaseStageIGraspingModule* precursorPointer
      );

   /// null object
   static EcStageIIGraspingContainer nullObject
      (
      );

   /// initialize the grasp calculation for the specified object
   /// and manipulator
   virtual EcBoolean calculateGrasp
      (
      const EcGraspInitParams& params
      );
};

#endif // ecStageIIGraspingContainer_H_
