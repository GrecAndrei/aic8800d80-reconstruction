// v23 annotated: sub_102BB0 @ 0x102bb0
// Original: 102bb0_sub_102BB0.c
// Primary struct: <unclustered>
//
// sub_102BB0 @ 0x102bb0, size 358 bytes
int __fastcall sub_102BB0(int a1, unsigned __int16 *a2)
{
  unsigned int v2; // r7
  unsigned int v4; // r11
  int v5; // r9
  int v6; // r8
  unsigned int v7; // r4
  unsigned int *v8; // r6
  int v9; // r5
  unsigned int v10; // r4
  int v11; // t1
  int v12; // r1
  unsigned int v13; // r4
  int v14; // r3
  int result; // r0
  unsigned __int64 *v16; // r3
  char *v17; // r12
  int v18; // r6
  char *v19; // r7
  int v20; // r4
  int v21; // t1
  unsigned __int16 *v22; // r1
  int v23; // r3
  int v24; // r5
  int v25; // r1
  __int64 v26; // r2
  int v27; // [sp+Ch] [bp-28h]
  unsigned __int64 v29; // [sp+1Ch] [bp-18h] BYREF
  int v30; // [sp+24h] [bp-10h]
  __int64 v31; // [sp+28h] [bp-Ch]

  while ( !*(_DWORD *)off_102D18 )
    ;
  v4 = 0;
  sub_102ADC(0);
  v5 = dword_102D48;
  v6 = dword_102D40;
  v27 = 0;
  while ( ((1 << v4) & a1) == 0 )
  {
    v7 = (unsigned __int16)v4;
    if ( (unsigned __int16)v4 == 5 )
      goto LABEL_10;
LABEL_4:
    ++v4;
  }
  v8 = (unsigned int *)(dword_102D1C + (v4 << 9));
  v9 = 0;
  v2 = (unsigned int)(a2 - 1);
  do
  {
    v10 = *v8;
    sub_11F74C(0x2000, v5, v4, v9, (unsigned __int16)(*v8 >> 11));
    v11 = *(unsigned __int16 *)(v2 + 2);
    v2 += 2;
    v12 = dword_102D20;
    v13 = v10 & v6 | (v11 << 11);
    *v8 = v13;
    v8 += 8;
    v14 = v9++;
    sub_11F74C(0x2000, v12, v4, v14, (unsigned __int16)(v13 >> 11));
  }
  while ( v9 != 16 );
  if ( v4 <= 1 )
    goto LABEL_4;
  v7 = (unsigned __int16)v4;
  v27 = 1;
  if ( (unsigned __int16)v4 != 5 )
    goto LABEL_4;
LABEL_10:
  result = sub_102B40(0);
  *(_DWORD *)off_102D18 = 1;
  if ( v27 )
  {
    if ( (a1 & 0x80) != 0 )
      v2 = 3;
    else
      v7 = 3;
    if ( (a1 & 0x80) == 0 )
      v2 = 0;
    if ( (*(_DWORD *)off_102D24 & 0x8000000) == 0 || (*(_DWORD *)off_102D28 & 0x400) != 0 )
      v16 = (unsigned __int64 *)off_102D44;
    else
      v16 = (unsigned __int64 *)off_102D2C;
    v29 = *v16;
    v25 = *((_DWORD *)v16 + 2);
    v26 = *(unsigned __int64 *)((char *)v16 + 12);
    v30 = v25;
    v31 = v26;
  }
  else
  {
    result = 0;
    v30 = dword_102D34;
    v29 = __PAIR64__(dword_102D30, dword_102D38);
    v31 = (unsigned int)dword_102D3C;
    if ( (a1 & 0x80) != 0 )
      v7 = 4;
    else
      v7 = 2;
    if ( (a1 & 0x80) != 0 )
      v2 = 2;
    else
      v2 = 0;
  }
  if ( v2 < v7 )
  {
    v17 = (char *)&v29 + 4 * v2 + 4 * (unsigned __int16)(v7 - 1 - v2) + 4;
    v18 = dword_102D40;
    v19 = (char *)&v29 + 4 * v2;
    do
    {
      v21 = *(_DWORD *)v19;
      v19 += 4;
      v20 = v21;
      v22 = a2;
      v23 = v21;
      v24 = v21 + 320;
      do
      {
        if ( v20 )
        {
          result = *v22;
          *(_DWORD *)(v23 + 16) = *(_DWORD *)(v23 + 16) & v18 | (result << 11);
        }
        v23 += 20;
        ++v22;
      }
      while ( v24 != v23 );
    }
    while ( v19 != v17 );
  }
  return result;
}

