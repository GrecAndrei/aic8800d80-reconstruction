// sub_136A28 @ 0x136a28, size 100 bytes
int __fastcall sub_136A28(int result, int a2)
{
  int v3; // r3
  int v4; // r0

  if ( (*(_WORD *)(result + 30) & 0x1000) != 0 )
  {
    v3 = *(unsigned __int8 *)(a2 + 310);
    if ( ((unsigned __int8)v3 & *(_BYTE *)(dword_136A8C + *(unsigned __int8 *)(result + 27))) != 0 )
    {
      if ( (*(_BYTE *)(a2 + 53) & 8) == 0 )
      {
        *(_BYTE *)(a2 + 53) |= 8u;
        if ( v3 == 15 )
          goto LABEL_5;
      }
    }
    else if ( (*(_BYTE *)(a2 + 53) & 2) == 0 )
    {
      *(_BYTE *)(a2 + 53) |= 2u;
LABEL_5:
      v4 = sub_12C7EC(65, 0, 5, 4u);
      *(_WORD *)v4 = *(_WORD *)(a2 + 32);
      *(_BYTE *)(v4 + 3) = *(_BYTE *)(a2 + 34);
      *(_BYTE *)(v4 + 2) = 1;
      return sub_12C84C(v4);
    }
  }
  return result;
}

