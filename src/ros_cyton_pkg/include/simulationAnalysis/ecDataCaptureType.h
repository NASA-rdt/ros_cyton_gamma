#ifndef ecDataCaptureType_H_
#define ecDataCaptureType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecDataCaptureType.h
/// @class EcDataCaptureType
/// @brief An abstract base class for capturing and storing the data.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

class EcSystemSimulation;

/**
\class EcDataCaptureType
\author Chalongrath Pholsiri
\brief An abstract base class for capturing and storing the data.

To capture a specific piece of data, a new class must be derived from this class and implement all the pure virtual functions.
*/
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcDataCaptureType : public EcXmlCompoundType
{
public:
   enum
   {
      MANIPULATOR_DATA_TYPE,
      LINK_DATA_TYPE,
      END_EFFECTOR_DATA_TYPE
   };

   /// default constructor
   EcDataCaptureType
      (
      );

   /// destructor
   virtual ~EcDataCaptureType
      (
      );

   /// copy constructor
   EcDataCaptureType
      (
      const EcDataCaptureType& orig
      );

   /// assignment operator
   EcDataCaptureType& operator=
      (
      const EcDataCaptureType& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDataCaptureType& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets the disable flags
   virtual const EcXmlBooleanVector& disableFlags
      (
      ) const;

   /// sets the disable flags
   virtual void setDisableFlags
      (
      const EcXmlBooleanVector& disableFlags
      );

   /// return the description of data at a given index
   virtual const EcString& label
      (
      const EcU32& index
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const=0;

   /// return a description. This is more human-readable than the token and should be used in GUI in place of the token.
   virtual const EcString& description
      (
      ) const=0;

   /// capture the data
   /**
   \param[in] simulation The simulation from which the data will be captured.
   \param[in] manipIndex The index of the manipulator from which the data will be captured.
   \param[in] minorIndex The minor index of the data to be captured. This can be either a link index or an end-effector index, depending on the type of the data capture.
   */
   virtual EcBoolean captureData
      (
      const EcSystemSimulation& simulation,
      const EcU32&      manipIndex,
      const EcU32&      minorIndex
      ) const=0;

   /// return the data size.  This will match the number of labels
   virtual const EcU32 dataSize
      (
      ) const=0;

   /// return the number of active data elements (i.e. ones that are not disabled through the disable flags).
   virtual const EcU32 activeDataSize
      (
      ) const;

   /// returns a type
   virtual EcU32 type
      (
      ) const=0;

   /// return the captured data
   virtual const EcXmlRealVector& data
      (
      ) const;

protected:
   /// XML data
   /// disable flags
   EcXmlBooleanVector   m_DisableFlags;

   /// descriptions for the elements
   EcXmlStringVector    m_Labels;

   /// non-XML data below

   /// a vector containing the captured data
   mutable EcXmlRealVector   m_Data;

   /// an empty string
   EcString             m_EmptyString;
};

#endif // ecDataCaptureType_H_
