#ifndef ecBaseGeneralBoundObject_H_
#define ecBaseGeneralBoundObject_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseGeneralBoundObject.h
/// @class EcBaseGeneralBoundObject
/// @brief Defines a base class for geometric objects that do not belong to any link.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecCoordSysXForm.h>
#include <xml/ecXmlCompType.h>
#include <geometry/ecShape.h>
#include <geometry/ecShapeContainer.h>

// forward declarations
class EcStatedSystem;
class EcIndividualManipulator;
class EcManipulatorActiveState;

/** Defines a base class for geometric objects that do not belong to any link. The object
 *  is only used for rendering.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcBaseGeneralBoundObject : public EcXmlCompoundType
{
public:
   /// default constructor
   EcBaseGeneralBoundObject
      (
      );

   /// destructor
   virtual ~EcBaseGeneralBoundObject
      (
      );

   /// copy constructor
   EcBaseGeneralBoundObject
      (
      const EcBaseGeneralBoundObject& orig
      );

   /// assignment operator
   EcBaseGeneralBoundObject& operator=
      (
      const EcBaseGeneralBoundObject& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseGeneralBoundObject& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const = 0;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const = 0;

   /// return a string token
   virtual const EcToken& token
      (
      ) const = 0;

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

   /// get the shape used to represent the object
   virtual const EcShape* shape
      (
      )const;

   /// set the shape used to represent the object
   virtual void setShape
      (
      const EcShape& shp
      );

   /// gets the primary frame. This is the frame in which the shape is represented.
   virtual const EcCoordinateSystemTransformation& primaryFrame
      (
      ) const;

   /// sets the primary frame.
   virtual void setPrimaryFrame
      (
      const EcCoordinateSystemTransformation& value
      );

   /// returns the location of this object in the system coordinates.
   virtual const EcCoordinateSystemTransformation& locationInSystem
      (
      EcManipulatorActiveState& state,
      const EcIndividualManipulator& manip
      )const = 0;

protected:
   /// container for holding the shape
   EcShapeContainer m_ShapeContainer;

   /// the primary frame
   EcCoordinateSystemTransformation m_PrimaryFrame;
};

#endif // ecBaseGeneralBoundObject_H_
