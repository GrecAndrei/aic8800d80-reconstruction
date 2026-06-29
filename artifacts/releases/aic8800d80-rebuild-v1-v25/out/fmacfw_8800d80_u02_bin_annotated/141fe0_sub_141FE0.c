// fwstruct annotate: 141fe0_sub_141FE0.c
// sub_141FE0 @ 0x141fe0, size 80 bytes
int __fastcall sub_141FE0(int a1, int a2, char a3)
{
  int result; // r0
  unsigned __int16 v5; // r3
  int v6; // r0
  int v7; // r1
  __int64 v8; // r2
  int v9; // [sp+Ch] [bp-4h] BYREF

  result = sub_141B70((int)&v9, dword_142034 + 1320 * a1, dword_142030 + 696 * a2, 7, 0);
  if ( result )
  {
    v5 = result + 1;
    *(_BYTE *)(*(_DWORD *)(v9 + 72) + result + 108) = a3;
    v6 = v9;
    v7 = *(_DWORD *)(v9 + 76);
    LODWORD(v8) = *(_DWORD *)(v7 + 28) - 1 + v5;
    HIDWORD(v8) = v5 + 4;
    *(_QWORD *)(v7 + 32) = v8;
    return rf_param_get_status(v6, 3);
  }
  return result;
}

