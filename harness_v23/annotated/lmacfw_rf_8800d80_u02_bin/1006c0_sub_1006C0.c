// v23 annotated: sub_1006C0 @ 0x1006c0
// Original: 1006c0_sub_1006C0.c
// Primary struct: <unclustered>
//
// sub_1006C0 @ 0x1006c0, size 238 bytes
// Doc: sub_12006C0 [unknown]: Complex helper: parses input/output buffer pointers with stack frame
// sub_12006C0 [unknown]: Complex helper: parses input/output buffer pointers with stack frame
int __fastcall sub_1006C0(int result, int a2, int a3, unsigned int a4)
{
  int v4; // r8
  unsigned int v5; // r12
  unsigned int v6; // r11
  int v7; // r7
  int v8; // r10
  int v9; // r10
  unsigned int v10; // r3
  unsigned int v11; // r4
  int v12; // r4
  int v13; // r5
  int v14; // r2
  int v15; // r5
  bool v16; // zf
  int v17; // r5
  int v18; // r5
  int v19; // r3
  _DWORD *v20; // r2
  int v21; // t1
  int v22; // [sp+4h] [bp-10h]

  v4 = result - 4;
  v5 = 16;
  v6 = 31;
  v22 = 0;
  do
  {
    v7 = 32 * v22;
    if ( ((a4 >> v22) & 1) != 0 )
    {
      if ( v5 - 15 <= v5 + 16 )
        v8 = 32;
      else
        v8 = 1;
      v9 = v8 + v7;
      v10 = 32 * v22;
      do
      {
        while ( 1 )
        {
          v14 = v10 >= v5 ? v10 - 16 : v10 + 16;
          v15 = *(_DWORD *)(result + 4 * v14);
          v11 = v14 + 1;
          if ( v15 != *(_DWORD *)(v4 + 64) )
            break;
          ++v10;
          *(_DWORD *)(a2 + 4 * v14) = v15;
          if ( v10 == v9 )
            goto LABEL_17;
        }
        if ( v11 > v6 )
          v11 = 32 * v22;
        v12 = *(_DWORD *)(result + 4 * v11);
        v13 = (unsigned __int8)v12;
        if ( (unsigned __int8)v12 <= 0x97u )
          v13 = (unsigned __int8)(v12 - 1);
        ++v10;
        *(_DWORD *)(a2 + 4 * v14) = ((unsigned __int8)v12
                                   - ((unsigned int)(((unsigned int)dword_1007B0
                                                    * (unsigned __int64)(unsigned int)(v13 + 10)) >> 32) >> 2))
                                  | v12 & 0xFFFFFF00;
      }
      while ( v10 != v9 );
    }
    else
    {
      if ( v5 - 15 <= v5 + 16 )
        v17 = 32;
      else
        v17 = 1;
      v18 = result - 4 + 4 * (v17 + v7);
      v19 = v4;
      do
      {
        v20 = (_DWORD *)(a2 + 4 - result + v19);
        v21 = *(_DWORD *)(v19 + 4);
        v19 += 4;
        *v20 = v21;
      }
      while ( v19 != v18 );
    }
LABEL_17:
    v16 = v22++ == 2;
    v4 += 128;
    v6 += 32;
    v5 += 32;
  }
  while ( !v16 );
  return result;
}

