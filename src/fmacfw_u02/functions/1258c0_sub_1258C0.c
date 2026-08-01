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

extern uint32_t off_1259C8;
extern uint32_t off_1259CC;
extern uint32_t off_1259C4;
extern uint32_t dword_1259D8;
extern uint32_t dword_1259D4;
extern uint32_t off_1259D0;
extern uint32_t off_1259DC;

// ke_event_dispatch @ 0x1258c0, size 258 bytes
void ke_event_dispatch()
{
  int v0; // r4
  uint8_t *v1; // r6
  int v2; // r5
  uint32_t *v3; // r2
  int v4; // r7
  uint8_t *v5; // r8
  char v6; // r9
  int v7; // r10
  int status; // r0
  int v9; // r3

  v0 = *((uint32_t *)off_1259C8 + 2);
  v1 = off_1259CC;
  if ( **(int16_t **)off_1259C4 < 0 && *((uint32_t *)off_1259CC + 1) )
  {
    mmio_clear_register(dword_1259D8, dword_1259D4, 1074);
    v2 = (uint8_t)v1[9];
    if ( v1[9] )
      goto LABEL_20;
  }
  else
  {
    v2 = *((uint8_t *)off_1259CC + 9);
    if ( *((uint8_t *)off_1259CC + 9) )
    {
LABEL_20:
      v1[8] = 1;
      return;
    }
  }
  v3 = off_1259D0;
  v1[8] = v2;
  v4 = 32 * *v3;
  if ( v0 )
  {
    v5 = off_1259DC;
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
      if ( hci_acl_tx_done(v0) )
        ++*v5;
      if ( v7 && (unsigned int)(v4 - 50) > 0xBB6 )
      {
        wlc_get_ops(v0);
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
        v7 = wlc_get_ops(v0);
        if ( v7 )
        {
          *(uint8_t *)(v0 + 144) = *(uint8_t *)(v0 + 107);
          *(uint8_t *)(v0 + 145) = -1;
          status = tx_path_status(v0 + 116, 4);
          v9 = *((uint32_t *)v1 + 1);
          if ( status )
            *((uint32_t *)v1 + 1) = ++v9;
          if ( v9 == 1 )
            shared_s16_check();
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

