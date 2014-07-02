#ifndef ecContExpMatrixToAb_H_
#define ecContExpMatrixToAb_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpMatrixToAb.h
/// @class EcControlExpressionMatrixToAB
/// @brief This expression element converts a full matrix (as would be
///        appropriate for control core) to an AB matrix value (as would be appropriate
///        for control AB core).
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include "ecExpBaseUnary.h"
#include "ecContExpContainer.h"
#include "ecJacobianTool.h"

/// This expression element converts a full matrix (as would be appropriate for control core) to an AB matrix value (as would be appropriate for control AB core).
class EC_ACTIN_CONTROL_DECL EcControlExpressionMatrixToAB : public EcExpressionBaseUnary
{
public:
   /// default constructor
   EcControlExpressionMatrixToAB
      (
      );

   /// constructor from an EcControlExpressionContainer pointer
   EcControlExpressionMatrixToAB
      (
      const EcControlExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionMatrixToAB
      (
      );

   /// copy constructor
   EcControlExpressionMatrixToAB
      (
      const EcControlExpressionMatrixToAB& orig
      );

   /// assignment operator
   EcControlExpressionMatrixToAB& operator=
      (
      const EcControlExpressionMatrixToAB& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionMatrixToAB& orig
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
   /// @return (EcVelocityControlData&) The velocity control data
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
   /// @param[in] stream (EcXmlReader&) stream to be read from xml file
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   /// @param[in] stream (EcXmlWriter&) stream to be written into xml file
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   /// @return (EcControlExpressionMatrixToAB) the null object
   static EcControlExpressionMatrixToAB nullObject
      (
      );

   /// token for this class
   /// @return (EcToken&) the classs token
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

#endif // ecContExpMatrixToAb_H_
