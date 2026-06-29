// fwstruct annotate: 1312d8_sub_1312D8.c
// sub_1312D8 @ 0x1312d8, size 486 bytes
// Doc: sub_12312D8 [tx]: Parse header bytes and dispatch via table lookup
// sub_12312D8 [tx]: Parse header bytes and dispatch via table lookup
int __fastcall sub_1312D8(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  int v7; // r1
  _BYTE *v8; // r3
  _DWORD *v10; // r1
  _DWORD *v11; // r2
  _DWORD *v12; // r0
  _DWORD *v13; // r7
  int v14; // r4
  _DWORD *v15; // r2
  int v16; // r3
  int v17; // r1
  _DWORD *v18; // r2
  _DWORD *v19; // r0
  int v20; // r4
  _DWORD *v21; // r7
  _BYTE *v22; // r2
  int *v23; // r4
  int v24; // r3
  int v25; // r1
  int v26; // r0
  _DWORD *v27; // r2
  _DWORD *v28; // r0
  _DWORD *v29; // r4
  _DWORD *v30; // r2
  _DWORD *v31; // r7
  _DWORD *v32; // r0
  _DWORD *v33; // r3
  unsigned int *v34; // r1
  _DWORD *v35; // r2

  feature_guard_check(2, dword_1314C0, *a2, a2[1]);
  v7 = *a2;
  v8 = off_1314C8;
  **(_BYTE **)off_1314C4 = v7;
  v8[412] = a2[1];
  if ( v7 == 1 )
  {
    if ( v8[189] )
    {
      v27 = off_1314F8;
      v28 = off_1314D8;
      *(_DWORD *)off_1314D4 &= ~0x2000000u;
      *v27 |= 0x200000u;
      *v28 = 36;
    }
    else
    {
      v18 = off_1314D4;
      v19 = off_1314EC;
      v20 = *((unsigned __int8 *)off_1314EC + 18);
      v21 = off_1314D8;
      *(_DWORD *)off_1314D4 |= 0x2000000u;
      *v21 = 4;
      if ( !v20 )
      {
        *(_DWORD *)off_1314F0 = 1;
        v18[8202] &= 0xFFFBFFFE;
      }
      v22 = off_1314DC;
      if ( *((_BYTE *)off_1314DC + 28) )
      {
        if ( !*((_BYTE *)off_1314DC + 29) )
        {
          v23 = (int *)v19[2];
          if ( v23 )
          {
            while ( !*((_BYTE *)v23 + 108) || *((_BYTE *)v23 + 106) )
            {
              v23 = (int *)*v23;
              if ( !v23 )
                goto LABEL_21;
            }
            v24 = *((_DWORD *)off_1314E8 + 4);
            v25 = *(unsigned __int16 *)(*(_DWORD *)off_1314E4 + 54);
            v26 = dword_1314F4;
            *((_DWORD *)off_1314DC + 5) = v23;
            v22[29] = 4;
            timestamp_update(v26, v25 + v24);
            v23[1] |= 0x200u;
          }
        }
      }
    }
LABEL_21:
    *((_DWORD *)off_1314E0 + 20) |= 0x40000u;
  }
  else if ( v7 == 2 )
  {
    v10 = off_1314D0;
    v11 = off_1314D4;
    v12 = off_1314D8;
    v13 = off_1314DC;
    *(_DWORD *)off_1314D0 |= 0x10000u;
    v14 = v13[8];
    *v11 &= ~0x2000000u;
    *v12 = 63;
    v15 = off_1314E0;
    v10[10] &= ~1u;
    v15[20] &= ~0x40000u;
    if ( v14 && *(_BYTE *)(v14 + 108) )
    {
      v16 = *((_DWORD *)off_1314E8 + 4);
      v17 = *(unsigned __int16 *)(*(_DWORD *)off_1314E4 + 54);
      v13[5] = v14;
      *((_BYTE *)v13 + 29) = 4;
      timestamp_update((int)(v13 + 3), v17 + v16);
      *(_DWORD *)(v14 + 4) |= 0x200u;
      timestamp_remove(v14 + 24);
    }
  }
  else if ( !v7 && **(_BYTE **)off_1314CC == 3 )
  {
    v29 = off_1314D0;
    v30 = off_1314D4;
    v31 = off_1314D8;
    *(_DWORD *)off_1314D0 &= ~0x10000u;
    *v30 |= 0x2000000u;
    *v31 = 0;
    v32 = off_1314E0;
    v29[10] |= 1u;
    v32[20] |= 0x40000u;
    if ( (*v30 & 4) != 0 )
    {
      if ( v8[190] )
      {
        v33 = off_131500;
        *(_DWORD *)off_1314FC &= ~0x200u;
        *v33 &= ~1u;
        *v33 &= ~0x80u;
      }
      *(_DWORD *)off_131504 = 48;
      sub_117AB8();
      sub_128EA0();
    }
    if ( !*((_BYTE *)off_131508 + 36) )
    {
      v34 = (unsigned int *)off_131510;
      v35 = off_131514;
      *(_DWORD *)off_13150C &= ~0x40000u;
      *v34 = *v34 & 0xFFFFFFF0 | 8;
      *v35 |= 1u;
    }
  }
  sub_12CA10(5142, a4, a3);
  return 0;
}

