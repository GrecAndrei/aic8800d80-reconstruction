// fwstruct annotate: 12ecb0_sub_12ECB0.c
// sub_12ECB0 @ 0x12ecb0, size 128 bytes
int sub_12ECB0(int result, ...)
{
  _DWORD *v1; // r6
  unsigned __int8 *v2; // r4
  __int16 **v3; // r8
  int v4; // r10
  int v5; // r9
  unsigned int v6; // r5
  unsigned int v7; // t1
  char v8; // r2
  int varg_r0; // [sp+28h] [bp+20h]
  va_list varg_r1; // [sp+2Ch] [bp+24h] BYREF

  va_start(varg_r1, result);
  varg_r0 = result;
  v1 = off_12ED30;
  if ( *((_DWORD *)off_12ED30 + 1) )
  {
    v2 = (unsigned __int8 *)result;
    v3 = (__int16 **)off_12ED34;
    v4 = dword_12ED38;
    v5 = dword_12ED3C;
    do
    {
      result = (int)v2;
      v7 = *v2++;
      v6 = v7;
      v8 = v7 + 0x80;
      if ( (v7 & 0x80) == 0 )
        break;
      if ( v6 > 0x89 )
      {
        if ( **v3 < 0 && (unsigned __int8)(v6 + 102) > 5u )
          result = sub_12F694(v5, v4, 812);
        if ( v1[1] <= v6 - 154 )
          return result;
      }
      else if ( (((unsigned int)~*v1 >> v8) & 1) != 0 )
      {
        return result;
      }
      result = (int)v2;
    }
    while ( (unsigned __int8 *)(varg_r0 + 2) != v2 );
    return sdio_transfer(result, (int)varg_r1);
  }
  return result;
}

