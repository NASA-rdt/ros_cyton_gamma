#ifndef ecRenderScalarBarHud_H_
#define ecRenderScalarBarHud_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderScalarBarHud.h
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>
#include <foundCore/ecTypes.h>
#include <foundCore/ecVector.h>

#include <osg/ref_ptr>
#include <osg/Array>
#include <osgSim/ColorRange>
#include <osgSim/ScalarBar>

// Forward declarations.
namespace osg
{
   class Group;
   class MatrixTransform;
   class Node;
}

class EC_RENDER_RENDCORE_DECL EcRenderScalarBarHud : public osg::Group
{
public:
    /// constructor
    EcRenderScalarBarHud
    (
    );

    /// destructor
    virtual ~EcRenderScalarBarHud
    (
    );

    /// initialization method
    /// \param[in] minScalarValue minimum scalar value for the color range
    /// \param[in] maxScalarValue maximum scalar value for the color range
    virtual void init
       (
            EcReal minScalarValue = 0.0,
            EcReal maxScalarValue = 1.0
       );

    /// sets the visibility of the scalar bar
    /// \param[in] isVisible true to make the scalar bar visible 
    ///
    virtual void setScalarBarVisibilityEnabled
       (
       EcBoolean isVisible
       );

    /// sets the visibility of the scalar bar
    /// \return isVisible true is the scalar bar is currently visible 
    ///
    virtual EcBoolean scalarBarVisibilityEnabled
       (
       ) const;

    virtual void setMinScalarValue
       (
       EcReal min
       );

    virtual EcReal minScalarValue
       (
       ) const;

    virtual void setMaxScalarValue
       (
       EcReal max
       );

    virtual EcReal maxScalarValue
       (
       ) const;

    virtual void setColorRange
    (
      osgSim::ColorRange* pColorRange
    );

    virtual osgSim::ColorRange* colorRange
    (
    ) const;


    static EcRenderScalarBarHud* createScalarBarHud();

    static osgSim::ColorRange* createColorRange
    (
            EcReal minScalar,
            EcReal maxScalar
    );

protected:
    osgSim::ScalarBar*           m_pScalarBar;      ///< pointer to scalar bar osg object
    osgSim::ColorRange*          m_pColorRange;     ///< color range that maps scalars to colors
    EcReal                       m_MinScalarValue;  ///< minimum scalar value for the color range
    EcReal                       m_MaxScalarValue;  ///< maximum scalar value for the color range
};

#endif // ecRenderScalarBarHud_H_
