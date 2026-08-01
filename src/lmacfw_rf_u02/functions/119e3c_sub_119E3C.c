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

extern uint32_t off_119F0C;
extern uint32_t dword_119F08;
extern uint32_t dword_119F04;

// rf_get_rssi @ 0x119e3c, size 184 bytes
void  __noreturn rf_get_rssi(int a1, int a2, int a3)
{
  int v3; // r0
  int v4; // [sp+Ch] [bp-14h]
  int v5; // [sp+10h] [bp-10h]
  int v6; // [sp+14h] [bp-Ch]
  int v7; // [sp+18h] [bp-8h]
  int v8; // [sp+1Ch] [bp-4h]

  v3 = **(int16_t **)off_119F0C;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  if ( v3 < 0 )
  {
    if ( flash_write_byte(a3) )
      flash_ctrl_init(dword_119F08, dword_119F04, 337);
  }
  wifi_set_channel();
}

