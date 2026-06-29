// fwstruct annotate: 135978_rf_bus_write_6b_d.c
// rf_bus_write_6b_d @ 0x135978, size 120 bytes
// Doc: rf_bus_write_6b_d [rf]: Write 6-byte value with tag 0xd to RF bus
// rf_bus_write_6b_d [rf]: Write 6-byte value with tag 0xd to RF bus
int __fastcall rf_bus_write_6b_d(char a1, int a2, unsigned int a3)
{
  unsigned int v3; // r4
  int v6; // r0
  __int16 **v7; // r3
  __int16 *v8; // r3
  int v9; // r5
  int v10; // r3
  unsigned int v11; // r4

  v3 = a3;
  v6 = sub_12C92C(6152, 13, 6, (unsigned __int16)(a3 + 4));
  v7 = (__int16 **)off_1359F0;
  *(_BYTE *)v6 = a1;
  v8 = *v7;
  *(_WORD *)(v6 + 2) = v3;
  v9 = v6;
  if ( *v8 < 0 )
  {
    if ( v3 >= sub_12F654() - 4 )
      sub_12F46C(dword_1359FC, dword_1359F8, 1444);
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
  sub_12CD34(6u, 7);
  timer_set_relative(6154, 6, dword_1359F4);
  return sdio_buffer_prepare_n_4e8(v9);
}

