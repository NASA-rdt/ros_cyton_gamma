#ifndef ecManipulationDirectorExecPluginConfig_H_
#define ecManipulationDirectorExecPluginConfig_H_
//------------------------------------------------------------------------------
// Copyright (c) 2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationDirectorExecPluginConfig.h
//
//------------------------------------------------------------------------------

#include <plugins/plugins_config.h>

#include <manipulationDirector/ecManipulationDirector.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlBasicType.h>

//---------------------------------------------------------------------------
class EC_PLUGINS_MANIPULATIONDIRECTOREXEC_DECL EcManipulationDirectorExecPluginConfig : public EcXmlCompoundType
{
public:
   EcManipulationDirectorExecPluginConfig
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

   const EcString& manipulationDirectorFile
      (
      );

   void setManipulationDirectorFile
      (
      const EcString& file
      );

   const EcManipulationDirector& manipulationDirector
      (
      ) const;

   void setManipulationDirector
      (
      const EcManipulationDirector& director
      );

   EcBoolean autoStart
      (
      ) const;

   void setAutoStart
      (
      EcBoolean autoStart
      );

protected:
   EcXmlString            m_ManipulationDirectorFile;
   EcManipulationDirector m_ManipulationDirector;
   EcXmlBoolean           m_AutoStart;
};

#endif // ecManipulationDirectorExecPluginConfig_H_
