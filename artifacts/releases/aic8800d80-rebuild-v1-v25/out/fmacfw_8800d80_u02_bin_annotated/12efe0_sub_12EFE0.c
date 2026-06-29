// fwstruct annotate: 12efe0_sub_12EFE0.c
// sub_12EFE0 @ 0x12efe0, size 120 bytes
// Doc: sub_122EFE0 [ipc]: Host message send wrapper invoking message dispatch
// sub_122EFE0 [ipc]: Host message send wrapper invoking message dispatch
int __fastcall sub_12EFE0(int a1, int *a2, __int16 a3, __int16 a4)
{
  int *v5; // r0
  int *v6; // r5
  _DWORD *v7; // r0
  int v8; // r3
  int v9; // r0
  int v10; // r2

  v5 = (int *)sub_12C92C(1027, a4, a3, 8u);
  v6 = v5;
  if ( (unsigned int)**(unsigned __int8 **)off_12F058 - 1 <= 1 )
  {
    v10 = a2[1];
    *(_QWORD *)v5 = *(_QWORD *)a2;
  }
  else
  {
    v7 = (_DWORD *)*a2;
    if ( (((unsigned int)*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      rf_reg_write_wait((int)v7, a2[1], 1);
      v9 = sub_10ED84(*a2, 1);
      v8 = *a2;
    }
    else
    {
      *v7 = a2[1];
      v8 = *a2;
      v9 = *(_DWORD *)*a2;
    }
    v6[1] = v9;
    v10 = a2[1];
    *v6 = v8;
  }
  msg_parse(dword_12F05C, v10);
  sdio_buffer_prepare_n_4e8((int)v6);
  return 0;
}

