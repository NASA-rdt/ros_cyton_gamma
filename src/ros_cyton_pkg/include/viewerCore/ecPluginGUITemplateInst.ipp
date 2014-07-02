//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecPluginGUITemplateInst.ipp
/// @brief Template instantiation of setParam, getParam and param methods.
///        These items are the only valid combinations of CommandType and
///        variable type that we allow.  Performs compile-time checking
///        of parameters to ensure proper usage.  This file needs to be
///        included before template specialization definitions on windows
///        but after definitions on other platforms.
/// @details Plugin template instantiations of allowed types.
///
/// NOTE - The use of generic types that can be declared in other ways is
/// discouraged.  For example an EcU32 may be specified as an EcInt32 or
/// another compatible type.  This causes the user to explicitly cast it into
/// and EcU32 to resolve the symbol and might not necessarily be intuitive.
/// Forcing it to a typedef or other type is preferable to remove potential
/// confusion.
//
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Provide convenience macros to forward declare specific parameter types.
//------------------------------------------------------------------------------


/// Qt signal connection and disconnection
#define FWD_DECL_SIGNAL(T) \
   EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL template EC_GUICOMMON_VIEWERCORE_DECL EcBoolean \
   PluginGUI::connectSignal<T>(const char*, QObject*); \
   template EC_GUICOMMON_VIEWERCORE_DECL EcBoolean \
   PluginGUI::disconnectSignal<T>(QObject*, const char*)

// Explicit instantiations for the Qt objects we support with the getPtr() call.
#define FWD_DECL_GETPTR(T) \
   template EC_GUICOMMON_VIEWERCORE_DECL T* PluginGUI::getPtr<T>(const QString&)

/// Convert an PluginGUI parameter to an Plugin parameter type.
#define FWD_DECL_GUIPARAM(T1,T2) \
   EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL template EC_GUICOMMON_VIEWERCORE_DECL const T2 \
   Plugin::param<T1, T2>() const

/// setParam that takes two additional arguments
#define FWD_DECL_GUIS2PARAM(T1,T2) \
   EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL template EC_GUICOMMON_VIEWERCORE_DECL EcBoolean \
   Plugin::setParam<T1,T2>(const EcU32, const EcU32, const T2&)

/// setParam that takes one additional arguments
#define FWD_DECL_GUIS1PARAM(T1,T2) \
   EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL template EC_GUICOMMON_VIEWERCORE_DECL EcBoolean \
   Plugin::setParam<T1,T2>(const EcU32, const T2&)

/// setParam that takes no additional arguments
#define FWD_DECL_GUIS0PARAM(T1,T2) \
   EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL template EC_GUICOMMON_VIEWERCORE_DECL EcBoolean \
   Plugin::setParam<T1,T2>(const T2&)

/// getParam that takes two additional arguments
#define FWD_DECL_GUIG2PARAM(T1,T2) \
   EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL template EC_GUICOMMON_VIEWERCORE_DECL EcBoolean \
   Plugin::getParam<T1,T2>(const EcU32, const EcU32, T2&) const

/// getParam that takes no additional arguments
#define FWD_DECL_GUIG0PARAM(T1,T2) \
   EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL template EC_GUICOMMON_VIEWERCORE_DECL EcBoolean \
   Plugin::getParam<T1,T2>(T2&) const

#define FWD_DECL_GUISG0PARAM(T1,T2) FWD_DECL_GUIS0PARAM(T1,T2); FWD_DECL_GUIG0PARAM(T1,T2)
#define FWD_DECL_GUISG2PARAM(T1,T2) FWD_DECL_GUIS2PARAM(T1,T2); FWD_DECL_GUIG2PARAM(T1,T2)

FWD_DECL_GUISG0PARAM(BackgroundColor,     EcColor);
FWD_DECL_GUIPARAM   (BackgroundColor,     EcColor);

FWD_DECL_GUIS0PARAM (Cursor,              EcU32);

// Add in osg argument version of ActualEndEffector
FWD_DECL_GUIG2PARAM (ActualEndEffector,   osg::Matrixd);
FWD_DECL_GUIG2PARAM (ActualEndEffector,   osg::Vec3d);
FWD_DECL_GUIG2PARAM (ActualEndEffector,   osg::Quat);

// Add in osg argument version of DesiredEndEffector
FWD_DECL_GUISG2PARAM(DesiredEndEffector,  osg::Matrixd);
FWD_DECL_GUISG2PARAM(DesiredEndEffector,  osg::Vec3d);
FWD_DECL_GUISG2PARAM(DesiredEndEffector,  osg::Quat);

FWD_DECL_GUIS1PARAM (DisplayMask,         EcBoolean);
FWD_DECL_GUIPARAM   (DisplayMask,         EcU32);

FWD_DECL_GUIS0PARAM (FrameRate,           EcU32);
FWD_DECL_GUIPARAM   (FrameRate,           EcU32);

FWD_DECL_GUISG0PARAM(GuideFrame,          EcCoordinateSystemTransformation);
FWD_DECL_GUIPARAM   (GuideFrame,          EcCoordinateSystemTransformation);
FWD_DECL_GUISG0PARAM(GuideFrame,          osg::Matrixd);
FWD_DECL_GUIPARAM   (GuideFrame,          osg::Matrixd);

FWD_DECL_GUIPARAM   (Height,              EcU32);

FWD_DECL_GUISG0PARAM(PovParameters,       EcPovParameters);
FWD_DECL_GUIPARAM   (PovParameters,       EcPovParameters);

FWD_DECL_GUIS0PARAM (SelectedArm,         EcU32);
FWD_DECL_GUIPARAM   (SelectedArm,         EcU32);

FWD_DECL_GUIS0PARAM (SelectedEndEffector, EcU32);
FWD_DECL_GUIPARAM   (SelectedEndEffector, EcU32);

FWD_DECL_GUIS0PARAM (Signal,              GuiParamTypeEnum);

FWD_DECL_GUIS0PARAM (SystemReady,         EcBoolean);
FWD_DECL_GUIPARAM   (SystemReady,         EcBoolean);

FWD_DECL_GUIS1PARAM (ViewerAttribute,     EcBoolean);
FWD_DECL_GUIPARAM   (ViewerAttribute,     EcU32);

FWD_DECL_GUISG0PARAM(VisualizationParameters, EcVisualizationParameters);

FWD_DECL_GUIPARAM   (Width,               EcU32);

/// These are specialized instantiations within the library.  Pre-declare on windows.
EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL FWD_DECL_GETPTR(EcBaseViewerMainWidget);
EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL FWD_DECL_GETPTR(EcRenderWindow);
EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL FWD_DECL_GETPTR(Viewer);
EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL FWD_DECL_GETPTR(RenderHUD);
EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL FWD_DECL_GETPTR(osg::Group);
EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL FWD_DECL_GETPTR(osgViewer::View);
EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL FWD_DECL_GETPTR(osgViewer::CompositeViewer);
EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL FWD_DECL_GETPTR(osgViewer::Viewer);
EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL FWD_DECL_GETPTR(QMainWindow);
EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL FWD_DECL_GETPTR(QMenu);
EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL FWD_DECL_GETPTR(QMenuBar);
EC_GUICOMMON_VIEWERCORE_PRETEMPLATE_DECL FWD_DECL_GETPTR(QStatusBar);

/// These are standard instantiations we want symbols generated for.
FWD_DECL_GETPTR(QAction);
FWD_DECL_GETPTR(QActionGroup);
FWD_DECL_GETPTR(QDockWidget);
FWD_DECL_GETPTR(QTabWidget);
FWD_DECL_GETPTR(QToolBar);
FWD_DECL_GETPTR(QToolButton);

FWD_DECL_SIGNAL(SignalContextMenu);
FWD_DECL_SIGNAL(SignalPreRender);
FWD_DECL_SIGNAL(SignalPostRender);
FWD_DECL_SIGNAL(SignalFrameDone);
FWD_DECL_SIGNAL(SignalStartSimulation);
FWD_DECL_SIGNAL(SignalStopSimulation);
FWD_DECL_SIGNAL(SignalLoadScene);
FWD_DECL_SIGNAL(SignalReset);
FWD_DECL_SIGNAL(SignalPlaybackCompleted);
FWD_DECL_SIGNAL(SignalSensorInput);
FWD_DECL_SIGNAL(SignalActionsEnabled);
FWD_DECL_SIGNAL(SignalSimulationEnabled);
FWD_DECL_SIGNAL(SignalSimulationChanged);
FWD_DECL_SIGNAL(SignalSimulationTimeStep);
FWD_DECL_SIGNAL(SignalWindowResized);
FWD_DECL_SIGNAL(SignalManipulatorAdded);
FWD_DECL_SIGNAL(SignalManipulatorDeleted);
FWD_DECL_SIGNAL(SignalActiveManipulatorChanged);
FWD_DECL_SIGNAL(SignalActiveEndEffectorChanged);
FWD_DECL_SIGNAL(SignalControlDescriptionChanged);
FWD_DECL_SIGNAL(SignalControlMethodChanged);
FWD_DECL_SIGNAL(SignalControlSystemChanged);
FWD_DECL_SIGNAL(SignalEndEffectorSetChanged);
FWD_DECL_SIGNAL(SignalExit);

#undef FWD_DECL_GUISG0PARAM
#undef FWD_DECL_GUIS1PARAM
#undef FWD_DECL_GUIS0PARAM
#undef FWD_DECL_GUIG0PARAM
#undef FWD_DECL_GUIPARAM
#undef FWD_DECL_SIGNAL
#undef FWD_DECL_GETPTR
