// sub_125A44 @ 0x125a44, size 66 bytes
// Doc: sub_1225A44 [unknown]: Initializes context from FW globals and config fields
// sub_1225A44 [unknown]: Initializes context from FW globals and config fields
int  sub_125A44(int a1)
{
  int v2; // r0
  uint8_t *v3; // r2
  int v4; // r1
  int v5; // r4
  int v6; // r0
  int v7; // r6

  v2 = *(unsigned __int8 *)(a1 + 9);
  v3 = off_125A90;
  v4 = dword_125A94;
  v5 = dword_125A88 + 1320 * v2;
  v6 = dword_125A8C + 620 * v2;
  v7 = *(unsigned __int8 *)(v5 + 107);
  *((uint8_t *)off_125A90 + 9) = 1;
  v3[10] = 0;
  sub_143770(v6 + 108, v4 + (v7 << 9), *(unsigned __int16 *)(a1 + 4));
  return sub_1259E0(v5);
}

