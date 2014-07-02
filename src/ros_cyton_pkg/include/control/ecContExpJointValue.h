#ifndef ecContExpJointValue_H_
#define ecContExpJointValue_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpJointValue.h
/// @class EcControlExpressionJointValue
/// @brief An element of an expression tree.
///        Holds a joint value (a scalar constant).
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"

class EcExpressionContainer;

/// An element of an expression tree.  Holds a joint value.
class EC_ACTIN_CONTROL_DECL EcControlExpressionJointValue : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionJointValue
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcControlExpressionJointValue
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionJointValue
      (
      );

   /// copy constructor
   EcControlExpressionJointValue
      (
      const EcControlExpressionJointValue& orig
      );

   /// assignment operator
   EcControlExpressionJointValue& operator=
      (
      const EcControlExpressionJointValue& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionJointValue& orig
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

   /// return the joint value
   /// @return (EcVelocityControlData&) the velocity control data
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// gets the manipulator index
   /// @return (EcU32) the manipulator index
   virtual const EcU32 manipulatorIndex
      (
      ) const;

   /// sets the manipulator index
   /// @param[in] index (EcU32) value to set
   virtual void setManipulatorIndex
      (
      const EcU32 index
      );

   /// gets the joint index
   /// @return (EcU32) Index of the joint
   virtual const EcU32 jointIndex
      (
      ) const;

   /// sets the joint index
   /// @param[in] index (EcU32) Value to set the joint
   virtual void setJointIndex
      (
      const EcU32 index
      );

   /// return a token
   /// @return (EcToken&) the xml token
   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   /// @param[in] stream (EcXmlReader&) stream to be read from xml file
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   /// @param[in] stream (EcXmlWriter&) stream to be written into xml file
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   /// @return (EcControlExpressionJointValue) The nul object
   static EcControlExpressionJointValue nullObject
      (
      );

   /// token for this class
   /// @return (EcToken&) The class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The xml object
   static EcXmlObject* creator
      (
      );

protected:
   /// the manipulator index
   EcXmlU32        m_ManipulatorIndex;
   /// the joint index
   EcXmlU32        m_JointIndex;
};

#endif // ecContExpJointValue_H_
