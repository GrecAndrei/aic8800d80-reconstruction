// sub_11DF7C @ 0x11df7c, size 98 bytes
int __fastcall sub_11DF7C(int a1, int a2)
{
  int v2; // r3
  int result; // r0
  unsigned int v4; // r3
  _DWORD *v5; // r1
  int v6; // r2
  bool v7; // cf
  unsigned int v8; // r2

  if ( !a2 )
  {
    v4 = a1 + 160;
    goto LABEL_9;
  }
  if ( (*(_WORD *)(a2 + 16) & 1) != 0 )
  {
LABEL_8:
    v4 = (*(_DWORD *)(a2 + 12) & 0xFFFFFFFC) + 4;
LABEL_9:
    v5 = off_11DFEC;
    v6 = *((_DWORD *)off_11DFEC + 2);
    if ( *((_DWORD *)off_11DFEC + 1) == v4 )
      v4 = *(_DWORD *)off_11DFEC;
    *(_DWORD *)(a1 + 152) = v4;
    result = v6 & 0x7FFFFFFF;
    v7 = v4 >= (v6 & 0x7FFFFFFFu);
    v8 = v6 & 0x80000000;
    if ( !v7 )
      v8 += 0x80000000;
    v5[2] = v4 | v8;
    return result;
  }
  v2 = *(_DWORD *)off_11DFE0;
  while ( 1 )
  {
    a2 = *(_DWORD *)(a2 + 4);
    if ( **(__int16 **)off_11DFE0 < 0 && !a2 )
      return fmac_phy_op_handler(dword_11DFE8, dword_11DFE4, 1119, v2);
    v2 = *(unsigned __int16 *)(a2 + 16) << 31;
    if ( (*(_WORD *)(a2 + 16) & 1) != 0 )
      goto LABEL_8;
  }
}

