// msg_get_value @ 0x12ce88, size 130 bytes
// Doc: message_dispatch_n500 [ipc]: Dispatch host message by type byte to handler
// message_dispatch_n500 [ipc]: Dispatch host message by type byte to handler
int  msg_get_value(unsigned int a1)
{
  __int16 **v1; // r5
  unsigned int v2; // r6
  int v3; // r4
  int v4; // r5
  int v5; // r4
  int v7; // r3

  v1 = (__int16 **)off_12CF0C;
  v2 = a1 >> 8;
  v3 = (unsigned __int8)a1;
  if ( **(__int16 **)off_12CF0C >= 0 )
    goto LABEL_2;
  if ( (unsigned __int8)a1 > 0xDu )
  {
    sub_12F46C(dword_12CF1C, dword_12CF14, 210);
    if ( **v1 >= 0 )
    {
LABEL_2:
      v4 = dword_12CF10;
      v5 = 16 * v3;
      return *(unsigned __int16 *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
    }
    if ( v3 != 14 )
      sub_12F46C(dword_12CF24, dword_12CF20, 183);
  }
  else if ( (unsigned __int8)a1 != 13 )
  {
    goto LABEL_6;
  }
  sub_12F46C(dword_12CF28, dword_12CF14, 211);
  if ( **v1 >= 0 )
    goto LABEL_2;
LABEL_6:
  v4 = dword_12CF10;
  v7 = dword_12CF10 + 16 * v3;
  v5 = 16 * v3;
  if ( *(unsigned __int16 *)(v7 + 14) > v2 )
    return *(unsigned __int16 *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
  sub_12F46C(dword_12CF18, dword_12CF14, 212);
  return *(unsigned __int16 *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
}

