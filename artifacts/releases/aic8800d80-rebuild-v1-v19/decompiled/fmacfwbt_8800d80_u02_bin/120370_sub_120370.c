// sub_120370 @ 0x120370, size 326 bytes
// Doc: sub_1220370 [rf]: FMAC/BT init/setup routine sizing a 0x528-byte block, indexed by channel/mode byte
// sub_1220370 [rf]: FMAC/BT init/setup routine sizing a 0x528-byte block, indexed by channel/mode byte
__int64 __fastcall sub_120370(unsigned __int8 *a1, char a2)
{
  int v3; // r6
  int v4; // r8
  int v5; // r4
  _BYTE *v6; // r7
  int v7; // r10
  int *v8; // r9
  int *v9; // r0
  int v10; // r2
  int v11; // r3
  __int64 result; // r0
  __int64 v13; // r2
  int v14; // r4
  int v15; // r0

  v3 = *a1;
  v4 = a1[41];
  v5 = dword_1204C0;
  v6 = (_BYTE *)(1320 * v4 + 120 * v3 + dword_1204C0);
  v7 = 120 * v3 + 1320 * v4;
  v6[578] = a2;
  v6[576] = a1[40];
  v8 = (int *)(v7 + 480 + v5);
  v6[577] = v3;
  v9 = memset_thunk(v8, 0, 0x48u);
  switch ( v6[576] )
  {
    case 0:
    case 3:
      *(_QWORD *)(1320 * v4 + 120 * v3 + v5 + 552) = sub_143A18(v9) & 0xFFFFFFLL;
      break;
    case 1:
      v15 = 1320 * v4 + 120 * v3 + v5;
      *(_DWORD *)(v15 + 560) = *((_DWORD *)a1 + 6);
      *(_DWORD *)(v15 + 564) = *((_DWORD *)a1 + 7);
      *(_DWORD *)(v15 + 568) = *((_DWORD *)a1 + 8);
      *(_DWORD *)(v15 + 572) = *((_DWORD *)a1 + 9);
      *(_QWORD *)(v15 + 552) = 0;
      break;
    case 4:
      *(_QWORD *)(1320 * v4 + 120 * v3 + v5 + 552) = *(_QWORD *)&dword_1204B8;
      break;
    case 5:
      sub_14380C(v7 + 560 + v5, a1 + 8, 16);
      goto LABEL_3;
    default:
LABEL_3:
      *(_QWORD *)(1320 * v4 + 120 * v3 + v5 + 552) = 0;
      break;
  }
  v10 = 1320 * v4 + 120 * v3 + v5;
  v11 = 1320 * v4 + v5;
  if ( *(_BYTE *)(v10 + 576) == 5 )
    *(_DWORD *)(v11 + 1204) = v8;
  else
    *(_DWORD *)(v11 + 1200) = v8;
  *(_BYTE *)(v10 + 579) = 1;
  result = *((_QWORD *)a1 + 1);
  v13 = *((_QWORD *)a1 + 2);
  v14 = v5 + 1320 * v4 + 120 * v3;
  *(_QWORD *)(v14 + 580) = result;
  *(_QWORD *)(v14 + 588) = v13;
  *(_BYTE *)(v14 + 596) = a1[4];
  return result;
}

