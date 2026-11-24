// sub_13BD60 @ 0x13bd60, size 64 bytes
// Doc: sub_123BD60 [util]: Builds a 16-bit control word with shift/and/or of args and constant 8
// sub_123BD60 [util]: Builds a 16-bit control word with shift/and/or of args and constant 8
int __fastcall sub_13BD60(char a1, int a2)
{
  int v2; // r4
  int v4; // r0
  int v5; // r1
  int v6; // r2

  v2 = a2;
  v4 = sub_12C92C(40, 0, ((_WORD)a2 << 8) | 8, 8u);
  v5 = dword_13BDA0 + 32 * v2;
  v6 = *(unsigned __int8 *)(v5 + 17);
  *(_BYTE *)(v4 + 1) = a1;
  *(_BYTE *)v4 = v6 != 1;
  *(_BYTE *)(v4 + 2) = *(_BYTE *)(v5 + 22);
  LOWORD(v2) = *(_WORD *)(v5 + 20);
  *(_WORD *)(v4 + 6) = *(_WORD *)(v5 + 12);
  *(_WORD *)(v4 + 4) = v2;
  return sdio_buffer_prepare_n_4e8(v4);
}

