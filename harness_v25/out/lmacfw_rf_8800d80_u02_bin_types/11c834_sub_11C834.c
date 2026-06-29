// sub_11C834 @ 0x11c834, size 24 bytes
int  sub_11C834(int a1, int a2, int a3)
{
  int result; // r0

  result = dword_11C84C + 32 * a1;
  if ( a3 )
    ++*(uint32_t *)(result + 20);
  else
    ++*(uint32_t *)(result + 16);
  return result;
}

