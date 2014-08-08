#ifndef ecPropertyDelegate_H_
#define ecPropertyDelegate_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecPropertyDelegate.h
/// @brief Customized delegate for property table
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.

#include <QtGui/QItemDelegate>

class QCheckBox;

/**
The editor for check box. We use this instead of a simple check box because we can then handle a mouse click in such a way that the user can click anyway in the cell table and it will check/uncheck the check box instead of having to click on directly on the check box. Also, we can fill the background of the cell when it's being edited.
*/
class EC_GUICOMMON_VIEWERCORE_DECL EcCheckBoxEditor : public QWidget
{
   Q_OBJECT
public:
   EcCheckBoxEditor
      (
      QWidget* parent=0
      );

   QCheckBox* checkBox() { return m_Checkbox; }
Q_SIGNALS:
   void stateChanged(int);
protected:
   void mousePressEvent(QMouseEvent *event);
   QCheckBox* m_Checkbox;
};

class EC_GUICOMMON_VIEWERCORE_DECL EcPropertyDelegate : public QItemDelegate
{
   Q_OBJECT
public:
   EcPropertyDelegate
      (
      QObject* parent=0
      );

   /// these methods override the parent's
   void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
   QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
   void setEditorData(QWidget *editor, const QModelIndex &index) const;
   void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

   virtual void setDefaultDoubleSpinBoxMinimum(double value);
   virtual void setDefaultDoubleSpinBoxMaximum(double value);
   virtual void setDefaultDoubleSpinBoxDecimals(int value);
   virtual void setDefaultDoubleSpinBoxSingleStep(double value);
   virtual void setPreciseDoubleSpinBoxDecimals(int value);
   virtual void setPreciseDoubleSpinBoxSingleStep(double value);
protected Q_SLOTS:
   void sendCommitSignal();
protected:
   double   m_DefaultDoubleSpinBoxMinimum;
   double   m_DefaultDoubleSpinBoxMaximum;
   int      m_DefaultDoubleSpinBoxDecimals;
   double   m_DefaultDoubleSpinBoxSingleStep;
   int      m_PreciseDoubleSpinBoxDecimals;
   double   m_PreciseDoubleSpinBoxSingleStep;
};
#endif // ecPropertyDelegate_H_
