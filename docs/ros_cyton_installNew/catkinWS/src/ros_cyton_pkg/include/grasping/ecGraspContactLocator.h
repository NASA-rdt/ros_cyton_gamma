#ifndef ecGraspContactLocator_H_
#define ecGraspContactLocator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspContactLocator.h
/// @class EcGraspContactLocator
/// @brief Abstract class to compute contact points and normals
/// @todo Multiple classes are defined in this file
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecDistanceCalculationTool.h"
#include "ecGraspContactPointData.h"
#include <manipulator/ecSystemActiveState.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

// Forward declarations
class EcManipulatorSystem;
class EcManipulatorSystemState;
class EcPositionState;

class EC_ACTIN_GRASPING_DECL EcGraspContactLocator : public EcXmlCompoundType
{
public:
   enum {
      DISTAL_ONLY,      //< search contacts through distal links only (finger-tip grasps)
      PROXIMAL_DISTAL   //< search contacts through proximal and distal links (whole-hand grasps)
   };

   /// default constructor
   EcGraspContactLocator
      (
      );

   /// destructor
   virtual ~EcGraspContactLocator
      (
      );

   /// copy constructor
   EcGraspContactLocator
      (
      const EcGraspContactLocator& orig
      );

   /// assignment operator
   EcGraspContactLocator& operator=
      (
      const EcGraspContactLocator& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspContactLocator& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// get the labels of all the fingers' distal links
   virtual const EcXmlStringVector& distalFingerLinks
      (
      ) const;

   /// set the labels of all the fingers' distal links
   virtual void setDistalFingerLinks
      (
      const EcXmlStringVector& labels
      );

   /// get the labels of all the fingers' proximal links
   virtual const EcXmlStringVector& proximalFingerLinks
      (
      ) const;

   /// set the labels of all the fingers' proximal links
   virtual void setProximalFingerLinks
      (
      const EcXmlStringVector& labels
      );

   /// get the tolerance value used to terminate the search
   virtual EcReal tolerance
      (
      ) const;

   /// set the tolerance value used to terminate the search
   virtual void setTolerance
      (
      EcReal value
      );

   /// get the max iterations used to terminate the search
   virtual EcU32 maxIterations
      (
      ) const;

   /// set the max iterations used to terminate the search
   virtual void setMaxIterations
      (
      EcU32 value
      );

   /// get the mode of searching for contacts
   virtual EcU32 searchMode
      (
      ) const;

   /// set the mode of searching for contacts
   virtual void setSearchMode
      (
      EcU32 value
      );


   /// compute and return the locations and normals of the contact points
   /**
   \param[in] system The system containing both the hand and the object to be grasped
   \param[in] initState The state used as initial point to search for contact locations
   \param[in] handIndex The index of the hand manipulator in the system
   \param[in] objectIndex The index of the object manipulator in the system
   \param[out] contactPoints The contact point data including the locations and normal forces
   \param[out] handState The position state (joint positions) of the hand (fingers) associated with the contact points
   \return True if contact points are successfully determined
   */
   virtual EcBoolean process
      (
      const EcManipulatorSystem& system,
      const EcManipulatorSystemState& initState,
      EcU32 handIndex,
      EcU32 objectIndex,
      EcGraspContactPointDataVector& contactPoints,
      EcPositionState& handState
      );

protected:

   /// labels of all fingers' distal links
   EcXmlStringVector    m_DistalFingerLinks; 

   /// labels of all fingers' proximal links
   EcXmlStringVector    m_ProximalFingerLinks; 
   /// tolerance for determining contact
   EcXmlReal            m_Tolerance;         

   /// max iterations to prevent infinite loop
   EcXmlU32             m_MaxIterations;     

   /// search mode (distal, proximal distal, and so forth)
   EcXmlU32             m_SearchMode;

   /// find the link indices from link labels
   virtual void findLinkIndices
      (
      const EcManipulatorSystem& system,
      EcU32 handIndex
      );

   /// locate a contact point given between a finger and an object
   virtual EcBoolean locateContactPoint
      (
      const EcManipulatorSystem& system,
      EcU32 handIndex,
      EcU32 objectIndex,
      const EcIndividualManipulator& hand,
      const EcIndividualManipulator& object,
      EcU32 linkIndex,
      EcGraspContactPointData& contactPoint,
      EcReal& jointPosition
      );

   /// inner class forward declaration
   class DistanceCalculation;

   /// search for the contact point
   /**
   \param[in] lowerBound The lower bound of the joint position to perform search
   \param[in] upperBound The upper bound of the joint position to perform search
   \param[in] distanceFunctor The functor to perform distance calculations
   \param[in] forward The search direction is forward (from lower bound to upper bound) or backward
   \param[out] solution The joint value (if found) at which the contact takes place
   \return True if a solution (i.e. contact) is found or false otherwise
   */
   virtual EcBoolean search
      (
      EcReal lowerBound,
      EcReal upperBound,
      DistanceCalculation& distanceFunctor,
      EcBoolean forward,
      EcReal& solution
      ) = 0;

   // Non-XML data

   /// non-XML vector holding the indices of the distal finger links
   EcU32Vector          m_DistalFingerLinkIndices;

   /// non-XML vector holding the indices of the proximal finger links
   EcU32Vector          m_ProximalFingerLinkIndices;

   /// an active state to speed processing 
   EcSystemActiveState  m_ActiveState;

   /// a position state to describe the hand
   EcPositionState      m_HandPosState;

   /// a function class for calculating distance
   class DistanceCalculation
   {
   public:
      /// constructor with values
      DistanceCalculation
         (
         const EcManipulatorSystem* pSystem,
         EcU32                      handIndex,
         EcU32                      objectIndex,
         const EcManipulatorLink*   pFingerLink,
         const EcManipulatorLink*   pObjectLink,
         EcU32                      linkIndex,
         EcSystemActiveState&       activeState,
         EcPositionState&           handState
         );

      /// function method
      /// @return The joint position
      EcReal operator()
         (
         EcReal jointPosition
         );

      /// a pointer to the system
      const EcManipulatorSystem*    m_pSystem;

      /// a pointer to the link representing the finger
      const EcManipulatorLink*      m_pFingerLink;

      /// a pointer to the link representing the object
      const EcManipulatorLink*      m_pObjectLink;

      /// the link index used in operator(). This joint is set to the value passed in.
      EcU32                         m_LinkIndex;

      /// an active state used to speed kinematic and dynamic calculations
      EcSystemActiveState&          m_ActiveState;

      /// the position state describing the hand
      EcPositionState&              m_HandPosState;

      /// a key used in geometric reasoning for the hand/finger
      EcManipulatorStateCacheKey    m_HandKey;

      /// a key used for geometric reasoning for the object
      EcManipulatorStateCacheKey    m_ObjectKey;

      /// an example point for contact on the finger
      EcVector                      m_FingerWitnessPoint;

      /// an example point for contact on the object
      EcVector                      m_ObjectWitnessPoint;

      /// the id for the contact shape on the finger
      EcU32                         m_FingerShapeID;

      /// the id for the contact shape on the object
      EcU32                         m_ObjectShapeID;

      /// an array of intersection pairs for cacheing
      EcShapeKeyPairVector          m_IntersectingShapes;

      /// an array of flags indicating if a shape is swapped for cacheing
      EcBooleanVector               m_ShapeSwappedVec;

      /// the tool used to calculate distance
      EcDistanceCalculationTool     m_DistTool;
   };
};

#endif // ecGraspContactLocator_H_
