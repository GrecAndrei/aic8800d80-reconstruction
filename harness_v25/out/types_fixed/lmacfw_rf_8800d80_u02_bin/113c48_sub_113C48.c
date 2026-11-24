// sub_113C48 @ 0x113c48, size 78 bytes
int __fastcall sub_113C48(int *a1, unsigned int *a2)
{
  unsigned int v4; // r4
  unsigned int v5; // r0
  unsigned int v6; // r4
  unsigned int v7; // r3
  int v8; // r4
  int result; // r0
  unsigned __int16 v10; // r0

  v4 = sub_113A44(8u);
  v5 = sub_113A44(9u);
  v6 = HIWORD(v4) << 16;
  if ( v6 | v5 )
  {
    v7 = HIWORD(v5);
    v8 = (v5 << 16) | HIWORD(v6);
    result = 0;
  }
  else
  {
    v8 = sub_113A44(7u);
    v10 = sub_113A44(8u);
    v7 = v10;
    if ( v8 )
    {
      result = 1;
    }
    else if ( v10 )
    {
      result = 1;
    }
    else
    {
      result = 2;
    }
  }
  *a1 = v8;
  *a2 = v7;
  return result;
}

