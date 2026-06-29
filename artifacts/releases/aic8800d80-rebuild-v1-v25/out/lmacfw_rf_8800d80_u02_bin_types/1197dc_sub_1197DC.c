// sub_1197DC @ 0x1197dc, size 186 bytes
int  sub_1197DC(int a1, uint8_t *a2, int a3, int a4)
{
  int v5; // r1
  uint8_t *v6; // r5
  char v7; // r2
  uint8_t *v8; // r6
  int v9; // r1
  uint8_t v11[5]; // [sp+7h] [bp-5h] BYREF

  v11[0] = 0;
  v6 = (uint8_t *)sub_11DDF0(124, a4, a3, 2);
  if ( *a2 )
  {
    sub_11F504(dword_119898, v5);
    **(uint8_t **)off_11989C = 0;
  }
  else
  {
    sub_11F504(dword_1198A8, v5);
    **(uint8_t **)off_11989C = 3;
  }
  sub_11416C(v11);
  v7 = v11[0];
  v6[1] = v11[0];
  v8 = off_1198A0;
  if ( a2[1] )
    *((uint8_t *)off_1198A0 + 188) = (v7 & 0x20) != 0;
  else
    *((uint8_t *)off_1198A0 + 188) = (a2[2] & 0x20) != 0;
  if ( sub_1141F8() )
  {
    v8[188] = 0;
    v9 = 0;
  }
  else
  {
    v9 = (unsigned __int8)v8[188];
  }
  if ( *a2 )
  {
    if ( a2[3] )
      *((uint16_t *)v8 + 89) |= 0x4000u;
    sub_11F504(dword_1198A4, v9);
    LOBYTE(v9) = v8[188];
  }
  *v6 = v9;
  sub_11DE50(v6);
  return 0;
}

