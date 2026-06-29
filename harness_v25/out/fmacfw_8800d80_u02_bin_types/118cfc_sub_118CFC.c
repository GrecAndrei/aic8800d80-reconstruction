// sub_118CFC @ 0x118cfc, size 40 bytes
// Doc: sub_1218CFC [unknown]: Unknown helper at 0x1218cfc in fmacfw
// sub_1218CFC [unknown]: Unknown helper at 0x1218cfc in fmacfw
int  sub_118CFC(int result, int a2)
{
  int v2; // r4
  int ( *v4)(uint32_t, uint32_t); // r3

  v2 = result;
  if ( !*(uint8_t *)(result + 96) )
    result = list_push_tail(dword_118D24);
  if ( a2 )
  {
    v4 = *(int ( **)(uint32_t, uint32_t))(v2 + 88);
    if ( v4 )
      return v4(*(uint32_t *)(v2 + 92), 0);
  }
  return result;
}

