
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

#define L_BASE 0
#define L_COLEMAK (1 << 1)
#define L_COLEMAKMOD (1 << 2)
#define L_MACRO (1 << 3)
#define L_TEMP (1 << 4)
#define L_LEFT (1 << 5)
#define L_RIGHT (1 << 6)
#define L_SETTINGS (1 << 7)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    break;
  case L_COLEMAK:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Colemak");
    break;
  case L_COLEMAKMOD:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: ModMod-DHVJ");
    break;
  case L_MACRO:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: why");
    break;
  case L_TEMP:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Temp");
    break;
  case L_LEFT:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Left");
    break;
  case L_RIGHT:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Right");
    break;
  case L_SETTINGS:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Debug");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "fix this soon. #%ld", layer_state);
  }

  return layer_state_str;
}
