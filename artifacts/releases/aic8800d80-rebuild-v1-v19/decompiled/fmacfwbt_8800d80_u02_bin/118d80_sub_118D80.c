// sub_118D80 @ 0x118d80, size 172 bytes
int __fastcall sub_118D80(int a1, int a2, int a3)
{
  __int16 **v3; // r8
  int v4; // r10
  int v5; // r9
  int v9; // r4
  int v10; // r1

  v3 = (__int16 **)off_118E2C;
  v4 = dword_118E30;
  v5 = dword_118E34;
  while ( 1 )
  {
    v9 = sub_12D4F8(a2);
    if ( !v9 )
      break;
    while ( 1 )
    {
      v10 = *(_DWORD *)(v9 + 76);
      if ( *(_DWORD *)(v9 + 68) )
      {
        *(_DWORD *)(v10 + 4) = 2080374784;
      }
      else if ( *(int *)(v10 + 4) >= 0 )
      {
        *(_DWORD *)(v10 + 4) = 0x40000000;
      }
      if ( *(_WORD *)(v9 + 4) )
        break;
      sub_119120(v9);
      v9 = sub_12D4F8(a2);
      if ( !v9 )
        return rx_buf_init_n168();
    }
    *(_DWORD *)(v10 + 4) |= 0x800000u;
    flag_check_1218170(v9, (_DWORD *)(v10 + 4));
    sub_1164CC(v9);
    if ( sub_13B01C(v9, 1) )
    {
      if ( **v3 < 0 && !a3 )
        sub_12F694(v5, v4, 1105);
      list_push_tail(a3);
    }
    else
    {
      fmac_bt_event_handler(a1, v9);
    }
  }
  return rx_buf_init_n168();
}

