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

extern uint32_t dword_130138;
extern uint32_t dword_130140;
extern uint32_t dword_130144;
extern uint32_t dword_130148;
extern uint32_t dword_13015C;
extern uint32_t dword_13014C;
extern uint32_t dword_13016C;
extern uint32_t dword_130164;
extern uint32_t dword_130160;
extern uint32_t dword_130168;
extern uint32_t dword_130150;
extern uint32_t off_130154;
extern uint32_t off_130158;
extern uint32_t dword_13013C;

// find_by_index @ 0x130018, size 288 bytes
int  find_by_index(unsigned int a1)
{
  int v1; // r0
  int v2; // r4
  uint32_t *v4; // r0
  uint32_t *v5; // r5
  unsigned int CPSR; // r1
  unsigned int v7; // r2
  unsigned int v8; // r4
  unsigned int v9; // r5
  unsigned int v10; // r3
  uint8_t *v11; // r2
  int v12; // r0
  int v13; // r8
  int v14; // r7
  unsigned int v15; // r5
  unsigned int v16; // r6
  int v17; // t1
  int v18; // r7
  int v19; // r6
  unsigned int v20; // r4
  unsigned int v21; // r5
  int v22; // t1
  unsigned int v23; // [sp+8h] [bp-8h]

  v1 = fetch_global_ptr(a1, (uint8_t *)dword_130138, 0);
  v2 = v1;
  if ( v1 >= 0 )
  {
    if ( v1 )
    {
      if ( memmove(dword_130140) != v1 || strcmp(dword_130140, dword_130138) )
      {
        v4 = mem_word_load(dword_130144);
        v5 = v4;
        if ( v4 )
        {
          memcpy(v4 + 1, dword_130138);
          cmd_handler_a(dword_130148, v5);
        }
        else
        {
          read_memory_byte((uint8_t *)dword_13015C);
        }
      }
      else
      {
        CPSR = __get_CPSR();
        v7 = __get_CPSR();
        v8 = __get_CPSR();
        v9 = __get_CPSR();
        v10 = __get_CPSR();
        v23 = __get_CPSR();
        log_printf(dword_13014C, CPSR, v7, v8, v9, v10, v23);
        if ( v9 )
        {
          v13 = dword_13016C;
          v14 = dword_130164;
          v15 = v9 & 0xFFFFFFF0;
          read_memory_byte((uint8_t *)dword_130160);
          v16 = v15 + 256;
          do
          {
            if ( !(v15 << 28) )
              log_printf(v13, v15);
            v17 = *(uint32_t *)v15;
            v15 += 4;
            log_printf(v14, v17);
          }
          while ( v16 != v15 );
        }
        if ( v8 )
        {
          v18 = dword_13016C;
          v19 = dword_130164;
          v20 = v8 & 0xFFFFFFF0;
          read_memory_byte((uint8_t *)dword_130168);
          v21 = v20 + 256;
          do
          {
            if ( !(v20 << 28) )
              log_printf(v18, v20);
            v22 = *(uint32_t *)v20;
            v20 += 4;
            log_printf(v19, v22);
          }
          while ( v21 != v20 );
        }
        read_memory_byte((uint8_t *)dword_130150);
        v11 = off_130154;
        v12 = *(uint8_t *)off_130154;
        if ( *(uint8_t *)off_130154 )
        {
          *((uint8_t *)off_130158 + 783) = -4;
          v2 = 0;
          *v11 = 0;
        }
        else
        {
          *((uint8_t *)off_130158 + 783) = -12;
          v2 = v12;
          *v11 = 1;
        }
      }
    }
    else
    {
      read_memory_byte((uint8_t *)dword_13013C);
    }
    fetch_global_ptr(0x30u, (uint8_t *)dword_130138, dword_13013C);
  }
  return v2;
}

