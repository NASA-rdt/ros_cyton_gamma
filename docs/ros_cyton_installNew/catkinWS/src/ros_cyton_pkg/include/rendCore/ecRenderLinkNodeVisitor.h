#ifndef ecRenderLinkNodeVisitor_H_
#define ecRenderLinkNodeVisitor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderLinkNodeVisitor.h
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include "ecRenderManipulator.h"

#include <foundCore/ecMacros.h>
#include <osg/MatrixTransform>
#include <osg/Group>
#include <osg/Geode>
#include <osg/NodeVisitor>
#include <osg/Drawable>
#include <ostream>

namespace Ec
{

/**
* @brief The RenderLinkNodeVisitor class
* This class is used to find all RenderManipulators and RenderLinks from the
* scene graph.
*/
class EC_RENDER_RENDCORE_DECL RenderLinkNodeVisitor : public osg::NodeVisitor
{
public:
   /// Constructor
   /// @param[in] vJoints Incoming vector to populate
   /// @param[in] traversePastManipulators Whether to traverse past manipulators
   RenderLinkNodeVisitor
      (
      EcRenderLink::RenderLinkVector& vJoints,
      bool traversePastManipulators = false
      ):
   osg::NodeVisitor(osg::NodeVisitor::UPDATE_VISITOR,
                    osg::NodeVisitor::TRAVERSE_ALL_CHILDREN),
   m_vJoints(vJoints),
   m_MaxManipCount(traversePastManipulators ? ~0 : 2)
   { m_vJoints.resize(0); }

   /// type of object we are looking for
   /// @param[in,out] node Object that could be an EcRenderLink
   void apply
      (
      osg::MatrixTransform& node
      )
   {
      EcRenderManipulator* pRenderMan = dynamic_cast<EcRenderManipulator*>(&node);
      if(pRenderMan)
      {
         m_vpManips.push_back(pRenderMan);
      }
      if(m_vpManips.size() >= m_MaxManipCount)
      {
         return;
      }

      EcRenderLink* pLink = dynamic_cast<EcRenderLink*>(&node);
      if(pLink)
      {
         m_vJoints.push_back(osg::ref_ptr<EcRenderLink>(pLink));
      }
      traverse(node);
   }

   EcRenderManipulator* getRenderManipulator
      (
      const size_t index = 0
      ) const
   {
      if(index < m_vpManips.size())
      {
         return m_vpManips.at(index);
      }
      return EcNULL;
   }

protected:
   EcRenderLink::RenderLinkVector& m_vJoints; ///< Running collection of joints.
   std::vector<EcRenderManipulator*> m_vpManips;
   EcU32 m_MaxManipCount;
};


///----------------------------------------------------------------------------------
/**
 * @brief The RenderLinkNodeRemovalVisitor class
 * Visitor class which traverses the built scene graph and removes a select property
 * as a child of every link.
 */
class EC_RENDER_RENDCORE_DECL RenderLinkNodeRemovalVisitor : public osg::NodeVisitor
{
public:
   /// Constructor
   RenderLinkNodeRemovalVisitor
      (
      EcRenderTypes::DisplayMask nodeMaskToRemove
      ):
      osg::NodeVisitor(osg::NodeVisitor::UPDATE_VISITOR,
                       osg::NodeVisitor::TRAVERSE_ALL_CHILDREN),
      m_DisplayMask(nodeMaskToRemove)
   {
   }

   /// Destructor
   virtual ~RenderLinkNodeRemovalVisitor
   (
   )
   {
      for(size_t ii=0,size=m_NodesToRemove.size(); ii<size; ++ii)
      {
         const osg::Node::ParentList& plist = m_NodesToRemove[ii]->getParents();
         for(osg::Node::ParentList::const_iterator it=plist.begin(); it!=plist.end(); ++it)
         {
            (*it)->removeChild(m_NodesToRemove[ii]);
         }
      }
   }

   /// This method gets called for every osg::MatrixTransform.  There is no easy
   /// way to specifically have an apply() method that takes an EcRenderLink as an
   /// argument.  Therefore we perform a dynamic_cast to look for them.
   virtual void apply
      (
      osg::MatrixTransform &node
      )
   {
      // First look for EcRenderManipulator types to set surface properties.
      EcRenderManipulator* pManip = dynamic_cast<EcRenderManipulator*>(&node);
      if(pManip)
      {
         pManip->unsetInitState(m_DisplayMask);
      }
      traverse(node);
   }

   /// Remove all BV nodes based on their node mask.  Ignore unset masks.
   virtual void apply
      (
      osg::Node& node
      )
   {
      EcU32 mask = node.getNodeMask();
      //EcPRINT("%s, mask=%u\n", node.getName().c_str(), mask);
      if(mask != static_cast<EcU32>(~0) && mask & m_DisplayMask)
      {
         const osg::Node::ParentList& plist = node.getParents();
         m_NodesToRemove.push_back(osg::ref_ptr<osg::Node>(&node));
      }
      else
      {
         traverse(node);
      }
   }

private:
   EcRenderTypes::DisplayMask              m_DisplayMask;
   std::vector<osg::ref_ptr<osg::Node> >   m_NodesToRemove;
};

///------------------------------------------------------------------------------
/**
 * @brief The RenderLinkWorldCoordVisitor class
 * Visitor class which traverses up from a given node that gets the world/system
 * coordinates.
 */
class EC_RENDER_RENDCORE_DECL RenderLinkWorldCoordVisitor : public osg::NodeVisitor
{
public:
   /// Constructor
   RenderLinkWorldCoordVisitor
      (
      ):
   osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_PARENTS),
   m_Matrix()
   { }

   virtual void apply
      (
      osg::Node& node
      )
   {
      if(node.getNumParents())
      {
         traverse(node);
      }
      else
      {
         m_Matrix = osg::computeLocalToWorld(getNodePath());
      }
   }

   osg::Matrix getMatrix() const { return m_Matrix; }

private:
   osg::Matrix m_Matrix;
};


///-----------------------------------------------------------------------------
/**
 * @brief The RenderParentManipLinkVisitor class
 * Node visitor to find the parent manipulator and link of a node
 */
class EC_RENDER_RENDCORE_DECL RenderParentManipLinkVisitor: public osg::NodeVisitor
{
public:
    RenderParentManipLinkVisitor() :
        m_LinkFound(EcFalse),
        m_ManipFound(EcFalse),
        m_ManipClassName("EcRenderManipulator"),
        m_LinkClassName("EcRenderLink")
    {
        setTraversalMode(osg::NodeVisitor::TRAVERSE_PARENTS);
    }

    virtual void apply( osg::Node& node )
    {

        if (m_LinkClassName.compare(node.className()) == 0)
        {
            if (! m_LinkFound)
            {
                m_ParentManipAndLink.second = node.getName();
                m_LinkFound = EcTrue;
            }
           traverse(node);
        }
        else if (m_ManipClassName.compare(node.className()) == 0)
        {
            if( ! m_ManipFound)
            {
                m_ParentManipAndLink.first = node.getName();
                m_ManipFound = EcTrue;
            }
        }
        else
        {
           traverse(node);
        }
    }

    const std::pair<EcString, EcString>& getManipAndLinkIdentifiers()
    {
        return m_ParentManipAndLink;
    }

    EcBoolean manipAndLinkFound() {return (m_ManipFound && m_LinkFound);}

protected:
    std::pair<EcString, EcString>  m_ParentManipAndLink;
    EcBoolean                      m_LinkFound;
    EcBoolean                      m_ManipFound;
    EcString                       m_ManipClassName;
    EcString                       m_LinkClassName;
};

///-----------------------------------------------------------------------------
/**
 * @brief The CollectNodesByClassNameVisitor class
 * Collects all nodes with the given class name in a vector of osg::Node*
 */
class EC_RENDER_RENDCORE_DECL CollectNodesByClassNameVisitor : public osg::NodeVisitor
{
public:
   CollectNodesByClassNameVisitor(const EcString& className)
       :
         osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN),
         m_ClassName(className)
   {
   }

   virtual void apply(osg::Node& node)
   {   if(m_ClassName.compare(node.className()) == 0)
       {
           m_NodeVec.push_back(&node);
       }
       traverse(node);
   }

   const std::vector<osg::Node*>& getNodeVec()
   {
       return m_NodeVec;
   }

protected:
   EcString m_ClassName;
   std::vector<osg::Node*> m_NodeVec;
};

///-----------------------------------------------------------------------------
/**
 * @brief The NodeGraphDisplayVisitor class
 * This node visitor will print the children of a node in
 * indented from for a quick view of the scene graph
 * The output will be sent to the std::ostream provided
 */
class EC_RENDER_RENDCORE_DECL NodeGraphDisplayVisitor : public osg::NodeVisitor
{
public:
    NodeGraphDisplayVisitor(std::ostream& outstream = std::cout) : m_Outstream(outstream), m_Level(0)
    {
        setTraversalMode(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN);
    }

    std::string spaces()
    {
        return std::string(m_Level*2, ' ');
    }

    virtual void apply( osg::Node& node )
    {
        m_Outstream << spaces() << node.libraryName() << "::"
                    << node.className() << " " << node.getName()<< std::endl;
        m_Level++;
        traverse( node );
        m_Level--;
    }

    virtual void apply( osg::Geode& geode )
    {
        m_Outstream << spaces() << geode.libraryName() << "::"
                    << geode.className() << " " << geode.getName() << std::endl;
        m_Level++;
        for ( unsigned int i=0; i<geode.getNumDrawables(); ++i )
        {
            osg::Drawable* drawable = geode.getDrawable(i);
            m_Outstream << spaces() << drawable->libraryName() << "::"
                        << drawable->className() << " " << drawable->getName() << std::endl;
        }
        traverse( geode );
        m_Level--;
    }

protected:
    std::ostream& m_Outstream;
    EcU32 m_Level;
};

///-----------------------------------------------------------------------------
/**
 * @brief The CollectNodesByNodeMaskVisitor class
 * Collects all nodes with the given node mask set in a vector of osg::Node*
 */
class EC_RENDER_RENDCORE_DECL CollectNodesByNodeMaskVisitor : public osg::NodeVisitor
{
public:
   CollectNodesByNodeMaskVisitor(const osg::Node::NodeMask& mask)
       :
         osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN),
         m_Mask(mask)
   {
   }

   virtual void apply(osg::Node& node)
   {   if(m_Mask&node.getNodeMask())
       {
           m_NodeVec.push_back(&node);
       }
       traverse(node);
   }

   const std::vector<osg::Node*>& getNodeVec()
   {
       return m_NodeVec;
   }

protected:
   osg::Node::NodeMask m_Mask;
   std::vector<osg::Node*> m_NodeVec;
};

} // namespace Ec

#endif // ecRenderLinkNodeVisitor_H_
