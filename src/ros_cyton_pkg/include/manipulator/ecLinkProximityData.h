#ifndef ecLinkProximityData_H_
#define ecLinkProximityData_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkProximityData.h
/// @class EcLinkProximityData
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecVector.h>

/// Holds a class to describe a link proximity related data
class EC_FOUNDATION_MANIPULATOR_DECL EcLinkProximityData
{
public:
   /// default constructor
   EcLinkProximityData
      (
      );

   /// destructor
   virtual ~EcLinkProximityData
      (
      );

   /// the distance to the object
   virtual EcReal distance
      (
      ) const;

   /// set the distance to the object
   virtual void setDistance
      (
      EcReal dist
      );

   /// set the update time for link1
   virtual void setUpdateTime1
      (
      EcU32 uTime
      );

   /// get the update time for link1
   virtual EcU32 updateTime1
      (
      ) const;

   /// set the update time for link2
   virtual void setUpdateTime2
      (
      EcU32 uTime
      );

   /// get the update time for link2
   virtual EcU32 updateTime2
      (
      ) const;

protected:
   /// distance to shape
   EcReal   m_Distance;

   //-------used internally----------

   /// the time of the last update for link1
   EcU32    m_LastUpdateTime1;
   /// the time of the last update for link2
   EcU32    m_LastUpdateTime2;
};

#endif // ecLinkProximityData_H_
