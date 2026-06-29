// fwstruct annotate: 11a8b0_sub_11A8B0.c
// sub_11A8B0 @ 0x11a8b0, size 68 bytes
int __fastcall sub_11A8B0(int result, int a2)
{
  int v2; // r3
  int v3; // r2
  int v4; // r3
  unsigned int v5; // r3

  v2 = *(_DWORD *)(result + 60);
  if ( v2 < 0 )
  {
    v3 = *(_DWORD *)(result + 36);
    if ( **(__int16 **)off_11A8F4 < 0 && (v4 = v2 << 15, v4 >= 0) )
    {
      return fmac_phy_op_handler(dword_11A8FC, dword_11A8F8, 3371, v4);
    }
    else
    {
      v5 = *(_DWORD *)(v3 + 20) & 0xFFFE3FFF | 0x4000;
      *(_DWORD *)(result + 60) = 0;
      *(_DWORD *)(v3 + 20) = v5;
      return mmio_reg_poll_n6b4(result, a2, v3, v5);
    }
  }
  return result;
}

