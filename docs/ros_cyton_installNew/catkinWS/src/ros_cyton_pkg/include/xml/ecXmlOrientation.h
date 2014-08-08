#ifndef ecXmlOrientation_H_
#define ecXmlOrientation_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlOrientation.h
/// @class EcXmlOrientation
/// @brief Defined class for describing orientation.
///
/// @details This compound type is added as wrapper to the EcOrientation
///          basic type.  This allows us flexibility in the XML read and
///          write operations.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecOrientation.h>
#include <xml/ecXmlVectorType.h>

class EC_STABLE_XML_DECL EcXmlOrientation : public EcXmlObject
{
public:
   ///	#ECXMLOBJECT(cls) EcXmlObject class convenience macro
   ECXMLOBJECT(EcXmlOrientation);
   ECXMLOBJECT_ACCEPT(EcXmlOrientation)

   /// construct with an orientation
   EcXmlOrientation
      (
      const EcOrientation &params
      );

   /// assignment operator from an orientation
   EcXmlOrientation& operator=
      (
      const EcOrientation &other
      );

   /// cast to non-XML orientation
   inline operator const EcOrientation&
      (
      ) const
   {
      return m_Orientation;
   }

   /// inequality operator
   EcBoolean operator!=
      (
      const EcXmlOrientation &params
      ) const;

   /// get q0
   EcReal q0
      (
      ) const;

   /// get q1
   EcReal q1
      (
      ) const;

   /// get q2
   EcReal q2
      (
      ) const;

   /// get q3
   EcReal q3
      (
      ) const;

   /// get the EcOrientation value - const version
   inline const EcOrientation& value
      (
      ) const
   {
      return m_Orientation;
   }

   /// get the value - nonconst version
   inline EcOrientation& value
      (
      )
   {
      return m_Orientation;
   }

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

   /// get a no-rotation object
   static EcXmlOrientation nullObject
      (
      );

protected:
   /// the actual quaternion representation for math processing.
   EcOrientation m_Orientation;
};

/// A vector of orientations
typedef EcXmlVectorType<EcXmlOrientation> EcXmlOrientationVector;

#endif // ecXmlOrientation_H_
