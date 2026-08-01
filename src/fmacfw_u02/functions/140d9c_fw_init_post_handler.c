// clear_197750_buffer @ 0x140d9c, size 36 bytes
// Doc: clear_197750_buffer [patch]: Posts init command 0xB to subsystem via mailbox call
// clear_197750_buffer [patch]: Posts init command 0xB to subsystem via mailbox call
int *clear_197750_buffer()
{
  int *v0; // r4
  int *result; // r0

  v0 = (int *)dword_140DC0;
  rx_phy_status_parse(0xBu, 0);
  result = memset(v0, 0, 0x1960u);
  v0[1620] = -1;
  return result;
}

