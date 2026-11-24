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


extern uint32_t dword_12C8A0;
extern uint32_t dword_12C8A4;
extern uint32_t dword_12C8AC;
extern uint32_t dword_12C8B0;

// ke_event_schedule @ 0x12c7f8, size 166 bytes
int ke_event_schedule()
{
  unsigned int v0; // r7
  int *v1; // r5
  int *v2; // r9
  uint32_t *v3; // r8
  int v4; // r1
  unsigned int v5; // r3
  int result; // r0
  volatile unsigned int v7; // r2
  char *v8; // r0
  char *v9; // r4
  int v10; // r2
  int v11; // r3
  int v12; // r2
  int v13; // r4
  int v14; // r3
  int *v15; // r3
  int v16; // r3
  int v17; // r3
  int v18; // r2

  v0 = dword_12C8A0;
  v1 = (int *)dword_12C8A4;
  v2 = (int *)dword_12C8B0;
  v3 = (uint32_t *)(dword_12C8A0 + 32);
  while ( 1 )
  {
    unknown_func_12d14c(0x10000000);
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *v2 = 1;
    }
    v12 = *v1;
    v13 = *(uint32_t *)(v0 + 0x14);
    v14 = *v1 + 1;
    result = (int)v3;
    *v1 = v14;
    if ( !v13 )
      break;
    v4 = *(uint32_t *)(v13 + 8);
    v5 = v4 - (*(volatile uint32_t *)0x40501010u);
    if ( (int)(v5 - 50) >= 0 )
    {
      result = unknown_worker(v3, v4);
      v7 = (*(volatile uint32_t *)0x40501010u);
      if ( (int)(*(uint32_t *)(v13 + 8) - v7) >= 0 )
      {
        if ( *v1 )
        {
          v17 = *v1 - 1;
          v18 = *(uint32_t *)dword_12C8B0;
          *v1 = v17;
          if ( !v17 )
          {
            if ( v18 )
              goto LABEL_15;
          }
        }
        return result;
      }
    }
    v8 = (char *)mem_word_load(dword_12C8AC);
    v9 = v8;
    v10 = *v1 - 1;
    if ( *v1 )
    {
      v11 = *v2;
      *v1 = v10;
      if ( !v10 )
      {
        if ( v11 )
          __enable_irq();
      }
    }
    ke_msg_send_no_param(*((uint16_t *)v8 + 2), *((uint16_t *)v8 + 3), 255);
    tx_pkt_enqueue(v9);
  }
  if ( v14 )
  {
    v15 = (int *)dword_12C8B0;
    *v1 = v12;
    v16 = *v15;
    if ( !v12 )
    {
      if ( v16 )
LABEL_15:
        __enable_irq();
    }
  }
  return result;
}
