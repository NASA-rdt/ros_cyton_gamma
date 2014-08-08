#ifndef ecLineAndNeighbors_H_
#define ecLineAndNeighbors_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecLineAndNeighbors.h
/// @class EcLineAndNeighbors
/// @brief Hold the lines and neighbors information
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlPairType.h>
#include <xml/ecXmlVector.h>

/// Hold the lines and neighbors information
class EC_FOUNDATION_GEOMETRY_DECL EcLineAndNeighbors : public EcXmlCompoundType
{
public:
   /// constructor
   EcLineAndNeighbors
      (
      );

   /// destructor
   virtual ~EcLineAndNeighbors
      (
      );

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

   /// get token
   virtual const EcToken& token
      (
      ) const;

   /// copy constructor
   EcLineAndNeighbors
      (
      const EcLineAndNeighbors& orig
      );

   /// assignment operator
   EcLineAndNeighbors& operator=
      (
      const EcLineAndNeighbors& orig
      );

   /// equal operator
   virtual EcBoolean operator==
      (
      const EcLineAndNeighbors& orig
      ) const;

	/// set neighbor vertex index
	void setVertexIndex0
      (
      const EcU32& number
      );

	/// set neighbor vertex index
	void setVertexIndex1
      (
      const EcU32& number
      );

    /// get neighbor vertex index
	const EcU32 vertexIndex0
      (
      ) const;

    /// get neighbor vertex index
	const EcU32 vertexIndex1
      (
      ) const;

    /// Get Normal vector of line
	const EcVector& normalVector
      (
      ) const;

	/// Set Normal vector of line
	void setNormalVector
      (
      const EcVector& normalVector
      );

	/// set line length
	void setLineLength
      (
      const EcReal& lineLength
      );

	/// get line length
	const EcReal lineLength
      (
      ) const;

	/// set neighbor facet vector
	void setFacetIndexVector
      (
      const EcXmlU32U32PairVector& facetVector
      );

	/// get neighbor facet index
	const EcXmlU32U32PairVector& facetIndexVector
      (
      ) const;

protected:
   /// the index to neighborhood vertex 0
   EcU32 m_VertexIndex0;

   /// the index to neighborhood vertex 1
   EcU32 m_VertexIndex1;

   /// the index vector to neighborhood facet
   EcXmlU32U32PairVector m_FacetIndexVector;

   /// Normal vector of line
   EcVector m_NormalVector;

   /// line length
   EcReal m_LineLength;
};

/// type of a vector of EcLineAndNeighbors
typedef EcXmlVectorType<EcLineAndNeighbors> EcLineAndNeighborsVector;

#endif // ecLineAndNeighbors_H_
