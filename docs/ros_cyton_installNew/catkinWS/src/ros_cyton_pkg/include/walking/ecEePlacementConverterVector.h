#ifndef ecEePlacementConverterVector_H_
#define ecEePlacementConverterVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecEePlacementConverterVector.h
/// @brief Vector of EE placement converters
/// @details EcEndEffectorPlacementConverterVector
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarVectType.h>

#include "ecBaseEePlacementConverter.h"
#include <control/ecManipEndEffectorPlace.h>
#include <manipulator/ecIndManipulator.h>

/// type definition of XML variable vector of EcBaseEndEffectorPlacementConverter to be used as a base class
typedef EcXmlVariableVectorType<EcBaseEndEffectorPlacementConverter> EcBaseEndEffectorPlacementConverterVector;

/// Vector of end-effector placement converters
class EC_ACTIN_WALKING_DECL EcEndEffectorPlacementConverterVector : public EcBaseEndEffectorPlacementConverterVector
{
public:
   /// default constructor
   EcEndEffectorPlacementConverterVector
      (
      );

   /// destructor
   virtual ~EcEndEffectorPlacementConverterVector
      (
      );

   /// copy constructor
   EcEndEffectorPlacementConverterVector
      (
      const EcEndEffectorPlacementConverterVector& orig
      );

   /// assignment operator
   EcEndEffectorPlacementConverterVector& operator=
      (
      const EcEndEffectorPlacementConverterVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcEndEffectorPlacementConverterVector& orig
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

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// find the index of the converter in the vector that matches the given manipulator index
   /**
   \param[in] manipulatorIndex The manipulator index.
   \param[out] index Upon successful return, it will contain the converter index.
   \return True if a converter was found or false otherwise.
   */
   virtual EcBoolean findConverterIndex
      (
      EcU32 manipulatorIndex,
      EcU32& index
      ) const;

   /// get a null object
   static EcEndEffectorPlacementConverterVector nullObject
      (
      );
};

#endif // ecEePlacementConverterVector_H_
