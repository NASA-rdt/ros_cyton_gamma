#ifndef ecBasePhysicalExtentConverter_H_
#define ecBasePhysicalExtentConverter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecBasePhysicalExtentConverter.h
/// @class EcBasePhysicalExtentConverter
/// @brief Holds a description of a base class for converting
///        other object formats to XML physical extents.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>

class EcPolyPhysicalExtent;

/** Holds a description of a base class for converting physical extents.
*/
class EC_FOUNDATION_CONVERTSYSTEM_DECL EcBasePhysicalExtentConverter : public EcXmlCompoundType
{
public:
   /// default constructor
   EcBasePhysicalExtentConverter
      (
      );

   /// destructor
   virtual ~EcBasePhysicalExtentConverter
      (
      );

   /// copy constructor
   EcBasePhysicalExtentConverter
      (
      const EcBasePhysicalExtentConverter& orig
      );

   /// assignment operator
   EcBasePhysicalExtentConverter& operator=
      (
      const EcBasePhysicalExtentConverter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBasePhysicalExtentConverter& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// return a string token
   virtual const EcToken& token
      (
      ) const = 0;

   /// read a description from an istream
   virtual EcBoolean readExtentFromStream
      (
      EcPolyPhysicalExtent&    physicalExtent,
      std::istream&        stream,
      const EcString&      streamName="stream"
      ) const = 0;

   /// write a description to an ostream
   virtual EcBoolean writeExtentToStream
      (
      const EcPolyPhysicalExtent& physicalExtent,
      std::ostream&           stream
      ) const = 0;

   /// load and convert from a file
   virtual EcBoolean readExtentFromFile
      (
      EcPolyPhysicalExtent&    physicalExtent,
      const EcString&      filename,
      const EcStringVector path=EcStringVector()
      ) const;

   /// save to a file
   virtual EcBoolean writeExtentToFile
      (
      const EcPolyPhysicalExtent& physicalExtent,
      const EcString&  filename
      ) const;
};

#endif // ecBasePhysicalExtentConverter_H_
