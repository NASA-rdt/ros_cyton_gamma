#ifndef ecBase64_H_
#define ecBase64_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecBase64.h
/// @brief Base 64 encoding functions
/// @details namespace Base64
///*** Based on C_Base64 by Bob Withers*********************************
///*********************************************************************
///* C_Base64 - a simple base64 encoder and decoder.
///*
///*     Copyright (c) 1999, Bob Withers - bwit@pobox.com
///*
///* This code may be freely used for any purpose, either personal
///* or commercial, provided the authors copyright notice remains
///* intact.
///*********************************************************************
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>
#include <string>

/// Base 64 encoding functions
namespace Base64
{
   /// Base64 encoder
   /**
      \param data Decoded data
      \return Encoded data
   */
   std::string EC_SENSOR_SENSCORE_DECL encode
      (
      const std::string& data
      );

   /// Base64 encoder
   /**
      \param data Decoded data
      \param ret Encoded data
   */
   void EC_SENSOR_SENSCORE_DECL encode
      (
      const std::string& data,
      std::string& ret
      );

   /// Base64 decoder
   /**
      \param data Encoded Data
      \return Decoded data
   */
   std::string EC_SENSOR_SENSCORE_DECL decode
      (
      const std::string& data
      );

   /// Base64 decoder
   /**
      \param data Encoded Data
      \param ret  Decoded data
   */
   void EC_SENSOR_SENSCORE_DECL decode
      (
      const std::string& data,
      std::string& ret
      );
}

#endif // ecBase64_H_
