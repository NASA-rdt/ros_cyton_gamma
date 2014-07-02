#ifndef ecManipLinkWidget_H_
#define ecManipLinkWidget_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipLinkWidget.h
/// @class EcManipLinkWidget
/// @brief Widget for selecting manipulator and link
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

#include <QtGui/QWidget>

// forward declarations
namespace Ec { class PluginGUI; }
namespace Ui { class ecManipLinkWidget; }

/////////////////////////////////////////////////////////////////////////////
// EcManipLinkWidget dialog
class EC_GUICOMMON_VIEWERCORE_DECL EcManipLinkWidget : public QWidget
{
   Q_OBJECT

public:
   /// constructor
   explicit EcManipLinkWidget
      (
      Ec::PluginGUI* pPlugin
      );

   /// destructor
   virtual ~EcManipLinkWidget
      (
      );

   EcU32 currentManipulator() const;
   EcU32 currentLink() const;

Q_SIGNALS:
   void manipulatorSelected(EcU32 manipIndex);
   void linkSelected(EcU32 linkIndex);

public Q_SLOTS:
   virtual void reset();
   virtual void addManipulator
      (
      const QString& label
      );
   virtual void deleteManipulator
      (
      EcU32 index
      );

protected Q_SLOTS:
   virtual void showManip(int index);
   virtual void showLink(int row);

protected:
   /// the UI components from Qt Designer
   Ui::ecManipLinkWidget* m_pUi;
   Ec::PluginGUI*       m_pPlugin;        ///< pointer to the plugin
   EcU32                m_ManipIndex;     ///< current manipulator index
   EcU32                m_LinkIndex;      ///< current link index
   EcStringVector       m_ManipNames;     ///< names of all manipulators
};

#endif // ecManipLinkWidget_H_
