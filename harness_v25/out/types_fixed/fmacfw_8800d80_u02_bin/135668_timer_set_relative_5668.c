// timer_set_relative_5668 @ 0x135668, size 144 bytes
int __fastcall sub_135668(int a1)
{
  int v2; // r6
  int v3; // r2
  int result; // r0
  int v5; // r6
  int v6; // r4

  v2 = *(unsigned __int8 *)(a1 + 8);
  if ( sub_12CE88(6) == 10 || sub_12CE88(6) == 9 )
    return 2;
  if ( sub_12CE88(6) )
  {
    v3 = *(unsigned __int8 *)(*((_DWORD *)off_1356F8 + 4) + 61);
    if ( v3 != *(unsigned __int8 *)(a1 + 8) )
      return 2;
    sub_12ECD0(256, off_135704, v3);
    if ( sub_12C8B4(6154, 6) )
      sub_12C73C(6154, 6);
    sub_134E04(1);
    return 0;
  }
  else
  {
    v5 = dword_1356FC + 1320 * v2;
    result = *(unsigned __int8 *)(v5 + 108);
    if ( *(_BYTE *)(v5 + 108) )
    {
      v6 = *(unsigned __int16 *)(a1 + 12);
      sub_12ECD0(256, off_135700[0], v6);
      sub_134D8C(v5, v6, 0);
      return 0;
    }
  }
  return result;
}

