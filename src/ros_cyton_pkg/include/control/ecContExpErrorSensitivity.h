#ifndef ecContExpErrorSensitivity_H_
#define ecContExpErrorSensitivity_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpErrorSensitivity.h
/// @class EcControlExpressionErrorSensitivity
/// @brief This expression returns the gradient of an error
///        sensitivity function.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"
#include "ecExpContainer.h"
#include "ecFiniteDifferenceTool.h"
#include <measure/ecErrorSensFunction.h>

/// This expression returns the gradient of an error sensitivity function.
class EC_ACTIN_CONTROL_DECL EcControlExpressionErrorSensitivity : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionErrorSensitivity
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcControlExpressionErrorSensitivity
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionErrorSensitivity
      (
      );

   /// copy constructor
   EcControlExpressionErrorSensitivity
      (
      const EcControlExpressionErrorSensitivity& orig
      );

   /// assignment operator
   EcControlExpressionErrorSensitivity& operator=
      (
      const EcControlExpressionErrorSensitivity& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionErrorSensitivity& orig
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

   /// gets the link identifier
   /// @return The link identifier name
   virtual const EcString& linkIdentifier
      (
      ) const;

   /// sets the link identifier
   /// @param[in] linkIdentifier (EcString&) value to set
   virtual void setLinkIdentifier
      (
      const EcString& linkIdentifier
      );

   /// get the end-effector weights
   /// @return (EcXmlRealVector&) The end-effector weights TODO
   virtual const EcXmlRealVector& endEffectorWeights
      (
      ) const;

   /// set the end-effector weights
   /// @param[in] endEffectorWeights (EcXmlRealVector&) weights to set the end-effector weights
   virtual void setEndEffectorWeights
      (
      const EcXmlRealVector& endEffectorWeights
      );

   /// return the value
   /// @return The velocity control data
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// return a token
   /// @return (EcToken&) The xml token
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
   /// @return The null object
   static EcControlExpressionErrorSensitivity nullObject
      (
      );

   /// token for this class
   /// @return The class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The xml object created
   static EcXmlObject* creator
      (
      );

protected:
   /// the link (joint) identifier
   EcXmlString                        m_LinkIdentifier;

   /// a vector of input weights
   EcXmlRealVector                    m_EndEffectorWeights;

   /// utility finite-difference tool
   mutable EcFiniteDifferenceTool     m_FiniteDifferenceTool;

   /// utility function
   mutable EcErrorSensitivityFunction m_ErrorSensitivityFunction;
};

#endif // ecContExpErrorSensitivity_H_
