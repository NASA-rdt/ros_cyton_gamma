//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlBasicType.ipp
//
//------------------------------------------------------------------------------
#include "ecXmlBasicType.h"
#include <foundCore/ecMacros.h>
#include "ecXmlReader.h"
#include "ecXmlWriter.h"
#include <sstream>

/////////////////////////////////////////////////////////////////////////
// Functions:    Big four and other header functions
// Description:  Common functions
/////////////////////////////////////////////////////////////////////////

// constructor
template<class BasicType>
EcXmlBasicType<BasicType>::EcXmlBasicType():
EcBaseXmlBasicType(),
m_Value(0)
{
}

// constructor of the basic type
template<class BasicType>
EcXmlBasicType<BasicType>::EcXmlBasicType
   (
   const BasicType& val
   ):
EcBaseXmlBasicType(),
m_Value(val)
{
}

// destructor
template<class BasicType>
EcXmlBasicType<BasicType>::~EcXmlBasicType
   (
   )
{
}

// copy constructor
template<class BasicType>
EcXmlBasicType<BasicType>::EcXmlBasicType
   (
   const EcXmlBasicType<BasicType>& orig
   ):
EcBaseXmlBasicType(orig),
m_Value(orig.m_Value)
{
}

// assignment operator
template<class BasicType>
EcXmlBasicType<BasicType>& EcXmlBasicType<BasicType>::operator=
   (
   const EcXmlBasicType<BasicType>& orig
   )
{
   // self assignment.
   if (this==&orig)
   {
      return *this;
   }

   // call parent
   EcXmlObject::operator=(orig);

   m_Value=orig.m_Value;

   return *this;
}

// equality operator
template<class BasicType>
EcBoolean EcXmlBasicType<BasicType>::operator==
   (
   const EcXmlBasicType<BasicType>& orig
   ) const
{
   EcBoolean retVal=EcXmlObject::operator==(orig);

   if(retVal)
   {
      if(!(m_Value==orig.m_Value))
      {
         retVal=EcFalse;
      }
   }

   return retVal;
}

// less-than operator.  This is used for creating
// sorted lists.
template<class BasicType>
EcBoolean EcXmlBasicType<BasicType>::operator<
   (
   const EcXmlBasicType<BasicType>& orig
   ) const
{
   return value()<orig.value();
}

/////////////////////////////////////////////////////////////////////////
//End of header functions
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// Functions:    clone()
// Description:  Virtual constructor.
// I/O:          Return XML object
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcXmlObject* EcXmlBasicType<BasicType>::clone
   (
   ) const
{
   return ( new EcXmlBasicType<BasicType>(*this) );
}

/////////////////////////////////////////////////////////////////////////
// Function:     equality
// Description:  equality - virtual equality to an EcXmlObject pointer
// I/O:          Input XML object, Return status
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcBoolean EcXmlBasicType<BasicType>::equality
   (
   const EcXmlObject* other
   ) const
{
   EcBoolean retVal=EcTrue;

   const EcXmlBasicType<BasicType>* cast=
      dynamic_cast<const EcXmlBasicType<BasicType>*>(other);

   if(!cast || !(*this==*cast))
   {
      retVal=EcFalse;
   }
   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     newObject
// Description:  A virtual new that returns an EcXmlObject.
// I/O:          Return XML object
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcXmlObject* EcXmlBasicType<BasicType>::newObject
   (
   ) const
{
   return new EcXmlBasicType<BasicType>();
}


/////////////////////////////////////////////////////////////////////////
// Functions:   read()
// Description: Reads the class from an xml data stream
// I/O:         Input stream, output status
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcBoolean EcXmlBasicType<BasicType>::read
   (
   EcXmlReader& stream
   )
{
   EcBoolean retVal=EcXmlObject::read(stream);

   if(retVal)
   {
      EcXmlFileReader::XML_READER_MODE mode = stream.mode();

      switch (mode)
      {
         case EcXmlFileReader::START_TAG:
         {
            mode = stream.readXml();
            if( mode == EcXmlFileReader::CONTENT )
            {
               // if CONTENT mode, get the content
               setValueFromString(stream.content());
            }
            else if( mode == EcXmlFileReader::END_TAG )
            {
               // if END_TAG mode, no content
               setValueFromString("");
            }
            else
            {
               EcWARN
               ("EcXmlBasicType Error: file not valid.\n\t"
                "No data found.\n\tFile: %s\n\tLine: %d\n",
                stream.filename(), stream.lineCountOfFile());
               setValueFromString("");
               return EcFalse;
            }
            break;
         }
         case EcXmlFileReader::EMPTY_TAG:
         {
            // if empty tag found, content is empty data
            setValueFromString("");
            break;
         }
         case EcXmlFileReader::CONTENT:
         {
            // if CONTENT mode, get the content
            setValueFromString(stream.content());
            break;
         }
         default:
         {
            EcWARN
            ("EcXmlBasicType Error: file not valid.\n\t"
             "No data found.\n\tFile: %s\n\tLine: %d\n",
             stream.filename(), stream.lineCountOfFile());
            setValueFromString("");
            retVal=EcFalse;
         }
      }
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Functions:   readAttribute()
// Description: Reads the attribute from an xml data stream
// I/O:         Input stream, output status
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcBoolean EcXmlBasicType<BasicType>::readAttribute
   (
   EcXmlReader& stream
   )
{
   EcBoolean retVal=EcXmlObject::read(stream);

   if(retVal)
   {
      if( stream.remainingNumOfAttributes() > 0 )
      {
         // attribute data available
         setValueFromString(stream.attributeValue());
      }
      else
      {
         EcWARN
         ("EcXmlBasicType Error: file not valid.\n\t"
          "No attributes found.\n\tFile: %s\n\tLine: %d\n",
         stream.filename(), stream.lineCountOfFile());
         setValueFromString("");
      }

   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Functions:    write()
// Description:  Writes the class to an xml data stream
// I/O:          Input stream, Output status
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcBoolean EcXmlBasicType<BasicType>::write
   (
   EcXmlWriter& stream
   ) const
{
   EcBoolean retVal=EcXmlObject::write(stream);

   if(retVal)
   {
      stream << m_Value;
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     writeSchema
// Description:  writes the class schema to the schema creator
// I/O:          Input stream, output status
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcBoolean EcXmlBasicType<BasicType>::writeSchema
   (
   EcXmlSchema& stream
   ) const
{
   EcBoolean retVal=EcXmlObject::writeSchema(stream);

   if(retVal)
   {
      // submit type for basic value
      stream.setType(typeid(BasicType));
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Functions:    isBasicType
// Description:  Is this a basic type?
// I/O:          Output: default is false
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcBoolean EcXmlBasicType<BasicType>::isBasicType
   (
   ) const
{
   return EcTrue;
}

/////////////////////////////////////////////////////////////////////////
// Function:    nullObject()
// Description: Returns an empty, null, or identity value
// I/O:         Output copy of null object.
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcXmlBasicType<BasicType> EcXmlBasicType<BasicType>::nullObject
   (
   )
{
   return EcXmlBasicType<BasicType>(0);
}


/////////////////////////////////////////////////////////////////////////
// Function:    token()
// Description: Gets the xml token tag for this object.
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
const EcToken&
EcXmlBasicType<BasicType>::token
   (
   ) const
{
   return EcXml::EcBasicTypeToken;
}

/////////////////////////////////////////////////////////////////////////
// Function:     setValueFromString
// Description:  converts a string into the BasicType value.
// I/O:          Input string
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
void EcXmlBasicType<BasicType>::setValueFromString
   (
   const EcString& string
   )
{
   std::stringstream valueStream;
   valueStream<<string;
   valueStream>>m_Value;
}

// Place specializations here

/////////////////////////////////////////////////////////////////////////
// Functions:    specialized constructor
// Description:  specialization: constructor for strings
/////////////////////////////////////////////////////////////////////////
template<>
EC_STABLE_XML_DECL EcXmlBasicType<EcString>::EcXmlBasicType():
EcBaseXmlBasicType(),
m_Value("")
{
}

/////////////////////////////////////////////////////////////////////////
// Functions:    isBasicType
// Description:  Is this a basic type?
// I/O:          Output: default is false
/////////////////////////////////////////////////////////////////////////
template<>
EC_STABLE_XML_DECL EcBoolean
EcXmlBasicType<EcString>::isBasicType
   (
   ) const
{
   return EcFalse;
}

/////////////////////////////////////////////////////////////////////////
// Function:    nullValue() specialized for strings
// Description: Returns an empty, null, or identity value
// I/O:         Output copy of null object.
/////////////////////////////////////////////////////////////////////////
template<>
EC_STABLE_XML_DECL EcXmlBasicType<EcString>
EcXmlBasicType<EcString>::nullObject
   (
   )
{
   return EcXmlBasicType<EcString>("");
}


/////////////////////////////////////////////////////////////////////////
// Function:     setValueFromString specialized for string type
// Description:  converts a string into the BasicType value.
// I/O:          Input string
/////////////////////////////////////////////////////////////////////////
template<>
EC_STABLE_XML_DECL void
EcXmlBasicType<EcString>::setValueFromString
   (
   const EcString& string
   )
{
   m_Value=string;
}

/////////////////////////////////////////////////////////////////////////
// Function:     setValueFromString specialized for EcReal type
// Description:  converts a string into the BasicType value.
// I/O:          Input string
/////////////////////////////////////////////////////////////////////////
template<>
EC_STABLE_XML_DECL void
EcXmlBasicType<EcReal>::setValueFromString
   (
   const EcString& string
   )
{
   m_Value=atof(string.c_str());
}

/////////////////////////////////////////////////////////////////////////
// Function:     setValueFromString specialized for EcInt32 type
// Description:  converts a string into the BasicType value.
// I/O:          Input string
/////////////////////////////////////////////////////////////////////////
template<>
EC_STABLE_XML_DECL void
EcXmlBasicType<EcInt32>::setValueFromString
   (
   const EcString& string
   )
{
   m_Value=atol(string.c_str());
}

/////////////////////////////////////////////////////////////////////////
// Function:     setValueFromString specialized for EcU32 type
// Description:  converts a string into the BasicType value.
// I/O:          Input string
/////////////////////////////////////////////////////////////////////////
template<>
EC_STABLE_XML_DECL void
EcXmlBasicType<EcU32>::setValueFromString
   (
   const EcString& string
   )
{
   std::stringstream stream;
   stream << string;
   stream >> m_Value;
}

/////////////////////////////////////////////////////////////////////////
// Function:     setValueFromString specialized for EcU8 type
// Description:  converts a string into the U8 value.
// I/O:          Input string
/////////////////////////////////////////////////////////////////////////
template<>
EC_STABLE_XML_DECL void
EcXmlBasicType<EcU8>::setValueFromString
   (
   const EcString& string
   )
{
   if(string==EcString(""))
   {
      m_Value=0;
   }
   else
   {
      EcU16 value;
      std::stringstream stream;
      stream << string;
      stream >> value;
      m_Value=EcU8(value);
   }
}

/////////////////////////////////////////////////////////////////////////
// Functions:    write() specialized for EcU8 type
// Description:  Writes the U8 value to an xml data stream
// I/O:          Input stream, Output status
/////////////////////////////////////////////////////////////////////////
template<>
EC_STABLE_XML_DECL EcBoolean
EcXmlBasicType<EcU8>::write
   (
   EcXmlWriter& stream
   ) const
{
   EcBoolean retVal=EcXmlObject::write(stream);

   if(retVal)
   {
      stream << (EcU16)m_Value;
   }

   return retVal;
}
