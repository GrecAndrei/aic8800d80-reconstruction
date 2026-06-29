// fwstruct annotate: 12e948_msg_parse.c
// msg_parse @ 0x12e948, size 128 bytes
// Doc: msg_parse [ipc]: Parse an incoming message using the message table at 0x18274c
// msg_parse [ipc]: Parse an incoming message using the message table at 0x18274c
int msg_parse(int result, ...)
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
  v1 = off_12E9C8;
  if ( *((_DWORD *)off_12E9C8 + 1) )
  {
    v2 = (unsigned __int8 *)result;
    v3 = (__int16 **)off_12E9CC;
    v4 = dword_12E9D0;
    v5 = dword_12E9D4;
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
          result = sub_12F32C(v5, v4, 812);
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
    return sub_10D6C8(result, (int)varg_r1);
  }
  return result;
}

