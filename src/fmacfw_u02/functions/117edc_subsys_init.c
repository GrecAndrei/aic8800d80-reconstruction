// init_buf_188290 @ 0x117edc, size 56 bytes
// Doc: init_buf_188290 [util]: Initializes subsystem via callback registration
// init_buf_188290 [util]: Initializes subsystem via callback registration
int init_buf_188290()
{
  int v0; // r4

  v0 = dword_117F14;
  memset((int *)dword_117F14, 0, 0x28u);
  zero_8_bytes(v0);
  zero_8_bytes(v0 + 8);
  zero_8_bytes(v0 + 16);
  zero_8_bytes(v0 + 24);
  return zero_8_bytes(v0 + 32);
}

