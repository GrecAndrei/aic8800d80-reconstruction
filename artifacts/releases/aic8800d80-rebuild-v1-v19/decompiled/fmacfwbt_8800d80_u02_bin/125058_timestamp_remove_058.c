// timestamp_remove_058 @ 0x125058, size 96 bytes
// Doc: timestamp_remove_058 [util]: strip/clear timestamp field from message
// timestamp_remove_058 [util]: strip/clear timestamp field from message
int __fastcall timestamp_remove_058(int a1)
{
  int *v1; // r4
  void *v2; // r5
  bool v3; // zf
  int result; // r0
  int v5; // r3
  int v6; // r2
  _DWORD *v7; // r3
  int v8; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1250B8 = 1;
  }
  v1 = (int *)off_1250BC;
  v2 = off_1250C0;
  v3 = *(_DWORD *)off_1250C0 == a1;
  ++*(_DWORD *)off_1250BC;
  if ( v3 )
  {
    result = sub_12D4F8(v2);
    v7 = off_1250C4;
    if ( *(_DWORD *)v2 )
    {
      v8 = *(_DWORD *)(*(_DWORD *)v2 + 12);
      result = 0x40000;
      *((_DWORD *)off_1250C4 + 2) = 0x40000;
      v7[12] = v8;
      v7[2] = 4;
    }
    else
    {
      *((_DWORD *)off_1250C4 + 2) = 1024;
    }
  }
  else
  {
    result = list_remove_node_d510(v2, a1);
  }
  if ( *v1 )
  {
    v5 = *v1 - 1;
    v6 = *(_DWORD *)off_1250B8;
    *v1 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

