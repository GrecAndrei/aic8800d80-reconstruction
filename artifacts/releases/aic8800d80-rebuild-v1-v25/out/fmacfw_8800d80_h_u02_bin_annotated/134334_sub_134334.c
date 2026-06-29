// fwstruct annotate: 134334_sub_134334.c
// sub_134334 @ 0x134334, size 72 bytes
int __fastcall sub_134334(_DWORD *a1, _DWORD *a2)
{
  int v2; // r6
  int result; // r0

  v2 = *((_DWORD *)off_13437C + 4);
  *a1 = 0;
  *a2 = 0;
  if ( (*(_BYTE *)(v2 + 34) & 1) != 0 )
  {
    result = sub_138134(v2);
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
    result = sub_1380D8();
    if ( result )
      goto LABEL_4;
  }
  if ( *(unsigned __int16 *)(v2 + 40) != 0xFFFF )
    *a2 = v2 + 40;
  return result;
}

