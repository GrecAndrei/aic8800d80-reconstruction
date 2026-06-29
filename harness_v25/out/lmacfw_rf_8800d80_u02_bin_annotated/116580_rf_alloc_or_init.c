// fwstruct annotate: 116580_rf_alloc_or_init.c
// rf_alloc_or_init @ 0x116580, size 38 bytes
// Doc: rf_alloc_or_init [rf]: Allocates/init RF context via 0x11e7ac then stores result
// rf_alloc_or_init [rf]: Allocates/init RF context via 0x11e7ac then stores result
int __fastcall rf_alloc_or_init(int a1, int a2)
{
  int v4; // r0
  int v5; // r1
  int v6; // r4

  v4 = sub_11E7AC(dword_1165A8);
  v6 = v4;
  if ( v4 )
  {
    rf_buf_setup_check(v4, a1, a2);
    return v6;
  }
  else
  {
    msg_parse(dword_1165AC, v5);
    return 0;
  }
}

