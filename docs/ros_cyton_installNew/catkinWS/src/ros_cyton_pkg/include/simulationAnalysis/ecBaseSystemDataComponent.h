#ifndef ecBaseSystemDataComponent_H_
#define ecBaseSystemDataComponent_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseSystemDataComponent.h
/// @class EcBaseSystemDataComponent
/// @brief Holds a base class for elements of system data description.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecBaseExpTreeElement.h>

/** Holds a base class for elements in a variable vector of system data
    for analysis.
*/
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcBaseSystemDataComponent : public EcXmlCompoundType
{
public:
   enum {GENERAL_CAPTURE,GENERAL_STORAGE};

   /// default constructor
   EcBaseSystemDataComponent
      (
      );

   /// destructor
   virtual ~EcBaseSystemDataComponent
      (
      );

   /// copy constructor
   EcBaseSystemDataComponent
      (
      const EcBaseSystemDataComponent& orig
      );

   /// assignment operator
   EcBaseSystemDataComponent& operator=
      (
      const EcBaseSystemDataComponent& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseSystemDataComponent& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const = 0;

   /// register components with the parent
   virtual void registerComponents
      (
      )=0;

   // returns the token for this class
   virtual const EcToken& token
      (
      ) const =0;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const = 0;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const = 0;

   /// returns a type
   virtual EcU32 type
      (
      ) const = 0;

   /// get a vector of strings that contains the elements of this data component
   /**
   This is primarily used for writing to files.
   \param[out] vElements A vector of strings which, upon return, will contains the elements of this data component. It will be resized appropriately.
   */
   virtual void getStringElements
      (
      EcStringVector& vElements
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
};

#endif // ecBaseSystemDataComponent_H_
