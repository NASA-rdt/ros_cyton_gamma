#ifndef ecLinkVelState_H_
#define ecLinkVelState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkVelState.h
/// @class EcLinkVelocityState
/// @brief Holds the velocity state of a single manipulator link.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecGeneralMotion.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlBasicType.h>

/// Holds the velocity state of a single manipulator link.
class EC_FOUNDATION_MANIPULATOR_DECL EcLinkVelocityState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcLinkVelocityState
      (
      );

   /// destructor
   virtual ~EcLinkVelocityState
      (
      );

   /// copy constructor
   EcLinkVelocityState
      (
      const EcLinkVelocityState& orig
      );

   /// assignment operator
   EcLinkVelocityState& operator=
      (
      const EcLinkVelocityState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinkVelocityState& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// gets the locally-represented D-H frame general velocity
   virtual const EcGeneralVelocity& dhFrameVelocityInLocal
      (
      ) const;

   /// sets the locally-represented D-H frame general velocity
   virtual void setDhFrameVelocityInLocal
      (
      const EcGeneralVelocity& dhFrameVelocityInLocal
      );

   /// gets the system-represented D-H frame general velocity
   virtual const EcGeneralVelocity& dhFrameVelocityInSystem
      (
      ) const;

   /// sets the system-represented D-H frame general velocity
   virtual void setDhFrameVelocityInSystem
      (
      const EcGeneralVelocity& dhFrameVelocityInSystem
      );

   /// gets the system-represented primary frame general velocity
   virtual const EcGeneralVelocity& primaryFrameVelocityInSystem
      (
      ) const;

   /// sets the system-represented primary frame general velocity
   virtual void setPrimaryFrameVelocityInSystem
      (
      const EcGeneralVelocity& primaryFrameVelocityInSystem
      );

   /// gets the locally-represented center of mass general velocity
   virtual const EcGeneralVelocity& comVelocityInLocal
      (
      ) const;

   /// sets the locally-represented center of mass general velocity
   virtual void setComVelocityInLocal
      (
      const EcGeneralVelocity& value
      );

   /// gets the momentum at center of mass represented in local DH frame
   virtual const EcGeneralMotion& momentumInLocal
      (
      ) const;

   /// sets the momentum at center of mass represented in local DH frame
   virtual void setMomentumInLocal
      (
      const EcGeneralMotion& value
      );

   /// gets the composite momentum of this link and its outboard links represented in local DH frame
   virtual const EcGeneralMotion& compositeMomentumInLocal
      (
      ) const;

   /// sets the composite momentum of this link and its outboard links represented in local DH frame
   virtual void setCompositeMomentumInLocal
      (
      const EcGeneralMotion& value
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

   /// gets the system D-H validity flag
   virtual EcBoolean systemDhValid
      (
      ) const;

   /// sets the system D-H validity flag
   virtual void setSystemDhValid
      (
      EcBoolean valid=EcTrue
      );

   /// gets the system primary validity flag
   virtual EcBoolean systemPrimaryValid
      (
      ) const;

   /// sets the system primary validity flag
   virtual void setSystemPrimaryValid
      (
      EcBoolean valid=EcTrue
      );

   /// gets the local COM velocity validity flag
   virtual EcBoolean localComValid
      (
      ) const;

   /// sets the local COM velocity validity flag
   virtual void setLocalComValid
      (
      EcBoolean valid=EcTrue
      );

   /// gets the momentum validity flag
   virtual EcBoolean localMomentumValid
      (
      ) const;

   /// sets the momentum validity flag
   virtual void setLocalMomentumValid
      (
      EcBoolean valid=EcTrue
      );

   /// gets the composite momentum validity flag
   virtual EcBoolean compositeMomentumValid
      (
      ) const;

   /// sets the composite momentum validity flag
   virtual void setCompositeMomentumValid
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
   static EcLinkVelocityState nullObject
      (
      );

protected:

   /// the locally represented velocity for the link
   EcGeneralVelocity m_DhFrameVelocityInLocal;

   /// the system-represented velocity for the link
   EcGeneralVelocity m_DhFrameVelocityInSystem;

   /// the system-represented velocity for the primary frame
   EcGeneralVelocity m_PrimaryFrameVelocityInSystem;

   /// the locally represented velocity for the center of mass
   EcGeneralVelocity m_ComVelocityInLocal;

   /// the momentum at center of mass represented in local DH frame
   EcGeneralMotion   m_MomentumInLocal;

   /// the composite momentum of this link and its outboard links represented in local DH frame
   EcGeneralMotion   m_CompositeMomentumInLocal;

   /// locally represented D-H frame validity flag
   EcXmlBoolean      m_LocalDhValid;

   /// system-represented D-H frame validity flag
   EcXmlBoolean      m_SystemDhValid;

   /// system-represented primary frame validity flag
   EcXmlBoolean      m_SystemPrimaryValid;

   /// locally represented COM velocity validity flag
   EcXmlBoolean      m_LocalComValid;

   /// the validity flag for momentum
   EcXmlBoolean      m_LocalMomentumValid;

   /// the validity flag for composite momentum
   EcXmlBoolean      m_CompositeMomentumValid;
};

/// a vector of position states
typedef EcXmlVectorType<EcLinkVelocityState> EcLinkVelocityStateVector;

#endif // ecLinkVelState_H_
