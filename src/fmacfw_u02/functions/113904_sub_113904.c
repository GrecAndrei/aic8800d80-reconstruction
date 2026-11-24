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


extern uint32_t dword_1139A8;
extern uint32_t off_1139A0;
extern uint32_t off_1139A4;
extern uint32_t off_1139AC;
extern uint32_t off_1139B0;
extern uint32_t off_1139B4;
extern uint32_t off_1139B8;
extern uint32_t off_1139BC;
extern uint32_t off_1139C4;

// assert_fault @ 0x113904, size 156 bytes
int  assert_fault(uint32_t *a1)
{
  int *v2; // r4
  int v3; // r0
  uint8_t *v4; // r1
  int result; // r0
  uint16_t v6; // r3
  int v7; // r3
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1139A0 = 1;
  }
  v2 = (int *)off_1139A4;
  v3 = dword_1139A8;
  ++*(uint32_t *)off_1139A4;
  cmd_handler_a(v3, a1);
  v4 = off_1139B0;
  result = *(uint8_t *)off_1139B0;
  v6 = *(uint16_t *)off_1139AC + 1;
  *(uint16_t *)off_1139AC = v6;
  if ( result && *(uint8_t *)off_1139B4 <= (unsigned int)v6 )
  {
    v9 = *(uint8_t *)off_1139B8;
    *v4 = 0;
    if ( v9 )
      *((uint32_t *)off_1139BC + 512) &= ~0x2000u;
    else
      *((uint32_t *)off_1139BC + 713) &= ~1u;
    state_check_4_b(1);
    ke_int_lock((char *)0x42D, 1);
    result = check_status_bits(512, aWfr);
    if ( !*(uint8_t *)off_1139C4 )
      read_state_flag(result, v10, v11, *(uint8_t *)off_1139C4);
  }
  if ( *v2 )
  {
    v7 = *v2 - 1;
    v8 = *(uint32_t *)off_1139A0;
    *v2 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}
