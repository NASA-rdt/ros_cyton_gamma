#ifndef servoParamDlg_H_
#define servoParamDlg_H_
//     Copyright (c) 2010-2011 Energid Technologies. All rights reserved. ////
//
// Filename:    servoParamDlg.h
//
// Description: Dialog for getting and setting servo paramters
//
// Contents:    class ServoParamDlg
//
/////////////////////////////////////////////////////////////////////////
#include <foundCore/ecTypes.h>

#include <QtGui/QDialog>

// forward declarations
namespace Ui { class servoParamDlg; }
namespace Ec { class HardwarePlugin; }

/////////////////////////////////////////////////////////////////////////////
// ServoParamDlg dialog
class ServoParamDlg : public QDialog
{
   Q_OBJECT

public:
   /// constructor
   /// @param[in] plugin Hardware plugin
   /// @param[in] parent A pointer to the parent widget
   ServoParamDlg
      (
      Ec::HardwarePlugin* plugin,
      QWidget* parent
      );

   /// destructor
   virtual ~ServoParamDlg
      (
      );

   void populateParameterLabels
      (
      );

protected Q_SLOTS:
   /// on OK button press
   void accept();

   /// populate the servo param table
   virtual void populateServoParamTable(int id);

   /// on Refresh button press
   virtual void onActionRefresh();

   /// on Cancel button press
   virtual void onActionCancel();

protected:
   Ui::servoParamDlg* m_pUi;      ///< UI components
   Ec::HardwarePlugin* m_pPlugin; ///< Handle to owning plugin
   EcStringVector m_LinkLabels;   ///< link labels from simulation 
};

#endif // servoParamDlg_H_
