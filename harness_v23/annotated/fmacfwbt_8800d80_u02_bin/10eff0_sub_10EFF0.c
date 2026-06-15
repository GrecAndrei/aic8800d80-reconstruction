// v23 annotated: sub_10EFF0 @ 0x10eff0
// Original: 10eff0_sub_10EFF0.c
// Primary struct: log_state (cluster 11, 4 funcs)
// Fields: enable=0x0, state=0x0, level=0x4, flag=0x7, count=0x8, tick=0xa, buf=0x14, status=0x16a
//
// sub_10EFF0 @ 0x10eff0, size 90 bytes
int sub_10EFF0()
{
  _BYTE *v0; // r6
  int v1; // r5
  int v2; // r4
  int v3; // r0
  int result; // r0

  v0 = off_10F050;
  v1 = (char)(*((_BYTE *)off_10F050 + 5) + (*(_BYTE *)off_10F04C & 3));
  v2 = *((char *)off_10F050 + 7) - v1;
  if ( v2 < -62 )
    LOBYTE(v2) = -62;
  sub_1029F8(v2);
  v3 = dword_10F054;
  v0[7] = v2;
  result = sub_12ECB0(v3, (char)v2, v1);
  if ( (char)v2 >= -61 )
    return sub_124F60(v0 + 12, *((_DWORD *)off_10F058 + 4) + 30000 * *((unsigned __int16 *)v0 + 4));
  v0[11] = 0;
  return result;
}

