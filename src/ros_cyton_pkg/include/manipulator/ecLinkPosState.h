#ifndef ecLinkPosState_H_
#define ecLinkPosState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkPosState.h
/// @class EcLinkPositionState
/// @brief Holds the state of a single manipulator link.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecCoordSysXForm.h>
#include <xml/ecXmlCompType.h>

/// Holds the state of a single manipulator link.
class EC_FOUNDATION_MANIPULATOR_DECL EcLinkPositionState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcLinkPositionState
      (
      );

   /// destructor
   virtual ~EcLinkPositionState
      (
      );

   /// copy constructor
   EcLinkPositionState
      (
      const EcLinkPositionState& orig
      );

   /// assignment operator
   EcLinkPositionState& operator=
      (
      const EcLinkPositionState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinkPositionState& orig
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

   /// gets the Denavit-Hartenberg Frame
   virtual const EcCoordinateSystemTransformation& dhFrame
      (
      ) const;

   /// sets the Denavit-Hartenberg Frame
   virtual void setDhFrame
      (
      const EcCoordinateSystemTransformation& dhFrame
      );

   /// gets the Primary Frame
   virtual const EcCoordinateSystemTransformation& primaryFrame
      (
      ) const;

   /// sets the Primary Frame
   virtual void setPrimaryFrame
      (
      const EcCoordinateSystemTransformation& primaryFrame
      );

   /// gets the D-H Transform
   virtual const EcCoordinateSystemTransformation& dhTransform
      (
      ) const;

   /// sets the D-H Transform
   virtual void setDhTransform
      (
      const EcCoordinateSystemTransformation& dhTransform
      );

   /// gets the in-system validity flag
   virtual EcBoolean locationInSystemValid
      (
      ) const;

   /// sets the validity flag
   virtual void setLocationInSystemValid
      (
      EcBoolean valid=EcTrue
      );

   /// gets the DH transform validity flag
   virtual EcBoolean dhTransformValid
      (
      ) const;

   /// sets the validity flag
   virtual void setDhTransformValid
      (
      EcBoolean valid=EcTrue
      );

   /// invalidates all values
   virtual void invalidateAll
      (
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

   /// get a null object
   static EcLinkPositionState nullObject
      (
      );

protected:

   /// the dh frame for the link in system coordinates
   EcCoordinateSystemTransformation m_DhFrame;

   /// the primary frame for the link in system coordinates
   EcCoordinateSystemTransformation m_PrimaryFrame;

   /// the link D-H transformation
   EcCoordinateSystemTransformation m_DhTransform;

   /// location-in-system validity flag
   EcXmlBoolean                     m_LocationInSystemValid;

   /// D-H transform validity flag
   EcXmlBoolean                     m_DhTransformValid;
};

/// a vector of position states
typedef EcXmlVectorType<EcLinkPositionState> EcLinkPositionStateVector;

#endif // ecLinkPosState_H_
