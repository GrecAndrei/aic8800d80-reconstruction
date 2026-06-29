// fwstruct annotate: 13a528_sub_13A528.c
// sub_13A528 @ 0x13a528, size 280 bytes
// Doc: sub_123A528 [util]: Index into a table entry using byte fields 0x1c/0x1d with stride 0x2b8
// sub_123A528 [util]: Index into a table entry using byte fields 0x1c/0x1d with stride 0x2b8
int __fastcall sub_13A528(int a1, _DWORD *a2)
{
  int v3; // r7
  int v4; // r0
  int v5; // r3
  __int64 v6; // kr00_8
  int v7; // r2
  int v8; // r6
  int v9; // lr
  int v10; // r5
  int v11; // r2
  int v12; // r0

  v3 = dword_13A640;
  v4 = *(unsigned __int8 *)(a1 + 29);
  v5 = dword_13A640 + 696 * v4;
  v6 = *(_QWORD *)(v5 + 184);
  v7 = dword_13A644 + 1320 * *(unsigned __int8 *)(a1 + 28);
  v8 = *(_DWORD *)HIDWORD(v6);
  v9 = *(_DWORD *)(v7 + 1200);
  v10 = 0;
  *a2 = 0;
  if ( !v8 || !v9 )
    return 0;
  if ( (*(_DWORD *)(v7 + 1208) & 2) != 0
    && *(unsigned __int16 *)(v5 + 56) == (unsigned __int16)__rev16(*(unsigned __int16 *)(a1 + 24)) )
  {
    return v10;
  }
  if ( !(_DWORD)v6
    || (unsigned int)*(unsigned __int8 *)(v6 + 96) - 1 > 1
    || *(unsigned __int8 *)(v3 + 696 * v4 + 669) > 1u )
  {
    switch ( *(_BYTE *)(v8 + 96) )
    {
      case 0:
      case 3:
        v10 = 4;
        *a2 = 4;
        v11 = 2;
        v12 = 1;
        break;
      case 1:
        *a2 = 12;
        v10 = 8;
        v11 = 3;
        v12 = 1;
        break;
      case 2:
        v10 = 8;
        *a2 = 8;
        v11 = 3;
        v12 = 1;
        break;
      case 4:
        *a2 = 16;
        if ( *(unsigned __int8 *)(v8 + 98) >= 0x10u )
          v12 = 2;
        else
          v12 = 1;
        v10 = 18;
        v11 = 4;
        break;
      case 6:
      case 7:
      case 8:
        *a2 = 16;
        v10 = 8;
        v11 = 3;
        v12 = 1;
        break;
      default:
        if ( **(__int16 **)off_13A648 < 0 )
          sub_12F46C(dword_13A64C, dword_13A650, 181);
        v10 = 0;
        v11 = 3;
        v12 = 1;
        break;
    }
    if ( (*(_WORD *)(a1 + 30) & 1) == 0 )
    {
      *(_QWORD *)(v8 + 72) += v12;
      sub_143770(a1 + 56, v8 + 72, 2 * v11);
    }
    return v10;
  }
  return 0;
}

