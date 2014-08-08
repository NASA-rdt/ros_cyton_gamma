#ifndef ecGeometryOverwriteDescriptor_H_
#define ecGeometryOverwriteDescriptor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecGeometryOverwriteDescriptor.h
/// @class EcGeometryOverwriteDescriptor
/// @brief Holds a class for implementing a geometry overwrite descriptor.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlPairType.h>
#include <foundCommon/ecColor.h>
#include <xml/ecXmlVector.h>

/// a pair of real for UV coordinate
typedef EcXmlPairType<EcXmlReal,EcXmlReal> EcUvCoordinateType;

/// a pair of UV coordinate for line coordinate
typedef EcXmlPairType<EcUvCoordinateType,EcUvCoordinateType> EcXmlUvCoordinatePair;

/// a pair of vector for line coordinate (in xyz)
typedef EcXmlPairType<EcXmlVector,EcXmlVector> EcXmlPointVectorPair;

/** Holds a class for implementing a polygon change descriptor.
*/
class EC_FOUNDATION_GEOMETRY_DECL EcGeometryOverwriteDescriptor : public EcXmlCompoundType
{
public:
   /// default constructor
   EcGeometryOverwriteDescriptor
      (
      );

   /// destructor
   virtual ~EcGeometryOverwriteDescriptor
      (
      );

   /// copy constructor
   EcGeometryOverwriteDescriptor
      (
      const EcGeometryOverwriteDescriptor& orig
      );

   /// assignment operator
   EcGeometryOverwriteDescriptor& operator=
      (
      const EcGeometryOverwriteDescriptor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGeometryOverwriteDescriptor& orig
      ) const;

   /// get the flag indicating whether it is activated or not in the higher level
   const EcXmlBoolean& isActivatedForMarking
      (
      ) const;

   /// set the flag indicating whether it is activated or not from the higher level
   virtual void setIsActivatedForMarking
      (
      const EcXmlBoolean& isActivatedForMarking
      );

   /// get the endpoints of the line to be marked
   virtual const EcXmlPointVectorPair& markedLineEndpoints
      (
      ) const;

   /// set the endpoints of the line to be marked
   virtual void setMarkedLineEndpoints
      (
      const EcXmlPointVectorPair& markedLineEndpoints
      );

   /// get the UV coordinates of the line to be marked
   virtual const EcXmlUvCoordinatePair& markedUvCoordinates
      (
      ) const;

   /// set the UV coordinates of the line to be marked
   virtual void setMarkedUvCoordinates
      (
      const EcXmlUvCoordinatePair& markedUvCoordinates
      );

   /// get the color to use for the line segment
   virtual const EcColor& markedLinecolor
      (
      ) const;

   /// set the color to use for the line segment
   virtual void setMarkedLinecolor
      (
      const EcColor& markedLinecolor
      );

   /// get the width to use for the line segment
   virtual const EcXmlReal& markedLineWidth
      (
      ) const;

   /// set the width to use for the line segment
   virtual void setMarkedLineWidth
      (
      const EcXmlReal& markedLineWidth
      );

   /// get the flag indicating whether to use a texture map or not
   virtual const EcXmlBoolean& useTextureForMarkedLine
      (
      ) const;

   /// set the flag indicating whether to use a texture map or not
   virtual void setUseTextureForMarkedLine
      (
      const EcXmlBoolean& useTextureForMarkedLine
      );

   /// get the texture map marking level
   virtual const EcXmlU32& textureMarkingLevel
      (
      ) const;

   /// set the texture map marking level
   virtual void setTextureMarkingLevel
      (
      const EcXmlU32& textureMarkingLevel
      );

   /// get the flag indicating whether over written or not
   virtual EcBoolean overWritten
      (
      ) const;

   /// set the flag indicating whether over written or not
   virtual void setOverWritten
      (
      const EcBoolean overWritten
      ) const;

   /// initialize the geometry overwrite descriptor
   virtual void init
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// registers components with the parent
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

   /// virtual method returning the token for this object
   virtual const EcToken& token
      (
      ) const;

protected:
   /// to activate texture marking
   EcXmlBoolean         m_IsActivatedForMarking;

   /// the endpoints of the line to be created
   EcXmlPointVectorPair m_MarkedLineEndpoints;

   /// the UV coordinates of the line to be created
   EcXmlUvCoordinatePair m_MarkedUvCoordinates;

   /// the color to use for the line segment
   EcColor          m_LineColor;

   /// the width of the line segment in pixels (*)
   EcXmlReal        m_LineWidth;

   /// flag indicating whether to use a texture map or not
   EcXmlBoolean     m_UseTexture;

   /// flag indicating whether over written or not
   mutable EcXmlBoolean     m_IsOverWritten;

   /// the texture map marking level
   EcXmlU32         m_TextureMarkingLevel;
};

#endif // ecGeometryOverwriteDescriptor_H_
