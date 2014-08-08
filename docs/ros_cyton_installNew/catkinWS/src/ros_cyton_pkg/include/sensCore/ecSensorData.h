#ifndef ecSensorData_H_
#define ecSensorData_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecSensorData.h
/// @class EcSensorData
/// @brief Holds a description of sensor data.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

/// Holds a description of sensor data.
class EC_SENSOR_IMAGE_DECL EcSensorData : public EcXmlCompoundType
{
public:
   /// default constructor
   EcSensorData
      (
      );

   /// constructor giving a zero image
   /// freed when it is no longer used.
   EcSensorData
      (
      EcU32 multibytesPerValue,
      EcU32 bitsPerSubbyteValue,
      EcU32 numValues
      );

   /// destructor
   virtual ~EcSensorData
      (
      );

   /// copy constructor
   EcSensorData
      (
      const EcSensorData& orig
      );

   /// assignment operator
   EcSensorData& operator=
      (
      const EcSensorData& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSensorData& orig
      ) const;

   /// copies data from the other image without reference counting
   virtual void copyDataFrom
      (
      const EcSensorData& orig
      );

   /// copy data to a real vector.  Ordering is flattened row by row.
   /// i.e., x,y,c=0,0,0; x,y,c=0,0,1;... x,y,c=1,0,0...
   virtual void copyDataTo
      (
      EcRealVector& realVector
      ) const;

   /// copy data from a real vector.  Ordering is flattened row by row.
   /// i.e., x,y,c=0,0,0; x,y,c=0,0,1;... x,y,c=1,0,0...
   virtual void copyDataFrom
      (
      const EcRealVector& realVector
      );

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

   /// init to a value
   virtual EcBoolean init
      (
      EcU32 multibytesPerValue,
      EcU32 bitsPerSubbyteValue,
      EcU32 numValues,
      EcU8  initValue
      );

   /// set to all zeros
   virtual EcBoolean zero
      (
      EcU32 multibytesPerValue,
      EcU32 bitsPerSubbyteValue,
      EcU32 numValues
      );

   /// keep current size and set to init value
   virtual EcBoolean init
      (
      EcU8 initValue
      );

   // keep current size and set to initial value, 4 bytes at a time
   virtual EcBoolean init
      (
      EcU32 initValue
      );

   /// keep current size and set to all zeros
   virtual EcBoolean zero
      (
      );

   /// set from vector data.  The memory will be
   /// freed when it is no longer used.
   virtual EcBoolean set
      (
      const EcU8Vector& vMultibytes,
      const EcU8Vector& vSubbytes,
      EcU32 multibytesPerValue,
      EcU32 bitsPerSubbyteValue,
      EcU32 numValues
      );

   /// get a multibyte value
   virtual EcU8 multibyteValue
      (
      EcU32 valueIndex,
      EcU32 byteIndex
      ) const;

   /// set a multibyte value
   virtual EcBoolean setMultibyteValue
      (
      EcU32 valueIndex,
      EcU32 byteIndex,
      EcU8 value
      );

   /// get a subbyte bit
   virtual EcBoolean subbyteBit
      (
      EcU32 valueIndex,
      EcU32 bitIndex
      ) const;

   /// set a subbyte bit
   virtual EcBoolean setSubbyteBit
      (
      EcU32 valueIndex,
      EcU32 bitIndex,
      EcBoolean value
      );

   /// gets the number of multibytes per value
   virtual EcU32 multibytesPerValue
      (
      ) const;

   /// gets the number of bits per subbyte value
   virtual EcU32 bitsPerSubbyteValue
      (
      ) const;

   /// gets the number of values
   virtual EcU32 numValues
      (
      ) const;

   /// gets a pointer to the multibyte data - const
   /// use with great caution.
   virtual const EcU8* multibytePointer
      (
      ) const;

   /// gets a pointer to the multibyte data - nonconst
   /// use with great caution.
   virtual EcU8* multibytePointer
      (
      );

   /// gets a pointer to the subbyte data - const
   /// use with great caution.
   virtual const EcU8* subbytePointer
      (
      ) const;

   /// gets a pointer to the subbyte data - nonconst
   /// use with great caution.
   virtual EcU8* subbytePointer
      (
      );

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

   /// write this object to an XML schema
   virtual EcBoolean writeSchema
      (
      EcXmlSchema& stream
      ) const;

   /// read value from unregistered token
   virtual EcBoolean readValueFromSpecialToken
      (
      const EcToken& token,
      EcXmlReader& stream
      );

   virtual const EcToken& token
      (
      ) const;

   /// get a null object
   static EcSensorData nullObject
      (
      );

   /// set the referenceable flag
   virtual void setReferenceable
      (
      EcBoolean referenceable
      );

protected:
   /// copy shared data into members.  The data is going to be modified.
   virtual void aboutToModify
      (
      );

   /// remove reference to shared data and delete if necessary
   virtual void removeReference
      (
      );

   /// calcualte the size ofthe multibyte array
   virtual EcU32 multibyteArraySize
      (
      ) const;

   /// calcualte the size ofthe subbyte array
   virtual EcU32 subbyteArraySize
      (
      ) const;

   /// get the number of columns for printing
   virtual EcU32 numColumns
      (
      ) const;

   /// multibyte array factory method
   virtual EcU8* newMultibyteArray
      (
      ) const;

   /// subbyte array factory method
   virtual EcU8* newSubbyteArray
      (
      ) const;

   /// reference counter factory method
   virtual EcU32* newReferenceCounter
      (
      ) const;

protected:
   /// A pointer to the multibyte data.
   EcU8*                m_pMultibytes;

   /// A pointer to the bit data.
   EcU8*                m_pSubbytes;

   /// The number of byte-size channels in the data set.
   EcXmlU32             m_MultibytesPerValue;

   /// The number of bit-size channels in the data set.
   EcXmlU32             m_BitsPerSubbyteValue;

   /// The number of values in the data set.
   EcXmlU32             m_NumValues;

   // nonXML data below

   /// A reference-count pointer.
   EcU32*               m_pReferenceCount;

   /// The number of allocated multibytes
   EcU32                m_AllocatedMultibytes;

   /// A flag indicating that this class owns its own multibytes.
   EcBoolean            m_OwnMultibytes;

   /// A flag indicating that this class owns its own bits.
   EcBoolean            m_OwnSubbytes;

   /// A flag indicating that this object can be referenced.
   mutable EcBoolean    m_Referenceable;

   /// The default number of columns for printing.
   static const EcU32   m_theDefaultNumColumns;
};

#endif // ecSensorData_H_
