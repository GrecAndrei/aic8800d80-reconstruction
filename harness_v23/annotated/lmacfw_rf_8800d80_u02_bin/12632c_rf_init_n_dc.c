// v23 annotated: rf_init_n_dc @ 0x12632c
// Original: 12632c_rf_init_n_dc.c
// Primary struct: mmio_clock_gate (cluster 1, 25 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// rf_init_n_dc @ 0x12632c, size 248 bytes
// Doc: rf_init_n_dc [rf]: Initialize RF subsystem globals and call sub-init routine
// rf_init_n_dc [rf]: Initialize RF subsystem globals and call sub-init routine
int rf_init_n_dc()
{
  int v0; // r0
  int v1; // r4
  _BYTE *v2; // r8
  unsigned __int16 *v3; // r5
  int v4; // r9
  int v5; // r1
  _BYTE *v6; // r5
  _WORD *v7; // r4
  _DWORD *v8; // r0
  _DWORD *v9; // r2
  _DWORD *v10; // r2
  unsigned int *v11; // r4
  int v12; // r1
  int result; // r0
  unsigned int v14; // r3
  int *v15; // r3
  int v16; // r3
  _DWORD *v17; // r3

  v0 = dword_126428;
  *(_BYTE *)off_126424 = 0;
  msg_parse(v0);
  v1 = *(unsigned __int8 *)off_12642C;
  if ( v1 == 1 )
  {
    v17 = off_126450;
    *(_DWORD *)off_126450 &= ~0x100u;
    *v17 &= ~0x200u;
    *v17 &= ~0x400u;
    goto LABEL_15;
  }
  if ( *(_BYTE *)off_12642C )
  {
LABEL_15:
    msg_parse(
      dword_126454,
      *(unsigned __int8 *)off_126434,
      *(unsigned __int16 *)off_126430,
      *((unsigned __int8 *)off_126430 + 2),
      *((char *)off_126430 + 3),
      *((char *)off_126430 + 4),
      *((char *)off_126430 + 5));
    goto LABEL_7;
  }
  v2 = off_126458;
  if ( *(_BYTE *)off_126458 )
  {
    v3 = (unsigned __int16 *)off_126430;
    v4 = dword_126454;
    v5 = *(unsigned __int8 *)off_12642C;
    do
    {
      msg_parse(
        v4,
        v5 + 1,
        v3[4 * v5],
        LOBYTE(v3[4 * v5 + 1]),
        SHIBYTE(v3[4 * v5 + 1]),
        SLOBYTE(v3[4 * v5 + 2]),
        SHIBYTE(v3[4 * v5 + 2]));
      v5 = (unsigned __int8)++v1;
    }
    while ( (unsigned __int8)*v2 > (unsigned int)(unsigned __int8)v1 );
  }
  v6 = off_126434;
  v7 = off_126438;
  sub_100200((int *)off_126430, 0, 8u);
  v8 = off_12643C;
  v9 = off_126440;
  *v6 = 1;
  *v2 = 1;
  *v7 = 0;
  *v8 = 0;
  *v9 = 0;
LABEL_7:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_126444 = 1;
  }
  v10 = off_126448;
  v11 = (unsigned int *)off_12644C;
  v12 = *(_DWORD *)off_126448;
  result = *(_DWORD *)off_126448 + 1;
  v14 = *(_DWORD *)off_12644C & 0xFFFFFBFF;
  *(_DWORD *)off_126448 = result;
  *v11 = v14;
  if ( result )
  {
    v15 = (int *)off_126444;
    *v10 = v12;
    v16 = *v15;
    if ( !v12 )
    {
      if ( v16 )
        __enable_irq();
    }
  }
  return result;
}

