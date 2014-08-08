#ifndef ecContExpVectorToAb_H_
#define ecContExpVectorToAb_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpVectorToAb.h
/// @class EcControlExpressionVectorToAB
/// @brief This expression element converts a full vector (as would be
///        appropriate for control core) to an AB vector value (as would be appropriate
///        for control AB core).
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecExpBaseUnary.h"
#include "ecContExpContainer.h"
#include "ecJacobianTool.h"

/// This expression element converts a full vector (as would be appropriate for control core) to an AB vector value (as would be appropriate for control AB core).
class EC_ACTIN_CONTROL_DECL EcControlExpressionVectorToAB : public EcExpressionBaseUnary
{
public:
   /// default constructor
   EcControlExpressionVectorToAB
      (
      );

   /// constructor from an EcControlExpressionContainer pointer
   EcControlExpressionVectorToAB
      (
      const EcControlExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionVectorToAB
      (
      );

   /// copy constructor
   EcControlExpressionVectorToAB
      (
      const EcControlExpressionVectorToAB& orig
      );

   /// assignment operator
   EcControlExpressionVectorToAB& operator=
      (
      const EcControlExpressionVectorToAB& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionVectorToAB& orig
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
   virtual const EcToken& token
      (
      ) const;

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
   static EcControlExpressionVectorToAB nullObject
      (
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// utility Jacobian tool
   mutable EcJacobianTool m_JacobianTool;
};

#endif // ecContExpVectorToAb_H_
