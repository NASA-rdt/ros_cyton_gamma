#ifndef ecBaseSystemLoader_H_
#define ecBaseSystemLoader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseSystemLoader.h
/// @class EcBaseSystemLoader
/// @brief Holds a base class for loading systems from various file types.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecPhysicalSystemExpander.h"
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlBasicType.h>

class EcVisualizableStatedSystem;

/** Holds a base class for loading systems from various file types.
*/
class EC_FOUNDATION_CONVERTSYSTEM_DECL EcBaseSystemLoader : public EcXmlCompoundType
{
public:
   /// default constructor
   EcBaseSystemLoader
      (
      );

   /// destructor
   virtual ~EcBaseSystemLoader
      (
      );

   /// copy constructor
   EcBaseSystemLoader
      (
      const EcBaseSystemLoader& orig
      );

   /// assignment operator
   EcBaseSystemLoader& operator=
      (
      const EcBaseSystemLoader& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseSystemLoader& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets the vec physical system expander
   /**
       \retval physical system expander
   */
   virtual const EcPhysicalSystemExpander& physicalSystemExpander
      (
      ) const;

   /// sets the vec physical system expander
   /**
       \param physicalSystemExpander physical system expander
   */
   virtual void setPhysicalSystemExpander
      (
      const EcPhysicalSystemExpander& physicalSystemExpander
      );

   /// gets the load as polygon flag
   virtual const EcBoolean& loadAsPolygon
      (
      ) const;

   /// sets the load as polygon flag  (this is going to be removed)
   virtual void setLoadAsPolygon
      (
      const EcBoolean& loadAsPolygon
      );

   /// set to load as cutting physical Ext.
   virtual void setLoadAsCuttingPhyExt
      (
      const EcBoolean&  setloadAsCutting
      );

   /// return a string token
   virtual const EcToken& token
      (
      ) const = 0;

   /// load a file and build a visualizable stated system
   /**
       \param visStatedSystem stated system
       \param filename filename for building stated system
       \retval error status
   */
   virtual EcBoolean loadVisualizableStatedSystemFromFile
      (
      EcVisualizableStatedSystem& visStatedSystem,
      const EcString& filename
      ) const = 0;

protected:
   /// Expands physical components into stated systems
   EcPhysicalSystemExpander     m_PhysicalSystemExpander;

   /// load to polygon or triangle  (will be removed)
   mutable EcXmlBoolean         m_LoadAsPolygon;

   /// flag indicating if load as cutting physical extent
   mutable EcBoolean                   m_LoadAsCuttingPhyExt;
};

#endif // ecBaseSystemLoader_H_
