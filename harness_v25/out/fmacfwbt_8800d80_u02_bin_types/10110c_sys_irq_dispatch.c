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

extern uint32_t off_101398;
extern uint32_t off_10139C;
extern uint32_t off_1013A0;
extern uint32_t off_1013A4;
extern uint32_t off_1013A8;
extern uint32_t off_1013AC;
extern uint32_t off_1013B0;
extern uint32_t off_1013B4;
extern uint32_t off_1013B8;
extern uint32_t off_1015FC;
extern uint32_t off_1015E4;
extern uint32_t dword_1015E8;
extern uint32_t dword_1015EC;
extern uint32_t dword_1015F0;
extern uint32_t off_1015E0;
extern uint32_t off_1013F0;
extern uint32_t off_1013C4;
extern uint32_t dword_1013E4;
extern uint32_t dword_1013E8;
extern uint32_t dword_1013EC;
extern uint32_t off_1013BC;
extern uint32_t dword_1015F4;
extern uint32_t dword_1015F8;
extern uint32_t dword_1013C0;
extern uint32_t dword_1013C8;
extern uint32_t dword_1013E0;
extern uint32_t dword_1013CC;
extern uint32_t off_1013D0;
extern uint32_t off_1013D4;
extern uint32_t off_1013D8;
extern uint32_t off_101584;
extern uint32_t dword_1013DC;
extern uint32_t dword_101588;
extern uint32_t off_101590;
extern uint32_t off_10158C;
extern uint32_t off_101594;
extern uint32_t off_101598;
extern uint32_t off_1015A0;
extern uint32_t off_10159C;
extern uint32_t off_1015A4;
extern uint32_t off_1015A8;
extern uint32_t off_1015AC;
extern uint32_t qword_1015D4;
extern uint32_t dword_1015DC;
extern uint32_t qword_1015C8;
extern uint32_t dword_1015D0;
extern uint32_t qword_1015B0;
extern uint32_t dword_1015B8;
extern uint32_t off_1015BC;
extern uint32_t off_1015C0;
extern uint32_t off_1015C4;

// sys_irq_dispatch @ 0x10110c, size 1142 bytes
// Doc: sys_irq_dispatch [ipc]: System interrupt dispatch reading MMIO registers 0x40344000-0x40344084
// sys_irq_dispatch [ipc]: System interrupt dispatch reading MMIO registers 0x40344000-0x40344084
uint32_t * sys_irq_dispatch(unsigned int a1)
{
  uint32_t *v1; // r2
  uint32_t *v2; // r3
  uint32_t *v3; // r5
  uint32_t *v4; // r4
  unsigned int *v5; // r6
  uint32_t *v6; // r1
  unsigned int *v7; // r5
  unsigned int *v8; // r3
  uint32_t *v9; // r4
  unsigned int v10; // r12
  int *v12; // r0
  int v13; // r3
  int *v14; // r8
  int *v15; // r7
  int v16; // r1
  int v17; // r2
  unsigned int v18; // lr
  int v19; // r10
  int v20; // r1
  unsigned int *v21; // r2
  unsigned int v22; // r0
  uint64_t v23; // r4
  uint32_t *v24; // r3
  unsigned int *v25; // r2
  int v26; // r2
  int v27; // r1
  int v28; // r5
  int v29; // r3
  int v30; // r2
  unsigned int *v31; // r0
  uint8_t *v32; // r4
  uint32_t *v33; // r2
  uint32_t *v34; // r0
  unsigned int v35; // r3
  unsigned int *v36; // r2
  unsigned int *v37; // r1
  uint64_t *v38; // r3
  uint64_t v39; // r0
  int v40; // r5
  uint8_t *v41; // r4
  uint32_t *v42; // r2
  uint32_t *result; // r0
  uint64_t *v44; // r3
  uint64_t v45; // r0
  uint64_t v46; // r0
  int v47; // r2
  int v48; // r2

  v1 = off_101398;
  v2 = off_10139C;
  *(uint32_t *)off_101398 &= ~0x400u;
  v3 = off_1013A0;
  v4 = off_1013A4;
  v5 = (unsigned int *)off_1013A8;
  *v1 &= ~0x800u;
  *v3 |= 4u;
  v6 = off_1013AC;
  *v4 |= 0x80000u;
  *v4 &= ~0x100000u;
  *v2 |= 0x400u;
  *v2 &= ~0x100u;
  *v2 |= 0x80u;
  v7 = (unsigned int *)off_1013B0;
  v1[16] |= 0x8000u;
  *v6 |= 1u;
  *v6 &= ~2u;
  v4[4] |= 0x40u;
  *v7 = *v7 & 0xFFC01FFF | 0x32000;
  v4[24] &= ~0x8000u;
  v4[24] |= 0x4000u;
  *v5 = *v5 & 0xFFF9FFFF | 0x20000;
  *(unsigned int *)((char *)v7 + 0xFFFFFFC0) = *(unsigned int *)((char *)v7 + 0xFFFFFFC0) & 0xFFFFE3FF | 0x800;
  v4[7] = v4[7] & 0xFC7FFFFF | 0x1000000;
  v8 = (unsigned int *)off_1013B4;
  *(unsigned int *)((char *)v7 + 0xFFFFFFBC) &= 0xFFFFC7FF;
  *v8 = *v8 & 0xFFFFF83F | 0x400;
  v1[16] = v1[16] & 0xFFFFE3FF | 0x1000;
  *v6 |= 0xC00u;
  v9 = off_1013B8;
  v1[16] = v1[16] & 0xFFFFFF87 | 0x48;
  v7 -= 1921;
  *v8 &= ~1u;
  *v7 |= 8u;
  *v7 |= 4u;
  *v8 &= ~2u;
  *v9 &= ~0x20000u;
  v10 = (uint16_t)(a1 - 5000);
  *v8 |= 0x20u;
  if ( v10 > 0xFA )
  {
    if ( a1 > 0x14C8 )
    {
      if ( a1 <= 0x15C2 )
      {
        v14 = (int *)off_1015FC;
        v15 = (int *)off_1015E4;
        v13 = dword_1015E8;
        v16 = dword_1015EC;
        v47 = dword_1015F0;
        *(uint32_t *)off_1015E0 = dword_1015E8;
        *v14 = v47;
        *v15 = v16;
        v18 = 0x80000000;
        v19 = 1610612736;
        goto LABEL_4;
      }
      if ( a1 <= 0x1612 )
      {
        v14 = (int *)off_1013F0;
        v15 = (int *)off_1013C4;
        v13 = dword_1013E4;
        v16 = dword_1013E8;
        v30 = dword_1013EC;
        *(uint32_t *)off_1013BC = dword_1013E4;
        *v14 = v30;
        *v15 = v16;
        v18 = 0;
        v19 = 1610612736;
        goto LABEL_4;
      }
      v12 = (int *)off_1015E0;
      v13 = dword_1015E8;
      v14 = (int *)off_1015FC;
      v15 = (int *)off_1015E4;
      v16 = dword_1015EC;
      if ( a1 <= 0x1662 )
      {
        v48 = dword_1015F4;
        *(uint32_t *)off_1015E0 = dword_1015E8;
        *v14 = v48;
        *v15 = v16;
        v18 = 0;
        v19 = 0x40000000;
        goto LABEL_4;
      }
      v17 = dword_1015F8;
    }
    else
    {
      v12 = (int *)off_1013BC;
      v13 = dword_1013C0;
      v14 = (int *)off_1013F0;
      v15 = (int *)off_1013C4;
      v16 = dword_1013C8;
      v17 = dword_1013E0;
    }
  }
  else
  {
    v12 = (int *)off_1013BC;
    v13 = dword_1013C0;
    v14 = (int *)off_1013F0;
    v15 = (int *)off_1013C4;
    v16 = dword_1013C8;
    v17 = dword_1013CC;
  }
  *v12 = v13;
  v18 = 0;
  *v14 = v17;
  *v15 = v16;
  v19 = 0;
LABEL_4:
  v20 = v16 + 4;
  v21 = (unsigned int *)v13;
  do
  {
    if ( v10 > 0x140 )
    {
      v22 = v21[1] & 0xFFFFFFFE;
      *v21 = *v21 & 0x1FFFFFFF | v19 | v18;
      v21[1] = v22;
      v23 = *(uint64_t *)(v20 - 4);
      LODWORD(v23) = v23 & 0x1FFFFFFF | v19 | v18;
      HIDWORD(v23) &= ~1u;
      *(uint64_t *)(v20 - 4) = v23;
    }
    v21 += 3;
    v20 += 12;
  }
  while ( (unsigned int *)(v13 + 192) != v21 );
  sub_102D10(1, 0, 16, v13);
  sub_102D10(1, 16, 16, *v14);
  sub_102D10(1, 32, 16, *v15);
  sub_1009A0(1, a1);
  v24 = off_1013D0;
  v25 = (unsigned int *)off_1013D4;
  *(uint32_t *)off_1013D0 |= 8u;
  *v24 |= 4u;
  *v25 = *v25 & 0xFFFC7FFF | 0x10000;
  *v25 = *v25 & 0xFFFF8FFF | 0x3000;
  if ( a1 > 0x1666 )
  {
    v28 = 10;
    v27 = 5;
  }
  else if ( a1 > 0x1616 )
  {
    v28 = 8;
    v27 = 4;
  }
  else if ( a1 > 0x15C6 )
  {
    v28 = 6;
    v27 = 3;
  }
  else
  {
    if ( a1 <= 0x1571 )
    {
      v26 = *(uint8_t *)off_1013D8;
      v27 = a1 > 0x1486;
      if ( a1 <= 0x1486 )
        v28 = 0;
      else
        v28 = 2;
      if ( v26 == 3 )
        goto LABEL_16;
      goto LABEL_24;
    }
    v28 = 4;
    v27 = 2;
  }
  v26 = *(uint8_t *)off_101584;
  if ( v26 == 3 )
  {
LABEL_16:
    v29 = dword_1013DC;
    goto LABEL_26;
  }
LABEL_24:
  v29 = dword_101588;
  if ( v26 != 7 )
    v29 = 0;
LABEL_26:
  v31 = (unsigned int *)off_101590;
  *(uint32_t *)off_10158C = *(uint32_t *)off_10158C & 0xFFFFFF00 | *(uint8_t *)(v29 + v28);
  v32 = off_101594;
  *v31 = *v31 & 0xFFFFFF00 | *(uint8_t *)(v29 + v28 + 1);
  if ( !v32[1] )
  {
    v33 = off_101598;
    v31[1918] &= 0xFFFFFC7F;
    *v33 &= ~0x8000u;
  }
  v34 = off_1015A0;
  v35 = *(uint32_t *)off_10159C & 0xFF00FFFF;
  if ( v27 <= 1 )
    v35 |= 0x1F0000u;
  *(uint32_t *)off_10159C = v35;
  v36 = (unsigned int *)off_1015A4;
  v37 = (unsigned int *)off_1015A8;
  *v34 &= ~0x4000u;
  *v36 = *v36 & 0xFFF8FFFF | 0x20000;
  *v36 = *v36 & 0xFFFFFFF0 | 8;
  *v37 = *v37 & 0xFFF1FFFF | 0x60000;
  if ( a1 <= 0x15E4 )
  {
    v44 = (uint64_t *)off_1015AC;
    if ( a1 <= 0x14D6 )
    {
      v46 = qword_1015D4;
      *((uint32_t *)off_1015AC + 2) = dword_1015DC;
      *v44 = v46;
      v40 = 0;
    }
    else
    {
      v45 = qword_1015C8;
      *((uint32_t *)off_1015AC + 2) = dword_1015D0;
      *v44 = v45;
      v40 = 1;
    }
  }
  else
  {
    v38 = (uint64_t *)off_1015AC;
    v39 = qword_1015B0;
    *((uint32_t *)off_1015AC + 2) = dword_1015B8;
    *v38 = v39;
    v40 = 2;
  }
  v41 = off_1015BC;
  if ( *(uint8_t *)off_1015BC != v40 )
    sub_102DA4(0);
  v42 = off_1015C0;
  *v41 = v40;
  while ( !*v42 )
    ;
  result = (uint32_t *)(*(uint32_t *)off_1015C4 & 1);
  if ( result )
    goto LABEL_40;
  if ( a1 - 5270 <= 0x32 || a1 - 5550 <= 0x64 )
  {
    result = mmio_status_check_n0d94();
LABEL_40:
    *(uint32_t *)off_1015C0 = 1;
    return result;
  }
  result = (uint32_t *)sub_100CD0(0);
  *(uint32_t *)off_1015C0 = 1;
  return result;
}

