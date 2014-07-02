#ifndef ecDirectorObject_H_
#define ecDirectorObject_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecDirectorObject.h
/// @class EcDirectorObject
/// @brief Virtual base class for manipulation director objects.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <xml/ecBaseExpTreeElement.h>

// Forward declarations
class EcManipulationAction;
class EcManipulationScene;
class EcManipulationSceneDirection;

/// Virtual base class for manipulation director objects.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcDirectorObject : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcDirectorObject
      (
      );

   /// destructor
   virtual ~EcDirectorObject
      (
      );

   /// copy constructor
   EcDirectorObject
      (
      const EcDirectorObject& orig
      );

   /// assignment operator
   EcDirectorObject& operator=
      (
      const EcDirectorObject& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDirectorObject& orig
      ) const;

   virtual const EcManipulationAction* action
      (
      ) const = 0;

   virtual const EcManipulationSceneDirection* direction
      (
      ) const = 0;

   virtual const EcManipulationScene* scene
      (
      ) const = 0;
};

#endif // ecDirectorObject_H_
