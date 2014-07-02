#ifndef ecTeaBase_H_
#define ecTeaBase_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecTeaBase.h
/// @class Ec::EcTeaBase
/// @brief A base class for the TEA cipher
/// @details This is the abstract base class for the TEA cipher
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

namespace Ec
{

class EC_STABLE_FILTERSTREAM_DECL EcTeaBase
{
public:

   /// An enum of the available TEA byte constants
   enum BYTE_CONSTANTS
   {
      TEA_MINKEYSIZE=16,       ///< minimum key is 16 bytes
      TEA_MAXBLOCKSIZE=1024    ///< max block size is 1024 bytes
   };

   typedef EcInt8Vector charVector;      ///< type definition of a character vector of 8-bit char elements
   typedef EcU8Vector keyVector;         ///< type definition of a key vector of 8-bit unsigned integers

   /// default ctor
   EcTeaBase();

   /// non-default ctor
   /**
   Constructor with key for the cipher
   @param[in] newKey the string of characters to be used for the key
   @param[in] newKeyLen the length of the key: the number of bytes
   */
   EcTeaBase
      (
      const unsigned char* newKey,
      const EcU32 newKeyLen
      );

   /// dtor
   virtual ~EcTeaBase();

   /// copy ctor
   EcTeaBase(const EcTeaBase& rhs);

   /// assignment operator
   EcTeaBase& operator=(const EcTeaBase& rhs);

   /// encrypt
   /**
      Encrypts the src vector using the tea algorithm and stores the results in the dest vector
      @param[in] src the clear text to be encrypted
      @param[out] dest the cipher text
      */
   virtual EcBoolean encrypt
      (
      const charVector& src,
      charVector& dest
      ) = 0;

   /// decrypt
   /**
      Decrypts the src vector using the XXTea algorighm and stores the results in the dest vector
      @param[in] src the cipher text to be decrypted
      @param[out] dest the clear text result of decrypting
      */
   virtual EcBoolean decrypt
      (
      const charVector& src,
      charVector& dest
      ) = 0;

   /// setKey
   /**
     Sets the public key for the cipher
     @param[in] newKey the string of characters to be used for the key
     @param[in] newKeyLen the length of the key: the number of bytes
   */
   virtual EcBoolean setKey
      (
      const unsigned char* newKey,
      const EcU32 newKeyLen
      );

   /// clearKey
   /**
     Clears the key
   */
   virtual void clearKey();

   /// clone using copy ctor
   virtual EcTeaBase* clone() const = 0;

   /// create using default ctor
   virtual EcTeaBase* create() const = 0;

protected:
   /// crypt_pre
   /**
   Perform pre-processing necessary to prepare the cipher engine.
   @return EcBoolean
   */
   virtual EcBoolean crypt_pre() = 0;

   /// crypt_post
   /**
   Perform post-processing necessary
   @return EcBoolean
   */
   virtual EcBoolean crypt_post() = 0;

   keyVector      m_UserKey; ///< hold the public key to the cipher
   EcBoolean      m_InitOk;  ///< indicate if cipher is ready to use
};

} // namespace Ec

#endif // ecTeaBase_H_
