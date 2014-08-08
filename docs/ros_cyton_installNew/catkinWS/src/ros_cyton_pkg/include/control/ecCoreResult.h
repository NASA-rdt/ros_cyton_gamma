#ifndef ecCoreResult_H_
#define ecCoreResult_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecCoreResult.h
/// @class EcCoreResult
/// @brief Holds a description of the result of the execution of
///        the core velocity control algorithm (either regular or AB).
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

// forward declarations
class EcReArray;

/// Holds a description of the result of the execution of the core velocity control algorithm (either regular or AB).
class EC_ACTIN_CONTROL_DECL EcCoreResult : public EcXmlCompoundType
{
public:
   /// default constructor
   EcCoreResult
      (
      );

   /// destructor
   virtual ~EcCoreResult
      (
      );

   /// copy constructor
   EcCoreResult
      (
      const EcCoreResult& orig
      );

   /// assignment operator
   EcCoreResult& operator=
      (
      const EcCoreResult& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCoreResult& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

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

   /// get base component
   virtual const EcXmlRealVector& baseComponent
      (
      ) const;

   /// set base component
   virtual void setBaseComponent
      (
      const EcXmlRealVector& baseComponent
      );

   /// get null-space component
   /// (this value may be identically zero)
   virtual const EcXmlRealVector& nullSpaceComponent
      (
      ) const;

   /// set null-space component
   /// (this value may be identically zero)
   virtual void setNullSpaceComponent
      (
      const EcXmlRealVector& nullSpaceComponent
      );

   /// set the joint-rate components from the total and the null
   virtual void setComponentsFromTotalAndNull
      (
      const EcRealVector& totalJointRateSolution,
      const EcRealVector& nullSpaceComponent
      );

   /// get the components
   virtual void getComponents
      (
      EcRealVector& baseComponent,
      EcRealVector& nullSpaceComponent
      ) const;

   /// get the determinant of the primary matrix
   virtual EcReal primaryDeterminant
      (
      ) const;

   /// set the determinant of the primary matrix
   virtual void setPrimaryDeterminant
      (
      EcReal primaryDeterminant
      );

   /// returns true if the null-space component is zero
   virtual EcBoolean isNullSpaceComponentZero
      (
      ) const;

   /// get the cooordinates in component space of a column vector
   virtual EcBoolean getComponentCoordinates
      (
      const EcReArray& jointRates,
      EcReal& baseCoordinate,
      EcReal& nullCoordinate
      ) const;

   /// @copydoc EcXmlObject::token()
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

   /// get a null object
   static EcCoreResult nullObject
      (
      );

protected:
   /// the base component.  This will give the desired end-effector velocity
   EcXmlRealVector m_BaseComponent;

   /// the null-space component.  This alone will give no motion of the end-effector
   EcXmlRealVector m_NullSpaceComponent;

   /// the determinant of the primary matrix
   EcXmlReal       m_PrimaryDeterminant;
};

#endif // ecCoreResult_H_
