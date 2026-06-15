// v23 annotated: sub_122DF4 @ 0x122df4
// Original: 122df4_sub_122DF4.c
// Primary struct: <unclustered>
//
// sub_122DF4 @ 0x122df4, size 98 bytes
int __fastcall sub_122DF4(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v4; // r7
  int v6; // r4
  int v9; // r4
  int v10; // r3

  v4 = dword_122E5C;
  v6 = *a2;
  if ( **(__int16 **)off_122E58 < 0 && *(_BYTE *)(dword_122E5C + 1320 * v6 + 106) )
    sub_12F694(dword_122E64, dword_122E60, 3702);
  v9 = v4 + 1320 * v6;
  *(_BYTE *)(v9 + 143) = a2[1];
  v10 = a2[2];
  *(_WORD *)(v9 + 144) = (unsigned __int8)v10;
  message_dispatch_n84(134, a4, a3, v10);
  return 0;
}

