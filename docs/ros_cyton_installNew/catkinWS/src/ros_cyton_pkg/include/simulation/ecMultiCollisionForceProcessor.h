#ifndef ecMultiCollisionForceProcessor_H_
#define ecMultiCollisionForceProcessor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecMultiCollisionForceProcessor.h
/// @class EcMultiCollisionForceProcessor
/// @brief compute collision force
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecCollisionForceProcessorVector.h"

#include <manipulator/ecBaseCollisionForceProcessor.h>
#include <xml/ecXmlMapType.h>

/// A map with <string,string> map and unsigned 32-bit integer values
typedef EcXmlMapType<EcXmlString,EcXmlStringU32Map>    EcXmlStringStringU32Map;

/** compute collision force
*/
class EC_ACTIN_SIMULATION_DECL EcMultiCollisionForceProcessor : public EcBaseCollisionForceProcessor
{
public:
   /// default constructor
   EcMultiCollisionForceProcessor
      (
      );


   /// destructor
   virtual ~EcMultiCollisionForceProcessor
      (
      );

   /// copy constructor
   EcMultiCollisionForceProcessor
      (
      const EcMultiCollisionForceProcessor& orig
      );

   /// assignment operator
   EcMultiCollisionForceProcessor& operator=
      (
      const EcMultiCollisionForceProcessor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcMultiCollisionForceProcessor& orig
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

   /// get an empty object
   static EcMultiCollisionForceProcessor nullObject
      (
      );

    /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

   /// get the processor vector
   virtual const EcCollisionForceProcessorVector& processorVector
      (
      ) const;

   /// set the processor vector
   virtual void setProcessorVector
      (
      const EcCollisionForceProcessorVector& value
      );

   /// get the index of collision force processor in the processor vector that will be used as the default processor.
   virtual EcU32 defaultCollisionForceProcessorIndex
      (
      ) const;

   /// set the index of collision force processor in the processor vector that will be used as the default processor.
   virtual void setDefaultCollisionForceProcessorIndex
      (
      EcU32 index
      );

   /// set the index of collision force processor in the processor vector that will be used between two surface properties
   virtual void setCollisionForceProcessorIndex
      (
      const EcString& sp1,
      const EcString& sp2,
      EcU32 index
      );

   /// get the index of collision force processor in the processor vector that will be used between two surface properties
   virtual EcU32 collisionForceProcessorIndex
      (
      const EcString& sp1,
      const EcString& sp2
      ) const;

   /// get the collision force processor in the processor vector that will be used between two surface properties
   virtual const EcBaseCollisionForceProcessor* collisionForceProcessor
      (
      const EcString& sp1,
      const EcString& sp2
      ) const;

   /// @copydoc EcBaseCollisionForceProcessor::process()
   virtual EcBoolean process
      (
      EcShapeCollisionData& collision,
      EcSystemActiveState& actState,
      const EcManipulatorTorqueVector&  torqueVec,
      EcManipulatorExternalForceVector& externalForceVec,
      const EcReal& time
      ) const;

protected:
   /// the vector of different collision force processors
   EcCollisionForceProcessorVector     m_vProcessors;

   /// the index of the default processor
   EcXmlU32                            m_DefaultProcessorIndex;

   /// map for lookup table for the processor
   EcXmlStringStringU32Map             m_ProcessorMap;
};

#endif // ecMultiCollisionForceProcessor_H_
