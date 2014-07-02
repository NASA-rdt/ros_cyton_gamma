#ifndef ecBaseScalarFunction_H_
#define ecBaseScalarFunction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseScalarFunction.h
/// @class EcBaseScalarFunction
/// @brief Holds a description of a base class defining a function that
///        one-to-one maps the range 0-1 to the domain 0-1.  It represents
///        a scalar function that must be monotonically increasing.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecBaseExpTreeElement.h>
#include <xml/ecXmlBasicType.h>

class EcImage;

/** Holds a description of a base class defining a function that
one-to-one maps the range 0-1 to the domain [start end].  It represents
a scalar function that does not need to be monotonically increasing.
*/
class EC_FOUNDATION_FUNCTION_DECL EcBaseScalarFunction : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcBaseScalarFunction
      (
      );

   /// destructor
   virtual ~EcBaseScalarFunction
      (
      );

   /// copy constructor
   EcBaseScalarFunction
      (
      const EcBaseScalarFunction& orig
      );

   /// assignment operator
   EcBaseScalarFunction& operator=
      (
      const EcBaseScalarFunction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseScalarFunction& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// evaluate the function
   virtual EcReal evaluate
      (
      const EcReal& domainValue
      )const = 0;
};

#endif // ecBaseScalarFunction_H_
