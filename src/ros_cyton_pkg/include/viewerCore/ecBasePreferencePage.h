#ifndef ecBasePreferencePage_H_
#define ecBasePreferencePage_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecBasePreferencePage.h
/// @class EcBasePreferencePage
/// @brief Base class for preference pages
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.

#include <QtGui/QWidget>

/////////////////////////////////////////////////////////////////////////////
// EcBasePreferencePage widget
class EC_GUICOMMON_VIEWERCORE_DECL EcBasePreferencePage : public QWidget
{
   Q_OBJECT

public:
   /// constructor
   EcBasePreferencePage
      (
      QWidget* parent
      );

   /// destructor
   virtual ~EcBasePreferencePage
      (
      );

   /// initialize the page. Default to do nothing. Derived classes must implement this method. This is called every time the preference dialog is open.
   virtual void init
      (
      ) = 0;

   /// apply the changes made to the page
   virtual void apply
      (
      ) = 0;

public Q_SLOTS:
   /// set IsModified flat to true and emit modified signal. The derived classes should call this method whenever a change has been made to them.
   virtual void setIsModified
      (
      );

Q_SIGNALS:
   /// this signal is emitted when a change has been made to the page.
   void signalModified();

protected:
   bool m_IsModified; ///< Modified state of preference page
};

#endif // ecBasePreferencePage_H_
