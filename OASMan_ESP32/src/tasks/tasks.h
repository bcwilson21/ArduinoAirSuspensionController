#ifndef tasks_h
#define tasks_h

#include <Arduino.h>

#include <user_defines.h>
#include "components/screen.h"
#if USE_BLE == false
#include "bluetooth/bt.h"
#endif
#include "bluetooth/ble.h"
#include "ota/ota.h"

#if ENABLE_PS3_CONTROLLER_SUPPORT
#include "bluetooth/ps3_controller.h"
#endif

void setup_tasks();

#endif