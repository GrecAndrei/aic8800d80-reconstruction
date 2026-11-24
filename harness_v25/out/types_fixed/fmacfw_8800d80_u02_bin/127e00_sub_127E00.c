// sub_127E00 @ 0x127e00, size 138 bytes
int *__fastcall sub_127E00(int a1)
{
  __int16 **v1; // r8
  int v2; // r5
  int *v4; // r6
  int v5; // r7
  int v6; // r4
  int *result; // r0

  v1 = (__int16 **)off_127EA0;
  v2 = dword_127E8C;
  v4 = (int *)(dword_127E8C + 28 * a1);
  if ( **(__int16 **)off_127EA0 < 0 )
  {
    v5 = 8 * a1;
    if ( *(unsigned __int8 *)(dword_127E8C + 28 * a1 + 24) != 255
      || (sub_12F46C(dword_127E9C, dword_127E94, 3044), **v1 < 0) )
    {
      if ( *(_BYTE *)(v2 + 4 * (v5 - a1) + 25) )
        sub_12F46C(dword_127E98, dword_127E94, 3046);
    }
  }
  else
  {
    v5 = 8 * a1;
  }
  list_push_tail(dword_127E90);
  v6 = v2 + 4 * (v5 - a1);
  result = memset_thunk(v4, 0, 0x1Cu);
  *(_WORD *)(v6 + 14) = 255;
  *(_BYTE *)(v6 + 24) = -1;
  *(_BYTE *)(v6 + 27) = -1;
  return result;
}

