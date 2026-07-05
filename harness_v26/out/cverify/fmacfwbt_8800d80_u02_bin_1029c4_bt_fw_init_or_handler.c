#include <stdint.h>
#define BYTE1(x) ((uint8_t)(((uint32_t)(x) >> 8) & 0xFFu))
#define BYTE2(x) ((uint8_t)(((uint32_t)(x) >> 16) & 0xFFu))
#define BYTE3(x) ((uint8_t)(((uint32_t)(x) >> 24) & 0xFFu))
#define __noreturn
#define _VF 0
#define _CF 0
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

#define off_1029D4 ((uint32_t)0x00173224u)
// bt_fw_init_or_handler @ 0x1029c4, size 16 bytes
// Doc: bt_fw_init_or_handler [bt]: Bluetooth firmware init/handler routine
// bt_fw_init_or_handler [bt]: Bluetooth firmware init/handler routine
uint8_t * bt_fw_init_or_handler(uint8_t *result, uint8_t *a2)
{
  uint8_t *v2; // r3

  v2 = off_1029D4;
  *result = *((uint8_t *)off_1029D4 + 294);
  *a2 = v2[295];
  return result;
}

