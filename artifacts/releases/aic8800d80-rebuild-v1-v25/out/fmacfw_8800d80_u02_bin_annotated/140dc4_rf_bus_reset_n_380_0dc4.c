// fwstruct annotate: 140dc4_rf_bus_reset_n_380_0dc4.c
// rf_bus_reset_n_380_0dc4 @ 0x140dc4, size 52 bytes
// Doc: rf_bus_reset_n_380_0dc4 [rf]: Reset RF control bus by toggling MMIO control registers
// rf_bus_reset_n_380_0dc4 [rf]: Reset RF control bus by toggling MMIO control registers
int __fastcall rf_bus_reset_n_380_0dc4(char a1, char a2, char a3, int a4, char a5)
{
  int v5; // r4
  __int16 v6; // r6
  int result; // r0
  _BYTE v8[140]; // [sp+0h] [bp-8Ch] BYREF

  v5 = dword_140DF8;
  v8[2] = a5;
  v6 = *(_WORD *)(dword_140DF8 + 6488);
  *(_BYTE *)(dword_140DF8 + 6488) = a2;
  *(_BYTE *)(v5 + 6489) = a1;
  v8[0] = a3;
  result = sub_140AE4((int)v8, a4);
  *(_WORD *)(v5 + 6488) = v6;
  return result;
}

