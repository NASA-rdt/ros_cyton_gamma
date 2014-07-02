#ifndef ecManipDataCapture_H_
#define ecManipDataCapture_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipDataCapture.h
/// @class EcManipulatorDataCapture
/// @brief A base class used for configuration data capture of manipulator data.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecEndEffectorDataCapture.h"
#include "ecLinkDataCapture.h"

class EcIndividualManipulator;

class EC_ACTIN_SIMULATIONANALYSIS_DECL EcManipulatorDataCapture : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorDataCapture
      (
      );

   /// destructor
   virtual ~EcManipulatorDataCapture
      (
      );

   /// copy constructor
   EcManipulatorDataCapture
      (
      const EcManipulatorDataCapture& orig
      );

   /// assignment operator
   EcManipulatorDataCapture& operator=
      (
      const EcManipulatorDataCapture& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorDataCapture& orig
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

   /// get the manipulator index
   virtual EcU32 manipulatorIndex
      (
      ) const;

   /// set the manipulator index
   virtual void setManipulatorIndex
      (
      const EcU32& manipIndex
      );

   /// get the manipulator-level data capture vector
   virtual const EcDataCaptureTypeVector& dataCaptureVector
      (
      ) const;

   /// get the link data capture vector
   virtual const EcLinkDataCaptureVector& linkDataCaptureVector
      (
      ) const;

   /// get the EE data capture vector
   virtual const EcEndEffectorDataCaptureVector& endEffectorDataCaptureVector
      (
      ) const;

   /// capture the data
   virtual EcBoolean captureData
      (
      const EcSystemSimulation& simulation
      ) const;

   /// return a pointer to the data capture type given a token. If token is not found, EcNULL is returned.
   virtual const EcDataCaptureType* dataCaptureType
      (
      const EcToken& token
      ) const;

   /// add a data capture type to this manipulator
   /**
   \param[in] token The token of the data capture type to be added.
   \return False if token is invalid or if the data capture type is not of a manipulator type. Otherwise, return true.
   */
   virtual EcBoolean addDataCaptureType
      (
      const EcToken& token
      );

   /// add a data capture type to all links of this manipulator.
   /**
   \param[in] token The token of the data capture type to be added.
   \param[in] manip The manipulator object. Needed to ensure that all links of the manipulator are accounted for.
   \return False if token is invalid or if the data capture type is not of a link type. Otherwise, return true.
   */
   virtual EcBoolean addLinkDataCaptureType
      (
      const EcToken& token,
      const EcIndividualManipulator& manip
      );

   /// add a data capture type to a link of this manipulator
   /**
   \param[in] linkId The identifying label of the link to which the data capture type will be added.
   \param[in] token The token of the data capture type to be added.
   \return False if token is invalid or if the data capture type is not of a link type. Otherwise, return true.
   */
   virtual EcBoolean addLinkDataCaptureType
      (
      const EcString& linkId,
      const EcToken& token
      );

   /// add a data capture type to all EEs of this manipulator.
   /**
   \param[in] token The token of the data capture type to be added.
   \param[in] numEndEffectors The total number of end-effectors of this manipulator.
   \return False if token is invalid or if the data capture type is not of a EE type. Otherwise, return true.
   */
   virtual EcBoolean addEndEffectorDataCaptureType
      (
      const EcToken& token,
      EcU32 numEndEffectors
      );

   /// add a data capture type to all EEs of this manipulator.
   /**
   \param[in] dataType The data capture type to be added.
   \param[in] numEndEffectors The total number of end-effectors of this manipulator.
   \return False if token is invalid or if the data capture type is not of a EE type. Otherwise, return true.
   */
   virtual EcBoolean addEndEffectorDataCaptureType
      (
      const EcDataCaptureType& dataType,
      EcU32 numEndEffectors
      );

   /// add a data capture type to an end-effector of this manipulator
   /**
   \param[in] eeIndex The index of the end-effector to which the data capture type will be added.
   \param[in] token The token of the data capture type to be added.
   \return False if token is invalid or if the data capture type is not of a end-effector type. Otherwise, return true.
   */
   virtual EcBoolean addEndEffectorDataCaptureType
      (
      EcU32 eeIndex,
      const EcToken& token
      );

   /// add a data capture type to an end-effector of this manipulator
   /**
   \param[in] eeIndex The index of the EE to which the data capture type will be added.
   \param[in] dataType The data capture type to be added.
   \return False if the data capture type is not of an EE type. Otherwise, return true.
   */
   virtual EcBoolean addEndEffectorDataCaptureType
      (
      EcU32 eeIndex,
      const EcDataCaptureType& dataType
      );

   /// remove a data capture type from this manipulator
   /**
   \param[in] token The token of the data capture type to be removed.
   \return False if token is invalid or if the data capture type of the given token does belong to this manipulator. Otherwise, return true.
   */
   virtual EcBoolean removeDataCaptureType
      (
      const EcToken& token
      );

   /// remove a data capture type from all links in this manipulator
   /**
   \param[in] token The token of the data capture type to be removed.
   \return False if token is invalid or if the data capture type of the given token does not belong to any of the links. Otherwise, return true.
   */
   virtual EcBoolean removeLinkDataCaptureType
      (
      const EcToken& token
      );

   /// remove a data capture type from all end-effectors in this manipulator
   /**
   \param[in] token The token of the data capture type to be removed.
   \return False if token is invalid or if the data capture type of the given token does belong to any of the end-effectors. Otherwise, return true.
   */
   virtual EcBoolean removeEndEffectorDataCaptureType
      (
      const EcToken& token
      );

   /// remove a data capture type from a link in this manipulator
   /**
   \param[in] token The token of the data capture type to be removed.
   \param[in] linkId The identifying label of the link from which the data capture type will be removed.
   \return False if token is invalid or if the data capture type of the given token does belong to this link. Otherwise, return true.
   */
   virtual EcBoolean removeLinkDataCaptureType
      (
      const EcString& linkId,
      const EcToken& token
      );

   /// remove a data capture type from an end-effector in this manipulator
   /**
   \param[in] token The token of the data capture type to be removed.
   \param[in] eeIndex The index of the end-effector from which the data capture type will be removed.
   \return False if token is invalid or if the data capture type of the given token does belong to this end-effector. Otherwise, return true.
   */
   virtual EcBoolean removeEndEffectorDataCaptureType
      (
      EcU32 eeIndex,
      const EcToken& token
      );

   /// add a link data capture object
   virtual void addLinkDataCapture
      (
      const EcLinkDataCapture& linkDataCapture
      );

   /// return a pointer to the link data capture of a given link identifying label. If linkId is not found, EcNULL is returned.
   virtual const EcLinkDataCapture* linkDataCapture
      (
      const EcString& linkId
      ) const;

   /// add an end-effector data capture object
   virtual void addEndEffectorDataCapture
      (
      const EcEndEffectorDataCapture& endEffectorDataCapture
      );

   /// return a pointer to the end-effector data capture of a given index. If eeIndex is not found, EcNULL is returned.
   virtual const EcEndEffectorDataCapture* endEffectorDataCapture
      (
      EcU32 eeIndex
      ) const;

   /// remove a single link data capture object by link identifying label
   /**
   \param[in] linkId The identifying label of the link to be removed.
   \return False if linkId is not found or true otherwise
   */
   virtual EcBoolean removeLinkDataCapture
      (
      const EcString& linkId
      );

   /// remove a single end-effector data capture object by index
   /**
   \param[in] eeIndex The index of the end-effector to be removed.
   \return False if eeIndex is not found or true otherwise
   */
   virtual EcBoolean removeEndEffectorDataCapture
      (
      EcU32 eeIndex
      );

   /// Return whether or not the data capture type as given by the token is included in this manipulator.
   /**
   \param[in] token The token of the data capture type being queried.
   \return True if the data capture type is included in this manipulator or false otherwise.
   */
   virtual EcBoolean isDataCaptureTypeIncluded
      (
      const EcToken& token
      ) const;

   /// Return whether or not the data capture type as given by the token is included in a link of this manipulator.
   /**
   \param[in] linkId The identifying label of the link being queried.
   \param[in] token The token of the data capture type being queried.
   \return True if the data capture type is included in the link or false otherwise.
   */
   virtual EcBoolean isDataCaptureTypeIncluded
      (
      const EcString& linkId,
      const EcToken& token
      ) const;

   /// Return whether or not the data capture type as given by the token is included in an EE of this manipulator.
   /**
   \param[in] eeIndex The index of the EE being queried.
   \param[in] token The token of the data capture type being queried.
   \return True if the data capture type is included in the link or false otherwise.
   */
   virtual EcBoolean isDataCaptureTypeIncluded
      (
      EcU32 eeIndex,
      const EcToken& token
      ) const;

   /// return the number of data capture types included in this manipulator.
   virtual EcU32 numDataCaptureTypes
      (
      ) const;

   // return the number of data capture types included in a link of this manipulator.
   /**
   \param[in] linkId The identifying label of the link being queried.
   */
   virtual EcU32 numDataCaptureTypes
      (
      const EcString& linkId
      ) const;

   // return the number of data capture types included in an EE of this manipulator.
   /**
   \param[in] eeIndex The index of the EE being queried.
   */
   virtual EcU32 numDataCaptureTypes
      (
      EcU32 eeIndex
      ) const;

   /// set the disable flags of a manipulator data capture type.
   /**
   \param[in] token The token of the data capture type to which the disable flags will be set.
   \param[in] disableFlags A vector of booleans containing the disable flags to be set.
   \return True if the data capture type is included in this manipulator or false otherwise.
   */
   virtual EcBoolean setDisableFlags
      (
      const EcToken& token,
      const EcXmlBooleanVector& disableFlags
      );

   /// set the disable flags of a link data capture type.
   /**
   \param[in] linkId The identifying label of the link.
   \param[in] token The token of the data capture type to which the disable flags will be set.
   \param[in] disableFlags A vector of booleans containing the disable flags to be set.
   \return True if the data capture type is included in the link or false otherwise.
   */
   virtual EcBoolean setDisableFlags
      (
      const EcString& linkId,
      const EcToken& token,
      const EcXmlBooleanVector& disableFlags
      );

   /// set the disable flags of an EE data capture type.
   /**
   \param[in] eeIndex The index of the EE.
   \param[in] token The token of the data capture type to which the disable flags will be set.
   \param[in] disableFlags A vector of booleans containing the disable flags to be set.
   \return True if the data capture type is included in the link or false otherwise.
   */
   virtual EcBoolean setDisableFlags
      (
      EcU32 eeIndex,
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
   /// find the index in the internal link vector for a given link identifying label
   /**
   \param[in] linkId The link identifying label.
   \param[out] index The index in the link vector corresponding to linkId.
   \return True if linkId can be found or false otherwise.
   */
   virtual EcBoolean findIndex
      (
      const EcString& linkId,
      EcU32& index
      ) const;

   /// find the index in the internal EE vector for a given EE index
   /**
   \param[in] eeIndex The EE index.
   \param[out] index The index in the EE vector corresponding to eeIndex.
   \return True if eeIndex can be found or false otherwise.
   */
   virtual EcBoolean findIndex
      (
      EcU32 eeIndex,
      EcU32& index
      ) const;

protected:
   /// the manipulator index
   EcXmlU32    m_ManipulatorIndex;

   /// a vector containing the types of data to be captured for this manipulator
   EcDataCaptureTypeVector    m_vDataCapture;

   /// a vector containing the data capture of the links of this manipulator
   EcLinkDataCaptureVector    m_vLinkDataCapture;

   /// a vector containing the data capture of the end-effectors of this manipulator
   EcEndEffectorDataCaptureVector   m_vEndEffectorDataCapture;

   // non-XML data
   /// flag indicating whether or not the vector of all available data types is ready
   static EcBoolean           m_theAvailableTypesReady;

   /// vector of all available data capture types
   static EcDataCaptureTypeVector      m_theAvailableDataCaptureTypeVector;
};

/// type definition of EcManipulatorDataCaptureVector
typedef EcXmlVectorType<EcManipulatorDataCapture> EcManipulatorDataCaptureVector;

#endif // ecManipDataCapture_H_
