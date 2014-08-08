#ifndef ecBaseOutputWriter_H_
#define ecBaseOutputWriter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseOutputWriter.h
/// @class EcBaseOutputWriter
/// @brief Holds a base class for writing output to files.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <iostream>
#include <xml/ecXmlCompType.h>

class EcBaseSystemDataComponent;
class EcSystemDataVector;

/** Holds a base class for streaming outputs (captured data) to files of different formats.
*/
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcBaseOutputWriter : public EcXmlCompoundType
{
public:
   // returns the token for this class
   virtual const EcToken& token
      (
      ) const = 0;

   /// return the descriptor of the file format. For example, "MATLAB", "Plain Text", "Mathematica", etc.
   virtual const EcString& formatDescriptor
      (
      ) const = 0;

   /// return the file extension of the format that this writer is writing in. For example, ".m" for MATLAB or ".txt" for plain text.
   virtual const EcString& fileExtension
      (
      ) const = 0;

   /// open file
   virtual void openFile
      (
      const EcString& fileName,
      std::ofstream& stream
      ) = 0;

   /// initialize the writer if necessary
   virtual void initialize
      (
      const EcSystemDataVector& dataVector,
      std::ostream& stream
      ) = 0;

   /// finalize the writer if necessary
   virtual void finalize
      (
      const EcSystemDataVector& dataVector,
      std::ostream& stream
      ) = 0;

   /// write the opening of a data component to an output stream
   /**
   \param[in] component The data component.
   \param[out] stream The output stream.
   */
   virtual void writeComponentOpening
      (
      const EcBaseSystemDataComponent& component,
      std::ostream& stream
      ) const = 0;

   /// write a data component to an output stream
   /**
   \param[in] component The data component.
   \param[out] stream The output stream.
   */
   virtual void writeDataComponent
      (
      const EcBaseSystemDataComponent& component,
      std::ostream& stream
      ) const = 0;

   /// write the closing of a data component to an output stream
   /**
   \param[in] component The data component.
   \param[out] stream The output stream.
   */
   virtual void writeComponentClosing
      (
      const EcBaseSystemDataComponent& component,
      std::ostream& stream
      ) const = 0;
};

#endif // ecBaseOutputWriter_H_
