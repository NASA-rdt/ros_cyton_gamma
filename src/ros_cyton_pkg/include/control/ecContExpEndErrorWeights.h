#ifndef ecContExpEndErrorWeights_H_
#define ecContExpEndErrorWeights_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpEndErrorWeights.h
/// @class EcControlExpressionEndEffectorErrorWeights
/// @brief This returns a matrix of weights as provided by
///        the end effectors.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecContExpContainer.h"
#include "ecEndEffectorTool.h"
#include "ecExpElement.h"
#include "ecJacobianTool.h"
#include "ecManipEndEffectorVel.h"

/// This returns a matrix of weights as provided by the end effectors.
class EC_ACTIN_CONTROL_DECL EcControlExpressionEndEffectorErrorWeights : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionEndEffectorErrorWeights
      (
      );

   /// constructor from an EcControlExpressionContainer pointer
   EcControlExpressionEndEffectorErrorWeights
      (
      const EcControlExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionEndEffectorErrorWeights
      (
      );

   /// copy constructor
   EcControlExpressionEndEffectorErrorWeights
      (
      const EcControlExpressionEndEffectorErrorWeights& orig
      );

   /// assignment operator
   EcControlExpressionEndEffectorErrorWeights& operator=
      (
      const EcControlExpressionEndEffectorErrorWeights& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionEndEffectorErrorWeights& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
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

   /// return the value
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// sets the container
   virtual void setContainer
      (
      const EcXmlBaseVariableCompoundType* container
      );

   /// return a token
   /// @return (EcToken&) The xml token
   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   /// @param[in] stream (EcXmlReader&) Stream to be read
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   /// @param[in] stream (EcXmlWriter&) Xml stream to be writtern into file
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   /// @return (EcControlExpressionEndEffectorErrorWeights) The null object
   static EcControlExpressionEndEffectorErrorWeights nullObject
      (
      );

   /// token for this class
   /// @return (EcToken&) The xml class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return The xml object
   static EcXmlObject* creator
      (
      );
};

#endif // ecContExpEndErrorWeights_H_
