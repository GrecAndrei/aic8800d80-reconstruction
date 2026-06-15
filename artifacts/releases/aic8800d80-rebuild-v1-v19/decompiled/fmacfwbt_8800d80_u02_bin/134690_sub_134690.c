// sub_134690 @ 0x134690, size 72 bytes
// Doc: sub_1234690 [mac]: initializes state and clears outptr/inptr slots
// sub_1234690 [mac]: initializes state and clears outptr/inptr slots
int __fastcall sub_134690(_DWORD *a1, _DWORD *a2)
{
  int v2; // r6
  int result; // r0

  v2 = *((_DWORD *)off_1346D8 + 4);
  *a1 = 0;
  *a2 = 0;
  if ( (*(_BYTE *)(v2 + 34) & 1) != 0 )
  {
    result = sub_138378(v2);
    if ( result )
    {
      *a1 = result + 2;
LABEL_4:
      *a2 = *(_DWORD *)(result + 44);
      return result;
    }
  }
  else
  {
    *a1 = v2 + 34;
    result = sub_13831C();
    if ( result )
      goto LABEL_4;
  }
  if ( *(unsigned __int16 *)(v2 + 40) != 0xFFFF )
    *a2 = v2 + 40;
  return result;
}

