#ifndef ecBrick_H_
#define ecBrick_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecBrick.h
/// @class EcBrick
/// @brief The class holds a list of indices and a data value for a block
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

/** The class holds a list of indices and a data value for a block
*/
class EC_FOUNDATION_GEOMETRY_DECL EcBrick : public EcXmlCompoundType
{
public:
   /// default constructor
   EcBrick
      (
      );

   /// destructor
   virtual ~EcBrick
      (
      );

   /// copy constructor
   EcBrick
      (
      const EcBrick& orig
      );

   /// assignment operator
   EcBrick& operator=
      (
      const EcBrick& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBrick& orig
      ) const;

   /// register XML components of class
   void registerComponents
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   virtual const EcToken& token
      (
      ) const;

   /// get an empty polygon
   static EcBrick nullObject
      (
      );

   /// less than operator
   EcBoolean operator<
      (
      const EcBrick& orig
      ) const;

   /// get brick
   const EcXmlU32Vector& indices
      (
      ) const;

   /// set brick
   void setIndices
      (
      const EcXmlU32Vector& indices
      );

   /// get data
   EcReal data
      (
      ) const;

   /// set data
   void setData
      (
      EcReal data
      );

protected:
   /// brick grid
   EcXmlU32Vector m_vIndices;

   /// data in brick
   EcXmlReal m_Data;
};

/// A vector of polygons
typedef EcXmlVectorType<EcBrick> EcBrickVector;

#endif // ecBrick_H_
