#ifndef ecContExpGravTorqueGrad_H_
#define ecContExpGravTorqueGrad_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpGravTorqueGrad.h
/// @class EcControlExpressionGravitationalTorqueGradient
/// @brief This expression returns the gradient of the gravitational
///        torque/force squared on a single joint.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"
#include "ecExpContainer.h"
#include <manipulator/ecGravitationalTorqueTool.h>

/// This expression returns the gradient of the gravitational torque/force squared on a single joint.
class EC_ACTIN_CONTROL_DECL EcControlExpressionGravitationalTorqueGradient : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionGravitationalTorqueGradient
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcControlExpressionGravitationalTorqueGradient
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionGravitationalTorqueGradient
      (
      );

   /// copy constructor
   EcControlExpressionGravitationalTorqueGradient
      (
      const EcControlExpressionGravitationalTorqueGradient& orig
      );

   /// assignment operator
   EcControlExpressionGravitationalTorqueGradient& operator=
      (
      const EcControlExpressionGravitationalTorqueGradient& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionGravitationalTorqueGradient& orig
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
   /// @return The control expression gravitational torque gradient null object
   static EcControlExpressionGravitationalTorqueGradient nullObject
      (
      );

   /// token for this class
   /// @return (EcToken&) The xml class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The xml object
   static EcXmlObject* creator
      (
      );

protected:
   /// identification name for a link
   EcXmlString                       m_LinkIdentifier;

   /// utility gravitational-torque tool
   mutable EcGravitationalTorqueTool m_GravitationalTorqueTool;
};

#endif // ecContExpGravTorqueGrad_H_
