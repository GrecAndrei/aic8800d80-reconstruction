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

extern uint32_t dword_12ACF4;
extern uint32_t dword_12ACD0;
extern uint32_t off_12ACD4;
extern uint32_t dword_12ACEC;
extern uint32_t dword_12ACE8;
extern uint32_t off_12ACDC;
extern uint32_t off_12ACE4;
extern uint32_t dword_12ACD8;
extern uint32_t dword_12ACF0;
extern uint32_t dword_12ACE0;

// bt_dev_update @ 0x12aa04, size 716 bytes
uint8_t * bt_dev_update(int a1)
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

  v1 = dword_12ACF4;
  v2 = *(uint8_t *)(a1 + 17);
  v3 = *(uint8_t *)(a1 + 16);
  v4 = dword_12ACF4 + 140 * v2;
  v21 = *(uint8_t *)(v4 + 113);
  v6 = dword_12ACD0 + 1320 * v21;
  v7 = (uint8_t *)v4;
  if ( *(uint8_t *)(v4 + 112) == 1 )
  {
    v8 = *(uint32_t *)(a1 + 12);
  }
  else
  {
    v20 = *(uint32_t *)(a1 + 44);
    if ( **(int16_t **)off_12ACD4 < 0 && *(uint8_t *)(v6 + 106) )
      mmio_irq_clear(dword_12ACEC, dword_12ACE8, 98);
    v8 = v20 + *((uint32_t *)off_12ACDC + 4) - *(uint32_t *)off_12ACE4 - *(uint32_t *)(v6 + 132);
  }
  v9 = (int16_t **)off_12ACD4;
  v10 = dword_12ACD8;
  v11 = off_12ACDC;
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
              bt_conn_get_state(v6, *(uint8_t *)(a1 + 18), 0);
              v12 = (int)v7;
            }
            else
            {
              if ( *(uint8_t *)(a1 + 16) )
              {
                ke_event_set_lock(a1);
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
              if ( v8 - *((uint32_t *)off_12ACDC + 4) - 5000 >= 0 )
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
              set_flag_byte(*(uint8_t *)(dword_12ACD0 + 1320 * v21 + 107), 3);
              if ( v8 - *((uint32_t *)off_12ACDC + 4) - 5000 >= 0 )
              {
                v3 = 1;
                v16 = *(uint8_t *)(v1 + 140 * v2 + 112);
                goto LABEL_35;
              }
LABEL_27:
              v14 = *(uint32_t *)(a1 + 24);
            }
          }
          else if ( v8 - *((uint32_t *)off_12ACDC + 4) - 5000 >= 0 )
          {
            v22 = *(uint8_t *)(v13 + 112);
            ke_event_lock(a1, v8);
            *(uint8_t *)(a1 + 16) = v22;
            mem_fill((int)v7);
            result = state_machine_step(v7);
            if ( *(uint8_t *)(dword_12ACD0 + 1320 * v21 + 106) != 2 )
              return result;
            goto LABEL_30;
          }
        }
        else if ( v8 - *((uint32_t *)off_12ACDC + 4) - 5000 >= 0 )
        {
          v3 = 1;
          goto LABEL_35;
        }
        v8 += v14;
      }
      while ( v8 - *((uint32_t *)off_12ACDC + 4) - 5000 < 0 );
      v3 = 2;
      if ( *(uint8_t *)(v1 + 140 * v2 + 112) )
        goto LABEL_36;
LABEL_42:
      if ( **(int16_t **)off_12ACD4 < 0 && *(uint8_t *)(v6 + 106) )
        mmio_irq_clear(dword_12ACEC, dword_12ACF0, 79);
      *(uint32_t *)(a1 + 44) = *(uint32_t *)off_12ACE4 - *((uint32_t *)off_12ACDC + 4) + *(uint32_t *)(v6 + 132) + v8;
      goto LABEL_36;
    }
    if ( **v9 < 0 )
    {
      mmio_irq_clear(dword_12ACE0, v10, 720);
      v9 = (int16_t **)off_12ACD4;
      v10 = dword_12ACD8;
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
    mem_fill(v12);
    return state_machine_step(v7);
  }
  v16 = *(uint8_t *)(v1 + 140 * v2 + 112);
LABEL_35:
  if ( !v16 )
    goto LABEL_42;
LABEL_36:
  ke_event_lock(a1, v8);
  *(uint8_t *)(a1 + 16) = v3;
  mem_fill((int)v7);
  result = state_machine_step(v7);
  if ( *(uint8_t *)(dword_12ACD0 + 1320 * v21 + 106) == 2 && v3 == 1 )
LABEL_30:
    *(uint32_t *)(dword_12ACD0 + 1320 * v21 + 4) |= 0x20u;
  return result;
}

