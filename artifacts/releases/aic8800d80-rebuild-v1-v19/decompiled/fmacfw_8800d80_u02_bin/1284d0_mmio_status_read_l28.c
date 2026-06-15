// mmio_status_read_l28 @ 0x1284d0, size 74 bytes
// Doc: mmio_status_read_l28 [mmio]: Read status field at offset 0x28 from sysctl base
// mmio_status_read_l28 [mmio]: Read status field at offset 0x28 from sysctl base
BOOL __fastcall mmio_status_read_l28(int a1)
{
  int v1; // r3
  unsigned int v2; // r1

  v1 = *((_DWORD *)off_12851C + 10);
  if ( !v1 )
    return 0;
  v2 = *(unsigned __int8 *)(v1 + 24);
  if ( v2 <= 2 )
    return *(_DWORD *)(a1 + 72) == v1;
  if ( *(_DWORD *)(a1 + 72) && !*(_BYTE *)(a1 + 1224) && v2 == 4 )
    return sub_128490(a1);
  return *(unsigned __int8 *)(v1 + 26) == *(unsigned __int8 *)(a1 + 107);
}

