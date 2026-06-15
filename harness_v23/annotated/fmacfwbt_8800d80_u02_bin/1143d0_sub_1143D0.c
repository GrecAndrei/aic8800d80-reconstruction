// v23 annotated: sub_1143D0 @ 0x1143d0
// Original: 1143d0_sub_1143D0.c
// Primary struct: <unclustered>
//
// sub_1143D0 @ 0x1143d0, size 40 bytes
int __fastcall sub_1143D0(int a1, int a2, int a3)
{
  int result; // r0
  _BYTE *v4; // r3
  _DWORD *v5; // r1

  result = sub_12ECB0(dword_1143F8, a2, a3);
  v4 = off_1143FC;
  if ( *((_BYTE *)off_1143FC + 3) )
  {
    v5 = off_114404;
    *(_DWORD *)off_114400 &= ~8u;
    *v5 &= 0xFFFFFFF0;
    v4[3] = 0;
    return 0;
  }
  return result;
}

