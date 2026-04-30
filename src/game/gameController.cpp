#include "game/gameController.h"

GameController::GameController(vector<Object*> &objects, vector<HitboxObject*> &hitboxObjects, vector<Entity*> &entities) 
: objects(objects), hitboxObjects(hitboxObjects), entities(entities) {}
void GameController::update() {
  for (int i=0; i<entities.size(); i++) {
    entities[i]->update();
  }
}
void GameController::testCollisions() {
  for (int i=0; i<entities.size(); i++) {
    for (int j=0; j<hitboxObjects.size(); j++) {
      if (entities[i] == hitboxObjects[j]) continue;
      entities[i]->collide(*hitboxObjects[j]);
    }
  }
}