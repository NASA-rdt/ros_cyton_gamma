#ifndef EcSpringDamperPropertiesQWrapper_H_
#define EcSpringDamperPropertiesQWrapper_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecSpringDamperPropertiesQWrapper.h
/// @brief Wrappers for EcSpringProperties and EcDamperProperties to create QT UI
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <manipulator/ecSpringProperties.h>
#include <manipulator/ecDamperProperties.h>
#include <QtCore/QObject>

/// Wrapper for EcSpringProperties
class EC_GUICOMMON_VIEWERCORE_DECL EcSpringDamperPropertiesQWrapper : public QObject
{
   Q_OBJECT
   Q_PROPERTY(double springConstant READ springConstant WRITE setSpringConstant)
   Q_PROPERTY(double damperConstant READ damperConstant WRITE setDamperConstant)
public:
   EcSpringDamperPropertiesQWrapper
      (
      QObject* parent=0
      );

   virtual ~EcSpringDamperPropertiesQWrapper() {}

   void setSpringProperties
      (
      const EcSpringProperties& springProp
      );

   const EcSpringProperties& springProperties
      (
      );

   double springConstant
      (
      ) const;

   void setSpringConstant
      (
       double spring
      );

    void setDamperProperties
      (
      const EcDamperProperties& damperProp
      );

   const EcDamperProperties& damperProperties
      (
      );

   double damperConstant
      (
      ) const;

   void setDamperConstant
      (
       double spring
      );

protected:
   EcSpringProperties m_SpringProp;
   EcDamperProperties m_DamperProp;
};

#endif // EcSpringDamperPropertiesQWrapper_H_
