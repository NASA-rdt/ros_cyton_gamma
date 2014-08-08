#ifndef ecTypes_H_
#define ecTypes_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecTypes.h
/// @brief A defininition of basic types of data and structs.
/// @details This presents typedefs to data types and structs.
//
//------------------------------------------------------------------------------
#include "ecConfig.h"

#ifdef _MSC_VER
#  pragma warning(disable:4503) //< Don't warn on long names.
#endif

#include <complex>
#include <map>
#include <string>
#include <vector>
#include <set>

/// Boolean (0 or 1)
typedef bool                    EcBoolean;

/// 32-bit floating-point.
typedef float                   EcF32;           

/// 64-bit floating-point.
typedef double                  EcF64;           

/// Alias for 64-bit float.
typedef EcF64                   EcReal;          

/// A special type for time.
typedef EcF64                   EcTime;          

/// 8-bit unsigned integer
typedef unsigned char           EcU8;            

/// 8-bit signed integer
typedef char                    EcInt8;          

#ifndef EC_NO_BOOST
   /// Boost does a really good job of properly defining size types for
   /// a wide variety of platforms.
#  include <boost/cstdint.hpp>

   /// 16-bit unsigned integer
   typedef boost::uint16_t      EcU16;           

   /// 16-bit signed integer
   typedef boost::int16_t       EcInt16;         

   /// 32-bit unsigned integer
   typedef boost::uint32_t      EcU32;           

   /// 32-bit signed integer
   typedef boost::int32_t       EcInt32;         

   /// 64-bit unsigned integer
   typedef boost::uint64_t      EcU64;           

   /// 64-bit signed integer
   typedef boost::int64_t       EcInt64;   

#else  // EC_NO_BOOST
   /// Assign 'typical' case for users that do not want boost.
   /// Platform dependent - use with caution.

   /// 16-bit unsigned integer
   typedef unsigned short       EcU16;       

   /// 16-bit signed integer
   typedef short                EcInt16;    

#  if defined(__uint32_t_defined)
   /// Debian defines these internally, which is different
   /// from the settings below.
   /// 32-bit unsigned integer
   typedef uint32_t             EcU32;           
   /// 32-bit signed integer
   typedef int32_t              EcInt32;         
   /// 64-bit unsigned integer
   typedef uint64_t             EcU64;           
   /// 64-bit signed integer
   typedef int64_t              EcInt64;         

#  else
   /// 32-bit unsigned integer
   typedef unsigned int         EcU32;           
   /// 32-bit signed integer
   typedef int                  EcInt32;    

#    if ULONG_MAX == 0xffffffff
   // 32-bit OS
   /// 64-bit unsigned integer
   typedef unsigned long long   EcU64;           
   /// 64-bit signed integer
   typedef long long            EcInt64;    

#    else  // ! ULONG_MAX == 0xffffffff
   // 64-bit OS

   ///< 64-bit unsigned integer
   typedef unsigned long        EcU64;   

   /// 64-bit signed integer
   typedef long                 EcInt64;         
#    endif // ULONG_MAX == 0xffffffff
#  endif   // EC_NO_BOOST
#endif   // EC_NO_BOOST

/// a complex real value
typedef std::complex<double>              EcComplexReal;

/// a character string
typedef std::basic_string<char>           EcString;

/// a wide character string
typedef std::basic_string<wchar_t>        EcWString;

/// string organization using vectors
typedef std::vector<EcString>             EcStringVector;

/// a vector of string vectors
typedef std::vector<EcStringVector>       EcStringVectorVector;

/// a vector of vectors of string vectors
typedef std::vector<EcStringVectorVector> EcStringVector3D;

/// a string-u32 map
typedef std::map<EcString,EcU32>          EcStringU32Map;

/// a string-int32 map
typedef std::map<EcString,EcInt32>        EcStringInt32Map;

/// a string-real map
typedef std::map<EcString,EcReal>         EcStringRealMap;

/// a string-string map
typedef std::map<EcString,EcString>       EcStringStringMap;

/// a comparison function for strings
typedef std::less<EcString>               EcStringComp;

/// a general floating-point vector
typedef std::vector<EcReal>               EcRealVector;

/// a general 32-bit unsigned integer vector
typedef std::vector<EcU32>                EcU32Vector;

/// a 2D vector of EcU32
typedef std::vector<EcU32Vector>          EcU32VectorVector;

/// a general 32-bit signed integer vector
typedef std::vector<EcInt32>              EcInt32Vector;

/// a general 2D 32-bit signed integer vector
typedef std::vector<EcInt32Vector>        EcInt32VectorVector;

/// a general 3D 32-bit signed integer vector
typedef std::vector<EcInt32VectorVector>  EcInt32Vector3D;

/// a general 16-bit unsigned integer vector
typedef std::vector<EcU16>                EcU16Vector;

/// a general 16-bit signed integer vector
typedef std::vector<EcInt16>              EcInt16Vector;

/// a general 8-bit unsigned integer vector
typedef std::vector<EcU8>                 EcU8Vector;

/// a general 8-bit signed integer vector
typedef std::vector<EcInt8>               EcInt8Vector;

/// a general boolean vector
typedef std::vector<EcBoolean>            EcBooleanVector;

/// a general 2D boolean vector
typedef std::vector<EcBooleanVector>      EcBooleanVectorVector;

/// a general floating-point array
typedef std::vector<EcRealVector>         EcRealVectorVector;

/// a general floating-point 3D array
typedef std::vector<EcRealVectorVector>   EcRealVector3D;

/// a general complex vector
typedef std::vector<EcComplexReal>        EcComplexVector;

/// a general complex array
typedef std::vector<EcComplexVector>      EcComplexVectorVector;

/// a pair of U32 values
typedef std::pair<EcU32,EcU32>            EcU32U32Pair;

/// a pair of strings
typedef std::pair<EcString,EcString>      EcStringStringPair;

/// a coupling of a string with a U32
typedef std::pair<EcString,EcU32>         EcStringU32Pair;

/// a null deleter. It performs no action when given a pointer and can be useful
/// in some circumstances when creating a shared pointer to a pre-existing statically
/// allocated object (that should not be deleted).
struct EcNullDeleter
{
   /// this is the operating method of the deleter.
   void operator()
      (
      void const *
      ) const {}
};

/// define the self test directory name.
const char EcSelfTestDirectory[] = "selfTest";

#endif // ecTypes_H_
