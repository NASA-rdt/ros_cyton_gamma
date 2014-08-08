#ifndef ecExternalForceDescription_H_
#define ecExternalForceDescription_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecExternalForceDescription.h
/// @class EcExternalForceDescription
/// @brief Class describing a general force (force and moment) and its point of application
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <foundCommon/ecCoordSysXForm.h>
#include <foundCommon/ecGeneralForce.h>
#include <geometry/ecLineSegment.h>

class EcManipulatorLink;

/** Class describing a general force (force and moment) and its point of application
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcExternalForceDescription : public EcXmlCompoundType
{
public:
   /// default constructor
   EcExternalForceDescription
      (
      );

   /// destructor
   virtual ~EcExternalForceDescription
      (
      );

   /// copy constructor
   EcExternalForceDescription
      (
      const EcExternalForceDescription& orig
      );

   /// assignment operator
   EcExternalForceDescription& operator=
      (
      const EcExternalForceDescription& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcExternalForceDescription& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

   /// clone
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

   /// get the external force in the primary frame
   const EcGeneralForce& externalLinkForce
      (
      )const;

   /// set the external force in the primary frame
   void setExternalLinkForce
      (
      const EcGeneralForce& value
      );

   /// get the force application point in the primary frame
   const EcVector& forceApplicationPoint
      (
      )const;

   /// set the force application point in the primary frame
   void setForceApplicationPoint
      (
      const EcVector& value
      );

   /// return valid
   virtual const EcBoolean& valid
      (
      )const;

   /// set the valid flag
   virtual void setValid
      (
      const EcBoolean& val = EcTrue
      );

   /// computes the representative force vector used for display
   const EcLineSegment& representativeForceVector
      (
      ) const;

protected:

   /// the external force in the primary frame
   EcGeneralForce m_ExternalLinkForce;

   /// the point of application of the force in the primary frame
   EcVector m_ForceApplicationPoint;

   /// value representing the force vector
   mutable EcLineSegment m_RepresentativeForceVector;

   /// the valid flag
   EcBoolean m_IsValid;

   // const data
   static const EcLineSegment m_TheNullLineSegment;   ///< The null line segment for error recovery

};

#endif // ecExternalForceDescription_H_
