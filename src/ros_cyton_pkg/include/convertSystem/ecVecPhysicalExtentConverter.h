#ifndef ecVecPhysicalExtentConverter_H_
#define ecVecPhysicalExtentConverter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecVecPhysicalExtentConverter.h
/// @class EcVecPhysicalExtentConverter
/// @brief Holds a description of a base class for converting
///        other object formats to XML physical extents.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBasePhysicalExtentConverter.h"
#include <geometry/ecPolygonWithKey.h>

/// Holds a description of a class for converting Enigma vec files into physical extents.
class EC_FOUNDATION_CONVERTSYSTEM_DECL EcVecPhysicalExtentConverter : public EcBasePhysicalExtentConverter
{
public:
   /// default constructor
   EcVecPhysicalExtentConverter
      (
      );

   /// destructor
   virtual ~EcVecPhysicalExtentConverter
      (
      );

   /// copy constructor
   EcVecPhysicalExtentConverter
      (
      const EcVecPhysicalExtentConverter& orig
      );

   /// assignment operator
   EcVecPhysicalExtentConverter& operator=
      (
      const EcVecPhysicalExtentConverter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcVecPhysicalExtentConverter& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// read a description from an istream
   virtual EcBoolean readExtentFromStream
      (
      EcPolyPhysicalExtent&    physicalExtent,
      std::istream&        stream,
      const EcString&      streamName="stream"
      ) const;

   /// write a description to an ostream
   virtual EcBoolean writeExtentToStream
      (
      const EcPolyPhysicalExtent& physicalExtent,
      std::ostream&           stream
      ) const;

   /// a token unique to this class
   static const EcToken& classToken
      (
      );

   /// get an empty object
   static EcVecPhysicalExtentConverter nullObject
      (
      );

protected:

   /// get the next uncommented (by a #) line
   virtual EcBoolean getNextUncommentedLine
      (
      std::istream&  stream,
      EcString&      buffer
      ) const;

   /// loads an object of type MLE_OBJECT from a VEC stream
   /// adds the polygons to the collection.
   virtual EcBoolean loadMleObject
      (
      std::istream&        stream,
      const EcString&      streamName,
      EcPolygonWithKeyVector& polygons
      ) const;

   /// loads an object of type MLE_TRISTRIP from a VEC stream
   /// adds the polygons to the collection.
   virtual EcBoolean loadMleTristrip
      (
      std::istream&        stream,
      const EcString&      streamName,
      EcPolygonWithKeyVector& polygons
      ) const;

   /// loads an object of type MLE_CYL_PRIM from a VEC stream
   /// adds the polygons to the collection.
   virtual EcBoolean loadMleCylPrim
      (
      std::istream&        stream,
      const EcString&      streamName,
      EcXmlVectorVector&   points,
      EcXmlVectorVector&   normals,
      EcPolygonWithKeyVector& polygons
      ) const;

protected:
   mutable EcU32 m_LineCount;   ///< line count
};

#endif // ecVecPhysicalExtentConverter_H_
