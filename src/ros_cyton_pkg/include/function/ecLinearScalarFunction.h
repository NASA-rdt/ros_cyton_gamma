#ifndef ecLinearScalarFunction_H_
#define ecLinearScalarFunction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinearScalarFunction.h
/// @class EcLinearScalarFunction
/// @brief Holds a description of a unitary map that is shaped
///        like an s-curve.  It uses two pieces of rational polynomials.
///        The form used for each of the two pieces is
///        a0 x^2 + a1 x
///        f = -------------
///        (b-x)
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlBasicType.h>
#include "ecBaseScalarFunction.h"

/** Holds a description of a linear function defined through two points.
*/
class EC_FOUNDATION_FUNCTION_DECL EcLinearScalarFunction : public EcBaseScalarFunction
{
public:
   /// default constructor
   EcLinearScalarFunction
      (
      );

   /// destructor
   virtual ~EcLinearScalarFunction
      (
      );

   /// copy constructor
   EcLinearScalarFunction
      (
      const EcLinearScalarFunction& orig
      );

   /// assignment operator
   EcLinearScalarFunction& operator=
      (
      const EcLinearScalarFunction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinearScalarFunction& orig
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

   /// get start value
   virtual EcReal startValue
      (
      ) const;

   /// set start value
   virtual void setStartValue
      (
      EcReal startValue
      );

   /// get end value
   virtual EcReal endValue
      (
      ) const;

   /// set end value
   virtual void setEndValue
      (
      EcReal endValue
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
   static EcLinearScalarFunction nullObject
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
   EcXmlReal                      m_StartValue;

   /// Ending Value
   EcXmlReal                      m_EndValue;

};

#endif // ecLinearScalarFunction_H_
