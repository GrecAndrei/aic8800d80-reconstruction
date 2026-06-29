// fwstruct annotate: 101da4_mmio_set_byte_field.c
// mmio_set_byte_field @ 0x101da4, size 58 bytes
// Doc: mmio_set_byte_field [mmio]: Set a byte field in MMIO register by masking and OR-ing shifted value
// mmio_set_byte_field [mmio]: Set a byte field in MMIO register by masking and OR-ing shifted value
int __fastcall mmio_set_byte_field(int result)
{
  _DWORD *v1; // r2
  unsigned int v2; // r3
  int v3; // r3

  v1 = off_101DE4;
  *(_DWORD *)off_101DE0 = *(_DWORD *)off_101DE0 & 0xFFFFFF | ((unsigned __int8)(result / 2) << 24);
  v2 = *v1 & 0xFFFFF0FF;
  if ( (result & 1) != 0 )
  {
    if ( result >= 0 )
      v3 = v2 | 0xB00;
    else
      v3 = v2 | 0x500;
    *v1 = v3;
  }
  else
  {
    *v1 = v2 | 0x800;
  }
  return result;
}

