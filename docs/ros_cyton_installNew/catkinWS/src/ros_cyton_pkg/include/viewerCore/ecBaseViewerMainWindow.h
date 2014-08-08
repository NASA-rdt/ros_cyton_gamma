#ifndef ecBaseViewerMainWindow_H_
#define ecBaseViewerMainWindow_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseViewerMainWindow.h
/// @class EcBaseViewerMainWindow
/// @brief The main window for Viewer
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>

#include <QtGui/QMainWindow>
#include <boost/shared_ptr.hpp>

/// Forward declarations.
namespace Ui { class ecBaseViewer; }
class EcBaseViewerMainWidget;
class EcPreferenceDlg;
class QFileInfo;
class QMenu;
class QProcess;
class QFileDialog;
class QString;

class EC_GUICOMMON_VIEWERCORE_DECL EcBaseViewerMainWindow : public QMainWindow
{
   Q_OBJECT

public:
   /// constructor
   EcBaseViewerMainWindow
      (
      );

   /// destructor
   virtual ~EcBaseViewerMainWindow
      (
      );

   /// Initializes window and displays if necessary.
   virtual void init
      (
      const EcStringVector& args,
      EcBoolean loadPlugins = EcTrue
      );

   /// Creator method for sub-classable main rendering widget.
   virtual EcBaseViewerMainWidget *newMainWidget
      (
      );

   /// Sets the window application name for the window.  It gets coupled with
   /// the loaded filename to form '[m_XmlFilename] - m_WindowName'.
   /// \param[in] name m_WindowName to set or update titlebar if empty string.
   virtual void setWindowName
      (
      const QString &name = QString()
      );

   /// Retrieves the window application name for the window.
   /// \return const QString& Retrieves m_WindowName.
   const QString& windowName
      (
      ) const;

   /// Sets the window titlebar filename name for the window.
   /// \param[in] name m_WindowName to set or update titlebar if empty string.
   virtual void setTitleFileName
      (
      const QString &name = QString("Untitled.xml")
      );

   /// load a file into the Viewer
   virtual EcBoolean loadLocalFile
      (
      const EcString& fileName,
      bool loadPlugins = EcTrue
      );

   /// Provide a safe pointer to the main rendering widget.
   /// \return boost::weak_ptr<EcBaseViewerMainWidget> Safe handle to rendering widget.
   boost::weak_ptr<EcBaseViewerMainWidget> mainWidget
      (
      );

Q_SIGNALS:
   void signalActionsEnabled(bool); ///< Sent when file load status changes
   void signalExit();               ///< Sent when exiting application

public Q_SLOTS:
   /// File menu and toolbar actions.
   virtual void onFileClose();
   virtual void onFileExit();
   virtual void onFileOpen();
   virtual void onFileSave();
   virtual void onFileSaveAs();
   virtual void openRecentFile();

   virtual void onEditPreferences();

   /// Plugin menu actions.
   virtual void onActionLoadPlugin();
   virtual void onActionRemoveFromPluginList(QAction *action);

   /// Viewer help menu item.
   virtual void onHelpAbout();

   /// Viewer actin help menu item.
   virtual void onViewActinHelp();

   /// set maximum number of recently used files
   virtual void setMaxRecentFiles(int maxRecentFiles);

protected:
   /// Displays open dialog with specified filter(s) and then load the file into the Viewer
   virtual EcBoolean loadLocalFile
      (
      const QString& filter
      );

   /// override QMainWindow::dragEnterEvent to allow dragging to open a file
   virtual void dragEnterEvent
      (
      QDragEnterEvent *event
      );

   /// override QMainWindow::dropEvent to allow dropping to open a file
   virtual void dropEvent
      (
      QDropEvent *event
      );

   /// override QMainWindow::closeEvent to properly clean up before closing the Window
   virtual void closeEvent
      (
      QCloseEvent *event
      );

   /// check the suffix of the file info. If the suffix designates an acceptable file type (xml, xml.gz, ecz, etc.), then it returns true. Otherwise, return false.
   virtual EcBoolean checkSuffix
      (
      const QFileInfo& fileInfo
      );

   virtual void updateRecentFileActions
      (
      );

   EcBoolean checkForFileSave
      (
      );


   void disableToolBar
      (
      );
   virtual void sendCommand(const QString &cmd);


   /// the UI components from Qt Designer
   Ui::ecBaseViewer* m_pUi;
   /// Pointer to central rendering widget.
   boost::shared_ptr<EcBaseViewerMainWidget> m_pViewer;
   /// the preference dialog
   boost::shared_ptr<EcPreferenceDlg> m_pPreferenceDialog;
   /// the most recently used file
   EcString m_MruFile;
   /// the file name of the xml file loaded
   EcString m_XMLFileName;
   /// Title of window.
   QString m_WindowName;
   /// actions to open recent files
   QList<QAction*> m_vpRecentFileActions;
   /// QProcess member variable to launch help
   QProcess *m_pProcess;
};

#endif // ecBaseViewerMainWindow_H_
