#ifndef ecQuadPivotedSliderJointBObject_H_
#define ecQuadPivotedSliderJointBObject_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecQuadPivotedSliderJointBObject.h
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <geometry/ecShape.h>
#include <geometry/ecShapeContainer.h>
#include "ecBaseGeneralBoundObject.h"

/** Holds a description of a quadrilateral link object
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcQuadrilateralPivotedSliderJointBObject : public EcBaseGeneralBoundObject
{
public:
   /// default constructor
   EcQuadrilateralPivotedSliderJointBObject
      (
      );

   /// destructor
   virtual ~EcQuadrilateralPivotedSliderJointBObject
      (
      );

   /// copy constructor
   EcQuadrilateralPivotedSliderJointBObject
      (
      const EcQuadrilateralPivotedSliderJointBObject& orig
      );

   /// assignment operator
   EcQuadrilateralPivotedSliderJointBObject& operator=
      (
      const EcQuadrilateralPivotedSliderJointBObject& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcQuadrilateralPivotedSliderJointBObject& orig
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
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// return a string token
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

   /// returns the class token
   static const EcToken& classToken
      (
      );

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// returns the location (transformation) of the frame attached to point B in the system coordinates.
   virtual const EcCoordinateSystemTransformation& locationInSystem
      (
      EcManipulatorActiveState& state,
      const EcIndividualManipulator& manip
      )const;


   /// get parent link ID
   virtual const EcString& linkIdentifier
      (
      ) const;

   /// set parent link ID
   virtual void setlinkIdentifier
      (
      const EcString& lnkName
      ) ;

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// the link identifier
   EcXmlString m_LinkIdentifier;

   // --- mutable objects
   /// holds the location of the object
   mutable EcCoordinateSystemTransformation m_Location;
};

#endif // ecQuadPivotedSliderJointBObject_H_
