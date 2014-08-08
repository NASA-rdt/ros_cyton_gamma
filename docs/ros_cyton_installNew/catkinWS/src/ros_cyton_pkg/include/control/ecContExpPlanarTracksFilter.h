#ifndef ecContExpPlanarTracksFilter_H_
#define ecContExpPlanarTracksFilter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpPlanarTracksFilter.h
/// @class EcControlExpressionPlanarTracksFilter
/// @brief This expression element is supposed to work with planar end
///        effector and yields the tracks behavior.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"
#include "ecExpContainer.h"
#include "ecContExpContainer.h"

// forward declaration
class EcIndividualManipulator;

/// This yields the tracks behavior.
class EC_ACTIN_CONTROL_DECL EcControlExpressionPlanarTracksFilter : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionPlanarTracksFilter
      (
      );

   /// constructor from an EcControlExpressionContainer pointer
   EcControlExpressionPlanarTracksFilter
      (
      const EcControlExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionPlanarTracksFilter
      (
      );

   /// copy constructor
   EcControlExpressionPlanarTracksFilter
      (
      const EcControlExpressionPlanarTracksFilter& orig
      );

   /// assignment operator
   EcControlExpressionPlanarTracksFilter& operator=
      (
      const EcControlExpressionPlanarTracksFilter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionPlanarTracksFilter& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return the value
   /// @return (EcVelocityControlData&) The velocity control data
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// sets the container
   /// @param[in] container (EcXmlBaseVariableCompoundType*) value to set
   virtual void setContainer
      (
      const EcXmlBaseVariableCompoundType* container
      );

   /// gets the angular rate factor
   /// @return (EcReal&) The angular rate (directly proportional to linear speed and direction)
   virtual const EcReal& angularRateFactor
      (
      ) const;

   /// sets the angular Rate Factor
   /// @param[in] angularRateFactor (EcReal&) value to set the angular rate
   virtual void setAngularRateFactor
      (
      const EcReal& angularRateFactor
      );

   /// gets the unfiltered rates
   /// @return The (EcControlExpressionContainer&) The unfiltered rates
   virtual const EcControlExpressionContainer& unfilteredRates
      (
      ) const;

   /// sets the unfiltered rates
   /// @param[in] unfilteredRatesContainer (EcControlExpressionContainer&) value to set the unfiltered rates container
   virtual void setUnfilteredRatesContainer
      (
      const EcControlExpressionContainer& unfilteredRatesContainer
      );

   /// sets the unfiltered rates element
   /// @param[in] unfilteredRatesElement (EcExpressionElement&) value to set the un-filtered rates element
   virtual void setUnfilteredRatesElement
      (
      const EcExpressionElement& unfilteredRatesElement
      );

   /// gets the frame in primary
   /// @return The base primary frame
   virtual const EcCoordinateSystemTransformation& baseFilterFrameInPrimary
      (
      ) const;

   /// sets the frame in primary
   /// @param[in] baseFilterFrameInPrimary (EcCoordinateSystemTransformation&) value to set the base filter frame
   virtual void setBaseFilterFrameInPrimary
      (
      const EcCoordinateSystemTransformation& baseFilterFrameInPrimary
      );

   /// Use joint rate information in manipulator to automaticaly assign appropriate values for weights and threshold
   /// @param[in] manip (EcIndividualManipulator&) The individual manipulator
   virtual void assignParametersFromManip
      (
      const EcIndividualManipulator& manip
      );

   /// return a token
   /// @return (EcToken&) The xml token
   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   /// @param[in] stream (EcXmlReader&) stream to be read from xml file
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   /// @param[in] stream (EcXmlWriter&) stream to be written into xml file
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   /// (EcControlExpressionPlanarTracksFilter) The null object
   static EcControlExpressionPlanarTracksFilter nullObject
      (
      );

   /// token for this class
   /// @return (EcToken&) The class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The xml object pointer
   static EcXmlObject* creator
      (
      );

protected:
   /// angular rate is proportional to linear speed and direction
   EcXmlReal   m_AngularRateFactor;

   /// the unfiltered joint rates
   EcControlExpressionContainer  m_UnfilteredRates;


   // This should be the same as the one defined in the End Effector; but we have
   // trouble getting access to that data, so redefine it here.
   /// Filter Frame represented in base primary frame.
   EcCoordinateSystemTransformation m_BaseFilterFrameInPrimary;
};

#endif // ecContExpPlanarTracksFilter_H_
