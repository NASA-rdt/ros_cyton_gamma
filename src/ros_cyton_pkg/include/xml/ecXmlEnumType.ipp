//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlEnumType.ipp
//
//------------------------------------------------------------------------------
#include "ecXmlEnumType.h"
#include "ecXmlReader.h"
#include "ecXmlWriter.h"

/////////////////////////////////////////////////////////////////////////
// Functions:    Big four and other header functions
// Description:  Common functions
/////////////////////////////////////////////////////////////////////////

// constructor
template<class BasicType>
EcXmlEnumType<BasicType>::EcXmlEnumType():
EcBaseXmlBasicType(),
m_Value(0)
{
   m_vEnumConstants.clear();
   m_vEnumStrings.clear();
}

// constructor of the basic type
template<class BasicType>
EcXmlEnumType<BasicType>::EcXmlEnumType
   (
   const BasicType& val
   ):
EcBaseXmlBasicType()
{
   m_Value=val;
   m_vEnumConstants.clear();
   m_vEnumStrings.clear();
}

// destructor
template<class BasicType>
EcXmlEnumType<BasicType>::~EcXmlEnumType
   (
   )
{
}

// copy constructor
template<class BasicType>
EcXmlEnumType<BasicType>::EcXmlEnumType
   (
   const EcXmlEnumType<BasicType>& orig
   ):
EcBaseXmlBasicType(orig),
m_Value(orig.m_Value)
{
}

// assignment operator
template<class BasicType>
EcXmlEnumType<BasicType>& EcXmlEnumType<BasicType>::operator=
   (
   const EcXmlEnumType<BasicType>& orig
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

// assignment operator using basic type
template<class BasicType>
EcXmlEnumType<BasicType>& EcXmlEnumType<BasicType>::operator=
   (
   const BasicType& val
   )
{
   // just assign the value to keep enumeration registration as before
   m_Value=val;

   return *this;
}

// equality operator
template<class BasicType>
EcBoolean EcXmlEnumType<BasicType>::operator==
   (
   const EcXmlEnumType<BasicType>& orig
   ) const
{
   EcBoolean retVal=EcXmlObject::operator==(orig);

   if(retVal)
   {
      retVal=(m_Value==orig.m_Value);
   }

   // test the enumeration configuration only if both objects
   // have been xml-initialized.
   if(xmlInitialized() && orig.xmlInitialized())
   {

      if(!(m_vEnumConstants.size()==orig.m_vEnumConstants.size()))
      {
         retVal=EcFalse;
      }

      if(!(m_vEnumStrings.size()==orig.m_vEnumStrings.size()))
      {
         retVal=EcFalse;
      }

      // test the constants vector
      if(retVal)
      {
         const size_t size = m_vEnumConstants.size();
         for(size_t ii=0;ii<size;++ii)
         {
            if(!(m_vEnumConstants[ii]==orig.m_vEnumConstants[ii]))
            {
               retVal=EcFalse;
            }
         }
      }

      // test the strings vector
      if(retVal)
      {
         const size_t size = m_vEnumConstants.size();
         for(size_t ii=0;ii<size;++ii)
         {
            if(!(m_vEnumStrings[ii]==orig.m_vEnumStrings[ii]))
            {
               retVal=EcFalse;
            }
         }
      }
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
//End of function block : Common functions
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// Function:     const basic type cast
// Description:  cast to the const basic type
// I/O:          Return m_Value
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcXmlEnumType<BasicType>::operator const BasicType&
   (
   ) const
{
   return m_Value;
}

/////////////////////////////////////////////////////////////////////////
// Function:     operator<
// Description:  less than operator
// I/O:          Input basic type, Return test result
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcBoolean EcXmlEnumType<BasicType>::operator<
   (
   const EcXmlEnumType<BasicType>& orig
   ) const
{
   return value()<orig.value();
}

/////////////////////////////////////////////////////////////////////////
// Function:    clone
// Description: Create clone of EcXmlEnumType
// I/O:         Return XML object
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcXmlObject* EcXmlEnumType<BasicType>::clone
   (
   ) const
{
   EcXmlEnumType<BasicType>* retVal=new EcXmlEnumType<BasicType>;
   retVal->setValue(value());
   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     equality
// Description:  equality - virtual equality to an EcXmlObject pointer
// I/O:          Input XML object, Return status
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcBoolean EcXmlEnumType<BasicType>::equality
   (
   const EcXmlObject* other
   ) const
{
   EcBoolean retVal=EcTrue;

   const EcXmlEnumType<BasicType>* cast=
      dynamic_cast<const EcXmlEnumType<BasicType>*>(other);

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
EcXmlObject* EcXmlEnumType<BasicType>::newObject
   (
   ) const
{
   return new EcXmlEnumType<BasicType>();
}

/////////////////////////////////////////////////////////////////////////
// Function:    read
// Description: Reads the class from an xml data stream
// I/O:         Input stream, return status
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcBoolean EcXmlEnumType<BasicType>::read
   (
   EcXmlReader& stream
   )
{
   EcBoolean retVal=EcXmlObject::read(stream);

   if(retVal)
   {
      // valueToken can come from attribute or data in XML stream
      EcString enumText;

      EcXmlFileReader::XML_READER_MODE mode = stream.mode();

      switch (mode)
      {
         case EcXmlFileReader::START_TAG:
         {
            mode = stream.readXml();
            if( mode == EcXmlFileReader::CONTENT )
            {
               // if CONTENT mode, get the content
               enumText = stream.content();
            }
            else if( mode == EcXmlFileReader::END_TAG )
            {
               // if END_TAG mode, no content
               enumText = "";
            }
            else
            {
               EcPrint(Warning) << "EcXmlEnumType Error: file not valid.\n\t"
                      << "No data found.\n\tFile: " << stream.filename()
                      << "\n\tLine: " << stream.lineCountOfFile() << std::endl;
               enumText = "";
               return EcFalse;
            }
            break;
         }
         case EcXmlFileReader::EMPTY_TAG:
         {
            // if CONTENT mode, get the content
            enumText = "";
            break;
         }
         case EcXmlFileReader::CONTENT:
         {
            // if CONTENT mode, get the content
            enumText = stream.content();
            break;
         }
         default:
         {
            EcPrint(Warning) << "EcXmlEnumType Error: file not valid.\n\t"
                   << "No data found.\n\tFile: " << stream.filename()
                   << "\n\tLine: " << stream.lineCountOfFile() << std::endl;
            enumText = "";
         }
      }

      // Convert the text into a valid enumeration value.
      retVal = findEnumString( enumText, m_Value );
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:    readAttribute
// Description: Reads the class from an xml data stream
// I/O:         Input stream, return status
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcBoolean EcXmlEnumType<BasicType>::readAttribute
   (
   EcXmlReader& stream
   )
{
   EcBoolean retVal=EcXmlObject::read(stream);

   if(retVal)
   {
      // valueToken can come from attribute or data in XML stream
      EcString enumText;

      if( stream.remainingNumOfAttributes() > 0 )
      {
         // attribute data available
         enumText = stream.attributeValue();
      }
      else
      {
         EcPrint(Warning) << "EcXmlEnumType Error: file not valid.\n\t"
                << "No data found.\n\tFile: " << stream.filename()
                << "\n\tLine: " << stream.lineCountOfFile() << std::endl;
         enumText = "";
      }

      // Convert the text into a valid enumeration value.
      retVal = findEnumString( enumText, m_Value );
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:    write
// Description: Writes the class to an xml data stream
// I/O:         Input stream, return status
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcBoolean EcXmlEnumType<BasicType>::write
   (
   EcXmlWriter& stream
   ) const
{
   EcBoolean retVal=EcXmlObject::write(stream);

   if(retVal)
   {
      stream << enumString();
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     writeSchema
// Description:  writes the class schema to the schema creator
// I/O:          Input stream, return status
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcBoolean EcXmlEnumType<BasicType>::writeSchema
   (
   EcXmlSchema& stream
   ) const
{
   EcBoolean retVal=EcXmlObject::writeSchema(stream);

   if(retVal)
   {
      // submit type for basic value
      stream.setType(typeid(EcString));
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Functions:    isBasicType
// Description:  Is this a basic type?
// I/O:          Output: default is false
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcBoolean EcXmlEnumType<BasicType>::isBasicType
   (
   ) const
{
   return EcTrue;
}

/////////////////////////////////////////////////////////////////////////
// Function:    value
// Description: Gets a const reference to the contained value - const.
// I/O:         Return class value
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
const BasicType& EcXmlEnumType<BasicType>::value
   (
   ) const
{
   return m_Value;
}

/////////////////////////////////////////////////////////////////////////
// Function:    value
// Description: Gets a reference to the contained value.
// I/O:         Return class value
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
BasicType& EcXmlEnumType<BasicType>::value
   (
   )
{
   return m_Value;
}

/////////////////////////////////////////////////////////////////////////
// Function:    setValue
// Description: Sets the contained value.
// I/O:         Input class value
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
void EcXmlEnumType<BasicType>::setValue
   (
   const BasicType& val
   )
{
   m_Value=val;
}

/////////////////////////////////////////////////////////////////////////
// Function:    enumString
// Description: Return the enumeration string based on current value.
// I/O:         Return string token
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
const EcString &EcXmlEnumType<BasicType>::enumString
   (
   ) const
{
   size_t      validIndex = 0;
   EcBoolean   found = EcFalse;

   const size_t size = m_vEnumConstants.size();

   // Loop through the strings to find the appropriate match, if it is available.
   for(size_t index=0; (!found) && (index < size); ++index)
   {
      if(m_vEnumConstants[index] == m_Value)
      {
         found = EcTrue;
         validIndex = index;
      }
   }

   return(m_vEnumStrings[validIndex]);
}

/////////////////////////////////////////////////////////////////////////
// Function:    enumString
// Description: Return the enumeration string based on given value.
// I/O:         Input class value, Output string token
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
const EcString &EcXmlEnumType<BasicType>::enumString
   (
   const BasicType &val
   ) const
{
   size_t      validIndex = 0;
   EcBoolean   found = EcFalse;

   // Loop through the strings to find the appropriate match, if it is available.
   for(size_t index = 0,size=m_vEnumConstants.size(); !found && (index<size); ++index)
   {
      if ( m_vEnumConstants[index] == val )
      {
         found = EcTrue;
         validIndex = index;
      }
   }

   return m_vEnumStrings[validIndex];
}

/////////////////////////////////////////////////////////////////////////
// Function:    setEnumString
// Description: Set the specified enumeration string for the given value.
// I/O:         Input enum text and value
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
void  EcXmlEnumType<BasicType>::setEnumString
   (
   const BasicType   &enumVal,
   const EcString    &enumText
   )
{
   BasicType lookupVal;

   // only add an entry if none already exist
   if(!findEnumString(enumText,lookupVal))
   {
      m_vEnumConstants.push_back( enumVal );
      m_vEnumStrings.push_back( enumText );
   }
}

/////////////////////////////////////////////////////////////////////////
// Function:    findEnumString
// Description: Lookup the given string and return the appropiate enumeration.
// I/O:         Input text, Ouput value and error status
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcBoolean EcXmlEnumType<BasicType>::findEnumString
   (
   const EcString    &enumText,
   BasicType         &enumVal
   )
{
   EcBoolean found = EcFalse;

   const size_t size = m_vEnumStrings.size();

   // Loop through the strings to find the appropriate match, if it is available.
   for(size_t index=0; !found && (index<size); ++index)
   {
      if(m_vEnumStrings[index] == enumText)
      {
         found = EcTrue;
         enumVal = m_vEnumConstants[index];
      }
   }

   return found;
}

/////////////////////////////////////////////////////////////////////////
// Function:     setValueFromString
// Description:  converts a string into the BasicType value.
// I/O:          Input string
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
void EcXmlEnumType<BasicType>::setValueFromString
   (
   const EcString& string
   )
{
   // Convert the text into a valid enumeration value.
   findEnumString( string, m_Value );
}

/////////////////////////////////////////////////////////////////////////
// Function:    nullObject
// Description: Returns an empty, null, or identity value
// I/O:         Output copy of null object.
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
EcXmlEnumType<BasicType> EcXmlEnumType<BasicType>::nullObject
   (
   )
{
   EcXmlEnumType<BasicType> retVal;
   retVal.setValue(0);
   return retVal;
}


/////////////////////////////////////////////////////////////////////////
// Function:    token()
// Description: Gets the xml token tag for this object.
/////////////////////////////////////////////////////////////////////////
template<class BasicType>
const EcToken&
EcXmlEnumType<BasicType>::token
   (
   ) const
{
   return EcXml::EcEnumTypeToken;
}
