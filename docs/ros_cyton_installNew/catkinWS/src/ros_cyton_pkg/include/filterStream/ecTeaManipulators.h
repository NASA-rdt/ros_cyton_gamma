#ifndef ecTeaManipulators_H_
#define ecTeaManipulators_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecTeaManipulators.h
/// @class EcTeaManipulators
/// @brief Utility class for tea cipher
/// @details This class performance simple conversions and operations on vectors and strings as required by the tea algorithm
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecMacros.h>

class EC_STABLE_FILTERSTREAM_DECL EcTeaManipulators
{
public:
   /// Constants used in the tea algorithm
   enum BYTE_CONSTANTS {TEA_MINBLOCKSIZE=8};

   /// ctor
   EcTeaManipulators
      (
      )
   {}

   /// dtor
   virtual ~EcTeaManipulators
      (
      )
   {}

   /// char2Vec
   /**
    Convert a character array to a vector of character
    @param[in] in array of characters to be converted
    @param[in] inLen number of bytes in array
    @param[out] out the vector array of characters
   */
   inline static void char2Vec
      (
      const char* in,
      const EcU32 inLen,
      std::vector<char>& out
      )
   {
      out.resize(inLen);
      memcpy(&out[0],in,inLen);
   }

   /// addPksPadding
   /**
    Add bytes of padding to meet TEA_MINBLOCKSIZE using the Pks padding method
    @param[in] blockSize number of bytes
    @param[in,out] fillBlock the vector of char, wrong blocksize on entry. On exit of the correct blockSize, with padding added
   */
   inline static void addPksPadding
      (
      const char blockSize,
      std::vector<char>& fillBlock
      )
   {
      const char  byteQtyToAdd= blockSize - fillBlock.size();

      if ( byteQtyToAdd > 0 )
      {
         for (char jj=0; jj < byteQtyToAdd; jj++)
         {
            fillBlock.push_back(byteQtyToAdd);
         }
      }
   }

   /// stripPksPadding
   /**
    Remove the Pks padding for the vector
    @param[in] minBytes the mininum number of bytes
    @param[in,out] y the vector with the padding on entry, without the padding on exit
   */
   inline static void stripPksPadding
      (
      const char minBytes,
      std::vector<char>& y
      )
   {
      if ( ! y.empty() )
      {
         if ( y.size() >= (unsigned char)minBytes)
         {
            const EcU32 lastIndex=y.size()-1;
            const char lastByteValue = y[lastIndex];
            if ( ( lastByteValue > 0 ) && (lastByteValue <= minBytes) )
            {
               EcBoolean allMatch(true);
               for (EcU32 ii=lastIndex-lastByteValue+1; ii < y.size(); ++ii)
               {
                  if ( lastByteValue != y[ii] )
                  {
                     allMatch=false;
                     break;
                  }
               }
               if ( allMatch )
               {
                  y.resize(y.size()-lastByteValue);
               }
            }
         }
      }
   }

   /// char2ULong
   /**
    Convert 4 bytes (chars or unsigned chars) from a vector of bytes into a single unsigned long
    @param[in] y a vector of bytes
    @param[in] offset offset into the vector for the bytes to be converted
    @param[out] out the unsigned long result of the conversion
    @return EcBoolean return true on success, failure otherwise
   */
   template <typename T>
   inline static EcBoolean char2ULong
      (
      const std::vector<T>& y,
      const EcU32 offset,
      EcU32 & out
      )
   {
      EcBoolean rc(true);
      out=0;
      if ( ( y.size() - offset ) < 4 )
      {
         rc=false;
      }
      else
      {
         out =
            ((EcU32)(y[offset+3] & 255)<<24) |
            ((EcU32)(y[offset+2] & 255)<<16) |
            ((EcU32)(y[offset+1] & 255)<< 8) |
            ((EcU32)(y[offset  ] & 255));
      }
      return rc;
   }

   /// ulong2Char
   /**
    Convert a 4 byte unsigned long int into 4 bytes
    @param[in] x unsigned 32 bit int to be converted
    @param[out] y vector of byte resulting from conversion
   */
   template <typename T>
   inline static void ulong2Char
      (
      const EcU32 x,
      std::vector<T>& y
      )
   {
      y.erase(y.begin(),y.end());
      y.resize(4);
      y[3] = (unsigned char)((x >>24) & 255);
      y[2] = (unsigned char)((x >>16) & 255);
      y[1] = (unsigned char)((x >> 8) & 255);
      y[0] = (unsigned char)((x     ) & 255);
   }

   /// str2Longs
   /**
    Convert a vector of char into a vector of unsigned longs
    @param[in] in the vector of char to be converted
    @param[out] out the vector of 32 bit unsigned long ints resulting from conversion
    @return EcBoolean return true on success, failure otherwise
   */
   inline static EcBoolean str2Longs
      (
      const std::vector<char>& in,
      std::vector<EcU32>& out
      )
   {
      EcBoolean rc(true);

      out.erase(out.begin(),out.end());
      EcU32 lastIndex= 4*static_cast<EcU32>(double(in.size()/4.0f));
      EcU32 leftOvers = in.size() - lastIndex;
      EcU32 reserveSize=lastIndex/4+(leftOvers>0?1:0);
      out.reserve(reserveSize);

      register EcU32 ii;
      EcU32 tempLong(0);
      for (ii=0; ii < lastIndex; ii+=4)
      {
         if ( ! char2ULong(in,ii,tempLong) )
         {
            rc=false;
            break;
         }
         else
         {
            out.push_back( tempLong );
         }
      }

      if (rc && ( leftOvers > 0 ) )
      {
         std::vector<char> fillBlock;
         fillBlock.push_back( in[ii++]);
         if ( ii < in.size() )
            fillBlock.push_back(in[ii++]);
         if ( ii < in.size() )
            fillBlock.push_back(in[ii++]);

         addPksPadding(TEA_MINBLOCKSIZE,fillBlock);
         for (EcU32 jj=0; jj < fillBlock.size(); jj+=4)
         {
            if ( ! char2ULong(fillBlock,jj,tempLong) )
            {
               rc=false;
               break;
            }
            else
            {
               out.push_back( tempLong );
            }
         }
      }
      return rc;
   }

   /// longs2Str
   /**
    Convert a vector of unsigned 32 bit unsigned long ints into a vector of char
    @param[in] in the vector of 32 bit unsigned long ints to be converted
    @param[out] out the vector of chars resulting from conversion
    @param[in] stripTrailingNulls If true then remove padding from trailing bytes
   */
   inline static void longs2Str
      (
      const std::vector<EcU32>& in,
      std::vector<char>& out,
      const EcBoolean stripTrailingNulls
      )
   {
      out.erase(out.begin(),out.end());
      EcU32 reserveSize=in.size()*4;
      out.reserve(reserveSize);

      std::vector<char> temp;
      register EcU32 ii(0);
      for (ii=0; ii < in.size(); ++ii)
      {
         ulong2Char(in[ii],temp);
         out.insert(out.end(),temp.begin(),temp.end());
      }
      if ( stripTrailingNulls )
      {
         stripPksPadding(TEA_MINBLOCKSIZE,out);
      }
   }
};

#endif // ecTeaManipulators_H_
