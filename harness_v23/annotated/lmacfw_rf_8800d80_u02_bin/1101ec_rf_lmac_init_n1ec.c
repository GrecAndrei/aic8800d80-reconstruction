// v23 annotated: rf_lmac_init_n1ec @ 0x1101ec
// Original: 1101ec_rf_lmac_init_n1ec.c
// Primary struct: <unclustered>
//
// rf_lmac_init_n1ec @ 0x1101ec, size 54 bytes
// Doc: rf_lmac_init_n1ec [rf]: Initialize LMAC RF state with config
// rf_lmac_init_n1ec [rf]: Initialize LMAC RF state with config
int rf_lmac_init_n1ec()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_110224 = 1;
  }
  v0 = (int *)off_110228;
  v1 = dword_11022C;
  ++*(_DWORD *)off_110228;
  result = list_push_tail(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_110224;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

