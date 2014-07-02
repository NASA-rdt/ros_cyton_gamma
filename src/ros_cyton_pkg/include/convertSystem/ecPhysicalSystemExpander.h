#ifndef ecPhysicalSystemExpander_H_
#define ecPhysicalSystemExpander_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecPhysicalSystemExpander.h
/// @class EcPhysicalSystemExpander
/// @brief Holds a tool for expanding physical components into
///        stated systems.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>

class EcIndividualManipulator;
class EcManipulatorLink;
class EcBasePhysicalExtent;
class EcStatedSystem;
class EcVelocityControlSystem;
class EcVisualizableStatedSystem;
class EcJointControllerSystemContainer;

/** Holds a tool for expanding physical components into stated systems.
*/
class EC_FOUNDATION_CONVERTSYSTEM_DECL EcPhysicalSystemExpander : public EcXmlCompoundType
{
public:
   /// default constructor
   EcPhysicalSystemExpander
      (
      );

   /// destructor
   virtual ~EcPhysicalSystemExpander
      (
      );

   /// copy constructor
   EcPhysicalSystemExpander
      (
      const EcPhysicalSystemExpander& orig
      );

   /// assignment operator
   EcPhysicalSystemExpander& operator=
      (
      const EcPhysicalSystemExpander& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPhysicalSystemExpander& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
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

   /// convert a physical extent to an individual manipulator
   virtual EcBoolean convertExtentToIndividualManipulator
      (
      const EcBasePhysicalExtent& physicalExtent,
      EcIndividualManipulator&  manipulator
      ) const;

   /// convert a physical extent to a manipulator link
   virtual EcBoolean convertExtentToManipulatorLink
      (
      const EcBasePhysicalExtent& physicalExtent,
      EcManipulatorLink& link
      ) const;

   /// convert a physical extent to a stated system
   virtual EcBoolean convertExtentToStatedSystem
      (
      const EcBasePhysicalExtent& physicalExtent,
      EcStatedSystem&  statedSystem
      ) const;

   /// convert an individual manipulator to a stated system
   virtual EcBoolean convertIndividualManipulatorToStatedSystem
      (
      const EcIndividualManipulator&  manipulator,
      EcStatedSystem&  statedSystem
      ) const;

   /// convert an individual manipulator to a visualizable stated system
   virtual EcBoolean convertIndividualManipulatorToVisualizableStatedSystem
      (
      const EcIndividualManipulator&  manipulator,
      EcVisualizableStatedSystem&  visStatedSystem
      ) const;

   /// convert a physical extent to a visualizable stated system
   virtual EcBoolean convertExtentToVisualizableStatedSystem
      (
      const EcBasePhysicalExtent& physicalExtent,
      EcVisualizableStatedSystem&  visStatedSystem
      ) const;

   /// convert a stated system to a visualizable stated system
   virtual EcBoolean convertStatedSystemToVisualizableStatedSystem
      (
      const EcStatedSystem&  statedSystem,
      EcVisualizableStatedSystem&  visStatedSystem
      ) const;

   /// a token unique to this class
   static const EcToken& classToken
      (
      );

   /// get an empty object
   static EcPhysicalSystemExpander nullObject
      (
      );
};

#endif // ecPhysicalSystemExpander_H_
