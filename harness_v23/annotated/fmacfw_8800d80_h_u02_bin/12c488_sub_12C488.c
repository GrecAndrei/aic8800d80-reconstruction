// v23 annotated: sub_12C488 @ 0x12c488
// Original: 12c488_sub_12C488.c
// Primary struct: <unclustered>
//
// sub_12C488 @ 0x12c488, size 26 bytes
BOOL __fastcall sub_12C488(int a1, unsigned int a2)
{
  return *(unsigned __int16 *)(a1 + 4) == HIWORD(a2) && *(unsigned __int16 *)(a1 + 6) == (unsigned __int16)a2;
}

