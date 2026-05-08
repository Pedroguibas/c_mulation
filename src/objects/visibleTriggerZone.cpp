#include "objects/visibleTriggerZone.h"
#include "objects/entity.h"

VisibleTriggerZone::VisibleTriggerZone(int width, int height, int x, int y, bool single, vector<Entity *> observedEntities, function<void()> func)
    : Object(width, height, x, y), TriggerZone(width, height, x, y, single, observedEntities, func) {}

VisibleTriggerZone::VisibleTriggerZone(int width, int height, int x, int y, Color color, bool single, vector<Entity *> observedEntities, function<void()> func)
    : Object(width, height, x, y, color), TriggerZone(width, height, x, y, single, observedEntities, func) {}

VisibleTriggerZone::VisibleTriggerZone(int width, int height, int x, int y, Color color, Color border, int borderThickness, bool single, vector<Entity *> observedEntities, function<void()> func)
    : Object(width, height, x, y, color, border, borderThickness), TriggerZone(width, height, x, y, single, observedEntities, func) {}

