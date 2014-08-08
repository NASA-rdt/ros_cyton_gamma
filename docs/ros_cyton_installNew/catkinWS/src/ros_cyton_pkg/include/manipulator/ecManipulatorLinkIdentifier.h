#ifndef ecManipulatorLinkIdentifier_H_
#define ecManipulatorLinkIdentifier_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulatorLinkIdentifier.h
/// @class EcManipulatorLinkIdentifier
/// @brief a helper class containing a link identifier and its manipulator index
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

/// a helper class containing a link identifier and its manipulator index
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorLinkIdentifier : public EcXmlCompoundType
{
public:
   /// Macro for declaring methods required to make a derived
   /// EcXmlObject concrete.
   ECXMLOBJECT(EcManipulatorLinkIdentifier);

   /// constructor
   EcManipulatorLinkIdentifier
      (
      EcU32 manipIndex,
      const EcString& linkId
      );

   /// less-than operator
   EcBoolean operator<
      (
      const EcManipulatorLinkIdentifier& orig
      ) const;

   /// register components
   void registerComponents
      (
      );

   /// get manipulator index
   EcU32 manipulatorIndex
      (
      ) const;

   /// set manipulator index
   void setManipulatorIndex
      (
      EcU32 value
      );

   /// get link string identifier
   const EcString& linkId
      (
      ) const;

   /// set link string identifier
   void setLinkId
      (
      const EcString& value
      );

   /// null object
   static EcManipulatorLinkIdentifier nullObject
      (
      );

protected:
   /// manipulator index
   EcXmlU32       m_ManipulatorIndex;

   /// link string identifier
   EcXmlString    m_LinkId;
};

/// a helper class containing a link index and its manipulator index
class EcManipulatorLinkIndex
{
public:
   /// default constructor
   EcManipulatorLinkIndex();

   /// constructor
   EcManipulatorLinkIndex
      (
      EcU32 manipIndex,
      EcU32 linkIndex
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorLinkIndex& orig
      ) const;

   /// less-than operator
   EcBoolean operator<
      (
      const EcManipulatorLinkIndex& orig
      ) const;

   /// get manipulator index
   EcU32 manipulatorIndex
      (
      ) const;

   /// set manipulator index
   void setManipulatorIndex
      (
      EcU32 value
      );

   /// get link index
   EcU32 linkIndex
      (
      ) const;

   /// set link index
   void setLinkIndex
      (
      EcU32 value
      );
protected:
   /// manipulator index
   EcU32    m_ManipulatorIndex;

   /// link index
   EcU32    m_LinkIndex;
};

#endif // ecManipulatorLinkIdentifier_H_
