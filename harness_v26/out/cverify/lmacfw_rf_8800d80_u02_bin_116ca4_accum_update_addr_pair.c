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

#define off_116CD0 ((uint32_t)0x00185cd0u)
#define off_116CCC ((uint32_t)0x001581c0u)
// accum_update_addr_pair @ 0x116ca4, size 38 bytes
// Doc: accum_update_addr_pair [util]: Add two 32-bit address pairs and store accumulator
// accum_update_addr_pair [util]: Add two 32-bit address pairs and store accumulator
int accum_update_addr_pair()
{
  uint32_t *v0; // r3
  uint64_t v1; // kr00_8
  uint64_t v2; // kr08_8

  v0 = off_116CD0;
  v1 = *((uint64_t *)off_116CCC + 17);
  v2 = *((uint64_t *)off_116CCC + 18);
  *((uint32_t *)off_116CD0 + 1) = HIDWORD(v1) + v1;
  v0[2] = v1;
  v0[3] = v2;
  v0[4] = HIDWORD(v2) + v2;
  *v0 = v1;
  v0[5] = v2;
  return rf_temp_sensor_read();
}

