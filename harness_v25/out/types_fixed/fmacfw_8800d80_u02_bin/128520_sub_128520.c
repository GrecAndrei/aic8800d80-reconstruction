// sub_128520 @ 0x128520, size 34 bytes
// Doc: sub_1228520 [util]: Trivial wrapper calling sub_1284d0
// sub_1228520 [util]: Trivial wrapper calling sub_1284d0
BOOL __fastcall sub_128520(int a1)
{
  BOOL result; // r0

  result = mmio_status_read_l28(a1);
  if ( result )
    return !*((_DWORD *)off_128544 + 11) || *(unsigned __int8 *)(*((_DWORD *)off_128544 + 10) + 16) == 6;
  return result;
}

