// sub_119124 @ 0x119124, size 278 bytes
int __fastcall sub_119124(int a1, int a2, int a3)
{
  int v3; // r3
  int v4; // r3
  int v7; // r3
  BOOL v8; // r0
  int v9; // r8
  int v10; // r0
  int v11; // r2
  int v12; // r6
  int v13; // r5
  _WORD *v14; // r2
  __int16 v15; // r3
  __int16 v16; // r1
  int v17; // r0

  v3 = *(unsigned __int8 *)(a1 + 106);
  if ( v3 != 2 )
  {
    sub_12E948(dword_119250, v3, a3);
    return 1;
  }
  v4 = *(_DWORD *)(a1 + 72);
  if ( v4 )
  {
    v7 = *(unsigned __int8 *)(v4 + 4);
    if ( **(__int16 **)off_11923C >= 0 || v7 != 2 )
    {
      v8 = (v7 | *(unsigned __int8 *)(a1 + 1224)) != 0;
      goto LABEL_5;
    }
  }
  else if ( **(__int16 **)off_11923C >= 0 )
  {
    goto LABEL_9;
  }
  sub_12F32C(dword_11924C, dword_119248, 520);
LABEL_9:
  v8 = 1;
LABEL_5:
  v9 = dword_119258;
  v10 = sub_118B04(v8, *(unsigned __int16 *)(dword_119258 + 2 * *(unsigned __int8 *)(a1 + 107)));
  v12 = v10;
  if ( v10 )
  {
    sub_12C3A8(a1, v10);
    v13 = *(_DWORD *)(v12 + 72);
    *(_BYTE *)(v13 + 108) = 80;
    *(_BYTE *)(v13 + 109) = 0;
    *(_BYTE *)(v13 + 110) = 0;
    *(_BYTE *)(v13 + 111) = 0;
    sub_143630(v13 + 112, a2, 6);
    v14 = off_119240;
    v15 = *((_WORD *)off_119240 + 254);
    v16 = *(_WORD *)(a1 + 104);
    *(_DWORD *)(v13 + 118) = *(_DWORD *)(a1 + 100);
    ++v15;
    v17 = *(_DWORD *)(a1 + 100);
    *(_WORD *)(v13 + 122) = v16;
    *(_DWORD *)(v13 + 124) = v17;
    *(_WORD *)(v13 + 128) = v16;
    v14[254] = v15;
    *(_WORD *)(v13 + 130) = 16 * v15;
    sub_143630(
      v13 + 132,
      dword_119244 + (*(unsigned __int8 *)(a1 + 107) << 9),
      *(unsigned __int16 *)(v9 + 2 * *(unsigned __int8 *)(a1 + 107)) - 24);
    *(_DWORD *)(v12 + 88) = 0;
    *(_DWORD *)(v12 + 92) = 0;
    *(_BYTE *)(v12 + 28) = *(_BYTE *)(a1 + 107);
    *(_BYTE *)(v12 + 29) = -1;
    sub_118B34(v12, 5);
    return 0;
  }
  else
  {
    sub_12E948(dword_119254, *(unsigned __int16 *)(v9 + 2 * *(unsigned __int8 *)(a1 + 107)), v11);
    return 1;
  }
}

