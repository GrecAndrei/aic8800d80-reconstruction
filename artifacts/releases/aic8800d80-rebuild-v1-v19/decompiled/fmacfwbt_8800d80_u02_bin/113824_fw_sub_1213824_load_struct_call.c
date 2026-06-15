// fw_sub_1213824_load_struct_call @ 0x113824, size 52 bytes
// Doc: fw_sub_1213824_load_struct_call [unknown]: Loads two struct pointers, calls helper 0x12d468, then reads 16-bit field at [r3+4] from primary struct
// fw_sub_1213824_load_struct_call [unknown]: Loads two struct pointers, calls helper 0x12d468, then reads 16-bit field at [r3+4] from primary struct
int fw_sub_1213824_load_struct_call()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = off_113858;
  result = bt_xtal_init_check(dword_11385C);
  if ( *(_WORD *)(*(_DWORD *)v0 + 4) )
  {
    v2 = dword_113860;
    v3 = dword_11385C;
    v4 = 0;
    do
    {
      log_pool_alloc2(v2, 0x7Cu);
      result = list_push_tail(v3);
      ++v4;
    }
    while ( *(unsigned __int16 *)(*(_DWORD *)v0 + 4) > (unsigned int)(unsigned __int16)v4 );
  }
  return result;
}

