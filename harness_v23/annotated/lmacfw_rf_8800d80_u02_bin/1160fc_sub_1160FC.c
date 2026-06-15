// v23 annotated: sub_1160FC @ 0x1160fc
// Original: 1160fc_sub_1160FC.c
// Primary struct: <unclustered>
//
// sub_1160FC @ 0x1160fc, size 502 bytes
int __fastcall sub_1160FC(int a1, int a2)
{
  unsigned __int8 **v2; // r11
  int v3; // r10
  int v6; // r1
  int v7; // r2
  int v8; // r4
  int *v9; // r5
  int v11; // r3
  int v12; // r2
  int v13; // r2
  int v14; // r1
  int v15; // r8
  int v16; // r0
  int v17; // r12
  int v18; // r9
  __int16 *v19; // lr
  unsigned int v20; // r1
  int v21; // r2
  int *v22; // r3
  int v23; // r1
  int v24; // r3
  _BYTE *v25; // r3
  int *v26; // r8
  int v27; // r0
  int v28; // r1
  int v29; // r3
  int v30; // r2
  __int16 v31; // [sp+4h] [bp-10h]
  int v32; // [sp+8h] [bp-Ch] BYREF
  int v33; // [sp+Ch] [bp-8h]

  v2 = (unsigned __int8 **)off_116318;
  v3 = dword_11631C;
  while ( 1 )
  {
    v8 = sub_11E7AC(a2);
    if ( !v8 )
      break;
    while ( 1 )
    {
      v9 = *(int **)(v8 + 32);
      if ( *(_DWORD *)(v8 + 24) )
      {
        *v9 = 2080374784;
      }
      else if ( *v9 >= 0 )
      {
        *v9 = 0x40000000;
      }
      if ( *(_WORD *)(v8 + 4) )
        break;
      sub_11660C(v8, v6, v7);
      v8 = sub_11E7AC(a2);
      if ( !v8 )
        return sub_116654();
    }
    v11 = *v9;
    v12 = *(_DWORD *)(v8 + 40);
    *v9 |= 0x800000u;
    if ( v12 < 0 )
    {
      v14 = **v2;
      switch ( v14 )
      {
        case 2:
          v15 = sub_1132C0();
          if ( v15 )
          {
            if ( *(_DWORD *)off_1162F8 )
            {
              v16 = sub_11E7AC(off_1162F8);
              *(_BYTE *)v15 = 8;
              *(_BYTE *)(v15 + 1) = 0;
              *(_WORD *)(v15 + 2) = 18;
              v17 = *(_DWORD *)(v8 + 40) & 0x3FFFFFFF;
              v18 = v16;
              v32 = *v9 & 0xF;
              v33 = v17;
              sub_1282E8(v15 + 4, &v32, 8);
              v19 = (__int16 *)off_116320;
              v20 = *(unsigned __int16 *)off_116320;
              if ( v20 > 0x186 )
              {
                v21 = 0;
                LOWORD(v20) = 0;
                v31 = 1;
              }
              else
              {
                v31 = v20 + 1;
                v21 = 8 * v20;
              }
              v22 = (int *)off_1162FC;
              *(_WORD *)(v18 + 12) = v20;
              v23 = *v22;
              v24 = dword_116300;
              *(_DWORD *)(v23 + v21 + 4) = v15;
              *(_DWORD *)(v23 + v21) = v24 & *(_DWORD *)(v23 + v21) | 0x400000C;
              v25 = off_116304;
              *v19 = v31;
              ++v25[3074];
              *(_DWORD *)(v18 + 4) = v23 + v21;
              *(_BYTE *)(v18 + 14) = 1;
              *(_DWORD *)v18 = 0;
              *(_DWORD *)(v18 + 8) = 12;
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(_DWORD *)off_116308 = 1;
              }
              v26 = (int *)off_116324;
              ++*(_DWORD *)off_116324;
              sub_11F504(v3, v8);
              v27 = sub_11E724(dword_11630C);
              sub_112D84(v27, v28);
              if ( *v26 )
              {
                v29 = *v26 - 1;
                v30 = *(_DWORD *)off_116308;
                *v26 = v29;
                if ( !v29 )
                {
                  if ( v30 )
                    __enable_irq();
                }
              }
            }
            else
            {
              sub_10DA6C(dword_116310);
            }
          }
          else
          {
            sub_10DA6C(dword_116314);
          }
          break;
        case 1:
          v32 = v11 & 0xF;
          v33 = v12 & 0x3FFFFFFF;
          sub_110BF8(18, (int)&v32, 8);
          sub_11F504(v3, v8);
          break;
        case 3:
          **(_DWORD **)off_1162F4 = v11 & 0xF;
          sub_10CF2C();
          break;
      }
    }
    sub_115314(v8);
    sub_121AF0(a1, v8, v13);
  }
  return sub_116654();
}

