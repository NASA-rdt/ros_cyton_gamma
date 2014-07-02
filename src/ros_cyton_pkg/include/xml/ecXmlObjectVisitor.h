#ifndef ecXmlObjectVisitor_H_
#define ecXmlObjectVisitor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file  ecXmlObjectVisitor.h
/// @brief A class that implements the visitor pattern to operate on objects
///        derived from EcXmlObject
/// @details EcXmlObjectVisitor implements the visitor pattern to operate
///          on objects derived from EcXmlObject without exposing the
///          implementatin details within those class files.  Its main
///          purpose is to collect information about the current object
///          and its children.  It will then call the virtual method
///          to propagate the data to the derived class.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecToken.h"
#include <list>

// Forward declare all classes that we operate on.
class EcXmlObject;
class EcXmlCompoundType;
class EcXmlBaseVariableCompoundType;
class EcBaseExpressionTreeElement;
class EcPolygon;
class EcXmlOrientation;
class EcXmlVector;
class EcXmlVectorVector;
template <typename> class EcXmlBasicType;
template <typename> class EcXmlEnumType;
template <typename> class EcXmlVectorType;
template <typename> class EcXmlSetType;
template <typename> class EcXmlVariableElementType;
template <typename> class EcXmlVariableVectorType;
template <typename> class EcBaseExpressionTreeContainer;
template <typename,typename> class EcXmlMapType;
template <typename,typename> class EcXmlPairType;

/// This class implements the visitor pattern to operate on objects derived from EcXmlObject
/** This class implements the visitor pattern to operate on objects derived from EcXmlObject
    without exposing the implementatin details within those class files.
    Its main purpose is to collect information about the current object
    and its children.  It will then call the virtual method
    to propagate the data to the derived class.
*/
class EcXmlObjectVisitor
{
public:
   /// constructor
   EC_STABLE_XML_DECL EcXmlObjectVisitor
      (
      );

   /// destructor
   virtual EC_STABLE_XML_DECL ~EcXmlObjectVisitor
      (
      );

   /**
     @brief setTraversalDepth
     @param depth is the traversal depth, which defaults to -1 for inifinite depth.
   */
   virtual void EC_STABLE_XML_DECL setTraversalDepth
      (
      const EcInt32 depth = -1 // -1 means infinite.
      );

   /**
     @brief visit method for an EcXmlObject
     @param obj is a constant pointer to the EcXmlObject.
   */
   void EC_STABLE_XML_DECL visit
      (
      const EcXmlObject* obj
      );

   /**
     @brief visit method for an EcXmlCompoundType
     @param obj is a constant pointer to the EcXmlCompoundType
   */
   void EC_STABLE_XML_DECL visit
      (
      const EcXmlCompoundType* obj
      );

   /**
     @brief visit method for an EcXmlBaseVariableCompoundType
     @param obj is a constant pointer to the EcXmlBaseVariableCompoundType
   */
   void EC_STABLE_XML_DECL visit
      (
      const EcXmlBaseVariableCompoundType* obj
      );

   /**
     @brief visit method for an EcBaseExpressionTreeElement
     @param obj is a constant pointer to the EcBaseExpressionTreeElement
   */
   void EC_STABLE_XML_DECL visit
      (
      const EcBaseExpressionTreeElement* obj
      );

   /**
     @brief visit method for an EcPolygon
     @param obj is a constant pointer to the EcPolygon
   */
   void EC_FOUNDATION_GEOMETRY_DECL visit
      (
      const EcPolygon* obj
      );

   /**
     @brief visit method for EcXmlOrientation
     @param obj is a constant pointer to the EcXmlOrientation
   */
   void EC_STABLE_XML_DECL visit
      (
      const EcXmlOrientation* obj
      );

   /**
     @brief visit method for EcXmlVector
     @param obj is a constant pointer to the EcXmlVector
   */
   void EC_STABLE_XML_DECL visit
      (
      const EcXmlVector* obj
      );

   /**
     @brief visit method for EcXmlVectorVector
     @param obj is a constant pointer to the EcXmlVectorVector
   */
   void EC_STABLE_XML_DECL visit
      (
      const EcXmlVectorVector* obj
      );

   /**
     @brief visit method for EcXmlBasicType<BasicType>
     @tparam BasicType the typename
     @param obj is a constant pointer to the EcXmlBasicType<BasicType>
   */
   template <typename BasicType> void visit
      (
      const EcXmlBasicType<BasicType>* obj
      );

   /**
     @brief visit method for EcXmlEnumType<BasicType>
     @tparam BasicType the typename
     @param obj is a constant pointer to the EcXmlEnumType<BasicType>
   */
   template <typename BasicType> void visit
      (
      const EcXmlEnumType<BasicType>* obj
      );

   /**
     @brief visit method for EcXmlVectorType<ElementType>
     @tparam ElementType the typename of the vector elements
     @param obj is a constant pointer to the EcXmlVectorType<ElementType>
   */
   template <typename ElementType> void visit
      (
      const EcXmlVectorType<ElementType>* obj
      );

   /**
     @brief visit method for EcXmlSetType<ElementType>
     @tparam ElementType the typename of the set elements
     @param obj is a constant pointer to the EcXmlSetType<ElementType>
   */
   template <typename ElementType> void visit
      (
      const EcXmlSetType<ElementType>* obj
      );

   /**
     @brief visit method for EcXmlVariableElementType<ElementType>
     @tparam ElementType the typename of the variable elements
     @param obj is a constant pointer to the EcXmlVariableElementType<ElementType>
   */
   template <typename ElementType> void visit
      (
      const EcXmlVariableElementType<ElementType>* obj
      );

   /**
     @brief visit method for EcXmlVariableVectorType<ElementType>
     @tparam ElementType the typename of the variable vector elements
     @param obj is a constant pointer to the EcXmlVariableVectorType<ElementType>
   */
   template <typename ElementType> void visit
      (
      const EcXmlVariableVectorType<ElementType>* obj
      );

   /**
     @brief visit method for EcXmlMapType<KeyType, ValueType>
     @tparam KeyType the typename of the map key type
     @tparam ValueType the typename of the map value type
     @param obj is a constant pointer to the EcXmlMapType<KeyType, ValueType>
   */
   template <typename KeyType, typename ValueType> void visit
      (
      const EcXmlMapType<KeyType, ValueType>* obj
      );

   /**
     @brief visit method for EcXmlPairType<FirstType, SecondType>
     @tparam FirstType the typename of the pair's first element
     @tparam SecondType the typename of the pair's second element
     @param obj is a constant pointer to the EcXmlPairType<FirstType, SecondType>
   */
   template <typename FirstType, typename SecondType> void visit
      (
      const EcXmlPairType<FirstType, SecondType>* obj
      );

   /**
     @brief visit method for EcBaseExpressionTreeContainer<ExpressionType>
     @tparam ExpressionType the typename of the expression tree container's elements
     @param obj is a constant pointer to the EcBaseExpressionTreeContainer<ExpressionType>
   */
   template <typename ExpressionType> void visit
      (
      const EcBaseExpressionTreeContainer<ExpressionType>* obj
      );

protected:
   /**
     @brief Perform depth and consistency check to make sure a traversal can be performed.
            Notes: It will always push the object onto the parent list, even
                   if no traversal will happen.  This makes sure that the
                   entry will be popped on the back end properly.
     @param obj the xml object to traverse
     @return True if the traversal can be performed
   */
   virtual EcBoolean EC_STABLE_XML_DECL checkDepthTraversal
      (
      const EcXmlObject* obj
      );

   /// Process object after performing depth traversal.  Keeps track of parent list.
   virtual void EC_STABLE_XML_DECL afterDepthTraversal
      (
      );

   /// Gets called from derived classes to do something with the data.
   /// @return EcBoolean True to continue processing the children or elements of the
   ///                   xml object or false otherwise. This depends on the purpose
   ///                   of the visitor that's derived from this class.
   virtual EcBoolean process
      (
      ) = 0;

   /// Stack list of parent objects in the tree.
   std::list<const EcXmlObject*> m_Parents;
   /// String list giving textual description of object.
   std::list<EcString>     m_List;
   /// Token identifier for the current object.
   EcToken                 m_Token;
   /// Pointer containing current object to be processed.
   const EcXmlObject*      m_pObject;
   /// Give the ability to limit the traversal depth. -1 == infinite depth.
   EcInt32                 m_MaxTraversalDepth;
};

/// Define a standard set of statements that go in all visit methods.
#define ECXMLOBJECT_VISITOR_BEGIN() \
   m_pObject = obj; \
   m_List.clear(); \
   m_List.push_back(typeid(obj).name());

#endif // ecXmlObjectVisitor_H_
