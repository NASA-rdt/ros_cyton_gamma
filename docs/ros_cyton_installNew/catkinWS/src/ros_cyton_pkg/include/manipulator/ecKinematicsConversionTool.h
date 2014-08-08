#ifndef ecKinematicsConversionTool_H_
#define ecKinematicsConversionTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecKinematicsConversionTool.h
/// @class EcKinematicsConversionTool
/// @brief Convert manipulators and systems to alternative, equivalent
///        representations.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include "ecStatedSystem.h"

class EC_FOUNDATION_MANIPULATOR_DECL EcKinematicsConversionTool  : public EcXmlCompoundType
{
public:
   /// constructor
   EcKinematicsConversionTool
      (
      );

   /// destructor
   virtual ~EcKinematicsConversionTool
      (
      );

   /// copy constructor
   EcKinematicsConversionTool
      (
      const EcKinematicsConversionTool& orig
      );

   /// assignment operator
   EcKinematicsConversionTool& operator=
      (
      const EcKinematicsConversionTool& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcKinematicsConversionTool& orig
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

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

   /// convert kinematic form to Craig's DH
   virtual EcBoolean convertManipulatorToCraigsDhForm
      (
      const EcStatedSystem& inputStatedSystem,
      EcStatedSystem& outputStatedSystem,
      EcU32 manipulatorIndex
      ) const;

   /// convert kinematic form to pure Craig's DH for serial arms
   virtual EcBoolean convertSerialManipulatorToCraigsDhForm
      (
      const EcStatedSystem& inputStatedSystem,
      EcStatedSystem& outputStatedSystem,
      EcU32 manipulatorIndex
      ) const;

   /// convert kinematic form to Craig's DH for bifurcating arms
   /// At each bifurcation, precursors are introduced for those
   /// links beyond the first one.
   virtual EcBoolean convertBifurcatingManipulatorToCraigsDhForm
      (
      const EcStatedSystem& inputStatedSystem,
      EcStatedSystem& outputStatedSystem,
      EcU32 manipulatorIndex
      ) const;

   /// convert a link in a bifurcating manipulator and all its children to Craig's DH form
   virtual EcBoolean convertBifurcatingLinkAndChildrenToCraigsDhForm
      (
      EcStatedSystem& statedSystem,
      EcU32 manipulatorIndex,
      EcU32 linkIndex,
      const EcCoordinateSystemTransformation& preTransform,
      EcBoolean isFirstChild
      ) const;

   /// convert kinematic form to pure Craig's DH for all-rotational serial arms
   /// includes extra constraints on the DH parameters
   virtual EcBoolean convertManipulatorToCraigsDhForm
      (
      const EcStatedSystem& inputStatedSystem,
      EcStatedSystem& outputStatedSystem,
      EcU32 manipulatorIndex,
      const EcBooleanVector& alphaPositives,
      const EcBooleanVector& dPositives,
      const EcRealVector& firstAndLastDValues,
      const EcRealVector& firstAndLastThetaLowerBound,
      const EcReal* pFirstA,
      const EcReal* pFirstAlpha
      ) const;

   /// recenter the joint limits if rotational
   /// the closest offset by 2Pi is used
   virtual EcBoolean recenterJointLimits
      (
      EcStatedSystem& statedSystem,
      EcU32 manipulatorIndex,
      const EcRealVector& jointCenters
      ) const;

   /// set all primary frames to identity
   virtual EcBoolean reconfigureForIdentityPrimaryFrames
      (
      EcStatedSystem& statedSystem,
      EcU32 manipulatorIndex
      ) const;

   protected:

};

#endif // ecKinematicsConversionTool_H_
