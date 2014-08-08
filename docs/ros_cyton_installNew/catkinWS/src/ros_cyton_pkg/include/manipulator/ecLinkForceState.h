#ifndef ecLinkForceState_H_
#define ecLinkForceState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkForceState.h
/// @class EcLinkForceState
/// @brief Holds the force state of a single manipulator link.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecGeneralForce.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlVectorType.h>
#include "ecExternalForceDescription.h"

/// Holds the force state of a single manipulator link.
class EC_FOUNDATION_MANIPULATOR_DECL EcLinkForceState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcLinkForceState
      (
      );

   /// destructor
   virtual ~EcLinkForceState
      (
      );

   /// copy constructor
   EcLinkForceState
      (
      const EcLinkForceState& orig
      );

   /// assignment operator
   EcLinkForceState& operator=
      (
      const EcLinkForceState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinkForceState& orig
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

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets the locally-represented D-H frame general velocity
   virtual const EcGeneralForce& dhFrameForceInLocal
      (
      ) const;

   /// sets the locally-represented D-H frame general velocity
   virtual void setDhFrameForceInLocal
      (
      const EcGeneralForce& dhFrameVelocityInLocal
      );

   /// gets the external force description
   virtual const EcExternalForceDescription& externalForceDescription
      (
      ) const;

   /// sets the external force description
   virtual void setExternalForceDescription
      (
      const EcExternalForceDescription& dhFrameVelocityInLocal
      );

   /// gets the external force valid flag
   virtual const EcBoolean& externalForceValid
      (
      ) const;

   /// sets the external force valid flag
   virtual void setExternalForceValid
      (
      EcBoolean valid=EcTrue
      );

   /// gets the local D-H validity flag
   virtual EcBoolean localDhValid
      (
      ) const;

   /// sets the local D-H validity flag
   virtual void setLocalDhValid
      (
      EcBoolean valid=EcTrue
      );

   /// invalidates all values
   virtual void invalidateAll
      (
      );

   /// @copydoc EcXmlObject::token()
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

   /// get a null object
   static EcLinkForceState nullObject
      (
      );

protected:
   /// the locally represented velocity for the link
   EcGeneralForce m_DhFrameForceInLocal;

   /// locally represented D-H frame validity flag
   EcXmlBoolean m_LocalDhValid;

   /// forces imposed from impact dynamics
   EcExternalForceDescription m_ExternalForce;

};

/// a vector of position states
typedef EcXmlVectorType<EcLinkForceState> EcLinkForceStateVector;

#endif // ecLinkForceState_H_
