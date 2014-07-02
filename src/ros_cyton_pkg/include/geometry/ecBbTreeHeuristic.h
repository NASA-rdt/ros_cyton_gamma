#ifndef ecBbTreeHeuristic_H_
#define ecBbTreeHeuristic_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecBbTreeHeuristic.h
/// @class EcBBTreeHeuristic
/// @brief A class used to describe the heuristic used by the BB tree
///        for determining when decompose the tree further.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecLineSegment.h"
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

/// Holds a class used to describe the heuristic used by the BB tree for determining when decompose the tree further.
class EC_FOUNDATION_GEOMETRY_DECL EcBBTreeHeuristic : public EcXmlCompoundType
{
public:
   /// default constructor
   EcBBTreeHeuristic
      (
      );

   /// destructor
   virtual ~EcBBTreeHeuristic
      (
      );

   /// copy constructor
   EcBBTreeHeuristic
      (
      const EcBBTreeHeuristic& orig
      );

   /// assignment operator
   EcBBTreeHeuristic& operator=
      (
      const EcBBTreeHeuristic& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBBTreeHeuristic& orig
      ) const;

   /// virtual equality
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      )const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// get the maximum tree depth
   virtual const EcU32& maxTreeDepth
      (
      )const;


   /// get the maximum tree depth
   virtual void setMaxTreeDepth
      (
      const EcU32& treeDepth
      );

   /// get the minimum primitive count
   virtual const EcU32& minPrimitiveCount
      (
      )const;


   /// set the minimum primitive count
   virtual void setMinPrimitiveCount
      (
      const EcU32& minPrimitiveCount
      );


   /// get the target primitive count
   virtual const EcU32& targetPrimitiveCount
      (
      )const;


   /// set the target primitive count
   virtual void setTargetPrimitiveCount
      (
      const EcU32& targetPrimCount
      );

   /// get the minimum error
   virtual const EcReal& minimumError
      (
      )const;

   /// set the minimum error
   virtual void setMinimumError
      (
      const EcReal& minError
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

   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get an empty polygon
   static EcBBTreeHeuristic nullObject
      (
      );

protected:
   /// maximum tree depth
   EcXmlU32 m_MaxTreeDepth;

   /// minimum primitive count
   EcXmlU32 m_MinPrimitiveCount;

   /// target primitive count
   EcXmlU32 m_TargetPrimitiveCount;

   /// minimum error required
   EcReal m_MinError;
};

#endif // ecBbTreeHeuristic_H_
