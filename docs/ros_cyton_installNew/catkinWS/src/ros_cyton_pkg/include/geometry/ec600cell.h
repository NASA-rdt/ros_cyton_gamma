#ifndef ec600cell_H_
#define ec600cell_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ec600cell.h
/// @class Ec600Cell
/// @brief Provides a tool for operating with a 600-cell, a
///        four-dimensional regular polytope for 3-D orientation analysis.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecOrientation.h>
#include <xml/ecXmlVectorType.h>
#include "ecBaseOrientationSampler.h"
// XXX FIXME: selfTest requires access to protected methods.
namespace Ec { namespace test { class Ec600CellTester; } }

/** Provides a tool for operating with a 600-cell, a four-dimensional
 regular polytope for 3-D orientation analysis.
*/
class EC_FOUNDATION_GEOMETRY_DECL Ec600Cell : public EcBaseOrientationSampler
{
public:
   /// dimensions
   enum{NUM_VERTICES=120,
        NUM_EDGES=720,
        NUM_TRIANGLES=1200,
        NUM_TETRAHEDRONS=600,
        NUM_POSNEGTETRAHEDRONS=270,
        NUM_MIXTETRAHEDRONS=60,
        NUM_MIRROREDCOLLECTION=300};

   /// a number specifying an invalid sample
   enum{INVALID=0xFFFFFFFF};

   /**
    * @brief Default constructor.
    */
   Ec600Cell
      (
      );

   /**
    * @brief Destructor.
    */
   virtual ~Ec600Cell
      (
      );

   /**
    * @brief Copy constructor.
    * @param[in] orig the object to be copied
    */
   Ec600Cell
      (
      const Ec600Cell& orig
      );

   /**
    * @brief Assignment operator.
    * @param[in] orig the object to be assigned from
    * @return Ec600Cell& this
    */
   Ec600Cell& operator=
      (
      const Ec600Cell& orig
      );

   /**
    * @brief Equality operator.
    * @param[in] orig the object to be compared with
    * @details Return EcBoolean true for the same sample count.
    */
   EcBoolean operator==
      (
      const Ec600Cell& orig
      ) const;

   /**
    * @brief Get vertex from its global index.
    * @param[in] index
    * @return EcOrientation
    */
   virtual EcOrientation vertex
      (
      EcU32 index
      ) const;

   /**
    * @brief Get a global vertex index from an edge and its local index (0,1).
    * @param[in] edgeIndex
    * @param[in] vertexIndex
    * @return EcU32
    */
   virtual EcU32 edgeVertexIndex
      (
      EcU32 edgeIndex,
      EcU32 vertexIndex
      ) const;

   /**
    * @brief Get a vertex from an edge and a local index (0,1).
    * @param[in] edgeIndex
    * @param[in] vertexIndex
    * @return EcOrientation
    */
   virtual EcOrientation edgeVertex
      (
      EcU32 edgeIndex,
      EcU32 vertexIndex
      ) const;

   /**
    * @brief Get a global edge index from a triangle and a local edge index (0,1,2).
    * @param[in] triangleIndex
    * @param[in] edgeIndex
    * @return EcU32
    */
   virtual EcU32 triangleEdgeIndex
      (
      EcU32 triangleIndex,
      EcU32 edgeIndex
      ) const;

   /**
    * @brief Get a global vertex index from a triangle and a local vertex index (0,1,2).
    * @details The first two vertices are the start and finish of the first edge.
    * @param[in] triangleIndex
    * @param[in] vertexIndex
    * @return EcU32
    */
   virtual EcU32 triangleVertexIndex
      (
      EcU32 triangleIndex,
      EcU32 vertexIndex
      ) const;

   /**
    * @brief Get a vertex from a triangle and a local vertex index (0,1,2).
    * @param[in] triangleIndex
    * @param[in] vertexIndex
    * @return EcOrientation
    */
   virtual EcOrientation triangleVertex
      (
      EcU32 triangleIndex,
      EcU32 vertexIndex
      ) const;

   /**
    * @brief Get a global triangle index from a tetrahedron and a local triangle index (0,1,2,3).
    * @param[in] tetrahedronIndex
    * @param[in] triangleIndex
    * @return EcU32
    */
   virtual EcU32 tetrahedronTriangleIndex
      (
      EcU32 tetrahedronIndex,
      EcU32 triangleIndex
      ) const;

   /**
    * @brief Get a global edge index from a tetrahedron and a local edge index (0,1,2,3,4,5).
    * @details The first three edges are those for the first triangle, the next two are for the
    *          second triangle, and the last is with the third triangle.
    * @param[in] tetrahedronIndex
    * @param[in] edgeIndex
    * @return EcU32
    */
   virtual EcU32 tetrahedronEdgeIndex
      (
      EcU32 tetrahedronIndex,
      EcU32 edgeIndex
      ) const;

   /**
    * @brief Get a global vertex index from a tetrahedron and a local vertex index (0,1,2,3).
    * @details The first two are with the first edge, the third is with the second edge, and
    *          the fourth is with the fourth edge.
    * @param[in] tetrahedronIndex
    * @param[in] vertexIndex
    * @return EcU32
    */
   virtual EcU32 tetrahedronVertexIndex
      (
      EcU32 tetrahedronIndex,
      EcU32 vertexIndex
      ) const;

   /**
    * @brief Get a vertex from a tetrahedron and a local vertex index (0,1,2,3).
    * @param[in] tetrahedronIndex
    * @param[in] vertexIndex
    * @return EcOrientation
    */
   virtual EcOrientation tetrahedronVertex
      (
      EcU32 tetrahedronIndex,
      EcU32 vertexIndex
      ) const;

   /**
    * @brief Get the single tetrahedron sample count.
    * @return EcU32
    */
   virtual EcU32 singleTetrahedronSampleCount
      (
      ) const;

   /**
    * @brief Get the total count of all unique orientations.
    * @details This equals the number of samples per tetrahedron times the number of tetrahedrons.
    * @return EcU32
    */
   virtual EcU32 totalSampleCount
      (
      ) const;

   /**
    * @brief Setup for sampling (samples per radian).
    * @details The default just picks the center of each tetrahedron.  A value of
    *          0 creates no samples.
    * @param[in] samplesPerRadian
    * @return EcBoolean
    */
   virtual EcBoolean setupForSampling
      (
      const EcU32& samplesPerRadian
      );

   /**
    * @brief Get a sample.
    * @param[in] sampleIndex
    * @return EcOrientation
    */
   virtual EcOrientation sample
      (
      const EcU32& sampleIndex
      );

   /**
    * @brief Get offsets to three linearly independent neighbors (0 is returned when a neighbor is not available).
    * @param[in] sampleIndex
    * @param[out] neighborOffset0
    * @param[out] neighborOffset1
    * @param[out] neighborOffset2
    * @return void
    */
   virtual void getNeighborOffsets
      (
      EcU32 sampleIndex,
      EcInt32& neighborOffset0,
      EcInt32& neighborOffset1,
      EcInt32& neighborOffset2
      ) const;

   /**
    * @brief Get all the valid neighbors that are available, up to some maximum.
    * @details The maximum may not be available.
    * @param[in] sampleIndex
    * @param[in] maximumNumber
    * @param[out] neighborOffsets
    * @return void
    */
   virtual void getNeighborOffsets
      (
      EcU32 sampleIndex,
      EcU32 maximumNumber,
      EcXmlInt32Vector& neighborOffsets
      ) const;

   /**
    * @brief Edge length--the length of each edge in the 600-cell.
    * @return EcReal
    */
   static EcReal edgeLength
      (
      );

protected:
   /// XXX FIXME: selfTest uses protected methods!
   friend class Ec::test::Ec600CellTester;

   /**
    * @brief Setup for sampling (real increment).
    * @param[in] increment
    * @return EcBoolean
    */
   virtual EcBoolean setupForSamplingWithIncrement
      (
      EcReal increment
      );

   /**
    * @brief Setup vertices, edges, triangles, and tetrahedrons.
    * @return EcBoolean
    */
   virtual EcBoolean setup
      (
      );

   /**
    * @brief Increase the size of the barycentric array.
    * @param[in] numCoordinates
    * @return void
    */
   virtual void resizeBaryCentric
      (
      EcU32 numCoordinates
      );

   /**
    * @brief Find the member of the 300-tetrahedron collection that contains an orientation.
    * @param[in] or1
    * @return EcU32
    */
   virtual EcU32 findCollectionContainer
      (
      const EcOrientation& or1
      ) const;

   /**
    * @brief Allocate the array data.
    * @return void
    */
   virtual void allocateArrays
      (
      );

   /**
    * @brief Copy the data that is specific to the configuration.
    * @param[in] orig
    * @return void
    */
   virtual void copySpecificData
      (
      const Ec600Cell& orig
      );

   /**
    * @brief Check to see if the indices are in bounds and point to a valid neighbor in the sample array.
    * @param[in] seekSample
    * @param[in] sampleArray
    * @param[in] numStepsAlongEachAxis
    * @param[in] seekIndices
    * @return EcBoolean
    */
   virtual EcBoolean checkSampleArray
      (
      EcU32& seekSample,
      EcU32*** sampleArray,
      const EcU32 numStepsAlongEachAxis,
      const EcInt32* seekIndices
      ) const;

   /**
    * @brief Check the first numRows of a 3x3 integer array of offsets for linear dependence.
    * @param[in] array
    * @param[in] numRows
    * @return EcBoolean
    */
   virtual EcBoolean offsetsIndependent
      (
      EcInt32 array[][3],
      EcU32 numRows
      ) const;

protected:

   // the following data is always the same

   /// vertices
   EcReal**  m_Vertices;
   /// edges
   EcU32**   m_Edges;
   /// triangles
   EcU32**   m_Triangles;
   /// tetrahedrons
   EcU32**   m_Tetrahedrons;

   /// positive tetrahedrons
   EcU32*    m_PosTetrahedrons;
   /// negative tetrahedrons
   EcU32*    m_NegTetrahedrons;
   /// mix tetrahedrons
   EcU32*    m_MixTetrahedrons;

   /// tetrahedron mirrors
   EcU32*    m_TetrahedronMirrors;
   /// mirrored collection
   EcU32*    m_MirroredCollection;
   /// mirrored collection neighbors
   EcU32**   m_MirroredCollectionNeighbors;
   /// collection of start vertices
   EcReal**  m_CollectionStartVertices;
   /// collection of bases
   EcReal*** m_CollectionBases;

   // the following data varies based on setup parameters

   /// barycentric value
   EcReal*                  m_pBaryCentric;
   /// sample count of single tetrahedron
   EcU32                    m_SingleTetrahedronSampleCount;
   /// a vector of vector of neighbors
   EcXmlU32VectorVector     m_NeighborVectorVector;

   // the following is utility data
   /// utility vector of neighbors
   mutable EcXmlInt32Vector m_UtilityNeighborVector;
};

#endif // ec600cell_H_
