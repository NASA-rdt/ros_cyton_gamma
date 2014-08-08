#ifndef ecBaseViewerMainWidget_H_
#define ecBaseViewerMainWidget_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseViewerMainWidget.h
/// @class EcBaseViewerMainWidget
/// @brief A widget class used to render our stated system and is
///        the main rendering widget for the Viewer application.
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include "ecSGWidgetQt.h"
#include <rendCore/ecRenderWindow.h>

// Forward declarations.
namespace Ec { class MainWidgetPlugin; }
class EcMainWidgetContextMenu;
class QMainWindow;
Q_DECLARE_METATYPE(EcU32);

class EC_GUICOMMON_VIEWERCORE_DECL EcBaseViewerMainWidget : public EcSGWidgetQt, public EcRenderWindow
{
   Q_OBJECT

public:
   explicit EcBaseViewerMainWidget
      (
      QMainWindow* mainWindow
      );

   virtual ~EcBaseViewerMainWidget
      (
      );

   /// Called by the main viewer window to finish init hooking of plugin.
   void setMainWindow
      (
      QMainWindow* mainWindow
      );

   virtual EcBoolean renderScene
      (
      );

   /// get a pointer to the stated system
   virtual const EcStatedSystem* statedSystem
      (
      ) const;

   /// return the frame rate in Hz
   EcU32 frameRate
      (
      ) const;

   /// set the frame rate in Hz
   void setFrameRate
      (
      EcU32 frameRate
      );

   /// Loads the simulation from file. Returns true if successful.
   virtual EcBoolean openFile
      (
      const EcString& fileName,
      bool loadPlugins
      );

   /// Closes down the current simulation file.
   virtual void closeFile
      (
      );

   /// Saves the current simulation to a file, with the time is set to 0 instead of the current time.
   /// Returns true if successful.
   virtual EcBoolean saveCurrentAs
      (
      const EcString& fileName,
      EcBoolean savePluginConfigs = EcFalse
      );

   /// set the state for simulation and rendering
   virtual void setState
      (
      const EcManipulatorSystemState& state
      );

   /// Displays save dialog with specified filter(s) and suffix.
   /// Allows the user to select the location and name of the saved file.
   virtual EcBoolean setSaveFileName
      (
      EcString& result,
      const EcString& filter = "Energid Files (*.ecx *.ecz);;XML Files (*.xml);;Compressed XML Files (*.xml.gz)",
      const EcString& suffix = "ecz"
      );

   /// @copydoc EcSGWindow::loadScene()
   virtual EcBoolean loadScene
      (
      );

   /// returns true if the current simulation file has plugin information saved in it
   /// else returns false
   EcBoolean  getSimPluginConfig
      (
      )const;

Q_SIGNALS:
   void signalPreRender();             ///< Issued before starting to render
   void signalPostRender();            ///< Issued after rendering complete, but before swapbuffer
   void signalFrameDone(double);       ///< Issued after rendering and swapbuffer
   void signalDeleteContents();        ///< Issued when data is cleared (Ec::Plugin::reset)
   void signalPlaybackCompleted();     ///< Issued when path playback is finished

public Q_SLOTS:
   void deleteContents();   ///< Cleanup system
   void saveImageAs();      ///< Saves current screen as an image file
   void saveDepthImageAs(); ///< Saves current depth buffer to an image file
   void setDisplayAxesHUD(bool value); ///< Sets the display mask for the axes orientation heads up display

protected:
   virtual void initializeGL
      (
      );

   virtual void paintGL
      (
      );

   /// Override event method to allow custom tooltips
   virtual bool event
      (
      QEvent* event
      );
protected:
   friend class Ec::MainWidgetPlugin;

   EcMainWidgetContextMenu* m_pContextMenu; ///< Context menu (right click)
   Ec::MainWidgetPlugin* m_pPlugin;         ///< Base plugin hooking
   QMainWindow* m_pMainWindow;              ///< Main window
};

#endif // ecBaseViewerMainWidget_H_
