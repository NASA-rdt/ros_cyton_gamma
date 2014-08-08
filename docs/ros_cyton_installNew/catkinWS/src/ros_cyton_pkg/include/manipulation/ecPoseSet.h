#ifndef ecPoseSet_H_
#define ecPoseSet_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecPoseSet.h
/// @class EcPoseSet
/// @brief This class is a set of poses
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecPose.h"

#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>
#include <xml/ecXmlVectorType.h>

class EC_ACTIN_MANIPULATION_DECL EcPoseSet : public EcXmlCompoundType
{
public:
   /// type definition of Pose
   typedef EcPose Pose;
   /// type definition of StringPoseMap
   typedef EcXmlMapType< EcXmlString, Pose > StringPoseMap;

   /// default constructor
   EcPoseSet
      (
      );

   /// destructor
   virtual ~EcPoseSet
      (
      );

   /// copy constructor
   EcPoseSet
      (
      const EcPoseSet& orig
      );

   /// assignment operator
   EcPoseSet& operator=
      (
      const EcPoseSet& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPoseSet& orig
      ) const;

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

   /// the token
   virtual const EcToken& token
      (
      ) const;

   /// get the name
   virtual const EcString& name
      (
      ) const;

   /// set the name
   virtual void setName
      (
      const EcString& value
      );

   /// get the pose map
   virtual const StringPoseMap& poseMap
      (
      ) const;

   /// set the pose map
   virtual void setPoseMap
      (
      const StringPoseMap& value
      );

   /// add a pose with name
   virtual EcBoolean addPose
      (
      const EcXmlString& name,
      const Pose& pose
      );

   /// update an existing named pose
   virtual EcBoolean updatePose
      (
      const EcXmlString& name,
      const Pose& pose
      );

   /// delete the pose associated with the name
   virtual EcBoolean deletePose
      (
      const EcXmlString& name
      );

protected:
   EcXmlString       m_Name;     ///< name of the set
   StringPoseMap     m_PoseMap;  ///< map containing poses with name of each pose as the key
};

/// type definition of EcPoseSetVector
typedef EcXmlVectorType< EcPoseSet >   EcPoseSetVector;

#endif // ecPoseSet_H_
