#ifndef EcComPolygonalStoppingCriterion_H_
#define EcComPolygonalStoppingCriterion_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecComPolygonalStoppingCriterion.h
/// @class EcComPolygonalStoppingCriterion
/// @brief Compute the collision force at the link level
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseStoppingCriterion.h"
#include <foundCommon/ecCoordSysXForm.h>
#include <foundCommon/ecPlanarVector.h>
#include <xml/ecXmlVectorVector.h>

class EcPropagationResultData;
class EcStatedSystem;

/// Compute the collision force at the link level
class EC_FOUNDATION_MANIPULATOR_DECL EcComPolygonalStoppingCriterion : public EcBaseStoppingCriterion
{
public:
   /// constructor
   EcComPolygonalStoppingCriterion
      (
      );

   /// destructor
   virtual ~EcComPolygonalStoppingCriterion
      (
      );

   /// copy constructor
   EcComPolygonalStoppingCriterion
      (
      const EcComPolygonalStoppingCriterion& orig
      );

   /// assignment operator
   EcComPolygonalStoppingCriterion& operator=
      (
      const EcComPolygonalStoppingCriterion& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcComPolygonalStoppingCriterion& orig
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

   /// XML-initializes the class by registering the components
   virtual EcBoolean xmlInit
      (
      );

   /// A virtual constructor that returns an EcXmlObject.
   virtual EcXmlObject* clone
      (
      ) const;

   /// registers all the components for this class that are
   /// read and written to XML files.
   virtual void registerComponents
      (
      );

   /// get the polygon vertices
   virtual const EcXmlVectorVector& polygonVertices
      (
      ) const;

   /// set the polygon vertices
   virtual void setPolygonVertices
      (
      const EcXmlVectorVector& polygonVertices
      );

   /// get the collision force container
   virtual const EcString& referenceLinkLabel
      (
      ) const;

   /// set the label for the reference link
   virtual void setReferenceLinkLabel
      (
      const EcString& referenceLinkLabel
      );

   /// get descriptive text
   virtual const EcString& descriptiveText
      (
      ) const;

   /// set descriptive text
   virtual void setDescriptiveText
      (
      const EcString& descriptiveText
      );

   /// Reads class data from an XML stream.
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// Writes class data to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   static EcComPolygonalStoppingCriterion nullObject
      (
      );

   /// @copydoc EcBaseStoppingCriterion::stop()
   virtual EcBoolean stop
      (
      EcSystemActiveState&              actState,
      const EcStatedSystem&             statedSystem,
      const EcReal&                     time,
      EcU32                             manipulatorIndex,
      EcPropagationResultData&          propagationResults
      ) const;

   /// a virtual function returning the token for this class
   virtual const EcToken& token
      (
      ) const;

   /// a static function returning the token for this class
   static const EcToken& classToken
      (
      );

   /// a creator function for this class
   static EcXmlObject* creator
      (
      );

protected:

   /// calculate the planar projections and other data for the vertices
   virtual void calculatePlanarValues
      (
      );

   /// determine if a projected point (onto the planar x-y plane) is inside the polygon
   virtual EcBoolean isInsidePolygon
      (
      const EcPlanarVector& projectedPoint
      ) const;

protected:

   /// the vertices of the polygon to force to contain the COM
   EcXmlVectorVector  m_PolygonVertices;

   /// the label of the reference link; empty for system coordinates
   EcXmlString        m_ReferenceLinkLabel;

   /// descriptive text that relates the type of criterion
   EcXmlString        m_DescriptiveText;

   // non-XML below

   /// a coordinate system representing the plane of the polygon (z perpendicular)
   EcCoordinateSystemTransformation m_PolygonPlanarFrame;

   /// the vertices of the polygon in the planar frame
   EcPlanarVectorVector             m_PlanarPolygonVertices;

   /// a radius completely within the polygon
   EcReal                           m_QuickPassRadius;

   /// a radius completely outside the polygon
   EcReal                           m_QuickFailRadius;

};
#endif // EcComPolygonalStoppingCriterion_H_
