#ifndef ecPreferenceDlg_H_
#define ecPreferenceDlg_H_
//------------------------------------------------------------------------------
// Copyright (c) 2010-2013 Energid Technologies. All rights reserved.
//
/// @file ecPreferenceDlg.h
/// @class EcPreferenceDlg
/// @brief Dialog for editing preferences
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

#include <QtGui/QDialog>

namespace Ui { class ecPreferenceDlg; }
class EcBasePreferencePage;
class QAbstractButton;

/////////////////////////////////////////////////////////////////////////////
// EcPreferenceDlg dialog
class EC_GUICOMMON_VIEWERCORE_DECL EcPreferenceDlg : public QDialog
{
   Q_OBJECT

public:
   /// constructor
   EcPreferenceDlg
      (
      QWidget* parent
      );

   /// destructor
   ~EcPreferenceDlg
      (
      );

   /// Displays the dialog box and updates the current page.
   void init
      (
      );

protected Q_SLOTS:
   /// add a preference page creator. This is intended for plugins to extend the preference dialog
   /// @param[in] category The name of the preference category.
   /// @param[in] pageCreator The preference page creator for this category.
   void addPreferencePageCreator(const QString& category, QObject* pageCreator);
   void apply();
   void accept();
   void handleButtonBox(QAbstractButton* button);
   void enableOkApplyButtons();
   void createPreferencePage(const QString& category);
   void showPreferencePage(const QString& category);
   void deletePreferencePage(const QString& category);
   EcBasePreferencePage* newPreferencePage();

protected:
   typedef std::map<QString, EcBasePreferencePage*> EcPreferencePageMap;
   // type definition of a creator function map
   typedef std::map<QString, QObject*> EcPreferencePageCreatorMap;

   Ui::ecPreferenceDlg*       m_pUi;        ///< UI components
   EcPreferencePageMap        m_PageMap;    ///< map between category and page
   EcPreferencePageCreatorMap m_CreatorMap; ///< page creator map
};

#endif // ecPreferenceDlg_H_
