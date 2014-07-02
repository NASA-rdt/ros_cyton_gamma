#ifndef ecJointLimitDisplayParameters_H_
#define ecJointLimitDisplayParameters_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecJointLimitDisplayParameters.h
/// @class EcJointLimitDisplayParameters
/// @brief display option parameters for joint limits
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecDisplayOptionsParameters.h"

/// Display option parameters for joint limits
class EC_FOUNDATION_VISUALIZATION_DECL EcJointLimitDisplayParameters : public EcDisplayOptionsParameters
{
public:
   /// constructor
   EcJointLimitDisplayParameters();

   /// destructor
   virtual ~EcJointLimitDisplayParameters();

   /// copy constructor
   EcJointLimitDisplayParameters
      (
      const EcJointLimitDisplayParameters& orig
      );

   /// assignment operator
   EcJointLimitDisplayParameters& operator=
      (
      const EcJointLimitDisplayParameters& orig
      );

   /// equal operator
   EcBoolean operator==
      (
      const EcJointLimitDisplayParameters& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
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

   /// get a null point end effector
   static EcJointLimitDisplayParameters nullObject
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

   /// get set functions
   /// get tolerance
   virtual const EcXmlReal& tolerance
      (
      ) const;

   /// set tolerance
   virtual void setTolerance
      (
      const EcXmlReal& tolerance
      );

protected:
   /// trigger alarm when joint limit is within tolerance
   EcXmlReal            m_Tolerance;
};

#endif // ecJointLimitDisplayParameters_H_
