#ifndef ecSystemTecplotLoader_H_
#define ecSystemTecplotLoader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemTecplotLoader.h
/// @class EcSystemTecplotLoader
/// @brief Tecplot file loader
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <geometry/ecBrick.h>
#include "ecBaseSystemLoader.h"
#include "ecVisualizableStatedSystem.h"

/// Tecplot file loader
class EC_FOUNDATION_CONVERTSYSTEM_DECL EcSystemTecplotLoader : public EcBaseSystemLoader
{
public:
   /// constructor
	EcSystemTecplotLoader
      (
      );

   /// destructor
	virtual ~EcSystemTecplotLoader
      (
      );

   /// copy constructor
   EcSystemTecplotLoader
      (
      const EcSystemTecplotLoader& orig
      );

   /// assignment operator
   EcSystemTecplotLoader& operator=
      (
      const EcSystemTecplotLoader& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemTecplotLoader& orig
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
   static EcSystemTecplotLoader nullObject
      (
      );

   /// Find grid zone
   /**
       \param vertex input vertex
       \param lowerBound lower bound grid data
       \param upperBound upper bound grid data
       \retval zone
   */
   EcU16 findZone
      (
      const EcVector& vertex,
      const EcRealVectorVector& lowerBound,
      const EcRealVectorVector& upperBound
      ) const;

   /// Calculate brick center
   /**
       \param brick input brick
       \param vertexVector vector of vertices
       \retval center
   */
   const EcVector brickCenter
      (
      const EcBrick& brick,
      const EcXmlVectorVector& vertexVector
      ) const;

   /// Strip white space from bounds
   /**
      \param input String containing data to be parsed
   */
   virtual void stripWhiteSpaceFromBounds
      (
      EcString& input
      ) const;

   /// Skip comment lines
   /**
      \param ifs input file stream
   */
   virtual EcString skipComments
      (
      std::ifstream& ifs
      ) const;

   /// Get bounds for value surrounded by quotes
   /**
      \param line input String containing data to be parsed
      \param pos starting string position
      \retval ending string position
   */
   virtual std::string::size_type findQuotedValue
      (
      const EcString &line,
      std::string::size_type &pos
      ) const;

protected:
   /// load from file
   /**
       \param filename tecplot filename
       \retval error status
   */
	virtual EcBoolean loadFromFile
      (
      const char *filename
      ) const;

   /// visualizable stated system
   mutable EcVisualizableStatedSystem m_VizStatedSystem;
};

#endif // ecSystemTecplotLoader_H_
