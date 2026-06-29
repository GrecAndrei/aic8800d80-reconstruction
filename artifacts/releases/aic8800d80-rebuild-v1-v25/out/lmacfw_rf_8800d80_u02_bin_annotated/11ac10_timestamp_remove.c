// fwstruct annotate: 11ac10_timestamp_remove.c
// timestamp_remove @ 0x11ac10, size 96 bytes
// Doc: timestamp_remove [rx]: Strip/remove timestamp field from received frame
// timestamp_remove [rx]: Strip/remove timestamp field from received frame
int __fastcall timestamp_remove(int a1)
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
    *(_DWORD *)off_11AC70 = 1;
  }
  v1 = (int *)off_11AC74;
  v2 = off_11AC78;
  v3 = *(_DWORD *)off_11AC78 == a1;
  ++*(_DWORD *)off_11AC74;
  if ( v3 )
  {
    result = sub_11E7AC(v2);
    v7 = off_11AC7C;
    if ( *(_DWORD *)v2 )
    {
      v8 = *(_DWORD *)(*(_DWORD *)v2 + 12);
      result = 0x40000;
      *((_DWORD *)off_11AC7C + 2) = 0x40000;
      v7[12] = v8;
      v7[2] = 4;
    }
    else
    {
      *((_DWORD *)off_11AC7C + 2) = 1024;
    }
  }
  else
  {
    result = list_remove_node(v2, a1);
  }
  if ( *v1 )
  {
    v5 = *v1 - 1;
    v6 = *(_DWORD *)off_11AC70;
    *v1 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

