#ifndef ecXml2DEllipse_H_
#define ecXml2DEllipse_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecXml2DEllipse.h
/// @class EcXml2DEllipse
/// @brief implementation of the EcXml2DEllipse class;
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.

#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>


#include <foundCommon/ecXml2DRectangle.h>

/*!
\class EcXml2DEllipse
\brief EcXml2DEllipse - defines 2D ellipse and circle
\version 1.0
*/
class EC_FOUNDATION_FOUNDCOMMON_DECL EcXml2DEllipse : public EcXml2DRectangle
{
public:


   /// Constructor
   EcXml2DEllipse
      (
      );

   /// Destructor
   virtual ~EcXml2DEllipse
      (
      );

   /// Copy constructor
   EcXml2DEllipse
      (
      const EcXml2DEllipse& orig
      );

   /// Copy assignment operator
   EcXml2DEllipse& operator=
      (
      const EcXml2DEllipse& orig
      );

   /// Equality operator
   EcBoolean operator==
      (
      const EcXml2DEllipse& orig
      ) const;

   /// Clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// Register components with the parent
   virtual void registerComponents
      (
      );

   /// Equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// Virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// Return a string token
   virtual const EcToken& token
      (
      ) const;

    /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );
   /// returns true if the shape allows arc else false
   virtual EcBoolean allowArcs
      (
      );

   /// returns the number of vertices used for the shape
   virtual EcU32 numVertices
      (
      );

   /// returns id for the shape
   virtual const EcString id
      (
      )const;

   /// copies the data into the newData
   virtual void copyData
      (
      EcXml2DShape* newData
      );

   /// returns true or face based on given point is inside the shape or not
   virtual EcBoolean contains
      (
      EcReal x,
      EcReal y
      );


protected:

};

#endif // EcXmlRectangularItem_H_
