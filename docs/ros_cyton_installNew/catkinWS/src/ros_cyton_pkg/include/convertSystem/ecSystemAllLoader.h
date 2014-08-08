#ifndef ecSystemAllLoader_H_
#define ecSystemAllLoader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemAllLoader.h
/// @class EcSystemAllLoader
/// @brief Holds a tool for loading systems from various file types.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecSystem3dsLoader.h"
#include "ecSystemAseLoader.h"
#include "ecSystemCfgLoader.h"
#include "ecSystemPntpLoader.h"
#include "ecSystemS3dsLoader.h"
#include "ecSystemSaseLoader.h"
#include "ecSystemTecplotLoader.h"
#include "ecSystemVecLoader.h"
#include "ecSystemVrml97Loader.h"

/// Holds a tool for loading system from various file types.
class EC_FOUNDATION_CONVERTSYSTEM_DECL EcSystemAllLoader : public EcBaseSystemLoader
{
public:
   /// default constructor
   EcSystemAllLoader
      (
      );

   /// destructor
   virtual ~EcSystemAllLoader
      (
      );

   /// copy constructor
   EcSystemAllLoader
      (
      const EcSystemAllLoader& orig
      );

   /// assignment operator
   EcSystemAllLoader& operator=
      (
      const EcSystemAllLoader& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemAllLoader& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;


   /// gets the system .3ds loader
   virtual const EcSystem3dsLoader& system3dsLoader
      (
      ) const;

   /// sets the system .3ds loader
   virtual void setSystem3dsLoader
      (
      const EcSystem3dsLoader& system3dsLoader
      );

   /// gets the system .ase loader
   virtual const EcSystemAseLoader& systemAseLoader
      (
      ) const;

   /// sets the system .ase loader
   virtual void setSystemAseLoader
      (
      const EcSystemAseLoader& systemAseLoader
      );

   /// gets the system .cfg loader
   /// this is specific to Robonaut
   virtual const EcSystemCfgLoader& systemCfgLoader
      (
      ) const;

   /// sets the system .cfg loader
   /// this is specific to Robonaut
   virtual void setSystemCfgLoader
      (
      const EcSystemCfgLoader& systemCfgLoader
      );

   /// gets the system .pntp loader
   virtual const EcSystemPntpLoader& systemPntpLoader
      (
      ) const;

   /// sets the system .pntp loader
   virtual void setSystemPntpLoader
      (
      const EcSystemPntpLoader& systemPntpLoader
      );

   /// gets the system .s3ds loader
   virtual const EcSystemS3dsLoader& systemS3dsLoader
      (
      ) const;

   /// sets the system .s3ds loader
   virtual void setSystemS3dsLoader
      (
      const EcSystemS3dsLoader& systemS3dsLoader
      );

   /// gets the system .sase loader
   virtual const EcSystemSaseLoader& systemSaseLoader
      (
      ) const;

   /// sets the system .sase loader
   virtual void setSystemSaseLoader
      (
      const EcSystemSaseLoader& systemSaseLoader
      );

   /// gets the system .vec loader
   virtual const EcSystemVecLoader& systemVecLoader
      (
      ) const;

   /// sets the system .vec loader
   virtual void setSystemVecLoader
      (
      const EcSystemVecLoader& systemVecLoader
      );

   /// gets the system .stec loader
   virtual const EcSystemTecplotLoader& systemTecplotLoader
      (
      ) const;

   /// sets the system .stec loader
   virtual void setSystemTecplotLoader
      (
      const EcSystemTecplotLoader& systemtecplotLoader
      );

   /// gets the system .wrl loader
   virtual const EcSystemVrml97Loader& systemVrml97Loader
      (
      ) const;

   /// sets the system .wrl loader
   virtual void setSystemVrml97Loader
      (
      const EcSystemVrml97Loader& systemVrml97Loader
      );

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;



   /// load a file and build a visualizable stated system
   /**
       \param visStatedSystem stated system
       \param filename filename for building stated system
       \retval error status
   */
   virtual EcBoolean loadVisualizableStatedSystemFromFile
      (
      EcVisualizableStatedSystem&  visStatedSystem,
      const EcString& filename
      ) const;

   /// a token unique to this class
   static const EcToken& classToken
      (
      );

   /// get an empty object
   static EcSystemAllLoader nullObject
      (
      );

protected:

   /// load an XML file and build a visualizable stated system
   virtual EcBoolean loadVisualizableStatedSystemFromXmlFile
      (
      EcVisualizableStatedSystem&  visStatedSystem,
      const EcString& filename
      ) const;

protected:
   mutable EcSystem3dsLoader            m_System3dsLoader;      ///< 3DS system loader
   mutable EcSystemAseLoader            m_SystemAseLoader;      ///< ASE system loader
   mutable EcSystemCfgLoader            m_SystemCfgLoader;      ///< CFG system loader
   mutable EcSystemPntpLoader           m_SystemPntpLoader;     ///< PNTP system loader
   mutable EcSystemS3dsLoader           m_SystemS3dsLoader;     ///< Multiple 3DS system loader
   mutable EcSystemSaseLoader           m_SystemSaseLoader;     ///< Multiple ASE system loader
   mutable EcSystemVecLoader            m_SystemVecLoader;      ///< VEC system loader
   mutable EcSystemTecplotLoader        m_SystemTecplotLoader;  ///< Tecplot system loader
   mutable EcSystemVrml97Loader         m_SystemVrml97Loader;   ///< VRML system loader
};

#endif // ecSystemAllLoader_H_
