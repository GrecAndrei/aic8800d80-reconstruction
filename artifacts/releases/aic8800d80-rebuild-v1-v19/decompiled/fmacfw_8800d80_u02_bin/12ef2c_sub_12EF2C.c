// sub_12EF2C @ 0x12ef2c, size 72 bytes
// Doc: sub_122EF2C [mmio]: Read register with mask 0x10000 shift and dispatch to handler
// sub_122EF2C [mmio]: Read register with mask 0x10000 shift and dispatch to handler
int __fastcall sub_12EF2C(int a1, int *a2, __int16 a3, __int16 a4)
{
  int v5; // r0
  _DWORD *v6; // r1
  _DWORD *v7; // r4
  int v9; // r0

  v5 = sub_12C92C(1025, a4, a3, 8u);
  v6 = (_DWORD *)*a2;
  v7 = (_DWORD *)v5;
  if ( (((unsigned int)*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
  {
    v9 = sub_10ED84(*a2, 1);
    v6 = (_DWORD *)*a2;
    v7[1] = v9;
  }
  else
  {
    *(_DWORD *)(v5 + 4) = *v6;
  }
  *v7 = v6;
  msg_parse(dword_12EF74);
  sdio_buffer_prepare_n_4e8((int)v7);
  return 0;
}

