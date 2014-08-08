#ifndef ecCoordSysXForm_H_
#define ecCoordSysXForm_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecCoordSysXForm.h
/// @class EcCoordinateSystemTransformation
/// @brief A rotation and a translation to describe a new frame.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <matrixUtilities/ecReArray.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlEnumType.h>
#include <xml/ecXmlOrientation.h>
#include <xml/ecXmlVector.h>

// forward declarations
class EcGeneralMotion;

// XXX FIXME: selfTest requires access to protected methods.
namespace Ec { namespace test { class EcCoordinateSystemTransformationTester; } }

/** Holds a class to describe 3D rigid-body transformation.
*/
class EC_FOUNDATION_FOUNDCOMMON_DECL EcCoordinateSystemTransformation : public EcXmlCompoundType
{
public:
   /// descriptor of the type of transformation
   enum {ARBITRARY, NO_TRANSLATION, NO_ROTATION, NO_CHANGE};

   /// default constructor
   EcCoordinateSystemTransformation
      (
      );

   /// constructor with a translation and orientation
   EcCoordinateSystemTransformation
      (
      const EcVector& trans,
      const EcOrientation& orient
      );

   /// constructor with a translation (implicit conversion used in code base)
   EcCoordinateSystemTransformation
      (
      const EcVector& trans
      );

   /// constructor with an orientation (implicit conversion used in code base)
   EcCoordinateSystemTransformation
      (
      const EcOrientation& orient
      );

   /// destructor
   ~EcCoordinateSystemTransformation
      (
      );

   /// copy constructor
   EcCoordinateSystemTransformation
      (
      const EcCoordinateSystemTransformation& orig
      );

   /// assignment operator
   EcCoordinateSystemTransformation& operator=
      (
      const EcCoordinateSystemTransformation& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCoordinateSystemTransformation& orig
      ) const;

   /// initialize XML components for reading and writing
   EcBoolean xmlInit
      (
      );

   /// clone - a constructor to an EcXmlObject pointer
   EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   void registerComponents
      (
      );

   /// equality - equality to an EcXmlObject pointer
   EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// new that returns an EcXmlObject
   EcXmlObject* newObject
      (
      ) const;

   /// get mode
   EcU32 mode
      (
      ) const;

   /// get translation
   inline const EcVector& translation
      (
      ) const
   {
      return m_Translation.value();
   }

   /// set translation
   /// (For vectors, it is faster to use setTranslation() on the
   /// vector quantity than to set the three elements individually.)
   void setTranslation
      (
      const EcVector& value
      );

   /// set the translation x-value
   void setTranslationX
      (
      EcReal xValue
      );

   /// set the translation y-value
   void setTranslationY
      (
      EcReal yValue
      );

   /// set the translation z-value
   void setTranslationZ
      (
      EcReal zValue
      );

   /// get orientation
   inline const EcOrientation& orientation
      (
      ) const
   {
      return m_Orientation.value();
   }

   /// set orientation
   void setOrientation
      (
      const EcOrientation& value
      );

   /// outboard transform by a translation and rotation
   void outboardTransformBy
      (
      const EcVector& translation,
      const EcOrientation& orientation
      );

   /// outboard transform by a translation only
   void outboardTransformBy
      (
      const EcVector& translation
      );

   /// get a 4x4 transformation matrix
   EcReArray make4x4
      (
      ) const;

   /// assign a 16 element double pointer
   void assign16
      (
      EcF64* vec16
      ) const;

   /// assign a 4x4 transformation matrix
   void assign4x4
      (
      EcReArray& array
      ) const;

   /// assign a 16 element double pointer
   void setBy16
      (
      const EcF64* vec
      );

   /// set to no rotation and no translation
   void setToIdentity
      (
      );

   /// conversion to a composite
   EcCoordinateSystemTransformation& operator *=
      (
      const EcCoordinateSystemTransformation& xform2
      );

   /// transformation composition
   EcCoordinateSystemTransformation operator*
      (
      const EcCoordinateSystemTransformation& xform2
      ) const;

   /// vector transformation
   EcVector operator*
      (
      const EcVector& vec
      ) const;

   /// vector transformation in place
   void transform
      (
      EcVector& vec
      ) const;

   /// transforms a vector and puts the result in the second argument
   /// The same vector may be used for to and from.
   void transform
      (
      const EcVector& from,
      EcVector& to
      ) const;

   /// transforms two vectors - more efficient than transforming individually
   /// The same vector may be used for to and from.
   void transform
      (
      const EcVector& firstFrom,
      EcVector& firstTo,
      const EcVector& secondFrom,
      EcVector& secondTo
      ) const;

   /// test for approximate equality of transformations.
   EcBoolean approxEq
      (
      const EcCoordinateSystemTransformation& xform2,
      EcReal tol
      ) const;

   /// get the inverse of the transformation
   EcCoordinateSystemTransformation inverse
      (
      ) const;

   /// invert this transformation in place
   EcCoordinateSystemTransformation& invert
      (
      );

   /// integrates general velocity (linear and angular).
   /// The velocity is expressed in the moving coordinate
   /// system, with point of application at the origin of
   /// the moving coordinate system.
   void integrateLocalFrameVelocity
      (
      const EcGeneralMotion& locallyReferencedVelocity,
      EcReal time
      );

   /// integrates general velocity (linear and angular).
   /// The velocity is expressed in the system (nonmoving)
   /// coordinate system, with point of application at the
   /// origin of the moving coordinate system.
   void integrateReferenceFrameVelocity
      (
      const EcGeneralMotion& systemReferencedVelocity,
      EcReal time
      );

   /// set this EcCoordinateSystemTransformation object from a vector of reals
   /**
   \param[in] vector The vector of reals. Must have at least 7 elements. The first three will be used to set the translation and the last four for orientation. If it has fewer than 7 elements, this method does nothing. If it has more than 7 elements, the extra elements are ignored.
   */
   void setFromVector
      (
      const EcRealVector& vector
      );

   /// set a vector of reals from this EcCoordinateSystemTransformation object
   /**
   \param[out] vector The vector of reals. Upon return, it will have 7 elements. The first three will be used to set the translation and the last four for orientation.
   */
   void setToVector
      (
      EcRealVector& vector
      ) const;

   /// an (mostly string) token for this class
   const EcToken& token
     (
     ) const;

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

   /// get an identity transformation as a null object
   static EcCoordinateSystemTransformation nullObject
      (
      );

   /// get a static const reference
   static const EcCoordinateSystemTransformation& identity
      (
      );

   /// interpolation between two xforms
   EcBoolean interpolation
      (
      const EcCoordinateSystemTransformation& coordSysxForm1,
      const EcCoordinateSystemTransformation& coordSysXForm2,
      const EcReal& factor
      );

   /// compute and return the transformation between two vectors (from v1 to v2). This is not unique since the rotations around the vector are not considered. v1 and v2 must not be zero.
   static EcCoordinateSystemTransformation transformBetween
      (
      const EcVector& v1,
      const EcVector& v2,
      const EcVector& translation
      );
protected:
   // XXX FIXME: selfTest requires access to protected methods.
   friend class Ec::test::EcCoordinateSystemTransformationTester;

   /// set mode - use with care
   void setMode
      (
      EcU32 value
      );

protected:

   /// the offset of the transformation in the nonrotated frame
   EcXmlVector      m_Translation;

   /// the rotation of the transformation
   EcXmlOrientation m_Orientation;

   // nonXML below

   /// the mode of the transformation
   EcU32            m_Mode;

   /// an identity to return by reference
   static const EcCoordinateSystemTransformation m_theIdentity;
};

/// a vector of coordinate systems
typedef EcXmlVectorType<EcCoordinateSystemTransformation>
   EcCoordinateSystemTransformationVector;

/// a vector of vectors of coordinate systems
typedef EcXmlVectorType<EcCoordinateSystemTransformationVector>
   EcCoordinateSystemTransformationVectorVector;

#endif // ecCoordSysXForm_H_
