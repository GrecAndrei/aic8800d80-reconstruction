// sub_11DAE0 @ 0x11dae0, size 26 bytes
BOOL  sub_11DAE0(int a1, unsigned int a2)
{
  return *(unsigned __int16 *)(a1 + 4) == HIWORD(a2) && *(unsigned __int16 *)(a1 + 6) == (unsigned __int16)a2;
}

