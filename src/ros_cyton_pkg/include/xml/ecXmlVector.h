#ifndef ecXmlVector_H_
#define ecXmlVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlVector.h
/// @class EcXmlVector
/// @brief This compound type is added as wrapper to the EcVector
///        basic type.  This allows flexibility in the XML read and
///        write operations.
/// @details This class allows the elements of an EcVector to be written out and read as XML attributes.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecVector.h>
#include <xml/ecXmlObject.h>

// forward declarations.
class EcXmlVectorVector;

class EC_STABLE_XML_DECL EcXmlVector : public EcXmlObject
{
public:
   ///	#ECXMLOBJECT(cls) EcXmlObject class convenience macro
   ECXMLOBJECT(EcXmlVector);
   ECXMLOBJECT_ACCEPT(EcXmlVector)

   /// construct with a vector (implicit construction intended)
   EcXmlVector
      (
      const EcVector &orig
      );

   /// assignment operator from non-XML vector
   EcXmlVector& operator=
      (
      const EcVector &orig
      );

   /// cast to non-XML vector
   inline operator const EcVector&
      (
      ) const
   {
      return m_Vector;
   }

   /// inequality operator
   EcBoolean operator!=
      (
      const EcXmlVector &orig
      ) const;

   /// returns a value by index (0, 1, or 2) - const version.
   inline const EcReal& operator[]
      (
      EcU32 index
      ) const
   {
      return m_Vector[index];
   }

   /// returns a value by index (0, 1, or 2) - nonconst version.
   inline EcReal& operator[]
      (
      EcU32 index
      )
   {
      return m_Vector[index];
   }

   /// returns the x value of the vector
   inline const EcReal& x
      (
      ) const
   {
      return m_Vector.x();
   }

   /// returns the y value of the vector
   inline const EcReal& y
      (
      ) const
   {
      return m_Vector.y();
   }

   /// returns the z value of the vector
   inline const EcReal& z
      (
      ) const
   {
      return m_Vector.z();
   }

   /// get/set entry values
   inline void setX
      (
      const EcReal& val
      )
   {
      m_Vector.setX(val);
   }

   /// sets the x value of the vector
  inline void setY
      (
      const EcReal& val
      )
   {
      m_Vector.setY(val);
   }

   /// sets the y value of the vector
   inline void setZ
      (
      const EcReal& val
      )
   {
      m_Vector.setZ(val);
   }

   /// sets the z value of the vector
   void set
      (
      const EcReal& x,
      const EcReal& y,
      const EcReal& z
      );

   /// get the EcVector value - const version
   inline const EcVector& value
      (
      ) const
   {
      return m_Vector;
   }

   /// get the EcVector value - nonconst version
   inline EcVector& value
      (
      )
   {
      return m_Vector;
   }

   /// set the values from EcVector
   void setValue
      (
      const EcVector& value
      );

   /// read this object from an XML stream
   EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// write schema
   EcBoolean writeSchema
      (
      EcXmlSchema& stream
      ) const;

   /// read this object from a binary stream
   EcBoolean readBin
      (
      std::istream& stream
      );

   /// write this object to a binary stream
   EcBoolean writeBin
      (
      std::ostream& stream
      ) const;

   /// get an identity transformation
   static EcXmlVector nullObject
      (
      );

   /// dump result to a file for debuging
   static EcBoolean dump
      (
      const EcXmlVectorVector& points,  // vector vector
      const char* fileName
      );

protected:
   /// the actual vector representation for math processing.
   EcVector    m_Vector;
};

#endif // ecXmlVector_H_
