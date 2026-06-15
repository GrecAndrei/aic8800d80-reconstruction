// sub_126DD8 @ 0x126dd8, size 108 bytes
// Doc: rf_level_apply_n54 [rf]: Applies RF TX power level bytes to register block
// rf_level_apply_n54 [rf]: Applies RF TX power level bytes to register block
int __fastcall sub_126DD8(int a1)
{
  _BYTE *v1; // r3
  int v2; // r2
  int v3; // r0
  char v4; // lr
  char v5; // r9
  char v6; // r8
  char v7; // r5
  int v8; // r7
  int v9; // r6
  char v10; // r4
  char v11; // r12
  char v12; // r1

  v1 = rf_level_apply_n6c;
  v2 = *((char *)rf_level_apply_n6c + 2) + 7;
  v3 = a1 + 7;
  v4 = *(_BYTE *)(rf_level_apply_n74 + v2);
  v5 = *(_BYTE *)(rf_level_apply_n70 + v2 + 16);
  v6 = *(_BYTE *)(rf_level_apply_n70 + v2 + 32);
  v7 = *(_BYTE *)(rf_level_apply_n70 + v3 + 16);
  v8 = rf_level_apply_n74 + v2;
  LOBYTE(v2) = *(_BYTE *)(rf_level_apply_n70 + v3) - *(_BYTE *)(rf_level_apply_n70 + v2);
  v9 = rf_level_apply_n74 + v3;
  v10 = *(_BYTE *)(rf_level_apply_n70 + v3 + 32);
  LOBYTE(v3) = *(_BYTE *)(rf_level_apply_n74 + v3);
  v11 = *(_BYTE *)(v8 + 16);
  v12 = *(_BYTE *)(v9 + 16);
  LOBYTE(v8) = *(_BYTE *)(v8 + 32);
  *((_BYTE *)rf_level_apply_n6c + 8) = v2;
  LOBYTE(v2) = *(_BYTE *)(v9 + 32) - v8;
  v1[9] = v7 - v5;
  v1[10] = v10 - v6;
  v1[11] = v3 - v4;
  v1[12] = v12 - v11;
  v1[13] = v2;
  return sub_102948();
}

