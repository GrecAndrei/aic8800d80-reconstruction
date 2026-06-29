// fwstruct annotate: 12af68_sub_12AF68.c
// sub_12AF68 @ 0x12af68, size 138 bytes
// Doc: sub_122AF68 [util]: Calls helper(2), checks return against 3 (likely init/status poll)
// sub_122AF68 [util]: Calls helper(2), checks return against 3 (likely init/status poll)
int sub_12AF68()
{
  int value; // r0
  int v1; // r2
  _BYTE *v2; // r4
  int v3; // r0
  unsigned int v4; // r2
  unsigned int v5; // r3
  int v6; // r1

  if ( msg_get_value(2) != 3 )
  {
    value = msg_get_value(2);
    msg_parse(dword_12AFF4, value, v1);
  }
  if ( **(__int16 **)off_12AFF8 < 0 && msg_get_value(2) != 3 )
    sub_12F46C(dword_12B004, dword_12B000, 201);
  v2 = off_12AFFC;
  v3 = *(_DWORD *)off_12AFFC;
  v4 = *(unsigned __int8 *)(*(_DWORD *)off_12AFFC + 367);
  v5 = (unsigned __int8)(*((_BYTE *)off_12AFFC + 10) + 1);
  *((_BYTE *)off_12AFFC + 10) = v5;
  if ( v4 <= v5 || v2[11] )
  {
    sub_12CA38(v3 - 12);
    v6 = *((unsigned __int16 *)v2 + 4);
    if ( v2[11] )
    {
      ipc_msg_alloc_n0(0, v6);
      v2[11] = 0;
    }
    else
    {
      sub_12CA10(2050, v6, 2);
    }
    sub_12CD34(2);
    return 0;
  }
  else
  {
    sub_12B1A4();
    return 0;
  }
}

