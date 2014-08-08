//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseShapeDataCache.ipp
//
//------------------------------------------------------------------------------
#include "ecBaseShapeDataCache.h"
#include "ecGeometryTokens.h"
#include "ecShapeStateCacheKey.h"
#include <foundCommon/ecFoundCommonTokens.h>
#include <foundCommon/ecFoundCommonTypes.h>

template<class DataType>
const DataType EcBaseShapeDataCache<DataType>::m_theNullDatum= DataType();

/////////////////////////////////////////////////////////////////////////
// Function:    Big four and other header functions.
// Description: Common functions
/////////////////////////////////////////////////////////////////////////

// constructor
template<class DataType>
EcBaseShapeDataCache<DataType>::EcBaseShapeDataCache():
EcXmlCompoundType(),
m_ShapeData()
{
}

// destructor
template<class DataType>
EcBaseShapeDataCache<DataType>::~EcBaseShapeDataCache
   (
   )
{
}

// copy constructor.  Also copies the parent link pointer.
template<class DataType>
EcBaseShapeDataCache<DataType>::EcBaseShapeDataCache
   (
   const EcBaseShapeDataCache<DataType>& orig
   ):
EcXmlCompoundType(orig),
m_ShapeData(orig.m_ShapeData)
{
}

// assignment operator
template<class DataType>
EcBaseShapeDataCache<DataType>& EcBaseShapeDataCache<DataType>::operator=
   (
   const EcBaseShapeDataCache<DataType>& orig
   )
{
   // self assignment.
   if (this==&orig)
   {
      return *this;
   }

   // call parent
   EcXmlCompoundType::operator=(orig);

   // copy data

   m_ShapeData = orig.m_ShapeData;

   return *this;
}

// equality operator
template<class DataType>
EcBoolean EcBaseShapeDataCache<DataType>::operator==
   (
   const EcBaseShapeDataCache<DataType>& orig
   ) const
{
   EcBoolean retVal=EcXmlCompoundType::operator==(orig);

   if(retVal)
   {



   }
   return retVal;
}

/////////////////////////////////////////////////////////////////////////
//End of header functions.
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// Function:    xmlInit()
// Description: XML-initializes the class and all parent classes.
// I/O:         Return error status
/////////////////////////////////////////////////////////////////////////
template<class DataType>
EcBoolean EcBaseShapeDataCache<DataType>::xmlInit
   (
   )
{
   if(EcXmlCompoundType::xmlInit())
   {
      return EcTrue;
   }
   else
   {
      return EcFalse;
   }
}

/////////////////////////////////////////////////////////////////////////
// Function:    clone()
// Description: A virtual constructor that returns an EcXmlObject.
// I/O:         Return XML object
/////////////////////////////////////////////////////////////////////////
template<class DataType>
EcXmlObject* EcBaseShapeDataCache<DataType>::clone
   (
   ) const
{
   return new EcBaseShapeDataCache<DataType>(*this);
}

/////////////////////////////////////////////////////////////////////////
// Function:    registerComponents()
// Description: All the components registered here are automatically
//              read from and written to xml streams.
/////////////////////////////////////////////////////////////////////////
template<class DataType>
void EcBaseShapeDataCache<DataType>::registerComponents
   (
   )
{

}

/////////////////////////////////////////////////////////////////////////
// Function:     equality
// Description:  equality - virtual equality to an EcXmlObject pointer
// I/O:          Input XML object, Return status
/////////////////////////////////////////////////////////////////////////
template<class DataType>
EcBoolean EcBaseShapeDataCache<DataType>::equality
   (
   const EcXmlObject* other
   ) const
{
   EcBoolean retVal=EcTrue;

   const EcBaseShapeDataCache<DataType>* cast=
      dynamic_cast<const EcBaseShapeDataCache<DataType>*>(other);

   if(!cast || !(*this==*cast))
   {
      retVal=EcFalse;
   }
   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     newObject
// Description:  A virtual new that returns an EcXmlObject.
// I/O:          Return XML object
/////////////////////////////////////////////////////////////////////////
template<class DataType>
EcXmlObject* EcBaseShapeDataCache<DataType>::newObject
   (
   ) const
{
   return new EcBaseShapeDataCache<DataType>();
}

/////////////////////////////////////////////////////////////////////////
// Function:    read()
// Description: Reads class data from an XML stream.
// I/O:         Output: true for success.
/////////////////////////////////////////////////////////////////////////
template<class DataType>
EcBoolean EcBaseShapeDataCache<DataType>::read
   (
   EcXmlReader& stream
   )
{
   EcBoolean retVal=EcXmlCompoundType::read(stream);

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:    write()
// Description: Writes class data to an XML stream.
// I/O:         Output: true for success.
/////////////////////////////////////////////////////////////////////////
template<class DataType>
EcBoolean EcBaseShapeDataCache<DataType>::write
   (
   EcXmlWriter& stream
   ) const
{
   EcBoolean retVal=EcXmlCompoundType::write(stream);

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:    nullObject()
// Description: Create an empty object.
// I/O:         Return empty object
/////////////////////////////////////////////////////////////////////////
template<class DataType>
EcBaseShapeDataCache<DataType> EcBaseShapeDataCache<DataType>::nullObject
   (
   )
{
   return EcBaseShapeDataCache<DataType>();
}

/////////////////////////////////////////////////////////////////////////
// Function:     setData
// Description:  This method sets the data in the existing data structure,
//               if the data structure required does not exist, it returns
//               EcFalse.
/////////////////////////////////////////////////////////////////////////
template<class DataType>
EcBoolean EcBaseShapeDataCache<DataType>::setData
(
   const EcShapeStateCacheKey& shape1,
   const EcShapeStateCacheKey& shape2,
   const DataType& datum
) const
{
   EcBoolean retVal = EcFalse;
   EcShapeStateCacheKey key1 = shape1;
   EcShapeStateCacheKey key2 = shape2;

   /// make key1 be the key with the higher manipulator index
   makeKeysCompatible(key1,key2);


   if (!(key1 == EcShapeStateCacheKey::invalidKey() ||
         key2 == EcShapeStateCacheKey::invalidKey() ))
   {

      // get the manipulator indices
      EcU32 manipID1 = key1.manipID();
      EcU32 manipID2 = key2.manipID();

      EcBoolean manipsValid = EcTrue;
      if (m_ShapeData.size() <= manipID1)
      {
         manipsValid = EcFalse;
      }
      else
      {
         if (m_ShapeData[manipID1].size() <= manipID2)
         {
            manipsValid = EcFalse;
         }
      }

     // makeIndicesCompatible(manipID1,manipID2);
      if (manipsValid)
      {
         // check the links
         std::vector<std::vector<
         std::vector<std::vector<DataType> > > >& links
         = m_ShapeData[manipID1][manipID2];

         // now check if the links exist in the database
         EcU32 linkID1 = key1.linkID();
         EcU32 linkID2 = key2.linkID();

         // when indexing in the link dimension,
         // the BASEINDEX is index (0) and the link IDs are
         // shifted by one (i.e link (0) is at link index (1)
         EcU32 link1Index = (linkID1==EcFoundCommon::BASEINDEX ? 0:linkID1+1);
         EcU32 link2Index = (linkID2==EcFoundCommon::BASEINDEX ? 0:linkID2+1);

         EcBoolean linksValid = EcTrue;
         if (links.size() <= link1Index)
         {
            linksValid = EcFalse;
         }
         else
         {
            if (links[link1Index].size() <= link2Index)
            {
               linksValid = EcFalse;
            }
         }
         if (linksValid)
         {
            // now check the shapes
            std::vector<std::vector<DataType> > & shapes =
               links[link1Index][link2Index];

            // now check if the shapes exist in the database
            EcU32 shapeID1 = key1.shapeID();
            EcU32 shapeID2 = key2.shapeID();

            EcBoolean shapesValid = EcTrue;
            if (shapes.size() <= shapeID1)
            {
               shapesValid = EcFalse;
            }
            else
            {
               if (shapes[shapeID1].size() <= shapeID2)
               {
                  shapesValid = EcFalse;
               }
            }
            if (shapesValid)
            {
               // set the data value
               shapes[shapeID1][shapeID2] = datum;
               retVal = EcTrue;
            }
            else
            {
               // shapes don't exist
               retVal = EcFalse;
            }
         }
         else
         {
            // links don't exist in the database
            retVal = EcFalse;
         }
      }
      else
      {
         // manipulators don't not exist
         retVal = EcFalse;
      }
   }
   else
   {
      // invalid key passed in
      retVal = EcFalse;
   }
   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     allocateAndSetData
// Description:  This method sets the data in the data structure,
//               allocating as required.
/////////////////////////////////////////////////////////////////////////
template<class DataType>
EcBoolean EcBaseShapeDataCache<DataType>::allocateAndSetData
(
   const EcShapeStateCacheKey& shape1,
   const EcShapeStateCacheKey& shape2,
   const EcInt32Vector3D& systemNumShapes,
   const DataType& datum
) const
{
   EcBoolean retVal = EcTrue;

   // guard for invalid key entries
   if (!(shape1==EcShapeStateCacheKey::invalidKey() ||
         shape2==EcShapeStateCacheKey::invalidKey()))
   {

      EcShapeStateCacheKey key1 = shape1;
      EcShapeStateCacheKey key2 = shape2;

      /// make key1 be the key with the higher manipulator index
      makeKeysCompatible(key1,key2);

      // get the manipulator indices
      EcU32 manipID1 = key1.manipID();
      EcU32 manipID2 = key2.manipID();
      EcU32 linkID1 = key1.linkID();
      EcU32 linkID2 = key2.linkID();

      EcBoolean reallocManips = EcFalse;
      if (m_ShapeData.size() <= manipID1)
      {
         reallocManips = EcTrue;
      }
      else
      {
         if (m_ShapeData[manipID1].size() <= manipID2)
         {
            reallocManips = EcTrue;
         }
      }

      if (reallocManips)
      {
         // build the manipulator level
         // get the number of manipulators in the system
         const size_t numManips = systemNumShapes.size();

         m_ShapeData.resize(numManips);
         for(size_t ii=0;ii<numManips;++ii)
         {
            m_ShapeData[ii].resize(numManips);
         }
      }

      // check the links
      std::vector<std::vector<
      std::vector<std::vector<DataType> > > >& links
      = m_ShapeData[manipID1][manipID2];

      // when indexing in the link dimension,
      // the BASEINDEX is index (0) and the link IDs are
      // shifted by one (i.e link (0) is at link index (1)
      EcU32 link1Index = (linkID1==EcFoundCommon::BASEINDEX ? 0:linkID1+1);
      EcU32 link2Index = (linkID2==EcFoundCommon::BASEINDEX ? 0:linkID2+1);

      // now check if the links exist in the database
      EcBoolean reallocLinks = EcFalse;
      if (links.size() <= link1Index)
      {
         reallocLinks = EcTrue;
      }
      else
      {
         if (links[link1Index].size() <= link2Index)
         {
            reallocLinks = EcTrue;
         }
      }
      if (reallocLinks)
      {
         const size_t nLinks1 = systemNumShapes[manipID1].size();
         const size_t nLinks2 = systemNumShapes[manipID2].size();

         // this level will be non-square in general, choose the larger of
         // the two indices to be the the first dimension

         links.resize(nLinks1);

         for (size_t ii=0; ii<nLinks1; ++ii)
         {
            links[ii].resize(nLinks2);
         }
      }

      // now check the shapes
      std::vector<std::vector<DataType> > & shapes =
         links[link1Index][link2Index];


      // now check if the shapes exist in the database
      EcU32 shapeID1 = key1.shapeID();
      EcU32 shapeID2 = key2.shapeID();

      EcBoolean reallocShapes = EcFalse;
      if (shapes.size() <= shapeID1)
      {
         reallocShapes = EcTrue;
      }
      else
      {
         if (shapes[shapeID1].size() <= shapeID2)
         {
            reallocShapes = EcTrue;
         }
      }

      if (reallocShapes)
      {
         // create the shape matrix for this set of links
         // get the number of shapes for each link
         const size_t numberOfShapes1 = systemNumShapes[manipID1][link1Index].size();
         const size_t numberOfShapes2 = systemNumShapes[manipID2][link2Index].size();

         shapes.resize(numberOfShapes1);

         for (size_t ii=0; ii<numberOfShapes1; ++ii)
         {
            shapes[ii].resize(numberOfShapes2);
         }
      }
      /// set the value
      shapes[shapeID1][shapeID2] = datum;
   }
   else
   {
      retVal = EcFalse;
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     allocateAndGetData
// Description:  This method gets the data in the data structure,
//               allocating as required.  The default value is returned
//               if the data structure doesn't initially exist at the
//               time of this call
// I/O:          Input:  keys for the database, the system (needed for
//                       resizing if necessary)
//               Output: datum value, EcBoolean success
/////////////////////////////////////////////////////////////////////////
template<class DataType>
const DataType* EcBaseShapeDataCache<DataType>::allocateAndGetData
(
   const EcShapeStateCacheKey& shape1,
   const EcShapeStateCacheKey& shape2,
   const EcInt32Vector3D& systemNumShapes
) const
{
   const DataType* retVal = EcNULL;
   // guard for invalid key entries
   if (!(shape1==EcShapeStateCacheKey::invalidKey() ||
         shape2==EcShapeStateCacheKey::invalidKey()))
   {

      EcShapeStateCacheKey key1 = shape1;
      EcShapeStateCacheKey key2 = shape2;

      /// make key1 be the key with the higher manipulator index
      makeKeysCompatible(key1,key2);

      // get the manipulator indices
      const EcU32 manipID1 = key1.manipID();
      const EcU32 manipID2 = key2.manipID();
      const EcU32 linkID1 = key1.linkID();
      const EcU32 linkID2 = key2.linkID();

      EcBoolean reallocManips = EcFalse;
      EcU32 sdSize = EcU32(m_ShapeData.size());
      if ( sdSize<= manipID1)
      {
         reallocManips = EcTrue;
      }
      else
      {
         EcU32 sdrSize = EcU32(m_ShapeData[manipID1].size());
         if (sdrSize <= manipID2)
         {
            reallocManips = EcTrue;
         }
      }

      if (reallocManips)
      {
         // build the manipulator level
         // get the number of manipulators in the system
         const size_t numManips = systemNumShapes.size();

         m_ShapeData.resize(numManips);
         for (size_t ii=0;ii<numManips;++ii)
         {
            m_ShapeData[ii].resize(numManips);
         }
      }

      // check the links
      std::vector<std::vector<
      std::vector<std::vector<DataType> > > >& links
      = m_ShapeData[manipID1][manipID2];

      // when indexing in the link dimension,
      // the BASEINDEX is index (0) and the link IDs are
      // shifted by one (i.e link (0) is at link index (1)
      const EcU32 link1Index = (linkID1==EcFoundCommon::BASEINDEX ? 0:linkID1+1);
      const EcU32 link2Index = (linkID2==EcFoundCommon::BASEINDEX ? 0:linkID2+1);

      // now check if the links exist in the database
      EcBoolean reallocLinks = EcFalse;
      if (links.size() <= link1Index)
      {
         reallocLinks = EcTrue;
      }
      else
      {
         if (links[link1Index].size() <= link2Index)
         {
            reallocLinks = EcTrue;
         }
      }

      if (reallocLinks)
      {
         const size_t nLinks1 = systemNumShapes[manipID1].size();
         const size_t nLinks2 = systemNumShapes[manipID2].size();

         links.resize(nLinks1);

         for (size_t ii=0;ii<nLinks1;++ii)
         {
            links[ii].resize(nLinks2);
         }
      }

      // now check the shapes
      std::vector<std::vector<DataType> > & shapes =
         links[link1Index][link2Index];


      // now check if the shapes exist in the database
      EcU32 shapeID1 = key1.shapeID();
      EcU32 shapeID2 = key2.shapeID();

      // makeIndicesCompatible(shapeID1, shapeID2);

      EcBoolean reallocShapes = EcFalse;
      if (shapes.size() <= shapeID1)
      {
         reallocShapes = EcTrue;
      }
      else
      {
         if (shapes[shapeID1].size() <= shapeID2)
         {
            reallocShapes = EcTrue;
         }
      }

      if (reallocShapes)
      {
         // create the shape matrix for this set of links
         // get the number of shapes for each link
         const size_t numberOfShapes1 = systemNumShapes[manipID1][link1Index].size();
         const size_t numberOfShapes2 = systemNumShapes[manipID2][link2Index].size();

         shapes.resize(numberOfShapes1);

         for (size_t ii=0;ii<numberOfShapes1;++ii)
         {
            shapes[ii].resize(numberOfShapes2);
         }
      }
      /// set the value
      retVal = &shapes[shapeID1][shapeID2];
   }
   else
   {
      //status = EcFalse;
   }

   return retVal;
}


/////////////////////////////////////////////////////////////////////////
// Function:     allocateAndGetData (non-const)
// Description:  This method gets the data in the data structure,
//               allocating as required.  The default value is returned
//               if the data structure doesn't initially exist at the
//               time of this call
// I/O:          Input:  keys for the database, the system (needed for
//                       resizing if necessary)
//               Output: datum value, EcBoolean success
/////////////////////////////////////////////////////////////////////////
template<class DataType>
DataType* EcBaseShapeDataCache<DataType>::allocateAndGetData
(
   const EcShapeStateCacheKey& shape1,
   const EcShapeStateCacheKey& shape2,
   const EcInt32Vector3D& systemNumShapes
)
{
   DataType* retVal = EcNULL;

   // guard for invalid key entries
   if (!(shape1==EcShapeStateCacheKey::invalidKey() ||
         shape2==EcShapeStateCacheKey::invalidKey()))
   {

      EcShapeStateCacheKey key1 = shape1;
      EcShapeStateCacheKey key2 = shape2;

      /// make key1 be the key with the higher manipulator index
      makeKeysCompatible(key1,key2);

      // get the manipulator indices
      EcU32 manipID1 = key1.manipID();
      EcU32 manipID2 = key2.manipID();
      EcU32 linkID1 = key1.linkID();
      EcU32 linkID2 = key2.linkID();

      EcBoolean reallocManips = EcFalse;
      EcU32 sdSize = EcU32(m_ShapeData.size());
      if ( sdSize<= manipID1)
      {
         reallocManips = EcTrue;
      }
      else
      {
         EcU32 sdrSize = EcU32(m_ShapeData[manipID1].size());
         if (sdrSize <= manipID2)
         {
            reallocManips = EcTrue;
         }
      }

      if (reallocManips)
      {
         // build the manipulator level
         // get the number of manipulators in the system
         const size_t numManips = systemNumShapes.size();

         m_ShapeData.resize(numManips);
         for (size_t ii=0; ii<numManips; ++ii)
         {
            m_ShapeData[ii].resize(numManips);
         }
      }

      // check the links
      std::vector<std::vector<
      std::vector<std::vector<DataType> > > >& links
      = m_ShapeData[manipID1][manipID2];

      // when indexing in the link dimension,
      // the BASEINDEX is index (0) and the link IDs are
      // shifted by one (i.e link (0) is at link index (1)
      EcU32 link1Index = (linkID1==EcFoundCommon::BASEINDEX ? 0:linkID1+1);
      EcU32 link2Index = (linkID2==EcFoundCommon::BASEINDEX ? 0:linkID2+1);

      // now check if the links exist in the database
      EcBoolean reallocLinks = EcFalse;
      if (links.size() <= link1Index)
      {
         reallocLinks = EcTrue;
      }
      else
      {
         if (links[link1Index].size() <= link2Index)
         {
            reallocLinks = EcTrue;
         }
      }

      if (reallocLinks)
      {
         const size_t nLinks1 = systemNumShapes[manipID1].size();
         const size_t nLinks2 = systemNumShapes[manipID2].size();

         links.resize(nLinks1);

         for (size_t ii=0;ii<nLinks1;++ii)
         {
            links[ii].resize(nLinks2);
         }
      }

      // now check the shapes
      std::vector<std::vector<DataType> > & shapes =
         links[link1Index][link2Index];


      // now check if the shapes exist in the database
      EcU32 shapeID1 = key1.shapeID();
      EcU32 shapeID2 = key2.shapeID();

      // makeIndicesCompatible(shapeID1, shapeID2);

      EcBoolean reallocShapes = EcFalse;
      if (shapes.size() <= shapeID1)
      {
         reallocShapes = EcTrue;
      }
      else
      {
         if (shapes[shapeID1].size() <= shapeID2)
         {
            reallocShapes = EcTrue;
         }
      }

      if (reallocShapes)
      {
         // create the shape matrix for this set of links
         // get the number of shapes for each link
         const size_t numberOfShapes1 = systemNumShapes[manipID1][link1Index].size();
         const size_t numberOfShapes2 = systemNumShapes[manipID2][link2Index].size();

         shapes.resize(numberOfShapes1);

         for (size_t ii=0;ii<numberOfShapes1;++ii)
         {
            shapes[ii].resize(numberOfShapes2);
         }
      }
      /// set the value
      retVal = &shapes[shapeID1][shapeID2];
   }
   else
   {
      //status = EcFalse;
   }

   return retVal;

}

/////////////////////////////////////////////////////////////////////////
// Function:     getData
// Description:  This method gets the data in the existing data structure,
//               if the data structure required does not exist, it returns
//               EcFalse.
/////////////////////////////////////////////////////////////////////////
template<class DataType>
const DataType* EcBaseShapeDataCache<DataType>::getData
(
   const EcShapeStateCacheKey& shape1,
   const EcShapeStateCacheKey& shape2
) const
{
   const DataType* retVal = EcNULL;

   // guard for invalid key entries
   if (!(shape1==EcShapeStateCacheKey::invalidKey() ||
         shape2==EcShapeStateCacheKey::invalidKey()))
   {

      EcShapeStateCacheKey key1 = shape1;
      EcShapeStateCacheKey key2 = shape2;

      /// make key1 be the key with the higher manipulator index
      makeKeysCompatible(key1,key2);

      // get the manipulator indices
      EcU32 manipID1 = key1.manipID();
      EcU32 manipID2 = key2.manipID();

      if ( m_ShapeData.size()    > manipID1)
      {
         if (m_ShapeData[manipID1].size() > manipID2)
         {
            // check the links
            std::vector<std::vector<
            std::vector<std::vector<DataType> > > >& links
            = m_ShapeData[manipID1][manipID2];

            // now check if the links exist in the database
            EcU32 linkID1 = key1.linkID();
            EcU32 linkID2 = key2.linkID();

            // when indexing in the link dimension,
            // the BASEINDEX is index (0) and the link IDs are
            // shifted by one (i.e link (0) is at link index (1)
            EcU32 link1Index = (linkID1==EcFoundCommon::BASEINDEX ? 0:linkID1+1);
            EcU32 link2Index = (linkID2==EcFoundCommon::BASEINDEX ? 0:linkID2+1);

            if (links.size() > link1Index)
            {
               if (links[link1Index].size() > link2Index)
               {
                  // now check the shapes
                  std::vector<std::vector<DataType> > & shapes =
                     links[link1Index][link2Index];

                  // now check if the shapes exist in the database
                  EcU32 shapeID1 = key1.shapeID();
                  EcU32 shapeID2 = key2.shapeID();

                  // makeIndicesCompatible(shapeID1, shapeID2);
                  if (shapes.size() > shapeID1)
                  {
                     if (shapes[shapeID1].size() > shapeID2)
                     {
                        // set the data value
                        retVal = &shapes[shapeID1][shapeID2];
                     }
                     else
                     {
                        //status = EcFalse;
                     }
                  }
                  else
                  {
                     // shapes don't exist
                     //status = EcFalse;
                  }
               }
               else
               {
                  //status = EcFalse;
               }
            }
            else
            {
               //status = EcFalse;
            }
         }
         else
         {
            // links don't exist in the database
            //status = EcFalse;
         }
      }
      else
      {
         // manipulators don't not exist
         //status = EcFalse;
      }
   }
   else
   {
      // invalid key
      //status = EcFalse;
   }

   return retVal;
}




/////////////////////////////////////////////////////////////////////////
// Function:     getData
// Description:  This method gets the data in the existing data structure,
//               if the data structure required does not exist, it returns
//               EcFalse.
/////////////////////////////////////////////////////////////////////////
template<class DataType>
DataType* EcBaseShapeDataCache<DataType>::getData
(
   const EcShapeStateCacheKey& shape1,
   const EcShapeStateCacheKey& shape2
)
{
   DataType* retVal = EcNULL;

      // guard for invalid key entries
   if (!(shape1==EcShapeStateCacheKey::invalidKey() ||
         shape2==EcShapeStateCacheKey::invalidKey()))
   {

      EcShapeStateCacheKey key1 = shape1;
      EcShapeStateCacheKey key2 = shape2;

      /// make key1 be the key with the higher manipulator index
      makeKeysCompatible(key1,key2);

      // get the manipulator indices
      EcU32 manipID1 = key1.manipID();
      EcU32 manipID2 = key2.manipID();

      if ( m_ShapeData.size()    > manipID1)
      {
         if (m_ShapeData[manipID1].size() > manipID2)
         {
            // check the links
            std::vector<std::vector<
             std::vector<std::vector<DataType> > > >& links
            = m_ShapeData[manipID1][manipID2];

            // now check if the links exist in the database
            EcU32 linkID1 = key1.linkID();
            EcU32 linkID2 = key2.linkID();

            // when indexing in the link dimension,
            // the BASEINDEX is index (0) and the link IDs are
            // shifted by one (i.e link (0) is at link index (1)
            EcU32 link1Index = (linkID1==EcFoundCommon::BASEINDEX ? 0:linkID1+1);
            EcU32 link2Index = (linkID2==EcFoundCommon::BASEINDEX ? 0:linkID2+1);

            if (links.size() > link1Index)
            {
               if (links[link1Index].size() > link2Index)
               {
                  // now check the shapes
                  std::vector<std::vector<DataType> > & shapes =
                     links[link1Index][link2Index];

                  // now check if the shapes exist in the database
                  EcU32 shapeID1 = key1.shapeID();
                  EcU32 shapeID2 = key2.shapeID();

                  // makeIndicesCompatible(shapeID1, shapeID2);
                  if (shapes.size() > shapeID1)
                  {
                     if (shapes[shapeID1].size() > shapeID2)
                     {
                        // set the data value
                        retVal = &shapes[shapeID1][shapeID2];
                     }
                     else
                     {
                        //status = EcFalse;
                     }
                  }
                  else
                  {
                     // shapes don't exist
                     //status = EcFalse;
                  }
               }
               else
               {
                  //status = EcFalse;
               }
            }
            else
            {
               //status = EcFalse;
            }
         }
         else
         {
            // links don't exist in the database
            //status = EcFalse;
         }
      }
      else
      {
         // manipulators don't not exist
         //status = EcFalse;
      }
   }
   else
   {
      // invalid key
      //status = EcFalse;
   }

   return retVal;
}



/////////////////////////////////////////////////////////////////////////
// Function:     makeKeysCompatible
// Description:  Make sure the indices always access elements in the lower
//               left of the matrix. The first index must be > the second
// I/O:          See Below
/////////////////////////////////////////////////////////////////////////
template<class DataType>
EcBoolean EcBaseShapeDataCache<DataType>::makeKeysCompatible
(
   EcShapeStateCacheKey& key1,
   EcShapeStateCacheKey& key2
)const
{
   EcShapeStateCacheKey temp;
   EcBoolean retVal = EcTrue;
   if( key1.manipID() < key2.manipID())
   {
      temp = key1;
      key1 = key2;
      key2 = temp;
   }

   else if(key1.manipID() == key2.manipID())
   {
      if(key1.linkID() < key2.linkID())
      {
         temp = key1;
         key1 = key2;
         key2 = temp;
      }
      else if(key1.linkID() == key2.linkID())
      {
         EcPrint(Warning) << "EcBaseShapeDataCache<DataType>::makeKeysCompatible(): testing "<<
         "link against itself, manipulator "<< key1.manipID()<<", link "<<key1.linkID()<<"\n";
      }
   }

   return retVal;
}



/////////////////////////////////////////////////////////////////////////
// Function:     makeIndicesCompatible
// Description:  Make sure the indices always access elements in the lower
//               left of the matrix. The first index must be > the second
// I/O:          See Below
/////////////////////////////////////////////////////////////////////////
template<class DataType>
EcBoolean EcBaseShapeDataCache<DataType>::makeIndicesCompatible
(
   EcU32& index1,  // index of link
   EcU32& index2   // index of link
)const
{
   return EcTrue;
   EcBoolean retVal = EcTrue;
   if( index1 < index2 )
   {                 // then swap objID1 with objID2
                     // (this is a swap without the normal temp var)
      index1 = index1 ^ index2 ;
      index2 = index1 ^ index2 ;
      index1 = index1 ^ index2 ;
   }
   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     resizeDatabaseToSystem
// Description:  resize the database to the size of the system
// I/O:          See Below
/////////////////////////////////////////////////////////////////////////
template<class DataType>
EcBoolean EcBaseShapeDataCache<DataType>::resizeDatabaseToSystem
   (
   const EcInt32Vector3D& systemNumShapes
   )
{
   EcBoolean retVal = EcTrue;

   // build the manipulator level
   // get the number of manipulators in the system
   const size_t numManips = systemNumShapes.size();

   m_ShapeData.resize(numManips);
   for (size_t ii=0;ii<numManips;++ii)
   {
      m_ShapeData[ii].resize(numManips);
      // go through the manipulators for this manipulator
      for (size_t jj=0;jj<numManips;++jj)
      {
         // get a reference to the link matrix for this (manip,manip) pair
         std::vector<std::vector<
         std::vector<std::vector<DataType> > > >& links
         = m_ShapeData[ii][jj];

         // get the number of links in the first manipulator
         const size_t nLinks1 = systemNumShapes[ii].size(); // joints + base

         // resize the first dimension of the link matrix
         links.resize(nLinks1);

         for (size_t kk=0;kk<nLinks1;++kk)
         {
            // get the number of links in the second manipulator
            const size_t nLinks2 = systemNumShapes[jj].size(); // joints + base

            // resize the second dimension of the link matrix
            links[kk].resize(nLinks2);
            // go through the links for this manip-->link
            for (size_t xx=0;xx<nLinks2;++xx)
            {
               // get a reference to the shape matrix for this (link,link) pair
               std::vector<std::vector<DataType> > & shapes =
               links[kk][xx];

               // get the number of shapes for each link
               const size_t numberOfShapes1 = systemNumShapes[ii][kk].size();
               const size_t numberOfShapes2 = systemNumShapes[jj][xx].size();

               /// resize the first dimension of the shape matrix
               shapes.resize(numberOfShapes1);

               /// resize the second dimension of the shape matrix
               for (size_t ll=0;ll<numberOfShapes1;++ll)
               {
                  shapes[ll].resize(numberOfShapes2);
               }
            }
         }
      }
   }

   return retVal;
}

template<class DataType>
const EcToken&
EcBaseShapeDataCache<DataType>::token
   (
   ) const
{
   return EcGeom::EcBaseShapeDataCacheToken;
}
