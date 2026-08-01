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

extern uint32_t off_11581C;
extern uint32_t dword_115818;
extern uint32_t dword_11580C;
extern uint32_t dword_115810;
extern uint32_t off_115814;

// rx_pkt_status_update @ 0x115754, size 184 bytes
int * rx_pkt_status_update(int a1, int a2, int a3, int a4)
{
  int v5; // r1
  int16_t **v9; // r8
  int v10; // r7
  int v11; // r3
  int v12; // r3
  int v13; // zf
  int16_t v14; // r2
  uint16_t *v15; // r3
  int16_t v16; // r1

  v5 = *(uint16_t *)(a2 + 4);
  *(uint16_t *)(a1 + 38) |= 4u;
  if ( !v5 )
    return pdu_type_init(*(uint32_t *)(a1 + 32) + 8, *(uint32_t *)(a1 + 32) + 8, a4, a4);
  v9 = (int16_t **)off_11581C;
  v10 = *(uint32_t *)(a2 + 32);
  if ( **(int16_t **)off_11581C < 0 )
  {
    if ( *(uint32_t *)(a2 + 28) )
    {
      v11 = *(uint32_t *)(v10 + 24);
      if ( v11 )
        goto LABEL_7;
    }
    else
    {
      flash_ctrl_init(dword_115818, dword_11580C, 518);
      v11 = *(uint32_t *)(v10 + 24);
      if ( v11 )
        goto LABEL_7;
      if ( **v9 >= 0 )
        goto LABEL_5;
    }
    v12 = *(uint32_t *)(v10 + 20);
    if ( v12 )
      goto LABEL_6;
    flash_ctrl_init(dword_115810, dword_11580C, 525);
LABEL_5:
    v12 = *(uint32_t *)(v10 + 20);
LABEL_6:
    v11 = *(uint32_t *)(v12 + 8);
    goto LABEL_7;
  }
  v11 = *(uint32_t *)(v10 + 24);
  if ( !v11 )
    goto LABEL_5;
LABEL_7:
  if ( *(uint8_t *)(a2 + 14) == 255 )
  {
    v14 = *(uint8_t *)(v11 + 22) & 0xF;
    v13 = (*(uint8_t *)(v11 + 22) & 0xF) == 0;
    v15 = (uint16_t *)(v11 + 22);
    if ( v13 )
    {
      v16 = *((uint16_t *)off_115814 + 70) + 1;
      *((uint16_t *)off_115814 + 70) = v16;
    }
    else
    {
      v16 = *((uint16_t *)off_115814 + 70);
    }
    *v15 = v14 | (16 * v16);
  }
  llm_adv_pdu_build(a2);
  return pdu_type_init(*(uint32_t *)(a1 + 32) + 8, *(uint32_t *)(a1 + 32) + 8, a4, a4);
}

