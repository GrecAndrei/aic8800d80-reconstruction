// sub_11D8F0 @ 0x11d8f0, size 178 bytes
int __fastcall sub_11D8F0(int a1)
{
  int v1; // r5
  int *v3; // r7
  int v4; // r8
  int v5; // r0
  int v6; // r0
  int v7; // r6
  int v8; // r3
  int v9; // r2
  void (__fastcall *v10)(_DWORD, int); // r3
  int v12; // r2

  v1 = *(unsigned __int8 *)(dword_11D9A4 + a1);
  if ( a1 )
    sub_11E628(0x40000000);
  else
    sub_11E628(0x8000);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_11D9A8 = 1;
  }
  v3 = (int *)off_11D9AC;
  v4 = dword_11D9BC;
  v5 = dword_11D9BC + 8 * a1;
  ++*(_DWORD *)off_11D9AC;
  v6 = sub_11E7AC(v5);
  v7 = v6;
  if ( *v3 && (v8 = *v3 - 1, v9 = *(_DWORD *)off_11D9A8, (*v3 = v8) == 0) && v9 )
  {
    __enable_irq();
    if ( **(__int16 **)off_11D9B0 >= 0 )
      goto LABEL_8;
  }
  else if ( **(__int16 **)off_11D9B0 >= 0 )
  {
    goto LABEL_8;
  }
  if ( !v6 )
    rf_cmd_send_n264(dword_11D9B8, dword_11D9B4, 190);
LABEL_8:
  v10 = *(void (__fastcall **)(_DWORD, int))(v7 + 8);
  if ( v10 )
    v10(*(_DWORD *)(v7 + 12), a1);
  v12 = dword_40021008[16 * v1] | 1;
  ++*(_WORD *)(v4 + 2 * (a1 + 12));
  dword_40021008[16 * v1] = v12;
  return 4104;
}

