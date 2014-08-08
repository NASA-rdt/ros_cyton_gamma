#ifndef ecSpatialGrid_H_
#define ecSpatialGrid_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecSpatialGrid.h
/// @class EcSpatialGrid
/// @brief Holds a description of a grid of data that can be arbitrarily
///        spaced with any number of channels.  The data is represented at the grid
///        points.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

class EcImage;
class EcRealImageConversionParameters;

/** Holds a description of a grid of data that can be arbitrarily spaced with any
 number of channels.  The data is represented at the grid points.
*/
class EC_SENSOR_IMAGE_DECL EcSpatialGrid : public EcXmlCompoundType
{
public:
   /// default constructor
   EcSpatialGrid
      (
      );

   /// destructor
   virtual ~EcSpatialGrid
      (
      );

   /// copy constructor
   EcSpatialGrid
      (
      const EcSpatialGrid& orig
      );

   /// assignment operator
   EcSpatialGrid& operator=
      (
      const EcSpatialGrid& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSpatialGrid& orig
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

   /// get grid points
   virtual const EcXmlRealVectorVector& gridPoints
      (
      ) const;

   /// set grid points
   virtual void setGridPoints
      (
      const EcXmlRealVectorVector& gridPoints
      );

   /// get the number of channels
   virtual EcU32 numChannels
      (
      ) const;

   /// set the number of channels
   virtual void setNumChannels
      (
      EcU32 numChannels
      );

   /// get comments
   virtual const EcString& comments
      (
      ) const;

   /// set comments
   virtual void setComments
      (
      const EcString& comments
      );

   /// get data
   virtual const EcXmlRealVector& data
      (
      ) const;

   /// set data
   virtual void setData
      (
      const EcXmlRealVector& data
      );

   /// read in the data from a map file
   virtual EcBoolean readMap
      (
      const EcString& fileName
      );

   /// create an image from the data based on the minimum spatial grid distance
   virtual void createImage
      (
      const EcRealImageConversionParameters& conversionParameters,
      EcImage& image
      ) const;

   /// create an image from the data with the prescribed size
   virtual void createSizedImage
      (
      const EcRealImageConversionParameters& conversionParameters,
      EcU32 imageWidth,
      EcU32 imageHeight,
      EcImage& image
      ) const;

   /// build a set of conversion parameters that will maximize dynamic rage
   /// when converting to an image
   virtual void constructConversionParameters
      (
      EcRealImageConversionParameters& conversionParameters
      ) const;

   virtual const EcToken& token
      (
      ) const;

   /// get a null object
   static EcSpatialGrid nullObject
      (
      );

protected:
   /// the spatial gridpoints along each axis
   EcXmlRealVectorVector m_GridPoints;

   /// the number of channels
   EcXmlU32 m_NumChannels;

   /// string comments
   EcXmlString m_Comments;

   /// data (represented at the grid points)
   EcXmlRealVector m_Data;
};

/// A vector of image conversion parameters
typedef EcXmlVectorType<EcSpatialGrid> EcSpatialGridVector;

#endif // ecSpatialGrid_H_
