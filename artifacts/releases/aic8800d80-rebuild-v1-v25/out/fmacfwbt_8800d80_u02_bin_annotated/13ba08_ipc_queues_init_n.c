// fwstruct annotate: 13ba08_ipc_queues_init_n.c
// ipc_queues_init_n @ 0x13ba08, size 146 bytes
// Doc: ipc_queues_init_n [ipc]: Initialize three IPC/queue structures at offsets 0/8/0x10
// ipc_queues_init_n [ipc]: Initialize three IPC/queue structures at offsets 0/8/0x10
_DWORD *ipc_queues_init_n()
{
  _DWORD *v0; // r9
  int v1; // r5
  int v2; // r8
  unsigned int i; // r4
  _DWORD *result; // r0

  v0 = (_DWORD *)dword_13BA9C;
  bt_xtal_init_check((_DWORD *)dword_13BA9C);
  bt_xtal_init_check(v0 + 2);
  bt_xtal_init_check(v0 + 4);
  bt_xtal_init_check(v0 + 6);
  bt_xtal_init_check(v0 + 8);
  bt_xtal_init_check(v0 + 10);
  v1 = dword_13BAA0;
  v2 = dword_13BAA4;
  for ( i = 0; ; ++i )
  {
    *(_BYTE *)(v1 + 16) = -1;
    *(_BYTE *)(v1 + 26) = i;
    if ( i > 0xF )
      break;
    list_push_tail((int)v0, (_DWORD *)v1);
    rf_bus_mark_n_3b7((i << 8) & 0xFF00 | 8, 0);
LABEL_3:
    v1 += 32;
  }
  *(_DWORD *)(v1 + 28) = v2 + 268 * i;
  list_push_tail((int)(v0 + 6), (_DWORD *)v1);
  result = rf_bus_mark_n_3b7((i << 8) & 0xFF00 | 8, 0);
  if ( i != 31 )
    goto LABEL_3;
  return result;
}

