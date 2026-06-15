// sub_1294C8 @ 0x1294c8, size 86 bytes
int sub_1294C8()
{
  int v0; // r1
  _DWORD *v1; // r0
  _DWORD *v2; // r1
  _DWORD *v3; // r5
  _DWORD *v4; // r2

  v0 = dword_129528;
  *(_DWORD *)off_129520 |= 0x2000000u;
  feature_guard_check(2, v0);
  if ( !*((_BYTE *)off_12952C + 18) )
    *(_DWORD *)off_129530 &= ~1u;
  v1 = off_129538;
  v2 = off_129530;
  v3 = off_12953C;
  v4 = off_129540;
  *(_DWORD *)off_129534 &= ~0x10000u;
  *v1 &= ~0x40000000u;
  *v2 &= ~0x10000000u;
  *v3 = 0;
  *v4 &= ~1u;
  return 0;
}

