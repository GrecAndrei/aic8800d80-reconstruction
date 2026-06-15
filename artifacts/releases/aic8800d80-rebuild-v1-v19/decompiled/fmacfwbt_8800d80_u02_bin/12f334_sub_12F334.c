// sub_12F334 @ 0x12f334, size 116 bytes
int __fastcall sub_12F334(int a1, int *a2, __int16 a3, __int16 a4)
{
  int v5; // r0
  int v6; // r3
  _DWORD *v7; // r4
  int v9; // r5

  v5 = rf_bus_setup_n3a8(1038, a4, a3, 4u);
  v6 = a2[1];
  v7 = (_DWORD *)v5;
  switch ( v6 )
  {
    case 1:
      sub_12ECB0(dword_12F3B4, *(_DWORD *)(*a2 + 4));
      break;
    case 2:
      sub_12ECB0(dword_12F3B8, *a2);
      break;
    case 3:
      v9 = *a2;
      sub_12ECB0(dword_12F3B0, v9);
      if ( !v9 )
        sub_12F2F0();
      rf_level_apply_80c(1068, 1, v9 << 10);
      break;
    default:
      sub_12ECB0(dword_12F3A8);
      break;
  }
  *v7 = (unsigned __int8)indirect_call_trampoline();
  sub_12ECB0(dword_12F3AC);
  sub_12CBB4((int)v7);
  return 0;
}

