#ifndef ecToken_H_
#define ecToken_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecToken.h
/// @class EcToken
/// @brief An EcString-like class that holds a tag and a namespace.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

#include <boost/preprocessor/seq/for_each.hpp>
#include <iosfwd>

/// External macro for specifying xml tokens.
#define ECTOKEN_DEFINITIONS(decl,seq) BOOST_PP_SEQ_FOR_EACH(_ECTOKEN_DECL,decl,_MAKE_SEQ2(seq))

// If ECTOKEN_DEFINE is defined, then we also initialize the token.
#ifdef ECTOKEN_DEFINE
#  define _ECTOKEN_DEFN(name,str)  name = str
#else
#  define _ECTOKEN_DEFN(name,str)  name  ///< _ECTOKEN_DEFN(name,str)
#endif

/// _ECTOKEN_DECL(r,decl,elem) Iterator macro to generate token statements depending on ECTOKEN_DEFINE.
#define _ECTOKEN_DECL(r,decl,elem) extern decl const EcToken _ECTOKEN_DEFN elem;

/** Create a set of macros to add an additional set of () around each tuple
    element in a sequence.  It will take (a,b)(c,d) and return ((a,b))((c,d))
*/
#define _MAKE_SEQ2(seq)        BOOST_PP_CAT(_SEQ2_MACRO_1 seq,_FINISH)()
#define _SEQ2_MACRO_1(x,y)     ((x, y)) _SEQ2_MACRO_2          ///< macro for tuple sequences
#define _SEQ2_MACRO_2(x,y)     ((x, y)) _SEQ2_MACRO_1          ///< macro for tuple sequences
#define _SEQ2_MACRO_1_FINISH()                                 ///< macro for tuple sequences
#define _SEQ2_MACRO_2_FINISH()                                 ///< macro for tuple sequences


class EC_STABLE_XML_DECL EcToken
{
public:
   /// default constructor
   EcToken
      (
      );

   /// constructor from EcString reference (implicit construction okay)
   EcToken
      (
      const EcString& token
      );

   /// constructor from char* (implicit construction okay)
   EcToken
      (
      const char* token
      );

   /// constructor from namespace/EcString pair
   EcToken
      (
      const EcString& xmlNamespace,
      const EcString& token
      );

   /// destructor
   virtual ~EcToken
      (
      );

   /// copy constructor
   EcToken
      (
      const EcToken& orig
      );

   /// assignment operator
   EcToken& operator=
      (
      const EcToken& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcToken& orig
      ) const;

   /// inequality operator
   EcBoolean operator!=
      (
      const EcToken& orig
      ) const;

   /// less-than operator
   EcBoolean operator<
      (
      const EcToken& orig
      ) const;

   /// get namespace
   virtual EcString xmlNamespace
      (
      ) const;

   /// get token
   virtual EcString token
      (
      ) const;

   /// get namespace/token pair
   virtual EcString namespaceAndToken
      (
      ) const;

   /// Remove leading and trailing whitespace
   virtual void strip
      (
      );

   // Provide basic string methods.  They are pass-throughs to the token.

   /// operator=
   EcToken& operator=(const EcString& token);

   /// operator+=
   EcToken& operator+=(const EcString& token);

   /// operator==
   EcBoolean operator==(const EcString& orig) const;

   /// return length of sequence
   size_t size() const;

   /// return length of sequence
   size_t length() const;

   /// resizes the token string to size n
   void resize(size_t n);

   /// clears the token string
   void clear();

   /// returns true if string is empty
   EcBoolean empty() const;

   /**
    * @brief Appends a copy of string str
    * @param str
    * @return *this
    */
   EcString& append(const EcString& str);

   /**
    * @brief Appends a copy of string str to the token at the position
    * @param str another string object, whose value is appended
    * @param pos position of the first character in str that is copied to the object as a substring
    * @param n number of characters to copy
    * @return *this
    */
   EcString& append(const EcString& str, size_t pos, size_t n);

   /**
    * @brief Appends a copy of the first n characters in the array of characters pointed by s
    * @param s pointer to an array of characters
    * @param n number of characters to copy
    * @return *this
    */
   EcString& append(const char* s, size_t n);

   /// Assigns a new value to the string, replacing its current contents
   void assign(const EcString&);

   /// Erases part of the string
   EcString& erase(size_t pos = 0, size_t n = EcString::npos);

   /// Copies part of the string
   size_t copy(char* s, size_t n, size_t pos = 0);

   /// Swaps the string
   void swap(EcString& str);

   /// returns const pointer to the character array for the string
   const char* c_str() const;

   /**
    *  @brief find EcString& str
    *  @param[in] str another string
    *  @param[in] pos Position of the first character in the string to be
    *             considered in the search
    *  @return  The position of the first character of the first match
    */
   size_t find(const EcString& str, size_t pos = 0) const;

   /**
    *  @brief find const char* s
    *  @param[in] s another string
    *  @param[in] pos Position of the first character in the string to be
    *             considered in the search
    *  @param[in] n Length of sequence of characters to match
    *  @return  The position of the first character of the first match
    */
   size_t find(const char* s, size_t pos, size_t n) const;

   /**
    *  @brief find const char* s
    *  @param[in] s another string
    *  @param[in] pos Position of the first character in the string to be
    *             considered in the search
    *  @return  The position of the first character of the first match
    */
   size_t find(const char* s, size_t pos = 0) const;

   /**
    *  @brief find const char c
    *  @param[in] c another string
    *  @param[in] pos Position of the first character in the string to be
    *             considered in the search
    *  @return  The position of the first character of the first match
    */
   size_t find(char c, size_t pos = 0) const;

   /**
    * @brief substr
    * @param pos Position of the first character to be copied as a substring
    * @param n Number of characters to include in the substring
    * @return A string object with a substring of this object.
    */
   EcString substr(size_t pos = 0, size_t n = EcString::npos) const;

   /// Provide implicit type-casting from EcToken to EcString.
   operator const EcString&() const;

protected:
   EcString m_Token;           ///< The token string
   EcString m_XmlNamespace;    ///< The XML namespace string
};

/// overload of operator== to compare EcString with EcToken
inline EcBoolean EC_STABLE_XML_DECL
operator==
   (
   const EcString& left,
   const EcToken& right
   )
{
   return right.operator==(left);
}

/// overload of operator+ to add an EcString to an EcToken
inline EcToken EC_STABLE_XML_DECL
operator+
   (
   const EcToken& left,
   const EcString& right
   )
{
   return (EcToken(left) += right);
}

/// overload of operator+ to add a char* to an EcToken
inline EcToken EC_STABLE_XML_DECL
operator+
   (
   const EcToken& left,
   const char* right
   )
{
   return (EcToken(left) += right);
}

/// overload of operator<< to add EcToken to an ostream
inline std::ostream& operator<<
   (
   std::ostream& os,
   const EcToken& token
   )
{
   return os << token.token();
}

#endif // ecToken_H_
