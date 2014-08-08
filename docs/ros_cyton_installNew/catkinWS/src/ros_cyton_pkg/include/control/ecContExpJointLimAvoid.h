#ifndef ecContExpJointLimAvoid_H_
#define ecContExpJointLimAvoid_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpJointLimAvoid.h
/// @class EcControlExpressionJointLimitAvoidance
/// @brief This expression returns a vector that will drive
///        joints away from limits.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"
#include "ecExpContainer.h"

/// This expression returns a vector that will drive joints away from limits.
class EC_ACTIN_CONTROL_DECL EcControlExpressionJointLimitAvoidance : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionJointLimitAvoidance
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcControlExpressionJointLimitAvoidance
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionJointLimitAvoidance
      (
      );

   /// copy constructor
   EcControlExpressionJointLimitAvoidance
      (
      const EcControlExpressionJointLimitAvoidance& orig
      );

   /// assignment operator
   EcControlExpressionJointLimitAvoidance& operator=
      (
      const EcControlExpressionJointLimitAvoidance& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionJointLimitAvoidance& orig
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

   /// return the value
   /// @return (EcVelocityControlData&) the velocity control data
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// return a token
   /// @return The xml token
   virtual const EcToken& token
      (
      ) const;

   /// gets the exponent
   /// @return (EcReal) The exponent value
   virtual EcReal exponent
      (
      ) const;

   /// sets the exponent
   /// @param[in] exponent   (EcReal) value to set, (Must be between 0 and 1 inclusive)
   virtual void setExponent
      (
      EcReal exponent
      );

   /// gets the avoidance zone
   /// @return (EcReal) The avoidance region, TODO, radius?
   virtual EcReal avoidanceZone
      (
      ) const;

   /// sets the avoidance zone
   /// @param[in] avoidanceZone (EcReal) value to set
   virtual void setAvoidanceZone
      (
      EcReal avoidanceZone
      );

   /// get the flag indicating that the stopper zone is computed as a fraction of the overall joint limits
   /// @return The flag indicating the stopper zone
   virtual const EcBoolean& fractional
      (
      )const;

   /// set the flag indicating that the stopper zone is computed as a fraction of the overall joint limits
   /// @param[in] value (EcBoolean&) set flag indicating the stopper zone
   virtual void setFractional
      (
      const EcBoolean& value
      );

   /// gets the maximum
   /// @return The maximum value, this occurs when the joint is at a limit
   virtual EcReal maximum
      (
      ) const;

   /// sets the maximum
   /// @param[in] maximum TODO
   virtual void setMaximum
      (
      EcReal maximum
      );

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
   /// @return The control expression joint constraint avoidance null object
   static EcControlExpressionJointLimitAvoidance nullObject
      (
      );

   /// standard object
   ///@return The default object
   static EcControlExpressionJointLimitAvoidance defaultObject
      (
      );

   /// token for this class
   /// @return The class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The xml object creator
   static EcXmlObject* creator
      (
      );

protected:
   /// the exponent of a polynomial function
   EcXmlReal                       m_Exponent;

   /// the zone in which to avoid a limit
   EcXmlReal                       m_AvoidanceZone;

   /// the maximum value of any entry.  This occurs when the joint is at a limit
   EcXmlReal                       m_Maximum;

   /// flag indicating that the stopper zone is computed as a fraction of the overall joint limits
   EcXmlBoolean                    m_Fractional;
};

#endif // ecContExpJointLimAvoid_H_
