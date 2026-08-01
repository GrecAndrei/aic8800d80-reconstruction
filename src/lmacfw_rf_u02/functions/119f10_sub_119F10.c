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

extern uint32_t off_119F88;
extern uint32_t dword_119F90;
extern uint32_t dword_119F8C;
extern uint32_t off_119F94;
extern uint32_t dword_119F98;

// rf_check_rssi @ 0x119f10, size 118 bytes
int  rf_check_rssi(int a1, void ( **a2)(int), int a3)
{
  int16_t **v3; // r5
  int result; // r0
  int v7; // r0

  v3 = (int16_t **)off_119F88;
  if ( **(int16_t **)off_119F88 < 0 && flash_write_byte(a3) == 4 )
    flash_ctrl_init(dword_119F90, dword_119F8C, 1587);
  result = flash_write_byte(a3);
  if ( result )
  {
    if ( result != 2 )
    {
      rf_cal_trim_check();
      flash_erase_sector(a3);
      return 2;
    }
  }
  else
  {
    if ( **v3 < 0 && *(uint32_t *)off_119F94 << 28 )
      flash_ctrl_init(dword_119F98, dword_119F8C, 1594);
    v7 = flash_erase_sector(a3);
    (*a2)(v7);
    return 0;
  }
  return result;
}

