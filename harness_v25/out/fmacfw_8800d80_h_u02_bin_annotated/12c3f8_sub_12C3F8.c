// fwstruct annotate: 12c3f8_sub_12C3F8.c
// sub_12C3F8 @ 0x12c3f8, size 60 bytes
void __fastcall sub_12C3F8(int a1, int a2, unsigned __int8 *a3)
{
  int v3; // r4
  int v4; // r0

  if ( *((_BYTE *)off_12C434 + 197) )
  {
    v3 = *(_DWORD *)(*(_DWORD *)(a2 + 76) + 48);
    v4 = sub_101CAC((*(_DWORD *)(v3 + 20) >> 11) & 7, *(_DWORD *)(v3 + 20) & 0x7F, a3);
    *(_DWORD *)(v3 + 36) = v4 | (v4 << 8);
  }
  else if ( **(__int16 **)off_12C438 < 0 )
  {
    sub_12F32C(dword_12C440, dword_12C43C, 109);
  }
}

