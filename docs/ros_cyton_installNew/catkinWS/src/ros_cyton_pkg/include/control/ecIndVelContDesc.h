#ifndef ecIndVelContDesc_H_
#define ecIndVelContDesc_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecIndVelContDesc.h
/// @class EcIndividualVelocityControlDescription
/// @brief Holds a description of a velocity control system for an
///        individual manipulator.  This includes a control expression and a
///        corresponding end-effector set.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecContExpContainer.h"
#include "ecEndEffectorSet.h"
#include <manipulator/ecJacobianState.h>
#include <xml/ecXmlCompType.h>

class EcIndividualManipulator;

/// Holds a description of a velocity control system for an individual manipulator.
/** This includes a control expression and a corresponding end-effector set.
*/
class EC_ACTIN_CONTROL_DECL EcIndividualVelocityControlDescription : public EcXmlCompoundType
{
public:
   /// default constructor
   EcIndividualVelocityControlDescription
      (
      );

   /// destructor
   virtual ~EcIndividualVelocityControlDescription
      (
      );

   /// copy constructor
   EcIndividualVelocityControlDescription
      (
      const EcIndividualVelocityControlDescription& orig
      );

   /// assignment operator
   EcIndividualVelocityControlDescription& operator=
      (
      const EcIndividualVelocityControlDescription& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcIndividualVelocityControlDescription& orig
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

   /// gets the label
   virtual const EcXmlString& label
      (
      ) const;

   /// sets the label
   virtual void setLabel
      (
      const EcXmlString& label
      );

   /// gets the control expression - const version
   virtual const EcControlExpressionContainer& controlExpression
      (
      ) const;

   /// gets the control expression - nonconst version
   virtual EcControlExpressionContainer& controlExpression
      (
      );

   /// sets the control expression
   virtual void setControlExpression
      (
      const EcControlExpressionContainer& controlExpression
      );

   /// gets the data-map pointer
   const EcDataMap* dataMapPointer
      (
      ) const;

   /// sets the data-map pointer for a specified manipulator
   void setDataMapPointer
      (
      const EcDataMap* pDataMap
      );

   /// gets the end-effector set
   virtual const EcEndEffectorSet& endEffectorSet
      (
      ) const;

   /// non const gets the end-effector set
   virtual EcEndEffectorSet& endEffectorSet
      (
      );

   /// sets the end-effector set
   virtual void setEndEffectorSet
      (
      const EcEndEffectorSet& endEffectorSet
      );

   /// gets the is-on flag
   virtual EcBoolean isOn
      (
      ) const;

   /// sets the is-on flag
   virtual void setIsOn
      (
      EcBoolean isOn
      );

   /// gets the is-floating-base flag
   virtual EcBoolean isFixedBase
      (
      ) const;

   /// sets the is-floating-base flag
   virtual void setIsFixedBase
      (
      EcBoolean isFixedBase
      );

   /// sets relative link data
   virtual EcBoolean setRelativeLinkData
      (
      EcU32 endEffectorIndex,
      const EcEndEffectorRelativeLinkData& relData
      );

   /// gets relative link data
   virtual const EcEndEffectorRelativeLinkData& relativeLinkData
      (
      EcU32 endEffectorIndex
      ) const;

   /// return the calculated value
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// the Jacobian state used for control calculations for this control description
   virtual EcJacobianState& jacobianState
      (
      ) const;

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

   /// get a null object
   static EcIndividualVelocityControlDescription nullObject
      (
      );

   /// create a default control description from a manipulator
   static EcIndividualVelocityControlDescription createDefaultFromManipulator
      (
      const EcIndividualManipulator& manipulator
      );

protected:

   /// the label
   EcXmlString                           m_Label;

   /// the control expression
   EcControlExpressionContainer          m_ControlExpression;

   /// the end-effector description
   EcEndEffectorSet                      m_EndEffectorSet;

   /// an on-off flag
   EcXmlBoolean                          m_IsOn;

   /// a flag indicating floating-base control
   EcXmlBoolean                          m_IsFixedBase;

   // non-XML data below
   mutable EcJacobianState               m_JacobianState;   ///< the Jacobian state

   /// velocity control data that is zero-valued and of the correct size
   mutable EcVelocityControlData         m_ZeroValue;     
};

/// a vector of individual velocity control descriptions
typedef EcXmlVectorType<EcIndividualVelocityControlDescription>
   EcVelocityControlDescriptionVector;

/// a vector of vectors of individual velocity control descriptions
typedef EcXmlVectorType<EcVelocityControlDescriptionVector>
   EcVelocityControlDescriptionVectorVector;

#endif // ecIndVelContDesc_H_
