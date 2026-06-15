// v23 annotated: sub_136E40 @ 0x136e40
// Original: 136e40_sub_136E40.c
// Primary struct: <unclustered>
//
// sub_136E40 @ 0x136e40, size 84 bytes
// Doc: sub_1236E40 [mac]: FMAC behavioral routine indexed by mla with stride 0x2b8
// sub_1236E40 [mac]: FMAC behavioral routine indexed by mla with stride 0x2b8
int __fastcall sub_136E40(int result, int a2)
{
  int v2; // r4
  char v3; // r1
  int v4; // r0
  __int16 v5; // r1

  if ( *(_BYTE *)(result + 106) == 2 )
  {
    v2 = dword_136E94 + 696 * a2;
    result = sub_11F704(result, v2, 0);
    v3 = *(_BYTE *)(v2 + 53);
    if ( (v3 & 0xA) != 0 )
    {
      *(_BYTE *)(v2 + 53) = v3 & 0xF5;
      if ( (v3 & 0xF5) == 0 )
      {
        v4 = rf_bus_setup_n3a8(65, 0, 5, 4u);
        v5 = *(_WORD *)(v2 + 32);
        *(_BYTE *)(v4 + 3) = *(_BYTE *)(v2 + 34);
        *(_BYTE *)(v4 + 2) = 0;
        *(_WORD *)v4 = v5;
        return sub_12CBB4(v4);
      }
    }
  }
  return result;
}

