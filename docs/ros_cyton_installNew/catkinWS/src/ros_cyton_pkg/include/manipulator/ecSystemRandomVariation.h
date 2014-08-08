#ifndef ecSystemRandomVariation_H_
#define ecSystemRandomVariation_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemRandomVariation.h
/// @brief Description of random variation for link properties for
///        the whole system
/// @details EcSystemRandomVariation
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlMapType.h>
#include <xml/ecXmlVectorType.h>
#include "ecLinkPropertyRandomVariation.h"

/**
\class EcSystemRandomVariation
\brief Description of random variation for link properties for the whole system.

The random variations are used in Monte Carlo simulations to randomly perturb the system properties. They are represented as a vector of maps. Each map represents the random variations of a manipulator in the system. The map uses the link labels as keys and EcLinkPropertyRandomVariation objects as values.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcSystemRandomVariation : public EcXmlCompoundType
{
public:
   /// Macro for declaring methods required to make a derived
   /// EcXmlObject concrete.
   ECXMLOBJECT(EcSystemRandomVariation);

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets the vector of manipulator random variation
   virtual const EcStringLinkPropertyRandomVariationMapVector& manipulatorRandomVariationVector
      (
      ) const;

   /// sets the vector of manipulator random variation
   virtual void setManipulatorRandomVariationVector
      (
      const EcStringLinkPropertyRandomVariationMapVector& value
      );

   /// gets the manipulator random variation map for a given manipulator index. Returns an empty map if the manipulator index is out of range.
   virtual const EcStringLinkPropertyRandomVariationMap& manipulatorRandomVariation
      (
      EcU32 manipIndex
      ) const;

   /// sets the manipulator random variation object for a given manipulator index. If manipIndex is out of range, then this will resize the internal vector of the manipulator random variations.
   virtual void setManipulatorRandomVariation
      (
      EcU32 manipIndex,
      const EcStringLinkPropertyRandomVariationMap& value
      );

   /// return the EcLinkPropertyRandomVariation object for a given link. If the manipulator index or the link identifier is invalid, the default value is returned
   /**
   \param[in] manipIndex The desired manipulator index.
   \param[in] linkId The desired link identifying label.
   */
   virtual const EcLinkPropertyRandomVariation& linkPropertyRandomVariation
      (
      EcU32 manipIndex,
      const EcString& linkId
      ) const;

   /// add an EcLinkPropertyRandomVariation object for a given link. If it already exists, it be be overwritten. If manipIndex is out of range, then this will resize the internal vector of the manipulator random variations.
   /**
   \param[in] manipIndex The desired manipulator index.
   \param[in] linkId The desired link identifying label.
   \param[in] value The EcLinkPropertyRandomVariation object to be added.
   */
   virtual void addLinkPropertyRandomVariation
      (
      EcU32 manipIndex,
      const EcString& linkId,
      const EcLinkPropertyRandomVariation& value
      );

   /// remove the EcLinkPropertyRandomVariation object for a given link.
   /**
   \param[in] manipIndex The desired manipulator index.
   \param[in] linkId The desired link identifying label.
   \return True if the removal was successful or false if the link is invalid.
   */
   virtual EcBoolean removeLinkPropertyRandomVariation
      (
      EcU32 manipIndex,
      const EcString& linkId
      );

   /// set the default link property random variation. The default value is returned by linkPropertyRandomVariation method when the link in query is invalid.
   void setDefaultLinkPropertyRandomVariation
      (
      const EcLinkPropertyRandomVariation& value
      );
protected:
   /// the vector for all manipulator random variations
   EcStringLinkPropertyRandomVariationMapVector    m_vManipRandomVariation;

   /// the default value for link property random variation
   EcLinkPropertyRandomVariation                   m_DefaultLinkRandomVariation;

   /// non-XML data
   /// the default value for manipulator random variation
   static EcStringLinkPropertyRandomVariationMap   m_theDefaultManipRandomVariation;
};

#endif // ecSystemRandomVariation_H_
