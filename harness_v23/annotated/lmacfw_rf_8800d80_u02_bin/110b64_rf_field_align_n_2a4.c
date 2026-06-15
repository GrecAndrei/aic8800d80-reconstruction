// v23 annotated: rf_field_align_n_2a4 @ 0x110b64
// Original: 110b64_rf_field_align_n_2a4.c
// Primary struct: <unclustered>
//
// rf_field_align_n_2a4 @ 0x110b64, size 116 bytes
// Doc: rf_field_align_n_2a4 [rf]: RF register field alignment utility (variant 2a4)
// rf_field_align_n_2a4 [rf]: RF register field alignment utility (variant 2a4)
int __fastcall rf_field_align_n_2a4(int result)
{
  _DWORD *v1; // r1
  _DWORD *v2; // r2
  int v3; // r4
  int v4; // r5
  int v5; // r6
  _DWORD *v6; // r2
  _DWORD *v7; // r7
  int *v8; // r3
  int v9; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_110BD8 = 1;
  }
  v1 = off_110BDC;
  v2 = off_110BE0;
  v3 = *(_DWORD *)off_110BDC;
  v4 = *(_DWORD *)off_110BDC + 1;
  *(_DWORD *)off_110BDC = v4;
  *v2 = 64;
  while ( (*v2 & 0x80) != 0 )
    ;
  if ( *(_DWORD *)off_110BE4 )
  {
    v5 = dword_110BE8;
    v6 = off_110BEC;
    *(_DWORD *)(*(_DWORD *)(dword_110BE8 + 6164) + 4) = result;
  }
  else
  {
    v6 = off_110BEC;
    *(_DWORD *)off_110BE4 = result;
    v5 = dword_110BE8;
  }
  ++*v6;
  v7 = off_110BF4;
  *(_BYTE *)off_110BF0 |= 2u;
  *v7 = 64;
  *(_DWORD *)(v5 + 6164) = result;
  if ( v4 )
  {
    v8 = (int *)off_110BD8;
    *v1 = v3;
    v9 = *v8;
    if ( !v3 )
    {
      if ( v9 )
        __enable_irq();
    }
  }
  return result;
}

