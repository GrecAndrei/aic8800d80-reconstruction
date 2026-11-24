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


extern uint32_t dword_11EEE8;
extern uint32_t dword_11EEEC;
extern uint32_t dword_11EEF4;
extern uint32_t dword_11EEF8;
extern uint32_t dword_11EEFC;
extern uint32_t dword_11EF00;
extern uint32_t dword_11EF04;
extern uint32_t off_11EEF0;

// ble_event_set @ 0x11edf0, size 248 bytes
int ble_event_set()
{
  int v0; // r5
  int v1; // r7
  uint32_t *v2; // r6
  uint32_t *v3; // r4
  uint32_t *v4; // r0
  int i; // r5
  uint32_t *v6; // r4
  uint32_t *v7; // r0
  int v8; // r4
  int v9; // r6
  int v10; // r5
  int v11; // r3
  int result; // r0
  int v13; // r3

  v0 = dword_11EEEC;
  v1 = dword_11EEE8;
  zero_8_bytes((uint32_t *)dword_11EEE8);
  v2 = (uint32_t *)(v0 + 22272);
  do
  {
    llc_aes_ccm_setup(v0 - 624);
    cmd_handler_a(v1, (uint32_t *)(v0 - 624));
    v3 = (uint32_t *)(v0 - 40);
    do
    {
      zero_8_bytes(v3);
      v4 = v3 + 10;
      v3 += 2;
      zero_8_bytes(v4);
    }
    while ( v3 != (uint32_t *)v0 );
    v0 = (int)(v3 + 174);
  }
  while ( v3 + 174 != v2 );
  for ( i = 2784; i != 3132; i += 87 )
  {
    v6 = v2 - 10;
    do
    {
      zero_8_bytes(v6);
      v7 = v6 + 10;
      v6 += 2;
      zero_8_bytes(v7);
    }
    while ( v6 != v2 );
    v2 = v6 + 174;
  }
  v8 = off_11EEF0;
  v9 = dword_11EEF4;
  v10 = dword_11EEF8;
  llc_aes_ccm_setup(off_11EEF0);
  *(uint32_t *)(v8 + 0x20) = 0x20000000;
  *(uint32_t *)(v8 + 0x150) = v9;
  *(uint32_t *)(v8 + 0xBC) = v10;
  *(uint8_t *)(v8 + 0x34) = 0;
  llc_aes_ccm_setup(v8 + 696);
  *(uint32_t *)(v8 + 0x408) = v9 + 64;
  v11 = dword_11EEFC;
  *(uint32_t *)(v8 + 0x374) = v10 + 1320;
  *(uint32_t *)(v8 + 0x2D8) = v11;
  *(uint8_t *)(v8 + 0x2EC) = 0;
  llc_aes_ccm_setup(v8 + 1392);
  *(uint32_t *)(v8 + 0x6C0) = v9 + 128;
  *(uint32_t *)(v8 + 0x590) = dword_11EF00;
  *(uint8_t *)(v8 + 0x5A4) = 0;
  *(uint32_t *)(v8 + 0x62C) = v10 + 2640;
  result = llc_aes_ccm_setup(v8 + 2088);
  v13 = dword_11EF04;
  *(uint8_t *)(v8 + 0x85C) = 0;
  *(uint32_t *)(v8 + 0x978) = v9 + 192;
  *(uint32_t *)(v8 + 0x8E4) = v10 + 3960;
  *(uint32_t *)(v8 + 0x848) = v13;
  return result;
}
