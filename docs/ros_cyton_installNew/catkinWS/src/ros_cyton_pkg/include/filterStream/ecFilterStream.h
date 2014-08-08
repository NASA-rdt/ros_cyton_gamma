#ifndef ecFilterStream_H_
#define ecFilterStream_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecFilterStream.h
/// @class Ec::EcFilterStream
/// @brief The high-level class invoking filters on an input stream
/// @details This class invokes a sequence of filter operations on an input stream
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <vector>
#include <boost/iostreams/filtering_stream.hpp>

namespace Ec
{
   class EcFilters;

   class EC_STABLE_FILTERSTREAM_DECL EcFilterStream
   {
   public:
	  /// convenience type of std::vector<char>
      typedef std::vector<char> vector_type;

      /// an output filter refines an output stream controlled by a sink
      /// providing access to the filtered sequence using put() and write()
      typedef boost::iostreams::filtering_ostream   outFilterStream;

      /// an input filter operated on a character sequence controlled by a source,
      /// provding access to the filtered sequence using get() and read()
      typedef boost::iostreams::filtering_istream   inFilterStream;

      /// ctor
      EcFilterStream();

      /// dtor
      virtual ~EcFilterStream();

      /// copy ctor
      EcFilterStream(const EcFilterStream& rhs);

      /// assignment operator
      EcFilterStream& operator=(const EcFilterStream& rhs);


      /// apply filters to some raw input, resulting in a modified output
      /// these filterInput methods are the primary methods for public use

      /// filterInput
      /**
      Apply the filter spec to an input stream, placing results in output stream

      @param[in] filters  the ordered sequence of filters to apply
      @param[in] in the stream of input to apply the filters to
      @param[out] out the stream holding the result
      */
      virtual EcBoolean filterInput
      (
         const EcFilters& filters,
         std::istream& in,
         std::ostream& out
      ) const;

      /// filterInput
      /**
       Apply the filter spec to an input string, placing results in output string

       @param[in] filters  the ordered sequence of filters to apply
       @param[in] in the string of input to apply the filters to
       @param[out] out the string holding the result
      */
      virtual EcBoolean filterInput
      (
         const EcFilters& filters,
         const EcString& in,
         EcString& out
      ) const;

      /// filterInput
      /**
       Apply the filter spec to an input stream, placing results in output string

       @param[in] filters  the ordered sequence of filters to apply
       @param[in] in the stream of input to apply the filters to
       @param[out] out the string holding the result
      */
      virtual EcBoolean filterInput
      (
         const EcFilters& filters,
         std::istream& in,
         EcString& out
      ) const;

      /// filterInput
      /**
       Apply the filter spec to an input string, placing results in output stream

       @param[in] filters  the ordered sequence of filters to apply
       @param[in] in the string of input to apply the filters to
       @param[out] out the stream holding the result
      */
      virtual EcBoolean filterInput
      (
         const EcFilters& filters,
         const EcString& in,
         std::ostream& out
      ) const;

      /// filterOutput
      /**
       Filter output from stream to stream

       @param[in] filters the ordered sequence of filters to apply
       @param[in] in the input
       @param[out] out the output
      */
      virtual EcBoolean filterOutput
      (
         const EcFilters& filters,
         std::istream& in,
         std::ostream& out
      ) const;

      /// filterOutput
      /**
       Filter output from string to string

       @param[in] filters the ordered sequence of filters to apply
       @param[in] in the input
       @param[out] out the output
      */
      virtual EcBoolean filterOutput
      (
         const EcFilters& filters,
         const EcString& in,
         EcString& out
      ) const;

      /// filterOutput
      /**
       Filter output from stream to string

       @param[in] filters the ordered sequence of filters to apply
       @param[in] in the input
       @param[out] out the output
      */
      virtual EcBoolean filterOutput
      (
         const EcFilters& filters,
         std::istream& in,
         EcString& out
      ) const;

      /// filterOutput
      /**
       Filter output from string to stream

       @param[in] filters the ordered sequence of filters to apply
       @param[in] in the input
       @param[out] out the output
      */
      virtual EcBoolean filterOutput
      (
         const EcFilters& filters,
         const EcString& in,
         std::ostream& out
      ) const;


      /// stream2Stream
      /**
       Apply both input AND output filters from stream to stream

       @param[in] inFilters the filters to apply to the input
       @param[in] outFilters the filters to apply to the output
       @param[in] in the input stream
       @param[out] out the output stream
      */
      virtual EcBoolean stream2Stream
      (
         const EcFilters& inFilters,
         const EcFilters& outFilters,
         std::istream& in,
         std::ostream& out
      ) const;

      /// buffer2Buffer
      /**
       Apply both input AND output filters from buffer to buffer

       @param[in] inFilters the filters to apply to the input
       @param[in] outFilters the filters to apply to the output
       @param[in] in the input string buffer
       @param[out] out the output string buffer
      */
      virtual EcBoolean buffer2Buffer
      (
         const EcFilters& inFilters,
         const EcFilters& outFilters,
         const EcString& in,
         EcString& out
      ) const;

      /// stream2Buffer
      /**
       Apply both input AND output filters from stream to buffer

       @param[in] inFilters the filters to apply to the input
       @param[in] outFilters the filters to apply to the output
       @param[in] in the input stream
       @param[out] out the output string buffer
      */
      virtual EcBoolean stream2Buffer
      (
         const EcFilters& inFilters,
         const EcFilters& outFilters,
         std::istream& in,
         EcString& out
      ) const;

      /// buffer2Stream
      /**
       Apply both input AND output filters from buffer to stream

       @param[in] inFilters the filters to apply to the input
       @param[in] outFilters the filters to apply to the output
       @param[in] in the input string buffer
       @param[out] out the output stream
      */
      virtual EcBoolean buffer2Stream
      (
         const EcFilters& inFilters,
         const EcFilters& outFilters,
         const EcString& in,
         std::ostream& out
      ) const;

      /// getWriterStream
      /**
       Return an output filtering stream

       @param[in] filters the filter specification to set in the writer
       @param[in] os the output stream to use in the writer
       @param[out] theOutStream the filtering output writer
      */
      virtual EcBoolean getWriterStream
      (
         const EcFilters& filters,
         std::ostream& os,
         outFilterStream& theOutStream
      ) const;

      /// getReaderStream
      /**
       Return an input filtering stream

       @param[in] filters the filter specification to set in the reader
       @param[in] is the input stream to use in the reader
       @param[out] theInStream the filtering input reader
      */
      virtual EcBoolean getReaderStream
      (
         const EcFilters& filters,
         std::istream& is,
         inFilterStream& theInStream
      ) const;
   };
}

#endif // ecFilterStream_H_
