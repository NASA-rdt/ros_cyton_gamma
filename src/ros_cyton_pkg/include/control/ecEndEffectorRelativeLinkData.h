#ifndef ecEndEffectorRelativeLinkData_H_
#define ecEndEffectorRelativeLinkData_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecEndEffectorRelativeLinkData.h
/// @class EcEndEffectorRelativeLinkData
/// @brief Holds a description of the relative nature of an
///        end effector.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlEnumType.h>

/// Holds a description of the relative nature of an end effector.
class EC_ACTIN_CONTROL_DECL EcEndEffectorRelativeLinkData : public EcXmlCompoundType
{
public:
   /// Mode of link relativity
   enum RelativeMode
   {
      NONE,             ///< The end-effector is not relative
      INTERNAL,         ///< The end-effector is relative to a link on the same manipulator
      EXTERNAL          ///< The end-effector is relative to a link on another manipulator
   };

   /// default constructor
   EcEndEffectorRelativeLinkData
      (
      );

   /// destructor
   virtual ~EcEndEffectorRelativeLinkData
      (
      );

   /// copy constructor
   EcEndEffectorRelativeLinkData
      (
      const EcEndEffectorRelativeLinkData& orig
      );

   /// assignment operator
   EcEndEffectorRelativeLinkData& operator=
      (
      const EcEndEffectorRelativeLinkData& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcEndEffectorRelativeLinkData& orig
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

   /// get the relative mode
   virtual RelativeMode relativeMode
      (
      ) const;

   /// set the relative mode
   virtual void setRelativeMode
      (
      RelativeMode mode
      );

   /// get relative link label
   virtual const EcString& relativeLinkID
      (
      ) const;

   /// set relative link label
   virtual void setRelativeLinkID
      (
      const EcString& relativeLinkID
      );

   /// get relative manipulator index.
   virtual EcU32 relativeManipulatorIndex
      (
      ) const;

   /// set relative manipulator index.
   virtual void setRelativeManipulatorIndex
      (
      EcU32 index
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

   /// get a null link
   static EcEndEffectorRelativeLinkData nullObject
      (
      );

   /// get a const reference to a static const value
   static const EcEndEffectorRelativeLinkData& referenceObject
      (
      );

protected:
   /// register relative mode enumerations
   virtual void registerRelativeModeEnumerations
      (
      );

protected:
   /// the relative mode
   EcXmlEnumU32                               m_RelativeMode;

   /// a relative link ID
   EcXmlString                                m_RelativeLinkID;

   /// the index of manipulator to which the end-effector is defined as relative
   EcXmlInt32                                 m_RelativeManipulatorIndex;

   /// relative link flag. It's deprecated and replaced by m_RelativeMode. Still present only for backward compability reason.
   EcXmlBoolean                               m_IsRelativeLink;

   /// non-XML below
   static const EcEndEffectorRelativeLinkData m_theReferenceObject;
};

#endif // ecEndEffectorRelativeLinkData_H_
