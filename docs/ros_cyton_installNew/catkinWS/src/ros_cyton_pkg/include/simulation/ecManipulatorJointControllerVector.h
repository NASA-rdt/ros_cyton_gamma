#ifndef ecManipulatorJointControllerVector_H_
#define ecManipulatorJointControllerVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulatorJointControllerVector.h
/// @class EcManipulatorJointControllerVector
/// @brief Holds a description of a vector of manipulator-level
///        joint controllers.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseManipulatorJointController.h"
#include <xml/ecXmlVarVectType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// type definition of EcBaseManipulatorJointControllerVector
typedef EcXmlVariableVectorType<EcBaseManipulatorJointController> EcBaseManipulatorJointControllerVector;

/** Holds a description of a vector of manipulator-level joint controllers.
*/
class EC_ACTIN_SIMULATION_DECL EcManipulatorJointControllerVector : public EcBaseManipulatorJointControllerVector
{
public:
   /// default constructor
   EcManipulatorJointControllerVector
      (
      );

   /// destructor
   virtual ~EcManipulatorJointControllerVector
      (
      );

   /// copy constructor
   EcManipulatorJointControllerVector
      (
      const EcManipulatorJointControllerVector& orig
      );

   /// assignment operator
   EcManipulatorJointControllerVector& operator=
      (
      const EcManipulatorJointControllerVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorJointControllerVector& orig
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
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

   /// register components with the parent
   virtual void registerComponents
      (
      );

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

   /// get a null object
   static EcManipulatorJointControllerVector nullObject
      (
      );
};

#endif // ecManipulatorJointControllerVector_H_
