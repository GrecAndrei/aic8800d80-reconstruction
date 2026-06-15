// mac_addr_write2 @ 0x11c4e4, size 16 bytes
// Doc: mac_addr_write2 [mac]: Write 2-byte MAC address fragment to global reg at +0xa4
// mac_addr_write2 [mac]: Write 2-byte MAC address fragment to global reg at +0xa4
_BYTE *__fastcall mac_addr_write2(_BYTE *result)
{
  _BYTE *v1; // r3

  v1 = off_11C4F4;
  *((_BYTE *)off_11C4F4 + 164) = *result;
  v1[165] = result[1];
  return result;
}

