#ifndef ecEndEffectorDataCapture_H_
#define ecEndEffectorDataCapture_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecEndEffectorDataCapture.h
/// @class EcEndEffectorDataCapture
/// @brief A base class used for configuring capture of end-effector data.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecDataCaptureTypeVector.h"

/**
\class EcEndEffectorDataCapture
\author Chalongrath Pholsiri
\brief This is a base class for collecting end-effector data such as placements, velocities, etc.
*/
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcEndEffectorDataCapture : public EcXmlCompoundType
{
public:
   /// default constructor
   EcEndEffectorDataCapture
      (
      );

   /// destructor
   virtual ~EcEndEffectorDataCapture
      (
      );

   /// copy constructor
   EcEndEffectorDataCapture
      (
      const EcEndEffectorDataCapture& orig
      );

   /// assignment operator
   EcEndEffectorDataCapture& operator=
      (
      const EcEndEffectorDataCapture& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcEndEffectorDataCapture& orig
      ) const;

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

   /// get the end-effector index
   EcU32 endEffectorIndex
      (
      ) const;

   /// get the end-effector index
   virtual void setEndEffectorIndex
      (
      EcU32 index
      );

   /// get the end-effector-level data capture vector
   virtual const EcDataCaptureTypeVector& dataCaptureVector
      (
      ) const;

   /// capture the data
   virtual EcBoolean captureData
      (
      const EcSystemSimulation& simulation,
      const EcU32&      manipIndex
      ) const;

   /// return a pointer to the data capture type given a token. If token is not found, EcNULL is returned.
   virtual const EcDataCaptureType* dataCaptureType
      (
      const EcToken& token
      ) const;

   /// add a data capture type to this end-effector
   /**
   \param[in] token The token of the data capture type to be added.
   \return False if token is invalid or if the data capture type is not of a link type. Otherwise, return true.
   */
   virtual EcBoolean addDataCaptureType
      (
      const EcToken& token
      );

   /// add a data capture type to this end-effector
   /**
   \param[in] dataType The data capture type to be added.
   \return False if token is invalid or if the data capture type is not of a link type. Otherwise, return true.
   */
   virtual EcBoolean addDataCaptureType
      (
      const EcDataCaptureType& dataType
      );

   /// remove a data capture type from this end-effector
   /**
   \param[in] token The token of the data capture type to be removed.
   \return False if token is invalid or if the data capture type of the given token does belong to this link. Otherwise, return true.
   */
   virtual EcBoolean removeDataCaptureType
      (
      const EcToken& token
      );

   /// Return whether or not the data capture type as given by the token is included in this link.
   /**
   \param[in] token The token of the data capture type being queried.
   \return True if the data capture type is included in this link or false otherwise.
   */
   virtual EcBoolean isDataCaptureTypeIncluded
      (
      const EcToken& token
      ) const;

   /// return the number of data capture types included in this link.
   virtual EcU32 numDataCaptureTypes
      (
      ) const;

   /// set the disable flags of a link data capture type.
   /**
   \param[in] token The token of the data capture type to which the disable flags will be set.
   \param[in] disableFlags A vector of booleans containing the disable flags to be set.
   \return True if the data capture type is included in this link or false otherwise.
   */
   virtual EcBoolean setDisableFlags
      (
      const EcToken& token,
      const EcXmlBooleanVector& disableFlags
      );

   /// remove all the data capture types
   virtual void removeAllDataCaptureTypes
      (
      );

   /// return a vector of all available data capture types
   static const EcDataCaptureTypeVector& allAvailableDataCaptureTypes
      (
      );

   const EcToken& token
      (
      ) const;

protected:
   /// the index of the end-effector
   EcXmlU32       m_EndEffectorIndex;

   /// a vector containing the types of data to be captured for this link
   EcDataCaptureTypeVector    m_vDataCapture;

   // non-XML data
   /// flag indicating whether or not the vector of all available data types is ready
   static EcBoolean           m_theAvailableTypesReady;

   /// vector of all available data capture types
   static EcDataCaptureTypeVector      m_theAvailableDataCaptureTypeVector;
};

/// type definition of EcEndEffectorDataCaptureVector
typedef EcXmlVectorType<EcEndEffectorDataCapture> EcEndEffectorDataCaptureVector;

#endif // ecEndEffectorDataCapture_H_
