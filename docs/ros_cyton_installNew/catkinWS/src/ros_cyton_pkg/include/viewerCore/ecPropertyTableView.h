#ifndef ecPropertyTableView_H_
#define ecPropertyTableView_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecPropertyTableView.h
/// @class EcPropertyTableView
/// @brief Table view for editing properties
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>

#include <QtGui/QTableView>

class QModelIndex;
class QStandardItemModel;

/////////////////////////////////////////////////////////////////////////////
// EcPropertyTableView
class EC_GUICOMMON_VIEWERCORE_DECL EcPropertyTableView : public QTableView
{
   Q_OBJECT

public:
   /// constructor
   EcPropertyTableView
      (
      QWidget *parent=0
      );

   /// destructor
   virtual ~EcPropertyTableView
      (
      );

   /// set the object whose properties to be displayed and edited. The properties include all properties except the first one (objectName).
   virtual void setObject
      (
      QObject* object
      );

   /// the property name at index
   const char* propertyName
      (
      int index
      ) const;

Q_SIGNALS:
   void propertyValueChanged(const char* name, const QVariant& value);

protected Q_SLOTS:
   void updataPropertyValue(const QModelIndex& topLeft, const QModelIndex& bottomRight);

protected:
   /// populate the table view with properties of the object
   virtual void populateTableView
      (
      );

   virtual void connectDataChanged();
   virtual void disconnectDataChanged();
protected:
   QStandardItemModel*  m_pPropertyModel;
   QObject*             m_pObject;
};

#endif // ecPropertyTableView_H_
