#ifndef ecFilters_H_
#define ecFilters_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecFilters.h
/// @class Ec::EcFilters
/// @brief A complete filter specification
/// @details A class to hold a complete filter specification: an ordered list of
///          filters and each filter's data
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <string>
#include <vector>
#include <iostream>

namespace Ec
{
   class EC_STABLE_FILTERSTREAM_DECL EcFilters
   {
   public:

      /// filter enumeration
      enum FILTER
      {
         RAW                                   
         ,BZIP2_COMPRESS,BZIP2_DECOMPRESS      
         ,ZLIB_COMPRESS,ZLIB_DECOMPRESS
         ,GZIP_COMPRESS,GZIP_DECOMPRESS
         ,BASE64_ENCODE,BASE64_DECODE
         ,RSA_ENCRYPT,RSA_DECRYPT
         ,TEA_ENCRYPT,TEA_DECRYPT
      };

      typedef std::vector<unsigned char> KEY_TYPE;    ///< key type definition 

      /**
	  * \class EcFilterArg
      * \brief Hold the args to a single filter
      *
      * A class to hold any parameters needed for a specific filter
      */
      class EcFilterArg
      {
      public:
         /// ctor
         /**
          Constructor with a specific filter
          @param[in] aFilter the enum specifier identifying the kind of filter the parameters are for
          */
         EcFilterArg(const FILTER& aFilter)
               : m_Filter(aFilter)
               , m_PublicKey(KEY_TYPE())
               , m_PrivateKey(KEY_TYPE())
         {}

         /// ctor
         /**
          Constructor for a cipher filter with a single public key
          @param[in] aFilter the enum specifier identifying the kind of cipher filter and a public key
          @param[in] aPublicKey the public key for the cipher filter
         */
         EcFilterArg
         (
            FILTER aFilter,
            const KEY_TYPE& aPublicKey
         )
               : m_Filter(aFilter)
               , m_PublicKey(aPublicKey)
               , m_PrivateKey(KEY_TYPE())
         {}

         /// ctor
         /**
          Constructor with filter and cipher public and private keys
          @param[in] aFilter the enum specifier identifying the kind of cipher filter for the keys
          @param[in] aPublicKey the public key for the cipher filter
          @param[in] aPrivateKey the private key for the cipher filter
         */
         EcFilterArg
         (
            FILTER aFilter,
            const KEY_TYPE& aPublicKey,
            const KEY_TYPE& aPrivateKey
         )
               : m_Filter(aFilter)
               , m_PublicKey(aPublicKey)
               , m_PrivateKey(aPrivateKey)
         {}

         /// dtor
         virtual ~EcFilterArg()
         {}

         /// copy ctor
         EcFilterArg(const EcFilterArg& rhs)
         {
            m_Filter      = rhs.m_Filter;
            m_PublicKey   = rhs.m_PublicKey;
            m_PrivateKey  = rhs.m_PrivateKey;
         }

         /// assignment operator
         EcFilterArg& operator=(const EcFilterArg& rhs)
         {
            if ( this == &rhs )
            {
               return *this;
            }
            m_Filter      = rhs.m_Filter;
            m_PublicKey   = rhs.m_PublicKey;
            m_PrivateKey  = rhs.m_PrivateKey;
            return *this;
         }

         FILTER   m_Filter;             ///< the filter specifier

         KEY_TYPE m_PublicKey;          ///< public key used if filter specifier is a cipher
         KEY_TYPE m_PrivateKey;         ///< private key used if filter specifier is a cipher

      };

      typedef std::vector<EcFilterArg> FILTER_ARGS;         ///< the filter arguments type

      /// ctor
      EcFilters();

      /// ctor
      /**
       Constructor with filter args
       @param[in] newArgs filter arguments for filter
      */
      EcFilters
         (
          const FILTER_ARGS& newArgs
          );

      /// dtor
      virtual ~EcFilters();

      /// copy ctor
      EcFilters
         (
          const EcFilters& rhs
          );

      /// assignment operator
      EcFilters& operator=
         (
          const EcFilters& rhs
          );

      /// addRaw
      /**
       Add a raw (i.e., empty/do-nothing/no-op) filter
      */
      void addRaw();

      /// addBzip2Compress
      /**
       Add the compression filter using the bzip2 algorithm
      */
      void addBzip2Compress();

      /// addBzip2Decompression
      /**
       Add the decompression filter using the bzip2 algorithm
      */
      void addBzip2Decompress();

      /// addZlibCompress
      /**
       Add the compression filter using zlib algorithm
      */
      void addZlibCompress();

      /// addZlibDecompress
      /**
       Add the decompression filter using zlib algorithm
      */
      void addZlibDecompress();

      /// addGzipCompress
      /**
       Add the compression filter using gzip algorithm
      */
      void addGzipCompress();

      /// addGzipDecompress
      /**
       Add the decompression filter using gzip algorithm
      */
      void addGzipDecompress();

      /// addBase64Encode
      /**
       Add the filter for base64 encoding
      */
      void addBase64Encode();

      /// addBase64Decode
      /**
       Add the filter for base64 decoding
      */
      void addBase64Decode();

      /// addTeaEncrypt
      /**
       Add the tea encryption filter
       @param[in] aPublicKey the public cipher key to use
       */
      void addTeaEncrypt
         (
          const KEY_TYPE& aPublicKey
          );

      /// addTeaDecrypt
      /**
       Add the tea decryption filter
       @param[in] aPublicKey the public cipher key to use
       */
      void addTeaDecrypt
         (
          const KEY_TYPE& aPublicKey
          );

      /// addRsaEncrypt
      /**
       Add the rsa encryption cipher
       @param[in] aPublicKey the public key to use
       @param[in] aPrivateKey the private key to use
      */
      void addRsaEncrypt
         (
          const KEY_TYPE& aPublicKey,
          const KEY_TYPE& aPrivateKey
          );

      /// addRsaDecrypt
      /**
       Add the rsa decryption cipher
       @param[in] aPublicKey the public key to use
       @param[in] aPrivateKey the private key to use
      */
      void addRsaDecrypt
         (
          const KEY_TYPE& aPublicKey,
          const KEY_TYPE& aPrivateKey
          );

      /// invert
      /**
       convenience method to invert the order and direction
       (compress-decompress or encrypt-decrypt) of the filters
       @return FILTER_ARGS the inverted filter spec
      */
      FILTER_ARGS invert() const;

      /// getFilterArgs
      /**
       Return the filter arguments
       @return FILTER_ARGS&
      */
      const FILTER_ARGS& getFilterArgs() const;

      /// determine if filters have been defined
      EcBoolean empty() const;

   private:
      FILTER_ARGS m_FilterArgs;         ///< the filter specification
   };
}

#endif // ecFilters_H_
