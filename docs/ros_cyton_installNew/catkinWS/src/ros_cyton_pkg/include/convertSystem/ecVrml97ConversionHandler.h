#ifndef ecVrml97ConversionHandler_H_
#define ecVrml97ConversionHandler_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecVrml97ConversionHandler.h
/// @class EcVrml97ConversionHandler
/// @brief Converter for VRML model to stated system.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <geometry/ecShapeAccumulator.h>

#include <deque>
#include <boost/array.hpp>
#include <boost/function.hpp>
#include <boost/ref.hpp>

#include <boost/version.hpp>
#if BOOST_VERSION < 103800
#   include <boost/spirit/tree/common.hpp>
#else
#   define BOOST_SPIRIT_USE_OLD_NAMESPACE
#   include <boost/spirit/include/classic_common.hpp>
#endif

// Forward declarations
class EcBasePhysicalExtent;
class EcDataMap;
class EcManipulatorLink;
class EcPolyPhysicalExtent;
class EcShape;
class EcVisualizableStatedSystem;

class EC_FOUNDATION_CONVERTSYSTEM_DECL EcVrml97ConversionHandler
{
public:
   typedef EcString::const_iterator                  IteratorT;  ///< string iterator
   typedef boost::spirit::tree_parse_info<IteratorT> ParseInfo;  ///< boost spirit tree_parse_info template

   /// constructor
   /**
   \param[in] os VRML stream
   \param[in] vss reference to visualizable stated system
   */
   EcVrml97ConversionHandler
      (
      std::ostream&               os,
      EcVisualizableStatedSystem& vss
      );

   /// parenthesis operator for creating a visualizable stated system
   void operator()
      (
      IteratorT        begin,
      IteratorT        end,
      const ParseInfo& info
      );

private:
   typedef boost::spirit::tree_match<IteratorT>  TreeMatch;           ///< boost spirit tree_match template
   typedef TreeMatch::node_t                     NodeT;               ///< boost spirit tree_match template
   typedef boost::reference_wrapper<NodeT const> NodeRef;             ///< boost reference_wrapper template
   typedef std::map<EcString, NodeRef>           NodeDefMap;          ///< map template
   typedef std::vector<NodeRef>                  NodeRefVector;       ///< vector template
   typedef boost::array<EcReal, 3>               Vec3F;               ///< boost array template
   typedef boost::array<EcReal, 4>               Vec4F;               ///< boost array template
   typedef std::vector<EcInt32>                  IntegerArray;        ///< vector template
   typedef std::vector<EcReal>                   RealArray;           ///< vector template
   typedef boost::function1<void, const NodeT&>  VisitAlgorithm;      ///< boost function template
   typedef std::deque<EcString>                  ReferenceNameStack;  ///< deque template

   /// populates node definition map
   void populateNodeDefMap
      (
      const NodeT& node
      );

   EcString referenceName
      (
      ) const;

   void registerShapePtr
      (
      EcShapeAccumulator::ShapePtr ptr
      );

   EcString uniqueName
      (
      );

   void visitAppearanceTypeNode
      (
      const NodeT& node,
      EcDataMap&   surface
      );

   void visitBackgroundNode
      (
      const NodeT& node
      );

   void visitBoxDefinition
      (
      const NodeT& node,
      EcDataMap&   surface
      );

   void visitCoordinateNode
      (
      const NodeT& node,
      RealArray&   array
      );

   void visitCylinderDefinition
      (
      const NodeT& node,
      EcDataMap&   surface
      );

   void visitGeometryTypeNode
      (
      const NodeT& node,
      EcDataMap&   surface
      );

   void visitIndexedFaceSetDefinition
      (
      const NodeT& node,
      EcDataMap&   surface
      );

   void visitMaterialDefinition
      (
      const NodeT& node,
      EcDataMap&   surface
      );

   void visitMaterialTypeNode
      (
      const NodeT& node,
      EcDataMap&   surface
      );

   void visitNode
      (
      const NodeT& node
      );

   void visitNormalNode
      (
      const NodeT& node,
      RealArray&   array
      );

   void visitReferenceableNode
      (
      const NodeT&    node,
      VisitAlgorithm& algorithm
      );

   void visitShapeNode
      (
      const NodeT& node
      );

   void visitSwitchNode
      (
      const NodeT& node
      );

   void visitTransformNode
      (
      const NodeT& node
      );

   //---
   // Static functions
   //---

   static EcBoolean checkNumChildren
      (
      const NodeT& node,
      EcU16        num,
      const char*  message
      );

   static void convert
      (
      const NodeT&  node,
      IntegerArray& array
      );

   static void convert
      (
      const RealArray&      coordArray,
      const IntegerArray&   coordIndexArray,
      const RealArray&      normalArray,
      const IntegerArray&   normalIndexArray,
      EcPolyPhysicalExtent& linkExtent
      );

   static void convert
      (
      const NodeT& node,
      RealArray&   array
      );

   static EcBoolean convertToBoolean
      (
      const NodeT& node
      );

   static EcInt32 convertToInteger
      (
      const NodeT& node
      );

   static EcReal convertToReal
      (
      const NodeT& node
      );

   static Vec3F convertToVec3f
      (
      const NodeT& node
      );

   static Vec4F convertToVec4f
      (
      const NodeT& node
      );

   static EcString getNodeUseName
      (
      const NodeT& node
      );

   static EcString nodeValueAsString
      (
      const NodeT& node
      );

   static void registerNodeDef
      (
      const NodeT& node,
      NodeDefMap&  nodeDefs
      );

   static void transformExtent
      (
      const NodeRefVector&  transformStack,
      EcBasePhysicalExtent& extent
      );

   static void transformExtent
      (
      const NodeT&          transformNode,
      EcBasePhysicalExtent& extent
      );

   typedef boost::shared_ptr<EcManipulatorLink> LinkPtr;         ///< boost shared pointer template
   typedef std::vector<LinkPtr>                 LinkPtrVector;   ///< vector template

   std::ostream&               m_os;                      ///< reference to stream
   EcVisualizableStatedSystem& m_VSS;                     ///< (output) reference to visualizable stated system

   EcBoolean                   m_LoadAsIndividualLinks;   ///< flag for loading as individual links
   ReferenceNameStack          m_RefNameStack;            ///< reference to stack of names for objects
   EcStringStringMap           m_UsedNames;               ///< map of used names
   NodeRefVector               m_TransformStack;          ///< coordinate transformation stack
   NodeDefMap                  m_NodeDefMap;              ///< map of node definitions
   Vec3F                       m_BackgroundColor;         ///< background color
   EcShapeAccumulator          m_ShapeAccumulator;        ///< group of shapes
   LinkPtrVector               m_LinkPtrVector;           ///< vector of link pointers
};

#endif // ecVrml97ConversionHandler_H_
