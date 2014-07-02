#ifndef ecMacros_H_
#define ecMacros_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecMacros.h
/// @brief Macros and C-style general functions.
//
//------------------------------------------------------------------------------
#include "ecConstants.h"
#include "ecPrint.h"
#include <boost/current_function.hpp>

/// traps the process in the debugger
#ifdef _DEBUG
#  include <assert.h>
#  define EcTRAP() assert(0)
#else
#  define ECTRAP()
#endif

/// deletes the object at the pointer and sets the pointer to zero.
/// @tparam Type
/// @param x
template<class Type>
inline void EcDELETE
   (
   Type& x
   )
{
   // it is always safe to regular delete a NULL pointer, but at
   // runtime most EcDELETE'ed pointers are NULL, so checking here is
   // faster
   if(x)
   {
      delete(x);
      x=0;
   }
}

/// array deletes the object at the pointer and sets the pointer to zero.
/// @tparam Type
/// @param x
template<class Type>
inline void EcARRAYDELETE
   (
   Type& x
   )
{
   // it is not safe to array delete a NULL pointer
   if(x)
   {
      delete[] x;
      x=0;
   }
}

/// swap any type
/// @tparam Type
/// @param xx
/// @param yy
template<class Type>
inline void EcSWAP
   (
   Type& xx,
   Type& yy
   )
{
   Type zz=xx;
   xx=yy;
   yy=zz;
}

/// sleep, in integer milleseconds
/// @param ms time in milleseconds
EC_STABLE_FOUNDCORE_DECL void EcSLEEPMS
   (
   EcU32 ms
   );

/// used for DWORD alignment
/// @param bits integer number of bits
#define WIDTHBYTES(bits)    (((bits) + 31) / 32 * 4)

/// Provide backwards compatibility with EcWRITEBIN.
#define EcWRITEBIN Ec::Print::writeBinary

/// Provide backwards compatiblity with EcREADBIN
#define EcREADBIN  Ec::Print::readBinary

/** Macros to determine what messages get printed.  Macros are used to
 * remove the overhead of calling an empty function when not enabled.
 * In addition, the 'EcSetEntryExit(EcBoolean)' routine can be used at runtime
 * in Debug mode to turn scope-level tracing on or off.  It has no effect in
 * Release mode.
 */

/// General print statement.  Always available.
#define EcPRINTA(type,...) Ec::Print::instance().write(type, __VA_ARGS__)

/// EcPRINT - General print statement.  Always available.
#define EcPRINT(...)   EcPRINTA(Ec::Print::PrintNone, __VA_ARGS__)

/// EcFATAL - Fatal message.  Display and exit.
#define EcFATAL(...)   EcPRINTA(Ec::Print::PrintFatal, __VA_ARGS__)

/// EcERROR - Error message.  Display and exit.
#define EcERROR(...)   EcPRINTA(Ec::Print::PrintError, __VA_ARGS__)

/// EcWARN  - Warning message.  Display and continue.
#define EcWARN(...)    EcPRINTA(Ec::Print::PrintWarning, __VA_ARGS__)
#if defined(_DEBUG)

/// EcINFO  - Informational message. On with _DEBUG.
#  define EcINFO(...)  EcPRINTA(Ec::Print::PrintInfo, __VA_ARGS__)

/// EcTRACE - Verbose messaging.  On with _TRACE.
#  define EcTRACE(...) EcPRINTA(Ec::Print::PrintTrace, __VA_ARGS__)
#else

/// EcINFO  - Informational message. On with _DEBUG.
#  define EcINFO(...)

/// EcTRACE - Verbose messaging.  On with _DEBUG.
#  define EcTRACE(...)
#endif  //  _DEBUG

/// boost current function
#define EcCurrentFunction     BOOST_CURRENT_FUNCTION

/// Provide a convenient, C++ stream style method of printing.
#define EcPrint(x)   Ec::Print::instance().ostream(Ec::Print::Print##x, EcCurrentFunction)

/// If statement to detect print level
#define EC_IF_PRINT_LEVEL(lvl)    if(Ec::Print::lvl >= Ec::Print::instance().printLevel())

/// Adds a print stream handle
#define EC_ADD_PRINT_HANDLE(x)    Ec::Print::instance().addStreamHandle(&x)

/// Removes a print stream handle
#define EC_REMOVE_PRINT_HANDLE(x) Ec::Print::instance().removeStreamHandle(&x)

/// Get the entry count: @copydoc  Ec::Print::ScopedPrint::getCount()
#define EcENTRYCOUNT              Ec::Print::ScopedPrint::getCount()

/// Get the current function name: @copydoc  Ec::Print::ScopedPrint::getFunc()
#define EcENTRYFUNC               Ec::Print::ScopedPrint::getFunc()

/// Set an entry exit message
#define EcENTRYEXIT(msg)          Ec::Print::ScopedPrint _Ecee(EcCurrentFunction, msg)

/// open the ouput file
#define EcOPENOUTPUTFILE(fn) Ec::Print::instance().setOutputFile(fn)

/// close the ouput file. No-op
#define EcCLOSEOUTPUTFILE()

/// make a directory.
/// @param dirname the directory name
/// @return Returns true for success
EC_STABLE_FOUNDCORE_DECL EcBoolean EcMKDIR
   (
   const EcString& dirname
   );

/// extract just a filename from a path plus filename
/// @param[in] directoryPlusFilename the full path to the file
/// @param[in,out] filenameOnly the file name
/// @return Return true if the file name was extracted
EC_STABLE_FOUNDCORE_DECL EcBoolean EcExtractFilename
   (
   const EcString& directoryPlusFilename,
   EcString& filenameOnly
   );

/// see if a file exists
EC_STABLE_FOUNDCORE_DECL EcBoolean EcFILEEXISTS
   (
   const EcString& directoryPlusFilename
   );


/// convert an integer to a string
EC_STABLE_FOUNDCORE_DECL EcString EcINT2STRING
   (
   EcU32 integer,
   EcU32 radix=10
   );

/// convert a double to a string
EC_STABLE_FOUNDCORE_DECL EcString EcDOUBLE2STRING
   (
   const EcReal value
   );

/// Convert a string to a double
EC_STABLE_FOUNDCORE_DECL EcReal EcSTRING2DOUBLE
   (
   const EcString& valueString
   );

/// Convert a string to a wide string
EC_STABLE_FOUNDCORE_DECL EcWString EcSTRING2WSTRING
   (
   const EcString& str
   );



/// Define some default macros for use in sub-classing EcXmlObject.
/// Provide a convenience declaration for accept(EcXmlObjectVisitor*)
#define ECXMLOBJECT_ACCEPT(EcCls) \
   virtual void accept(EcXmlObjectVisitor* v) const { v->visit(this); }

/// Provide a convenience declaration for accept(EcXmlObjectVisitor*)
#define ECXMLOBJECT_NVACCEPT(EcCls) \
   void accept(EcXmlObjectVisitor* v) const { v->visit(this); }

/// Provide a convenience declaration and definition of clone()
#define ECXMLOBJECT_CLONE(EcCls) \
   virtual EcXmlObject* clone() const \
   { \
      return new EcCls(*this); \
   }

/// Provide a convenience declaration and definition of equality(const EcXmlObject*)
#define ECXMLOBJECT_EQUALITY(EcCls) \
   virtual EcBoolean equality(const EcXmlObject* other) const \
   { \
      EcBoolean retVal=EcTrue; \
      const EcCls* cast = dynamic_cast<const EcCls*>(other); \
      if(!cast || !(*this==*cast)) \
      { \
         retVal=EcFalse; \
      } \
      return retVal; \
   }

/// Provide a convenience declaration and definition of newObject()
#define ECXMLOBJECT_NEWOBJECT(EcCls) \
   virtual EcXmlObject* newObject() const \
   { \
      return new EcCls(); \
   }

/// Provide a convenience declaration and definition of xmlObjectCreator()
#define ECXML_XMLOBJECTCREATOR(EcCls) \
   static EcXmlObject* xmlObjectCreator() \
   { \
      return new EcCls(); \
   }

/// Provide a convenience declaration and definition of token() and classToken()
/// This macro is split into two sections to keep from having to include
/// the class tokens header file in the header.
#define ECXML_DECLARE_TOKENS \
   virtual const EcToken& token() const \
   { \
      return classToken(); \
   } \
   static const EcToken& classToken()

/// Provide a convenience token definition method
#define ECXML_DEFINE_TOKENS(EcCls,EcClsToken) \
   const EcToken& EcCls::classToken() \
   { \
      return EcClsToken; \
   }

/// Convenience macro for registering this class within a container.
#define ECXML_REGISTER_COMPONENT_CREATOR(EcCls) \
   registerComponentCreator(EcCls::classToken(),EcCls::xmlObjectCreator)

/**
 Convenience macro for declaring the 'Big Four'.  Actually it is 'Big Five'.
 This macro declares a constructor, destructor, copy constructor, equal operator, and equality operator
 The copy constructor and equal operator execute a deep copy unless otherwise noted in the header file
 of the class.
*/
#define ECDECLARE_BIGFOUR(EcCls) \
   EcCls(); \
   virtual ~EcCls(); \
   EcCls(const EcCls&); \
   EcCls& operator=(const EcCls&); \
   EcBoolean operator==(const EcCls&) const

/**
 Convenience macro for declaring methods required to make a derived
 EcXmlObject concrete by calling the following macros in order:
 #ECDECLARE_BIGFOUR(EcCls),  #ECXMLOBJECT_CLONE(EcCls), #ECXMLOBJECT_EQUALITY(EcCls),
 #ECXMLOBJECT_NEWOBJECT(EcCls), and #ECXML_DECLARE_TOKENS
*/
#define ECXMLOBJECT(cls) \
   ECDECLARE_BIGFOUR(cls); \
   ECXMLOBJECT_CLONE(cls) \
   ECXMLOBJECT_EQUALITY(cls) \
   ECXMLOBJECT_NEWOBJECT(cls) \
   ECXML_DECLARE_TOKENS

#endif // ecMacros_H_
