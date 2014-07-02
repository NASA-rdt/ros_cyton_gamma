#ifndef ecCustomFileDialog_H_
#define ecCustomFileDialog_H_
//------------------------------------------------------------------------------
// Copyright (c) 2013 Energid Technologies. All rights reserved.
//
/// @file ecCustomFileDialog.h
//
//------------------------------------------------------------------------------

#include <foundCore/ecTypes.h>

#include <QtGui/QFileDialog>
#include <boost/scoped_ptr.hpp>

// Forward declarations
class QCheckBox;

//----------------------------------------------------------------------------
//////////////////////
class EcCustomFileDialog : public QFileDialog
{
   Q_OBJECT

public:
   /// constructor
   EcCustomFileDialog
      (
      QWidget*              pParent = 0
      );
   /// constructor
   EcCustomFileDialog
      (
      QWidget *parent,
      const QString &caption = QString(),
      const QString &directory = QString(),
      const QString &filter = QString(),
      const QString &checkBoxText = QString(),
      bool defaultState = true
      );
   /// destructor
   ~EcCustomFileDialog
      (
      );



   int checkBoxState
      (
      );

protected Q_SLOTS:
   void onCheckStateChanged
      (
      int state
      );

protected:

   int  m_CheckBoxState;
};

#endif // ecCustomFileDialog_H_
