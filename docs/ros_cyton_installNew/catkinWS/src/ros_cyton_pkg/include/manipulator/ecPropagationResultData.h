#ifndef ecPropagationResultData_H_
#define ecPropagationResultData_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecPropagationResultData.h
/// @class EcPropagationResultData
/// @brief Holds a class to describe the results of a
///        single-manipulator propagation.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

/// Holds a class to describe the results of a manipulator propagation.
class EC_FOUNDATION_MANIPULATOR_DECL EcPropagationResultData : public EcXmlCompoundType
{
public:
   /// default constructor
   EcPropagationResultData
      (
      );

   /// destructor
   virtual ~EcPropagationResultData
      (
      );

   /// copy constructor
   EcPropagationResultData
      (
      const EcPropagationResultData& orig
      );

   /// assignment operator
   EcPropagationResultData& operator=
      (
      const EcPropagationResultData& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPropagationResultData& orig
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

   /// return true if one or more exceptions (joint limit, singularity, collision, etc.) occurred
   virtual EcBoolean exceptionOccurred
      (
      ) const;

   /// get the hit-joint-limit flag
   virtual EcBoolean hitJointLimit
      (
      ) const;

   /// set the hit-joint-limit flag
   virtual void setHitJointLimit
      (
      EcBoolean hitJointLimit = EcTrue
      );

   /// get the hit-singularity (algorithmic) flag
   virtual EcBoolean hitSingularity
      (
      ) const;

   /// set the hit-singularity (algorithmic) flag
   virtual void setHitSingularity
      (
      EcBoolean hitSingularity = EcTrue
      );

   /// get the hit-singularity (algorithmic) flag
   virtual EcBoolean hitGeneralStoppingCriterion
      (
      ) const;

   /// set the hit-general-stopping-criterion flag
   virtual void setHitGeneralStoppingCriterion
      (
      EcBoolean hitGeneralStoppingCriterion = EcTrue
      );

   /// get the string of descriptiosn of the satisfied general stopping criteria
   /// If the hitGeneralStoppingCriterion flag is false, this should be empty.
   virtual const EcString& satisfiedGeneralStoppingCriteriaDescription
      (
      ) const;

   /// set the hit-general-stopping-criterion flag
   virtual void setSatisfiedGeneralStoppingCriteriaDescription
      (
      const EcString& satisfiedGeneralStoppingCriteriaDescription
      );

   /// set the collision occured flag
   virtual EcBoolean collisionOccurred
      (
      ) const;

   /// get the collision occured flag
   virtual void setCollisionOccurred
      (
      EcBoolean collisionOccurred = EcTrue
      );

   /// set the link index at joint limit
   virtual void setLinkIndexAtJointLimit
      (
      const EcU32 &value
      );

   /// get the link index at joint limit
   virtual const EcU32& linkIndexAtJointLimit
      (
      )const;

   /// get this manipulator collision index
   virtual EcU32 collidedManipulator
      (
      ) const;

   /// set this manipulator collision index
   virtual void setCollidedManipulator
      (
      EcU32 manipIndex
      );

   /// get this link collision index
   virtual EcU32 collidedLink
      (
      ) const;

   /// set this link collision index
   virtual void setCollidedLink
      (
      EcU32 collisionLink
      );

   /// get the other link collision
   virtual EcU32 otherCollidedLink
      (
      ) const;

   /// set the other link collision index
   virtual void setOtherCollidedLink
      (
      EcU32 collisionLinkIndex
      );

   /// get the other manipulator collision index
   virtual EcU32 otherCollidedManipulator
      (
      ) const;

   /// set the other manipulator collision index
   virtual void setOtherCollidedManipulator
      (
      EcU32 collisionLinkIndex
      );

   /// get closest manipulator id (self)
   virtual EcU32 closestManipulator
      (
      ) const;
   
   /// set closest manipulator id (self)
   virtual void setClosestManipulator
      (
      EcU32 manipIndex
      );

   /// the closest link id (self)
   virtual EcU32 closestLink
      (
      ) const;

   /// set the closest link id (self)
   virtual void setClosestLink
      (
      EcU32 closestLink
      );

   /// get the other closest link
   virtual EcU32 otherClosestLink
      (
      ) const;

   /// set the other closest link index
   virtual void setOtherClosestLink
      (
      EcU32 linkIndex
      );

   /// get the other closest manipulator index
   virtual EcU32 otherClosestManipulator
      (
      ) const;
 
   /// set the other closest manipulator index
   virtual void setOtherClosestManipulator
      (
      EcU32 manipIndex
      );

   /// set the closest distance
   virtual void setClosestDistance
      (
      EcReal dist
      );

   /// get the closest distance
   virtual EcReal closestDistance
      (
      );

   /// add a generic stopping criterion that has been satisfied
   virtual void registerGenericStoppingCriterion
      (
      const EcString& criterionDescription
      );

   /// reset all values
   virtual void reset
      (
      );

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

   /// get an empty polygon
   static EcPropagationResultData nullObject
      (
      );

protected:

   /// flag indicating if a collision occurred
   EcXmlBoolean m_CollisionOccurred;

   /// index indicating this manipulator that collided
   EcXmlU32     m_CollidedManipulator;

   /// index indicating which link on this manipulator that collided
   EcXmlU32     m_CollidedLink;

   /// the link of the other manipulator that collided with this one
   EcXmlU32     m_OtherCollidedLink;

   /// the manipulator that this manipulator collided with
   EcXmlU32     m_OtherCollidedManipulator;

   /// index of this manipulator where the closest distance occurred  
   EcXmlU32     m_ClosestManipulator;

   /// index indicating which link gives the closest distance
   EcXmlU32     m_ClosestLink;

   /// the link of the other manipulator that is closest to this one
   EcXmlU32     m_OtherClosestLink;

   /// the manipulator that this manipulator is closest to
   EcXmlU32     m_OtherClosestManipulator;

   /// the closest distance
   EcXmlReal    m_ClosestDistance;

   /// the link index of the link at a joint limit
   EcXmlU32     m_LinkIndexAtJointLimit;

   /// flag indicating if a joint limit is hit
   EcXmlBoolean m_HitJointLimit;

   /// flag indicating a singularity (agorithmic) was encountered
   EcXmlBoolean m_HitSingularity;

   /// flag indicating that one or more of the generic stopping criteria were satisfied
   EcXmlBoolean m_HitGeneralStoppingCriterion;

   /// string holding description of all satisfied general stopping criteria
   EcXmlString  m_SatisfiedGeneralStoppingCriteriaDescription;

   /// a separator (;) for general stopping criteria
   static const EcString m_theDescriptionSeparator;
};

/// A vector of line segments
typedef EcXmlVectorType<EcPropagationResultData> EcPropagationResultDataVector;

#endif // ecPropagationResultData_H_
