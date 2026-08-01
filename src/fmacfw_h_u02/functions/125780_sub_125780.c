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

extern uint32_t off_125888;
extern uint32_t off_12588C;
extern uint32_t off_125884;
extern uint32_t dword_125898;
extern uint32_t dword_125894;
extern uint32_t off_125890;
extern uint32_t off_12589C;

// patch_check_enable @ 0x125780, size 258 bytes
void patch_check_enable()
{
  int v0; // r4
  uint8_t *v1; // r6
  int v2; // r5
  uint32_t *v3; // r2
  int v4; // r7
  uint8_t *v5; // r8
  char v6; // r9
  int v7; // r10
  int v8; // r0
  int v9; // r3

  v0 = *((uint32_t *)off_125888 + 2);
  v1 = off_12588C;
  if ( **(int16_t **)off_125884 < 0 && *((uint32_t *)off_12588C + 1) )
  {
    irq_disable_mmio_write(dword_125898, dword_125894, 1074);
    v2 = (uint8_t)v1[9];
    if ( v1[9] )
      goto LABEL_20;
  }
  else
  {
    v2 = *((uint8_t *)off_12588C + 9);
    if ( *((uint8_t *)off_12588C + 9) )
    {
LABEL_20:
      v1[8] = 1;
      return;
    }
  }
  v3 = off_125890;
  v1[8] = v2;
  v4 = 32 * *v3;
  if ( v0 )
  {
    v5 = off_12589C;
    v6 = v2;
    v7 = 1;
    while ( 1 )
    {
      if ( *(uint8_t *)(v0 + 106) != 2
        || !*(uint8_t *)(v0 + 226)
        || !*(uint8_t *)(v0 + 108)
        || *(uint8_t *)(v0 + 225) != *(uint8_t *)(v0 + 224) )
      {
        goto LABEL_6;
      }
      if ( tx_path_setup(v0) )
        ++*v5;
      if ( v7 && (unsigned int)(v4 - 50) > 0xBB6 )
      {
        cfm_ops_get(v0);
LABEL_16:
        *v5 = v6;
        v0 = *(uint32_t *)v0;
        v7 = 0;
        v2 = 1;
        if ( !v0 )
          return;
      }
      else
      {
        if ( v2 )
          goto LABEL_16;
        v7 = cfm_ops_get(v0);
        if ( v7 )
        {
          *(uint8_t *)(v0 + 144) = *(uint8_t *)(v0 + 107);
          *(uint8_t *)(v0 + 145) = -1;
          v8 = sec_check(v0 + 116, 4);
          v9 = *((uint32_t *)v1 + 1);
          if ( v8 )
            *((uint32_t *)v1 + 1) = ++v9;
          if ( v9 == 1 )
            ke_evt_peek();
          v7 = 0;
        }
        else
        {
          *v5 = 0;
        }
LABEL_6:
        v0 = *(uint32_t *)v0;
        if ( !v0 )
          return;
      }
    }
  }
}

