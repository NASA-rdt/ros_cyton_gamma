#ifndef ecIntervalEndPoint_H_
#define ecIntervalEndPoint_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecIntervalEndPoint.h
/// @class EcIntervalEndPoint
/// @brief Defines an endpoint for an interval.  Used for interval
///        testing for collision detection.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

/// Defines an endpoint for an interval.  Used for interval testing for collision detection.
class EC_FOUNDATION_GEOMETRY_DECL EcIntervalEndPoint
{
public:
   /// default CSTR
   EcIntervalEndPoint
      (
      );

   /// CSTR
   EcIntervalEndPoint
      (
         EcU32 index,
         EcReal value,
         EcU32  type
      );

   /// DSTR
   virtual ~EcIntervalEndPoint
      (
      );

   /// copy CSTR
   EcIntervalEndPoint
      (
      const EcIntervalEndPoint& other
      );

   /// assignment
   EcIntervalEndPoint& operator=
      (
      const EcIntervalEndPoint& other
      );

   /// equality
   EcBoolean operator==
      (
      const EcIntervalEndPoint& other
      )const;

   /// support for sorting of end points
   EcBoolean operator<
      (
      const EcIntervalEndPoint& ep
      ) const;

   /// set the value of the interval
   virtual void setValue
      (
      EcReal value
      );

   /// set the index in the array of this interval
   virtual void setIndex
      (
      EcU32 index
      );

   /// set the type of the interval
   /// '0' if interval min, '1' if interval max
   virtual void setType
      (
      EcU32 type
      );

   /// get value
   virtual const EcReal& value
      (
      ) const;

   /// get type
   virtual const EcU32&  type
      (
      )  const;


   /// get index
   virtual const EcU32&  index
      (
      ) const;

   /// returns a null object for this class
   static EcIntervalEndPoint nullObject
      (
      );

protected:
   /// the value of the interval endpoint
   EcReal m_Value;
   /// type of interval
   /// '0' if interval min, '1' if interval max
   EcU32 m_Type;
   /// index of interval containing this end point
   EcU32 m_Index;
  };

#endif // ecIntervalEndPoint_H_
