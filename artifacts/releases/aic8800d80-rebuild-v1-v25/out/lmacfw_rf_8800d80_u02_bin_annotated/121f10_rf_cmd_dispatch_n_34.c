// fwstruct annotate: 121f10_rf_cmd_dispatch_n_34.c
// rf_cmd_dispatch_n_34 @ 0x121f10, size 50 bytes
// Doc: rf_mem_write_n_ee [rf]: RF memory write with parameter validation
// rf_mem_write_n_ee [rf]: RF memory write with parameter validation
int __fastcall rf_cmd_dispatch_n_34(int a1)
{
  int v2; // r0
  int v3; // r0
  int v5; // r3

  v2 = sub_1288C0(a1);
  if ( v2 <= 2 )
    return 4;
  v3 = v2 + a1;
  if ( *(_BYTE *)(v3 - 2) != 46 )
    return 4;
  v5 = *(unsigned __int8 *)(v3 - 1);
  if ( v5 == 98 )
    return 1;
  if ( v5 == 104 )
    return 2;
  return -1;
}

