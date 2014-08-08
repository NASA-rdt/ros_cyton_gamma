#ifndef ecSoftConstraintHandlerContainer_H_
#define ecSoftConstraintHandlerContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecSoftConstraintHandlerContainer.h
/// @class EcSoftConstraintHandlerContainer
/// @brief Holds a container for a soft-constraint handler.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecBaseExpTreeContainer.h>
#include <xml/ecXmlVectorType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EcReArray;
class EcControlExpressionContainer;
class EcBaseSoftConstraintHandler;

/** Holds a container for a soft-constraint handler.
*/
class EC_ACTIN_CONTROL_DECL EcSoftConstraintHandlerContainer : public EcBaseExpressionTreeContainer<EcBaseSoftConstraintHandler>
{
public:
   /// default constructor
   EcSoftConstraintHandlerContainer
      (
      );

   /// destructor
   virtual ~EcSoftConstraintHandlerContainer
      (
      );

   /// copy constructor
   EcSoftConstraintHandlerContainer
      (
      const EcSoftConstraintHandlerContainer& orig
      );

   /// assignment operator
   EcSoftConstraintHandlerContainer& operator=
      (
      const EcSoftConstraintHandlerContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSoftConstraintHandlerContainer& orig
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

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// take the input values and integrate soft-constraint optimization
   /// this method is for use with the primary core
   virtual void integrateSoftConstraints
      (
      const EcReArray& matrixIn,
      const EcReArray& vectorIn,
      const EcReArray& scalarIn,
      const EcControlExpressionContainer* pContainerIn,
      const EcReArray*& pMatrixOut,
      const EcReArray*& pVectorOut,
      const EcReArray*& pScalarOut
      ) const;

   /// take the input values and integrate soft-constraint optimization
   /// this method is for use with the AB core.
   virtual void integrateSoftConstraintsAB
      (
      const EcReArray& matrixIn,
      const EcReArray& vectorIn,
      const EcReArray& scalarIn,
      const EcControlExpressionContainer* pContainerIn,
      const EcReArray*& pMatrixOut,
      const EcReArray*& pVectorOut,
      const EcReArray*& pScalarOut
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
   static EcSoftConstraintHandlerContainer nullObject
      (
      );

   /// get a default object
   static EcSoftConstraintHandlerContainer defaultObject
      (
      );
};

/// type definition of XML vector of EcSoftConstraintHandlerContainer
typedef EcXmlVectorType<EcSoftConstraintHandlerContainer>
   EcSoftConstraintHandlerContainerVector;

#endif // ecSoftConstraintHandlerContainer_H_
