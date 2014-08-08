#ifndef ecManipGraspingModule_H_
#define ecManipGraspingModule_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipGraspingModule.h
/// @class EcManipulatorGraspingModule
/// @brief This class is a container for hand grasping modules.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarVectType.h>

class EcBaseHandGraspingModule;

/** This class is a container for hand grasping modules.
*/
class EC_ACTIN_GRASPING_DECL EcManipulatorGraspingModule : public EcXmlVariableVectorType<EcBaseHandGraspingModule>
{
public:
   /// default constructor
   EcManipulatorGraspingModule
      (
      );

   /// destructor
   virtual ~EcManipulatorGraspingModule
      (
      );

   /// copy constructor
   EcManipulatorGraspingModule
      (
      const EcManipulatorGraspingModule& orig
      );

   /// assignment operator
   EcManipulatorGraspingModule& operator=
      (
      const EcManipulatorGraspingModule& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorGraspingModule& orig
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

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// register all component creators - should be subclassed in child
   virtual void registerComponentCreators
      (
      );

   /// get a grasping module
   virtual EcBaseHandGraspingModule* getGraspingModule
      (
      const EcString& handDescriptor
      ) const;

   /// input hand grasping module
   virtual void pushBackGraspingModule
      (
      const EcBaseHandGraspingModule& handGraspingModule
      );
};

/// a vector of manipulator grasping modules
typedef EcXmlVectorType<EcManipulatorGraspingModule>
   EcManipulatorGraspingModuleVector;

#endif // ecManipGraspingModule_H_
