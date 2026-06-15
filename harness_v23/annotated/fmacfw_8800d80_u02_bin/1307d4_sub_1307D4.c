// v23 annotated: sub_1307D4 @ 0x1307d4
// Original: 1307d4_sub_1307D4.c
// Primary struct: <unclustered>
//
// sub_1307D4 @ 0x1307d4, size 46 bytes
// Doc: sub_12307D4 [util]: Initialize descriptor header with magic bytes F/5/p
// sub_12307D4 [util]: Initialize descriptor header with magic bytes F/5/p
int __fastcall sub_1307D4(int a1)
{
  **(_BYTE **)a1 = 70;
  *(_BYTE *)(*(_DWORD *)a1 + 1) = 5;
  *(_BYTE *)(*(_DWORD *)a1 + 2) = 112;
  *(_BYTE *)(*(_DWORD *)a1 + 3) = 0;
  *(_BYTE *)(*(_DWORD *)a1 + 4) = 0;
  *(_BYTE *)(*(_DWORD *)a1 + 5) = 0;
  *(_BYTE *)(*(_DWORD *)a1 + 6) = 0;
  *(_DWORD *)a1 += 7;
  return 7;
}

