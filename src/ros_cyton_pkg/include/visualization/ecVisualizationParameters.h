#ifndef ecVisualizationParameters_H_
#define ecVisualizationParameters_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecVisualizationParameters.h
/// @class EcVisualizationParameters
/// @brief Holds a description of all the parameters related to
///        visualizing the simulation.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecDisplayOptions.h"
#include "ecGuiObjectParameters.h"
#include "ecLightParameters.h"
#include "ecPovParameters.h"
#include "ecRenderParameters.h"
#include "ecShadowParameters.h"
#include <xml/ecXmlCompType.h>

/// Holds a description of all the parameters related to visualizing the simulation.
class EC_FOUNDATION_VISUALIZATION_DECL EcVisualizationParameters : public EcXmlCompoundType
{
public:
   /// default constructor
   EcVisualizationParameters
      (
      );

   /// destructor
   virtual ~EcVisualizationParameters
      (
      );

   /// copy constructor
   EcVisualizationParameters
      (
      const EcVisualizationParameters& orig
      );

   /// assignment operator
   EcVisualizationParameters& operator=
      (
      const EcVisualizationParameters& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcVisualizationParameters& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// gets the POV parameters (const)
   virtual const EcPovParameters& povParameters
      (
      ) const;

   /// sets the POV parameters
   virtual void setPovParameters
      (
      const EcPovParameters& povParameters
      );

   /// gets the light parameters (const)
   virtual const EcLightParameters& lightParameters
      (
      ) const;

   /// sets the light parameters
   virtual void setLightParameters
      (
      const EcLightParameters& lightParameters
      );

   /// gets the render parameters (const)
   virtual const EcRenderParameters& renderParameters
      (
      ) const;

   /// sets the render parameters
   virtual void setRenderParameters
      (
      const EcRenderParameters& renderParameters
      );

   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   static EcVisualizationParameters nullObject
      (
      );

   /// standard object
   static EcVisualizationParameters defaultObject
      (
      );

   /// gets the display options (const)
   virtual const EcDisplayOptions& displayOptions
      (
      ) const;

   /// sets the display options
   virtual void setDisplayOptions
      (
      const EcDisplayOptions& displayOptions
      );

   /// get function for the gui parameters
   virtual const EcGUIObjectParameters& GUIObjectParameters
      (
      ) const;

   /// sets the gui parameters
   virtual void setGUIObjectParameters
      (
      const EcGUIObjectParameters& GUIObjectParameters
      );

   /// get function for the shadow parameters
   virtual const EcShadowParameters& shadowParameters
      (
      ) const;

   /// sets the shadow parameters
   virtual void setShadowParameters
      (
      const EcShadowParameters& shadowParameters
      );

protected:

   /// parameters describing the kinematics of the view
   EcPovParameters         m_PovParameters;

   /// parameters describing the scene lighting
   EcLightParameters       m_LightParameters;

   /// parameters describing the rendering process
   EcRenderParameters      m_RenderParameters;

   /// display options
   EcDisplayOptions        m_DisplayOptions;

   /// GUI parameters
   EcGUIObjectParameters   m_GUIObjectParameters;

   /// Shadow rendering parameters
   EcShadowParameters      m_ShadowParameters;
};

/// A vector of visualization parameters
typedef EcXmlVectorType<EcVisualizationParameters>
   EcVisualizationParametersVector;

#endif // ecVisualizationParameters_H_
