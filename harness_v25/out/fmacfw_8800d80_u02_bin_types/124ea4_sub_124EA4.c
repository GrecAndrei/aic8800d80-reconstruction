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

extern uint32_t off_124F60;
extern uint32_t off_124F64;
extern uint32_t off_124F78;
extern uint32_t off_124F68;
extern uint32_t off_124F6C;
extern uint32_t dword_124F74;
extern uint32_t dword_124F70;

// sub_124EA4 @ 0x124ea4, size 186 bytes
int sub_124EA4()
{
  uint32_t *v0; // r7
  int *v1; // r6
  int *v2; // r8
  uint32_t *v3; // r5
  void *v4; // r9
  int result; // r0
  uint32_t *v6; // r4
  int v7; // r1
  int v8; // r3
  int v9; // r3
  int v10; // r2
  void ( *v11)(uint32_t); // r3
  int *v12; // r3
  int v13; // r3
  int *v14; // r3

  v0 = off_124F60;
  v1 = (int *)off_124F64;
  v2 = (int *)off_124F78;
  v3 = off_124F68;
  v4 = off_124F60;
  while ( 1 )
  {
    clear_flags(0x20000000);
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *v2 = 1;
    }
    result = *v1;
    v6 = (uint32_t *)*v0;
    v7 = *v1 + 1;
    *v1 = v7;
    if ( !v6 )
      break;
    v8 = v6[3];
    if ( v8 - v3[4] - 50 >= 0 )
    {
      v3[2] = 0x40000;
      v3[12] = v8;
      v3[2] = 4;
      if ( v8 - v3[4] >= 0 )
      {
        if ( !v7 )
          return result;
        v14 = (int *)off_124F78;
        *v1 = result;
        v13 = *v14;
        if ( result )
          return result;
        goto LABEL_17;
      }
    }
    rf_bus_mark_n100_d2d0(v4);
    if ( *v1 )
    {
      v9 = *v1 - 1;
      v10 = *v2;
      *v1 = v9;
      if ( !v9 )
      {
        if ( v10 )
          __enable_irq();
      }
    }
    v11 = (void ( *)(uint32_t))v6[1];
    if ( **(int16_t **)off_124F6C >= 0 || v11 )
    {
      v11(v6[2]);
    }
    else
    {
      sub_12F46C(dword_124F74, dword_124F70, 246);
      ((void ( *)(uint32_t))v6[1])(v6[2]);
    }
  }
  *((uint32_t *)off_124F68 + 2) = 1024;
  if ( !v7 )
    return result;
  v12 = (int *)off_124F78;
  *v1 = result;
  v13 = *v12;
  if ( result )
    return result;
LABEL_17:
  if ( v13 )
    __enable_irq();
  return result;
}

