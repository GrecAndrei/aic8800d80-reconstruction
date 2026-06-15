// v23 annotated: sub_12C218 @ 0x12c218
// Original: 12c218_sub_12C218.c
// Primary struct: <unclustered>
//
// sub_12C218 @ 0x12c218, size 178 bytes
int __fastcall sub_12C218(int a1)
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

  v1 = *(unsigned __int8 *)(dword_12C2CC + a1);
  if ( a1 )
    sub_12D00C(0x40000000);
  else
    sub_12D00C(1024);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12C2D0 = 1;
  }
  v3 = (int *)off_12C2D4;
  v4 = dword_12C2E4;
  v5 = dword_12C2E4 + 8 * a1;
  ++*(_DWORD *)off_12C2D4;
  v6 = sub_12D190(v5);
  v7 = v6;
  if ( *v3 && (v8 = *v3 - 1, v9 = *(_DWORD *)off_12C2D0, (*v3 = v8) == 0) && v9 )
  {
    __enable_irq();
    if ( **(__int16 **)off_12C2D8 >= 0 )
      goto LABEL_8;
  }
  else if ( **(__int16 **)off_12C2D8 >= 0 )
  {
    goto LABEL_8;
  }
  if ( !v6 )
    sub_12F32C(dword_12C2E0, dword_12C2DC, 190);
LABEL_8:
  v10 = *(void (__fastcall **)(_DWORD, int))(v7 + 8);
  if ( v10 )
    v10(*(_DWORD *)(v7 + 12), a1);
  v12 = dword_40021000[16 * v1 + 2] | 1;
  ++*(_WORD *)(v4 + 2 * (a1 + 12));
  dword_40021000[16 * v1 + 2] = v12;
  return 4104;
}

