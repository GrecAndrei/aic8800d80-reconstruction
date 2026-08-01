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

extern uint32_t off_12898C;
extern uint32_t dword_128968;
extern uint32_t dword_12895C;
extern uint32_t dword_128974;
extern uint32_t dword_128970;
extern uint32_t dword_128978;
extern uint32_t off_128990;
extern uint32_t dword_128980;
extern uint32_t dword_128988;
extern uint32_t dword_12897C;
extern uint32_t dword_128984;
extern uint32_t dword_128960;
extern uint32_t dword_128964;
extern uint32_t off_12896C;

// bsscfg_index @ 0x128748, size 530 bytes
int  bsscfg_index(int a1, int a2)
{
  int16_t **v2; // r10
  int v3; // r8
  int v4; // r7
  int v7; // r6
  int v8; // r9
  int v9; // r1
  uint8_t *v10; // r11
  int v11; // r3
  int v12; // r2
  uint8_t *v13; // r3
  int v14; // r2
  int v15; // r3
  int v16; // r2
  int result; // r0
  int v18; // r3
  char v19; // r0
  int16_t *v20; // r3
  unsigned int v21; // r2
  int v22; // r3
  int v23; // r3
  int v24; // r1

  v2 = (int16_t **)off_12898C;
  v3 = dword_128968;
  v4 = dword_12895C;
  v7 = dword_128968 + 28 * a2;
  if ( **(int16_t **)off_12898C >= 0
    || *(uint32_t *)(dword_12895C + 1320 * a1 + 72) && (irq_disable_mmio_write(dword_128974, dword_128970, 3061), **v2 >= 0) )
  {
    v8 = 8 * a2;
  }
  else
  {
    v8 = 8 * a2;
    if ( *(uint8_t *)(v3 + 28 * a2 + 24) == 255 )
      irq_disable_mmio_write(dword_128978, dword_128970, 3062);
  }
  v9 = v3 + 4 * (v8 - a2);
  v10 = off_128990;
  v11 = v4 + 1320 * a1;
  v12 = (uint8_t)(*(uint8_t *)(v9 + 25) + 1);
  *(uint8_t *)(v9 + 25) = v12;
  *(uint32_t *)(v11 + 72) = v7;
  *(uint8_t *)(v11 + 85) = 0;
  if ( v12 == 1 )
  {
    v19 = v10[90];
    *(uint8_t *)(v9 + 16) = 1;
    v20 = *v2;
    v21 = (uint8_t)(v19 + 1);
    v10[90] = v21;
    if ( *v20 < 0 && v21 > 2 )
    {
      irq_disable_mmio_write(dword_128980, dword_128970, 3082);
      v21 = (uint8_t)v10[90];
    }
    if ( v21 == 2 )
    {
      clear_stats_buf(dword_128988);
      v23 = dword_12895C;
      v24 = dword_12895C + 5280;
      do
      {
        *(uint8_t *)(v23 + 85) &= ~1u;
        v23 += 1320;
      }
      while ( v24 != v23 );
    }
    wlan_ioctl_handler_1(dword_12897C);
    if ( (v10[88] & 0xC) != 0 )
    {
      v22 = *((uint32_t *)v10 + 8);
      if ( **v2 < 0 && !v22 )
      {
        irq_disable_mmio_write(dword_128984, dword_128970, 3097);
        v22 = 0;
      }
      *(uint32_t *)(v22 + 8) = v7;
    }
    else if ( *((uint32_t *)v10 + 11) )
    {
      *((uint32_t *)v10 + 11) = v7;
    }
    else
    {
      llc_conn_command(v7);
    }
  }
  check_feature_flag(256, dword_128960);
  v13 = (uint8_t *)(v4 + 1320 * a1);
  v14 = (uint8_t)v13[1224];
  v13[86] = -1;
  if ( v14 && *(uint8_t *)(dword_128964 + 140 * (uint8_t)v13[1225] + 112) == 1 )
  {
    v13[85] |= 0x10u;
  }
  else
  {
    v15 = dword_128968;
    while ( 1 )
    {
      if ( *(uint8_t *)(v15 + 24) != 255 )
      {
        v16 = *(uint8_t *)(v15 + 27);
        if ( v16 != 255 )
          break;
      }
      v15 += 28;
      if ( dword_128968 + 84 == v15 )
        goto LABEL_10;
    }
    if ( *(uint32_t *)(v4 + 1320 * v16 + 72) != v7 )
      *(uint8_t *)(v4 + 1320 * a1 + 85) |= 0x10u;
  }
LABEL_10:
  result = type_get(v7);
  v18 = *((uint8_t *)off_12896C + 16);
  if ( v18 != a1 && v18 != 255 )
    return bsscfg_current(a2);
  return result;
}

