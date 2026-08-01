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

extern uint32_t off_11B88C;
extern uint32_t off_11B890;
extern uint32_t dword_11B894;

// tx_channel_setup @ 0x11b70c, size 382 bytes
int  tx_channel_setup(int a1)
{
  uint32_t *v1; // r5
  int v2; // r6
  int v4; // r3
  void *v5; // r7
  int v6; // r2
  int v7; // r8
  uint32_t *v8; // r4
  uint64_t v9; // r0
  uint32_t *v10; // r2
  uint32_t *v11; // r2
  unsigned int v12; // r3
  int v13; // r3
  uint16_t *v14; // r7
  void *v15; // r7
  char v16; // r3
  int v17; // r1
  int v18; // r2
  int v19; // r2
  int v20; // r3
  uint32_t *v22; // [sp+4h] [bp-4h] BYREF

  v1 = off_11B88C;
  v2 = *((uint8_t *)off_11B88C + 190);
  v22 = 0;
  mmio_modify_bit(v2);
  get_conn_env(*((uint8_t *)v1 + 190));
  if ( !a1 )
    goto LABEL_24;
  v4 = *(uint32_t *)(a1 + 36);
  if ( (v4 & 0x200000) != 0 )
  {
    v5 = off_11B890;
    v6 = *(uint32_t *)(a1 + 68);
    if ( *(uint8_t *)(*(uint32_t *)off_11B890 + 1) )
    {
      v7 = *(uint32_t *)(v6 + 88);
    }
    else if ( (v4 & 0x380000) == 0x280000 || (*(uint16_t *)(v6 + 8) & 0x400) != 0 )
    {
      v7 = *(uint32_t *)(v6 + 20);
    }
    else
    {
      v7 = *(uint32_t *)(v6 + 88);
      *(uint32_t *)(v6 + 88) = *(uint16_t *)(v6 + 8) & 0x400;
    }
    LODWORD(v9) = rx_packet_parse(a1, (int)&v22);
    v8 = v22;
    HIDWORD(v9) = *(uint8_t *)(*(uint32_t *)v5 + 1);
    if ( v22 )
    {
      if ( !*(uint8_t *)(*(uint32_t *)v5 + 1) && (v22[14] & 0x200000) != 0 )
      {
        *(uint32_t *)(v9 + 4) = v7;
        v1[7 * v2 + 9] = v9;
        goto LABEL_11;
      }
      v22[1] = v7;
    }
    if ( (uint32_t)v9 )
      goto LABEL_21;
LABEL_25:
    v18 = dword_11B894;
    LODWORD(v9) = 84 * v2;
    *(uint32_t *)(dword_11B894 + 84 * v2) = 0;
    v1[7 * v2 + 9] = 0;
    v19 = v18 + 84 * v2;
    if ( !HIDWORD(v9) )
    {
      *(uint32_t *)(v19 + 4) = 0;
      *(uint32_t *)(v19 + 8) = 0;
    }
    return v9;
  }
  if ( (*(uint16_t *)(a1 + 82) & 4) == 0 )
  {
LABEL_24:
    HIDWORD(v9) = *(uint8_t *)(*(uint32_t *)off_11B890 + 1);
    goto LABEL_25;
  }
  v11 = *(uint32_t **)(a1 + 76);
  v12 = *(uint32_t *)(*(uint32_t *)(a1 + 44) + 60);
  LODWORD(v9) = v11 + 3;
  if ( (*(uint16_t *)(a1 + 30) & 0x2000) != 0 )
    v13 = (v12 >> 4) & 1;
  else
    v13 = (v12 >> 3) & 1;
  v22 = v11 + 3;
  if ( v13 || (v14 = (uint16_t *)v11[7], (*v14 & 0x8000) == 0) )
  {
    v8 = v11 + 3;
    HIDWORD(v9) = *(uint8_t *)(*(uint32_t *)off_11B890 + 1);
  }
  else
  {
    *v14 &= ~0x8000u;
    v15 = off_11B890;
    v16 = *(uint8_t *)(a1 + 50) - 4;
    *(uint8_t *)(a1 + 51) -= 4;
    *(uint8_t *)(a1 + 50) = v16;
    v17 = v11[9];
    v11[8] -= 4;
    v11[9] = v17 - 4;
    HIDWORD(v9) = *(uint8_t *)(*(uint32_t *)v15 + 1);
    v8 = v11 + 3;
  }
LABEL_21:
  v1[7 * v2 + 9] = v9;
  if ( !HIDWORD(v9) )
  {
LABEL_11:
    if ( (v8[14] & 0x200000) != 0 )
    {
      if ( !*(uint32_t *)(v9 + 4) )
      {
        v20 = dword_11B894 + 84 * v2;
        HIDWORD(v9) = 1;
        *(uint64_t *)(v20 + 4) = v9;
        *(uint32_t *)v20 = v8;
      }
    }
    else if ( !v8[1] )
    {
      v10 = (uint32_t *)(dword_11B894 + 84 * v2);
      v10[1] = 0;
      v10[2] = 0;
      *v10 = v8;
      LODWORD(v9) = 84 * v2;
    }
    return v9;
  }
  if ( !v8[1] )
  {
    *(uint32_t *)(dword_11B894 + 84 * v2) = v8;
    LODWORD(v9) = 84 * v2;
  }
  return v9;
}

