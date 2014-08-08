#ifndef ecManipulationSceneDirection_H_
#define ecManipulationSceneDirection_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationSceneDirection.h
/// @class EcManipulationSceneDirection
/// @brief Virtual base class for manipulation scene directions.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <manipulation/ecManipulationStatus.h>
#include <xml/ecBaseExpTreeElement.h>
#include <xml/ecXmlBasicType.h>

// Forward declarations
class EcManipulationDirector;
class EcManipulationDirectorUpdateParams;
class EcManipulationSceneDirectionSimpleStateContainer;
class EcManipulationSceneDirectionStateContainer;

/// Virtual base class for manipulation scene directions.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationSceneDirection : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcManipulationSceneDirection
      (
      );

   /// destructor
   virtual ~EcManipulationSceneDirection
      (
      );

   /// copy constructor
   EcManipulationSceneDirection
      (
      const EcManipulationSceneDirection& orig
      );

   /// assignment operator
   EcManipulationSceneDirection& operator=
      (
      const EcManipulationSceneDirection& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationSceneDirection& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// get the tag used for referencing this direction
   virtual const EcString& tag
      (
      ) const;

   /// set the tag used for referencing this direction
   virtual void setTag
      (
      const EcString& tag
      );

   /// get the descriptor for this direction
   virtual const EcString descriptor
      (
      ) const = 0;

   /// get a vector of role names that are referenced within this direction
   virtual EcStringVector roleNames
      (
      const EcManipulationDirector& director
      ) const = 0;

   /// initialize the direction
   virtual EcBoolean init
      (
      const EcManipulationDirector&               director,
      const EcString&                             role,
      EcManipulationSceneDirectionStateContainer& dstateContainer
      ) const = 0;

   /// convert the direction state
   virtual void convert
      (
      const EcManipulationSceneDirectionStateContainer& dstateContainer,
      EcManipulationSceneDirectionSimpleStateContainer& sdstateContainer
      ) const = 0;

protected:
   /// Tag used for referencing this direction
   EcXmlString m_Tag;
};

#endif // ecManipulationSceneDirection_H_
