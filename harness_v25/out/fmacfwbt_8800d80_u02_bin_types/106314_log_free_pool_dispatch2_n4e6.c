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

extern uint32_t dword_1063A8;
extern uint32_t dword_1063AC;
extern uint32_t off_1063B4;
extern uint32_t off_1063B0;
extern uint32_t dword_1063B8;

// log_free_pool_dispatch2_n4e6 @ 0x106314, size 146 bytes
// Doc: log_free_pool_dispatch2_n4e6 [util]: Returns via pop and dispatches log/free-pool branch on slot byte
// log_free_pool_dispatch2_n4e6 [util]: Returns via pop and dispatches log/free-pool branch on slot byte
int  log_free_pool_dispatch2_n4e6(int a1, int a2)
{
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int *v13; // r4
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r0
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r6
  int v26; // r2
  uint8_t *v27; // r3
  int v28; // r1
  unsigned int *v29; // r4
  int v30; // r3
  int v31; // r1
  int v33; // [sp+0h] [bp-6Ch]
  int v34; // [sp+4h] [bp-68h]
  int v35; // [sp+8h] [bp-64h]
  int v36; // [sp+Ch] [bp-60h]
  int v37; // [sp+10h] [bp-5Ch]
  int v38; // [sp+14h] [bp-58h]
  int v39; // [sp+18h] [bp-54h]
  int v40; // [sp+1Ch] [bp-50h]
  int v41; // [sp+20h] [bp-4Ch]
  int v42; // [sp+24h] [bp-48h]
  int v43; // [sp+28h] [bp-44h]
  int v44; // [sp+2Ch] [bp-40h]
  int v45; // [sp+30h] [bp-3Ch]
  int v46; // [sp+34h] [bp-38h]
  int v47; // [sp+38h] [bp-34h]
  int v48; // [sp+3Ch] [bp-30h]
  int v49; // [sp+40h] [bp-2Ch]
  int v50; // [sp+44h] [bp-28h]
  int v51; // [sp+48h] [bp-24h]
  int v52; // [sp+4Ch] [bp-20h]
  int v53; // [sp+50h] [bp-1Ch]
  int v54; // [sp+54h] [bp-18h]
  int v55; // [sp+58h] [bp-14h]
  int v56; // [sp+5Ch] [bp-10h]
  int v57; // [sp+60h] [bp-Ch]
  int v58; // [sp+64h] [bp-8h]
  uint8_t v59[4]; // [sp+68h] [bp-4h] BYREF

  v4 = *(uint32_t *)(dword_1063A8 + 4);
  v5 = *(uint32_t *)(dword_1063A8 + 8);
  v6 = *(uint32_t *)(dword_1063A8 + 12);
  v33 = *(uint32_t *)dword_1063A8;
  v34 = v4;
  v35 = v5;
  v36 = v6;
  v7 = *(uint32_t *)(dword_1063A8 + 20);
  v8 = *(uint32_t *)(dword_1063A8 + 24);
  v9 = *(uint32_t *)(dword_1063A8 + 28);
  v37 = *(uint32_t *)(dword_1063A8 + 16);
  v38 = v7;
  v39 = v8;
  v40 = v9;
  v10 = *(uint32_t *)(dword_1063A8 + 36);
  v11 = *(uint32_t *)(dword_1063A8 + 40);
  v12 = *(uint32_t *)(dword_1063A8 + 44);
  v41 = *(uint32_t *)(dword_1063A8 + 32);
  v42 = v10;
  v43 = v11;
  v44 = v12;
  v13 = (int *)(dword_1063A8 + 48 + 4);
  v45 = *(uint32_t *)(dword_1063A8 + 48);
  v14 = *v13;
  v15 = v13[1];
  v16 = v13[2];
  v17 = v13[3];
  v13 += 4;
  v46 = v14;
  v47 = v15;
  v48 = v16;
  v49 = v17;
  v18 = *v13;
  v19 = v13[1];
  v20 = v13[2];
  v21 = v13[3];
  v13 += 4;
  v50 = v18;
  v51 = v19;
  v52 = v20;
  v53 = v21;
  v22 = v13[1];
  v23 = v13[2];
  v24 = v13[3];
  v54 = *v13;
  v55 = v22;
  v56 = v23;
  v57 = v24;
  v25 = *(uint32_t *)(a1 + 4 * a2 + 140);
  v58 = v13[4];
  feature_guard_sdio(1, dword_1063AC);
  if ( v25 > 25 )
    v26 = 12;
  else
    v26 = (v25 / 2) & ~((v25 / 2) >> 31);
  v27 = &v59[4 * v26];
  v28 = *((uint32_t *)v27 - 26);
  v29 = (unsigned int *)off_1063B4;
  v30 = *((uint32_t *)v27 - 13);
  *(uint32_t *)off_1063B0 = (8 * v28) & 0x38 | *(uint32_t *)off_1063B0 & 0xFFFFFFC7;
  v31 = dword_1063B8;
  *v29 = (4 * v30) & 0x1C | *v29 & 0xFFFFFFE3;
  return feature_guard_sdio(1, v31);
}

