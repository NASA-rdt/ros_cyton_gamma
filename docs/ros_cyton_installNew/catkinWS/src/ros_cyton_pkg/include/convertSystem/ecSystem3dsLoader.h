#ifndef ecSystem3dsLoader_H_
#define ecSystem3dsLoader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystem3dsLoader.h
/// @class EcSystem3dsLoader
/// @brief 3ds file loader
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseSystemLoader.h"

/// beginning of 3ds file
#define Ec3dsPrimary    0x4D4D

/// main chunk
#define Ec3dsObjectInfo 0x3D3D            ///< version of the mesh
#define Ec3dsVersion    0x0002            ///< version of the 3DS file

/// sub chunk of 3dsObjectInfo
#define Ec3dsMaterial	         0xAFFF   ///< surface properties info
   #define Ec3dsMatName          0xA000   ///< material name
   #define Ec3dsMatAmbient       0xA010   ///< ambient color
   #define Ec3dsMatDiffuse       0xA020   ///< diffuse color
   #define Ec3dsMatSpecular      0xA030   ///< specular color
   #define Ec3dsMatShininess     0xA040   ///< shininess
   #define Ec3dsMatTransparency  0xA050   ///< transparency
   #define Ec3dsMatTexture       0xA200   ///< header for texture
   #define Ec3dsMatTexFile       0xA300   ///< texture file name

#define Ec3dsGeomObj             0x4000   ///< header for geom object
   #define Ec3dsGeomMesh         0x4100   ///< beginning of mesh
   #define Ec3dsGeomVerts        0x4110   ///< vertices
   #define Ec3dsGeomFaces        0x4120   ///< faces
   #define Ec3dsGeomMatName      0x4130   ///< material name
   #define Ec3dsGeomTexVerts     0x4140   ///< texture coordinates


/// chunk info
struct EcChunkInfo
{
   unsigned short int ID;     ///< chunk ID
   unsigned int length;       ///< chunk length
   size_t bytesRead;          ///< bytes read
};

/// for vertices
class EcVectorF3
{
public:
   float x;     ///< x coordinate
   float y;     ///< y coordinate
   float z;     ///< z coordinate
};

/// for texture coordinates
class EcVectorF2
{
public:
   float x;     ///< x coordinate
   float y;     ///< y coordinate
};

/// triangle indices
struct EcTriInd
{
   EcInt32 indVerts[3];       ///< indicies for the verts
   EcInt32 indTVerts[3];      ///< indicies for the texture coordinates
};

/// material data
struct EcMaterialData
{
   char  name[255];           ///< material name
   char  texFileName[255];    ///< texture file name
   float ambient[3];          ///< The ambient color
   float diffuse[3];          ///< The diffuse color
   float specular[3];         ///< The specular color
   float shininess;           ///< The shininess
   float transparency;        ///< The transparency
   EcInt32 textureId;         ///< the texture ID

   /// Constructor - make sure and initialize variables to safe value.
   EcMaterialData
      (
      ):
   shininess(0.f),
   transparency(0.f),
   textureId(0)
   {
      name[0] = '\0';
      texFileName[0] = '\0';
      ambient [0] = ambient [1] = ambient [2] = 0.f;
      diffuse [0] = diffuse [1] = diffuse [2] = 0.f;
      specular[0] = specular[1] = specular[2] = 0.f;
   }
};

/// Geometric object data
struct EcGeomObj
{
   EcInt32   numVerts;        ///< number of verts
   EcInt32   numTexVertex;    ///< number of texture coordinates
   EcInt32   numTris;         ///< number of triangles
   EcVectorF3  *pVerts;	      ///< vertices
   EcVectorF2  *pTexVerts;    ///< texture coordinates
   EcTriInd    *pTris;        ///< triangle indices
   EcInt32   materialID;      ///< material index into m_vMaterial
   char      name[255];	      ///< The name of the object

   /// Constructor - make sure and initialize variables to safe value.
   EcGeomObj
      (
      ) :
   numVerts(0),
   numTexVertex(0),
   numTris(0),
   pVerts(EcNULL),
   pTexVerts(EcNULL),
   pTris(EcNULL),
   materialID(0)
   {
      name[0] = '\0';
   }
};

/// 3DS file loader
class EC_FOUNDATION_CONVERTSYSTEM_DECL EcSystem3dsLoader : public EcBaseSystemLoader
{
public:
   /// constructor
   EcSystem3dsLoader
      (
      );

   /// destructor
   virtual ~EcSystem3dsLoader
      (
      );

   /// copy constructor
   EcSystem3dsLoader
      (
      const EcSystem3dsLoader& orig
      );

   /// assignment operator
   EcSystem3dsLoader& operator=
      (
      const EcSystem3dsLoader& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystem3dsLoader& orig
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
   static EcSystem3dsLoader nullObject
      (
      );

   /// Set the combine Objects flag.  When set, the returned manipulator only
   /// contains one combined link.
   void setCombineObjectsFlag
      (
      EcBoolean combineObjectsFlag
      );

   /// load an .ase file as a manipulator
   /**
       \param manipulator new manipulator
       \param filename 3DS filename
       \param path path to file
       \param scale scale for points
       \retval error status
   */
   virtual EcBoolean loadManipulatorFrom3ds
      (
      EcIndividualManipulator&  manipulator,
      const EcString& filename,
      const EcString& path,
      EcReal scale = 1
      ) const;

   /// load to manipulator
   /**
       \param manipulator manipulator
       \retval error status
   */
   virtual EcBoolean loadToManipulator
      (
      EcIndividualManipulator& manipulator
      ) const;

   /// load to manipulator with tir physical extent
   virtual EcBoolean loadToManipulatorTri
      (
      EcIndividualManipulator&   manipulator      // manipulator
      ) const;

protected:

   /// load from 3DS
   /**
       \param filename 3DS filename
       \retval error status
   */
   virtual EcBoolean loadFrom3DS
      (
      const char *filename
      ) const;

   /// read string from stream
   EcInt32 readString
      (
      char *pBuffer
      ) const;

   /// read the next chunk info
   void readChunkInfo
      (
      EcChunkInfo *chunkInfo
      ) const;

   /// read next chunk
   void readNextChunk
      (
      EcChunkInfo *pPreChunkInfo
      ) const;

   /// read geom obj chunk
   void readGeomObjChunk
      (
      EcGeomObj *pObject,
      EcChunkInfo *pPreChunkInfo
      ) const;

   /// read material chunk
   void readMaterialChunk
      (
      EcChunkInfo *pPreChunkInfo
      ) const;

   /// read color chunk
   void readColorChunk
      (
      float* color,
      EcChunkInfo *pChunkInfo
      ) const;

   /// read a scalar
   void readScalarChunk
      (
      EcU32* value,
      EcChunkInfo *pChunk
      ) const;

   /// read vertices
   void readVertices
      (
      EcGeomObj *pObject,
      EcChunkInfo *pPreChunkInfo
      ) const;

   /// read vert indices
   void readVertexIndices
      (
      EcGeomObj *pObject,
      EcChunkInfo *pPreChunkInfo
      ) const;

   /// read texture coodinates
   void readTextureCoordinates
      (
      EcGeomObj *pObject,
      EcChunkInfo *pPreChunkInfo
      ) const;

   /// read material name and assign ID
   void readMaterialID
      (
      EcGeomObj *pObject,
      EcChunkInfo *pPreChunkInfo
      ) const;

   /// clear the vectors
   void clear
      (
      ) const;

   /// The file pointer
   mutable FILE *m_FilePointer;

   /// Tag for link labels
   mutable EcString m_Filename;

   /// Scale for points
   mutable EcReal m_Scale;

   /// for returning manipulator with only one link
   EcBoolean m_CombineObjectsFlag;

   /// vector of material properties
   mutable std::vector<EcMaterialData> m_vMaterials;

   /// vector of geom objects
   mutable std::vector<EcGeomObj>      m_vGeomObjs;

   /// temporary buffer for reading from file stream
   mutable EcInt32 * m_pBuffer;
};

#endif // ecSystem3dsLoader_H_
