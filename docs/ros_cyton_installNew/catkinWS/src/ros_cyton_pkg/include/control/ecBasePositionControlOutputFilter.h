#ifndef ecBasePositionControlOutputFilter_H_
#define ecBasePositionControlOutputFilter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecBasePositionControlOutputFilter.h
/// @class EcBasePositionControlOutputFilter
/// @brief An abstract base class of filtering position control output.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

/// forward declaration
class EcManipulatorSystemState;
class EcStatedSystem;
class EcSupplementalControlState;

/// Filter for controlling base position TODO
class EC_ACTIN_CONTROL_DECL EcBasePositionControlOutputFilter : public EcXmlCompoundType
{
public:

   /// default constructor
   EcBasePositionControlOutputFilter
      (
      );

   /// destructor
   virtual ~EcBasePositionControlOutputFilter
      (
      );

   /// copy constructor
   EcBasePositionControlOutputFilter
      (
      const EcBasePositionControlOutputFilter& orig
      );

   /// assignment operator
   EcBasePositionControlOutputFilter& operator=
      (
      const EcBasePositionControlOutputFilter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBasePositionControlOutputFilter& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// on/off flag
   /// (EcBoolean) The filter on/off flag
   virtual EcBoolean isOn
      (
      ) const;

   /// set on/off flag
   /// @param[in] isOn   (EcBoolean) value to set
   virtual void setIsOn
      (
      EcBoolean isOn
      );

   /// initialize the filter. This must be called prior to the filter being used
   /// @param[in] statedSystem (EcStatedSystem*) value to initialize TODO
   /// @return True if inialization is successful or false otherwise.
   virtual EcBoolean initialize
      (
      const EcStatedSystem* statedSystem
      )=0;

   /// perform an in-place filtering of the state using the supplemental control state
   /// @param[in] suppState   (EcSupplementalControlState&)  TODO
   /// @param[in] state       (EcManipulatorSystemState&) TODO
   virtual void filter
      (
      const EcSupplementalControlState& suppState,
      EcManipulatorSystemState& state
      ) const=0;

   /// update the supplemental control state for next cycle. This should be called after the filter method has been called for all the output filters.
   /// @param[in] suppState (EcSupplementalControlState&) TODO
   virtual void updateControlState
      (
      EcSupplementalControlState& suppState
      ) const=0;
protected:
   /// on/off flag
   EcXmlBoolean      m_IsOn;
};

#endif // ecBasePositionControlOutputFilter_H_
