// fwstruct annotate: 117db4_sub_117DB4.c
// sub_117DB4 @ 0x117db4, size 10 bytes
int __fastcall sub_117DB4(int result)
{
  if ( *(_DWORD *)(result + 72) )
    return rf_bus_reset2_c158();
  return result;
}

