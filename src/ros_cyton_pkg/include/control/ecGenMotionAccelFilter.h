#ifndef ecGenMotionAccelFilter_H_
#define ecGenMotionAccelFilter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGenMotionAccelFilter.h
/// @class EcGeneralMotionAccFilter
/// @brief Holds a description of a general-motion filter system.  Given
///        an existing frame, a desired frame, a desired frame (or point)
///        acceleration, what is the best overall general acceleration (or point
///        acceleration).  This uses proportional scaling with capping.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <foundCore/ecVector.h>
#include <foundCommon/ecCoordSysXForm.h>
#include <foundCommon/ecGeneralMotion.h>
#include <xml/ecXmlCompType.h>

/// Holds a description of a general-motion filter system.
/** Given an existing frame, a desired frame, a desired frame (or point)
 acceleration, what is the best overall general acceleration (or point
 acceleration).  This uses proportional scaling with capping.
*/
class EC_ACTIN_CONTROL_DECL EcGeneralMotionAccFilter : public EcXmlCompoundType
{
public:
   /// default constructor
   EcGeneralMotionAccFilter
      (
      );

   /// destructor
   virtual ~EcGeneralMotionAccFilter
      (
      );

   /// copy constructor
   EcGeneralMotionAccFilter
      (
      const EcGeneralMotionAccFilter& orig
      );

   /// assignment operator
   EcGeneralMotionAccFilter& operator=
      (
      const EcGeneralMotionAccFilter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGeneralMotionAccFilter& orig
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

   /// gets the offset
   virtual const EcVector& offset
      (
      ) const;

   /// sets the offset
   virtual void setOffset
      (
      const EcVector& offset
      );

   /// gets the angular weight
   virtual EcReal angularWeight
      (
      ) const;

   /// sets the angular weight
   virtual void setAngularWeight
      (
      EcReal angularWeight
      );

   /// gets the threshold
   virtual EcReal threshold
      (
      ) const;

   /// sets the threshold
   virtual void setThreshold
      (
      EcReal threshold
      );

   /// gets the threshold
   virtual EcReal linearGain
      (
      ) const;

   /// sets the threshold
   virtual void setLinearGain
      (
      EcReal linearGain
      );

   /// gets the angular gain
   virtual EcReal angularGain
      (
      ) const;

   /// sets the angular gain
   virtual void setAngularGain
      (
      EcReal angularGain
      );

   /// calculate a general motion that will make a tradeoff
   /// between driving the first frame to the second and achieving
   /// the desired general motion.
   virtual EcBoolean calculateGeneralAccMotion
      (
      const EcCoordinateSystemTransformation& from,
      const EcCoordinateSystemTransformation& to,
      const EcGeneralAcceleration& desiredAcceleration,
      EcReal timeStep,
      EcGeneralAcceleration& filteredAcceleration
      ) const;


   /// calculate a three-dimensional acceleration that will make a tradeoff
   /// between driving the first point to the second and achieving
   /// the desired acceleration.
   virtual EcBoolean calculateAcceleration
      (
      const EcVector& from,
      const EcVector& to,
      const EcVector& desiredAcceleration,
      EcReal timeStep,
      EcVector& filteredAcceleration
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
   static EcGeneralMotionAccFilter nullObject
      (
      );

protected:

   /// an offset vector.  This point in one frame will move
   /// directly toward the same point in another frame.
   EcXmlVector                        m_Offset;

   /// a weight for the angular acceleration, used in assessing
   /// threshold exceedance.
   EcXmlReal                          m_AngularWeight;

   /// a not-to-exceed threshold.  The function of the difference
   /// between the returned and the desired general acceleration,
   /// Sqrt[vd.vd + m_AngularWeight^2*wd.wd], will not exceed this.
   EcXmlReal                          m_Threshold;

   /// a linear gain factor.  The linear acceleration, when there
   /// is no explicit desired acceleration and it doesn't exceed
   /// the threshold will be a=gain*offset.
   EcXmlReal                          m_LinearGain;

   /// an angular gain factor.  The angular acceleration, when there
   /// is no explicit desired acceleration and it doesn't exceed
   /// the threshold will be a=gain*offset.
   EcXmlReal                          m_AngularGain;

   /// the cosine threshold.  When cos(theta) is larger than this,
   /// sin(theta) is assumed to be approximately equal to theta
   static const EcReal                m_theCosThreshold;
};

/// a vector of individual acceleration control descriptions
typedef EcXmlVectorType<EcGeneralMotionAccFilter>
   EcGeneralMotionAccFilterVector;

#endif // ecGenMotionAccelFilter_H_
