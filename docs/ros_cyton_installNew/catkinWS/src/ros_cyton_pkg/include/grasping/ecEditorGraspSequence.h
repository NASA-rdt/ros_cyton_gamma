#ifndef ecEditorGraspSequence_H_
#define ecEditorGraspSequence_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecEditorGraspSequence.h
/// @class EcEditorGraspSequence
/// @brief A grasp sequence for grasp editor.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecEditorGraspFrameData.h"
#include "ecGraspSequence.h"

/// A grasp sequence for grasp editor.
/**    This is a grasp sequence plus some complimentary data for editing purposes.
*/
class EC_ACTIN_GRASPING_DECL EcEditorGraspSequence : public EcXmlCompoundType
{
public:
   /// default constructor
   EcEditorGraspSequence
      (
      );

   /// destructor
   virtual ~EcEditorGraspSequence
      (
      );

   /// copy constructor
   EcEditorGraspSequence
      (
      const EcEditorGraspSequence& orig
      );

   /// assignment operator
   EcEditorGraspSequence& operator=
      (
      const EcEditorGraspSequence& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcEditorGraspSequence& orig
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

   /// get the grasp sequence
   virtual const EcGraspSequence& graspSequence
      (
      ) const;

   /// set the grasp sequence
   virtual void setGraspSequence
      (
      const EcGraspSequence& graspSequence
      );

   /// get the grasp frame container vector
   virtual const EcGraspFrameContainerVector& graspFrameContainerVector
      (
      ) const;

   /// set the grasp frame container vector
   virtual void setGraspFrameContainerVector
      (
      const EcGraspFrameContainerVector& graspFrameContainerVector
      );

   /// get the editor data vector
   virtual const EcEditorGraspFrameDataVector& editorDataVector
      (
      ) const;

   /// set the editor data vector
   virtual void setEditorDataVector
      (
      const EcEditorGraspFrameDataVector& editorDataVector
      );

   /// add a grasp frame at the end of the grasp sequence
   virtual void addFrame
      (
      const EcGraspFrame& graspFrame,
      const EcEditorGraspFrameData& editorData
      );

   /// add a grasp frame (held withink a container) at the end of the grasp sequence
   virtual void addFrame
      (
      const EcGraspFrameContainer& graspFrameContainer,
      const EcEditorGraspFrameData& editorData
      );

   /// delete a grasp frame. If index is invalid, it will do nothing.
   virtual void deleteFrame
      (
      EcU32 index
      );

   /// insert a grasp frame at the given index. If index=0, then it's the first grasp frame. If index >= current size of the sequence, it's equivalent to addFrame.
   virtual void insertFrame
      (
      EcU32 index,
      const EcGraspFrame& graspFrame,
      const EcEditorGraspFrameData& editorData
      );

   /// update the grasp frame at the given index. If index is out of range, then it does nothing
   virtual void updateFrame
      (
      EcU32 index,
      const EcGraspFrame& graspFrame,
      const EcEditorGraspFrameData& editorData
      );

   /// clear all frames from the sequence
   virtual void clear
      (
      );

protected:
   /// the grasp sequence
   EcGraspSequence   m_GraspSequence;
   /// the editor data vector
   EcEditorGraspFrameDataVector  m_vEditorData;
};

#endif // ecEditorGraspSequence_H_
