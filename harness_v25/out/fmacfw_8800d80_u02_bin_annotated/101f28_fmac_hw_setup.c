// fwstruct annotate: 101f28_fmac_hw_setup.c
// fmac_hw_setup @ 0x101f28, size 58 bytes
// Doc: fmac_hw_setup [util]: FMAC hardware setup routine
// fmac_hw_setup [util]: FMAC hardware setup routine
int __fastcall fmac_hw_setup(int result)
{
  _DWORD *v1; // r2
  unsigned int v2; // r3
  int v3; // r3

  v1 = off_101F68;
  *(_DWORD *)off_101F64 = *(_DWORD *)off_101F64 & 0xFFFFFF | ((unsigned __int8)(result / 2) << 24);
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

