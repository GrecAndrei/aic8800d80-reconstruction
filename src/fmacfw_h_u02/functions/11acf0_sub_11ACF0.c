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

extern uint32_t off_11AF84;
extern uint32_t dword_11AF78;
extern uint32_t off_11AF7C;
extern uint32_t dword_11AF8C;
extern uint32_t dword_11AF88;
extern uint32_t dword_11AF80;
extern uint32_t off_11AF70;
extern uint32_t off_11AF74;

// mac_tx_init @ 0x11acf0, size 638 bytes
int  mac_tx_init(int a1, int *a2, unsigned int a3, unsigned int a4, uint8_t a5)
{
  int v5; // r7
  uint32_t *v6; // r10
  uint32_t *v8; // r9
  int v12; // r11
  int v13; // r7
  int v14; // r3
  int v15; // r12
  int v16; // r2
  uint32_t *v17; // r11
  void *v18; // r7
  int v19; // r0
  int v20; // r3
  int v21; // r12
  int v22; // r0
  int v23; // r5
  int v24; // r1
  int v25; // r2
  uint16_t *v26; // r1
  char v27; // r2
  int v28; // r2
  unsigned int v29; // r3
  int v30; // r1
  int v32; // r3

  v5 = *(uint32_t *)(a1 + 36);
  v6 = *(uint32_t **)(a1 + 76);
  v8 = v6 + 3;
  if ( (v5 & 0x200000) == 0 )
  {
    if ( (*(uint16_t *)(a1 + 82) & 4) == 0 )
      return 0;
    v16 = *(uint16_t *)(a1 + 4);
    if ( !*(uint16_t *)(a1 + 4) || (*(uint16_t *)(a1 + 30) & 8) != 0 )
    {
      if ( a3 >= (uint16_t)(((v6[9] + 3) & 0xFFFC) + 4) )
        goto LABEL_32;
    }
    else
    {
      v26 = (uint16_t *)v6[7];
      if ( !v26 || (*v26 & 0x8000) != 0 )
      {
        if ( a3 >= (uint16_t)(((v6[9] + 3) & 0xFFFC) + 4) )
        {
          if ( !v26 )
            goto LABEL_32;
          v30 = v6[8];
          goto LABEL_31;
        }
      }
      else
      {
        *v26 = ~((unsigned int)~((uint16_t)*v26 << 17) >> 17);
        v27 = *(uint8_t *)(a1 + 51) + 4;
        *(uint8_t *)(a1 + 50) += 4;
        *(uint8_t *)(a1 + 51) = v27;
        v28 = v6[9];
        v29 = (uint16_t)(((v28 + 7) & 0xFFFC) + 4);
        v16 = v28 + 4;
        v30 = v6[8] + 4;
        v6[8] = v30;
        v6[9] = v16;
        if ( v29 <= a3 )
        {
          v16 = *(uint16_t *)(a1 + 4);
          if ( !*(uint16_t *)(a1 + 4) || (*(uint16_t *)(a1 + 30) & 8) != 0 )
            goto LABEL_32;
LABEL_31:
          *(uint32_t *)(v30 - 3) = *((uint32_t *)off_11AF84 + 43);
LABEL_32:
          v14 = *(uint32_t *)a1;
          *a2 = *(uint32_t *)a1;
          if ( !v14 )
          {
LABEL_20:
            if ( !*(uint32_t *)(a1 + 68) )
            {
              v22 = list_pop(dword_11AF78);
              v23 = v22;
              if ( **(int16_t **)off_11AF7C < 0 && !v22 )
                irq_disable_mmio_write(dword_11AF8C, dword_11AF88, 3646);
              *(uint8_t *)(v23 + 14) = 1;
              *(uint32_t *)(v23 + 40) = v6[9];
              *(uint16_t *)(v23 + 8) = 0;
              *(uint8_t *)(v23 + 12) = *(uint8_t *)(a1 + 29);
              v24 = *(uint32_t *)(a1 + 76);
              *(uint32_t *)(v23 + 324) = a1;
              *(uint8_t *)(v24 + 1) = 1;
              v25 = dword_11AF80;
              *(uint32_t *)(a1 + 68) = v23;
              wlan_ioctl_handler_2(84 * a5 + 28 + v25, v23);
            }
            return (int)v8;
          }
          v17 = off_11AF70;
          v18 = off_11AF74;
          v19 = 0;
          goto LABEL_8;
        }
      }
    }
    channel_table_lookup(v6 + 3, a5, v16);
    return 0;
  }
  if ( (v5 & 0x380000) != 0x280000 )
    return 0;
  v12 = *(uint32_t *)(a1 + 68);
  if ( (*(uint16_t *)(v12 + 8) & 3) != 3
    || *(uint8_t *)(*(uint32_t *)off_11AF74 + 62) > (*(uint32_t *)off_11AF70 & 0x3Fu) )
  {
    return 0;
  }
  if ( *(uint32_t *)(v12 + 40) > a3 )
    return enable_component(a1, a2, a3, a4, a5);
  btm_read_indirect((int16_t *)a1);
  v13 = *(uint32_t *)(a1 + 36);
  v14 = **(uint32_t **)(v12 + 324);
  *a2 = v14;
  if ( v14 )
  {
    v15 = v13 & 0x200000;
    v16 = *(uint16_t *)(a1 + 4);
    v17 = off_11AF70;
    v18 = off_11AF74;
    v19 = v15;
LABEL_8:
    if ( v16 )
    {
      while ( (*(uint16_t *)(a1 + 30) & 8) == 0
           && *(uint16_t *)(v14 + 4)
           && (*(uint16_t *)(v14 + 30) & 8) == 0
           && *(uint8_t *)(*(uint32_t *)v18 + 62) <= (*v17 & 0x3Fu) )
      {
        v20 = *(uint32_t *)(v14 + 36);
        if ( v19 )
        {
          if ( (v20 & 0x200000) != 0 )
          {
            if ( !btm_indirect_handler(a1, a2, a3, a4, a5) )
              goto LABEL_40;
          }
          else if ( !btm_is_link_active(a1, a2, a3, a4, a5) )
          {
            goto LABEL_40;
          }
        }
        else
        {
          if ( (v20 & 0x200000) == 0 )
            goto LABEL_20;
          if ( !config_stream(a1, a2, a3, a4, a5) )
          {
LABEL_40:
            if ( (*(uint32_t *)(a1 + 36) & 0x200000) == 0 )
              goto LABEL_20;
            goto LABEL_41;
          }
        }
        v14 = *a2;
        if ( !*a2 )
          goto LABEL_40;
        v19 = *(uint32_t *)(a1 + 36) & 0x200000;
        if ( !*(uint16_t *)(a1 + 4) )
          break;
      }
    }
    v21 = v19;
    goto LABEL_19;
  }
  v21 = v13 & 0x200000;
LABEL_19:
  if ( !v21 )
    goto LABEL_20;
LABEL_41:
  v32 = *(uint32_t *)(a1 + 68);
  *(uint32_t *)(*(uint32_t *)(*(uint32_t *)(v32 + 324) + 76) + 20) = 0;
  return v32 + 16;
}

