#ifndef ecPose_H_
#define ecPose_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecPose.h
/// @class EcPose
/// @brief This class is a set of poses
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <foundCommon/ecCoordSysXForm.h>


// forward declarations
class EcIndividualManipulator;
class EcManipulatorActivePositionState;
class EcStatedSystem;

/**
 * @brief The EcPose class
 * EcPose is used to specified a 3D location (position and orientation) in space.
 * It can be either relative or absolute (relative to system). If it's relative,
 * it can be relative to a primary frame of a named frame of a link.
 */
class EC_ACTIN_MANIPULATION_DECL EcPose : public EcXmlCompoundType
{
public:
   /// default constructor
   EcPose
      (
      );

   /// destructor
   virtual ~EcPose
      (
      );

   /// copy constructor
   EcPose
      (
      const EcPose& orig
      );

   /// assignment operator
   EcPose& operator=
      (
      const EcPose& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPose& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// the token
   virtual const EcToken& token
      (
      ) const;

   /// get the offset of the pose
   virtual const EcCoordinateSystemTransformation& offset
      (
      ) const;

   /// set the offset
   virtual void setOffset
      (
      const EcCoordinateSystemTransformation& value
      );

   /// return whether the pose is relative
   virtual EcBoolean isRelative
      (
      ) const;

   /// set whether the pose is relative
   virtual void setIsRelative
      (
      EcBoolean value
      );

   /// get the index of the manipulator to which the pose is relative
   virtual EcU32 manipulatorIndex
      (
      ) const;

   /// set the index of the manipulator to which the pose is relative
   virtual void setManipulatorIndex
      (
      EcU32 value
      );

   /// get the index of the link to which the pose is relative
   virtual EcU32 linkIndex
      (
      ) const;

   /// set the index of the link to which the pose is relative
   virtual void setLinkIndex
      (
      EcU32 value
      );

   /// get the named frame to which the pose is relative. If empty or invalid, the pose
   /// is assumed to be relative to the primary frame of the link. The named frame is
   /// invalid if the link doesn't have the frame with this name.
   virtual const EcString& namedFrame
      (
      ) const;

   /// set the named frame
   virtual void setNamedFrame
      (
      const EcString& value
      );

   /// calculate the offset in system coordinates. For non-relative pose, this is identical to offset().
   /// \param[in] manip The manipulator to which the pose is relative. This could be different than the one
   ///   provided by manipulatorIndex.
   /// \param[in,out] activePosState The active position state containing the current state of the manipulator.
   /// \param[out] offset The calculated offset in system.
   /// \return True if successful (i.e. link index is valid) or false otherwise
   virtual EcBoolean offsetInSystem
      (
      const EcIndividualManipulator& manip,
      EcManipulatorActivePositionState& activePosState,
      EcCoordinateSystemTransformation& offset
      ) const;

   /// calculate the offset in system coordinates. For non-relative pose, this is identical to offset().
   /// \param[in] statedSystem The stated system. This method will use the manipulator index of the pose and also
   ///   the position state in the stated system in the calculations.
   /// \param[out] offset The calculated offset in system.
   /// \return True if successful (i.e. manipulator and link indices valid) or false otherwise
   virtual EcBoolean offsetInSystem
      (
      const EcStatedSystem& statedSystem,
      EcCoordinateSystemTransformation& offset
      ) const;

   /// calculate the relative offset from the offset in the system coordinates and set it as the offset for the pose.
   /// \param[in] statedSystem The stated system. This method will use the manipulator index of the pose and also
   ///   the position state in the stated system in the calculations.
   /// \param[in] offset The offset in system.
   /// \return True if successful (i.e. manipulator and link indices valid) or false otherwise
   virtual EcBoolean setOffsetFromSystem
      (
      const EcStatedSystem& statedSystem,
      const EcCoordinateSystemTransformation& offset
      );

protected:
   EcCoordinateSystemTransformation m_Offset;      ///< The offset
   EcXmlBoolean      m_IsRelative;                 ///< Flag indicating if the pose is relative
   EcXmlU32          m_ManipIndex;                 ///< The manipulator index
   EcXmlU32          m_LinkIndex;                  ///< The link index
   EcXmlString       m_NamedFrame;                 ///< The named frame
};

#endif // ecPose_H_
