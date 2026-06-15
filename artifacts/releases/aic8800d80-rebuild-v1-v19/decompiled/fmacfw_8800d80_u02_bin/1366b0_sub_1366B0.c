// sub_1366B0 @ 0x1366b0, size 72 bytes
// Doc: sub_12366B8 [unknown]: Checks byte at offset 0x19c == 1; processes r6 byte at offset 0xd
// sub_12366B8 [unknown]: Checks byte at offset 0x19c == 1; processes r6 byte at offset 0xd
_DWORD *__fastcall sub_1366B0(_DWORD *result)
{
  _DWORD *v1; // r4
  _DWORD *v2; // r6
  int v3; // r3
  int v4; // r1

  if ( *((_BYTE *)result + 108) )
  {
    v1 = result;
    if ( *((_BYTE *)result + 412) == 1 )
    {
      v2 = off_1366F8;
      if ( *((_BYTE *)off_1366F8 + 13) )
      {
        *((_BYTE *)off_1366F8 + 13) = 0;
        return sub_100B90();
      }
      else
      {
        sub_100B14();
        v3 = v2[4];
        v4 = *((_DWORD *)off_1366FC + 4);
        *((_BYTE *)v2 + 13) = 1;
        v2[7] = v1;
        return (_DWORD *)timestamp_update((int)(v2 + 5), v4 + v3);
      }
    }
  }
  return result;
}

