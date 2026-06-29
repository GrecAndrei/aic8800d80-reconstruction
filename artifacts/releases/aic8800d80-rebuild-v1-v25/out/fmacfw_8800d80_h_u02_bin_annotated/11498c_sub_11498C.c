// fwstruct annotate: 11498c_sub_11498C.c
// sub_11498C @ 0x11498c, size 58 bytes
int __fastcall sub_11498C(int *a1)
{
  unsigned __int8 v2; // r0
  int v3; // r2
  int result; // r0
  int v5; // r3

  v2 = MEMORY[0x1FC](16);
  v3 = v2 >> 4;
  if ( (v2 & 0xF0) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !v2 )
    {
      *a1 = 0;
      return 2;
    }
    v3 = v2;
    result = 1;
  }
  if ( (v3 & 8) != 0 )
    v5 = v3 & 7;
  else
    v5 = -v3;
  if ( (v3 & 8) != 0 )
    ++v5;
  *a1 = v5;
  return result;
}

