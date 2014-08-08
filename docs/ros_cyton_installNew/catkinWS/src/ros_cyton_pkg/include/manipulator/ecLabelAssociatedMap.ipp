//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecLabelAssociatedMap.ipp
//
//------------------------------------------------------------------------------
#include "ecLabelAssociatedMap.h"
#include "ecManipulatorTokens.h"
#include "ecIndManipulator.h"

// namespaces
using namespace EcManip;

/////////////////////////////////////////////////////////////////////////
// Functions:    Big four and other header functions
// Description:  Common functions
/////////////////////////////////////////////////////////////////////////

// constructor
template<class ElementType>
EcLabelAssociatedMap<ElementType>::EcLabelAssociatedMap():
EcXmlCompoundType(),
m_AssociationMap(),
m_LabelMapping()
{
}

// destructor
template<class ElementType>
EcLabelAssociatedMap<ElementType>::~EcLabelAssociatedMap
   (
   )
{
}

// copy constructor.  Also copies the parent link pointer.
template<class ElementType>
EcLabelAssociatedMap<ElementType>::EcLabelAssociatedMap
   (
   const EcLabelAssociatedMap<ElementType>& orig
   ):
EcXmlCompoundType(orig),
m_AssociationMap(orig.m_AssociationMap),
m_LabelMapping(orig.m_LabelMapping)
{
}

// assignment operator
template<class ElementType>
EcLabelAssociatedMap<ElementType>& EcLabelAssociatedMap<ElementType>::operator=
   (
   const EcLabelAssociatedMap<ElementType>& orig
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
   m_AssociationMap = orig.m_AssociationMap;
   m_LabelMapping = orig.m_LabelMapping;


   return *this;
}

// equality operator
template<class ElementType>
EcBoolean EcLabelAssociatedMap<ElementType>::operator==
   (
   const EcLabelAssociatedMap<ElementType>& orig
   ) const
{
   EcBoolean retVal=EcXmlCompoundType::operator==(orig);

   if(retVal)
   {
      if(!( m_AssociationMap == orig.m_AssociationMap))
      {
         retVal=EcFalse;
      }
   }

   if(retVal)
   {
      if(!( m_LabelMapping == orig.m_LabelMapping))
      {
         retVal=EcFalse;
      }
   }
   return retVal;
}

/////////////////////////////////////////////////////////////////////////
//End of header functions.
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// Functions:    xmlInit()
// Description:  XML-initializes the class and all parent classes.
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcLabelAssociatedMap<ElementType>::xmlInit
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
// Function:     registerComponents()
// Description:  registers all the components for this class that are
//               read and written to XML streams.
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
void EcLabelAssociatedMap<ElementType>::registerComponents
   (
   )
{
   registerComponent(EcLabelAssociatedMapToken,&m_AssociationMap);
   registerComponent(EcLabelAssociatedMapIdentifierToken,&m_LabelMapping);

}

/////////////////////////////////////////////////////////////////////////
// Function:     read()
// Description:  Reads class data from an XML stream.
// I/O:          Input stream, Output error status
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcLabelAssociatedMap<ElementType>::read
   (
   EcXmlReader& stream
   )
{
   EcBoolean retVal=EcXmlCompoundType::read(stream);

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     write()
// Description:  Writes class data to an XML stream
// I/O:          Input stream, Output error status
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcLabelAssociatedMap<ElementType>::write
   (
   EcXmlWriter& stream
   ) const
{
   EcBoolean retVal=EcXmlCompoundType::write(stream);

   return retVal;
}


/////////////////////////////////////////////////////////////////////////
// Function:     makeIndicesCompatible
// Description:  Make sure the indices always access elements in the lower
//               left of the matrix. The first index must be > the second
// I/O:          See Below
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcLabelAssociatedMap<ElementType>::makeIndicesCompatible
(
   EcU32& index1,  // index of link
   EcU32& index2   // index of link
)const
{
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


/// set a link-link pair collision candidate value by identifier
template<class ElementType>
EcBoolean EcLabelAssociatedMap<ElementType>::setValue
(
   const EcString& link1,
   const EcString& link2,
   const ElementType val
)
{
   EcBoolean retVal = EcTrue;
   // get the indices
   EcXmlU32 index1;
   if (! m_LabelMapping.lookup(EcXmlString(link1),index1))
   {
      EcPrint(Warning) << "EcLabelAssociatedMap::setValue-->label ("
             << link1 << ") does not exist";
      retVal = EcFalse;
   }
   else
   {
      EcXmlU32 index2;
      if (! m_LabelMapping.lookup(EcXmlString(link2),index2))
      {
         EcPrint(Warning) << "EcLabelAssociatedMap::setValue-->label ("
                << link1 << ") does not exist";
         retVal = EcFalse;
      }
      else
      {

         retVal = setValueByIndex
         (
            index1,
            index2,
            val
         );
      }
   }
   return retVal;

}


/// set a link-link pair collision candidate value by identifier
template<class ElementType>
ElementType EcLabelAssociatedMap<ElementType>::value
(
   const EcString& tag1,
   const EcString& tag2
)const
{
   ElementType retVal;
   // get the indices
   EcXmlU32 index1;
   if (! m_LabelMapping.lookup(EcXmlString(tag1),index1))
   {
      EcPrint(Warning) << "EcLabelAssociatedMap::value-->label does not exist";

   }
   else
   {

      EcXmlU32 index2;
      if (! m_LabelMapping.lookup(EcXmlString(tag2),index2))
      {
         EcPrint(Warning) << "EcLabelAssociatedMap::value-->label does not exist";
      }
      else
      {
         // get the value
         retVal = valueByIndex
         (
            index1,
            index2
         );
      }
   }
   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     setLinkCollisionCanditate
// Description:  set a link-link pair collision candidate value
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcLabelAssociatedMap<ElementType>::setValueByIndex
   (
   EcU32 link1,
   EcU32 link2,
   const ElementType& val
   )
{
   EcBoolean retVal = EcTrue;
   // make sure we access the lower-left
   makeIndicesCompatible(link1,link2);

   if (link1 < m_AssociationMap.size())
   {
      if (link2<m_AssociationMap[link1].size())
      {
         m_AssociationMap[link1][link2]=val;
      }
      else
      {
         EcPrint(Warning) << "EcLabelAssociatedMap::setValueByIndex value ("
                << link2 << ") exceeds link map dimension\n";
         retVal = EcFalse;
      }
   }
   else
   {
      EcPrint(Warning) << "EcLabelAssociatedMap::setValueByIndex value ("
             << link1 << ") exceeds link map dimension\n";
      retVal = EcFalse;
   }
   return retVal;
}


/////////////////////////////////////////////////////////////////////////
// Function:     valueByIndex
// Description:  get  a value by index
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
ElementType EcLabelAssociatedMap<ElementType>::valueByIndex
(
EcU32 link1,
EcU32 link2
)const
{
   ElementType retVal;
   // make sure we access the lower-left
   makeIndicesCompatible(link1,link2);
   if (link1 < m_AssociationMap.size())
   {
      if (link2<m_AssociationMap[link1].size())
      {
         retVal=m_AssociationMap[link1][link2];
      }
      else
      {
         EcPrint(Warning) << "EcLabelAssociatedMap::setLinkCollisionCanditate link value ("
                << link2 << ") exceeds link map dimension\n";
      }
   }
   else
   {
      EcPrint(Warning) << "EcLabelAssociatedMap::setLinkCollisionCanditate link value ("
             <<  link1 << ") exceeds link map dimension\n";
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     resize
// Description:  resize the array of associations and the label map
//               note that values will be invalidated following a resize
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
void  EcLabelAssociatedMap<ElementType>::resize
(
   EcU32 size
)
{
   // reserve first dimension
   m_AssociationMap.reserve(size) ;

   // reserve upper-right triangle of 2D array
   EcU32 ii;
   for(ii = 0; ii <= size; ++ii)
   {
      EcXmlVectorType<ElementType> vec ;
      m_AssociationMap.pushBack(vec) ;
      m_AssociationMap[ii].reserve(ii+1) ;

      m_LabelMapping.add(EcXmlString("null"),ii);

      EcU32 jj;
      for(jj = 0; jj <= ii; ++jj)
      {
         // set them all to false
         m_AssociationMap[ii].pushBack(ElementType()) ;
      }
   }
}

/////////////////////////////////////////////////////////////////////////
// Function:     addLabelsAndSetValue
// Description:  Adds labels to the mapping as necessary. This will invalidate
//               existing entries.
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
void  EcLabelAssociatedMap<ElementType>::addLabel
(
   const EcString& tag1
)
{
   // look for tag1
   EcXmlU32 index1;
   if (! m_LabelMapping.lookup(EcXmlString(tag1),index1))
   {
      // we need to add this label
      // this will go in the next available index
      EcU32 nextIndex = m_AssociationMap.size() ;
      EcXmlVectorType<ElementType> vec;
      vec.resize(nextIndex+1);
      m_AssociationMap.pushBack(vec);

      // add the label
      m_LabelMapping.add(tag1,nextIndex);
      // allocate space in the map

   }
}

template<class ElementType>
const EcToken&
EcLabelAssociatedMap<ElementType>::token
   (
   ) const
{
   return EcManip::EcLabelAssociatedMapToken;
}
