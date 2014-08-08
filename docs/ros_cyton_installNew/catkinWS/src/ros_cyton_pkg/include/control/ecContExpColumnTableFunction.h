#ifndef ecContExpColumnTableFunction_H_
#define ecContExpColumnTableFunction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpColumnTableFunction.h
/// @class EcControlExpressionColumnTableFunction
/// @brief This evaluates a table function on the child.  The
///        input and the output are columns.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"
#include "ecExpContainer.h"
#include "ecContExpContainer.h"
#include <function/ecCompositeFunctionContainer.h>

/// This evaluates a table function on the child.  The input and the output are columns.
class EC_ACTIN_CONTROL_DECL EcControlExpressionColumnTableFunction : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionColumnTableFunction
      (
      );

   /// constructor from an EcControlExpressionContainer pointer
   EcControlExpressionColumnTableFunction
      (
      const EcControlExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionColumnTableFunction
      (
      );

   /// copy constructor
   EcControlExpressionColumnTableFunction
      (
      const EcControlExpressionColumnTableFunction& orig
      );

   /// assignment operator
   EcControlExpressionColumnTableFunction& operator=
      (
      const EcControlExpressionColumnTableFunction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionColumnTableFunction& orig
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
   /// @return (EcXmlObject*) The xml object
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

   /// sets the container
   /// @param[in] container (EcXmlBaseVariableCompoundType*) value to set the container
   virtual void setContainer
      (
      const EcXmlBaseVariableCompoundType* container
      );

   /// gets the input values container
   /// @return (EcControlExpressionContainer&) The input values container
   virtual const EcControlExpressionContainer& inputValuesContainer
      (
      ) const;

   /// sets the input values container
   /// @param[in] inputValuesContainer (EcControlExpressionContainer&) value to set the input value container
   virtual void setInputValuesContainer
      (
      const EcControlExpressionContainer& inputValuesContainer
      );

   /// sets the input values element
   /// @param[in] inputValuesElement (EcExpressionElement&) value to set the input values element of the container
   virtual void setInputValuesElement
      (
      const EcExpressionElement& inputValuesElement
      );

   /// gets the table function container
   /// @return (EcCompositeFunctionContainer&) The composite dunction container
   virtual const EcCompositeFunctionContainer& tableFunctionContainer
      (
      ) const;

   /// sets the table function container
   /// @param[in] tableFunctionContainer (EcCompositeFunctionContainer&) Value to set the table fucntion container
   virtual void setTableFunctionContainer
      (
      const EcCompositeFunctionContainer& tableFunctionContainer
      );

   /// sets the table function element
   /// @param[in] tableFunctionElement (EcCompositeFunctionElement&) value to set the table function container element
   virtual void setTableFunctionElement
      (
      const EcCompositeFunctionElement& tableFunctionElement
      );

   /// return a token
   ///@return (EcToken&) The xml token
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
   /// @return (EcControlExpressionColumnTableFunction) The null object
   static EcControlExpressionColumnTableFunction nullObject
      (
      );

   /// token for this class
   /// @return (EcToken&) The classs token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) the xml object pointer
   static EcXmlObject* creator
      (
      );

protected:
   /// the input values container
   EcControlExpressionContainer  m_InputValuesContainer;

   /// the table function container
   EcCompositeFunctionContainer      m_TableFunctionContainer;

   /// a utility vector to hold input values
   mutable EcRealVector            m_InputVector;
};

#endif // ecContExpColumnTableFunction_H_
