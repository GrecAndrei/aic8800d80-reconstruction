// sub_13064C @ 0x13064c, size 110 bytes
int __fastcall sub_13064C(int a1)
{
  signed int v1; // r0
  int v2; // r3
  int result; // r0

  if ( a1 > 29 )
    v1 = (unsigned int)(((unsigned int)dword_1306C8 * (unsigned __int64)(unsigned int)(a1 - 30)) >> 32) >> 3;
  else
    v1 = ((int)((unsigned __int64)(dword_1306BC * (__int64)(a1 - 40)) >> 32) >> 2) - ((a1 - 40) >> 31);
  if ( v1 >= 8 )
    v1 = 8;
  if ( v1 < -7 )
    v1 = -7;
  v2 = *((unsigned __int8 *)off_1306C0 + 4)
     + (char)(*(_BYTE *)(dword_1306C4 + v1 + 7) - *(_BYTE *)(dword_1306C4 + *((char *)off_1306C0 + 2) + 7));
  if ( v2 >= 31 )
    v2 = 31;
  if ( v2 < 1 )
    LOBYTE(v2) = 1;
  *((_BYTE *)off_1306C0 + 5) = v2;
  sub_130514(v1);
  result = sub_12EC84(9u, 4u);
  if ( result )
    return rf_level_dump_05bc();
  return result;
}

