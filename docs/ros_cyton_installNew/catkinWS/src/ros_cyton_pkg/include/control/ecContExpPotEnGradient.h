#ifndef ecContExpPotEnGradient_H_
#define ecContExpPotEnGradient_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpPotEnGradient.h
/// @class EcControlExpressionPotentialEnergyGradient
/// @brief This expression returns the potential-energy gradient
///        of the manipulator.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecExpElement.h"
#include "ecExpContainer.h"
#include <manipulator/ecGravitationalTorqueTool.h>
#include <xml/ecXmlBasicType.h>

class EC_ACTIN_CONTROL_DECL EcControlExpressionPotentialEnergyGradient : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionPotentialEnergyGradient
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcControlExpressionPotentialEnergyGradient
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionPotentialEnergyGradient
      (
      );

   /// copy constructor
   EcControlExpressionPotentialEnergyGradient
      (
      const EcControlExpressionPotentialEnergyGradient& orig
      );

   /// assignment operator
   EcControlExpressionPotentialEnergyGradient& operator=
      (
      const EcControlExpressionPotentialEnergyGradient& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionPotentialEnergyGradient& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   /// @return (EcXmlObject*) The xml object pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   /// @param[in] other (EcXmlObject*) the xml object pointer
   /// @return (EcBoolean) The flag indication equalting of the object
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   /// @return (EcXmlObject*) newly createed object pointer
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return the value
   /// @return (EcVelocityControlData&) the velocity control data
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// return a token
   /// @return (EcToken&) the xml token
   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   /// @param[in] stream (EcXmlReader&) stream to be read from xml file
   /// @return flag indicating the status
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   /// @param[in] stream (EcXmlWriter&) stream to be written into xml file
   /// @return Flag indicating the status
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   /// @return (EcControlExpressionPotentialEnergyGradient) the control expression potential energy gradient null object
   static EcControlExpressionPotentialEnergyGradient nullObject
      (
      );

   /// token for this class
   /// @return (EcToken&) The xml token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The xml object pointer
   static EcXmlObject* creator
      (
      );

protected:
   /// utility gravitational-torque tool
   mutable EcGravitationalTorqueTool m_GravitationalTorqueTool;
};

#endif // ecContExpPotEnGradient_H_
