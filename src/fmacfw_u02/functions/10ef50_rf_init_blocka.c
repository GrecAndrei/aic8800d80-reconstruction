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

extern uint32_t dword_10F100;
extern uint32_t dword_10F104;
extern uint32_t dword_10F110;
extern uint32_t dword_10F10C;
extern uint32_t dword_10F108;
extern uint32_t dword_10F114;
extern uint32_t dword_10F118;
extern uint32_t dword_10F11C;
extern uint32_t dword_10F120;
extern uint32_t dword_10F124;
extern uint32_t dword_10F128;
extern uint32_t dword_10F12C;
extern uint32_t dword_10F130;
extern uint32_t dword_10F134;
extern uint32_t dword_10F138;
extern uint32_t dword_10F144;
extern uint32_t dword_10F140;
extern uint32_t dword_10F13C;
extern uint32_t dword_10F148;
extern uint32_t dword_10F14C;
extern uint32_t dword_10F150;
extern uint32_t dword_10F154;
extern uint32_t dword_10F158;
extern uint32_t dword_10F15C;
extern uint32_t off_10F160;
extern uint32_t dword_10F168;
extern uint32_t dword_10F164;
extern uint32_t dword_10F170;
extern uint32_t dword_10F16C;
extern uint32_t dword_10F174;
extern uint32_t off_10F178;
extern uint32_t dword_10F17C;

// rf_enable @ 0x10ef50, size 430 bytes
// Doc: rf_enable [rf]: Initialize RF block A with config write and sub-call setup
// rf_enable [rf]: Initialize RF block A with config write and sub-call setup
int rf_enable()
{
  int result; // r0

  mmio_rmw32(1879048192, 256, 264, 1);
  mmio_rmw32(dword_10F100, 0x8000000, 0x8000000, 1);
  mmio_rmw32(dword_10F104, 21, 31, 1);
  mmio_rmw32(dword_10F110, dword_10F10C, dword_10F108, 1);
  mmio_rmw32(dword_10F114, 2560, 2560, 1);
  mmio_rmw32(dword_10F118, 255, 255, 1);
  mmio_rmw32(dword_10F11C, 0, 100663296, 1);
  mmio_rmw32(dword_10F120, 0, 983040, 1);
  mmio_rmw32(dword_10F124, 96, 96, 1);
  mmio_rmw32(dword_10F128, 256, 256, 1);
  mmio_rmw32(dword_10F12C, 469762048, 469762048, 1);
  mmio_rmw32(dword_10F130, 104, 252, 1);
  mmio_rmw32(dword_10F134, 6, 6, 1);
  mmio_rmw32(dword_10F138, 320, 992, 1);
  mmio_rmw32(dword_10F144, dword_10F140, dword_10F13C, 1);
  mmio_rmw32(dword_10F148, 0x400000, 15728640, 1);
  mmio_rmw32(dword_10F14C, 16, 63, 1);
  mmio_rmw32(dword_10F150, 0, 60, 1);
  mmio_rmw32(dword_10F154, 0, 256, 1);
  mmio_rmw32(dword_10F158, 2048, 16128, 1);
  result = mmio_rmw32(dword_10F15C, 1, 1, 1);
  if ( **(uint8_t **)off_10F160 == 1 )
  {
    mmio_write32(dword_10F168, dword_10F164, 1);
    mmio_write32(dword_10F170, dword_10F16C, 1);
    mmio_rmw32(dword_10F15C, 0x100000, 0x100000, 1);
    result = mmio_rmw32(dword_10F174, 2, 31, 1);
    if ( !*((uint8_t *)off_10F178 + 375) )
    {
      mmio_rmw32(dword_10F17C, 1, 1, 1);
      mmio_rmw32(dword_10F154, 256, 256, 1);
      mmio_rmw32(dword_10F158, 0x2000, 16128, 1);
      mmio_rmw32(dword_10F11C, 2359296, 16515072, 1);
      return mmio_rmw32(dword_10F15C, 256, 256, 1);
    }
  }
  return result;
}

