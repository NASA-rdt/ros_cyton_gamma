#ifndef ecDataPlotParameters_H_
#define ecDataPlotParameters_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecDataPlotParameters.h
/// @class EcDataPlotParameters
/// @brief Holds a description of parameters to control the data plots in
///        the GUI viewer.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlEnumType.h>

/// Holds a description of parameters to control the data plots in the GUI viewer.
class EC_ACTIN_SIMULATION_DECL EcDataPlotParameters : public EcXmlCompoundType
{
public:
   /// default constructor
   EcDataPlotParameters
      (
      );

   /// destructor
   virtual ~EcDataPlotParameters
      (
      );

   /// copy constructor
   EcDataPlotParameters
      (
      const EcDataPlotParameters& orig
      );

   /// assignment operator
   EcDataPlotParameters& operator=
      (
      const EcDataPlotParameters& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDataPlotParameters& orig
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

   /// get the width of the plot area in pixels
   virtual EcU32 plotAreaWidth
      (
      ) const;

   /// set the width of the plot area in pixels
   virtual void setPlotAreaWidth
      (
      EcU32 width
      );

   /// get the height of the plot area in pixels
   virtual EcU32 plotAreaHeight
      (
      ) const;

   /// set the height of the plot area in pixels
   virtual void setPlotAreaHeight
      (
      EcU32 length
      );

   /// get the maximum time scale of the plot
   virtual EcU32 maxTimeScale
      (
      ) const;

   /// set the maximum time scale of the plot
   virtual void setMaxTimeScale
      (
      EcU32 scale
      );

   /// get the initial time scale of the plot
   virtual EcU32 initialTimeScale
      (
      ) const;

   /// set the initial time scale of the plot
   virtual void setInitialTimeScale
      (
      EcU32 scale
      );

   /// gets the xml token used for writing out
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
   static EcDataPlotParameters nullObject
      (
      );

protected:
   /// the width of the plot area
   EcXmlU32          m_PlotAreaWidth;

   /// the height of the plot area
   EcXmlU32          m_PlotAreaHeight;

   /// the maximum time scale of the plot
   EcXmlU32          m_MaxTimeScale;

   /// the initial time scale of the plot
   EcXmlU32          m_InitialTimeScale;
};

#endif // ecDataPlotParameters_H_
