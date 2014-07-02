#ifndef ecBaseLinkInteractions_H_
#define ecBaseLinkInteractions_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseLinkInteractions.h
/// @class EcBaseLinkInteractions
/// @brief A base class describing interactions between links and other
///        links or the environment.  The result of interaction is
///        a force induced on the link
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>

// forward declarations
class EcManipulatorExternalForce;
class EcManipulatorSystem;
class EcManipulatorTorque;
class EcStatedSystem;
class EcSystemActiveState;
/// type defition of XML vector of EcManipulatorTorque
typedef EcXmlVectorType<EcManipulatorTorque> EcManipulatorTorqueVector;
/// type defition of XML vector of EcManipulatorExternalForce
typedef EcXmlVectorType<EcManipulatorExternalForce> EcManipulatorExternalForceVector;

/** Holds a description of a base preprocessor.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcBaseLinkInteractions : public EcXmlCompoundType
{
public:
   /// default constructor
   EcBaseLinkInteractions
      (
      );

   /// destructor
   virtual ~EcBaseLinkInteractions
      (
      );

   /// copy constructor
   EcBaseLinkInteractions
      (
      const EcBaseLinkInteractions& orig
      );

   /// assignment operator
   EcBaseLinkInteractions& operator=
      (
      const EcBaseLinkInteractions& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseLinkInteractions& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const = 0;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const = 0;

   /// return a string token
   virtual const EcToken& token
      (
      ) const = 0;

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

   /// Calculate force between links and ADD the result to manipExtForceVec. The force must be represented in the DH frame of the link, with point of application at the DH frame origin.
   /**
    * @param[in,out] actState The system active state
    * @param[in] manipSystem The manipulator system
    * @param[in] time The simulation time
    * @param[in] torqueVec The control torques
    * @param[in,out] manipExtForceVec The external forces. This method will calculate forces between links and add them
    *                to the external forces as appropriate.
    */
   virtual void forceBetweenLinks
      (
      EcSystemActiveState&              actState,
      const EcManipulatorSystem&        manipSystem,
      const EcReal&                     time,
      const EcManipulatorTorqueVector&  torqueVec,
      EcManipulatorExternalForceVector& manipExtForceVec // output
      ) const = 0;
};

#endif // ecBaseLinkInteractions_H_
