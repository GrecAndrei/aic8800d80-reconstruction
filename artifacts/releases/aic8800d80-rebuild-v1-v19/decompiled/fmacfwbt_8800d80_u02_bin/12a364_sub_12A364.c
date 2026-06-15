// sub_12A364 @ 0x12a364, size 72 bytes
unsigned int __fastcall sub_12A364(int a1, _DWORD *a2, _DWORD *a3)
{
  int v6; // r3
  int v7; // r0

  if ( **(__int16 **)off_12A3AC < 0 && !*(_BYTE *)(a1 + 1224) )
    sub_12F694(dword_12A3B8, dword_12A3B4, 1311);
  v6 = dword_12A3B0 + 140 * *(unsigned __int8 *)(a1 + 1225);
  *a2 = *(_DWORD *)(v6 + 128);
  v7 = *(_DWORD *)(v6 + 124);
  *a3 = v7;
  return (unsigned int)(v7 - *a2) >> 31;
}

