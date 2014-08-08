#ifndef ecGL_H_
#define ecGL_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecGL.h
/// @brief Defines GL Extensions
/// @details namespace EcGLExtension
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#if defined(WIN32)
#  include <windows.h>
#  include <GL/gl.h>
#  include <GL/glext.h>
#  include <GL/wglext.h>
#elif defined(__APPLE__) // OSX
#  include <OpenGL/gl.h>
#else // Linux / X11
#  include <GL/gl.h>
#  include <GL/glext.h>
#  include <GL/glx.h>
#endif

#include <foundCore/ecMacros.h>

/// Defines GL Extensions
namespace EcGLExtension
{
   const EcU32
      Nothing          = 0x00000000L, //< Initial setting
      Initialized      = 0x00000001L, //< Set after initialization
      Swap             = 0x00000002L, //< Vertical sync
      PixelBuffer      = 0x00000004L, //< Pbuffer support
      NonPowerOfTwo    = 0x00000008L, //< Support NPOT textures
      Shading          = 0x00000010L, //< Vertex and Fragment shaders
      FloatTextures    = 0x00000020L, //< Floating point textures
      FloatClamping    = 0x00000040L, //< Ability to unclamp floats
      FrameBuffer      = 0x00000080L, //< FrameBufferObject
      VertexBuffer     = 0x00000100L, //< Vertex Buffer Object
      MultiBuffers     = 0x00000200L, //< Render to Multiple Buffers
      TextureRectangle = 0x00000400L, //< Support for NPOT rectangle textures
      FloatNVTextures  = 0x00000800L, //< nVidia-specific float textures
      GeometryShaders  = 0x00001000L, //< Geometry shader support
      OcclusionQuery   = 0x00002000L, //< Occlusion query functions
      IntegerTextures  = 0x00004000L, //< Support for internal integer formats
      Shading_4        = 0x00008000L, //< Shading support version 4
      //
      OpenGL_1_3       = 0x10000000L, //< Minimum version to support
      OpenGL_2_0       = 0x30000000L  //< Encompasses previous versions
   ;
}

class EcGL
{
public:
   // Convenience routine to scale input up-to nearest power of 2.
   static GLuint EC_SENSOR_RENDER_DECL powerOf2
      (
      const GLuint val
      );

   // Display any OpenGL errors generated.
   static EcBoolean EC_SENSOR_RENDER_DECL printGLError
      (
      const GLchar *file,
      const GLuint line
      );

   // Query to see if an extension is available.
   static const EcBoolean EC_SENSOR_RENDER_DECL isSupported
      (
      const EcU32 ext
      );

   // Routine which initializes and attaches extensions.
   static EcBoolean EC_SENSOR_RENDER_DECL init
      (
      );

#ifdef __APPLE__
   static EcBoolean setSwapInterval
      (
      EcInt32 interval
      );
#endif

protected:
   static void setExtension
	  (
	  const EcU32 ext
	  );

   static EcU32 supportStatus;
};

#ifndef __APPLE__
   // GL_ARB_color_buffer_float
   // Provide mechanism to unclamp float values in pipeline.
   extern EC_SENSOR_RENDER_DECL PFNGLCLAMPCOLORARBPROC glClampColorARB;

   // GL_ARB_draw_buffers
   // Ability to render to more than one buffer at a time.
   extern EC_SENSOR_RENDER_DECL PFNGLDRAWBUFFERSARBPROC glDrawBuffersARB;

// Mesa OpenGL headers define these by default, so we need to exclude.
#  if !defined(EC_USING_MESA_HEADERS)
   // GL_ARB_multitexture
   extern EC_SENSOR_RENDER_DECL PFNGLACTIVETEXTUREARBPROC   glActiveTextureARB;
   extern EC_SENSOR_RENDER_DECL PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2fARB;
#  endif

   // GL_ARB_shader_objects
   // Fragment and Vertex shading extension.  Required for any shading code.
   extern EC_SENSOR_RENDER_DECL PFNGLATTACHOBJECTARBPROC         glAttachObjectARB;
   extern EC_SENSOR_RENDER_DECL PFNGLCOMPILESHADERARBPROC        glCompileShaderARB;
   extern EC_SENSOR_RENDER_DECL PFNGLCREATEPROGRAMOBJECTARBPROC  glCreateProgramObjectARB;
   extern EC_SENSOR_RENDER_DECL PFNGLCREATESHADEROBJECTARBPROC   glCreateShaderObjectARB;
   extern EC_SENSOR_RENDER_DECL PFNGLDETACHOBJECTARBPROC         glDetachObjectARB;
   extern EC_SENSOR_RENDER_DECL PFNGLDELETEOBJECTARBPROC         glDeleteObjectARB;
   extern EC_SENSOR_RENDER_DECL PFNGLGETATTACHEDOBJECTSARBPROC   glGetAttachedObjectsARB;
   extern EC_SENSOR_RENDER_DECL PFNGLGETHANDLEARBPROC            glGetHandleARB;
   extern EC_SENSOR_RENDER_DECL PFNGLGETINFOLOGARBPROC           glGetInfoLogARB;
   extern EC_SENSOR_RENDER_DECL PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARB;
   extern EC_SENSOR_RENDER_DECL PFNGLGETUNIFORMLOCATIONARBPROC   glGetUniformLocationARB;
   extern EC_SENSOR_RENDER_DECL PFNGLLINKPROGRAMARBPROC          glLinkProgramARB;
   extern EC_SENSOR_RENDER_DECL PFNGLSHADERSOURCEARBPROC         glShaderSourceARB;
   extern EC_SENSOR_RENDER_DECL PFNGLUSEPROGRAMOBJECTARBPROC     glUseProgramObjectARB;
   extern EC_SENSOR_RENDER_DECL PFNGLUNIFORM1IARBPROC            glUniform1iARB;
   extern EC_SENSOR_RENDER_DECL PFNGLUNIFORM2IARBPROC            glUniform2iARB;
   extern EC_SENSOR_RENDER_DECL PFNGLUNIFORM1FARBPROC            glUniform1fARB;
   extern EC_SENSOR_RENDER_DECL PFNGLUNIFORM1FVARBPROC           glUniform1fvARB;
   extern EC_SENSOR_RENDER_DECL PFNGLUNIFORM2FARBPROC            glUniform2fARB;
   extern EC_SENSOR_RENDER_DECL PFNGLUNIFORM2FVARBPROC           glUniform2fvARB;
   extern EC_SENSOR_RENDER_DECL PFNGLUNIFORM3FARBPROC            glUniform3fARB;
   extern EC_SENSOR_RENDER_DECL PFNGLVALIDATEPROGRAMARBPROC      glValidateProgramARB;

   /// GL_ARB_occlusion_query
   extern EC_SENSOR_RENDER_DECL PFNGLGENQUERIESARBPROC        glGenQueriesARB;
   extern EC_SENSOR_RENDER_DECL PFNGLBEGINQUERYARBPROC        glBeginQueryARB;
   extern EC_SENSOR_RENDER_DECL PFNGLENDQUERYARBPROC          glEndQueryARB;
   extern EC_SENSOR_RENDER_DECL PFNGLGETQUERYOBJECTIVARBPROC  glGetQueryObjectivARB;
   extern EC_SENSOR_RENDER_DECL PFNGLGETQUERYOBJECTUIVARBPROC glGetQueryObjectuivARB;

// If the default gl.h header is used, then OSG tries to force support for
// certain features - namely VBO and FBO.  For those cases OSG will provide
// the extension support for us.
#  ifndef OSG_GL
   // GL_ARB_vertex_buffer_object
   // Fastest way to download vertex data to GPU.
   extern EC_SENSOR_RENDER_DECL PFNGLBINDBUFFERARBPROC           glBindBufferARB;
   extern EC_SENSOR_RENDER_DECL PFNGLDELETEBUFFERSARBPROC        glDeleteBuffersARB;
   extern EC_SENSOR_RENDER_DECL PFNGLGENBUFFERSARBPROC           glGenBuffersARB;
   extern EC_SENSOR_RENDER_DECL PFNGLISBUFFERARBPROC             glIsBufferARB;
   extern EC_SENSOR_RENDER_DECL PFNGLBUFFERDATAARBPROC           glBufferDataARB;
   extern EC_SENSOR_RENDER_DECL PFNGLMAPBUFFERARBPROC            glMapBufferARB;
   extern EC_SENSOR_RENDER_DECL PFNGLUNMAPBUFFERARBPROC          glUnmapBufferARB;
   extern EC_SENSOR_RENDER_DECL PFNGLGETBUFFERPARAMETERIVARBPROC glGetBufferParameterivARB;
   extern EC_SENSOR_RENDER_DECL PFNGLGETBUFFERPOINTERVARBPROC    glGetBufferPointervARB;

   // GL_EXT_framebuffer_object
   // New and improved way to render to a non-displayable buffer.
   extern EC_SENSOR_RENDER_DECL PFNGLBINDFRAMEBUFFEREXTPROC         glBindFramebufferEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLBINDRENDERBUFFEREXTPROC        glBindRenderbufferEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC  glCheckFramebufferStatusEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLDELETEFRAMEBUFFERSEXTPROC      glDeleteFramebuffersEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLDELETERENDERBUFFERSEXTPROC     glDeleteRenderbuffersEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC glFramebufferRenderbufferEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLFRAMEBUFFERTEXTURE2DEXTPROC    glFramebufferTexture2DEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLGENFRAMEBUFFERSEXTPROC         glGenFramebuffersEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLGENRENDERBUFFERSEXTPROC        glGenRenderbuffersEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLISFRAMEBUFFEREXTPROC           glIsFramebufferEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLISRENDERBUFFEREXTPROC          glIsRenderbufferEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLRENDERBUFFERSTORAGEEXTPROC     glRenderbufferStorageEXT;
#  endif

   /// GL_EXT_geometry_shader4
   /// Geometry shader support.
   extern EC_SENSOR_RENDER_DECL PFNGLPROGRAMPARAMETERIEXTPROC glProgramParameteriEXT;

   /// GL_EXT_texture_integer
   /// Support for internal integer representation of textures.
   extern EC_SENSOR_RENDER_DECL PFNGLCLEARCOLORIUIEXTPROC       glClearColorIuiEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLTEXPARAMETERIIVEXTPROC     glTexParameterIivEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLTEXPARAMETERIUIVEXTPROC    glTexParameterIuivEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLGETTEXPARAMETERIIVEXTPROC  glGetTexParameterIivEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLGETTEXPARAMETERIUIVEXTPROC glGetTexParameterIuivEXT;

   /// GL_EXT_gpu_shader4
   /// Support for newer shading features in shader programs.
   extern EC_SENSOR_RENDER_DECL PFNGLUNIFORM1UIEXTPROC    glUniform1uiEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLUNIFORM2UIEXTPROC    glUniform2uiEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLUNIFORM3UIEXTPROC    glUniform3uiEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLUNIFORM4UIEXTPROC    glUniform4uiEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLUNIFORM1UIVEXTPROC   glUniform1uivEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLUNIFORM2UIVEXTPROC   glUniform2uivEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLUNIFORM3UIVEXTPROC   glUniform3uivEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLUNIFORM4UIVEXTPROC   glUniform4uivEXT;
   extern EC_SENSOR_RENDER_DECL PFNGLGETUNIFORMUIVEXTPROC glGetUniformuivEXT;
#else
// Workaround on OSX for NVIDIA float constants.
#  ifndef GL_NV_float_buffer
#    define GL_FLOAT_R_NV           0x8880
#    define GL_FLOAT_RG_NV          0x8881
#    define GL_FLOAT_RGB_NV         0x8882
#    define GL_FLOAT_RGBA_NV        0x8883
#    define GL_FLOAT_R16_NV         0x8884
#    define GL_FLOAT_R32_NV         0x8885
#    define GL_FLOAT_RG16_NV        0x8886
#    define GL_FLOAT_RG32_NV        0x8887
#    define GL_FLOAT_RGB16_NV       0x8888
#    define GL_FLOAT_RGB32_NV       0x8889
#    define GL_FLOAT_RGBA16_NV      0x888A
#    define GL_FLOAT_RGBA32_NV      0x888B
#  endif
#endif

   // Platform-specific extensions.
#  if defined(WIN32)
   // WGL_ARB_make_current_read
   // Set one context for reading and another for drawing.
   //extern EC_SENSOR_RENDER_DECL PFNWGLMAKECONTEXTCURRENTARBPROC wglMakeContextCurrentARB;

   // WGL_ARB_pbuffer
   // Off-screen pixel buffer capability.
   extern EC_SENSOR_RENDER_DECL PFNWGLCREATEPBUFFERARBPROC    wglCreatePbufferARB;
   extern EC_SENSOR_RENDER_DECL PFNWGLDESTROYPBUFFERARBPROC   wglDestroyPbufferARB;
   extern EC_SENSOR_RENDER_DECL PFNWGLGETPBUFFERDCARBPROC     wglGetPbufferDCARB;
   extern EC_SENSOR_RENDER_DECL PFNWGLQUERYPBUFFERARBPROC     wglQueryPbufferARB;
   extern EC_SENSOR_RENDER_DECL PFNWGLRELEASEPBUFFERDCARBPROC wglReleasePbufferDCARB;

   // WGL_ARB_pixel_format
   // Greater flexibility when requesting formats.
   extern EC_SENSOR_RENDER_DECL PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;

   // WGL_EXT_swap_control
   // Gives the ability to turn vertical sync on or off.
   extern EC_SENSOR_RENDER_DECL PFNWGLSWAPINTERVALEXTPROC glSwapInterval;
#elif defined(__APPLE__)
#  define glSwapInterval(interval)  EcGL::setSwapInterval(interval)
#else // Linux / X11
   extern PFNGLXSWAPINTERVALSGIPROC glSwapInterval;
#  endif


// Print OpenGL errors as they are generated, but only in the debug version.
#ifdef _DEBUG
#  define printOpenGLError() EcGL::printGLError(__FILE__, __LINE__)
#else
#  define printOpenGLError() EcTrue
#endif

#endif // ecGL_H_
