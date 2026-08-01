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

extern uint32_t off_1139A0;
extern uint32_t off_1139A4;
extern uint32_t dword_1139A8;
extern uint32_t off_1139B0;
extern uint32_t off_1139AC;
extern uint32_t off_1139B4;
extern uint32_t off_1139B8;
extern uint32_t off_1139BC;
extern uint32_t dword_1139C0;
extern uint32_t off_1139C4;

// assert_fault @ 0x113904, size 156 bytes
void assert_fault()
{
  int *v0; // r4
  int v1; // r0
  uint8_t *v2; // r1
  int v3; // r0
  uint16_t v4; // r3
  int v5; // r3
  int v6; // r2
  int v7; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1139A0 = 1;
  }
  v0 = (int *)off_1139A4;
  v1 = dword_1139A8;
  ++*(uint32_t *)off_1139A4;
  cmd_handler_a(v1);
  v2 = off_1139B0;
  v3 = *(uint8_t *)off_1139B0;
  v4 = *(uint16_t *)off_1139AC + 1;
  *(uint16_t *)off_1139AC = v4;
  if ( v3 && *(uint8_t *)off_1139B4 <= (unsigned int)v4 )
  {
    v7 = *(uint8_t *)off_1139B8;
    *v2 = 0;
    if ( v7 )
      *((uint32_t *)off_1139BC + 512) &= ~0x2000u;
    else
      *((uint32_t *)off_1139BC + 713) &= ~1u;
    state_check_4_b(1);
    ke_int_lock(1069, 1);
    check_status_bits(512, dword_1139C0);
    if ( !*(uint8_t *)off_1139C4 )
      read_state_flag();
  }
  if ( *v0 )
  {
    v5 = *v0 - 1;
    v6 = *(uint32_t *)off_1139A0;
    *v0 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
}

