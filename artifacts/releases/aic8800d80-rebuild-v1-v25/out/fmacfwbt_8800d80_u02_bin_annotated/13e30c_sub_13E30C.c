// fwstruct annotate: 13e30c_sub_13E30C.c
// sub_13E30C @ 0x13e30c, size 78 bytes
unsigned __int16 *__fastcall sub_13E30C(unsigned __int16 *result)
{
  unsigned int v1; // r3
  int v2; // r1
  unsigned int v3; // r2
  int v4; // r4
  int v5; // r3

  v1 = *result;
  if ( *result )
  {
    v2 = *((unsigned __int8 *)result + 9);
    v3 = result[1] << 16;
    *((_BYTE *)result + 8) = 0;
    v4 = v3 / v1;
    if ( v2 )
    {
      result[2] = (3 * (unsigned int)result[2] + v4) >> 2;
    }
    else
    {
      if ( v3 >= v1 )
        LOWORD(v2) = v4 - 1;
      result[2] = v2;
      *((_BYTE *)result + 9) = 1;
    }
  }
  else
  {
    v5 = *((unsigned __int8 *)result + 8);
    if ( v5 != 255 )
      *((_BYTE *)result + 8) = v5 + 1;
  }
  return result;
}

