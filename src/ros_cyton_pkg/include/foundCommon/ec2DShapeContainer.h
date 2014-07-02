#ifndef ec2DShapeContainer_H_
#define ec2DShapeContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ec2DShapeContainer.h
/// @class Ec2DShapeContainer
/// @brief Holds a container for a joint position finder.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>   // Required to be first header.
#include "ecXml2DShape.h"
#include <xml/ecXmlVarElemType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// a containter that can hold any 2D shape (subclassed from EcXml2DShape)
typedef EcXmlVariableElementType<EcXml2DShape> EcBase2DShapeContainer;

/// Holds a container for a 2dShapes
class EC_FOUNDATION_FOUNDCOMMON_DECL Ec2DShapeContainer : public EcBase2DShapeContainer
{
public:
   /// default constructor
   Ec2DShapeContainer
      (
      );

   /// destructor
   virtual ~Ec2DShapeContainer
      (
      );

   /// copy constructor
   Ec2DShapeContainer
      (
      const Ec2DShapeContainer& orig
      );

   /// assignment operator
   Ec2DShapeContainer& operator=
      (
      const Ec2DShapeContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const Ec2DShapeContainer& orig
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
   /**
       \return string token that describes the XML object
   */
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   /**
       \return cloned XML object
   */
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );
};



#endif // ec2DShapeContainer_H_
