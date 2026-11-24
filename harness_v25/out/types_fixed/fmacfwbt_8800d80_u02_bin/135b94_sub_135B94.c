// sub_135B94 @ 0x135b94, size 120 bytes
int __fastcall sub_135B94(char a1, int a2, unsigned int a3)
{
  unsigned int v3; // r4
  int v6; // r0
  __int16 **v7; // r3
  __int16 *v8; // r3
  int v9; // r5
  int v10; // r3
  unsigned int v11; // r4

  v3 = a3;
  v6 = rf_bus_setup_n3a8(6152, 13, 6, (unsigned __int16)(a3 + 4));
  v7 = (__int16 **)off_135C0C;
  *(_BYTE *)v6 = a1;
  v8 = *v7;
  *(_WORD *)(v6 + 2) = v3;
  v9 = v6;
  if ( *v8 < 0 )
  {
    if ( v3 >= sub_12F870() - 4 )
      sub_12F694(dword_135C18, dword_135C14, 1444);
    v3 = *(unsigned __int16 *)(v9 + 2);
  }
  if ( v3 )
  {
    v10 = v9 + 3;
    v11 = v3 + v9 + 3;
    do
    {
      *(_BYTE *)(v10 + 1) = *(_BYTE *)(a2 - 3 - v9 + v10);
      ++v10;
    }
    while ( v10 != v11 );
  }
  rf_bus_mark_n_3b7(6u, 7);
  rf_level_apply_80c(6154, 6, dword_135C10);
  return sub_12CBB4(v9);
}

