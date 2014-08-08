#ifndef ecShader_H_
#define ecShader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecShader.h
/// @brief Interface to use OpenGL Shading Language constructs.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecGL.h"

class EC_SENSOR_RENDER_DECL EcShader
{
public:
   /// Different shader types used.
   enum ShaderType {
      Fragment = GL_FRAGMENT_SHADER_ARB,
      Geometry = GL_GEOMETRY_SHADER_EXT,
      Vertex   = GL_VERTEX_SHADER_ARB,
      Program  = GL_PROGRAM_OBJECT_ARB
   };

   EcShader
      (
      );

   virtual ~EcShader
      (
      );

   /// Make sure that extensions are available.
   virtual EcBoolean init
      (
      );

   /// Load and compile a vertex or fragment shader from a file.
   virtual EcBoolean loadShaderFromFile
      (
      const EcString &fileName,
      const ShaderType type
      );

   /// Load and compile a vertex or fragment shader from a string.
   virtual EcBoolean loadShaderFromString
      (
      const EcString &shaderString,
      const ShaderType type
      );

   /// Load and compile both shaders with the following file prefix.
   /// Suffixes used are '.vert' and '.frag'.
   virtual EcBoolean loadShaders
      (
      const EcString &fileName
      );

   /// Attach previously loaded shader to gfx.
   virtual EcBoolean attach
      (
      const EcBoolean linkAndEnable = EcTrue
      );

   /// Give the capability to turn the shader on and off
   virtual EcBoolean enable
      (
      ) const;

   virtual EcBoolean disable
      (
      ) const;

   /// Method to pull variable information from the shader.
   virtual GLint getUniformLocation
      (
      const GLchar *name
      ) const;

   static const EcString getVertexShader
      (
      );

   virtual GLhandleARB getProgramId
      (
      ) const;

protected:
   /// Display shader compiler output.
   virtual void printInfoLog
      (
      const GLhandleARB shader,
      const ShaderType type
      ) const;

   /// Handles to current shader objects.
   GLhandleARB m_shaderProgram;
   GLhandleARB m_shaderFS;
   GLhandleARB m_shaderGS;
   GLhandleARB m_shaderVS;

   /// Flag to verify extension support.
   EcBoolean m_isInited;

   static EcString defaultVertexShader;
};

#endif // ecShader_H_
