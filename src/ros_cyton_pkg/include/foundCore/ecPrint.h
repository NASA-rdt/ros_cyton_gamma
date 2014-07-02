#ifndef ecPrint_H_
#define ecPrint_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecPrint.h
/// @class Ec::Print
/// @brief Generalized printing routines.  Allows for printing across
///        shared libraries as well as printing to multiple outputs.
//
//------------------------------------------------------------------------------
#include "ecConstants.h"
#include "ecMutex.h"

#include <boost/iostreams/filtering_stream.hpp>
#include <boost/scoped_ptr.hpp>

namespace boost { template <typename T> class thread_specific_ptr; }

namespace Ec
{

class Application;
class PrintFlushTimer;

class EC_STABLE_FOUNDCORE_DECL Print
{
public:
   /// Different types of printing messages supported.
   enum PrintType
   {
      PrintAll = 0, ///< Print all messages.
      PrintTrace,   ///< "EcTrace: "
      PrintDebug,   ///< "EcDebug: "
      PrintInfo,    ///< "EcInfo : "
      PrintWarning, ///< "EcWarn : "
      PrintError,   ///< "EcError: "
      PrintFatal,   ///< "EcFatal: "
      PrintNone     ///< No prefix / Print no message
   };

   /// Type of stream entry to print to.  Used when adding streams.
   typedef std::ostream* StreamElement;

   /// Returns the unique printing facility for this application.
   /// \return Print& Current printing facility.
   static Print& instance
      (
      );

   /// Override the default output filename.  It will close the existing file
   /// and open a new file if called after data has already been written out.
   /// @param fileName File to write out to.
   void setOutputFile
      (
      const EcString& fileName
      );

   /// Retrieve name of current output file.
   /// @return EcString File in use.
   EcString getOutputFile
      (
      ) const;

   /// Specify the level of printing
   /// @param type Print message level.  Prints at this level and below.
   void setPrintLevel
      (
      const PrintType type
      );

   /// Get the current level of printing
   /// @return PrintType Print message level.
   PrintType printLevel
      (
      ) const;

   /// Specify whether to print timestamps with each message
   /// @param enable Prints timestamps when set to EcTrue
   void setPrintTimestamps
      (
      const EcBoolean enable
      );

   /// Get whether timestamps are enabled
   /// @return EcBoolean EcTrue if timestamps are enabled, EcFalse otherwise
   EcBoolean printTimestamps
      (
      ) const;

   /// Provide access to the output stream.
   /// @param  type          Print message level.
   /// @param  func          Function name to prepend.
   /// @return std::ostream& Output stream to write to.
   std::ostream& ostream
      (
      const PrintType type,
      const char* func
      );

   /// Print statement of a particular type.
   /// @param[in] type   Prefix message to use
   /// @param[in] format printf format string.
   /// @param[in] ...    Variable arguments.
   void write
      (
      const PrintType type,
      const char* format,
      ...
      );

   /// Adds an additional output stream to write to.
   /// @param[in] os Output stream to add as a target.
   void addStreamHandle
      (
      StreamElement os
      );

   /// Removes an existing output stream from the list of writers.
   /// @param[in] os        Output stream to remove from list.
   /// @return    EcBoolean Success or failure of command.
   EcBoolean removeStreamHandle
      (
      StreamElement os
      );

   /// Structure to track entering and exiting of routines.
   class EC_STABLE_FOUNDCORE_DECL ScopedPrint
   {
   public:
      /// Stack constructor.
      /// @param[in] func Function name to prepend to message
      /// @param[in] msg  Message to display
      ScopedPrint
         (
         const char* func,
         const char* msg = ""
         );

      /// Stack destructor
      ~ScopedPrint
         (
         );

      /// Returns the 'depth' of tracing
      /// @return EcU32 Number of levels - used for print indentation.
      static const EcU32 getCount
         (
         );

      /// Retrieves the name of the current function.
      /// @return const char* const Function name
      static const char* const getFunc
         (
         );

   private:
      /// Disallow heap construction.
      void* operator new(size_t) throw() { return 0; }
      /// Internal function depth list on a per thread basis.
      static boost::thread_specific_ptr<std::vector<const char*> > _funcStack;
   };

   /// Writes a given type to an output stream.
   /// @param[in] x         Variable to write out.
   /// @param[in] ofs       File stream to write to.
   /// @return    EcBoolean Success or failure of write command.
   template <typename T> static EcBoolean writeBinary
      (
      const T& x,
      std::ostream& ofs
      )
   {
      /// for now, just use native format
      ofs.write(reinterpret_cast<const char*>(&x), sizeof(x));
      return EcTrue;
   }

   /// reads a given type from an input stream
   /// @param[out] x         Variable to read in.
   /// @param[in]  ifs       File stream to read from.
   /// @return     EcBoolean Success or failure of read command.
   template <typename T> static EcBoolean readBinary
      (
      T& x,
      std::istream& ifs
      )
   {
      /// for now, just use native format
      ifs.read(reinterpret_cast<char*>(&x), sizeof(x));
      return EcTrue;
   }

   ~Print
      (
      );

protected:
   /// Allow our internal flushing class internal access.
   friend class PrintFlushTimer;
   friend class Application;

   /// Disallow public construction.  Use static accessors instead.
   Print
      (
      );

   /// Internal form of print statement.
   /// @param[in] str Pre-processed string to print out.
   void write
      (
      const char* str
      );

   /// Internal method to complete filter stream by adding output file.
   /// It uses exclusive file I/O for platform-specific file locking.
   void addOutputFile
      (
      );

   /// StreamVector type based on std::vector of StreamElements
   typedef std::vector<StreamElement> StreamVector;

   StreamVector m_StreamVector;   ///< Map of streams we are printing to
   PrintType    m_PrefixType;     ///< Prefix for next print command
   PrintType    m_PrintLevel;     ///< Level at which to print messages
   EcBoolean    m_IsRealTime;     ///< Disables printing when enabled
   EcBoolean    m_PrintFunctions; ///< Whether to enable function output
   EcBoolean    m_PrintTimestamps; ///< Whether to enable printing a timestamp for each message
   EcMutex      m_Mutex;          ///< Only allow one writer at a time
   EcString     m_OutputFile;     ///< Name of file to write out to

   boost::iostreams::filtering_ostream m_Stream; ///< Collection of ostreams
   boost::scoped_ptr<PrintFlushTimer> m_pPrintFlusher; ///< Internal thread that flushes output
   static boost::iostreams::filtering_ostream s_NullStream; ///< Empty stream
};

} // namespace Ec

#endif // ecPrint_H_
