// v23 annotated: sub_118940 @ 0x118940
// Original: 118940_sub_118940.c
// Primary struct: <unclustered>
//
// sub_118940 @ 0x118940, size 172 bytes
// Doc: sub_1218940 [util]: Helper with 3 args loading pointers from a 3-entry table (0x182b60/0x167bc0/0x167b74)
// sub_1218940 [util]: Helper with 3 args loading pointers from a 3-entry table (0x182b60/0x167bc0/0x167b74)
int __fastcall sub_118940(int a1, int a2, int a3)
{
  __int16 **v3; // r8
  int v4; // r10
  int v5; // r9
  int v9; // r4
  int v10; // r1

  v3 = (__int16 **)off_1189EC;
  v4 = dword_1189F0;
  v5 = dword_1189F4;
  while ( 1 )
  {
    v9 = rf_bus_mark_n100_d2d0(a2);
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
      sub_118CE0(v9);
      v9 = rf_bus_mark_n100_d2d0(a2);
      if ( !v9 )
        return sub_118D28();
    }
    *(_DWORD *)(v10 + 4) |= 0x800000u;
    rf_status_check(v9, (_DWORD *)(v10 + 4));
    sub_11608C(v9);
    if ( sub_13AF80(v9, 1) )
    {
      if ( **v3 < 0 && !a3 )
        sub_12F46C(v5, v4, 1105);
      list_push_tail(a3);
    }
    else
    {
      rf_msg_forward_n_1f4(a1, v9);
    }
  }
  return sub_118D28();
}

