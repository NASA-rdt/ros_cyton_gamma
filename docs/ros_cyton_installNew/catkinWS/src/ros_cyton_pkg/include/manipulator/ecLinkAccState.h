#ifndef ecLinkAccState_H_
#define ecLinkAccState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkAccState.h
/// @class EcLinkAccelerationState
/// @brief Holds the acceleration state of a single manipulator link.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecGeneralMotion.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlBasicType.h>

/// Holds the acceleration state of a single manipulator link.
class EC_FOUNDATION_MANIPULATOR_DECL EcLinkAccelerationState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcLinkAccelerationState
      (
      );

   /// destructor
   virtual ~EcLinkAccelerationState
      (
      );

   /// copy constructor
   EcLinkAccelerationState
      (
      const EcLinkAccelerationState& orig
      );

   /// assignment operator
   EcLinkAccelerationState& operator=
      (
      const EcLinkAccelerationState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinkAccelerationState& orig
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

   /// gets the locally-represented D-H frame general Acceleration
   virtual const EcGeneralAcceleration& dhFrameAccelerationInLocal
      (
      ) const;

   /// sets the locally-represented D-H frame general Acceleration
   virtual void setDhFrameAccelerationInLocal
      (
      const EcGeneralAcceleration& dhFrameAccelerationInLocal
      );

   /// gets the system-represented D-H frame general Acceleration
   virtual const EcGeneralAcceleration& dhFrameAccelerationInSystem
      (
      ) const;

   /// sets the system-represented D-H frame general Acceleration
   virtual void setDhFrameAccelerationInSystem
      (
      const EcGeneralAcceleration& dhFrameAccelerationInSystem
      );

   /// gets the system-represented primary frame general Acceleration
   virtual const EcGeneralAcceleration&
      primaryFrameAccelerationInSystem
      (
      ) const;

   /// sets the system-represented primary frame general Acceleration
   virtual void setPrimaryFrameAccelerationInSystem
      (
      const EcGeneralAcceleration& primaryFrameAccelerationInSystem
      );

   /// gets the locally-represented center of mass general acceleration
   virtual const EcGeneralAcceleration& comAccelerationInLocal
      (
      ) const;

   /// sets the locally-represented center of mass general acceleration
   virtual void setComAccelerationInLocal
      (
      const EcGeneralAcceleration& value
      );

   /// gets the momentum rate at center of mass represented in local DH frame
   virtual const EcGeneralMotion& momentumRateInLocal
      (
      ) const;

   /// sets the momentum rate at center of mass represented in local DH frame
   virtual void setMomentumRateInLocal
      (
      const EcGeneralMotion& value
      );

   /// gets the composite momentum rate of this link and its outboard links represented in local DH frame
   virtual const EcGeneralMotion& compositeMomentumRateInLocal
      (
      ) const;

   /// sets the composite momentum rate of this link and its outboard links represented in local DH frame
   virtual void setCompositeMomentumRateInLocal
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

   /// gets the momentum rate validity flag
   virtual EcBoolean localMomentumRateValid
      (
      ) const;

   /// sets the momentum rate validity flag
   virtual void setLocalMomentumRateValid
      (
      EcBoolean valid=EcTrue
      );

   /// gets the composite momentum rate validity flag
   virtual EcBoolean compositeMomentumRateValid
      (
      ) const;

   /// sets the composite momentum rate validity flag
   virtual void setCompositeMomentumRateValid
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
   static EcLinkAccelerationState nullObject
      (
      );

protected:

   /// the locally represented Acceleration for the link
   EcGeneralAcceleration m_DhFrameAccelerationInLocal;

   /// the system-represented Acceleration for the link
   EcGeneralAcceleration m_DhFrameAccelerationInSystem;

   /// the system-represented Acceleration for the primary frame
   EcGeneralAcceleration m_PrimaryFrameAccelerationInSystem;

   /// the locally represented acceleration for the center of mass
   EcGeneralAcceleration m_ComAccelerationInLocal;

   /// the momentum rate at center of mass represented in local DH frame
   EcGeneralMotion       m_MomentumRateInLocal;

   /// the composite momentum rate of this link and its outboard links represented in local DH frame
   EcGeneralMotion       m_CompositeMomentumRateInLocal;

   /// locally represented D-H frame validity flag
   EcXmlBoolean          m_LocalDhValid;

   /// system-represented D-H frame validity flag
   EcXmlBoolean          m_SystemDhValid;

   /// system-represented primary frame validity flag
   EcXmlBoolean          m_SystemPrimaryValid;

   /// locally represented COM acceleration validity flag
   EcXmlBoolean      m_LocalComValid;

   /// the validity flag for momentum rate
   EcXmlBoolean          m_LocalMomentumRateValid;

   /// the validity flag for composite momentum rate
   EcXmlBoolean          m_CompositeMomentumRateValid;
};

/// a vector of position states
typedef EcXmlVectorType<EcLinkAccelerationState> EcLinkAccelerationStateVector;

#endif // ecLinkAccState_H_
