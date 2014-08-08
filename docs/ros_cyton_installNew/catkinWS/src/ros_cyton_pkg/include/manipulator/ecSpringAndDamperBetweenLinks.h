#ifndef ecSpringAndDamperBetweenLinks_H_
#define ecSpringAndDamperBetweenLinks_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecSpringAndDamperBetweenLinks.h
/// @class EcSpringAndDamperBetweenLinks
/// @brief Describes a spring and damper between two links.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseLinkInteractions.h"
#include "ecManipExternalForce.h"

#include <foundCommon/ecCoordSysXForm.h>
#include <foundCommon/ecGeneralMotion.h>

/// Describes a spring and damper between two links.
class EC_FOUNDATION_MANIPULATOR_DECL EcSpringAndDamperBetweenLinks : public EcBaseLinkInteractions
{
public:
   /// constructor
   EcSpringAndDamperBetweenLinks
      (
      );

   /// destructor
   virtual ~EcSpringAndDamperBetweenLinks
      (
      );

   /// copy constructor
   EcSpringAndDamperBetweenLinks
      (
      const EcSpringAndDamperBetweenLinks& orig
      );

   /// assignment operator
   EcSpringAndDamperBetweenLinks& operator=
      (
      const EcSpringAndDamperBetweenLinks& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSpringAndDamperBetweenLinks& orig
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

   /// XML-initializes the class by registering the components
   virtual EcBoolean xmlInit
      (
      );

   /// A virtual constructor that returns an EcXmlObject.
   virtual EcXmlObject* clone
      (
      ) const;

   /// registers all the components for this class that are
   /// read and written to XML files.
   virtual void registerComponents
      (
      );

   /// Reads class data from an XML stream.
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// Writes class data to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   static EcSpringAndDamperBetweenLinks nullObject
      (
      );

   /// get the linear spring constant
   virtual EcReal linearSpringConstant
      (
      )const;

   /// set the linear spring constant
   virtual void setAngularSpringConstant
      (
      EcReal angularSpringConstant
      );

   /// get the angular spring constant
   virtual EcReal angularSpringConstant
      (
      )const;

   /// set the angular spring constant
   virtual void setLinearSpringConstant
      (
      EcReal linearSpringConstant
      );

   /// get the linear spring offset
   virtual EcReal linearSpringOffset
      (
      )const;

   /// set the linear spring offset
   virtual void setLinearSpringOffset
      (
      EcReal linearSpringConstant
      );

   /// get the angular spring offset
   virtual EcReal angularSpringOffset
      (
      ) const;

   /// set the angular spring offset
   virtual void setAngularSpringOffset
      (
      EcReal angularSpringConstant
      );

   /// get the linear damper constant
   virtual EcReal linearDamperConstant
      (
      ) const;

   /// set the linear damper constant
   virtual void setLinearDamperConstant
      (
      EcReal linearDamperConstant
      );

   /// get the angular damper constant
   virtual EcReal angularDamperConstant
      (
      ) const;

   /// set the angular damper constant
   virtual void setAngularDamperConstant
      (
      EcReal angularDamperConstant
      );

   /// get the manipulator index for the first manipulator
   virtual EcU32  manipulatorOneIndex
      (
      ) const;

   /// set the manipulator index for the first manipulator
   virtual void setManipulatorOneIndex
      (
      EcU32 manipulatorOneIndex
      );

   /// get the manipulator index for the second manipulator
   virtual EcU32  manipulatorTwoIndex
      (
      ) const;

   /// set the manipulator index for the second manipulator
   virtual void setManipulatorTwoIndex
      (
      EcU32 manipulatorTwoIndex
      );

   /// get the link index for the first link
   virtual EcU32  linkOneIndex
      (
      ) const;

   /// set the link index for the first link
   virtual void setLinkOneIndex
      (
      EcU32  linkOneIndex
      );

   /// get the link index for the second link
   virtual EcU32  linkTwoIndex
      (
      ) const;

   /// set the link index for the second link
   virtual void setLinkTwoIndex
      (
      EcU32  linkTwoIndex
      );

   /// get the first frame offset
   virtual const EcCoordinateSystemTransformation& frameOffsetOne
      (
      ) const;

   /// set the first frame offset
   virtual void setFrameOffsetOne
      (
      const EcCoordinateSystemTransformation& frameOffsetOne
      );

   /// get the second frame offset
   virtual const EcCoordinateSystemTransformation& frameOffsetTwo
      (
      ) const;

   /// set the second frame offset
   virtual void setFrameOffsetTwo
      (
      const EcCoordinateSystemTransformation& frameOffsetOne
      );

   /// calculate the general force caused by spring and damper
   /// between links.  The force is represented in the DH frame
   /// of the link, with point of application at the DH frame
   /// origin.
   /// @copydoc EcBaseLinkInteractions::forceBetweenLinks()
   virtual void forceBetweenLinks
      (
      EcSystemActiveState&              actState,
      const EcManipulatorSystem&        manipSystem,
      const EcReal&                     time,
      const EcManipulatorTorqueVector&  torqueVec,
      EcManipulatorExternalForceVector& manipExtForceVec
      ) const;

   /// a virtual function returning the token for this class
   virtual const EcToken& token
      (
      ) const;

   /// a static function returning the token for this class
   static const EcToken& classToken
      (
      );

   /// a creator function for this class
   static EcXmlObject* creator
      (
      );

protected:

   /// linear spring constant
   EcXmlReal m_LinearSpringConstant;

   /// linear spring offset
   EcXmlReal m_LinearSpringOffset;

   /// Angular Spring Constant
   EcXmlReal m_AngularSpringConstant;

   /// Angular Spring Offset
   EcXmlReal m_AngularSpringOffset;

   /// Linear Damper Constant
   EcXmlReal m_LinearDamperConstant;

   /// Angular Damper Constant
   EcXmlReal m_AngularDamperConstant;

   /// Manipulator number One's Index
   EcXmlU32  m_ManipulatorOneIndex;

   /// Manipulator number Two's Index
   EcXmlU32  m_ManipulatorTwoIndex;

   /// Link number One's Index
   EcXmlU32  m_LinkOneIndex;

   /// Link number two's Index
   EcXmlU32  m_LinkTwoIndex;

   /// spring and damper connecting frame offset from the primary frame
   EcCoordinateSystemTransformation m_FrameOffsetOne;

   /// spring and damper connecting frame offset from the primary frame
   EcCoordinateSystemTransformation m_FrameOffsetTwo;

   // non-XML below

   /// Utility transformation
   mutable EcCoordinateSystemTransformation m_UtilityTransOne;

   /// utility transformation
   mutable EcCoordinateSystemTransformation m_UtilityTransTwo;

   /// utility general force
   mutable EcGeneralForce m_UtilityForceOne;

   /// utility general force
   mutable EcGeneralForce m_UtilityForceTwo;

   /// utility velocity
   mutable EcGeneralVelocity m_UtilityVelocityOne;

   /// utility velocity
   mutable EcGeneralVelocity m_UtilityVelocityTwo;
};

/// describes a vector of reals
typedef EcXmlVectorType<EcSpringAndDamperBetweenLinks>
   EcSpringAndDamperBetweenLinksVector;

#endif // ecSpringAndDamperBetweenLinks_H_
