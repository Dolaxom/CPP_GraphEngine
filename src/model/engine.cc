#include "engine.h"
#include "model/utils/save.h"

namespace ge {

Engine::Engine() : render_{map_} {
  Save::LoadMapFromFile("backup.ge", map_);
  graph_.InitAdjancyMatrix(map_, true);
}

Engine::~Engine() {
  Save::SaveMapToFile(map_);
}

} // namespace ge