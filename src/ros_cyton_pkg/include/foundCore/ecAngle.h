#ifndef ecAngle_H_
#define ecAngle_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecAngle.h
/// @class EcAngle
/// @brief A class to define an angle, with values in the range [-Pi, Pi].
/// @details This class holds a representation of an angle.  It maintains the
///          value in the range -Pi to Pi, and also stores the sine and
///          cosine of the angle for fast access.
//
//------------------------------------------------------------------------------
#include "ecConfig.h"  // Required to be first header.
#include "ecTypes.h"

class EC_STABLE_FOUNDCORE_DECL EcAngle
{
public:
   /// constructor
   EcAngle
      (
      );

   /// constructor from a real angle value (implicit conversion okay)
   EcAngle
      (
      const EcReal& val
      );

   /// destructor
   virtual ~EcAngle
      (
      );

   /// copy constructor
   EcAngle
      (
      const EcAngle& orig
      );

   /// assignment operator
   EcAngle& operator=
      (
      const EcAngle& orig
      );

   /// assignment operator from a real
   EcAngle& operator=
      (
      const EcReal& orig
      );

   /// opertor== checks for equality between two angles
   EcBoolean operator==
      (
      const EcAngle& orig
      ) const;

   /// cast to an EcReal
   operator const EcReal
      (
      ) const;

   /// operator+= adds a value to the angle
   EcAngle& operator +=
      (
      const EcAngle& a2
      );

   /// operator-= subtracts a value from the angle
   EcAngle& operator -=
      (
      const EcAngle& a2
      );

   /// operator*= scales the angle
   EcAngle& operator *=
      (
      const EcReal& a2
      );

   /// operator+ finds the sum of this angle plus another
   EcAngle operator+
      (
      const EcAngle& a2
      ) const;

   /// operator- finds the difference between this angle and another
   EcAngle operator-
      (
      const EcAngle& a2
      ) const;

   /// clone
   virtual EcAngle* clone
      (
      ) const;

   /// get the angle as a real value
   virtual const EcReal& angle
      (
      ) const;

   /// set the angle from a real value, forced into the range [-Pi, Pi]
   virtual void setAngle
      (
      const EcReal& val
      );

   /// get sine of the angle
   virtual const EcReal& sin
      (
      ) const;

   /// get cosine of the angle
   virtual const EcReal& cos
      (
      ) const;

   /// set the angle through its sine and cosine values
   virtual void  setSinCos
      (
      const EcReal& sin,
      const EcReal& cos
      );

   /// formalize an angle to the range (-Pi,Pi]
   static EcReal formalize
      (
      const EcReal& angle
      );

protected:
   /// the angle value
   EcReal m_Angle;

   /// the sine of the angle
   EcReal m_Sin;

   /// the cosine of the angle
   EcReal m_Cos;
};

/// read in from any stream
inline EC_STABLE_FOUNDCORE_DECL std::ostream& operator<<(std::ostream& stream, const EcAngle& angle)
{
   stream<<angle.angle();
   return stream;
}

/// write out to any stream
inline EC_STABLE_FOUNDCORE_DECL std::istream& operator>>
   (
   	std::istream& stream,
   	EcAngle& angle
   	)
{
   EcReal value;
   stream >> value;
   angle.setAngle(value);

   return stream;
}

#endif // ecAngle_H_
