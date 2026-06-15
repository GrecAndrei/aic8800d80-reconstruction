// v23 annotated: sub_112E28 @ 0x112e28
// Original: 112e28_sub_112E28.c
// Primary struct: <unclustered>
//
// sub_112E28 @ 0x112e28, size 174 bytes
int __fastcall sub_112E28(int f594, int a2, int a3)
{
  unsigned __int8 *v3; // r5
  char v4; // r3
  _BYTE *v5; // r4
  int v6; // r3
  int v7; // r5
  int v8; // r7
  int v9; // r6
  int v10; // r8
  int v11; // r3
  int v13; // r4

  v3 = (unsigned __int8 *)off_112ED8;
  if ( a3 )
    v4 = 3;
  else
    v4 = 2;
  *(_BYTE *)off_112ED8 = v4;
  if ( *v3 == 2 )
  {
    v5 = off_112EDC;
    v6 = *(unsigned __int8 *)off_112EDC;
    *v3 = 0;
    if ( v6 )
    {
      v7 = dword_112EE0;
      v8 = dword_112EE4;
      v9 = dword_112EE0 - 8;
      do
      {
        while ( 1 )
        {
          v10 = *(_DWORD *)(*(_DWORD *)(sub_11E7AC(v7) + 4) + 4);
          --*v5;
          list_push_tail(v9);
          v11 = *(unsigned __int8 *)(v10 + 2) >> 4;
          if ( v11 )
            break;
          ++*(_WORD *)off_112EE8;
          f594 = irq_nesting_or(1024);
          if ( !*v5 )
            goto LABEL_12;
        }
        if ( v11 == 1 )
        {
          f594 = sub_10FEF8((_DWORD *)v10);
        }
        else
        {
          sub_10DA6C(v8);
          f594 = rf_mem_read_f594(v10, 32, 1, 0);
        }
      }
      while ( *v5 );
    }
LABEL_12:
    rf_bus_mark_ne0(f594, a2);
    return 1;
  }
  else
  {
    v13 = f594;
    sub_10DA6C(dword_112EEC, *v3);
    ipc_msg_post_check(dword_112EF0, v13, a2, *v3);
    return 1;
  }
}

