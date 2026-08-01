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

extern uint32_t dword_12A990;
extern uint32_t dword_12A96C;
extern uint32_t off_12A970;
extern uint32_t dword_12A988;
extern uint32_t dword_12A984;
extern uint32_t off_12A978;
extern uint32_t off_12A980;
extern uint32_t dword_12A974;
extern uint32_t dword_12A98C;
extern uint32_t dword_12A97C;

// lll_conn_event_prepare @ 0x12a6a0, size 716 bytes
uint8_t * lll_conn_event_prepare(int a1)
{
  int v1; // r9
  int v2; // r8
  int v3; // r6
  int v4; // r3
  int v6; // r10
  uint8_t *v7; // r7
  int v8; // r4
  int16_t **v9; // r3
  int v10; // r1
  uint32_t *v11; // r11
  int v12; // r0
  int v13; // r12
  int v14; // r2
  unsigned int v15; // lr
  int v16; // r3
  int v17; // r6
  uint8_t *result; // r0
  uint64_t v19; // r0
  int v20; // r4
  int v21; // [sp+0h] [bp-Ch]
  char v22; // [sp+4h] [bp-8h]

  v1 = dword_12A990;
  v2 = *(uint8_t *)(a1 + 17);
  v3 = *(uint8_t *)(a1 + 16);
  v4 = dword_12A990 + 140 * v2;
  v21 = *(uint8_t *)(v4 + 113);
  v6 = dword_12A96C + 1320 * v21;
  v7 = (uint8_t *)v4;
  if ( *(uint8_t *)(v4 + 112) == 1 )
  {
    v8 = *(uint32_t *)(a1 + 12);
  }
  else
  {
    v20 = *(uint32_t *)(a1 + 44);
    if ( **(int16_t **)off_12A970 < 0 && *(uint8_t *)(v6 + 106) )
      irq_disable_mmio_write(dword_12A988, dword_12A984, 98);
    v8 = v20 + *((uint32_t *)off_12A978 + 4) - *(uint32_t *)off_12A980 - *(uint32_t *)(v6 + 132);
  }
  v9 = (int16_t **)off_12A970;
  v10 = dword_12A974;
  v11 = off_12A978;
  while ( 1 )
  {
    if ( v3 == 1 )
      goto LABEL_27;
    if ( v3 == 2 )
    {
      do
      {
        v17 = *(uint8_t *)(a1 + 19);
        if ( v17 != 255 )
        {
          v17 = (uint8_t)(v17 - 1);
          *(uint8_t *)(a1 + 19) = v17;
          if ( !v17 )
          {
            if ( *(uint8_t *)(v1 + 140 * v2 + 112) == 1 )
            {
              lll_conn_ready_check(v6, *(uint8_t *)(a1 + 18), 0);
              v12 = (int)v7;
            }
            else
            {
              if ( *(uint8_t *)(a1 + 16) )
              {
                mem_set_util(a1);
                *(uint8_t *)(a1 + 16) = 0;
              }
              v12 = (int)v7;
            }
            goto LABEL_21;
          }
        }
        v13 = v1 + 140 * v2;
        v15 = *(uint32_t *)(a1 + 28);
        v14 = *(uint32_t *)(a1 + 24);
        v16 = *(uint8_t *)(v13 + 112);
        v8 += v15 - v14;
        if ( v16 == 1 )
        {
          if ( *(uint8_t *)(v13 + 132) )
          {
            v19 = *(uint64_t *)(a1 + 36);
            LODWORD(v19) = v19 + v15;
            --HIDWORD(v19);
            *(uint64_t *)(a1 + 36) = v19;
            if ( HIDWORD(v19) )
            {
              if ( v8 - *((uint32_t *)off_12A978 + 4) - 5000 >= 0 )
              {
                v3 = 1;
                v16 = *(uint8_t *)(v13 + 112);
                goto LABEL_35;
              }
            }
            else
            {
              *(uint8_t *)(a1 + 20) = v17;
              if ( v15 )
                *(uint32_t *)(a1 + 40) = 0x80000000 / v15 - 1;
              util_get_state(*(uint8_t *)(dword_12A96C + 1320 * v21 + 107), 3);
              if ( v8 - *((uint32_t *)off_12A978 + 4) - 5000 >= 0 )
              {
                v3 = 1;
                v16 = *(uint8_t *)(v1 + 140 * v2 + 112);
                goto LABEL_35;
              }
LABEL_27:
              v14 = *(uint32_t *)(a1 + 24);
            }
          }
          else if ( v8 - *((uint32_t *)off_12A978 + 4) - 5000 >= 0 )
          {
            v22 = *(uint8_t *)(v13 + 112);
            mem_copy_util(a1, v8);
            *(uint8_t *)(a1 + 16) = v22;
            rsn_derive_key((int)v7);
            result = rsn_parse_ie(v7);
            if ( *(uint8_t *)(dword_12A96C + 1320 * v21 + 106) != 2 )
              return result;
            goto LABEL_30;
          }
        }
        else if ( v8 - *((uint32_t *)off_12A978 + 4) - 5000 >= 0 )
        {
          v3 = 1;
          goto LABEL_35;
        }
        v8 += v14;
      }
      while ( v8 - *((uint32_t *)off_12A978 + 4) - 5000 < 0 );
      v3 = 2;
      if ( *(uint8_t *)(v1 + 140 * v2 + 112) )
        goto LABEL_36;
LABEL_42:
      if ( **(int16_t **)off_12A970 < 0 && *(uint8_t *)(v6 + 106) )
        irq_disable_mmio_write(dword_12A988, dword_12A98C, 79);
      *(uint32_t *)(a1 + 44) = *(uint32_t *)off_12A980 - *((uint32_t *)off_12A978 + 4) + *(uint32_t *)(v6 + 132) + v8;
      goto LABEL_36;
    }
    if ( **v9 < 0 )
    {
      irq_disable_mmio_write(dword_12A97C, v10, 720);
      v9 = (int16_t **)off_12A970;
      v10 = dword_12A974;
    }
    if ( v8 - v11[4] - 5000 >= 0 )
      break;
    if ( !v3 )
      goto LABEL_10;
  }
  if ( !v3 )
  {
LABEL_10:
    v12 = (int)v7;
LABEL_21:
    rsn_derive_key(v12);
    return rsn_parse_ie(v7);
  }
  v16 = *(uint8_t *)(v1 + 140 * v2 + 112);
LABEL_35:
  if ( !v16 )
    goto LABEL_42;
LABEL_36:
  mem_copy_util(a1, v8);
  *(uint8_t *)(a1 + 16) = v3;
  rsn_derive_key((int)v7);
  result = rsn_parse_ie(v7);
  if ( *(uint8_t *)(dword_12A96C + 1320 * v21 + 106) == 2 && v3 == 1 )
LABEL_30:
    *(uint32_t *)(dword_12A96C + 1320 * v21 + 4) |= 0x20u;
  return result;
}

