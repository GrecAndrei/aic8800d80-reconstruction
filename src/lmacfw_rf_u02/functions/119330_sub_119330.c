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

extern uint32_t dword_1193D0;
extern uint32_t off_1193CC;
extern uint32_t dword_1193DC;
extern uint32_t dword_1193D8;
extern uint32_t dword_1193D4;

// rx_process_packet @ 0x119330, size 154 bytes
int  rx_process_packet(int a1, int *a2, int a3, int a4)
{
  int v4; // r6
  int v6; // r7
  int v9; // r8
  int v10; // r4
  char v11; // r1
  int v12; // r2
  int v13; // r3

  v4 = dword_1193D0;
  v6 = *((uint8_t *)a2 + 5);
  if ( **(int16_t **)off_1193CC < 0 )
  {
    v9 = 8 * v6;
    if ( *(uint8_t *)(dword_1193D0 + 224 * v6 + 94) )
      flash_ctrl_init(dword_1193DC, dword_1193D8, 2660);
  }
  else
  {
    v9 = 8 * v6;
  }
  v10 = v4 + 32 * (v9 - v6);
  v11 = *((uint8_t *)a2 + 4);
  v12 = *(uint8_t *)(v10 + 121);
  v13 = *a2;
  *(uint32_t *)(v10 + 144) = *a2;
  *(uint8_t *)(v10 + 140) = v11;
  if ( v12 == 1 )
  {
    ke_exit_critical(v4 + 224 * v6 + 124);
    v13 = *(uint32_t *)(v10 + 144);
    *(uint8_t *)(v10 + 121) = 0;
  }
  check_interrupt_flag(256, dword_1193D4, *(uint8_t *)(v4 + 32 * (v9 - v6) + 140), v13);
  ke_evt_handler(98, a4, a3);
  return 0;
}

