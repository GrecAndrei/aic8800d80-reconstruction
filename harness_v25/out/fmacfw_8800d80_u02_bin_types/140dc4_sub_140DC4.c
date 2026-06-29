// sub_140DC4 @ 0x140dc4, size 52 bytes
int  sub_140DC4(char a1, char a2, char a3, int a4, char a5)
{
  int v5; // r4
  __int16 v6; // r6
  int result; // r0
  uint8_t v8[140]; // [sp+0h] [bp-8Ch] BYREF

  v5 = dword_140DF8;
  v8[2] = a5;
  v6 = *(uint16_t *)(dword_140DF8 + 6488);
  *(uint8_t *)(dword_140DF8 + 6488) = a2;
  *(uint8_t *)(v5 + 6489) = a1;
  v8[0] = a3;
  result = sub_140AE4((int)v8, a4);
  *(uint16_t *)(v5 + 6488) = v6;
  return result;
}

