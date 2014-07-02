#ifndef ecCamera_H_
#define ecCamera_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecCamera.h
/// @class EcCamera
/// @brief A base camera window is used as an additional view into an
///        existing scene.  It will share the rendering resources with
///        the main window, but provide its own display and viewer
///        attributes in addition to a separate EcPovParameter.
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <rendCore/ecSGWindow.h>

// forward declarations.
class EcSGWidgetQt;
class QWidget;

class EC_GUICOMMON_VIEWERCORE_DECL EcCamera : public EcSGWindow
{
public:
   virtual ~EcCamera
      (
      );

   /// Creator method for instantiating and setting up camera.
   /// \param[in] pWin Pointer to rending window to share scene with.
   /// \param[in] parent Pointer to parent QWidget.
   static EcCamera* newCamera
      (
      const EcSGWindow* pWin,
      QWidget* parent = EcNULL
      );

   /// Perform one time initialization of rendering window.
   /// \return EcBoolean Success or failure of initialization.
   virtual EcBoolean init
      (
      );

   /// Retrieve the internal Qt Widget used for rendering.
   /// \return EcSGWidgetQt* Pointer to internal rendering widget.
   EcSGWidgetQt* getWidget
      (
      ) const;

protected:
   /// Constructor.  Create a base camera attached to another window.
   /// \param[in] pWin Pointer to rending window to share scene with.
   explicit EcCamera
      (
      const EcSGWindow* pWin
      );

   EcSGWidgetQt* m_pWidget;          //< Internal rendering widget.
   const EcSGWindow* m_pShareWindow; //< Window we share context with.
};

namespace Ec
{
   typedef EcCamera Camera;
}
#endif // ecCamera_H_
