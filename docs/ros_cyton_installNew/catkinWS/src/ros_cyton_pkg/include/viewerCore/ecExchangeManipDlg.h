#ifndef ecExchangeManipDlg_H_
#define ecExchangeManipDlg_H_
//------------------------------------------------------------------------------
// Copyright (c) 2010-2013 Energid Technologies. All rights reserved.
//
/// @file ecExchangeManipDlg.h
/// @class EcExchangeManipDlg
/// @brief Dialog for exchanging manipulator
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

#include <QtGui/QDialog>

class QListWidgetItem;
namespace Ui { class ecExchangeManipDlg; }

/////////////////////////////////////////////////////////////////////////////
// EcExchangeManipDlg dialog
class EC_GUICOMMON_VIEWERCORE_DECL EcExchangeManipDlg : public QDialog
{
   Q_OBJECT

public:
   /// constructor
   EcExchangeManipDlg
      (
      const QStringList& currentManips,
      const QStringList& otherManips,
      QWidget* parent
      );

   /// destructor
   ~EcExchangeManipDlg
      (
      );

   EcU32 currentManipIndex
      (
      ) const
   { return m_CurrentManipIndex; }

   EcU32 otherManipIndex
      (
      ) const
   { return m_OtherManipIndex; }

protected Q_SLOTS:
   void onExchange();
   void onCurrentManipulatorClicked(QListWidgetItem* item);
   void onOtherManipulatorClicked(QListWidgetItem* item);

protected:
   Ui::ecExchangeManipDlg*       m_pUi;        ///< UI components
   EcU32    m_CurrentManipIndex;
   EcU32    m_OtherManipIndex;
};

#endif // ecExchangeManipDlg_H_
