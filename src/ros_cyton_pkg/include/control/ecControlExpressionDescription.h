#ifndef ecControlExpressionDescription_H_
#define ecControlExpressionDescription_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecControlExpressionDescription.h
/// @class EcControlExpressionDescription
/// @brief A class containing EcControlExpressionContainer and a label
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecContExpContainer.h"
#include <xml/ecXmlCompType.h>

// forward declarations
class EcIndividualManipulator;

class EC_ACTIN_CONTROL_DECL EcControlExpressionDescription : public EcXmlCompoundType
{
public:
   /// default constructor
   EcControlExpressionDescription
      (
      );

   /// destructor
   virtual ~EcControlExpressionDescription
      (
      );

   /// copy constructor
   EcControlExpressionDescription
      (
      const EcControlExpressionDescription& orig
      );

   /// assignment operator
   EcControlExpressionDescription& operator=
      (
      const EcControlExpressionDescription& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionDescription& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// gets the label
   virtual const EcXmlString& label
      (
      ) const;

   /// sets the label
   virtual void setLabel
      (
      const EcXmlString& label
      );

   /// gets the control expression
   virtual const EcControlExpressionContainer& controlExpression
      (
      ) const;

   /// gets the control expression -- non-const
   virtual EcControlExpressionContainer& controlExpression
      (
      );

   /// sets the control expression
   virtual void setControlExpression
      (
      const EcControlExpressionContainer& controlExpression
      );

   /// gets the is-floating-base flag
   virtual EcBoolean isFixedBase
      (
      ) const;

   /// sets the is-floating-base flag
   virtual void setIsFixedBase
      (
      EcBoolean isFixedBase
      );

   /// gets the data-map pointer
   virtual const EcDataMap* dataMapPointer
      (
      ) const;

   /// sets the data-map pointer for a specified manipulator
   virtual void setDataMapPointer
      (
      const EcDataMap* pDataMap
      );

   /// return the calculated value
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader &stream
      );

   /// token
   virtual const EcToken& token
      (
      ) const;

   /// return the null object
   static EcControlExpressionDescription nullObject
      (
      );

   /// create a default control description from a manipulator
   static EcControlExpressionDescription createDefaultFromManipulator
      (
      const EcIndividualManipulator& manipulator
         );

protected:

   /// the label
   EcXmlString                           m_Label;

   /// the control expression
   EcControlExpressionContainer          m_ControlExpression;

   /// a flag indicating floating-base control
   EcXmlBoolean                          m_IsFixedBase;
};

/// a vector of individual velocity control descriptions
typedef EcXmlVectorType<EcControlExpressionDescription>
   EcControlExpressionDescriptionVector;

#endif // ecControlExpressionDescription_H_
