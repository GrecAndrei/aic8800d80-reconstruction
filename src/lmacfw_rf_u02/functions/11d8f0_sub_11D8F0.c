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

extern uint32_t dword_11D9A4;
extern uint32_t off_11D9A8;
extern uint32_t off_11D9AC;
extern uint32_t dword_11D9BC;
extern uint32_t off_11D9B0;
extern uint32_t dword_11D9B8;
extern uint32_t dword_11D9B4;
extern uint32_t dword_40021008;

// sub_11D8F0 @ 0x11d8f0, size 178 bytes
int  sub_11D8F0(int a1)
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

  v1 = *(uint8_t *)(dword_11D9A4 + a1);
  if ( a1 )
    sub_11E628(0x40000000);
  else
    sub_11E628(0x8000);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11D9A8 = 1;
  }
  v3 = (int *)off_11D9AC;
  v4 = dword_11D9BC;
  v5 = dword_11D9BC + 8 * a1;
  ++*(uint32_t *)off_11D9AC;
  v6 = sub_11E7AC(v5);
  v7 = v6;
  if ( *v3 && (v8 = *v3 - 1, v9 = *(uint32_t *)off_11D9A8, (*v3 = v8) == 0) && v9 )
  {
    __enable_irq();
    if ( **(int16_t **)off_11D9B0 >= 0 )
      goto LABEL_8;
  }
  else if ( **(int16_t **)off_11D9B0 >= 0 )
  {
    goto LABEL_8;
  }
  if ( !v6 )
    rf_cmd_send_n264(dword_11D9B8, dword_11D9B4, 190);
LABEL_8:
  v10 = *(void ( **)(uint32_t, int))(v7 + 8);
  if ( v10 )
    v10(*(uint32_t *)(v7 + 12), a1);
  v12 = dword_40021008[16 * v1] | 1;
  ++*(uint16_t *)(v4 + 2 * (a1 + 12));
  dword_40021008[16 * v1] = v12;
  return 4104;
}

