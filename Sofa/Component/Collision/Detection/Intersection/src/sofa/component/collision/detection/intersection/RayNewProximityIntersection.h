/******************************************************************************
*                 SOFA, Simulation Open-Framework Architecture                *
*                    (c) 2006 INRIA, USTL, UJF, CNRS, MGH                     *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this program. If not, see <http://www.gnu.org/licenses/>.        *
*******************************************************************************
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#pragma once
#include <sofa/component/collision/detection/intersection/config.h>

#include <sofa/component/collision/detection/intersection/NewProximityIntersection.h>
#include <sofa/component/collision/geometry/SphereModel.h>
#include <sofa/component/collision/geometry/TriangleModel.h>
#include <sofa/component/collision/geometry/LineModel.h>
#include <sofa/component/collision/geometry/PointModel.h>
#include <sofa/component/collision/geometry/CubeModel.h>
#include <sofa/component/collision/geometry/RayModel.h>

namespace sofa::component::collision::detection::intersection
{

class SOFA_COMPONENT_COLLISION_DETECTION_INTERSECTION_API RayNewProximityIntersection : public core::collision::BaseIntersector
{
    typedef NewProximityIntersection::OutputVector OutputVector;

public:
    RayNewProximityIntersection(NewProximityIntersection* intersection, bool addSelf=true);

    bool testIntersection(collision::geometry::Ray & t1, collision::geometry::Triangle& t2, const core::collision::Intersection* currentIntersection);
    int computeIntersection(collision::geometry::Ray& t1, collision::geometry::Triangle& t2, OutputVector*, const core::collision::Intersection* currentIntersection);

    // why rigidsphere has a different collision detection compared to RayDiscreteIntersection?
    bool testIntersection(collision::geometry::Ray& rRay, collision::geometry::RigidSphere& rSphere, const core::collision::Intersection* currentIntersection);
    int computeIntersection(collision::geometry::Ray& rRay, collision::geometry::RigidSphere& rSphere, OutputVector*, const core::collision::Intersection* currentIntersection);

    SOFA_ATTRIBUTE_DISABLED__COLLISION_DETECTION_INTERSECTION_AS_PARAMETER()
    bool testIntersection(collision::geometry::Ray& t1, collision::geometry::Triangle& t2) = delete;
    SOFA_ATTRIBUTE_DISABLED__COLLISION_DETECTION_INTERSECTION_AS_PARAMETER()
    int computeIntersection(collision::geometry::Ray& t1, collision::geometry::Triangle& t2, OutputVector*) = delete;
    SOFA_ATTRIBUTE_DISABLED__COLLISION_DETECTION_INTERSECTION_AS_PARAMETER()
    bool testIntersection(collision::geometry::Ray& rRay, collision::geometry::RigidSphere& rSphere) = delete;
    SOFA_ATTRIBUTE_DISABLED__COLLISION_DETECTION_INTERSECTION_AS_PARAMETER()
    int computeIntersection(collision::geometry::Ray& rRay, collision::geometry::RigidSphere& rSphere, OutputVector*) = delete;
};

} //namespace sofa::component::collision::detection::intersection
