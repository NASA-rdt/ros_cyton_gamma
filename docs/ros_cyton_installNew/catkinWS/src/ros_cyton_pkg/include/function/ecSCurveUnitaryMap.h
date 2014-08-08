#ifndef ecSCurveUnitaryMap_H_
#define ecSCurveUnitaryMap_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecSCurveUnitaryMap.h
/// @class EcSCurveUnitaryMap
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
#include "ecBaseUnitaryMap.h"

/** Holds a description of a unitary map that is shaped like an
    s-curve.  It uses two pieces of rational polynomials.  The
    form used for each of the two pieces is

        a0 x^2 + a1 x
    f = -------------
            (b-x)
*/
class EC_FOUNDATION_FUNCTION_DECL EcSCurveUnitaryMap : public EcBaseUnitaryMap
{
public:
   /// default constructor
   EcSCurveUnitaryMap
      (
      );

   /// destructor
   virtual ~EcSCurveUnitaryMap
      (
      );

   /// copy constructor
   EcSCurveUnitaryMap
      (
      const EcSCurveUnitaryMap& orig
      );

   /// assignment operator
   EcSCurveUnitaryMap& operator=
      (
      const EcSCurveUnitaryMap& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSCurveUnitaryMap& orig
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

   /// get center domain value
   virtual EcReal center
      (
      ) const;

   /// set center domain value
   virtual void setCenter
      (
      EcReal center
      );

   /// get initial slope
   virtual EcReal initialSlope
      (
      ) const;

   /// set initial slope
   virtual void setInitialSlope
      (
      EcReal initialSlope
      );

   /// get final slope
   virtual EcReal finalSlope
      (
      ) const;

   /// set final slope
   virtual void setFinalSlope
      (
      EcReal finalSlope
      );

   /// get center slope
   virtual EcReal centerSlope
      (
      ) const;

   /// set center slope
   virtual void setCenterSlope
      (
      EcReal centerSlope
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
   static EcSCurveUnitaryMap nullObject
      (
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcBaseUnitaryMap* creator
      (
      );

   /// static creator function to an xml object pointer
   static EcXmlObject* xmlObjectCreator
      (
      );

protected:

   /// calculate the function coefficients
   virtual void calculateCoefficients
      (
      );

   /// the center point of the s-curve:  f(center)=0.5
   /// should be between zero and one
   EcXmlReal                      m_Center;

   /// the initial slope of the s-curve
   /// should be less than 1/(2c)--if not, will be adjusted
   EcXmlReal                      m_InitialSlope;

   /// the final slope of the s-curve
   /// should be less than 1/(2-2c)--if not, will be adjusted
   EcXmlReal                      m_FinalSlope;

   /// the slope of the s-curve at the center value
   /// should be greater than Max(1/c-initialSlope,1/(1-c)-finalSlope
   /// if not, will be adjusted
   EcXmlReal                      m_CenterSlope;

   // nonXML values below

   // values defining (A0 x^2 + A1 x)/(B-x) for the left-half of the
   // s-curve.
   EcReal                         m_LeftA0;  ///< The A0 value of the left-half of the s-curve
   EcReal                         m_LeftA1;  ///< The A1 value of the left-half of the s-curve
   EcReal                         m_LeftB;   ///< The B value of the left-half of the s-curve

   // values defining 1-(A0 (1-x)^2 + A1 (1-x))/(B-(1-x)) for the
   // right-half of the s-curve.
   EcReal                         m_RightA0; ///< The A0 value of the right-half of the s-curve
   EcReal                         m_RightA1; ///< The A1 value of the right-half of the s-curve
   EcReal                         m_RightB;  ///< The B value of the right-half of the s-curve
};

#endif // ecSCurveUnitaryMap_H_
