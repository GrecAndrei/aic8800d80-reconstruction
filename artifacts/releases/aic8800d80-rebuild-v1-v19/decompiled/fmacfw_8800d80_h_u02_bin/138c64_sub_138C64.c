// sub_138C64 @ 0x138c64, size 554 bytes
int __fastcall sub_138C64(unsigned int a1, int a2, int a3, int a4)
{
  _DWORD *v4; // r8
  unsigned int v5; // r4
  int v8; // r5
  _DWORD *v9; // r6
  int v10; // r1
  int v11; // r1
  __int16 v12; // r2
  int v13; // r0
  unsigned int v14; // r5
  unsigned int v15; // r4
  bool v16; // cc
  int v17; // r1
  __int16 **v18; // r10
  __int16 **v19; // r12
  char *v20; // r0
  int v21; // r1
  __int64 v22; // r2
  __int16 v23; // r5
  __int16 v24; // lr
  signed int v25; // r3
  _BYTE *v26; // r2
  int v27; // r3
  int v28; // r10
  _BYTE *v29; // r5
  int v30; // lr
  _BYTE *v32; // r5
  char *v33; // r3
  char *v34; // r2
  int v35; // r6
  _BYTE *v36; // r3
  char *v37; // r2
  _BYTE *v38; // r5
  int v39; // r0
  int v40; // r1
  int v41; // r2
  __int64 v42; // r4
  int v43; // t1
  int v44; // [sp+Ch] [bp-10h]
  __int64 v45; // [sp+10h] [bp-Ch] BYREF

  v4 = off_138E9C;
  v5 = a1;
  if ( a3 )
  {
    sub_1334A4(
      a2,
      (_DWORD *)(*((_DWORD *)off_138E9C + 8) + 88),
      (int)off_138E9C + 36,
      (unsigned __int16 *)off_138E9C + 21,
      *((_BYTE *)off_138E9C + 7));
    v11 = *((unsigned __int8 *)v4 + 8);
    v9 = *(_DWORD **)(v5 + 28);
    LOWORD(v5) = *(_WORD *)(v5 + 48) - v11;
    v12 = *((unsigned __int8 *)v4 + 8);
  }
  else
  {
    v8 = *((unsigned __int8 *)off_138E9C + 8);
    v9 = *(_DWORD **)(a1 + 28);
    v5 = (unsigned __int16)(*(_WORD *)(a1 + 48) - v8);
    v10 = a2 + 16;
    if ( a4 && v5 <= 7 )
    {
      v44 = v10;
      v32 = (_BYTE *)(v8 + v9[2]);
      sub_1334F0((_DWORD *)a2, v10, v5);
      v33 = (char *)&v45;
      v34 = (char *)&v45 + (unsigned __int8)(8 - v5);
      do
      {
        *v33 = v33[v44 + v5 - (_DWORD)&v45];
        ++v33;
      }
      while ( v34 != v33 );
      v35 = 8 - (unsigned __int8)(8 - v5);
      if ( v35 )
      {
        v36 = v32;
        v37 = (char *)(v34 - v32);
        v38 = &v32[v35];
        do
        {
          v36[(_DWORD)v37] = *v36;
          ++v36;
        }
        while ( v38 != v36 );
      }
      goto LABEL_36;
    }
    sub_1334F0((_DWORD *)a2, v10, 8u);
    v11 = *((unsigned __int8 *)v4 + 8);
    v12 = *((unsigned __int8 *)v4 + 8);
  }
  v13 = v9[2];
  v14 = (unsigned __int16)(v5 - 8);
  v15 = (unsigned __int16)(v9[3] + 1 - v13);
  v16 = (int)(v11 + v14) <= (int)v15;
  v17 = v11 + v13;
  if ( v16 )
  {
    v15 = (unsigned __int16)(v12 + v14);
LABEL_11:
    sub_1334F0((_DWORD *)a2, v17, v14);
  }
  else
  {
    v18 = (__int16 **)off_138EA0;
    while ( 1 )
    {
      v14 = (unsigned __int16)(v14 + v12 - v15);
      sub_1334F0((_DWORD *)a2, v17, (unsigned __int16)(v15 - v12));
      v12 = 0;
      if ( !(_WORD)v14 )
        break;
      v9 = (_DWORD *)v9[1];
      if ( **v18 < 0 && !v9 )
      {
        sub_12F2C8(dword_138E94, dword_138E90, 963);
        return 0;
      }
      v17 = v9[2];
      v15 = (unsigned __int16)(v9[3] + 1 - v17);
      if ( v15 >= (unsigned __int16)v14 )
      {
        v15 = (unsigned __int16)v14;
        goto LABEL_11;
      }
    }
  }
  v19 = (__int16 **)off_138EA0;
  v20 = (char *)&v45;
  v21 = 8;
  while ( 1 )
  {
    v22 = *((_QWORD *)v9 + 1);
    v23 = v22;
    v24 = WORD2(v22) + 1;
    v25 = (unsigned __int16)(WORD2(v22) + 1 - v22);
    v26 = (_BYTE *)(v22 + v15);
    if ( (int)(v21 + v15) <= v25 )
      break;
    v27 = (unsigned __int16)(v25 - v15);
    v28 = v27 - 1;
    if ( v27 )
    {
      v21 = (unsigned __int16)(v21 + v15 + v23 - v24);
      goto LABEL_16;
    }
    v21 = (unsigned __int16)(v23 + v21 + v15 - v24);
LABEL_19:
    v9 = (_DWORD *)v9[1];
    v15 = 0;
    if ( **v19 < 0 && !v9 )
    {
      sub_12F2C8(dword_138E94, dword_138E90, 1005);
      return 0;
    }
  }
  v27 = v21;
  v28 = v21 - 1;
  v21 = 0;
LABEL_16:
  v29 = &v26[v28 + 1];
  v30 = v20 - v26;
  do
  {
    v26[v30] = *v26;
    ++v26;
  }
  while ( v26 != v29 );
  v20 += v27;
  if ( v21 )
    goto LABEL_19;
  if ( !a4 )
  {
    *(_QWORD *)(a2 + 16) = v45;
    return 1;
  }
LABEL_36:
  sub_13362C(a2);
  if ( v45 == *(_QWORD *)a2 )
    return 1;
  v39 = sub_12C7EC(5126, 13, 5, 0x18u);
  v40 = v4[6];
  v41 = dword_138E98 + 696 * *((unsigned __int8 *)v4 + 9);
  v42 = *((_QWORD *)v4 + 2);
  v43 = *(_DWORD *)(v41 + 38);
  *(_WORD *)(v39 + 4) = *(_WORD *)(v41 + 42);
  *(_QWORD *)(v39 + 8) = v42;
  *(_DWORD *)v39 = v43;
  *(_BYTE *)(v39 + 18) = *((_BYTE *)v4 + 10);
  *(_BYTE *)(v39 + 16) = (v40 & 0x400) != 0;
  *(_BYTE *)(v39 + 17) = *(_BYTE *)(v4[8] + 97);
  sub_12C84C(v39);
  return 0;
}

