#include "orderTag.hpp"

namespace pce {

orderTag::orderTag(const pce::Radar& _radar
                 , const pce::RigidObject& _rigobj)
  : radar(_radar)
  , rigobj(_rigobj)
{}

} /* pce */
