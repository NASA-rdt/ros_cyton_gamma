#ifndef ecBaseMotionFilter_H_
#define ecBaseMotionFilter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseMotionFilter.h
/// @class EcBaseMotionFilter
/// @brief Holds a description of a scalar-motion filter system.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlEnumType.h>

/// Filter for motion of the base of the robot TODO
class EC_ACTIN_CONTROL_DECL EcBaseMotionFilter : public EcXmlCompoundType
{
public:
   /// enumerations for the filtering mode
   enum
   {
      PROPORTIONAL=0,
      TRAPEZOIDAL=1,
      THREEHALVES=2
   };

   /// default constructor
   EcBaseMotionFilter
      (
      );

   /// destructor
   virtual ~EcBaseMotionFilter
      (
      );

   /// copy constructor
   EcBaseMotionFilter
      (
      const EcBaseMotionFilter& orig
      );

   /// assignment operator
   EcBaseMotionFilter& operator=
      (
      const EcBaseMotionFilter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseMotionFilter& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets the filtering mode
   /// @return The filtering method
   virtual EcU32 filteringMode
      (
      ) const;

   /// sets the filtering mode
   /// @param[in] filteringMode   (EcU32) value to set
   virtual void setFilteringMode
      (
      EcU32 filteringMode
      );

   /// gets the exponent
   /// @return (EcReal) The exponent value
   virtual EcReal exponent
      (
      ) const;

   /// sets the exponent
   /// @param[in] exponent   (EcReal) value to set, (Must be between 0 and 1 inclusive)
   virtual void setExponent
      (
      EcReal exponent
      );

   /// get the speed factor. This factor is multiplied with the velocity and acceleration/deceleration thresholds, thus allowing the end-effector speed to be adjusted at run-time.
   /// @return (EcReal) The speed factor
   virtual EcReal speedFactor
      (
      ) const;

   /// set the speed factor. Must be positive.
   /// param[in] value   (EcReal) value to set
   virtual void setSpeedFactor
      (
      EcReal value
      );

   /// returns whether filtering is active. If it is, then the velocity will be filtered according to the filtering mode. If not,
   /// then the velocity will be computed such that the returned velocity will result in the goal is accomplished in one step.
   virtual EcBoolean filteringActive
      (
      ) const;

   /// returns whether filtering is active.
   virtual void setFilteringActive
      (
      EcBoolean value
      );

protected:
   /// the filtering mode
   EcXmlEnumU32         m_FilteringMode;
   /// the exponent
   EcXmlReal            m_Exponent;

   // non-XML data
   /// the speed factor
   EcReal               m_SpeedFactor;

   /// Flag indicating whether filtering is actvie
   EcBoolean            m_FilteringActive;
};

#endif // ecBaseMotionFilter_H_
