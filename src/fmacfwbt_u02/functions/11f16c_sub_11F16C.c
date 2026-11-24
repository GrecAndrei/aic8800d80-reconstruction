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


extern uint32_t dword_11F264;
extern uint32_t dword_11F268;
extern uint32_t dword_11F270;
extern uint32_t dword_11F274;
extern uint32_t dword_11F278;
extern uint32_t dword_11F27C;
extern uint32_t dword_11F280;
extern uint32_t off_11F26C;

// wlc_attach @ 0x11f16c, size 248 bytes
int wlc_attach()
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

  v0 = dword_11F268;
  v1 = dword_11F264;
  zero_struct((uint32_t *)dword_11F264);
  v2 = (uint32_t *)(v0 + 22272);
  do
  {
    wlc_bsscfg_llc_flush(v0 - 624);
    check_abort_flag(v1, (uint32_t *)(v0 - 624));
    v3 = (uint32_t *)(v0 - 40);
    do
    {
      zero_struct(v3);
      v4 = v3 + 10;
      v3 += 2;
      zero_struct(v4);
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
      zero_struct(v6);
      v7 = v6 + 10;
      v6 += 2;
      zero_struct(v7);
    }
    while ( v6 != v2 );
    v2 = v6 + 174;
  }
  v8 = off_11F26C;
  v9 = dword_11F270;
  v10 = dword_11F274;
  wlc_bsscfg_llc_flush(off_11F26C);
  *(uint32_t *)(v8 + 0x20) = 0x20000000;
  *(uint32_t *)(v8 + 0x150) = v9;
  *(uint32_t *)(v8 + 0xBC) = v10;
  *(uint8_t *)(v8 + 0x34) = 0;
  wlc_bsscfg_llc_flush(v8 + 696);
  *(uint32_t *)(v8 + 0x408) = v9 + 64;
  v11 = dword_11F278;
  *(uint32_t *)(v8 + 0x374) = v10 + 1320;
  *(uint32_t *)(v8 + 0x2D8) = v11;
  *(uint8_t *)(v8 + 0x2EC) = 0;
  wlc_bsscfg_llc_flush(v8 + 1392);
  *(uint32_t *)(v8 + 0x6C0) = v9 + 128;
  *(uint32_t *)(v8 + 0x590) = dword_11F27C;
  *(uint8_t *)(v8 + 0x5A4) = 0;
  *(uint32_t *)(v8 + 0x62C) = v10 + 2640;
  result = wlc_bsscfg_llc_flush(v8 + 2088);
  v13 = dword_11F280;
  *(uint8_t *)(v8 + 0x85C) = 0;
  *(uint32_t *)(v8 + 0x978) = v9 + 192;
  *(uint32_t *)(v8 + 0x8E4) = v10 + 3960;
  *(uint32_t *)(v8 + 0x848) = v13;
  return result;
}
