#ifndef ecRenderShader_H_
#define ecRenderShader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderShader.h
/// @brief Provides functionality similar to the OpenGL Shading Language
///        in order to test fragment shader algorithms in software.  It
///        supports most vector constructs, except for component swizzling
///        and accessors.
///        Currently provides capability for vec3, ivec3, bvec3 as well
///        as mat4
/// @details namespace EcRenderShader
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>
#include <foundCore/ecTypes.h>
#include <cmath>
#include <algorithm>

// Turn off warnings about implicit casts from bool to int or float.
// These methods are never utilized for bool types.
#ifdef _MSC_VER
# pragma warning(disable:4800)
#endif

/// Provides functionality similar to the OpenGL Shading Language in order to test fragment shader algorithms in software.
namespace EcRenderShader
{

template <typename T>
class vecT3
{
public:
   typedef T value_type;

   // Default constructor
   vecT3
      (
      )
   {
      _v[0] = _v[1] = _v[2] = static_cast<value_type>(0);
   }

   // Conversion from one type to another.  Only supports basic types.
   template <typename VecType>
   vecT3
      (
      const vecT3<VecType>& v
      )
   {
      _v[0] = static_cast<value_type>(v[0]);
      _v[1] = static_cast<value_type>(v[1]);
      _v[2] = static_cast<value_type>(v[2]);
   }

   // Explicit 3 component initialization
   vecT3
      (
      const value_type v0,
      const value_type v1,
      const value_type v2
      )
   {
      _v[0] = v0;
      _v[1] = v1;
      _v[2] = v2;
   }

   // Convenience one component intialization
   vecT3
      (
      const value_type val
      )
   {
      _v[0] = _v[1] = _v[2] = val;
   }

   vecT3& operator=
      (
      const vecT3& rhs
      )
   {
      _v[0] = rhs._v[0];
      _v[1] = rhs._v[1];
      _v[2] = rhs._v[2];
      return *this;
   }

   vecT3& operator+=
      (
      const vecT3& rhs
      )
   {
      _v[0] += rhs._v[0];
      _v[1] += rhs._v[1];
      _v[2] += rhs._v[2];
      return *this;
   }

   const EcBoolean operator==
      (
      const vecT3& rhs
      )
   {
      return(
             (_v[0] == rhs._v[0]) &&
             (_v[1] == rhs._v[1]) &&
             (_v[2] == rhs._v[2])
             );
   }

   const vecT3 operator!
      (
      ) const
   {
      return vecT3(!_v[0], !_v[1], !_v[2]);
   }

   const vecT3 operator+
      (
      const value_type rhs
      ) const
   {
      return vecT3(_v[0]+rhs, _v[1]+rhs, _v[2]+rhs);
   }

   const vecT3 operator+
      (
      const vecT3& rhs
      ) const
   {
      return vecT3(_v[0]+rhs._v[0], _v[1]+rhs._v[1], _v[2]+rhs._v[2]);
   }

   const vecT3 operator-
      (
      const vecT3& rhs
      ) const
   {
      return vecT3(_v[0]-rhs._v[0], _v[1]-rhs._v[1], _v[2]-rhs._v[2]);
   }

   const vecT3 operator/
      (
      const vecT3& rhs
      ) const
   {
      if(rhs._v[0] == 0 || rhs._v[1] == 0 || rhs._v[2] == 0)
      {
         // Division by zero
         return vecT3(0);
      }
      return vecT3(_v[0]/rhs._v[0], _v[1]/rhs._v[1], _v[2]/rhs._v[2]);
   }

   const vecT3 operator*
      (
      const vecT3& rhs
      ) const
   {
      return vecT3(_v[0]*rhs._v[0], _v[1]*rhs._v[1], _v[2]*rhs._v[2]);
   }

   const vecT3 operator*
      (
      const value_type rhs
      ) const
   {
      return vecT3(_v[0]*rhs, _v[1]*rhs, _v[2]*rhs);
   }

   const vecT3<bool> operator>
      (
      const vecT3& rhs
      ) const
   {
      return vecT3<bool>(_v[0]>rhs._v[0], _v[1]>rhs._v[1], _v[2]>rhs._v[2]);
   }

   value_type& operator[]
      (
      int index
      )
   {
      return _v[index];
   }

   value_type operator[]
      (
      int index
      ) const
   {
      return _v[index];
   }

   T* ptr
      (
      )
   {
      return &_v[0];
   }

   size_t sizeOf
      (
      )
   {
      return sizeof(_v);
   }

protected:
   value_type _v[3];
};


typedef vecT3<float> vec3;
typedef vecT3<int> ivec3;
typedef vecT3<bool> bvec3;


template <typename T>
class matT4
{
public:
   typedef T value_type;

   matT4
      (
      )
   {
      reset();
   }

   matT4<T> &operator=
      (
      const matT4<T>& rhs
      )
   {
      for(EcU32 i=0; i<16; ++i)
      {
         _m[i] = rhs[i];
      }
      return *this;
   }

   const vecT3<T> operator*
      (
      const vecT3<T>& rhs
      )
   {
      return vecT3<T>(_m[0]*rhs[0]+_m[1]*rhs[1]+_m[2]*rhs[2],
                      _m[4]*rhs[0]+_m[5]*rhs[1]+_m[6]*rhs[2],
                      _m[8]*rhs[0]+_m[9]*rhs[1]+_m[10]*rhs[2]);
   }

   void transpose
      (
      )
   {
      value_type temp = _m[4];
      _m[4] = _m[1];
      _m[1] = temp;

      temp = _m[8];
      _m[8] = _m[2];
      _m[2] = temp;

      temp = _m[9];
      _m[9] = _m[6];
      _m[6] = temp;
   }

void reset
      (
      )
   {
      for(EcU32 i=0; i<16; ++i)
      {
         _m[i] = static_cast<T>(0);
      }
   }

   void identity
      (
      )
   {
      reset();
      _m[0] = _m[5] = _m[10] = _m[15] = static_cast<T>(1);
   }

   void rotate
      (
      const vec3 &v
      );

   void makeRot
      (
      vec3 &v
      ) const;

   T* data
      (
      )
   {
      return &_m[0];
   }

protected:
   T clampDegrees
      (
      const T &val
      ) const
   {
      if(val < static_cast<T>(0))
      {
         return (val + static_cast<T>(360));
      }
      else if(val >= static_cast<T>(360))
      {
         return (val - static_cast<T>(360));
      }
      return val;
   }

   value_type _m[16];
};


typedef matT4<float> mat4;

// Provides CPU version of 3D texture access including
// tri-linear interpolation or nearest neighbor matching.
class EC_SENSOR_RENDER_DECL Texture3
{
public:
   enum Filter { NEAREST, LINEAR };

   Texture3
      (
      const ivec3 _size,
      const int _values,
      float* _data
      );

   void setFilter
      (
      const Filter filter
      ) { m_Filter = filter; }

   const ivec3 size
      (
      ) const { return m_Size; }

      const vec3& tex3D
      (
      const vec3& texCoord
      ) const;

   float *getData() { return data; }
protected:

   ivec3 m_Size;
   int values;
   float *data;
   Filter m_Filter;
};

#define texture3D(t,v) t->tex3D(v)


/////////////////////////////////////////////////////////////////////////
// Functions:    General functions used in GLSL that operate on vec3
// Description:
/////////////////////////////////////////////////////////////////////////
template <typename T>
bvec3 lessThan(const vecT3<T>& lhs, const vecT3<T>& rhs)
{
   return bvec3(lhs[0]<rhs[0],lhs[1]<rhs[1],lhs[2]<rhs[2]);
}
template <typename T>
bvec3 greaterThan(const vecT3<T>& lhs, const vecT3<T>& rhs)
{
   return bvec3(lhs[0]>rhs[0],lhs[1]>rhs[1],lhs[2]>rhs[2]);
}
template <typename T>
bvec3 greaterThanEqual(const vecT3<T>& lhs, const vecT3<T>& rhs)
{
   return bvec3(lhs[0]>=rhs[0],lhs[1]>=rhs[1],lhs[2]>=rhs[2]);
}
template <typename T>
bvec3 notEqual(const vecT3<T>& lhs, const vecT3<T>& rhs)
{
   return bvec3(lhs[0]!=rhs[0],lhs[1]!=rhs[1],lhs[2]!=rhs[2]);
}
template <typename T>
bvec3 equal(const vecT3<T>& lhs, const vecT3<T>& rhs)
{
   return bvec3(lhs[0]==rhs[0],lhs[1]==rhs[1],lhs[2]==rhs[2]);
}
template <typename T>
T dot(const vecT3<T>& lhs, const vecT3<T>& rhs)
{
   return lhs[0]*rhs[0] + lhs[1]*rhs[1] + lhs[2]*rhs[2];
}

template <typename T>
vecT3<T> min(const vecT3<T>& lhs, const vecT3<T>& rhs)
{
   return vecT3<T>(std::min(lhs[0],rhs[0]), std::min(lhs[1],rhs[1]), std::min(lhs[2],rhs[2]));
}

template <typename T>
T min(const T lhs, const T rhs)
{
   return std::min(lhs,rhs);
}

template <typename T>
T length(const vecT3<T>& rhs)
{
   return std::sqrt(dot(rhs,rhs));
}

template <typename T>
vecT3<T> normalize(const vecT3<T>& rhs)
{
   T mag = length(rhs);
   if(mag == static_cast<T>(0))
   {
      return vecT3<T>(0);
   }
   return vecT3<T>(rhs[0]/mag,rhs[1]/mag,rhs[2]/mag);
}

template <typename T>
vecT3<T> abs(const vecT3<T>& rhs)
{
   return vecT3<T>(std::abs(rhs[0]),std::abs(rhs[1]),std::abs(rhs[2]));
}

template <typename T>
vecT3<T> floor(const vecT3<T>& rhs)
{
   return vecT3<T>(std::floor(rhs[0]),std::floor(rhs[1]),std::floor(rhs[2]));
}

template <typename T>
vecT3<T> ceil(const vecT3<T>& rhs)
{
   return vecT3<T>(std::ceil(rhs[0]),std::ceil(rhs[1]),std::ceil(rhs[2]));
}

template <typename T>
vecT3<T> sign(const vecT3<T>& rhs)
{
   return vecT3<T>(
      static_cast<T>(rhs[0]<static_cast<T>(0)? -1 : rhs[0]>static_cast<T>(0) ? 1 : 0),
      static_cast<T>(rhs[1]<static_cast<T>(0)? -1 : rhs[1]>static_cast<T>(0) ? 1 : 0),
      static_cast<T>(rhs[2]<static_cast<T>(0)? -1 : rhs[2]>static_cast<T>(0) ? 1 : 0)
      );
}

template <typename T>
vecT3<T> exp(const vecT3<T>& rhs)
{
   return vecT3<T>(std::exp(rhs[0]), std::exp(rhs[1]), std::exp(rhs[2]));
}

template <typename T>
vecT3<T> log(const vecT3<T>& rhs)
{
   return vecT3<T>(std::log(rhs[0]), std::log(rhs[1]), std::log(rhs[2]));
}

bool any(const bvec3& rhs);
bool all(const bvec3& rhs);

template <typename T>
std::ostream &
operator<<
   (
   std::ostream &s,
   const vecT3<T> &v
   )
{
   s << v[0] << "," << v[1] << "," << v[2];
   return s;
}

}; // namespace EcRenderShader

#endif // ecRenderShader_H_
