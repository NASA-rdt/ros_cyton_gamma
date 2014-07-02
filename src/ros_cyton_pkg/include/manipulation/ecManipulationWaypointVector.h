#ifndef ecManipulationWaypointVector_H_
#define ecManipulationWaypointVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationWaypointVector.h
/// @class EcManipulationWaypointVector
/// @brief Holds a description of a vector of waypoints.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationWaypoint.h"
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlVectorType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// type definition of EcBaseManipulationWaypointVector
typedef EcXmlVectorType<EcManipulationWaypoint> EcBaseManipulationWaypointVector;

/// Holds a description of a vector of waypoints.
class EC_ACTIN_MANIPULATION_DECL EcManipulationWaypointVector : public EcBaseManipulationWaypointVector
{
public:
   /// default constructor
   EcManipulationWaypointVector
      (
      );

   /// destructor
   virtual ~EcManipulationWaypointVector
      (
      );

   /// copy constructor
   EcManipulationWaypointVector
      (
      const EcManipulationWaypointVector& orig
      );

   /// assignment operator
   EcManipulationWaypointVector& operator=
      (
      const EcManipulationWaypointVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationWaypointVector& orig
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

   /// register components with the parent
   virtual void registerComponents
      (
      );
};

#endif // ecManipulationWaypointVector_H_
