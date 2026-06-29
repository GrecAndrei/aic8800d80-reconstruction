// fwstruct annotate: 12c760_sub_12C760.c
// sub_12C760 @ 0x12c760, size 60 bytes
void __fastcall sub_12C760(int a1, int a2, unsigned __int8 *a3)
{
  int v3; // r4
  int v4; // r0

  if ( *((_BYTE *)off_12C79C + 197) )
  {
    v3 = *(_DWORD *)(*(_DWORD *)(a2 + 76) + 48);
    v4 = sub_101BD4((*(_DWORD *)(v3 + 20) >> 11) & 7, *(_DWORD *)(v3 + 20) & 0x7F, a3);
    *(_DWORD *)(v3 + 36) = v4 | (v4 << 8);
  }
  else if ( **(__int16 **)off_12C7A0 < 0 )
  {
    sub_12F694(dword_12C7A8, dword_12C7A4, 109);
  }
}

