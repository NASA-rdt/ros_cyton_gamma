#ifndef ecCompositeFunctionBranch_H_
#define ecCompositeFunctionBranch_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecCompositeFunctionBranch.h
/// @class EcCompositeFunctionBranch
/// @brief Branch provider for table functions
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecCompositeFunctionElement.h"

class EcCompositeFunctionContainer;

/// Branch provider for table functions
/**
   Contains left and right pointer to EcCompositeFunctionElement
   which can be a table function interpolator or branch
*/
class EC_FOUNDATION_FUNCTION_DECL EcCompositeFunctionBranch : public EcCompositeFunctionElement
{
public:
   /// default constructor
   EcCompositeFunctionBranch
      (
      );

   /// constructor given a container pointer
   explicit EcCompositeFunctionBranch
      (
      const EcCompositeFunctionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcCompositeFunctionBranch
      (
      );

   /// copy constructor
   EcCompositeFunctionBranch
      (
      const EcCompositeFunctionBranch& orig
      );

   /// assignment operator
   EcCompositeFunctionBranch& operator=
      (
      const EcCompositeFunctionBranch& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCompositeFunctionBranch& orig
      ) const;

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

   /// sets the container
   virtual void setContainer
      (
      const EcXmlBaseVariableCompoundType* container
      );

   /// gets a pointer to the left expression
   virtual const EcCompositeFunctionElement* left
      (
      ) const;

   /// sets the left expression through a copy
   virtual void setLeft
      (
      const EcCompositeFunctionElement& left
      );

   /// gets a pointer to the right expression
   virtual const EcCompositeFunctionElement* right
      (
      ) const;

   /// sets the right expression through a copy
   virtual void setRight
      (
      const EcCompositeFunctionElement& right
      );

   /// return a string token
   virtual const EcToken& token
      (
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

   /// write object schema to an XML stream
   virtual EcBoolean writeSchema
      (
      EcXmlSchema& stream
      ) const;

   /// read value from unregistered token
   virtual EcBoolean readValueFromSpecialToken
      (
      const EcToken& token,
      EcXmlReader& stream
      );

   /// Evaluate table function
   /**
       Get interpolated value from table function
       \param vInput Independent data state
       \param lookedUp Flag indicating evaluation performed
       \retval Result of evaluation
   */
   virtual const EcRealVector& evaluate
      (
      const EcRealVector& vInput,
      EcBoolean& lookedUp
      ) const;

   /// Initializae bounds of independent data
   /**
       \retval Vector of min/max dimension bounds
   */
   virtual const EcRealVectorVector& initBounds
      (
      );

   /// Initialize boundary methods for independent data
   /**
       Initialization method used to evaluate requests of out of bounds data
       \retval Vector of min/max boundary methods
   */
   virtual const EcBooleanVectorVector& initLimitOrExtrapolate
      (
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// left table function branch
   EcCompositeFunctionElement* m_pLeft;

   /// right table function branch
   EcCompositeFunctionElement* m_pRight;

   /// evaluation result
   mutable EcRealVector m_vResult;
};

#endif // ecCompositeFunctionBranch_H_
