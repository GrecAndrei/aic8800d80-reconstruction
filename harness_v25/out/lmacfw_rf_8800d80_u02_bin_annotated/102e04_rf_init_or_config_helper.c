// fwstruct annotate: 102e04_rf_init_or_config_helper.c
// rf_init_or_config_helper @ 0x102e04, size 60 bytes
// Doc: rf_init_or_config_helper [rf]: RF firmware initialization/config helper saving r4-r6,lr
// rf_init_or_config_helper [rf]: RF firmware initialization/config helper saving r4-r6,lr
int __fastcall rf_init_or_config_helper(int a1)
{
  __int64 v1; // kr00_8
  int v2; // r4

  if ( a1 )
  {
    v1 = *(_QWORD *)((char *)off_102E40 + 4);
    v2 = *(_DWORD *)off_102E40;
  }
  else
  {
    v2 = *(_DWORD *)off_102E44;
    v1 = *(_QWORD *)((char *)off_102E44 + 4);
  }
  lmac_sub_init(0, 32, 0x10u, SHIDWORD(v1));
  lmac_sub_init(0, 48, 0x10u, v1);
  return lmac_sub_init(0, 64, 0x10u, v2);
}

