#include "objects/visibleTriggerZone.h"

template <typename T>
VisibleTriggerZone<T>::VisibleTriggerZone(int width, int height, int x, int y, bool single, vector<T *> observedEntities, function<void(T *ent)> func)
: Object(width, height, x, y), TriggerZone<T>(width, height, x, y, single, observedEntities, func) {}

template <typename T>
VisibleTriggerZone<T>::VisibleTriggerZone(int width, int height, int x, int y, Color color, bool single, vector<T *> observedEntities, function<void(T *ent)> func)
: Object(width, height, x, y, color), TriggerZone(width, height, x, y, single, observedEntities, func) {}

template <typename T>
VisibleTriggerZone<T>::VisibleTriggerZone(int width, int height, int x, int y, Color color, Color border, int borderThickness, bool single, vector<T *> observedEntities, function<void(T *ent)> func)
    : Object(width, height, x, y, color, border, borderThickness), TriggerZone(width, height, x, y, single, observedEntities, func) {}

