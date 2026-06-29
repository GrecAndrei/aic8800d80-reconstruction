// fwstruct annotate: 121654_sub_121654.c
// sub_121654 @ 0x121654, size 116 bytes
// Doc: sub_1221654 [unknown]: Calls helper with 0x40e, checks state field
// sub_1221654 [unknown]: Calls helper with 0x40e, checks state field
int __fastcall sub_121654(int a1, int *a2, __int16 a3, __int16 a4)
{
  int v5; // r0
  int v6; // r3
  _DWORD *v7; // r4
  int v9; // r5

  v5 = rf_setup_dispatch(1038, a4, a3, 4u);
  v6 = a2[1];
  v7 = (_DWORD *)v5;
  switch ( v6 )
  {
    case 1:
      msg_parse(dword_1216D4, *(_DWORD *)(*a2 + 4));
      break;
    case 2:
      msg_parse(dword_1216D8, *a2);
      break;
    case 3:
      v9 = *a2;
      msg_parse(dword_1216D0, v9);
      if ( !v9 )
        rf_fault_dump_n36e();
      timer_set_relative(1068, 1, v9 << 10);
      break;
    default:
      msg_parse(dword_1216C8);
      break;
  }
  *v7 = (unsigned __int8)sub_113A44(0xFu);
  msg_parse(dword_1216CC);
  sub_11DE50((int)v7);
  return 0;
}

