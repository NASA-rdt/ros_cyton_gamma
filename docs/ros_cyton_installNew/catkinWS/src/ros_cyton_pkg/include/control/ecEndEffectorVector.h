#ifndef ecEndEffectorVector_H_
#define ecEndEffectorVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecEndEffectorVector.h
/// @class EcEndEffectorVector
/// @brief Holds a description of a vector of general end effectors.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlBasicType.h>
#include "ecEndEffector.h"
#include <xml/ecXmlVarVectType.h>

#include "ecManipEndEffectorPlace.h"

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// type definition of XML variable vector of EcEndEffector to be used as a base class
typedef EcXmlVariableVectorType<EcEndEffector> EcBaseGeneralEndEffectorVector;

/// Holds a description of a vector of general end effectors.
class EC_ACTIN_CONTROL_DECL EcEndEffectorVector : public EcBaseGeneralEndEffectorVector
{
public:
   /// default constructor
   EcEndEffectorVector
      (
      );

   /// destructor
   virtual ~EcEndEffectorVector
      (
      );

   /// copy constructor
   EcEndEffectorVector
      (
      const EcEndEffectorVector& orig
      );

   /// assignment operator
   EcEndEffectorVector& operator=
      (
      const EcEndEffectorVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcEndEffectorVector& orig
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

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// set relative link data
   virtual EcBoolean setRelativeLinkData
      (
      EcU32 index,
      const EcEndEffectorRelativeLinkData relativeLinkData
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
   static EcEndEffectorVector nullObject
      (
      );

   /// given an endeffector token name, return an endeffector object
   virtual EcEndEffector* endEffectorFromToken
      (
      const EcToken& token
      );
};

#endif // ecEndEffectorVector_H_
