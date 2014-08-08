#ifndef ecXmlVariablePropertyEditor_H_
#define ecXmlVariablePropertyEditor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlVariablePropertyEditor.h
/// @class EcXmlVariablePropertyEditor
/// @brief Template class for property editor customized for EcXmlVariableElementType
//
//------------------------------------------------------------------------------
#include <foundCore/ecMacros.h>
#include <propertyEditorWrapper/ecPropertyEditor.h>
#include <QtCore/QStringList>

/////////////////////////////////////////////////////////////////////////////
// EcXmlVariablePropertyEditor
/**
\class EcXmlVariablePropertyEditor

Template class for property editor customized for EcXmlVariableElementType.
*/
template<class ElementType, class WrapperType, class ContainerType, class WrapperFactoryType>
class EcXmlVariablePropertyEditor : public QtPropertyEditor
{
public:
   /// constructor
   EcXmlVariablePropertyEditor
      (
      QWidget *parent=0
      );

   /// destructor
   ~EcXmlVariablePropertyEditor
      (
      );

   /// set the index of the current element
   virtual void setElementIndex
      (
      EcInt32 index
      );

   /// get the number of all available types
   virtual EcInt32 numAvailableTypes
      (
      ) const;

   /// get the pointer to the element at a given index
   virtual const ElementType* element
      (
      EcInt32 index
      ) const;

   /// set the element at a given index
   virtual EcBoolean setElement
      (
      EcInt32 index,
      const ElementType& value
      );

   /// get the list of the tokens of all available types
   const QStringList& availableTypes
      (
      ) const
   { return m_AvailableTypes; }

protected:
   QList< QPair < ElementType*, WrapperType* > >   m_vpElementWrapperPairs;
   QStringList    m_AvailableTypes;
};

#endif // ecXmlVariablePropertyEditor_H_
