// v23 annotated: sub_141DE8 @ 0x141de8
// Original: 141de8_sub_141DE8.c
// Primary struct: <unclustered>
//
// sub_141DE8 @ 0x141de8, size 66 bytes
int __fastcall sub_141DE8(int a1, int a2)
{
  int v3; // r5
  int v4; // r0
  int v5; // r2

  v3 = *(_DWORD *)(a1 + 24)
     - 400
     - *(_DWORD *)(a1 + 48) * a2
     - *(_DWORD *)(dword_141E2C + 1320 * *(unsigned __int8 *)(a1 + 47) + 40);
  v4 = sub_12C068();
  v5 = *((_DWORD *)off_141E30 + 4);
  *(_DWORD *)(a1 + 56) = dword_141E34;
  return timestamp_update_4f60(a1 + 52, v5 + v3 - v4);
}

