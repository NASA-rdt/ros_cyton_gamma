#ifndef ecSystemAseLoader_H_
#define ecSystemAseLoader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemAseLoader.h
/// @class EcSystemAseLoader
/// @brief interface for the EcSystemAseLoader class
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseSystemLoader.h"
#include <xml/ecXmlBasicType.h>

/// interface for the EcSystemAseLoader class
class EC_FOUNDATION_CONVERTSYSTEM_DECL EcSystemAseLoader : public EcBaseSystemLoader
{
public:
   /// constructor
	EcSystemAseLoader
      (
      );

   /// destructor
	virtual ~EcSystemAseLoader
      (
      );

   /// copy constructor
   EcSystemAseLoader
      (
      const EcSystemAseLoader& orig
      );

   /// assignment operator
   EcSystemAseLoader& operator=
      (
      const EcSystemAseLoader& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemAseLoader& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// get scale factor
   virtual EcReal scaleFactor
      (
      ) const;

   /// set scale factor
   virtual void setScaleFactor
      (
      EcReal scaleFactor
      );

   /// load a file and build a visualizable stated system
   /**
       \param[out] visStatedSystem stated system
       \param[in] filename filename for building stated system
       \retval error status
   */
   virtual EcBoolean loadVisualizableStatedSystemFromFile
      (
      EcVisualizableStatedSystem&  visStatedSystem,
      const EcString& filename
      ) const;

   /// a token unique to this class
   static const EcToken& classToken
      (
      );

   /// get an empty object
   static EcSystemAseLoader nullObject
      (
      );

   /// load an .ase file as a manipulator
   /**
       \param[out] manipulator manipulator
       \param[in] filename input filename
       \param[in] path to file
       \retval error status
   */
   virtual EcBoolean loadManipulatorFromAse
      (
      EcIndividualManipulator&  manipulator,
      const EcString& filename,
      const EcStringVector& path
      ) const;

   /// load a manipulator from stream
   /**
       \param[out] manipulator manipulator
       \param[in] stream file stream
       \retval error status
   */
   virtual EcBoolean readManipulatorFromStream
      (
      EcIndividualManipulator&   manipulator,
      std::istream&              stream
      ) const;

protected:
   EcXmlReal                     m_ScaleFactor;    ///< model scale factor
};

#endif // ecSystemAseLoader_H_
