// v23 annotated: sub_12EA88 @ 0x12ea88
// Original: 12ea88_sub_12EA88.c
// Primary struct: <unclustered>
//
// sub_12EA88 @ 0x12ea88, size 128 bytes
int sub_12EA88(int result, ...)
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
  v1 = off_12EB08;
  if ( *((_DWORD *)off_12EB08 + 1) )
  {
    v2 = (unsigned __int8 *)result;
    v3 = (__int16 **)off_12EB0C;
    v4 = dword_12EB10;
    v5 = dword_12EB14;
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
          result = sub_12F46C(v5, v4, 812);
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
    return sub_10D808(result, (int)varg_r1);
  }
  return result;
}

