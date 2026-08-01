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

extern uint32_t off_11F118;
extern uint32_t dword_11F11C;

// timer_timestamp_get @ 0x11f0d4, size 68 bytes
// Doc: timer_timestamp_get [mmio]: Read paired MMIO registers at 0x403410b0/0x403410b4
// timer_timestamp_get [mmio]: Read paired MMIO registers at 0x403410b0/0x403410b4
uint64_t *timer_timestamp_get()
{
  uint64_t *result; // r0
  uint64_t v1; // [sp+4h] [bp-20h] BYREF
  int v2; // [sp+Ch] [bp-18h]
  int v3; // [sp+10h] [bp-14h]
  int v4; // [sp+14h] [bp-10h]
  int v5; // [sp+18h] [bp-Ch]

  v2 = *(uint32_t *)off_11F118;
  v3 = *(uint32_t *)dword_11F11C;
  v4 = *(uint32_t *)(dword_11F11C + 8 + 0xFFFFFFFC);
  v5 = *(uint32_t *)(dword_11F11C + 8);
  result = timer_count_read(&v1, 0);
  if ( (v2 & 0xF) == 2 )
    return (uint64_t *)dispatch_if_ready(&v1);
  return result;
}

