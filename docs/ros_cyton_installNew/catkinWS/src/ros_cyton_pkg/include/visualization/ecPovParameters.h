#ifndef ecPovParameters_H_
#define ecPovParameters_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecPovParameters.h
/// @class EcPovParameters
/// @brief Holds a description of point-of-view parameters for
///        viewing the system, including the eyepoint, the center of interest,
///        and the field of view.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecCoordSysXForm.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVector.h>

/// Holds a description of point-of-view parameters for viewing the system,
/// including the eyepoint, the center of interest, and the field of view.
class EC_FOUNDATION_VISUALIZATION_DECL EcPovParameters : public EcXmlCompoundType
{
public:
   /// default constructor
   EcPovParameters
      (
      );

   /// constructor with values
   EcPovParameters
      (
      const EcVector& eyepoint,
      const EcVector& centerOfInterest,
      EcReal fieldOfView,
      const EcVector& up
      );

   /// destructor
   virtual ~EcPovParameters
      (
      );

   /// copy constructor
   EcPovParameters
      (
      const EcPovParameters& orig
      );

   /// assignment operator
   EcPovParameters& operator=
      (
      const EcPovParameters& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPovParameters& orig
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

   /// gets the eyepoint
   virtual const EcVector& eyepoint
      (
      ) const;

   /// sets the eye point
   virtual void setEyepoint
      (
      const EcVector& eyepoint
      );

   /// gets the up direction
   virtual const EcVector& up
      (
      ) const;

   /// sets the up direction
   virtual void setUp
      (
      const EcVector& up
      );

   /// gets the center of interest
   virtual const EcVector& centerOfInterest
      (
      ) const;

   /// sets the center of interest
   virtual void setCenterOfInterest
      (
      const EcVector& centerOfInterest
      );

   /// gets the field of view
   virtual EcReal fieldOfView
      (
      ) const;

   /// sets the field of view
   virtual void setFieldOfView
      (
      EcReal fieldOfView
      );

   /// calculate the view transformation.  This is the frame
   /// located at the eyepoint, with x toward the COI and y up.
   virtual EcCoordinateSystemTransformation viewTransformation
      (
      ) const;

   /// calculate the view distance.  This is the distance from
   /// the eyepoint to the center of interest
   virtual EcReal viewDistance
      (
      ) const;

   /// set the configuration from a view transformation and a
   /// distance
   virtual void setFromViewTransformationAndDistance
      (
      const EcCoordinateSystemTransformation& viewTransformation,
      const EcReal distance
      );

   /// Update the eyepoint (or COI) based on their distance.
   virtual void addDistanceFactor
      (
      const EcReal distance,
      const EcBoolean moveEyepoint = EcTrue
      );

   /// the xml class token
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
   static EcPovParameters nullObject
      (
      );

protected:

   /// the location of the eye viewing the scene
   EcXmlVector          m_Eyepoint;

   /// the center of interest (center of the rendered scene)
   EcXmlVector          m_CenterOfInterest;

   /// the field of view (diameter, in radians)
   EcXmlReal            m_FieldOfView;

   /// up direction for the view
   EcXmlVector          m_Up;
};

/// A vector of visualization parameters
typedef EcXmlVectorType<EcPovParameters>
   EcPovParametersVector;

#endif // ecPovParameters_H_
