#ifndef ecSystemDataStorage_H_
#define ecSystemDataStorage_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemDataStorage.h
/// @class EcSystemDataStorage
/// @brief Holds a description of captured system data.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseSystemDataComponent.h"
#include "ecManipDataStorage.h"

#include <foundCore/ecTypes.h>
#include <foundCommon/ecCoordSysXForm.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

/** Holds a description of captured system data.
*/
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcSystemDataStorage : public EcBaseSystemDataComponent
{
public:
   /// default constructor
   EcSystemDataStorage
      (
      );

   /// destructor
   virtual ~EcSystemDataStorage
      (
      );

   /// copy constructor
   EcSystemDataStorage
      (
      const EcSystemDataStorage& orig
      );

   /// assignment operator
   EcSystemDataStorage& operator=
      (
      const EcSystemDataStorage& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemDataStorage& orig
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

   /// get manipulator data vector
   virtual const EcManipulatorDataStorageVector& manipulatorDataVector
      (
      )const;

   /// set manipulator data vector
   virtual void setManipulatorDataVector
      (
      const EcManipulatorDataStorageVector& manipulatorDataVector
      );

   /// set specific manipulator-level data--one datum
   virtual void setSpecificManipulatorLevelData
      (
      EcU32 manipIndex,
      EcU32 dataIndex,
      EcU32 position,
      EcReal newData
      );

   /// set specific manipulator-level data--a vector of values
   virtual void setSpecificManipulatorLevelData
      (
      EcU32 manipIndex,
      EcU32 dataIndex,
      EcU32 startingPosition,
      const EcXmlRealVector& newData
      );

   /// set specific link-level data--one datum
   virtual void setSpecificLinkLevelData
      (
      EcU32 manipIndex,
      EcU32 linkIndex,
      EcU32 dataIndex,
      EcU32 position,
      EcReal newData
      );

   /// set specific link-level data--a vector of values
   virtual void setSpecificLinkLevelData
      (
      EcU32 manipIndex,
      EcU32 linkIndex,
      EcU32 dataIndex,
      EcU32 startingPosition,
      const EcXmlRealVector& newData
      );

   /// set specific end-effector data--one datum
   virtual void setSpecificEndEffectorData
      (
      EcU32 manipIndex,
      EcU32 eeIndex,
      EcU32 dataIndex,
      EcU32 position,
      EcReal newData
      );

   /// set specific end-effector data--a vector of values
   virtual void setSpecificEndEffectorData
      (
      EcU32 manipIndex,
      EcU32 eeIndex,
      EcU32 dataIndex,
      EcU32 startingPosition,
      const EcXmlRealVector& newData
      );

   /// get time
   virtual const EcReal& time
      (
      )const;

   /// set time
   virtual void setTime
      (
      const EcReal& time
      );

   /// gets the index of the point in the path
   virtual EcU32 pathPointIndex
      (
      ) const;

   /// sets the index of the point in the path
   virtual void setPathPointIndex
      (
      EcU32 value
      );

   // returns the token for this class
   virtual const EcToken& token
      (
      ) const;

   /// returns a type
   virtual EcU32 type
      (
      ) const;

   /// compute the total number of data elements in the storage. Should be called after memory has been allocated for the storage.
   virtual void computeElementSize
      (
      );

   /// returns the total number of data elements in the storage.
   /**
   \param[in] capturedDataOnly If true, the number of data elements includes only the captured data. Otherwise, it will include the simulation time, the path index, and the captured data.
   */
   virtual EcU32 elementSize
      (
      EcBoolean capturedDataOnly=EcTrue
      ) const;

   /// get a vector of strings that contains the data (converted from numbers) in this storage.
   /**
   \param[out] vElements A vector of strings which, upon return, will contains the data. It will be resized appropriately. The returned data include the simulation time, the path index, and the captured data.
   */
   virtual void getStringElements
      (
      EcStringVector& vElements
      ) const;

   /// get a vector of numbers that contains the data in this storage.
   /**
   \param[out] vElements A vector of numbers which, upon return, will contains the data. It will be resized appropriately.
   \param[in] capturedDataOnly If true, the returned data includes only the captured data. Otherwise, it will include the simulation time, the path index, and the captured data.
   */
   virtual void getRealElements
      (
      EcXmlRealVector& vElements,
      EcBoolean capturedDataOnly=EcTrue
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
   static EcSystemDataStorage nullObject
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

   /// manipulator-level data
   EcManipulatorDataStorageVector   m_ManipulatorDataVector;

   /// simulation time
   EcXmlReal                        m_Time;

   /// the index of the point in the path
   EcXmlU32                         m_PathPointIndex;

   /// non-XML data
   /// the total number of data elements in the storage, including time. Cached here so we don't have to compute it every single time.
   EcU32                            m_ElementSize;
};

/// an XML vector of links
typedef EcXmlVectorType<EcSystemDataStorage> EcSystemDataStorageVector;

#endif // ecSystemDataStorage_H_
