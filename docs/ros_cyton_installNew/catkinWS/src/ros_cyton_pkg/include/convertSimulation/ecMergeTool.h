#ifndef ecMergeTool_H_
#define ecMergeTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecMergeTool.h
/// @class EcMergeTool
/// @brief Provides a tool for merging multiple XML files.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

/// Provides a tool for merging multiple XML files.
class EC_ACTIN_CONVERTSIMULATION_DECL EcMergeTool
{
public:
   /// default constructor
   EcMergeTool
      (
      );

   /// destructor
   virtual ~EcMergeTool
      (
      );

   /// copy constructor
   EcMergeTool
      (
      const EcMergeTool& orig
      );

   /// assignment operator
   EcMergeTool& operator=
      (
      const EcMergeTool& orig
      );

   /// merge files
   /**
   \param[in] arguments argument list that defines files to merge
   \retval error status
   */
   EcBoolean merge
      (
      const EcStringVector& arguments
      );

   /// get a null object
   /**
   \retval merge tool
   */
   static EcMergeTool nullObject
      (
      );
};

#endif // ecMergeTool_H_
