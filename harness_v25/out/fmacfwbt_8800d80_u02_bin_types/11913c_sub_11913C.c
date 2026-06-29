// sub_11913C @ 0x11913c, size 40 bytes
int  sub_11913C(int result, int a2)
{
  int v2; // r4
  int ( *v4)(uint32_t, uint32_t); // r3

  v2 = result;
  if ( !*(uint8_t *)(result + 96) )
    result = list_push_tail(dword_119164);
  if ( a2 )
  {
    v4 = *(int ( **)(uint32_t, uint32_t))(v2 + 88);
    if ( v4 )
      return v4(*(uint32_t *)(v2 + 92), 0);
  }
  return result;
}

