// sub_12C7F0 @ 0x12c7f0, size 26 bytes
BOOL __fastcall sub_12C7F0(int a1, unsigned int a2)
{
  return *(unsigned __int16 *)(a1 + 4) == HIWORD(a2) && *(unsigned __int16 *)(a1 + 6) == (unsigned __int16)a2;
}

