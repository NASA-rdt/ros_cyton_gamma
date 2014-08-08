#ifndef ecEditorGraspFrameData_H_
#define ecEditorGraspFrameData_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecEditorGraspFrameData.h
/// @class EcEditorGraspFrameData
/// @brief Complimentary data for a grasp frame for use in grasp editor.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <manipulator/ecManipSysState.h>
#include <visualization/ecPovParameters.h>
#include <xml/ecXmlCompType.h>

/// Complimentary data for a grasp frame for use in grasp editor.
class EC_ACTIN_GRASPING_DECL EcEditorGraspFrameData : public EcXmlCompoundType
{
public:
   /// default constructor
   EcEditorGraspFrameData
      (
      );

   /// destructor
   virtual ~EcEditorGraspFrameData
      (
      );

   /// copy constructor
   EcEditorGraspFrameData
      (
      const EcEditorGraspFrameData& orig
      );

   /// assignment operator
   EcEditorGraspFrameData& operator=
      (
      const EcEditorGraspFrameData& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcEditorGraspFrameData& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   /**
       \retval cloned XML object
   */
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

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// get the POV parameters
   virtual const EcPovParameters& povParameters
      (
      ) const;

   /// set the POV parameters
   virtual void setPovParameters
      (
      const EcPovParameters& povParameters
      );

   /// get the state
   virtual const EcManipulatorSystemState& state
      (
      ) const;

   /// set the state
   virtual void setState
      (
      const EcManipulatorSystemState& state
      );

protected:
   /// the POV parameters
   EcPovParameters            m_PovParams;
   /// the state
   EcManipulatorSystemState   m_State;
};

/// An XML-readable/writiable vector of EcEditorGraspFrameData objects.
typedef EcXmlVectorType<EcEditorGraspFrameData> EcEditorGraspFrameDataVector;

#endif // ecEditorGraspFrameData_H_
