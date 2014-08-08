#ifndef ecJpegLib_H_
#define ecJpegLib_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecJpegLib.h
/// @brief JPEG include file
/// @details JPEG includes and structures
//
//------------------------------------------------------------------------------
extern "C"
{

#include <stdio.h>
#include <jpeglib.h>

#include "ecJpegInclude.h"

//  Energid Specific Protos

/// Expanded data destination object for stdio output
struct memory_source_mgr
{
  jpeg_source_mgr pub;	///< public fields

  JOCTET * buffer;		///< jpeg temp buffer
  JOCTET * input_data_buffer;  ///< buffer containing the JPEG data
  boolean start_of_buffer;     ///< Have we stated reading from the buffer yet?
  unsigned int    bufsize;     ///< input data buffer size
  unsigned int    datacount;   ///< count of data transferred

  /// transfers data from the data buffer to the source manager
  JMETHOD(unsigned int,transfer_data_from_buffer,(struct memory_source_mgr*,unsigned int size));
};

/// pointer to the source manager
typedef memory_source_mgr* mem_src_ptr;

/// copy memory buffer to the source manager
EXTERN(void) jpeg_membuf_src JPP((j_decompress_ptr cinfo,
                                 unsigned char * input_data_buffer,
                                 unsigned int buffer_size ));

/// Expanded data destination object for stdio output
struct memory_destination_mgr
{
  struct jpeg_destination_mgr pub; /// pointer to the destiation manager

  JOCTET * buffer;		///< jpeg data buffer
  int    bufsize;       ///< size of the jpeg data buffer
  int    datacount;     ///< index into the buffer
};

/// destination manager pointer
typedef memory_destination_mgr* mem_dest_ptr;

/// allocate the destination buffer
GLOBAL(void)
jpeg_memory_dest (j_compress_ptr cinfo, JOCTET *buffer,int bufsize);

}  // extern "C"

#endif // ecJpegLib_H_
