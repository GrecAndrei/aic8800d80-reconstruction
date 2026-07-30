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

extern uint32_t off_10F3AC;
extern uint32_t dword_10F3B4;
extern uint32_t dword_10F3B0;
extern uint32_t dword_10F3B8;
extern uint32_t dword_10F3BC;
extern uint32_t dword_10F3C4;
extern uint32_t dword_10F3C0;
extern uint32_t dword_10F3C8;
extern uint32_t dword_10F3CC;
extern uint32_t dword_10F3D0;
extern uint32_t dword_10F3D4;
extern uint32_t dword_10F3D8;
extern uint32_t dword_10F3DC;
extern uint32_t dword_10F3E0;
extern uint32_t dword_10F3E4;
extern uint32_t dword_10F3E8;
extern uint32_t dword_10F3EC;
extern uint32_t dword_10F3F8;
extern uint32_t dword_10F3F4;
extern uint32_t dword_10F3F0;
extern uint32_t dword_10F3FC;
extern uint32_t dword_10F400;
extern uint32_t dword_10F404;
extern uint32_t dword_10F408;
extern uint32_t dword_10F40C;
extern uint32_t dword_10F410;
extern uint32_t off_10F414;
extern uint32_t dword_10F41C;
extern uint32_t dword_10F418;
extern uint32_t dword_10F424;
extern uint32_t dword_10F420;
extern uint32_t dword_10F428;
extern uint32_t off_10F42C;
extern uint32_t dword_10F430;

// sub_10F1E0 @ 0x10f1e0, size 458 bytes
int sub_10F1E0()
{
  uint8_t *v0; // r4
  int v1; // r5
  int v2; // r1
  int v3; // r2
  int result; // r0

  sub_10F064(1879048192, 256, 264, 1);
  v0 = off_10F3AC;
  v1 = dword_10F3B4;
  sub_10F064(dword_10F3B0, 0x8000000, 0x8000000, 1);
  sub_10F064(dword_10F3B8, 21, 31, 1);
  v2 = dword_10F3BC;
  if ( (*v0 & 0xC0) == 0xC0 )
    v2 = v1;
  sub_10F064(dword_10F3C4, v2, dword_10F3C0, 1);
  sub_10F064(dword_10F3C8, 2560, 2560, 1);
  sub_10F064(dword_10F3CC, 255, 255, 1);
  sub_10F064(dword_10F3D0, 0, 100663296, 1);
  sub_10F064(dword_10F3D4, 0, 983040, 1);
  sub_10F064(dword_10F3D8, 96, 96, 1);
  sub_10F064(dword_10F3DC, 256, 256, 1);
  sub_10F064(dword_10F3E0, 469762048, 469762048, 1);
  sub_10F064(dword_10F3E4, 104, 252, 1);
  if ( (*v0 & 0xC0) == 0xC0 )
    v3 = 102;
  else
    v3 = 6;
  sub_10F064(dword_10F3E8, 6, v3, 1);
  sub_10F064(dword_10F3EC, 320, 992, 1);
  sub_10F064(dword_10F3F8, dword_10F3F4, dword_10F3F0, 1);
  sub_10F064(dword_10F3FC, 0x400000, 15728640, 1);
  sub_10F064(dword_10F400, 16, 63, 1);
  sub_10F064(dword_10F404, 0, 60, 1);
  sub_10F064(dword_10F408, 0, 256, 1);
  sub_10F064(dword_10F40C, 2048, 16128, 1);
  result = sub_10F064(dword_10F410, 1, 1, 1);
  if ( **(uint8_t **)off_10F414 == 1 )
  {
    rf_reg_write_wait(dword_10F41C, dword_10F418, 1);
    rf_reg_write_wait(dword_10F424, dword_10F420, 1);
    sub_10F064(dword_10F410, 0x100000, 0x100000, 1);
    result = sub_10F064(dword_10F428, 2, 31, 1);
    if ( !*((uint8_t *)off_10F42C + 375) )
    {
      sub_10F064(dword_10F430, 1, 1, 1);
      sub_10F064(dword_10F408, 256, 256, 1);
      sub_10F064(dword_10F40C, 0x2000, 16128, 1);
      sub_10F064(dword_10F3D0, 2359296, 16515072, 1);
      return sub_10F064(dword_10F410, 256, 256, 1);
    }
  }
  return result;
}

