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

extern uint32_t off_11ED9C;
extern uint32_t dword_11EDA0;

// timer_get_counter @ 0x11ed58, size 68 bytes
// Doc: sub_121ED58 [mmio]: MMIO helper reading from 0x403410b0/0x403410b4 peripheral registers
// sub_121ED58 [mmio]: MMIO helper reading from 0x403410b0/0x403410b4 peripheral registers
uint64_t *timer_get_counter()
{
  uint64_t *result; // r0
  uint64_t v1; // [sp+4h] [bp-20h] BYREF
  int v2; // [sp+Ch] [bp-18h]
  int v3; // [sp+10h] [bp-14h]
  int v4; // [sp+14h] [bp-10h]
  int v5; // [sp+18h] [bp-Ch]

  v2 = *(uint32_t *)off_11ED9C;
  v3 = *(uint32_t *)dword_11EDA0;
  v4 = *(uint32_t *)(dword_11EDA0 + 8 + 0xFFFFFFFC);
  v5 = *(uint32_t *)(dword_11EDA0 + 8);
  result = rf_call_handler(&v1, 0);
  if ( (v2 & 0xF) == 2 )
    return (uint64_t *)check_chip_mode(&v1);
  return result;
}

