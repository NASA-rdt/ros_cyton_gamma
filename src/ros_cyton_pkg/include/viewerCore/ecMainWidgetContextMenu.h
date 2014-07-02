#ifndef ecMainWidgetContextMenu_H_
#define ecMainWidgetContextMenu_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecMainWidgetContextMenu.h
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

#include <QtGui/QMenu>

/// Forward declarations.
class EcSystemPointEvent;
namespace Ec { class PluginGUI; }

class EC_GUICOMMON_VIEWERCORE_DECL EcMainWidgetContextMenu : public QMenu
{
   Q_OBJECT

public:
   /// constructor
   EcMainWidgetContextMenu
      (
      QWidget* parent,
      Ec::PluginGUI* plugin
      );

   /// return whether any object is underneath the cursor
   virtual EcBoolean isObjectPicked
      (
      ) const;

   /// if isObjectPiced is true, return the index of the manipulator that is the first (top) one underneath the cursor.
   virtual EcU32 pickedManipulatorIndex
      (
      ) const;

   /// if isObjectPiced is true, return the index of the link that is the first (top) one underneath the cursor.
   virtual EcU32 pickedLinkIndex
      (
      ) const;

   /// if isObjectPiced is true, return the label of the link that is the first (top) one underneath the cursor.
   virtual const EcString& pickedLinkLabel
      (
      ) const;

   /// check intersection between a line segment projecting the given point in this widget's coordinates and the objects in the scene
   /**
   \param[in] pos The position of the point in the local widget's coordinates.
   \param[out] pointEvent The output containing the data of the intersection.
   */
   virtual EcBoolean checkIntersection
      (
      const QPoint& pos,
      EcSystemPointEvent &pointEvent
      ) const;

   virtual void tooltipCheck
      (
      QEvent* event,
      const EcBoolean displayLink
      ) const;

Q_SIGNALS:
   /// the signal is emitted when this context menu is about to show. This allows plugins to append their menu items to the context menu as necessary.
   void initializeContextMenu();
   void signalContextMenu(QMenu*);

public Q_SLOTS:
   /// Respond to context menu events (right click or menu button on keyboard).
   void setPos(const QPoint& pos);

protected:
   Ec::PluginGUI* m_pPlugin;         ///< Handle to owning plugin
   EcBoolean      m_IsObjectPicked;  ///< True if any object is underneath the cursor
   EcU32          m_PickedArm;       ///< Selected manipulator index.
   EcU32          m_PickedLink;      ///< Selected link index.
   EcString       m_PickedLinkLabel; ///< Selected link label.
};

#endif // ecMainWidgetContextMenu_H_
