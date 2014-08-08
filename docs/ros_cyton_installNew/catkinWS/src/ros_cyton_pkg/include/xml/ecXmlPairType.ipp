//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlPairType.ipp
//
//------------------------------------------------------------------------------
#include "ecXmlPairType.h"
#include "ecXmlReader.h"
#include "ecXmlWriter.h"

//------------------------------------------------------------------------------
template<class FirstType, class SecondType>
EcXmlPairType<FirstType,SecondType>::EcXmlPairType():
EcXmlObject(),
m_PairContainer(),
m_TagNames(std::make_pair(EcXml::EcFirstToken, EcXml::EcSecondToken))
{
}


//------------------------------------------------------------------------------
template<class FirstType, class SecondType>
EcXmlPairType<FirstType,SecondType>::EcXmlPairType
   (
   FirstType  first,
   SecondType second
   ) :
EcXmlObject(),
m_PairContainer(first, second),
m_TagNames(std::make_pair(EcXml::EcFirstToken, EcXml::EcSecondToken))
{
}


//------------------------------------------------------------------------------
template<class FirstType, class SecondType>
EcXmlPairType<FirstType,SecondType>::~EcXmlPairType
   (
   )
{
}


//------------------------------------------------------------------------------
template<class FirstType, class SecondType>
EcXmlPairType<FirstType,SecondType>::EcXmlPairType
   (
   const EcXmlPairType<FirstType,SecondType>& orig
   ):
EcXmlObject(orig),
m_PairContainer(orig.m_PairContainer),
m_TagNames(orig.m_TagNames)
{
}


//------------------------------------------------------------------------------
template<class FirstType, class SecondType>
EcXmlPairType<FirstType,SecondType>& EcXmlPairType<FirstType,SecondType>::operator=
   (
   const EcXmlPairType<FirstType,SecondType>& orig
   )
{
   // self assignment.
   if (this==&orig)
   {
      return *this;
   }

   // call parent
   EcXmlObject::operator=(orig);

   m_PairContainer=orig.m_PairContainer;
   m_TagNames = orig.m_TagNames;
   return *this;
}


//------------------------------------------------------------------------------
template<class FirstType, class SecondType>
EcBoolean EcXmlPairType<FirstType,SecondType>::operator==
   (
   const EcXmlPairType<FirstType,SecondType>& orig
   ) const
{

   EcBoolean retVal=EcXmlObject::operator==(orig);

   if(retVal)
   {
      if(!(m_PairContainer.first==orig.m_PairContainer.first) ||
         !(m_PairContainer.second==orig.m_PairContainer.second))
      {
         retVal=EcFalse;
      }
   }

   return retVal;
}


//------------------------------------------------------------------------------
template<class FirstType, class SecondType>
const FirstType& EcXmlPairType<FirstType,SecondType>::first
   (
   ) const
{
   return m_PairContainer.first;
}


//------------------------------------------------------------------------------
template<class FirstType, class SecondType>
FirstType& EcXmlPairType<FirstType,SecondType>::first
   (
   )
{
   return m_PairContainer.first;
}


//------------------------------------------------------------------------------
template<class FirstType, class SecondType>
void EcXmlPairType<FirstType,SecondType>::setFirst
   (
   const FirstType& first
   )
{
   m_PairContainer.first=first;
}


//------------------------------------------------------------------------------
template<class FirstType, class SecondType>
const SecondType& EcXmlPairType<FirstType,SecondType>::second
   (
   ) const
{
   return m_PairContainer.second;
}


//------------------------------------------------------------------------------
template<class FirstType, class SecondType>
SecondType& EcXmlPairType<FirstType,SecondType>::second
   (
   )
{
   return m_PairContainer.second;
}


//------------------------------------------------------------------------------
template<class FirstType, class SecondType>
void EcXmlPairType<FirstType,SecondType>::setSecond
   (
   const SecondType& second
   )
{
   m_PairContainer.second=second;
}


//------------------------------------------------------------------------------
template<class FirstType, class SecondType>
void EcXmlPairType<FirstType,SecondType>::set
   (
   const FirstType& first,
   const SecondType& second
   )
{
   m_PairContainer.first=first;
   m_PairContainer.second=second;
}


//------------------------------------------------------------------------------
template<class FirstType, class SecondType>
void EcXmlPairType<FirstType,SecondType>::setXmlTagNames
   (
   const EcString& first,
   const EcString& second
   )
{
   m_TagNames = std::make_pair(first, second);
}


//------------------------------------------------------------------------------
template<class FirstType, class SecondType>
EcBoolean EcXmlPairType<FirstType,SecondType>::read
   (
   EcXmlReader& stream
   )
{
   EcBoolean retVal=EcXmlObject::read(stream);

   // if not EMPTY_TAG for current element, process data
   if(retVal && stream.mode() != EcXmlFileReader::EMPTY_TAG)
   {

      // keep looping so long as there is valid next start tag.

      EcXmlFileReader::XML_READER_MODE mode = stream.readXml();
      if( EcXmlFileReader::ERROR_FOUND == mode)
      {
         return EcFalse;
      }

      while ( mode == EcXmlFileReader::START_TAG ||
              mode == EcXmlFileReader::EMPTY_TAG )
      {
         if( stream.element() == m_TagNames.first ||
             stream.element() == EcXml::EcFirstToken )
         {
            // read the first
            m_PairContainer.first.xmlInit();
            m_PairContainer.first.read(stream);
         }
         else if (stream.element() == m_TagNames.second ||
                  stream.element() == EcXml::EcSecondToken )
         {
            // read the second
            m_PairContainer.second.xmlInit();
            m_PairContainer.second.read(stream);
         }
         else
         {
            EcPrint(Warning) << "EcXmlPairType Error: file not valid.\n\t"
                   "Format not correct.\n\tFile: " << stream.filename()
                   << "\n\tLine: " << stream.lineCountOfFile();
            EcPrint(Warning) << "\tExpected " << m_TagNames.first << " or "
                   << m_TagNames.second << " but received "
                   << stream.element() << ".";
            retVal=EcFalse;
         }

         // read the end tag for the element
         mode = stream.readXml();
         if( EcXmlFileReader::ERROR_FOUND == mode)
         {
            return EcFalse;
         }
      }
   }
   return retVal;
}


//------------------------------------------------------------------------------
template<class FirstType, class SecondType>
EcBoolean EcXmlPairType<FirstType,SecondType>::write
   (
   EcXmlWriter& stream
   ) const
{
   EcBoolean retVal=EcXmlObject::write(stream);

   // write the first element
   stream.writeStartTagUsingParentNamespace(m_TagNames.first);
   (m_PairContainer.first).write(stream);
   stream.writeEndTag();

   // write the second element
   stream.writeStartTagUsingParentNamespace(m_TagNames.second);
   (m_PairContainer.second).write(stream);
   stream.writeEndTag();

   return retVal;
}


//------------------------------------------------------------------------------
template<class FirstType, class SecondType>
EcBoolean EcXmlPairType<FirstType,SecondType>::writeSchema
   (
   EcXmlSchema& stream
   ) const
{
   EcBoolean retVal=EcXmlObject::writeSchema(stream);

   // write the first element
   stream.writeStartTagUsingParentNamespace(m_TagNames.first);
   FirstType().writeSchema(stream);
   stream.writeEndTag();

   // write the second element
   stream.writeStartTagUsingParentNamespace(m_TagNames.second);
   SecondType().writeSchema(stream);
   stream.writeEndTag();

   return retVal;
}


//------------------------------------------------------------------------------
template<class FirstType, class SecondType>
ECXML_DEFINE_TOKENS(EcXmlPairType<FirstType BOOST_PP_COMMA() SecondType>, EcXml::EcPairTypeToken);
