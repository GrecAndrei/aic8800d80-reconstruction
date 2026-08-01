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

extern uint32_t off_12086C;
extern uint32_t off_120870;
extern uint32_t off_120874;
extern uint32_t off_120878;
extern uint32_t off_12087C;

// wait_rf_calibration @ 0x1207e0, size 138 bytes
int wait_rf_calibration()
{
  int result; // r0
  uint32_t *v1; // r1
  uint16_t *v2; // r3
  unsigned int v3; // r2
  int16_t v4; // r2
  uint32_t *v5; // r1
  int16_t v6; // r2
  uint32_t *v7; // r1
  int16_t v8; // r2

  if ( (uint16_t)(*(uint32_t *)off_12086C >> 12) && (uint16_t)(*(uint32_t *)off_12086C >> 12) <= 0x96u )
    result = (uint16_t)(*(uint32_t *)off_12086C >> 12);
  else
    result = 150;
  v1 = off_120870;
  v2 = off_120874;
  v3 = *(uint32_t *)off_120870;
  *((uint16_t *)off_120874 + 4) = result;
  if ( (uint16_t)(v3 >> 12) && (uint16_t)(*v1 >> 12) <= 0x96u )
    v4 = *v1 >> 12;
  else
    v4 = 150;
  v5 = off_120878;
  v2[5] = v4;
  if ( (uint16_t)(*v5 >> 12) && (uint16_t)(*v5 >> 12) <= 0x96u )
    v6 = *v5 >> 12;
  else
    v6 = 150;
  v7 = off_12087C;
  v2[6] = v6;
  if ( (uint16_t)(*v7 >> 12) && (uint16_t)(*v7 >> 12) <= 0x96u )
  {
    v8 = *v7 >> 12;
    v2[7] = v8;
    v2[8] = v8;
  }
  else
  {
    v2[7] = 150;
    v2[8] = 150;
  }
  return result;
}

