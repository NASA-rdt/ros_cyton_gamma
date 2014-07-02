#ifndef ecRigidBodyMassQWrapper_H_
#define ecRigidBodyMassQWrapper_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecRigidBodyMassQWrapper.h
/// @brief Wrappers for EcRigidBodyMass used for GUI
//
//------------------------------------------------------------------------------
#include <guiCommon/guiCommon_config.h>  // Required to be first header.
#include <manipulator/ecRigidBodyMass.h>
#include <QtCore/QObject>
#include <QtGui/QVector3D>

// macros for convenience
#undef EC_PROPERTY_DEC
#undef EC_PROPERTY_DEF
#undef EC_PROPERTY_DEF1
#undef EC_DERIVED_PROPERTY_DEF

#define EC_PROPERTY_DEC(type, readMethod, writeMethod) \
   type readMethod() const; \
   void writeMethod(const type& value);

/// Wrapper for EcShape
class EC_GUICOMMON_VIEWERCORE_DECL EcRigidBodyMassQWrapper : public QObject
{
   Q_OBJECT
   Q_PROPERTY(double mass READ mass WRITE setMass)
   Q_PROPERTY(QVector3D centerOfMass READ centerOfMass WRITE setCenterOfMass)
   Q_PROPERTY(double Jxx READ Jxx WRITE setJxx)
   Q_PROPERTY(double Jyy READ Jyy WRITE setJyy)
   Q_PROPERTY(double Jzz READ Jzz WRITE setJzz)
   Q_PROPERTY(double Jxy READ Jxy WRITE setJxy)
   Q_PROPERTY(double Jxz READ Jxz WRITE setJxz)
   Q_PROPERTY(double Jyz READ Jyz WRITE setJyz)

public:
   EcRigidBodyMassQWrapper
      (
      QObject* parent=0
      );

   virtual ~EcRigidBodyMassQWrapper() {}

   void setRigidBodyMassProperties
      (
      const EcRigidBodyMassProperties& massProp
      )
   {
      m_MassProp = massProp;
   }

   const EcRigidBodyMassProperties& rigidBodyMassProperties()
   {
      return m_MassProp;
   }

   EC_PROPERTY_DEC(double, mass, setMass)
   EC_PROPERTY_DEC(QVector3D, centerOfMass, setCenterOfMass)
   EC_PROPERTY_DEC(double, Jxx, setJxx)
   EC_PROPERTY_DEC(double, Jyy, setJyy)
   EC_PROPERTY_DEC(double, Jzz, setJzz)
   EC_PROPERTY_DEC(double, Jxy, setJxy)
   EC_PROPERTY_DEC(double, Jxz, setJxz)
   EC_PROPERTY_DEC(double, Jyz, setJyz)
protected:
   EcRigidBodyMassProperties m_MassProp;
};

#undef EC_PROPERTY_DEC

#endif // ecRigidBodyMassQWrapper_H_
