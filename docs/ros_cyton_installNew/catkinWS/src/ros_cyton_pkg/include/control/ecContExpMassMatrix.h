#ifndef ecContExpMassMatrix_H_
#define ecContExpMassMatrix_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpMassMatrix.h
/// @class EcControlExpressionMassMatrix
/// @brief This expression returns the mass matrix of the manipulator.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"
#include "ecExpContainer.h"
#include <manipulator/ecMassMatrixTool.h>
#include <manipulator/ecMatrixDTool.h>

/// This expression returns the mass matrix of the manipulator.
class EC_ACTIN_CONTROL_DECL EcControlExpressionMassMatrix : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionMassMatrix
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcControlExpressionMassMatrix
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionMassMatrix
      (
      );

   /// copy constructor
   EcControlExpressionMassMatrix
      (
      const EcControlExpressionMassMatrix& orig
      );

   /// assignment operator
   EcControlExpressionMassMatrix& operator=
      (
      const EcControlExpressionMassMatrix& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionMassMatrix& orig
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
   /// @return (EcControlExpressionMassMatrix) The null object
   static EcControlExpressionMassMatrix nullObject
      (
      );

   /// token for this class
   /// @return (EcToken&) The xml class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The created objecct
   static EcXmlObject* creator
      (
      );

protected:
   /// utility mass-matrix tool
   mutable EcMassMatrixTool m_MassMatrixTool;

   /// utility matrix-D tool
   mutable EcMatrixDTool    m_MatrixDTool;

   /// utility array for matrix D
   mutable EcReArray        m_UtilityMatrixD;

   /// utility array for rigid-body inertia
   mutable EcReArray        m_UtilityRigidBodyInertia;
};

#endif // ecContExpMassMatrix_H_
