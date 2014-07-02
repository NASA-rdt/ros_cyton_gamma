#ifndef ecFrictionCoefficientLookupTool_H_
#define ecFrictionCoefficientLookupTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecFrictionCoefficientLookupTool.h
/// @class EcFrictionCoefficientLookupTool
/// @brief Description of a class for looking up friction values based
///        on link surface properties
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlMapType.h>

// forward declarations
class EcDataMap;

/** Holds a class for looking up friction values based on link surface properties
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcFrictionCoefficientLookupTool : public EcXmlCompoundType
{
public:
   /// default constructor
   EcFrictionCoefficientLookupTool
      (
      );

   /// destructor
   virtual ~EcFrictionCoefficientLookupTool
      (
      );

   /// copy constructor
   EcFrictionCoefficientLookupTool
      (
      const EcFrictionCoefficientLookupTool& orig
      );

   /// assignment operator
   EcFrictionCoefficientLookupTool& operator=
      (
      const EcFrictionCoefficientLookupTool& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcFrictionCoefficientLookupTool& orig
      ) const;

   /// read object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// get the rotational friction scale factor
   virtual const EcReal rotationalFrictionScaleFactor
      (
      const EcString& sp1,
      const EcString& sp2
      )const;

   /// set the rotational friction scale factor
   virtual void setRotationalFrictionScaleFactor
      (
      const EcString& sp1,
      const EcString& sp2,
      const EcReal& val
      );

   /// get the assumed mass map
   virtual const EcXmlStringStringRealMap& assumedMassMap
      (
      )const;

   /// set the assumed mass map
   virtual void setAssumedMassMap
      (
      const EcXmlStringStringRealMap& map
      );


   /// get the dry friction map (normal component)
   virtual const EcXmlStringStringRealMap& normalCoefficientOfStaticFrictionMap
      (
      )const;

   /// set the dry friction map (normal)
   virtual void setNormalCoefficientOfStaticFrictionMap
      (
      const EcXmlStringStringRealMap& nMap
      );

   /// get the dry friction map (tangential component)
   virtual const EcXmlStringStringRealMap& tangentialCoefficientOfStaticFrictionMap
      (
      )const;

   /// set the dry friction map (tangential)
   virtual void setTangentialCoefficientOfStaticFrictionMap
      (
      const EcXmlStringStringRealMap& tMap
      );


   /// get the kinetic friction map
   virtual const EcXmlStringStringRealMap& kineticFrictionMap
      (
      )const;

   /// set the kinetic friction map
   virtual void setKineticFrictionMap
      (
      const EcXmlStringStringRealMap& kinFrMap
      );

   /// get the viscous friction map
   virtual const EcXmlStringStringRealMap& viscousFrictionMap
      (
      )const;

   /// set the viscous friction map
   virtual void setViscousFrictionMap
      (
      const EcXmlStringStringRealMap& viscFrMap
      );

   /// get the rotational friction scale factor map
   virtual const EcXmlStringStringRealMap& rotationalFrictionScaleFactorMap
      (

      )const;

      /// set the rotational friction scale factor map
   virtual void setRotationalFrictionScaleFactorMap
      (
      const EcXmlStringStringRealMap& rMap
      );

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

   /// clone
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// get the coefficient for the tangential component of static friction
   /**
    * @param sp1 Surface property 1
    * @param sp2 Surface property 2
    * @return the coefficient for the tangential component of static friction between the two surface properties
    */
   virtual EcReal tangentialCoefficientOfStaticFriction
      (
      const EcString& sp1,
      const EcString& sp2
      )const;

   /// set the coefficient for the tangential component of static friction
   /**
    * @param sp1 Surface property 1
    * @param sp2 Surface property 2
    * @param val The coefficient for the tangential component of static friction between the two surface properties
    */
   virtual void setTangentialCoefficientOfStaticFriction
      (
      const EcString& sp1,
      const EcString& sp2,
      const EcReal& val
      );

   /// get the coefficient for the normal component of static friction
   /**
    * @param sp1 Surface property 1
    * @param sp2 Surface property 2
    * @return the coefficient for the normal component of static friction between the two surface properties
    */
   virtual EcReal normalCoefficientOfStaticFriction
      (
      const EcString& sp1,
      const EcString& sp2
      )const;

   /// set the coefficient for the normal component of static friction
   /**
    * @param sp1 Surface property 1
    * @param sp2 Surface property 2
    * @param val The coefficient for the normal component of static friction between the two surface properties
    */
   virtual void setNormalCoefficientOfStaticFriction
      (
      const EcString& sp1,
      const EcString& sp2,
      const EcReal& val
      );

   /// get the coefficient of kinetic friction
   /**
    * @param sp1 Surface property 1
    * @param sp2 Surface property 2
    * @return the coefficient of kinetic friction between the two surface properties
    */
   virtual EcReal coefficientOfKineticFriction
      (
      const EcString& sp1,
      const EcString& sp2
      )const;

   /// set kinetic friction value
   /**
    * @param sp1 Surface property 1
    * @param sp2 Surface property 2
    * @param val The coefficient of kinetic friction between the two surface properties
    */
   virtual void setCoefficientOfKineticFriction
      (
      const EcString& sp1,
      const EcString& sp2,
      const EcReal& val
      );

   /// get the coefficient of viscous friction
   /**
    * @param sp1 Surface property 1
    * @param sp2 Surface property 2
    * @return the coefficient of viscous friction between the two surface properties
    */
   virtual EcReal coefficientOfViscousFriction
      (
      const EcString& sp1,
      const EcString& sp2
      )const;

   /// set viscous viscous value
   /**
    * @param sp1 Surface property 1
    * @param sp2 Surface property 2
    * @param val The coefficient of viscous friction between the two surface properties
    */
   virtual void setCoefficientOfViscousFriction
      (
      const EcString& sp1,
      const EcString& sp2,
      const EcReal& val
      );

   /// get the assumed mass. The assumed mass is used to calculate damping value to give critical damping
   /// when the spring value is known.
   /**
    * @param sp1 Surface property 1
    * @param sp2 Surface property 2
    * @return the assumed mass between the two surface properties
    */
   virtual EcReal assumedMass
      (
      const EcString& sp1,
      const EcString& sp2
      )const;

   /// set the assumed mass
   /**
    * @param sp1 Surface property 1
    * @param sp2 Surface property 2
    * @param val the assumed mass between the two surface properties
    */
   virtual void setAssumedMass
      (
      const EcString& sp1,
      const EcString& sp2,
      const EcReal& val
      );


   /// get the default linear kinetic friction coefficient
   virtual EcReal defaultLinearKineticFrictionCoefficient
      (
      ) const;

   /// set the default linear kinetic friction coefficient
   virtual void setDefaultLinearKineticFrictionCoefficient
      (
      EcReal defaultLinearKineticFrictionCoefficient
      );

   /// get the default angular kinetic friction coefficient
   virtual EcReal defaultAngularFrictionScaleFactor
      (
      ) const;

   /// set the default angular kinetic friction coefficient
   virtual void setDefaultAngularFrictionScaleFactor
      (
      EcReal defaultAngularFrictionScaleFactor
      );

   /// get the default linear normal static friction coefficient
   virtual EcReal defaultLinearNormalStaticFrictionCoefficient
      (
      ) const;

   /// set the default linear normal static friction coefficient
   virtual void setDefaultLinearNormalStaticFrictionCoefficient
      (
      EcReal defaultLinearNormalStaticFrictionCoefficient
      );

   /// get the default linear tangential static friction coefficient
   virtual EcReal defaultLinearTangentialStaticFrictionCoefficient
      (
      ) const;

   /// set the default linear tangential static friction coefficient
   virtual void setDefaultLinearTangentialStaticFrictionCoefficient
      (
      EcReal defaultLinearTangentialStaticFrictionCoefficient
      );

   /// get the default viscous friction coefficient
   virtual EcReal defaultViscousFrictionCoefficient
      (
      ) const;

   /// set the default viscous friction coefficient
   virtual void setDefaultViscousFrictionCoefficient
      (
      EcReal defaultViscousFrictionCoefficient
      );

   /// get the default assumed mass
   virtual EcReal defaultAssumedMass
      (
      ) const;

   /// set the default assumed mass
   virtual void setDefaultAssumedMass
      (
      EcReal defaultAssumedMass
      );


   /// create an object with default properties
   static EcFrictionCoefficientLookupTool defaultObject
      (
      );

protected:

   /// lookup value in a map
   virtual EcBoolean lookupValue
      (
      const EcString& str1,
      const EcString& str2,
      const EcXmlStringStringRealMap& map,
      EcReal& value
      )const;

   /// set a link-link pair collision candidate value by identifier
   virtual EcBoolean setFrictionValue
      (
      const EcString& sp1,
      const EcString& sp2,
      const EcReal& val,
      EcXmlStringStringRealMap& rmap
      );

   /// main the map in the reverse alphabatical order
   virtual EcXmlStringStringRealMap maintainOrder
      (
      EcXmlStringStringRealMap& frictionMap
      );


   /// LUT for the coefficient of the normal component of
   /// static friction.
   EcXmlStringStringRealMap m_NormalStaticFrictionMap;

   /// LUT for the coefficient of the tangential component of
   /// static friction.   (This is the typical static friction coefficient)
   EcXmlStringStringRealMap m_TangentialStaticFrictionMap;

   /// LUT for the coefficient of kinetic friction.
   EcXmlStringStringRealMap m_KineticFrictionMap;

   /// LUT for the coefficient of viscous friction
   EcXmlStringStringRealMap m_ViscousFrictionMap;

   /// LUT for the rotational friction scale factor
   EcXmlStringStringRealMap m_RotationalFrictionScaleFactorMap;

   /// LUT for the assumed mass
   EcXmlStringStringRealMap m_AssumedMassMap;


   /// default linear kinetic friction coefficient
   EcXmlReal    m_DefaultLinearKineticFrictionCoefficient;

   /// default linear normal static friction coefficient
   EcXmlReal    m_DefaultLinearNormalStaticFrictionCoefficient;

   /// default linear tangential static friction coefficient
   EcXmlReal    m_DefaultLinearTangentialStaticFrictionCoefficient;

   /// default angular friction scale factor
   EcXmlReal    m_DefaultAngularFrictionScaleFactor;

   /// default viscous friction coefficient
   EcXmlReal    m_DefaultViscousFrictionCoefficient;

   /// default assumed mass
   EcXmlReal    m_DefaultAssumedMass;

   /// first utility string for lookup in maps
   mutable EcXmlString m_UtilityString1;

   /// second utility string for lookup in maps
   mutable EcXmlString m_UtilityString2;
};

#endif // ecFrictionCoefficientLookupTool_H_
