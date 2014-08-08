#ifndef ecShapeQueryData_H_
#define ecShapeQueryData_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeQueryData.h
/// @class EcShapeQueryData
/// @brief Defines a class used for holding input/output data for
///        shape distance/intersection queries along the shape
///        expression tree.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlVector.h>
#include <xml/ecXmlCompType.h>
#include "ecShapeQueryDescriptor.h"
#include "ecShapeQueryResult.h"

/// Holds a class to describe a shape query result
class EC_FOUNDATION_GEOMETRY_DECL EcShapeQueryData : public EcXmlCompoundType
{
public:
   /// default constructor
   EcShapeQueryData
      (
      );

   /// destructor
   virtual ~EcShapeQueryData
      (
      );

   /// copy constructor
   EcShapeQueryData
      (
      const EcShapeQueryData& orig
      );

   /// assignment operator
   EcShapeQueryData& operator=
      (
      const EcShapeQueryData& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcShapeQueryData& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// clone
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

   /// set the query descriptor
   virtual void setQueryDescriptor
      (
         const EcShapeQueryDescriptor& desc
      );

   /// get the query descriptor
   virtual const EcShapeQueryDescriptor& queryDescriptor
      (
      ) const;

   /// get the query descriptor (non-const)
   virtual  EcShapeQueryDescriptor& queryDescriptor
      (
      );

   /// set the query descriptor
   virtual void setQueryResult
      (
         const EcShapeQueryResult& result
      );

   /// get the query descriptor
   virtual const EcShapeQueryResult& queryResult
      (
      ) const;

   /// get the query descriptor (non-const)
   virtual EcShapeQueryResult& queryResult
      (
      );

   /// get token
   virtual const EcToken& token
      (
      ) const;

protected:
   /// the query description
   EcShapeQueryDescriptor m_QueryDescriptor;

   /// the query result
   EcShapeQueryResult     m_QueryResult;
};

#endif // ecShapeQueryData_H_
