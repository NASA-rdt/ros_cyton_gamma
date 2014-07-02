#ifndef ecManipDataStorage_H_
#define ecManipDataStorage_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipDataStorage.h
/// @class EcManipulatorDataStorage
/// @brief Holds a description of captured manipulator data.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

/** Holds a description of configured manipulator data.
*/
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcManipulatorDataStorage : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorDataStorage
      (
      );

   /// destructor
   virtual ~EcManipulatorDataStorage
      (
      );

   /// copy constructor
   EcManipulatorDataStorage
      (
      const EcManipulatorDataStorage& orig
      );

   /// assignment operator
   EcManipulatorDataStorage& operator=
      (
      const EcManipulatorDataStorage& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorDataStorage& orig
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

   /// get the manipulator-level data
   virtual const EcXmlRealVectorVector& manipulatorLevelData
      (
      )const;

   /// set the manipulator-level data
   virtual void setManipulatorLevelData
      (
      const EcXmlRealVectorVector& manipulatorLevelData
      );

   /// set specific manipulator-level data--one datum
   virtual void setSpecificManipulatorLevelData
      (
      EcU32 dataIndex,
      EcU32 position,
      EcReal newData
      );

   /// set specific manipulator-level data--a vector of values
   virtual void setSpecificManipulatorLevelData
      (
      EcU32 dataIndex,
      EcU32 startingPosition,
      const EcXmlRealVector& newData
      );

   /// get the link-level data
   virtual const EcXmlRealVector3D& linkLevelData
      (
      )const;

   /// set the link-level data
   virtual void setLinkLevelData
      (
      const EcXmlRealVector3D& linkLevelData
      );

   /// set specific link-level data--one datum
   virtual void setSpecificLinkLevelData
      (
      EcU32 linkIndex,
      EcU32 dataIndex,
      EcU32 position,
      EcReal newData
      );

   /// set specific link-level data--a vector of values
   virtual void setSpecificLinkLevelData
      (
      EcU32 linkIndex,
      EcU32 dataIndex,
      EcU32 startingPosition,
      const EcXmlRealVector& newData
      );

   /// get the end-effector data
   virtual const EcXmlRealVector3D& endEffectorData
      (
      )const;

   /// set the end-effector data
   virtual void setEndEffectorData
      (
      const EcXmlRealVector3D& data
      );

   /// set specific end-effector data--one datum
   virtual void setSpecificEndEffectorData
      (
      EcU32 eeIndex,
      EcU32 dataIndex,
      EcU32 position,
      EcReal newData
      );

   /// set specific end-effector data--a vector of values
   virtual void setSpecificEndEffectorData
      (
      EcU32 eeIndex,
      EcU32 dataIndex,
      EcU32 startingPosition,
      const EcXmlRealVector& newData
      );

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
   static EcManipulatorDataStorage nullObject
      (
      );

protected:
   /// manipulator-level data
   EcXmlRealVectorVector      m_ManipulatorLevelData;

   /// link-level data
   EcXmlRealVector3D          m_LinkLevelData;

   /// end-effector data
   EcXmlRealVector3D          m_EndEffectorData;
};

/// an XML vector of links
typedef EcXmlVectorType<EcManipulatorDataStorage> EcManipulatorDataStorageVector;

#endif // ecManipDataStorage_H_
