// sub_113D00 @ 0x113d00, size 128 bytes
int __fastcall sub_113D00(int *a1, unsigned int *a2)
{
  unsigned int v4; // r0
  int v5; // r4
  int result; // r0
  unsigned int v7; // r7
  unsigned int v8; // r0
  unsigned int v9; // r7
  int v10; // r7
  unsigned int v11; // r0

  v4 = sub_113A44(0xFu);
  v5 = HIWORD(v4) & 1;
  if ( (v4 & 0x10000) != 0 )
  {
    result = sub_113C48(a1, a2);
    if ( result <= 1 )
      *a1 = *a1 & 0xFFFFFF00 | (unsigned __int8)(*a1 + 1);
  }
  else
  {
    v7 = sub_113A44(0xDu);
    v8 = sub_113A44(0xEu);
    v9 = HIWORD(v7) << 16;
    if ( v9 | v8 )
    {
      v10 = (v8 << 16) | HIWORD(v9);
      v11 = HIWORD(v8);
    }
    else
    {
      v10 = sub_113A44(0xCu);
      v11 = (unsigned __int16)sub_113A44(0xDu);
      if ( v10 )
      {
        v5 = 1;
      }
      else if ( (_WORD)v11 )
      {
        v5 = 1;
      }
      else
      {
        v5 = 2;
      }
    }
    *a1 = v10;
    *a2 = v11;
    return v5;
  }
  return result;
}

