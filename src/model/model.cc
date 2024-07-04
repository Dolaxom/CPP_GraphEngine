#include "model.h"
#include "model/utils/save.h"

namespace ge {

Engine::Engine() : render_{map_} {
  map_.AddPoint(-1.2, 0);   // 0
  map_.AddPoint(-0.5, 1);
  map_.AddPoint(0.5, 1);
  map_.AddPoint(1.2, 0);    // 3
  map_.AddPoint(0.5, -1);
  map_.AddPoint(-0.5, -1);  // 5

  map_.AddPoint(-0.9, 1.5); // 6
  map_.AddPoint(-1.2, 1.6);
  map_.AddPoint(-0.8, 1.8);

  map_.AddPoint(0.9, 1.5); // 9
  map_.AddPoint(1.2, 1.6);
  map_.AddPoint(0.8, 1.8);

  map_.AddPoint(0.9, -1.5); // 12
  map_.AddPoint(1.2, -1.6);
  map_.AddPoint(0.8, -1.8);

  map_.AddPoint(-0.9, -1.5); // 15
  map_.AddPoint(-1.2, -1.6);
  map_.AddPoint(-0.8, -1.8);

  //

  map_.AddRelation(0, 1);
  map_.AddRelation(1, 2);
  map_.AddRelation(2, 3);
  map_.AddRelation(3, 4);
  map_.AddRelation(4, 5);
  map_.AddRelation(5, 0);

  map_.AddRelation(1, 6);
  map_.AddRelation(6, 7);
  map_.AddRelation(6, 8);

  map_.AddRelation(2, 9);
  map_.AddRelation(9, 10);
  map_.AddRelation(9, 11);

  map_.AddRelation(4, 12);
  map_.AddRelation(12, 13);
  map_.AddRelation(12, 14);
  
  map_.AddRelation(5, 15);
  map_.AddRelation(15, 17);
  map_.AddRelation(15, 16);
}

Engine::~Engine() {
  Save::SaveMapToFile(map_);
}

} // namespace ge