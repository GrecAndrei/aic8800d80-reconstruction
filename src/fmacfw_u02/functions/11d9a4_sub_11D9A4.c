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

extern uint32_t off_11DA58;
extern uint32_t off_11DA5C;
extern uint32_t off_11DA68;
extern uint32_t off_11DA6C;
extern uint32_t off_11DA60;
extern uint32_t dword_11DA64;

// mac_wait_scan @ 0x11d9a4, size 180 bytes
int mac_wait_scan()
{
  int *v0; // r6
  int v1; // r4
  int result; // r0
  uint16_t *v3; // r5
  int *v4; // r8
  int *v5; // r9
  char v6; // r2
  void ( *v7)(uint32_t); // r3
  int v8; // r3
  int v9; // r2
  uint8_t *v10; // r4

  v0 = (int *)off_11DA58;
  v1 = *(uint32_t *)off_11DA58;
  result = unknown_func_12d14c(0x200000);
  if ( v1 )
  {
    v3 = off_11DA5C;
    if ( *(uint16_t *)off_11DA5C )
    {
      v4 = (int *)off_11DA68;
      v5 = (int *)off_11DA6C;
      do
      {
        if ( (*(uint8_t *)(v1 + 16) & 1) == 0 && !*v3 )
          break;
        mem_word_load(v0);
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *v4 = 1;
        }
        v6 = *(uint8_t *)(v1 + 16);
        ++*v5;
        if ( (v6 & 1) == 0 )
          --*v3;
        v7 = *(void ( **)(uint32_t))(v1 + 4);
        *(uint8_t *)(v1 + 16) = 0;
        if ( v7 )
          v7(*(uint32_t *)(v1 + 8));
        result = *(uint32_t *)(v1 + 12);
        if ( result )
          result = radio_get_status();
        if ( *v5 )
        {
          v8 = *v5 - 1;
          v9 = *v4;
          *v5 = v8;
          if ( !v8 )
          {
            if ( v9 )
              __enable_irq();
          }
        }
        v1 = *v0;
      }
      while ( *v0 );
      v10 = off_11DA60;
      if ( *((uint8_t *)off_11DA60 + 69) )
      {
        unknown_func_12d104(0x80000);
        result = check_status_bits(1024, dword_11DA64);
        v10[69] = 0;
      }
    }
  }
  return result;
}

