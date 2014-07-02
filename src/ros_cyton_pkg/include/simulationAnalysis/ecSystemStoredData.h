#ifndef ecSystemStoredData_H_
#define ecSystemStoredData_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemStoredData.h
/// @brief A class used to manage data storage
/// @details EcViewerStoredData
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "simulationAnalysis/ecOutputWriterVector.h"
#include "simulationAnalysis/ecSystemDataVector.h"

#include <fstream>

class EcSystemDataCapture;
class EcOutputWriterVector;

/// A class used to manage data storage
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcSystemStoredData
{
public:
   /// declaration of the FIGFOUR: constructor, destructor, assignment operator and equality operator 
   ECDECLARE_BIGFOUR(EcSystemStoredData);

   /// set the vector of output writers
   void setOutputWriterVector
      (
      const EcOutputWriterVector& writerVector
      );

   /// allocate enough memory for the internal data storage
   /**
   \param[in] dataCapture An EcSystemDataCapture object that contains the configuration of which data to capture.
   */
   void allocateStorage
      (
      const EcSystemDataCapture& dataCapture
      );

   /// Open a file that will be used to write the captured data and initialize the save to file.
   /**
   \param[in] fileName The name of the file to which the captured data will be written.
   */
   void beginSaveToFile
      (
      const EcString& fileName
      );

   /// This method must be called after all the data is written to the file to finalize the save to file process and close the file.
   void finishSaveToFile
      (
      );

   /// Save a set of captured data by appending it to the open file.
   /**
   \param[in] time The timestamp of the set of captured data.
   \param[in] dataCapture An EcSystemDataCapture object that contains the captured data to be written.
   */
   void saveCapturedData
      (
      EcReal time,
      const EcSystemDataCapture& dataCapture
      );

   /// Save a set of captured data by appending it to the open file.
   /**
   \param[in] time The timestamp of the set of captured data.
   \param[in] pathPointIndex The index of the point in the path.
   \param[in] dataCapture An EcSystemDataCapture object that contains the captured data to be written.
   */
   void saveCapturedData
      (
      EcReal time,
      EcU32 pathPointIndex,
      const EcSystemDataCapture& dataCapture
      );

   /// Return true if the saving process is ongoing or false otherwise.
   EcBoolean isSaving
      (
      ) const
   { return m_IsSaving; }

protected:
   /// Data object. It's used to write the data to a file.
   EcSystemDataVector            m_DataVector;

   /// the vector of output writers
   EcOutputWriterVector          m_WriterVector;

   /// A vector of internal output file streams.
   std::vector<std::ofstream*>   m_vpStreams;

   /// A flag indicating whether or not the save to file process is ongoing.
   EcBoolean                     m_IsSaving;
};

#endif // ecSystemStoredData_H_
