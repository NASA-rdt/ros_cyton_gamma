#ifndef ecLabelAssociatedMap_H_
#define ecLabelAssociatedMap_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecLabelAssociatedMap.h
/// @class EcLabelAssociatedMap
//
//------------------------------------------------------------------------------
#include <foundCommon/ecGeneralMotion.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>

//  forward declarations
class EcIndividualManipulator;

/** Holds a label associated map.
*/
template<class ElementType>
class EcLabelAssociatedMap: public EcXmlCompoundType
{
public:
   /// default constructor
   EcLabelAssociatedMap<ElementType>
      (
      );

   /// destructor
   virtual ~EcLabelAssociatedMap<ElementType>
      (
      );

   /// copy constructor
   EcLabelAssociatedMap<ElementType>
      (
      const EcLabelAssociatedMap<ElementType>& orig
      );

   /// assignment operator
   EcLabelAssociatedMap<ElementType>& operator=
      (
      const EcLabelAssociatedMap<ElementType>& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLabelAssociatedMap<ElementType>& orig
      ) const;

   /// resize the array of associations and the label map
   /// note that values will be invalidated following a resize
   virtual void resize
      (
      EcU32 size
      );

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// set a tag tag pair collision candidate value by identifier
   virtual EcBoolean setValue
      (
      const EcString& tag1,
      const EcString& tag2,
      const ElementType val
      );

   /// set a label to the array, this will invalidate entries
   virtual void addLabel
      (
      const EcString& tag1
      );

   /// get a link-link pair collision candidate value by identifier
   virtual ElementType value
      (
      const EcString& link1,
      const EcString& link2
      )const;


   /// get the value by index
   virtual ElementType valueByIndex
      (
      EcU32 link1,
      EcU32 link2
      )const;

   /// set the value by index
   EcBoolean setValueByIndex
      (
      EcU32 link1,
      EcU32 link2,
      const ElementType& val
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

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

protected:


   /// make the indices compatible, we only use half a matrix
   /// due to symmetry.  This method will return the indices such
   /// that the entry in the lower-right triangle will always be
   /// used
   virtual EcBoolean makeIndicesCompatible
      (
      EcU32& index1,
      EcU32& index2
      )const;

   /// array of booleans describing which links can interact
   EcXmlVectorType<EcXmlVectorType<ElementType> > m_AssociationMap;

   /// array describing link identifiers
   EcXmlStringU32Map m_LabelMapping;
};

#endif // ecLabelAssociatedMap_H_
