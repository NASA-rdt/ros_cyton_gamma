#ifndef ecXXTea_H_
#define ecXXTea_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecXXTea.h
/// @class Ec::EcXXTea
/// @brief The XXTea cipher
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecTeaBase.h"
#include "ecTeaManipulators.h"

namespace Ec
{

class EC_STABLE_FILTERSTREAM_DECL EcXXTea : public EcTeaBase
{
public:
   static const EcU32 DELTA;  ///< set to 0x9e3779b9

   /// default ctor
   EcXXTea
      (
      );

   /// ctor with key
   /**
   Constructor with key for the cipher
   @param[in] newKey the string of characters to be used for the key
   @param[in] newKeyLen the length of the key: the number of bytes
   */
   EcXXTea
      (
      const unsigned char* newKey,
      const EcU32 newKeyLen
      );

   /// dtor
   virtual ~EcXXTea
      (
      );

   /// copy ctor
   EcXXTea
      (
      const EcXXTea& rhs
      );

   /// assignment operator
   EcXXTea& operator=
      (
      const EcXXTea& rhs
      );

   /// encrypt
   /**
    Encrypts the src vector using the XXTea algorithm and stores the results in the dest vector
    @param[in] src the clear text to be encrypted
    @param[out] dest the cipher text
    @return EcBoolean return true on success, failure otherwise
    */
   virtual EcBoolean encrypt
      (
      const charVector& src,
      charVector& dest
      );

   /// decrypt
   /**
    Decrypts the src vector using the XXTea algorighm and stores the results in the dest vector
    @param[in] src the cipher text to be decrypted
    @param[out] dest the clear text result of decrypting
    @return EcBoolean return true on success, failure otherwise
    */
   virtual EcBoolean decrypt
      (
      const charVector& src,
      charVector& dest
      );

   /// copy using copy ctor
   EcXXTea* clone
      (
      )  const;

   /// copy using default ctor
   EcXXTea* create
      (
      ) const;

protected:
   /// crypt_pre
   /**
   Perform pre-processing necessary to prepare the cipher engine.
   Currently this includes generating the Tea sub-keys
   @return EcBoolean return true on success, failure otherwise
   */
   virtual EcBoolean crypt_pre
      (
      );

   /// crypt_post
   /**
   Perform post-processing necessary
   @return EcBoolean return true on success, failure otherwise
   */
   virtual EcBoolean crypt_post
      (
      );

   /// generateSubKey
   /**
   Convert the public key into the 2 keys required by the cipher
   @return EcBoolean return true on success, failure otherwise
   */
   virtual EcBoolean generateSubKey
      (
      );

   /// crypt
   /*
   The XXTea cipher algorithm. All pre- and post-processing assumed to be done
   @param[in] in the input to the cipher
   @param[in] doEncrypt the direction of the cipher. True for encryption, False for decryption
   @param[out] out the output of the cipher
   @return EcBoolean return true on success, failure otherwise
   */
   virtual EcBoolean crypt
      (
      const charVector& in,
      charVector& out,
      const EcBoolean doEncrypt
      ) const;

   /// cryptAll
   /*
   Do all pre-processing, cryption, and post-processing
   @param[in] src the input to the cipher
   @param[in] doEncrypt the direction of the cipher. True for encryption, False for decryption
   @param[out] dest the output of the cipher
   @return EcBoolean return true on success, failure otherwise
   */
   virtual EcBoolean cryptAll
      (
      const charVector& src,
      charVector& dest,
      const EcBoolean doEncrypt
      );

   EcU32Vector            m_SubKey;  ///< hold the sub key required by algorithm
   EcTeaManipulators      m_Manip;   ///< utility class for converting between strings and vectors
};

} // namespace Ec

#endif // ecXXTea_H_
