#pragma once

#ifndef TRIGGER_ZONE_BASE
#define TRIGGER_ZONE_BASE

class TriggerZoneBase {
public:
  virtual ~TriggerZoneBase() = default;

  virtual void checkTrigger() = 0;
};

#endif