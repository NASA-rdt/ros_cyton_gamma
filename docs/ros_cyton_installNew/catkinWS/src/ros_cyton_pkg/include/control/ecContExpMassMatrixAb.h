#ifndef ecContExpMassMatrixAb_H_
#define ecContExpMassMatrixAb_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpMassMatrixAb.h
/// @class EcControlExpressionMassMatrixAB
/// @brief This expression returns the torque needed toachieve the
///        desired acceleration equal to the nullspacemass.  Same
///        as Nj^T * (mass matrix of the manipulator).
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecExpElement.h"
#include "ecExpContainer.h"
#include <manipulator/ecMassMatrixTool.h>
#include <xml/ecXmlBasicType.h>

/// This expression returns the mass matrix of the manipulator.
class EC_ACTIN_CONTROL_DECL EcControlExpressionMassMatrixAB : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionMassMatrixAB
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcControlExpressionMassMatrixAB
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionMassMatrixAB
      (
      );

   /// copy constructor
   EcControlExpressionMassMatrixAB
      (
      const EcControlExpressionMassMatrixAB& orig
      );

   /// assignment operator
   EcControlExpressionMassMatrixAB& operator=
      (
      const EcControlExpressionMassMatrixAB& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionMassMatrixAB& orig
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
   /// @return (EcControlExpressionMassMatrixAB) The null object
   static EcControlExpressionMassMatrixAB nullObject
      (
      );

   /// token for this class
   /// @return (EcToken&) The xml token
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// utility mass-matrix tool
   mutable EcMassMatrixTool m_MassMatrixTool;
};

#endif // ecContExpMassMatrixAb_H_
