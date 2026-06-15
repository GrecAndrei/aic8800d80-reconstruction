// v23 annotated: sub_1196A4 @ 0x1196a4
// Original: 1196a4_sub_1196A4.c
// Primary struct: <unclustered>
//
// sub_1196A4 @ 0x1196a4, size 278 bytes
// Doc: sub_12196A4 [unknown]: Push context and branch on state byte field 0x6a
// sub_12196A4 [unknown]: Push context and branch on state byte field 0x6a
int __fastcall sub_1196A4(int a1, int a2, int a3)
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
    sub_12ECB0(dword_1197D0, v3, a3);
    return 1;
  }
  v4 = *(_DWORD *)(a1 + 72);
  if ( v4 )
  {
    v7 = *(unsigned __int8 *)(v4 + 4);
    if ( **(__int16 **)off_1197BC >= 0 || v7 != 2 )
    {
      v8 = (v7 | *(unsigned __int8 *)(a1 + 1224)) != 0;
      goto LABEL_5;
    }
  }
  else if ( **(__int16 **)off_1197BC >= 0 )
  {
    goto LABEL_9;
  }
  sub_12F694(dword_1197CC, dword_1197C8, 520);
LABEL_9:
  v8 = 1;
LABEL_5:
  v9 = dword_1197D8;
  v10 = sub_119084(v8, *(unsigned __int16 *)(dword_1197D8 + 2 * *(unsigned __int8 *)(a1 + 107)));
  v12 = v10;
  if ( v10 )
  {
    message_dispatch_n_4a3(a1, v10);
    v13 = *(_DWORD *)(v12 + 72);
    *(_BYTE *)(v13 + 108) = 80;
    *(_BYTE *)(v13 + 109) = 0;
    *(_BYTE *)(v13 + 110) = 0;
    *(_BYTE *)(v13 + 111) = 0;
    sub_14380C(v13 + 112, a2, 6);
    v14 = off_1197C0;
    v15 = *((_WORD *)off_1197C0 + 254);
    v16 = *(_WORD *)(a1 + 104);
    *(_DWORD *)(v13 + 118) = *(_DWORD *)(a1 + 100);
    ++v15;
    v17 = *(_DWORD *)(a1 + 100);
    *(_WORD *)(v13 + 122) = v16;
    *(_DWORD *)(v13 + 124) = v17;
    *(_WORD *)(v13 + 128) = v16;
    v14[254] = v15;
    *(_WORD *)(v13 + 130) = 16 * v15;
    sub_14380C(
      v13 + 132,
      dword_1197C4 + (*(unsigned __int8 *)(a1 + 107) << 9),
      *(unsigned __int16 *)(v9 + 2 * *(unsigned __int8 *)(a1 + 107)) - 24);
    *(_DWORD *)(v12 + 88) = 0;
    *(_DWORD *)(v12 + 92) = 0;
    *(_BYTE *)(v12 + 28) = *(_BYTE *)(a1 + 107);
    *(_BYTE *)(v12 + 29) = -1;
    sub_1190B4(v12, 5);
    return 0;
  }
  else
  {
    sub_12ECB0(dword_1197D4, *(unsigned __int16 *)(v9 + 2 * *(unsigned __int8 *)(a1 + 107)), v11);
    return 1;
  }
}

