#ifndef ecSystemCfgLoader_H_
#define ecSystemCfgLoader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemCfgLoader.h
/// @class EcSystemCfgLoader
/// @brief Holds a tool for loading system from NASA .cfg file types.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseSystemLoader.h"
#include "ecVecPhysicalExtentConverter.h"

class EcCoordinateSystemTransformation;
class EcManipulatorSelfCollisionLinkMap;

/// Holds a tool for loading systems from NASA .cfg file types.
class EC_FOUNDATION_CONVERTSYSTEM_DECL EcSystemCfgLoader : public EcBaseSystemLoader
{
public:
   /// default constructor
   EcSystemCfgLoader
      (
      );

   /// destructor
   virtual ~EcSystemCfgLoader
      (
      );

   /// copy constructor
   EcSystemCfgLoader
      (
      const EcSystemCfgLoader& orig
      );

   /// assignment operator
   EcSystemCfgLoader& operator=
      (
      const EcSystemCfgLoader& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemCfgLoader& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// gets the vec physical extent converter
   virtual const EcVecPhysicalExtentConverter& vecPhysicalExtentConverter
      (
      ) const;

   /// sets the vec physical extent converter
   virtual void setVecPhysicalExtentConverter
      (
      const EcVecPhysicalExtentConverter& vecPhysicalExtentConverter
      );

   /// gets the load-right-arm flag
   virtual EcBoolean loadRightArm
      (
      ) const;

   /// sets the load-right-arm flag
   virtual void setLoadRightArm
      (
      EcBoolean loadRightArm
      );

   /// gets the load-right-arm flag
   virtual EcBoolean loadLeftArm
      (
      ) const;

   /// sets the load-right-arm flag
   virtual void setLoadLeftArm
      (
      EcBoolean loadLeftArm
      );

   /// gets the load-head flag
   virtual EcBoolean loadHead
      (
      ) const;

   /// sets the load-head flag
   virtual void setLoadHead
      (
      EcBoolean loadHead
      );

   /// gets the load-right-fingers flag
   virtual EcBoolean loadRightFingers
      (
      ) const;

   /// sets the load-right-fingers flag
   virtual void setLoadRightFingers
      (
      EcBoolean loadRightFingers
      );

   /// gets the load-left-fingers flag
   virtual EcBoolean loadLeftFingers
      (
      ) const;

   /// sets the load-left-fingers flag
   virtual void setLoadLeftFingers
      (
      EcBoolean loadLeftFingers
      );

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

    /// load a file and build a visualizable stated system
   /**
       \param visStatedSystem stated system
       \param filename filename for building stated system
       \retval error status
   */
   virtual EcBoolean loadVisualizableStatedSystemFromFile
      (
      EcVisualizableStatedSystem&  visStatedSystem,
      const EcString& filename
      ) const;

   /// build a self collision link map for robonaut
   virtual EcBoolean buildSelfCollisionLinkMap
      (
      EcManipulatorSelfCollisionLinkMap& map,
      const EcIndividualManipulator& manip
      )const;

   /// a token unique to this class
   static const EcToken& classToken
      (
      );

   /// get an empty object
   static EcSystemCfgLoader nullObject
      (
      );
   /// gets the load right hand only flag
   virtual EcBoolean loadRightHandOnly
      (
      ) const;

   /// sets the load right Hand Onlt flag
   virtual void setLoadRightHandOnly
      (
      EcBoolean loadRightHandOnly
      );

protected:

   enum {THUMB,INDEX,MIDDLE,RING,PINKY};
   /// load the right-arm links
   virtual EcBoolean loadRightArmLinks
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      std::vector<EcManipulatorLink>& vRightArmLinks
      ) const;

   /// load the left-arm links
   virtual EcBoolean loadLeftArmLinks
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      std::vector<EcManipulatorLink>& vLeftArmLinks
      ) const;

   /// load the head links
   virtual EcBoolean loadHeadLinks
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      std::vector<EcManipulatorLink>& vHeadLinks
      ) const;

   /// load tail links
   virtual EcBoolean loadTailLinks
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      std::vector<EcManipulatorLink>& vTailLinks
      ) const;

   /// load right hand thumb links
   EcBoolean loadRightThumbLinks
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      std::vector<EcManipulatorLink>& vThumbLinks
      ) const;

   /// load right hand index finger links
   EcBoolean loadRightIndexLinks
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      std::vector<EcManipulatorLink>& vIndexLinks
      ) const;

   /// load right hand middle finger links
   EcBoolean loadRightMiddleLinks
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      std::vector<EcManipulatorLink>& vMiddleLinks
      ) const;

   /// load right hand ring finger links
   EcBoolean loadRightRingLinks
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      std::vector<EcManipulatorLink>& vRingLinks
      ) const;

   /// load right hand pinky links
   EcBoolean loadRightPinkyLinks
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      std::vector<EcManipulatorLink>& vPinkyLinks
      ) const;

   /// load left hand thumb links
   EcBoolean loadLeftThumbLinks
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      std::vector<EcManipulatorLink>& vThumbLinks
      ) const;

   /// load left hand index finger links
   EcBoolean loadLeftIndexLinks
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      std::vector<EcManipulatorLink>& vIndexLinks
      ) const;

   /// load left hand middle finger links
   EcBoolean loadLeftMiddleLinks
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      std::vector<EcManipulatorLink>& vMiddleLinks
      ) const;

   /// load left hand ring finger links
   EcBoolean loadLeftRingLinks
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      std::vector<EcManipulatorLink>& vRingLinks
      ) const;

   /// load left hand pinky links
   EcBoolean loadLeftPinkyLinks
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      std::vector<EcManipulatorLink>& vPinkyLinks
      ) const;

   /// connect the fingers of the right hand to the arm
   EcBoolean connectRightFingersToRightArm
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      const std::vector<std::vector<EcManipulatorLink> >& vRightHandLinks,
      std::vector<EcManipulatorLink>& vRightArmLinks
      ) const;

      /// add the right thumb links to the right hand
   EcBoolean addRightThumbLinksToRightHand
      (
      const EcStringVector& strLines,
      const EcString& path,
      const std::vector<EcManipulatorLink>& vRightThumbLinks,
      std::vector<EcManipulatorLink>& vRightArmLinks
      ) const;

   /// add the right index links to the right hand
   EcBoolean addRightIndexLinksToRightHand
      (
      const EcStringVector& strLines,
      const EcString& path,
      const std::vector<EcManipulatorLink>& vRightIndexLinks,
      std::vector<EcManipulatorLink>& vRightArmLinks
      ) const;

   /// add the right middle links to the right hand
   EcBoolean addRightMiddleLinksToRightHand
      (
      const EcStringVector& strLines,
      const EcString& path,
      const std::vector<EcManipulatorLink>& vRightMiddleLinks,
      std::vector<EcManipulatorLink>& vRightArmLinks
      ) const;

   /// add the right ring links to the right hand
   EcBoolean addRightRingLinksToRightHand
      (
      const EcStringVector& strLines,
      const EcString& path,
      const std::vector<EcManipulatorLink>& vRightRingLinks,
      std::vector<EcManipulatorLink>& vRightArmLinks
      ) const;

   /// add the right thumb links to the right hand
   EcBoolean addRightPinkyLinksToRightHand
      (
      const EcStringVector& strLines,
      const EcString& path,
      const std::vector<EcManipulatorLink>& vRightPinkyLinks,
      std::vector<EcManipulatorLink>& vRightArmLinks
      ) const;


   /// connect the fingers of the left hand to the arm
   EcBoolean connectLeftFingersToLeftArm
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      const std::vector<std::vector<EcManipulatorLink> >& vLeftHandLinks,
      std::vector<EcManipulatorLink>& vLeftArmLinks
      ) const;

   /// add the left thumb links to the left hand
   EcBoolean addLeftThumbLinksToLeftHand
      (
      const EcStringVector& strLines,
      const EcString& path,
      const std::vector<EcManipulatorLink>& vLeftThumbLinks,
      std::vector<EcManipulatorLink>& vLeftArmLinks
      ) const;

   /// add the left index links to the left hand
   EcBoolean addLeftIndexLinksToLeftHand
      (
      const EcStringVector& strLines,
      const EcString& path,
      const std::vector<EcManipulatorLink>& vLeftIndexLinks,
      std::vector<EcManipulatorLink>& vLeftArmLinks
      ) const;

   /// add the left middle links to the left hand
   EcBoolean addLeftMiddleLinksToLeftHand
      (
      const EcStringVector& strLines,
      const EcString& path,
      const std::vector<EcManipulatorLink>& vLeftMiddleLinks,
      std::vector<EcManipulatorLink>& vLeftArmLinks
      ) const;

   /// add the left ring links to the left hand
   EcBoolean addLeftRingLinksToLeftHand
      (
      const EcStringVector& strLines,
      const EcString& path,
      const std::vector<EcManipulatorLink>& vLeftRingLinks,
      std::vector<EcManipulatorLink>& vLeftArmLinks
      ) const;

   /// add the left thumb links to the left hand
   EcBoolean addLeftPinkyLinksToLeftHand
      (
      const EcStringVector& strLines,
      const EcString& path,
      const std::vector<EcManipulatorLink>& vLeftPinkyLinks,
      std::vector<EcManipulatorLink>& vLeftArmLinks
      ) const;

   /// load links
   virtual EcBoolean loadLinks
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      const EcString& namePrecursor,
      std::vector<EcManipulatorLink>& vLinks
      ) const;

   /// load a visualizable stated system
   virtual EcBoolean loadVisualizableStatedSystemFromStream
      (
      EcVisualizableStatedSystem&  visStatedSystem,
      const EcString& path,
      std::ifstream& stream
      ) const;

   /// Loads and combines system transformations.
   virtual EcBoolean getSystemPose
      (
      const EcStringVector& strLines,
      const EcU32& currentLocation,
      EcBoolean recurse,
      EcCoordinateSystemTransformation& systemPose
      ) const;

   /// loads a model
   virtual EcBoolean getModelPhysicalExtentAndPose
      (
      const EcStringVector& strLines,
      const EcU32& currentLocation,
      const EcString& path,
      EcBoolean recurse,
      EcPolyPhysicalExtent& physicalExtent,
      EcCoordinateSystemTransformation& modelPose
      ) const;

   /// connect the right-arm links
   virtual EcBoolean connectRightArmToTail
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      const std::vector<EcManipulatorLink>& vRightArmLinks,
      std::vector<EcManipulatorLink>& vTailLinks
      ) const;

   /// connect the left-arm links
   virtual EcBoolean connectLeftArmToTail
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      const std::vector<EcManipulatorLink>& vLeftArmLinks,
      std::vector<EcManipulatorLink>& vTailLinks
      ) const;

   /// connect the head links
   virtual EcBoolean connectHeadToTail
      (
      std::ifstream&  stream,
      const EcStringVector& strLines,
      const EcString& path,
      const std::vector<EcManipulatorLink>& vHeadLinks,
      std::vector<EcManipulatorLink>& vTailLinks
      ) const;

   /// Finds the first location in the string vector containing the token.
   /// Returns true if the token is found, otherwise false.
   virtual EcBoolean findFirstLocationContaining
      (
      const EcStringVector& lines,
      const EcString& token,
      EcU32& location,
      const EcU32 startingLocation=0
      ) const;

   /// Finds the first location in the string vector containing the token.
   /// Must be a whole word.
   /// Returns true if the token is found, otherwise false.
   virtual EcBoolean findFirstLocationContainingWholeWordOnly
      (
      const EcStringVector& lines,
      const EcString& token,
      EcU32& location,
      const EcU32 startingLocation=0
      ) const;


   /// gets the next line containing token from the stream.
   /// Commented lines are ignored.
   virtual EcBoolean getNextLineContaining
      (
      std::istream&   stream,
      EcString&       line,
      const EcString& token
      ) const;

   /// gets the next line containing token from the stream.
   /// the token must be complete and not attached to other text
   /// Commented lines are ignored.
   virtual EcBoolean getNextLineContainingWholeWordOnly
      (
      std::istream&   stream,
      EcString&       line,
      const EcString& token
      ) const;


   /// get the next uncommented (by a #) line
   virtual EcBoolean getNextUncommentedLine
      (
      std::istream&  stream,
      EcString&      buffer
      ) const;

protected:
   EcVecPhysicalExtentConverter m_VecPhysicalExtentConverter;  ///< physical extent converter
   EcXmlBoolean                 m_LoadRightArm;                ///< flag for loading right arm
   EcXmlBoolean                 m_LoadLeftArm;                 ///< flag for loading left arm
   EcXmlBoolean                 m_LoadHead;                    ///< flag for loading head
   EcXmlBoolean                 m_LoadRightFingers;            ///< flag for loading right fingers
   EcXmlBoolean                 m_LoadLeftFingers;             ///< flag for loading left fingers
   EcXmlBoolean                 m_LoadRightHandOnly;           ///< flag for loading right hand only

   // non-XML data
   mutable EcU32 m_LineCount;                                  ///< line count
};

#endif // ecSystemCfgLoader_H_
