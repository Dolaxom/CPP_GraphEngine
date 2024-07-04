#include "model.h"
#include "model/utils/save.h"

namespace ge {

Engine::Engine() : render_{map_} {
  Save::LoadMapFromFile("backup.ge", map_);
}

Engine::~Engine() {
  Save::SaveMapToFile(map_);
}

} // namespace ge