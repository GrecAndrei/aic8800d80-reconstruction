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


extern uint32_t dword_10766C;
extern uint32_t off_107668;
extern uint32_t off_107670;
extern uint32_t off_107678;

// rf_load_tx_config @ 0x1075b8, size 176 bytes
int  rf_load_tx_config(int a1)
{
  int v2; // r1
  int v3; // r2
  int v4; // r3
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r8
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r6
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r6
  int *v23; // r7
  unsigned int *v24; // lr
  int v25; // r4
  int v26; // r8
  unsigned int *v27; // r5
  int v28; // r0
  int v30; // [sp+0h] [bp-60h]
  int v31; // [sp+4h] [bp-5Ch]
  int v32; // [sp+8h] [bp-58h]
  int v33; // [sp+Ch] [bp-54h]
  int v34; // [sp+10h] [bp-50h]
  int v35; // [sp+14h] [bp-4Ch]
  int v36; // [sp+18h] [bp-48h]
  int v37; // [sp+1Ch] [bp-44h]
  int v38; // [sp+20h] [bp-40h]
  int v39; // [sp+24h] [bp-3Ch]
  int v40; // [sp+28h] [bp-38h]
  int v41; // [sp+2Ch] [bp-34h]
  int v42; // [sp+30h] [bp-30h]
  int v43; // [sp+34h] [bp-2Ch]
  int v44; // [sp+38h] [bp-28h]
  int v45; // [sp+3Ch] [bp-24h]
  int v46; // [sp+40h] [bp-20h]
  int v47; // [sp+44h] [bp-1Ch]
  int v48; // [sp+48h] [bp-18h]
  int v49; // [sp+4Ch] [bp-14h]
  int v50; // [sp+50h] [bp-10h]
  int v51; // [sp+54h] [bp-Ch]
  int v52; // [sp+58h] [bp-8h]
  int v53; // [sp+5Ch] [bp-4h]
  int v54; // [sp+60h] [bp+0h] BYREF

  v2 = ((uint32_t *)(uintptr_t)off_107668)[99];
  v3 = ((uint32_t *)(uintptr_t)off_107668)[100];
  v4 = ((uint32_t *)(uintptr_t)off_107668)[101];
  v30 = ((uint32_t *)(uintptr_t)off_107668)[98];
  v31 = v2;
  v32 = v3;
  v33 = v4;
  v5 = ((uint32_t *)(uintptr_t)off_107668)[103];
  v6 = ((uint32_t *)(uintptr_t)off_107668)[104];
  v7 = ((uint32_t *)(uintptr_t)off_107668)[105];
  v34 = ((uint32_t *)(uintptr_t)off_107668)[102];
  v35 = v5;
  v36 = v6;
  v37 = v7;
  v8 = ((uint32_t *)(uintptr_t)off_107668)[107];
  v9 = ((uint32_t *)(uintptr_t)off_107668)[108];
  v10 = ((uint32_t *)(uintptr_t)off_107668)[109];
  v38 = ((uint32_t *)(uintptr_t)off_107668)[106];
  v39 = v8;
  v40 = v9;
  v41 = v10;
  v11 = ((uint32_t *)(uintptr_t)off_107668)[111];
  v12 = ((uint32_t *)(uintptr_t)off_107668)[112];
  v13 = ((uint32_t *)(uintptr_t)off_107668)[113];
  v42 = ((uint32_t *)(uintptr_t)off_107668)[110];
  v43 = v11;
  v44 = v12;
  v45 = v13;
  v14 = *(uint32_t *)(a1 + 8);
  v15 = ((uint32_t *)(uintptr_t)off_107668)[115];
  v16 = ((uint32_t *)(uintptr_t)off_107668)[116];
  v17 = ((uint32_t *)(uintptr_t)off_107668)[117];
  v18 = ((uint64_t)(dword_10766C * (uint64_t)*(int *)(a1 + 4)) >> 32) - (*(int *)(a1 + 4) >> 31);
  v46 = ((uint32_t *)(uintptr_t)off_107668)[114];
  v47 = v15;
  v48 = v16;
  v49 = v17;
  if ( v18 >= (int)(((uint64_t)(dword_10766C * (uint64_t)v14) >> 32) - (v14 >> 31)) )
    v18 = ((uint64_t)(dword_10766C * (uint64_t)v14) >> 32) - (v14 >> 31);
  v19 = ((uint32_t *)(uintptr_t)off_107668)[119];
  v20 = ((uint32_t *)(uintptr_t)off_107668)[120];
  v21 = ((uint32_t *)(uintptr_t)off_107668)[121];
  v22 = v18 & ~(v18 >> 31);
  v23 = &v54 + v22;
  v24 = (unsigned int *)off_107678;
  v25 = *(v23 - 24);
  v26 = *(uint32_t *)off_107678;
  v50 = ((uint32_t *)(uintptr_t)off_107668)[118];
  v51 = v19;
  v52 = v20;
  v53 = v21;
  v27 = (unsigned int *)off_107670;
  v28 = *(v23 - 12);
  *(uint32_t *)(a1 + 8) = 3 * v22;
  *v24 = (v25 << 12) & 0x7000 | v26 & 0xFFFF8FFF;
  *v27 |= 0x400u;
  *v27 = (v28 << 8) & 0x300 | *v27 & 0xFFFFFCFF;
  return state_check_feature(1, "index=%d shift_idx=%d\n", v22, 3 * v22);
}
