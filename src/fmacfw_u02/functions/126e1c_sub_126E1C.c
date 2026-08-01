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

extern uint32_t off_127000;
extern uint32_t off_127004;
extern uint32_t off_127008;
extern uint32_t off_12700C;
extern uint32_t off_127020;
extern uint32_t off_127024;
extern uint32_t off_12703C;
extern uint32_t dword_127044;
extern uint32_t dword_127040;
extern uint32_t off_127028;
extern uint32_t off_12702C;
extern uint32_t off_127030;
extern uint32_t off_127034;
extern uint32_t dword_127038;
extern uint32_t off_127018;
extern uint32_t off_12701C;
extern uint32_t off_127010;
extern uint32_t dword_127014;

// ctrl_poll_events @ 0x126e1c, size 484 bytes
int ctrl_poll_events()
{
  uint32_t *v0; // r5
  uint32_t *v1; // r6
  int v2; // r4
  uint8_t *v3; // r0
  int v4; // r3
  int16_t v5; // r3
  BOOL v6; // r7
  int v7; // r3
  unsigned int v8; // r3
  int v9; // r5
  int v10; // r7
  unsigned int *v11; // r2
  uint32_t *v12; // r4
  int v13; // r1
  int v14; // r3
  unsigned int v16; // r3
  int v17; // r2
  int v18; // r3
  uint32_t *v19; // r3
  int v20; // r0
  int v21; // r2
  uint16_t *v22; // r1

  v0 = off_127000;
  v1 = off_127004;
  v2 = *((uint32_t *)off_127000 + 11);
  rf_enable((uint16_t *)(v2 + 4), 0);
  util_format(*(char *)(v2 + 12));
  *(uint32_t *)off_127008 = v1[*(uint8_t *)(v2 + 4) + 5];
  if ( *(uint8_t *)(v2 + 24) == 3 )
  {
    v7 = v0[10];
    if ( !v7 )
    {
      v0[10] = v2;
      v0[11] = 0;
      *(uint8_t *)(v2 + 16) = 4;
      if ( *((uint8_t *)v0 + 90) || !*((uint8_t *)off_12700C + 511) )
        goto LABEL_29;
      goto LABEL_27;
    }
    v6 = 0;
    goto LABEL_7;
  }
  v3 = (uint8_t *)ke_msg_alloc(68, 13, 0, 4);
  v4 = *(uint8_t *)(v2 + 24);
  *v3 = v4;
  if ( v4 == 4 )
  {
    v5 = *(uint16_t *)(v2 + 14);
    if ( v5 )
      LOBYTE(v5) = 1;
  }
  else
  {
    LOBYTE(v5) = 0;
  }
  v6 = 0;
  v3[1] = v5;
  v3[3] = 0;
  v3[2] = *(uint8_t *)(v2 + 26);
  ke_msg_send(v3);
  v7 = v0[10];
  if ( v7 )
  {
    if ( *(uint8_t *)(v2 + 24) == 4
      && *(uint16_t *)(v7 + 4) == *(uint16_t *)(v2 + 4)
      && *(uint8_t *)(v7 + 13) == *(uint8_t *)(v2 + 13)
      && *(uint16_t *)(v7 + 6) == *(uint16_t *)(v2 + 6)
      && *(uint16_t *)(v7 + 8) == *(uint16_t *)(v2 + 8) )
    {
      v6 = *(uint16_t *)(v7 + 10) == *(uint16_t *)(v2 + 10);
    }
LABEL_7:
    *(uint8_t *)(v7 + 16) = 1;
    v8 = *(uint8_t *)(v2 + 24);
    goto LABEL_8;
  }
  v6 = 0;
  v8 = *(uint8_t *)(v2 + 24);
LABEL_8:
  v0[10] = v2;
  v0[11] = 0;
  *(uint8_t *)(v2 + 16) = 4;
  if ( v8 > 2 )
  {
    if ( *((uint8_t *)v0 + 90) && !v6 || !*((uint8_t *)off_12700C + 511) )
    {
      if ( v8 == 3 )
        goto LABEL_29;
      goto LABEL_22;
    }
  }
  else if ( !*((uint8_t *)off_12700C + 511) )
  {
    goto LABEL_10;
  }
LABEL_27:
  fatal_error_handler();
  v16 = *(uint8_t *)(v2 + 24);
  if ( v16 > 2 )
  {
    if ( v16 == 3 )
    {
LABEL_29:
      v17 = **(int16_t **)off_127020;
      v18 = v1[1] | 0x2200;
      *(uint32_t *)off_127024 = 0;
      v1[1] = v18;
      if ( v17 < 0 && *(uint32_t *)off_12703C << 28 )
      {
        call_shared_handler(dword_127044, dword_127040, 472);
        v18 = v1[1];
      }
      *(uint32_t *)off_127028 = v18 | *v1;
      ke_msg_send_no_param(141, 2, 255);
      if ( *((uint8_t *)off_12702C + 3851) == 1 && !*((uint8_t *)off_127030 + 10) )
      {
        v19 = *(uint32_t **)off_127034;
        if ( *(uint32_t *)off_127034 )
        {
          v20 = dword_127038;
          do
          {
            v21 = v19[15];
            if ( v21 >= 0 )
            {
              v22 = (uint16_t *)v19[4];
              if ( v22 )
              {
                if ( (*v22 & 0xFC) == 0x40 )
                  v19[15] = v21 | v20;
              }
            }
            v19 = (uint32_t *)v19[1];
          }
          while ( v19 );
        }
      }
    }
LABEL_22:
    v11 = (unsigned int *)off_127018;
    v12 = off_12701C;
    v13 = *(uint32_t *)off_127018;
    v14 = *((uint32_t *)off_12701C + 1) | 2;
    *((uint8_t *)v0 + 92) = (*(uint32_t *)off_127018 & 4) != 0;
    *v11 = v13 & 0xFFFFFFFB;
    v12[1] = v14;
    return set_clock_divisor();
  }
LABEL_10:
  rf_mmio_write();
  v9 = *((uint32_t *)off_127010 + 2);
  if ( v9 )
  {
    v10 = dword_127014;
    do
    {
      while ( *(uint32_t *)(v9 + 72) != v2 )
      {
        v9 = *(uint32_t *)v9;
        if ( !v9 )
          return set_clock_divisor();
      }
      *(uint8_t *)(v10 + 32 * *(uint8_t *)(v9 + 107) + 31) = 1;
      read_descriptor(v9);
      v9 = *(uint32_t *)v9;
    }
    while ( v9 );
  }
  return set_clock_divisor();
}

