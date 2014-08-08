#ifndef ecManipulatorAttachmentChange_H_
#define ecManipulatorAttachmentChange_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulatorAttachmentChange.h
/// @class EcManipulatorAttachmentChange
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecCoordSysXForm.h>

// forward declarations

/**
\class EcManipulatorAttachmentChange

This is a helper class to provide information about change in manipulator attachment (including detachment)
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorAttachmentChange : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorAttachmentChange
      (
      );

   /// destructor
   virtual ~EcManipulatorAttachmentChange
      (
      );

   /// copy constructor
   EcManipulatorAttachmentChange
      (
      const EcManipulatorAttachmentChange& orig
      );

   /// assignment operator
   EcManipulatorAttachmentChange& operator=
      (
      const EcManipulatorAttachmentChange& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorAttachmentChange& orig
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

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

   /// get the index of the attached/detached manipulator
   virtual EcU32 manipIndex
      (
      ) const;

   /// get whether this change is an attach (true) or detach (false)
   virtual EcBoolean isAttach
      (
      ) const;

   /// get the index of the base manipulator. Only valid if attach
   virtual EcU32 baseManipIndex
      (
      ) const;

   /// get the label of the base link. Only valid if attach
   virtual const EcString& baseLinkLabel
      (
      ) const;

   /// get the offset of the attach
   virtual const EcCoordinateSystemTransformation& offset
      (
      ) const;

   /// from from an attach change
   virtual void setFromManipulatorAttach
      (
      EcU32 manipIndex,
      EcU32 baseManipIndex,
      const EcString& baseLinkLabel,
      const EcCoordinateSystemTransformation& offset
      );

   /// from from an detach change
   virtual void setFromManipulatorDetach
      (
      EcU32 manipIndex
      );

protected:
   EcXmlU32       m_ManipIndex;     ///< The manipulator index
   EcXmlBoolean   m_IsAttach;       ///< A flag indicating whether the change is attachment or detachement
   EcXmlU32       m_BaseManipIndex; ///< The index of the base manipulator
   EcXmlString    m_BaseLinkLabel;  ///< The label of the base link
   EcCoordinateSystemTransformation    m_Offset;   ///< The attachment offset
};

/// a vector of attachment changes
typedef EcXmlVectorType<EcManipulatorAttachmentChange>
   EcManipulatorAttachmentChangeVector;

#endif // ecManipulatorAttachmentChange_H_
