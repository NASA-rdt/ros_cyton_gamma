#ifndef ecLinkAttachment_H_
#define ecLinkAttachment_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkAttachment.h
/// @class EcLinkAttachment
/// @brief Holds a class for single attachment to a link.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <foundCommon/ecGeneralMotion.h>
#include <foundCommon/ecCoordSysXForm.h>
#include <matrixUtilities/ecReArray.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlBasicType.h>

// forward declarations
class EcIndividualManipulator;
class EcManipulatorActivePositionState;
class EcManipulatorActiveState;
class EcManipulatorLink;
class EcManipulatorActiveState;

/** Holds a class for single attachment to a link.  This class is responsible for computing the placement, velocity, and acceleration of the attachment. These pieces of information can be used to determine the placements of sensors (such as cameras).
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcLinkAttachment : public EcXmlCompoundType
{
public:
   /// default constructor
   EcLinkAttachment
      (
      );

   /// destructor
   virtual ~EcLinkAttachment
      (
      );

   /// copy constructor
   EcLinkAttachment
      (
      const EcLinkAttachment& orig
      );

   /// assignment operator
   EcLinkAttachment& operator=
      (
      const EcLinkAttachment& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinkAttachment& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
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

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// Return the manipulator index
   virtual EcU32 manipulatorIndex
      (
      ) const;

   /// Set the manipulator index
   virtual void setManipulatorIndex
      (
      EcU32 manipulatorIndex
      );

   /// Return the link identifier
   virtual const EcString& linkIdentifier
      (
      ) const;

   /// Set the link identifier
   virtual void setLinkIdentifier
      (
      const EcString& linkIdentifier
      );

   /// Return the frame
   virtual const EcCoordinateSystemTransformation& frame
      (
      ) const;

   /// Set the frame
   virtual void setFrame
      (
      const EcCoordinateSystemTransformation& frame
      );

   /// calculate a placement value for the attachment.  The placement
   /// is described through an EcCoordinateSystemTransformation.
   virtual void calculatePlacement
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  activeState,
      EcCoordinateSystemTransformation& placement
      ) const;

   /// calculate attachment velocity.
   virtual void calculateVelocity
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& velocity,
      EcU32 startInsertionIndex=0
      ) const;

   /// calculate attachment acceleration.
   virtual void calculateAcceleration
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActiveState&  actState,
      EcXmlRealVector& acceleration,
      EcU32 startInsertionIndex=0
      ) const;

   /// get a null point end effector
   static EcLinkAttachment nullObject
      (
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// the manipulator index
   EcXmlU32                            m_ManipulatorIndex;

   /// the string identifier for the link to which this is attached
   EcXmlString                         m_LinkIdentifier;

   /// the end-effector frame with respect to the link's primary frame
   EcCoordinateSystemTransformation    m_Frame;
};

#endif // ecLinkAttachment_H_
