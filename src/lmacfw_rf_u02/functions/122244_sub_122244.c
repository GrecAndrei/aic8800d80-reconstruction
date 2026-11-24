#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))

// rf_set_frequency_1 @ 0x122244, size 116 bytes
int rf_set_frequency_1()
{
  float v0; // r0
  float v1; // r0
  float v2; // r0
  float v3; // r0
  float v4; // r0

  v0 = sdio_core_config_1();
  dispatch_event_handler_1("AVDD18 : %d mV\n", (unsigned int)v0);
  v1 = sdio_core_config_2();
  dispatch_event_handler_1("AVDD13 : %d mV\n", (unsigned int)v1);
  v2 = sdio_core_config_0();
  dispatch_event_handler_1("VBAT   : %d mV\n", (unsigned int)v2);
  v3 = sdio_core_config_3();
  dispatch_event_handler_1("VRTC0  : %d mV\n", (unsigned int)v3);
  v4 = sdio_core_init();
  dispatch_event_handler_1("VCORE  : %d mV\n", (unsigned int)v4);
  return 0;
}
