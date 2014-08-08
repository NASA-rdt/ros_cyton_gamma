#ifndef ecScalarFunctionContainer_H_
#define ecScalarFunctionContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecScalarFunctionContainer.h
/// @class EcScalarFunctionContainer
/// @brief A container for a unitary map (a scalar function
///        mapping 0-1 to 0-1).
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecBaseExpTreeContainer.h>
#include <xml/ecXmlPairType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EcBaseScalarFunction;

/** A container for a unitary map (a scalar function mapping 0-1 to 0-1).
*/
class EC_FOUNDATION_FUNCTION_DECL EcScalarFunctionContainer : public EcBaseExpressionTreeContainer<EcBaseScalarFunction>
{
public:
   /// Macro for declaring methods required to make a derived
   /// EcXmlObject concrete.
   ECXMLOBJECT(EcScalarFunctionContainer);
   /// Macro for declaration and definition of xmlObjectCreator()
   ECXML_XMLOBJECTCREATOR(EcScalarFunctionContainer)

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// evaluate the function
   virtual EcReal evaluate
      (
      const EcReal& domainValue
      )const;

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
   static EcScalarFunctionContainer nullObject
      (
      );
};

/// type definition of a vector of vector of constraints using EcScalarFunctionContainer
typedef EcXmlVectorType<
           EcXmlVectorType<
           EcXmlPairType<
           EcXmlPairType<EcXmlU32,EcXmlString>, EcScalarFunctionContainer
        > > > EcXmlConstraintVectorVectorType;

#endif // ecScalarFunctionContainer_H_
