// mac_addr_copy_to_global @ 0x11c924, size 16 bytes
// Doc: mac_addr_copy_to_global [mac]: Copy 2-byte MAC address fragment to global state buffer
// mac_addr_copy_to_global [mac]: Copy 2-byte MAC address fragment to global state buffer
_BYTE *__fastcall mac_addr_copy_to_global(_BYTE *result)
{
  _BYTE *v1; // r3

  v1 = off_11C934;
  *((_BYTE *)off_11C934 + 164) = *result;
  v1[165] = result[1];
  return result;
}

