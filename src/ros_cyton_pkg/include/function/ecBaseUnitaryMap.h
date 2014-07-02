#ifndef ecBaseUnitaryMap_H_
#define ecBaseUnitaryMap_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseUnitaryMap.h
/// @class EcBaseUnitaryMap
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
 one-to-one maps the range 0-1 to the domain 0-1.  It represents
 a scalar function that must be monotonically increasing.
*/
class EC_FOUNDATION_FUNCTION_DECL EcBaseUnitaryMap : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcBaseUnitaryMap
      (
      );

   /// destructor
   virtual ~EcBaseUnitaryMap
      (
      );

   /// copy constructor
   EcBaseUnitaryMap
      (
      const EcBaseUnitaryMap& orig
      );

   /// assignment operator
   EcBaseUnitaryMap& operator=
      (
      const EcBaseUnitaryMap& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseUnitaryMap& orig
      ) const;

   /// evaluate the function
   virtual EcReal evaluate
      (
      const EcReal& domainValue
      )const = 0;
};

#endif // ecBaseUnitaryMap_H_
