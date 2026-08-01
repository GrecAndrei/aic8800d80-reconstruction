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

extern uint32_t off_101478;
extern uint32_t off_10147C;
extern uint32_t off_101480;
extern uint32_t off_101484;
extern uint32_t off_101488;
extern uint32_t off_10148C;
extern uint32_t off_101490;
extern uint32_t off_101494;
extern uint32_t off_101688;
extern uint32_t off_10168C;
extern uint32_t dword_101690;
extern uint32_t dword_101694;
extern uint32_t off_101684;
extern uint32_t dword_1016A0;
extern uint32_t dword_1016A4;
extern uint32_t dword_101698;
extern uint32_t dword_10169C;
extern uint32_t off_10149C;
extern uint32_t off_1014A0;
extern uint32_t dword_1014BC;
extern uint32_t dword_1014C0;
extern uint32_t off_101498;
extern uint32_t dword_1014B4;
extern uint32_t dword_1014B8;
extern uint32_t dword_1014A4;
extern uint32_t dword_1014A8;
extern uint32_t off_1014AC;
extern uint32_t off_1014B0;
extern uint32_t dword_101630;
extern uint32_t off_101634;
extern uint32_t off_10162C;
extern uint32_t off_101638;
extern uint32_t off_10163C;
extern uint32_t off_101644;
extern uint32_t off_101640;
extern uint32_t off_101648;
extern uint32_t off_10164C;
extern uint32_t off_101650;
extern uint32_t qword_101678;
extern uint32_t dword_101680;
extern uint32_t qword_10166C;
extern uint32_t dword_101674;
extern uint32_t qword_101654;
extern uint32_t dword_10165C;
extern uint32_t off_101660;
extern uint32_t off_101664;
extern uint32_t off_101668;

// mmio_ahb_gate_release_n_60 @ 0x101260, size 972 bytes
uint32_t * mmio_ahb_gate_release_n_60(unsigned int a1)
{
  uint32_t *v1; // r2
  uint32_t *v2; // r5
  uint32_t *v3; // r4
  uint32_t *v4; // r3
  unsigned int *v5; // r6
  uint32_t *v6; // r1
  unsigned int *v7; // r5
  unsigned int *v8; // r3
  int *v10; // r6
  int *v11; // r5
  int v12; // r3
  int v13; // r2
  uint32_t *v14; // r3
  unsigned int *v15; // r2
  int v16; // r0
  int v17; // r6
  int v18; // r2
  int v19; // r2
  int v20; // r2
  unsigned int *v21; // r1
  int v22; // r5
  uint8_t *v23; // r2
  uint32_t *v24; // r2
  uint32_t *v25; // r1
  unsigned int v26; // r3
  uint32_t *v27; // r0
  unsigned int *v28; // r2
  uint64_t *v29; // r3
  uint64_t v30; // r0
  int v31; // r6
  uint8_t *v32; // r5
  uint32_t *v33; // r2
  uint32_t *result; // r0
  uint64_t *v35; // r3
  uint64_t v36; // r0
  uint64_t v37; // r0
  int v38; // r2
  int v39; // r2

  v1 = off_101478;
  *(uint32_t *)off_101478 &= ~0x400u;
  v2 = off_10147C;
  v3 = off_101480;
  v4 = off_101484;
  v5 = (unsigned int *)off_101488;
  *v1 &= ~0x800u;
  *v2 |= 4u;
  v6 = off_10148C;
  *v3 |= 0x80000u;
  *v3 &= ~0x100000u;
  *v4 |= 0x400u;
  *v4 &= ~0x100u;
  *v4 |= 0x80u;
  v7 = (unsigned int *)off_101490;
  v1[16] |= 0x8000u;
  *v6 |= 1u;
  *v6 &= ~2u;
  v3[4] |= 0x40u;
  *v7 = *v7 & 0xFFC01FFF | 0x32000;
  v3[24] &= ~0x8000u;
  v3[24] |= 0x4000u;
  *v5 = *v5 & 0xFFF9FFFF | 0x40000;
  *(unsigned int *)((char *)v7 + 0xFFFFFFC0) = *(unsigned int *)((char *)v7 + 0xFFFFFFC0) & 0xFFFFE3FF | 0x800;
  v3[7] = v3[7] & 0xFC7FFFFF | 0x1000000;
  v8 = (unsigned int *)off_101494;
  *(unsigned int *)((char *)v7 + 0xFFFFFFBC) &= 0xFFFFC7FF;
  *v8 = *v8 & 0xFFFFF83F | 0x400;
  v1[16] = v1[16] & 0xFFFFE3FF | 0x1000;
  *v6 |= 0xC00u;
  v1[16] = v1[16] & 0xFFFFFF87 | 0x48;
  v7 -= 1921;
  *v8 &= ~1u;
  *v7 |= 8u;
  *v7 |= 4u;
  *v8 &= ~2u;
  *(unsigned int *)((char *)v5 + 0xFFFFFFD8) &= ~0x20000u;
  *v8 |= 0x20u;
  if ( a1 - 5000 > 0xFA )
  {
    if ( a1 > 0x14C8 )
    {
      if ( a1 <= 0x15C2 )
      {
        v10 = (int *)off_101688;
        v11 = (int *)off_10168C;
        v12 = dword_101690;
        v38 = dword_101694;
        *(uint32_t *)off_101684 = dword_101690;
        *v10 = v12;
        *v11 = v38;
      }
      else if ( a1 > 0x1612 )
      {
        v10 = (int *)off_101688;
        v11 = (int *)off_10168C;
        if ( a1 > 0x1662 )
        {
          v12 = dword_1016A0;
          v39 = dword_1016A4;
          *(uint32_t *)off_101684 = dword_1016A0;
        }
        else
        {
          v12 = dword_101698;
          v39 = dword_10169C;
          *(uint32_t *)off_101684 = dword_101698;
        }
        *v10 = v12;
        *v11 = v39;
      }
      else
      {
        v10 = (int *)off_10149C;
        v11 = (int *)off_1014A0;
        v12 = dword_1014BC;
        v19 = dword_1014C0;
        *(uint32_t *)off_101498 = dword_1014BC;
        *v10 = v12;
        *v11 = v19;
      }
    }
    else
    {
      v10 = (int *)off_10149C;
      v11 = (int *)off_1014A0;
      v12 = dword_1014B4;
      v18 = dword_1014B8;
      *(uint32_t *)off_101498 = dword_1014B4;
      *v10 = v12;
      *v11 = v18;
    }
  }
  else
  {
    v10 = (int *)off_10149C;
    v11 = (int *)off_1014A0;
    v12 = dword_1014A4;
    v13 = dword_1014A8;
    *(uint32_t *)off_101498 = dword_1014A4;
    *v10 = v12;
    *v11 = v13;
  }
  uart_send_data(1, 0, 16, v12);
  uart_send_data(1, 16, 16, *v11);
  uart_send_data(1, 32, 16, *v10);
  sdio_irq_enable(1, a1);
  v14 = off_1014AC;
  v15 = (unsigned int *)off_1014B0;
  *(uint32_t *)off_1014AC |= 8u;
  *v14 |= 4u;
  *v15 = *v15 & 0xFFFC7FFF | 0x10000;
  *v15 = *v15 & 0xFFFF8FFF | 0x3000;
  if ( a1 > 0x1666 )
  {
    v17 = 10;
    v16 = 5;
  }
  else if ( a1 > 0x1616 )
  {
    v17 = 8;
    v16 = 4;
  }
  else if ( a1 > 0x15C6 )
  {
    v17 = 6;
    v16 = 3;
  }
  else if ( a1 > 0x1571 )
  {
    v17 = 4;
    v16 = 2;
  }
  else
  {
    v16 = a1 > 0x1486;
    if ( a1 <= 0x1486 )
      v17 = 0;
    else
      v17 = 2;
  }
  v20 = dword_101630;
  v21 = (unsigned int *)off_101634;
  *(uint32_t *)off_10162C = *(uint32_t *)off_10162C & 0xFFFFFF00 | *(uint8_t *)(dword_101630 + v17);
  v22 = *(uint8_t *)(v20 + v17 + 1);
  v23 = off_101638;
  *v21 = *v21 & 0xFFFFFF00 | v22;
  if ( !v23[1] )
  {
    v24 = off_10163C;
    v21[1918] &= 0xFFFFFC7F;
    *v24 &= ~0x8000u;
  }
  v25 = off_101644;
  v26 = *(uint32_t *)off_101640 & 0xFF00FFFF;
  if ( v16 <= 1 )
    v26 |= 0x1F0000u;
  v27 = off_101648;
  *(uint32_t *)off_101640 = v26;
  v28 = (unsigned int *)off_10164C;
  *v27 &= ~0x4000u;
  *v28 = *v28 & 0xFFF8FFFF | 0x20000;
  *v28 = *v28 & 0xFFFFFFF0 | 8;
  *v25 |= 0xE0000u;
  if ( a1 <= 0x15E4 )
  {
    v35 = (uint64_t *)off_101650;
    if ( a1 <= 0x14D6 )
    {
      v37 = qword_101678;
      *((uint32_t *)off_101650 + 2) = dword_101680;
      *v35 = v37;
      v31 = 0;
    }
    else
    {
      v36 = qword_10166C;
      *((uint32_t *)off_101650 + 2) = dword_101674;
      *v35 = v36;
      v31 = 1;
    }
  }
  else
  {
    v29 = (uint64_t *)off_101650;
    v30 = qword_101654;
    *((uint32_t *)off_101650 + 2) = dword_10165C;
    *v29 = v30;
    v31 = 2;
  }
  v32 = off_101660;
  if ( *(uint8_t *)off_101660 != v31 )
    hci_send_command(0);
  v33 = off_101664;
  *v32 = v31;
  while ( !*v33 )
    ;
  result = (uint32_t *)(*(uint32_t *)off_101668 & 1);
  if ( result )
    goto LABEL_30;
  if ( a1 - 5270 <= 0x32 || a1 - 5550 <= 0x64 )
  {
    result = rf_config_read_b();
LABEL_30:
    *(uint32_t *)off_101664 = 1;
    return result;
  }
  result = (uint32_t *)rf_config_read_a(0);
  *(uint32_t *)off_101664 = 1;
  return result;
}

