#ifndef ecDataMap_H_
#define ecDataMap_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecDataMap.h
/// @class EcDataMap
/// @brief Holds data organized by string maps.  Includes maps from
///        strings to strings, strings to integers, strings to reals, strings to
///        integer vectors, strings to real vectors, and strings to data maps.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>
#include <xml/ecXmlVectorType.h>

// a map of surface properties
class EcDataMap;

/// an XML-readable/writable map from string to EcDataMap
typedef EcXmlMapType<EcXmlString,EcDataMap> EcStringDataMapMap;

/// Holds data organized by string maps.
/** Includes maps from strings to
 strings, strings to integers, strings to reals, strings to integer vectors,
 strings to real vectors, and strings to data maps.
*/
class EC_FOUNDATION_FOUNDCOMMON_DECL EcDataMap : public EcXmlCompoundType
{
public:
   /// default constructor
   EcDataMap
      (
      );

   /// destructor
   virtual ~EcDataMap
      (
      );

   /// copy constructor
   EcDataMap
      (
      const EcDataMap& orig
      );

   /// assignment operator
   EcDataMap& operator=
      (
      const EcDataMap& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDataMap& orig
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

   /// add a new string/string pair
   virtual void add
      (
      const EcString& key,
      const EcString& value
      );

   /// add a new string/integer pair
   virtual void add
      (
      const EcString& key,
      const EcU32& value
      );

   /// add a new string/real pair
   virtual void add
      (
      const EcString& key,
      const EcReal& value
      );

   /// add a new string/integer-vector pair
   virtual void add
      (
      const EcString& key,
      const EcXmlU32Vector& value
      );

   /// add a new string/real-vector pair
   virtual void add
      (
      const EcString& key,
      const EcXmlRealVector& value
      );

   /// add a new string/map pair
   virtual void add
      (
      const EcString& key,
      const EcDataMap& value
      );

   /// lookup a string value.  Returns false for nonexistent key.
   virtual EcBoolean lookup
      (
      const EcString& key,
      EcString& value
      ) const;

   /// lookup an integer value.  Returns false for nonexistent key.
   virtual EcBoolean lookup
      (
      const EcString& key,
      EcU32& value
      ) const;

   /// lookup a real value.  Returns false for nonexistent key.
   virtual EcBoolean lookup
      (
      const EcString& key,
      EcReal& value
      ) const;

   /// lookup an integer-vector value.  Returns false for nonexistent key.
   virtual EcBoolean lookup
      (
      const EcString& key,
      EcXmlU32Vector& value
      ) const;

   /// lookup a real-vector value.  Returns false for nonexistent key.
   virtual EcBoolean lookup
      (
      const EcString& key,
      EcXmlRealVector& value
      ) const;

   /// lookup a map value.  Returns false for nonexistent key.
   virtual EcBoolean lookup
      (
      const EcString& key,
      EcDataMap& value
      ) const;

   /// clears all maps
   virtual void clear
      (
      );

   /// accessor for the string map
   virtual const EcXmlStringStringMap&  stringMap
      (
      ) const;

   /// accessor for the integer map
   virtual const EcXmlStringU32Map&  integerMap
      (
      ) const;

   /// accessor for the real map
   virtual const EcXmlStringRealMap&  realMap
      (
      ) const;

   /// accessor for the integer-vector map
   virtual const EcXmlStringU32VectorMap&  integerVectorMap
      (
      ) const;

   /// accessor for the real-vector map
   virtual const EcXmlStringRealVectorMap&  realVectorMap
      (
      ) const;

   /// extend this to include all the elements in the other
   /// where keys are the same and values different, the other
   /// values are taken
   virtual void extendBy
      (
      const EcDataMap& other
      );

   /// check to see if this description satisfies another
   /// by containing all the entries of the other
   virtual EcBoolean satisfies
      (
      const EcDataMap& other
      ) const;

   /// an (mostly string) token for this class
   virtual const EcToken& token
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

   /// gets an zero-information surface property
   static EcDataMap nullObject
      (
      );

   /// Create a color for bounding volume.
   static const EcDataMap& boundingColor
      (
      );

   /// Create a red color
   static const EcDataMap& redColor
      (
      );
   /// Create a blue color
   static const EcDataMap& blueColor
      (
      );
   /// Create a green color
   static const EcDataMap& greenColor
      (
      );

   /// Create a white color
   static const EcDataMap& whiteColor
      (
      );

   /// Create a yellow color
   static const EcDataMap& yellowColor
      (
      );

	/// Create a color for manipulator when not specified
	static const EcDataMap& defaultManipColor
		(
		);

protected:

   /// the string-to-string map
   EcXmlStringStringMap            m_StringMap;

   /// the string-to-integer map
   EcXmlStringU32Map               m_IntegerMap;

   /// the string-to-real map
   EcXmlStringRealMap              m_RealMap;

   /// the string-to-integer-vector map
   EcXmlStringU32VectorMap         m_IntegerVectorMap;

   /// the string-to-real-vector map
   EcXmlStringRealVectorMap        m_RealVectorMap;

   /// the string-to-data-map map
   EcStringDataMapMap*             m_pDataMapMap;

   /// a utility string
   mutable EcXmlString             m_UtilityStringForLookup;
};

/// a vector of data maps
typedef EcXmlVectorType<EcDataMap> EcDataMapVector;

/// a vector of data map vectors
typedef EcXmlVectorType<EcDataMapVector> EcDataMapVectorVector;

#endif // ecDataMap_H_
