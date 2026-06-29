// fwstruct annotate: 1388ec_sub_1388EC.c
// sub_1388EC @ 0x1388ec, size 354 bytes
int __fastcall sub_1388EC(int a1, __int16 a2)
{
  _BYTE *v2; // r2
  int v3; // r4
  int v4; // r3
  int v5; // r1
  int v6; // r5
  int result; // r0
  int v8; // r3
  char v9; // r1
  int v10; // r6
  int v11; // r8
  int v12; // r3
  int v13; // t1
  char v14; // r1
  int v15; // r4
  __int16 v16; // r3
  int v17; // r12
  char v18; // r4
  int v19; // r3

  v2 = off_138A50;
  v3 = *((unsigned __int8 *)off_138A50 + 8);
  v4 = (a2 & 0x7C) - 4;
  v5 = a2 & 0x400;
  v6 = a1 + v3;
  switch ( v4 )
  {
    case 0:
      *((_BYTE *)off_138A50 + 8) = v3 + 4;
      result = 1;
      break;
    case 4:
      *((_BYTE *)off_138A50 + 8) = v3 + 8;
      v16 = *(_WORD *)(a1 + v3);
      v17 = *(unsigned __int16 *)(v6 + 6);
      v18 = v2[48];
      *((_DWORD *)v2 + 4) = (unsigned __int16)(v16 << 8)
                          | *(unsigned __int8 *)(v6 + 2)
                          | (*(unsigned __int16 *)(v6 + 4) << 16);
      *((_DWORD *)v2 + 5) = v17;
      v2[48] = v18 | 3;
      if ( v5 )
        v19 = 1320 * (unsigned __int8)v2[10] + 480 + 120 * (*(unsigned __int16 *)(v6 + 2) >> 14) + dword_138A54;
      else
        v19 = dword_138A58 + 696 * (unsigned __int8)v2[9];
      *((_DWORD *)v2 + 8) = v19;
      result = 1;
      break;
    case 8:
    case 12:
    case 16:
    case 20:
      if ( v5 )
        v8 = 1320 * *((unsigned __int8 *)off_138A50 + 10)
           + 480
           + 120 * (*(unsigned __int16 *)(v6 + 2) >> 14)
           + dword_138A54;
      else
        v8 = dword_138A58 + 696 * *((unsigned __int8 *)off_138A50 + 9);
      *((_BYTE *)off_138A50 + 8) = v3 + 8;
      v9 = v2[48];
      v10 = *(unsigned __int16 *)(a1 + v3);
      v11 = *(unsigned __int16 *)(v6 + 4);
      *((_DWORD *)v2 + 8) = v8;
      *((_DWORD *)v2 + 5) = *(unsigned __int16 *)(v6 + 6);
      v2[48] = v9 | 2;
      *((_DWORD *)v2 + 4) = v10 | (v11 << 16);
      result = 1;
      break;
    case 24:
      if ( v5 )
        v12 = 1320 * *((unsigned __int8 *)off_138A50 + 10)
            + 480
            + 120 * (*(unsigned __int16 *)(v6 + 2) >> 14)
            + dword_138A54;
      else
        v12 = dword_138A58 + 696 * *((unsigned __int8 *)off_138A50 + 9);
      *((_BYTE *)off_138A50 + 8) = v3 + 18;
      v13 = *(_DWORD *)(v6 + 2);
      v14 = v2[48];
      v15 = *(_DWORD *)(v6 + 6);
      *((_DWORD *)v2 + 8) = v12;
      v2[48] = v14 | 2;
      *((_DWORD *)v2 + 4) = v13;
      *((_DWORD *)v2 + 5) = v15;
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

