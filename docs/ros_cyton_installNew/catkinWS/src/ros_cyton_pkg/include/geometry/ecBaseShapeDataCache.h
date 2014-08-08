#ifndef ecBaseShapeDataCache_H_
#define ecBaseShapeDataCache_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseShapeDataCache.h
/// @brief Holds a description of the class used to cache the
///        closest points between pairs of shapes
/// @details EcBaseShapeDataCache
//
//------------------------------------------------------------------------------
#include <foundCore/ecVector.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

#ifdef _MSC_VER
// This is for the nested vector below
#  pragma warning(disable:4786)
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

// forward declarations
class EcShapeStateCacheKey;

/** Holds a description of a  class used to cache the
    closest points between pairs of shapes
*/
template <class DataType>
class EcBaseShapeDataCache : public EcXmlCompoundType
{
public:
   /// default constructor
   EcBaseShapeDataCache
      (
      );

   /// destructor
   virtual ~EcBaseShapeDataCache
      (
      );

   /// copy constructor
   EcBaseShapeDataCache
      (
      const EcBaseShapeDataCache& orig
      );

   /// assignment operator
   EcBaseShapeDataCache& operator=
      (
      const EcBaseShapeDataCache& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseShapeDataCache& orig
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

   /// reads this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// writes this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// gets a null link
   static EcBaseShapeDataCache nullObject
      (
      );

   /// This method sets the data in the data structure,
   /// allocating as required.
   virtual EcBoolean allocateAndSetData
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2,
      const EcInt32Vector3D& systemNumShapes,
      const DataType& datum
      ) const;

   /// This method gets the data in the data structure,
   /// allocating as required. If the data is unavailable, the space
   /// is allocated and a default datum is returned
   virtual const DataType* allocateAndGetData
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2,
      const EcInt32Vector3D& systemNumShapes
      ) const;

   /// set the datum for the shape pair key provided
   virtual EcBoolean setData
      (
      const EcShapeStateCacheKey& shapeIndex1,
      const EcShapeStateCacheKey& shapeIndex2,
      const DataType& datum
      ) const;

   /// get the datum for the keys provided
   virtual const DataType* getData
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2
      ) const;

   /// make the indices compatible with the matrix, since we only store
   /// half the entries
   virtual EcBoolean makeIndicesCompatible
      (
      EcU32& index1,
      EcU32& index2
      )const;

   /// make two keys compatible.  If the manipulator ID is greater
   /// on the first key, then switch
   virtual EcBoolean makeKeysCompatible
      (
      EcShapeStateCacheKey& key1,
      EcShapeStateCacheKey& key2
      )const;

   ///  This method gets the data in the data structure,
   /// allocating as required. If the data is unavailable, the space
   /// is allocated and a default datum is returned (non-const)
   virtual DataType* allocateAndGetData
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2,
      const EcInt32Vector3D& systemNumShapes
      );

   /// get the datum for the keys provided (non-const)
   virtual DataType* getData
      (
      const EcShapeStateCacheKey& shape1,
      const EcShapeStateCacheKey& shape2
      ) ;

   /// resize the database to the number of shapes in each link of each manipulator in the system
   virtual EcBoolean resizeDatabaseToSystem
      (
      const EcInt32Vector3D& systemNumShapes
      );

   virtual const EcToken& token
      (
      ) const;

protected:
   /// six dimensional array of data
   /// the array goes (manipID  X  manipID) then
   ///                (linkID   X  linkID) and finally
   ///                (shapeID  X  shapeID)
   mutable
      std::vector<std::vector<
      std::vector<std::vector<
      std::vector<std::vector<DataType> > > > > > m_ShapeData;

   /// CONST DATA
   /// the null datum
   static const DataType m_theNullDatum;
};

#endif // ecBaseShapeDataCache_H_
