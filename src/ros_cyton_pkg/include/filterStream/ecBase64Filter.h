#ifndef ecBase64Filter_H_
#define ecBase64Filter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecBase64Filter.h
/// @class Ec::EcBase64Filter
/// @brief The base64 filter
/// @details The filter performing base64 encoding and decoding.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <boost/iostreams/filter/aggregate.hpp> // aggregate filter

namespace Ec
{
   /// convenience type for boost aggregate filer of type char
   typedef boost::iostreams::aggregate_filter<char, std::allocator<char> > base_type;

   class EC_STABLE_FILTERSTREAM_DECL EcBase64Filter: public  base_type
   {
   public:
      typedef base_type::char_type char_type;      ///< convenience type
      typedef base_type::category  category;       ///< convenience type
      typedef base_type::vector_type vector_type;  ///< convenience type

      /// default ctor
      EcBase64Filter
         (
          const EcBoolean encode=true
          );

      /// copy ctor
      EcBase64Filter
         (
          const EcBase64Filter& rhs
          );

      /// assignment operator
      EcBase64Filter& operator=
         (
          const EcBase64Filter& rhs
          );

      /// dtor
      virtual ~EcBase64Filter();

      /// encode
      /**
       encode the data using the base64 algorithm
       @param[in] src the input to be encoded
       @param[out] dest the result of encoding
      */
      virtual EcBoolean encode
         (
          const vector_type& src,
          vector_type& dest
          ) const;

      /// decode
      /**
       decode the data using the base64 algorithm
       @param[in] src the input to be decoded
       @param[out] dest the result of decoding
      */
      virtual EcBoolean decode
         (
          const vector_type& src,
          vector_type& dest
          ) const;

   protected:

      /// do_filter
      /*
      Concrete method required by abstract base class aggregate_filter.
      Invokes encode or decode based on m_doEncode flag
      @param[in] src input to the filter
      @param[out] dest output from filter
      */
      virtual void do_filter
         (
          const vector_type& src,
          vector_type& dest
          );

   private:
      EcBoolean  m_doEncode;    ///< flag indicating direction of coding. True for encode, False for decode
   };
}

#endif // ecBase64Filter_H_
