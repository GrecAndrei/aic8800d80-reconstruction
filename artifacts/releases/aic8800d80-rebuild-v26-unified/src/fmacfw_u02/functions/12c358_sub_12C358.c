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

extern uint32_t dword_12C40C;
extern uint32_t off_12C410;
extern uint32_t off_12C414;
extern uint32_t dword_12C424;
extern uint32_t off_12C418;
extern uint32_t dword_12C420;
extern uint32_t dword_12C41C;
extern uint32_t dword_40021000;

// sub_12C358 @ 0x12c358, size 178 bytes
int  sub_12C358(int a1)
{
  int v1; // r5
  int *v3; // r7
  int v4; // r8
  int v5; // r0
  int v6; // r0
  int v7; // r6
  int v8; // r3
  int v9; // r2
  void ( *v10)(uint32_t, int); // r3
  int v12; // r2

  v1 = *(uint8_t *)(dword_12C40C + a1);
  if ( a1 )
    clear_flags(0x40000000);
  else
    clear_flags(1024);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12C410 = 1;
  }
  v3 = (int *)off_12C414;
  v4 = dword_12C424;
  v5 = dword_12C424 + 8 * a1;
  ++*(uint32_t *)off_12C414;
  v6 = rf_bus_mark_n100_d2d0(v5);
  v7 = v6;
  if ( *v3 && (v8 = *v3 - 1, v9 = *(uint32_t *)off_12C410, (*v3 = v8) == 0) && v9 )
  {
    __enable_irq();
    if ( **(int16_t **)off_12C418 >= 0 )
      goto LABEL_8;
  }
  else if ( **(int16_t **)off_12C418 >= 0 )
  {
    goto LABEL_8;
  }
  if ( !v6 )
    sub_12F46C(dword_12C420, dword_12C41C, 190);
LABEL_8:
  v10 = *(void ( **)(uint32_t, int))(v7 + 8);
  if ( v10 )
    v10(*(uint32_t *)(v7 + 12), a1);
  v12 = dword_40021000[16 * v1 + 2] | 1;
  ++*(uint16_t *)(v4 + 2 * (a1 + 12));
  dword_40021000[16 * v1 + 2] = v12;
  return 4104;
}

