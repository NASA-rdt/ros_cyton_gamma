#ifndef ecContExpJointLimitFilter_H_
#define ecContExpJointLimitFilter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpJointLimitFilter.h
/// @class EcControlExpressionJointLimitFilter
/// @brief This caps the weighted infinity norm of the joint rates.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"
#include "ecExpContainer.h"
#include "ecContExpContainer.h"

class EC_ACTIN_CONTROL_DECL EcControlExpressionJointLimitFilter : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionJointLimitFilter
      (
      );

   /// constructor from an EcControlExpressionContainer pointer
   EcControlExpressionJointLimitFilter
      (
      const EcControlExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionJointLimitFilter
      (
      );

   /// copy constructor
   EcControlExpressionJointLimitFilter
      (
      const EcControlExpressionJointLimitFilter& orig
      );

   /// assignment operator
   EcControlExpressionJointLimitFilter& operator=
      (
      const EcControlExpressionJointLimitFilter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionJointLimitFilter& orig
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

   /// sets the container
   /// @param[in] container (EcXmlBaseVariableCompoundType*) value to set the container
   virtual void setContainer
      (
      const EcXmlBaseVariableCompoundType* container
      );

   /// gets the unfiltered rates
   /// @return The unfiltereed joint rates
   virtual const EcControlExpressionContainer& unfilteredRates
      (
      ) const;

   /// sets the unfiltered rates
   /// @param[in] unfilteredRatesContainer (EcControlExpressionContainer&) set unfiltered rates container
   virtual void setUnfilteredRatesContainer
      (
      const EcControlExpressionContainer& unfilteredRatesContainer
      );

   /// sets the unfiltered rates element
   /// @param[in] unfilteredRatesElement (EcExpressionElement&) set element of un-filtered rates
   virtual void setUnfilteredRatesElement
      (
      const EcExpressionElement& unfilteredRatesElement
      );

   /// gets the is-on flag
   /// @return (EcReal) TODO, (what is isOn flag?)
   virtual EcReal isOn
      (
      ) const;

   /// sets the is-on flag
   /// @param[in] isOn (EcBoolean) value to set the flag
   virtual void setIsOn
      (
      EcBoolean isOn
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
   /// @return The control expression joint limit filter null object
   static EcControlExpressionJointLimitFilter nullObject
      (
      );

   /// token for this class
   /// @return The class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The xml object creator
   static EcXmlObject* creator
      (
      );

protected:

   /// the unfiltered joint rates
   EcControlExpressionContainer  m_UnfilteredRates;

   /// a switch
   EcXmlBoolean                  m_IsOn;

   /// non-XML variables below
   mutable EcRealVector          m_BaseComponent;
   /// TODO
   mutable EcRealVector          m_NullSpaceComponent;
   /// TODO
   mutable EcRealVector          m_TotalJointRateSolution;
   /// TODO
   mutable EcReArray             m_McArray;

};

#endif // ecContExpJointLimitFilter_H_
