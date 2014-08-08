#ifndef cytonConfigDlg_H_
#define cytonConfigDlg_H_
//     Copyright (c) 2008-2011 Energid Technologies. All rights reserved. ////
//
// Filename:    cytonConfigDlg.h
//
// Description: Configuration dialog class for specifying parameters for
//              the Cyton arm.
//
/////////////////////////////////////////////////////////////////////////
#include <cytonTypes.h>
#include <QtGui/QDialog>

// Forward declarations
namespace Ui { class cytonConfigDlg; }

namespace cyton
{

class ViewerBase;

class ConfigDlg : public QDialog
{
   Q_OBJECT

public:
   /// Constructor
   ConfigDlg
      (
      QWidget* parent,
      ViewerBase& plugin
      );

   /// Destructor
   ~ConfigDlg
      (
      );

   /// Populates dialog box based on config file parameters.
   void setConfig
      (
      );

   /// Pulls data from dialog box to set plugin.
   void getConfig
      (
      ) const;

public Q_SLOTS:
   void accept();    ///< Reads in config and saves to file.
   void calibrate(); ///< Reads offsets from hardware.  Still needs saving.

protected:
   Ui::cytonConfigDlg* m_pUi; ///< Configuration dialog for this plugin
   ViewerBase& m_Plugin;          ///< Reference to plugin we need to configure
};

} // namespace cyton

#endif // cytonConfigDlg_H_
