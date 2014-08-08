#ifndef EcBaseStoppingCriterion_H_
#define EcBaseStoppingCriterion_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseStoppingCriterion.h
/// @class EcBaseStoppingCriterion
/// @brief A base class describing a criterion for stopping
///        the arm.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>

// forward declarations
class EcPropagationResultData;
class EcStatedSystem;
class EcSystemActiveState;

/** An abstract base class describing stopping criterion for a manipulator.
*/

class EC_FOUNDATION_MANIPULATOR_DECL EcBaseStoppingCriterion : public EcXmlCompoundType
{
public:
   /// default constructor
   EcBaseStoppingCriterion
      (
      );

   /// destructor
   virtual ~EcBaseStoppingCriterion
      (
      );

   /// copy constructor
   EcBaseStoppingCriterion
      (
      const EcBaseStoppingCriterion& orig
      );

   /// assignment operator
   EcBaseStoppingCriterion& operator=
      (
      const EcBaseStoppingCriterion& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseStoppingCriterion& orig
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

   /// give descriptive text
   virtual const EcString& descriptiveText
      (
      ) const = 0;

   /// Calculate whether or not the manipulator should stop.
   /**
    * @param[in,out] actState The system active state
    * @param[in] statedSystem The stated system containing the manipulator
    * @param[in] time The simulation time
    * @param[in] manipulatorIndex The index of the manipulator
    * @param[out] propagationResults If the manipulator should stop, the registerGenericStoppingCriterion
    *                method of propagationResults must be called to propagate the stopping criterion result.
    * @return True if the manipulator should stop due to it meeting this criterion
    */
   virtual EcBoolean stop
      (
      EcSystemActiveState&              actState,
      const EcStatedSystem&             statedSystem,
      const EcReal&                     time,
      EcU32                             manipulatorIndex,
      EcPropagationResultData&          propagationResults
      ) const = 0;
};

#endif // EcBaseStoppingCriterion_H_
