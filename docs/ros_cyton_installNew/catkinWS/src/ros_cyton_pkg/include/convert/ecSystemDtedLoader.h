#ifndef ecSystemDtedLoader_H_
#define ecSystemDtedLoader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemDtedLoader.h
/// @class EcSystemDtedLoader
/// @brief DTED file loader
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <convertSystem/ecBaseSystemLoader.h>
#include <convertSystem/ecVisualizableStatedSystem.h>

/// DTED file loader
class EC_RENDER_CONVERT_DECL EcSystemDtedLoader : public EcBaseSystemLoader
{
public:
   /// constructor
	EcSystemDtedLoader
      (
      );

   /// destructor
	virtual ~EcSystemDtedLoader
      (
      );

   /// copy constructor
   EcSystemDtedLoader
      (
      const EcSystemDtedLoader& orig
      );

   /// assignment operator
   EcSystemDtedLoader& operator=
      (
      const EcSystemDtedLoader& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemDtedLoader& orig
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

   /// load a file and build a visualizable stated system
   /**
       \param visStatedSystem stated system
       \param filename filename for building stated system
       \retval error status
   */
   virtual EcBoolean loadVisualizableStatedSystemFromFile
      (
      EcVisualizableStatedSystem&  visStatedSystem,
      const EcString& filename
      ) const;

   /// a token unique to this class
   static const EcToken& classToken
      (
      );

   /// get an empty object
   static EcSystemDtedLoader nullObject
      (
      );

   /// create viz stated system
   virtual void createVizStatedSystem
      (
      ) const;

   /// swap two bytes
   virtual void convert2ByteData
      (
      EcInt16& data
      ) const;

   /// swap two bytes
   virtual void swap2Bytes
      (
      char* data
      ) const;

   /// swap four bytes
   virtual void swap4Bytes
      (
      char* data
      ) const;

   /// convert latitude, longitude, and altitude to NED coordinates
   virtual EcVector latLongAlt2Ned
      (
      EcReal latitude,
      EcReal longitude,
      EcReal altitude,
      const EcVector& refEcef
      ) const;

   /// convert latitude, longitude, and altitude to ECEF coordinates
   virtual EcVector latLongAlt2Ecef
      (
      EcReal latitude,
      EcReal longitude,
      EcReal altitude
      ) const;

   /// convert latitude, and longitude to coordinate transform to NED
   virtual EcOrientation latLong2NedTransform
      (
      EcReal latitude,
      EcReal longitude
      ) const;

   /// initialize loader
   virtual void init
      (
      ) const;

   /// get max latitude
   virtual EcReal maxLatitude
      (
      ) const;

   /// set max latitude
   virtual void setMaxLatitude
      (
      EcReal input
      );

   /// get min latitude
   virtual EcReal minLatitude
      (
      ) const;

   /// set min latitude
   virtual void setMinLatitude
      (
      EcReal input
      );

   /// get max longitude
   virtual EcReal maxLongitude
      (
      ) const;

   /// set max longitude
   virtual void setMaxLongitude
      (
      EcReal input
      );

   /// get min longitude
   virtual EcReal minLongitude
      (
      ) const;

   /// set min longitude
   virtual void setMinLongitude
      (
      EcReal input
      );

   /// get bitmap filename
   virtual const EcString& bitmapFilename
      (
      ) const;

   /// set bitmap filename
   virtual void setBitmapFilename
      (
      const EcString&
      );

   /// set reference ECEF
   virtual void setRefEcef
      (
      const EcVector&
      );

protected:
   /// load from file
   /**
       \param[in] dtedFilename dted filename
       \param[in] bitmapFilename dted filename
       \param[in] leftX left clip distance
       \param[in] topY top clip distance
       \param[in] rightX right clip distance
       \param[in] bottomY bottom clip distance
       \retval error status
   */
	virtual EcBoolean loadFromFile
      (
      const char* dtedFilename,
      const char* bitmapFilename=0,
      EcReal leftX=0.0,
      EcReal topY=0.0,
      EcReal rightX=1.0,
      EcReal bottomY=1.0
      ) const;

   /// visualizable stated system
   mutable EcVisualizableStatedSystem m_VizStatedSystem;

   /// flag for creating visualizable stated system
   mutable EcBoolean m_CreateVizStatedSystem;

   /// reference ECEF location
   mutable EcVector m_RefEcef;

   /// vertex vector
   mutable EcXmlVectorVector m_VertexVector;

   /// surface properties
   mutable EcStringDataMapMap m_Surfaces;

   /// triangle vector
   mutable EcXmlStringTriangleVectorPairVector m_SurfaceKeyTrisPairVector;

   /// raster map
   mutable EcPlanarVectorVector m_RasterMapPoints;

   /// File counter
   mutable EcU16 m_FileCount;

   /// Max latitude
   mutable EcReal m_MaxLatitudeDegree;

   /// Min latitude
   mutable EcReal m_MinLatitudeDegree;

   /// Max longitude
   mutable EcReal m_MaxLongitudeDegree;

   /// Min Longitude
   mutable EcReal m_MinLongitudeDegree;

   /// Bitmap filename
   mutable EcString m_BitmapFilename;
};

#endif // ecSystemDtedLoader_H_
