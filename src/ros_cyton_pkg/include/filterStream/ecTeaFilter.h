#ifndef ecTeaFilter_H_
#define ecTeaFilter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecTeaFilter.h
/// @class Ec::EcTeaFilter
/// @brief The XXTea cipher
/// @details The tea filter class as required by aggregate filter base class
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <boost/iostreams/filter/aggregate.hpp> // aggregate filter

namespace Ec
{
   /// type definition of a boost agregate filter
   typedef boost::iostreams::aggregate_filter<char, std::allocator<char> > base_type;

   class EcTeaBase;

   class EC_STABLE_FILTERSTREAM_DECL EcTeaFilter: public base_type
   {
   private:
      EcBoolean  m_doEncrypt;   ///< flag indicating direction of cipher. True for encrypt, False for decrypt
      EcTeaBase* m_tea;         ///< pointer to tea implementation

   public:
      typedef base_type::char_type char_type;     ///< the base char type
      typedef base_type::category  category;      ///< the base category

      /// default ctor
      EcTeaFilter
         (
         );

      /// ctor with key and direction flag
      /**
      Constructor with key and direction for the cipher
      @param[in] newKey the string of characters to be used for the key
      @param[in] newKeyLen the length of the key: the number of bytes
      @param[in] crypt True for encrption, False for decryption
      */
      EcTeaFilter
         (
            const unsigned char* newKey,
            const EcU32 newKeyLen,
            const EcBoolean crypt=true
         );

      /// copy ctor
      EcTeaFilter
         (
         const EcTeaFilter& rhs
         );

      /// assignment operator
      EcTeaFilter& operator=
         (
         const EcTeaFilter& rhs
         );

      /// dtor
      virtual ~EcTeaFilter
         (
         );

   protected:
      typedef base_type::vector_type vector_type;     ///< the base vector type

      /// createHelper
      virtual EcTeaBase* createHelper
         (
         ) const;

      /// cloneHelper
      virtual EcTeaBase* cloneHelper
         (
         ) const;

      /// do_filter
      /**
      Concrete method required by abstract base class aggregate_filter.
      Invokes encrypt or decrypt based on m_doEncrypt flag
      @param[in] src input to cipher
      @param[out] dest output from cipher
      */
      virtual void do_filter
         (
            const vector_type& src,
            vector_type& dest
         );
   };
}

#endif // ecTeaFilter_H_
