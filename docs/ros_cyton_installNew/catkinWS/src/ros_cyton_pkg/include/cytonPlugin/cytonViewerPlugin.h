#ifndef cytonViewerPlugin_H_
#define cytonViewerPlugin_H_
//     Copyright (c) 2008-2011 Energid Technologies. All rights reserved. ////
//
// Filename:    cytonViewerPlugin.h
//
// Description: Creates a button for Assistive Mode
//
/////////////////////////////////////////////////////////////////////////
#include <base/cytonViewerBase.h>

#include <boost/shared_ptr.hpp>

class AssistiveThread;

class cytonViewerPlugin : public cyton::ViewerBase
{
   Q_OBJECT

public:
   /// @copydoc cyton::ViewerBase::init();
   EcBoolean init
      (
      );

   /// During assistive mode, it will retrieve the servo joint values.
   /// @param[in] time Elapsed simulation state time
   void update
      (
      const EcReal time
      );

protected Q_SLOTS:
   void onActionConfigureMode(bool checked); ///< Assistive mode button
   virtual void onActionExitMode(); ///< Assisve mode exit on key press

protected:
   cytonViewerPlugin
      (
      );

   EcBoolean shutdown
      (
      );

   /// @copydoc Ec::Plugin::setConfigurationString()
   void setConfigurationString
      (
      const EcString& str
      );

   /// @copydoc Ec::Plugin::getConfigurationString()
   EcString getConfigurationString
      (
      ) const;

   boost::shared_ptr<AssistiveThread> m_ThreadPtr; ///< Assistive mode thread
   EcU32 m_OldStatusUpdateInMs;                    ///< Cached status update
   Ec::Plugin* m_pPathPlugin;                      ///< Handle to pathPlugin
};

#endif // cytonViewerPlugin_H_
