#ifndef ec_RenderSerializer_H_
#define ec_RenderSerializer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2010-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderSerializer.h
/// @brief Provides wrapper subclasses that are designed to allow
///        OSG-based rendering classes to be serialized.  This
///        is used when reading and writing osg files to preserve
///        the custom characteristics without burdening the default
///        classes from the additional accessors and mutators that
///        are required for serialization.
///        NOTE: Currently only implemented for EcRenderManipulator
///        and EcRenderLink.
/// @details Ec::RenderLinkSerializer
//
//------------------------------------------------------------------------------
#include "ecRenderManipulator.h"
#include "ecRenderIntraLink.h"

class EcBaseGeneralBoundObject;

namespace Ec
{

/// This class provides the necessary accessors and mutators to properly
/// serialize the EcRenderLink class.
class EC_RENDER_RENDCORE_DECL RenderLinkSerializer : public EcRenderLink
{
public:
   /// Default constructor - used when reading
   RenderLinkSerializer
      (
      );

   /// Copy constructor - used when cloning
   /// @param[in] node   Object to copy from
   /// @param[in] copyop Type of copy to make
   RenderLinkSerializer
      (
      const RenderLinkSerializer& node,
      const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY
      );

   /// Copy constructor - used when writing to transform base object
   /// @param[in] node Object to copy from
   explicit RenderLinkSerializer
      (
      const EcRenderLink& node
      );

   /// Factory constructor - used when reading.
   /// @return osg::Object* Generic base handle to new object
   osg::Object* cloneType() const { return new RenderLinkSerializer; }

   osg::Object* clone
      (
      const osg::CopyOp& copyop
      ) const { return new RenderLinkSerializer(*this,copyop); }

   /// Specify the manipulator index.
   /// @param manIndex Index to manipulator
   void setManIndex
      (
      const EcU32 manIndex
      );

   /// Specify the link index.
   /// @param linkIndex Index to joint in manipulator
   void setLinkIndex
      (
      const EcU32 linkIndex
      );

   /// Used when reading from file.
   /// @param linkKinematics XML string detailing kinematics
   void setLinkKinematics
      (
      const EcString& linkKinematics
      );

   /// Used when serializing to store to file.
   /// @return const EcString& Returns XML string with kinematics
   const EcString& getLinkKinematics
      (
      ) const;

protected:
   /// Temp buffer for serializing EcLinkKinematics
   mutable EcString m_LKString;
};


/// This class provides the necessary accessors and mutators to properly
/// serialize the EcRenderLink class.
class EC_RENDER_RENDCORE_DECL RenderIntraLinkSerializer : public EcRenderIntraLink
{
public:
   /// Default constructor - used when reading
   RenderIntraLinkSerializer
      (
      );

   /// Copy constructor - used when cloning
   /// @param[in] node   Object to copy from
   /// @param[in] copyop Type of copy to make
   RenderIntraLinkSerializer
      (
      const RenderIntraLinkSerializer& node,
      const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY
      );

   /// Copy constructor - used when writing to transform base object
   /// @param[in] node Object to copy from
   explicit RenderIntraLinkSerializer
      (
      const EcRenderIntraLink& node
      );

   /// Factory constructor - used when reading.
   /// @return osg::Object* Generic base handle to new object
   osg::Object* cloneType() const { return new RenderIntraLinkSerializer; }

   osg::Object* clone
      (
      const osg::CopyOp& copyop
      ) const { return new RenderIntraLinkSerializer(*this,copyop); }

   void setGboVector
      (
      const GboVec& gbovec
      );

   const GboVec& getGboVector
      (
      ) const;

   /// Used when reading from file.
   /// @param gboKinematics XML string detailing kinematics
   void setGboKinematics
      (
      const EcString& gboKinematics
      );

   /// Used when serializing to store to file.
   /// @return const EcString& Returns XML string with kinematics
   const EcString& getGboKinematics
      (
      ) const;

protected:
   /// Temp buffer for serializing EcGeneralBoundObjectVector
   mutable EcString m_GboString;
};

/// This class provides the necessary accessors and mutators to properly
/// serialize the EcRenderManipulator class.
class EC_RENDER_RENDCORE_DECL RenderManipulatorSerializer : public EcRenderManipulator
{
public:
   /// Default constructor - used when reading
   RenderManipulatorSerializer
      (
      );

   /// Copy constructor - used when cloning
   /// @param[in] node   Object to copy from
   /// @param[in] copyop Type of copy to make
   RenderManipulatorSerializer
      (
      const RenderManipulatorSerializer& node,
      const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY
      );

   /// Copy constructor - used when writing to transform base object
   /// @param[in] node Object to copy from
   explicit RenderManipulatorSerializer
      (
      const EcRenderManipulator& node
      );

   /// Factory constructor - used when reading.
   /// @return osg::Object* Generic base handle to new object
   osg::Object* cloneType() const { return new RenderManipulatorSerializer; }

   osg::Object* clone
      (
      const osg::CopyOp& copyop
      ) const { return new RenderManipulatorSerializer(*this,copyop); }

   /// Specify the manipulator index.
   /// @param manIndex Index to manipulator
   void setManIndex
      (
      const EcU32 manIndex
      );

   /// Specify the number of child links.
   /// @param numLinks Number of child links for this manipulator
   void setNumLinks
      (
      const EcU32 numLinks
      );
};

} // namespace Ec

#endif // ec_RenderSerializer_H_
