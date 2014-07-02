#ifndef ecCompositeFunctionContainer_H_
#define ecCompositeFunctionContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecCompositeFunctionContainer.h
/// @class EcCompositeFunctionContainer
/// @brief Container class for table functions
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecBaseExpTreeContainer.h>
#include "ecCompositeFunctionElement.h"

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// Container for table function tree expression
class EC_FOUNDATION_FUNCTION_DECL EcCompositeFunctionContainer :
   public EcBaseExpressionTreeContainer<EcCompositeFunctionElement>
{
public:
   /// default constructor
   EcCompositeFunctionContainer
      (
      );

   /// destructor
   virtual ~EcCompositeFunctionContainer
      (
      );

   /// copy constructor
   EcCompositeFunctionContainer
      (
      const EcCompositeFunctionContainer& orig
      );

   /// assignment operator
   EcCompositeFunctionContainer& operator=
      (
      const EcCompositeFunctionContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCompositeFunctionContainer& orig
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

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

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

   /// set top element
   virtual void setTopElement
      (
      const EcCompositeFunctionElement& topElement
      );

   /// set the container pointer for the top element to this
   virtual void setTopElementContainerToThis
      (
      );

   /// perform an interpolation
   virtual void evaluate
      (
      const EcRealVector& vInput,
      EcRealVector& vOutput,
      EcBoolean& status
      ) const;

   /// Get bounds of independent data
   /**
       \retval Vector of min/max dimension bounds
   */
   virtual const EcRealVectorVector& bounds
      (
      ) const;

   /// null object
   static EcCompositeFunctionContainer nullObject
      (
      );

protected:
   /// interpolation boundaries
   EcRealVectorVector m_Bounds;
};

#endif // ecCompositeFunctionContainer_H_
