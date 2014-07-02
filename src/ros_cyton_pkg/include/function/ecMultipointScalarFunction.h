#ifndef EcMultipointScalarFunction_H_
#define EcMultipointScalarFunction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2010-2013 Energid Technologies. All rights reserved.
//
/// @file ecMultipointScalarFunction.h
/// @class EcMultipointScalarFunction
/// @brief Holds a function defined through multiple points
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlVectorType.h>
#include "ecBaseScalarFunction.h"

/** Holds a description of a piecewise linear function defined through multiple points.
*/
class EC_FOUNDATION_FUNCTION_DECL EcMultipointScalarFunction : public EcBaseScalarFunction
{
public:
   /// default constructor
   EcMultipointScalarFunction
      (
      );

   /// destructor
   virtual ~EcMultipointScalarFunction
      (
      );

   /// copy constructor
   EcMultipointScalarFunction
      (
      const EcMultipointScalarFunction& orig
      );

   /// assignment operator
   EcMultipointScalarFunction& operator=
      (
      const EcMultipointScalarFunction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcMultipointScalarFunction& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// get domain values
   virtual const EcXmlRealVector& domainValues
      (
      ) const;

   /// set domain values
   virtual void setDomainValues
      (
      const EcXmlRealVector& domainValues
      );

   /// get range values
   virtual const EcXmlRealVector& rangeValues
      (
      ) const;

   /// set range values
   virtual void setRangeValues
      (
      const EcXmlRealVector& rangeValues
      );

   /// evaluate the function
   virtual EcReal evaluate
      (
      const EcReal& domainValue
      ) const;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   static EcMultipointScalarFunction nullObject
      (
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcBaseScalarFunction* creator
      (
      );

   /// static creator function to an xml object pointer
   static EcXmlObject* xmlObjectCreator
      (
      );

protected:
   /// starting value
   EcXmlRealVector                m_DomainValues;

   /// Ending Value
   EcXmlRealVector                m_RangeValues;

};

#endif // EcMultipointScalarFunction_H_
