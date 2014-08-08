#ifndef ecNonnegReal_H_
#define ecNonnegReal_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecNonnegReal.h
/// @class EcNonNegReal
/// @brief A nonnegative floating-point number
/// @details Holds a representation of a nonnegative real number.
///          It provides utilities for working with nonnegative real numbers.
/// @todo Remove this class.
//
//------------------------------------------------------------------------------
#include "ecConfig.h"  // Required to be first header.
#include "ecTypes.h"

class EC_STABLE_FOUNDCORE_DECL EcNonNegReal
{
public:
   /// constructor
   EcNonNegReal
      (
      );

   /// constructor from a real (implicit conversion okay)
   EcNonNegReal
      (
      EcReal val
      );

   /// destructor
   ~EcNonNegReal
      (
      );

   /// copy constructor
   EcNonNegReal
      (
      const EcNonNegReal& orig
      );

   /// assignment operator
   EcNonNegReal& operator=
      (
      const EcNonNegReal& orig
      );

   /// assignment operator from a real
   /// no check for positivity
   EcNonNegReal& operator=
      (
      const EcReal& orig
      )
   {
      m_Value=orig;
      return *this;
   }

   /// equality operator
   EcBoolean operator==
      (
      const EcNonNegReal& orig
      ) const;

   /// cast to an EcReal
   operator const EcReal
      (
      ) const;

   /// adds another value to this one and set this value to the result
   EcNonNegReal& operator +=
      (
      const EcNonNegReal& a2
      );

   /// subtracts another value from this one and set this value to the result
   EcNonNegReal& operator -=
      (
      const EcNonNegReal& a2
      );

   /// multiplies this value by a scalar and set this value to the result
   EcNonNegReal& operator *=
      (
      const EcReal& a2
      );

   /// adds this to another value
   EcNonNegReal operator+
      (
      const EcNonNegReal& a2
      ) const;

   /// subtracts another value from this one.
   EcNonNegReal operator-
      (
      const EcNonNegReal& a2
      ) const;

   /// clone - virtual constructor
   EcNonNegReal* clone
      (
      ) const;

   /// get the floating-point representation
   inline const EcReal& value
      (
      ) const
   {
      return m_Value;
   }

   /// set the floating-point representation
   /// checks for positivity
   inline void setValue
      (
      const EcReal& val
      )
   {
      m_Value=val>0.0?val:0.0;
   }

protected:
   /// internal floating-point representation
   EcReal m_Value;
};


/// reads in from a stream
inline EC_STABLE_FOUNDCORE_DECL std::ostream& operator<<(std::ostream& stream, const EcNonNegReal& val)
{
   stream << val.value();
   return stream;
}

/// writes out to a stream
inline EC_STABLE_FOUNDCORE_DECL std::istream& operator>>(std::istream& stream, EcNonNegReal& val)
{
   EcReal value;
   stream >> value;
   val.setValue(value);

   return stream;
}

#endif // ecNonnegReal_H_
