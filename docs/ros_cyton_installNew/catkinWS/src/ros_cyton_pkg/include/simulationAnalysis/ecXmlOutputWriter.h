#ifndef ecXmlOutputWriter_H_
#define ecXmlOutputWriter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlOutputWriter.h
/// @class EcXmlOutputWriter
/// @brief A class for writing simulation outputs to files in
///        XML format.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlWriter.h>

#include "ecBaseOutputWriter.h"
#include "ecSystemDataVector.h"

/** A class for writing simulation outputs to files in XML format.
*/
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcXmlOutputWriter : public EcBaseOutputWriter
{
public:
   /// default constructor
   EcXmlOutputWriter
      (
      );

   /// destructor
   virtual ~EcXmlOutputWriter
      (
      );

   /// copy constructor
   EcXmlOutputWriter
      (
      const EcXmlOutputWriter& orig
      );

   /// assignment operator
   EcXmlOutputWriter& operator=
      (
      const EcXmlOutputWriter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcXmlOutputWriter& orig
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

   // returns the token for this class
   virtual const EcToken& token
      (
      ) const;

   /// return the descriptor of the file format.
   virtual const EcString& formatDescriptor
      (
      ) const;

   /// return the file extension.
   virtual const EcString& fileExtension
      (
      ) const;

   /// open file
   virtual void openFile
      (
      const EcString& fileName,
      std::ofstream& stream
      );

   /// initialize the writer if necessary
   virtual void initialize
      (
      const EcSystemDataVector& dataVector,
      std::ostream& stream
      );

   /// finalize the writer if necessary
   virtual void finalize
      (
      const EcSystemDataVector& dataVector,
      std::ostream& stream
      );

   /// write the opening of a data component to an output stream
   /**
   \param[in] component The data component.
   \param[out] stream The output stream.
   */
   virtual void writeComponentOpening
      (
      const EcBaseSystemDataComponent& component,
      std::ostream& stream
      ) const;

   /// write a data component to an output stream
   /**
   \param[in] component The data component.
   \param[out] stream The output stream.
   */
   virtual void writeDataComponent
      (
      const EcBaseSystemDataComponent& component,
      std::ostream& stream
      ) const;

   /// write the closing of a data component to an output stream
   /**
   \param[in] component The data component.
   \param[out] stream The output stream.
   */
   virtual void writeComponentClosing
      (
      const EcBaseSystemDataComponent& component,
      std::ostream& stream
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
   static EcXmlOutputWriter nullObject
      (
      );

   /// token for this class
   /**
   \return a unique string token.
   */
   static const EcToken& classToken
      (
      );

   /// static creator function
   /**
   \return a pointer to a new'ed object.
   */
   static EcXmlObject* creator
      (
      );

protected:
   /// an XML writer pointer
   mutable EcXmlWriter*       m_pWriter;

   /// a utility (empty) vector object helping in saving to XML file
   EcSystemDataVector         m_UtilityDataVector;

   /// a string containing the format descriptor "XML"
   static const EcString      m_TheFormatDescriptor;

   /// a string containing the file extension for text format (.xml)
   static const EcString      m_TheFileExtension;
};

#endif // ecXmlOutputWriter_H_
