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


extern uint32_t dword_110188;
extern uint32_t off_11017C;
extern uint32_t off_110180;
extern uint32_t off_110184;

// calculate_rf_power @ 0x110100, size 122 bytes
int calculate_rf_power()
{
  void *v0; // r4
  int v1; // r3
  uint32_t *v2; // r0
  uint16_t v3; // r2
  uint16_t v4; // r1
  uint64_t v5; // kr00_8
  uint16_t v7[2]; // [sp+4h] [bp-14h] BYREF
  uint16_t v8[8]; // [sp+8h] [bp-10h] BYREF

  v0 = off_11017C;
  v1 = *(uint32_t *)off_11017C;
  v2 = off_110184;
  v3 = HIWORD(((uint32_t *)(uintptr_t)off_110180)[76]);
  v4 = LOWORD(((uint32_t *)(uintptr_t)off_110180)[77]) - 4;
  v7[1] = *(uint16_t *)(*(uint32_t *)off_11017C + 2);
  v8[1] = *(uint16_t *)(v1 + 4);
  v8[5] = *(uint16_t *)(v1 + 6);
  v8[7] = *(uint16_t *)(v1 + 8);
  v5 = *(uint64_t *)(v1 + 20);
  *(uint32_t *)off_110184 = v5;
  v2[3] = dword_110188;
  v2[1] = HIDWORD(v5);
  *((uint8_t *)v2 + 8) = 1;
  v8[2] = v4;
  v8[6] = v3 - 4;
  v7[0] = 12;
  v8[4] = 1596;
  v8[0] = 124;
  v8[3] = 0;
  hci_handle_command(v2, (int)v7, 0x20u);
  return hci_send_command((int)v8, *(uint32_t *)(*(uint32_t *)v0 + 28), *(uint32_t *)(*(uint32_t *)v0 + 32));
}
