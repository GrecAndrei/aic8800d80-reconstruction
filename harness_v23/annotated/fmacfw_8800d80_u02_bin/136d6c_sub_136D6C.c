// v23 annotated: sub_136D6C @ 0x136d6c
// Original: 136d6c_sub_136D6C.c
// Primary struct: <unclustered>
//
// sub_136D6C @ 0x136d6c, size 246 bytes
int __fastcall sub_136D6C(int a1, int a2)
{
  int v2; // r3
  int v5; // r3
  int result; // r0
  int v7; // r5
  int v8; // r6
  _WORD *v9; // r2
  __int16 v10; // r3
  __int16 v11; // r1
  int v12; // r0
  int v13; // r0
  int v14; // r1
  __int64 v15; // r2

  v2 = *(_DWORD *)(a1 + 72);
  if ( v2 )
  {
    v5 = *(unsigned __int8 *)(v2 + 4);
    if ( **(__int16 **)off_136E64 >= 0 || v5 != 2 )
    {
      result = sub_118C44((v5 | *(unsigned __int8 *)(a1 + 1224)) != 0, 512);
      v7 = result;
      if ( !result )
        return result;
LABEL_4:
      sub_12C4E8(a1, result);
      v8 = *(_DWORD *)(v7 + 72);
      *(_BYTE *)(v8 + 108) = -64;
      *(_BYTE *)(v8 + 109) = 0;
      *(_BYTE *)(v8 + 110) = 0;
      *(_BYTE *)(v8 + 111) = 0;
      sub_143770(v8 + 112, a2, 6);
      v9 = off_136E68;
      v10 = *((_WORD *)off_136E68 + 254);
      v11 = *(_WORD *)(a1 + 104);
      *(_DWORD *)(v8 + 118) = *(_DWORD *)(a1 + 100);
      ++v10;
      v12 = *(_DWORD *)(a1 + 100);
      *(_WORD *)(v8 + 122) = v11;
      *(_DWORD *)(v8 + 124) = v12;
      *(_WORD *)(v8 + 128) = v11;
      v9[254] = v10;
      *(_WORD *)(v8 + 130) = 16 * v10;
      *(_DWORD *)(v7 + 88) = 0;
      *(_DWORD *)(v7 + 92) = a1;
      *(_BYTE *)(v7 + 28) = *(_BYTE *)(a1 + 107);
      *(_BYTE *)(v7 + 29) = -1;
      v13 = sub_130838((_WORD *)(v8 + 132), 7);
      v14 = *(_DWORD *)(v7 + 76);
      LODWORD(v15) = *(_DWORD *)(v14 + 28) + 23 + v13;
      HIDWORD(v15) = v13 + 28;
      *(_QWORD *)(v14 + 32) = v15;
      return rf_param_get_status(v7, 5);
    }
    goto LABEL_6;
  }
  if ( **(__int16 **)off_136E64 < 0 )
LABEL_6:
    sub_12F46C(dword_136E70, dword_136E6C, 520);
  result = sub_118C44(1, 512);
  v7 = result;
  if ( result )
    goto LABEL_4;
  return result;
}

