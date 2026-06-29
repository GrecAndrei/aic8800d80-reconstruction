// fwstruct annotate: 110114_rf_lmac_init_n114.c
// rf_lmac_init_n114 @ 0x110114, size 72 bytes
// Doc: rf_lmac_init_n114 [rf]: Initialize LMAC RF subsystem state and dispatch handlers
// rf_lmac_init_n114 [rf]: Initialize LMAC RF subsystem state and dispatch handlers
int rf_lmac_init_n114()
{
  void *v0; // r8
  int result; // r0
  _DWORD *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  unsigned int v6; // r1

  v0 = off_110168;
  result = sub_11E71C(dword_11015C);
  if ( *(_WORD *)(*(_DWORD *)v0 + 8) )
  {
    v2 = off_110160;
    v3 = dword_110164;
    v4 = dword_11015C;
    v5 = 0;
    do
    {
      log_pool_alloc2_a18(v3, 0x6B8u);
      result = list_push_tail(v4);
      v6 = *(unsigned __int16 *)(*(_DWORD *)v0 + 8);
      ++v5;
      ++*v2;
    }
    while ( v6 > (unsigned __int16)v5 );
  }
  return result;
}

