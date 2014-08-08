#ifndef ecVelContData_H_
#define ecVelContData_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecVelContData.h
/// @class EcVelocityControlData
/// @brief combines joint rates with extra data.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <matrixUtilities/ecReArray.h>
#include <xml/ecXmlVectorType.h>

// XXX FIXME:
namespace Ec { namespace test { class EcVelocityControlDataTester; } }

/// Joint rates with extra data, all of which is used as the result of a control expression.
class EC_ACTIN_CONTROL_DECL EcVelocityControlData : public EcReArray
{
public:
   /// default constructor
   EcVelocityControlData
      (
      );

   /// destructor
   virtual ~EcVelocityControlData
      (
      );

   /// copy constructor
   EcVelocityControlData
      (
      const EcVelocityControlData& orig
      );

   /// assignment operator
   EcVelocityControlData& operator=
      (
      const EcVelocityControlData& orig
      );

   /// assignment operator for EcReArray
   EcVelocityControlData& operator=
      (
      const EcReArray& orig
      );

   /// assignment operator from EcXmlRealVectorVector
   EcVelocityControlData& operator=
     (
      const EcXmlRealVectorVector& orig
      );

   /// assignment from a vector representing a single column
   EcVelocityControlData& operator=
      (
      const EcRealVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcVelocityControlData& other
      ) const;

   /// set function for the primary matrix determinant
   virtual void setPrimaryDeterminant
      (
      const EcReal& det
      );

   /// get function for the primary matrix determinant
   virtual EcReal primaryDeterminant
      (
      ) const;

   /// get an identity transformation
   static EcVelocityControlData nullObject
      (
      );

protected:
   // XXX FIXME:
   friend class Ec::test::EcVelocityControlDataTester;

   EcXmlReal    m_PrimaryDeterminant;        ///< the primary determinant
   EcXmlBoolean m_PrimaryDeterminantValid;   ///< flag indicating whether the primary determinant is valid
};

#endif // ecVelContData_H_
