#ifndef ecManipulationActionExecPluginConfig_H_
#define ecManipulationActionExecPluginConfig_H_
//------------------------------------------------------------------------------
// Copyright (c) 2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationActionExecPluginConfig.h
//
//------------------------------------------------------------------------------

#include <plugins/plugins_config.h>

#include <manipulation/ecManipulationActionContainer.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlBasicType.h>

/// manipulationActionExecPlugin directory
#if defined(plugins_manipulationActionExecPlugin_EXPORTS)
#  define EC_PLUGINS_MANIPULATIONACTIONEXEC_DECL EC_DECL_EXPORTS
#else
#  define EC_PLUGINS_MANIPULATIONACTIONEXEC_DECL EC_DECL_IMPORTS
#endif

//---------------------------------------------------------------------------
class EC_PLUGINS_MANIPULATIONACTIONEXEC_DECL EcManipulationActionExecPluginConfig : public EcXmlCompoundType
{
public:
   EcManipulationActionExecPluginConfig
      (
      );

   virtual EcXmlObject* clone
      (
      ) const;

   virtual void registerComponents
      (
      );

   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   virtual EcXmlObject* newObject
      (
      ) const;

   virtual const EcToken& token
      (
      ) const;

   const EcString& manipulationActionFile
      (
      );

   void setManipulationActionFile
      (
      const EcString& file
      );

   const EcManipulationActionContainer& manipulationActionContainer
      (
      ) const;

   void setManipulationActionContainer
      (
      const EcManipulationActionContainer& director
      );

   EcBoolean autoStart
      (
      ) const;

   void setAutoStart
      (
      EcBoolean autoStart
      );

protected:
   EcXmlString             m_ManipulationActionFile;
   EcManipulationActionContainer      m_ManipulationActionContainer;
   EcXmlBoolean            m_AutoStart;
};

#endif // ecManipulationActionExecPluginConfig_H_
