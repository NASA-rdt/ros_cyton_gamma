#ifndef ecDisplaySystemDataCapture_H_
#define ecDisplaySystemDataCapture_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecDisplaySystemDataCapture.h
/// @class EcDisplaySystemDataCapture
/// @brief System data capture for displaying (plotting) purposes.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecSystemDataCapture.h"

/**
\class EcDisplaySystemDataCapture
\author Chalongrath Pholsiri
\brief System data capture for displaying (plotting) purposes.

It basically consists of a plot title and two system data captures (instances of EcSystemDataCapture) -- one for the left y-axis and the other for the right y-axis of the plot.
*/
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcDisplaySystemDataCapture : public EcXmlCompoundType
{
public:
   enum
   {
      SCROLLING_CURVE=0,   //< plot data as scrolling curves
      BAR_CHART            //< plot data in a bar chart
   };

   /// default constructor
   EcDisplaySystemDataCapture
      (
      );

   /// destructor
   virtual ~EcDisplaySystemDataCapture
      (
      );

   /// copy constructor
   EcDisplaySystemDataCapture
      (
      const EcDisplaySystemDataCapture& orig
      );

   /// assignment operator
   EcDisplaySystemDataCapture& operator=
      (
      const EcDisplaySystemDataCapture& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDisplaySystemDataCapture& orig
      ) const;

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

   /// return the title of the plot
   virtual const EcString& title
      (
      ) const;

   /// set the title of the plot
   virtual void setTitle
      (
      const EcString& label
      );

   /// gets the system data capture of the plot's left axis
   virtual const EcSystemDataCapture& leftSystemDataCapture
      (
      ) const;

   /// gets the system data capture of the plot's left axis -- non-const
   virtual EcSystemDataCapture& leftSystemDataCapture
      (
      );

   /// sets the system data capture of the plot's left axis
   virtual void setLeftSystemDataCapture
      (
      const EcSystemDataCapture& value
      );

   /// gets the system data capture of the plot's right axis
   virtual const EcSystemDataCapture& rightSystemDataCapture
      (
      ) const;

   /// gets the system data capture of the plot's right axis -- non-const
   virtual EcSystemDataCapture& rightSystemDataCapture
      (
      );

   /// sets the system data capture of the plot's right axis
   virtual void setRightSystemDataCapture
      (
      const EcSystemDataCapture& value
      );

   /// gets the plot type
   virtual EcU32 plotType
      (
      ) const;

   /// sets the plot type by enum
   virtual void setPlotType
      (
      EcU32 type
      );

   /// sets the plot type by token
   virtual void setPlotType
      (
      const EcString& token
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

   /// get the number of plot types
   static EcU32 numPlotTypes
      (
      );

   /// get plot type tokens
   static const EcStringVector& plotTypeTokens
      (
      );
protected:
   /// registers enumeration strings for the simulation type
   virtual void registerEnumerations
      (
      );

protected:
   /// the title of the plot
   EcXmlString                m_Title;

   /// the system data capture of the plot's left axis
   EcSystemDataCapture        m_LeftSystemDataCapture;

   /// the system data capture of the plot's right axis
   EcSystemDataCapture        m_RightSystemDataCapture;

   /// the plot type
   EcXmlEnumU32               m_PlotType;
};

/// XML types of data captures
typedef EcXmlVectorType<EcDisplaySystemDataCapture> EcDisplaySystemDataCaptureVector;

#endif // ecDisplaySystemDataCapture_H_
