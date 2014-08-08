#ifndef ec_ViewerContextMenu_H_
#define ec_ViewerContextMenu_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecViewerContextMenu.h
/// @class Ec::ViewerContextMenu
/// @brief Context menu support (right-click) within Ec::Viewer class.
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

#include <osgGA/GUIEventHandler>
#include <QtGui/QMenu>

namespace osg { class Node; }
namespace osgViewer { class View; }

namespace Ec
{

class EC_GUICOMMON_VIEWERCORE_DECL ViewerContextMenu : public QMenu, public osgGA::GUIEventHandler
{
   Q_OBJECT

public:
   /// Default constructor.
   explicit ViewerContextMenu
      (
      QWidget* parent ///< Owner of this menu
      );

   /// Checks incoming events to validate a context event.  A valid event is
   /// one where the user right-clicks and releases without movement.
   /// @return Whether a valid context event was created
   bool handle
      (
      const osgGA::GUIEventAdapter& ea, ///< [in] Incoming event
      osgGA::GUIActionAdapter& aa       ///< [in,out] UI/rendering action
      );

   void toolTipCheck
      (
      QEvent* event,
      osgViewer::View* pView
      );

Q_SIGNALS:
   void signalContextMenu(QMenu*);      ///< When the context menu shows
   void signalSelectedNode(osg::Node*); ///< When we have selected a node

public Q_SLOTS:
   void setCOI();

protected:
   void populateMenu();        ///< Performs menu creation and display

   EcF32 m_MouseX;             ///< Cached previous mouse X
   EcF32 m_MouseY;             ///< Cached previous mouse Y
   EcInt32 m_Button;           ///< Cached previous mouse state
   osgViewer::View* m_pView;   ///< Current view issuing context menu
   osg::Node* m_pSelectedNode; ///< Handle to selected node under cursor
};

} // namespace Ec

#endif // ec_ViewerContextMenu_H_
