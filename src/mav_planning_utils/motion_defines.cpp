/*
* Copyright (c) 2015, Markus Achtelik, ASL, ETH Zurich, Switzerland
* You can contact the author at <markus dot achtelik at mavt dot ethz dot ch>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include <mav_planning_utils/motion_defines.h>

namespace mav_planning_utils {

std::string positionDerivativeToString(int derivative) {
  if (derivative >= derivative_order::POSITION &&
      derivative <= derivative_order::SNAP) {
    static constexpr const char* text[] = {"position", "velocity",
                                           "acceleration", "jerk", "snap"};
    return std::string(text[derivative]);
  } else
    return std::string("invalid");
}

int positionDerivativeToInt(const std::string& string) {
  using namespace derivative_order;
  if (string == "position")
    return POSITION;
  else if (string == "velocity")
    return VELOCITY;
  else if (string == "acceleration")
    return ACCELERATION;
  else if (string == "jerk")
    return JERK;
  else if (string == "snap")
    return SNAP;
  else
    return INVALID;
}

std::string orintationDerivativeToString(int derivative) {
  if (derivative >= derivative_order::ORIENTATION &&
      derivative <= derivative_order::ANGULAR_ACCELERATION) {
    static constexpr const char* text[] = {"orientation", "angular_velocity",
                                           "angular_acceleration"};
    return std::string(text[derivative]);
  } else
    return std::string("invalid");
}

int orientationDerivativeToInt(const std::string& string) {
  using namespace derivative_order;
  if (string == "orientation")
    return ORIENTATION;
  else if (string == "angular_velocity")
    return ANGULAR_VELOCITY;
  else if (string == "angular_acceleration")
    return ANGULAR_ACCELERATION;
  else
    return INVALID;
}

}  // namespace mav_planning_utils
