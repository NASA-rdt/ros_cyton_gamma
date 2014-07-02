#ifndef ecSystemDataCapture_H_
#define ecSystemDataCapture_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemDataCapture.h
/// @class EcSystemDataCapture
/// @brief Capture the data of the whole system.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipDataCapture.h"
#include "ecSystemDataStorage.h"
#include <xml/ecXmlPairType.h>
#include "ecBaseSystemDataComponent.h"


/**
\class EcSystemDataCapture
\author Chalongrath Pholsiri
\brief This is the class for capturing the data of the whole system.
*/
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcSystemDataCapture : public EcBaseSystemDataComponent
{
public:
   /// default constructor
   EcSystemDataCapture
      (
      );

   /// destructor
   virtual ~EcSystemDataCapture
      (
      );

   /// copy constructor
   EcSystemDataCapture
      (
      const EcSystemDataCapture& orig
      );

   /// assignment operator
   EcSystemDataCapture& operator=
      (
      const EcSystemDataCapture& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemDataCapture& orig
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

   // returns the token for this class
   virtual const EcToken& token
      (
      ) const;

   /// returns a type
   virtual EcU32 type
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

   /// return the label of this data capture object
   virtual const EcString& label
      (
      ) const;

   /// set the label of this data capture object
   virtual void setLabel
      (
      const EcString& label
      );

   /// get the manipulator data capture vector
   virtual const EcManipulatorDataCaptureVector& manipulatorDataCaptureVector
      (
      ) const;

   /// capture the data from a simulation
   /**
   \param[in] simulation The simulation object from which the data will be captured.
   */
   virtual EcBoolean captureData
      (
      const EcSystemSimulation& simulation
      ) const;

   /// add a data capture type to a manipulator
   /**
   \param[in] manipIndex The index of the manipulator to which the data capture type will be added.
   \param[in] token The token of the data capture type to be added.
   \return False if token is invalid or if the data capture type is not of a manipulator type. Otherwise, return true.
   */
   virtual EcBoolean addManipulatorDataCaptureType
      (
      const EcU32& manipIndex,
      const EcToken& token
      );

   /// add a data capture type to all links of a manipulator.
   /**
   \param[in] manipIndex The index of the manipulator to which the data capture type will be added.
   \param[in] token The token of the data capture type to be added.
   \param[in] manip The manipulator object. Needed to ensure that all links of the manipulator are accounted for.
   \return False if token is invalid or if the data capture type is not of a link type. Otherwise, return true.
   */
   virtual EcBoolean addLinkDataCaptureType
      (
      const EcU32& manipIndex,
      const EcToken& token,
      const EcIndividualManipulator& manip
      );

   /// add a data capture type to a link of a manipulator
   /**
   \param[in] manipIndex The index of the manipulator to which the data capture type will be added.
   \param[in] linkId The identifying label of the link to which the data capture type will be added.
   \param[in] token The token of the data capture type to be added.
   \return False if token is invalid or if the data capture type is not of a link type. Otherwise, return true.
   */
   virtual EcBoolean addLinkDataCaptureType
      (
      const EcU32& manipIndex,
      const EcString& linkId,
      const EcToken& token
      );

   /// add a data capture type to all EEs of a manipulator.
   /**
   \param[in] manipIndex The index of the manipulator to which the data capture type will be added.
   \param[in] token The token of the data capture type to be added.
   \param[in] numEndEffectors The total number of end-effectors of the manipulator.
   \return False if token is invalid or if the data capture type is not of a EE type. Otherwise, return true.
   */
   virtual EcBoolean addEndEffectorDataCaptureType
      (
      const EcU32& manipIndex,
      const EcToken& token,
      const EcU32& numEndEffectors
      );

   /// add a data capture type to all EEs of a manipulator.
   /**
   \param[in] manipIndex The index of the manipulator to which the data capture type will be added.
   \param[in] dataType The data capture type to be added.
   \param[in] numEndEffectors The total number of end-effectors of the manipulator.
   \return False if token is invalid or if the data capture type is not of a EE type. Otherwise, return true.
   */
   virtual EcBoolean addEndEffectorDataCaptureType
      (
      const EcU32& manipIndex,
      const EcDataCaptureType& dataType,
      const EcU32& numEndEffectors
      );

   /// add a data capture type to an EE of a manipulator
   /**
   \param[in] manipIndex The index of the manipulator to which the data capture type will be added.
   \param[in] eeIndex The index of the EE to which the data capture type will be added.
   \param[in] dataType The data capture type to be added.
   \return False if the data capture type is not of an EE type. Otherwise, return true.
   */
   virtual EcBoolean addEndEffectorDataCaptureType
      (
      const EcU32& manipIndex,
      const EcU32& eeIndex,
      const EcDataCaptureType& dataType
      );

   /// add a data capture type to an EE of a manipulator
   /**
   \param[in] manipIndex The index of the manipulator to which the data capture type will be added.
   \param[in] eeIndex The index of the EE to which the data capture type will be added.
   \param[in] token The token of the data capture type to be added.
   \return False if token is invalid or if the data capture type is not of an EE type. Otherwise, return true.
   */
   virtual EcBoolean addEndEffectorDataCaptureType
      (
      const EcU32& manipIndex,
      const EcU32& eeIndex,
      const EcToken& token
      );

   /// remove a data capture type from a manipulator
   /**
   \param[in] manipIndex The index of the manipulator from which the data capture type will be removed.
   \param[in] token The token of the data capture type to be removed.
   \return False if token is invalid or if the data capture type of the given token does belong to the manipulator. Otherwise, return true.
   */
   virtual EcBoolean removeManipulatorDataCaptureType
      (
      const EcU32& manipIndex,
      const EcToken& token
      );

   /// remove a data capture type from all links in this manipulator
   /**
   \param[in] manipIndex The index of the manipulator from which the data capture type will be removed.
   \param[in] token The token of the data capture type to be removed.
   \return False if token is invalid or if the data capture type of the given token does not belong to any of the links. Otherwise, return true.
   */
   virtual EcBoolean removeLinkDataCaptureType
      (
      const EcU32& manipIndex,
      const EcToken& token
      );

   /// remove a data capture type from a link in this manipulator
   /**
   \param[in] manipIndex The index of the manipulator from which the data capture type will be removed.
   \param[in] token The token of the data capture type to be removed.
   \param[in] linkId The identifying label of the link from which the data capture type will be removed.
   \return False if token is invalid or if the data capture type of the given token does not belong to this link. Otherwise, return true.
   */
   virtual EcBoolean removeLinkDataCaptureType
      (
      const EcU32& manipIndex,
      const EcString& linkId,
      const EcToken& token
      );

   /// remove a data capture type from all EEs in this manipulator
   /**
   \param[in] manipIndex The index of the manipulator from which the data capture type will be removed.
   \param[in] token The token of the data capture type to be removed.
   \return False if token is invalid or if the data capture type of the given token does not belong to any of the EEs. Otherwise, return true.
   */
   virtual EcBoolean removeEndEffectorDataCaptureType
      (
      const EcU32& manipIndex,
      const EcToken& token
      );

   /// remove a data capture type from a link in this manipulator
   /**
   \param[in] manipIndex The index of the manipulator from which the data capture type will be removed.
   \param[in] token The token of the data capture type to be removed.
   \param[in] eeIndex The index of the EE from which the data capture type will be removed.
   \return False if token is invalid or if the data capture type of the given token does not belong to this EE. Otherwise, return true.
   */
   virtual EcBoolean removeEndEffectorDataCaptureType
      (
      const EcU32& manipIndex,
      const EcU32& eeIndex,
      const EcToken& token
      );

   /// add a manipulator data capture object
   virtual void addManipulatorDataCapture
      (
      const EcManipulatorDataCapture& manipDataCapture
      );

   /// return a const pointer to the manipulator data capture of a given manipulator index. If manipIndex is not found, EcNULL is returned.
   virtual const EcManipulatorDataCapture* manipulatorDataCapture
      (
      const EcU32& manipIndex
      ) const;

   /// remove a single manipulator data capture object by manipulator index
   /**
   \param[in] manipIndex The index of the manipulator to be removed.
   \return False if manipIndex is not found or true otherwise
   */
   virtual EcBoolean removeManipulatorDataCapture
      (
      const EcU32& manipIndex
      );

   /// Return whether or not the data capture type as given by the token is included in a manipulator.
   /**
   \param[in] manipIndex The index of the manipulator being queried.
   \param[in] token The token of the data capture type being queried.
   \return True if the data capture type is included in the manipulator or false otherwise.
   */
   virtual EcBoolean isDataCaptureTypeIncluded
      (
      const EcU32& manipIndex,
      const EcToken& token
      ) const;

   /// Return whether or not the data capture type as given by the token is included in a link of a manipulator.
   /**
   \param[in] manipIndex The index of the manipulator being queried.
   \param[in] linkId The identifying label of the link being queried.
   \param[in] token The token of the data capture type being queried.
   \return True if the data capture type is included in the link or false otherwise.
   */
   virtual EcBoolean isDataCaptureTypeIncluded
      (
      const EcU32& manipIndex,
      const EcString& linkId,
      const EcToken& token
      ) const;

   /// Return whether or not the data capture type as given by the token is included in an EE of a manipulator.
   /**
   \param[in] manipIndex The index of the manipulator being queried.
   \param[in] eeIndex The index of the EE being queried.
   \param[in] token The token of the data capture type being queried.
   \return True if the data capture type is included in the EE or false otherwise.
   */
   virtual EcBoolean isDataCaptureTypeIncluded
      (
      const EcU32& manipIndex,
      const EcU32& eeIndex,
      const EcToken& token
      ) const;

   /// return the number of data capture types included in a manipulator.
   /**
   \param[in] manipIndex The index of the manipulator being queried.
   */
   virtual EcU32 numDataCaptureTypes
      (
      const EcU32& manipIndex
      ) const;

   /// return the number of data capture types included in a link of a manipulator.
   /**
   \param[in] manipIndex The index of the manipulator being queried.
   \param[in] linkId The identifying label of the link being queried.
   */
   virtual EcU32 numDataCaptureTypes
      (
      const EcU32& manipIndex,
      const EcString& linkId
      ) const;

   /// return the number of data capture types included in an EE of a manipulator.
   /**
   \param[in] manipIndex The index of the manipulator being queried.
   \param[in] eeIndex The index of the EE being queried.
   */
   virtual EcU32 numDataCaptureTypes
      (
      const EcU32& manipIndex,
      const EcU32& eeIndex
      ) const;

   /// set the disable flags of a manipulator data capture type.
   /**
   \param[in] manipIndex The index of the manipulator..
   \param[in] token The token of the data capture type to which the disable flags will be set.
   \param[in] disableFlags A vector of booleans containing the disable flags to be set.
   \return True if the data capture type is included in the manipulator or false otherwise.
   */
   virtual EcBoolean setDisableFlags
      (
      const EcU32& manipIndex,
      const EcToken& token,
      const EcXmlBooleanVector& disableFlags
      );

   /// set the disable flags of a link data capture type.
   /**
   \param[in] manipIndex The index of the manipulator.
   \param[in] linkId The identifying label of the link.
   \param[in] token The token of the data capture type to which the disable flags will be set.
   \param[in] disableFlags A vector of booleans containing the disable flags to be set.
   \return True if the data capture type is included in the link or false otherwise.
   */
   virtual EcBoolean setDisableFlags
      (
      const EcU32& manipIndex,
      const EcString& linkId,
      const EcToken& token,
      const EcXmlBooleanVector& disableFlags
      );

   /// set the disable flags of an EE data capture type.
   /**
   \param[in] manipIndex The index of the manipulator.
   \param[in] eeIndex The index of the EE.
   \param[in] token The token of the data capture type to which the disable flags will be set.
   \param[in] disableFlags A vector of booleans containing the disable flags to be set.
   \return True if the data capture type is included in the EE or false otherwise.
   */
   virtual EcBoolean setDisableFlags
      (
      const EcU32& manipIndex,
      const EcU32& eeIndex,
      const EcToken& token,
      const EcXmlBooleanVector& disableFlags
      );

   /// Allocate enough memory in the data storage for this data capture.
   /**
   \param[out] storage An EcSystemDataStorage object for which memory will be allocated. Note that the existing data in this storage object (if any) WILL be deleted upon return of this method.
   */
   virtual void allocateStorage
      (
      EcSystemDataStorage& storage
      ) const;

   /// Store the captured data in the data storage. This should be called after a call to captureData.
   /**
   \param[out] storage An EcSystemDataStorage object in which the captured data will be stored. Note that the existing data in this storage object (if any) WILL be replaced by the captured data upon return of this method.
   */
   virtual void storeData
      (
      EcSystemDataStorage& storage
      ) const;

   /// get a vector of strings that contains the descriptions of captured data elements.
   /**
   \param[out] vElements A vector of strings which, upon return, will contains the elements of this data component. It will be resized appropriately.
   */
   virtual void getStringElements
      (
      EcStringVector& vElements
      ) const;

   /// get a vector of reals that contains the current captured data.
   /**
   \param[out] vElements A vector of reals which, upon return, will contains the captured data. It will be resized appropriately.
   */
   virtual void getDataElements
      (
      EcXmlRealVector& vElements
      ) const;

   /// remove all the data capture types
   virtual void removeAllDataCaptureTypes
      (
      );

  /// token for this class
   /**
   \return a unique string token.
   */
   static const EcToken& classToken
      (
      );

   /// static creator function
   /**
   \return a pointer to a new'ed object.
   */
   static EcXmlObject* creator
      (
      );

protected:

   /// find the index in the internal vector for a given manipulator index
   /**
   \param[in] manipIndex The manipulator index.
   \param[out] index The index in the vector corresponding to manipIndex.
   \return True if manipIndex can be found or false otherwise.
   */
   virtual EcBoolean findIndex
      (
      const EcU32& manipIndex,
      EcU32& index
      ) const;

   /// compute the total number of data elements in the data capture object whenever a change (add or remove) has occurred.
   virtual void computeElementSize
      (
      );

   /// get active data
   virtual void getActiveData
      (
      const EcXmlBooleanVector& disableFlags,
      const EcXmlRealVector& data,
      EcXmlRealVector& activeData
      ) const;

protected:
   /// the label of this capture object
   EcXmlString                m_Label;

   /// the data capture of all manipulators, including their links.
   EcManipulatorDataCaptureVector   m_vManipulatorDataCapture;

   /// non-XML data
   /// the total number of data elements in the data capture object. Cached here so we don't have to compute it every single time.
   EcU32                            m_ElementSize;

   /// utility XML real vector
   mutable EcXmlRealVector          m_UtilityRealVector;
};

// XML types of data captures
/// type definition of EcSystemDataCaptureVector
typedef EcXmlVectorType<EcSystemDataCapture> EcSystemDataCaptureVector;
/// type definition of EcSystemDataCapturePair
typedef EcXmlPairType<EcSystemDataCapture, EcSystemDataCapture> EcSystemDataCapturePair;
/// type definition of EcStringSystemDataCapturePair
typedef EcXmlPairType<EcXmlString, EcSystemDataCapturePair> EcStringSystemDataCapturePair;
/// type definition of EcStringSystemDataCapturePairVector
typedef EcXmlVectorType<EcStringSystemDataCapturePair> EcStringSystemDataCapturePairVector;

#endif // ecSystemDataCapture_H_
