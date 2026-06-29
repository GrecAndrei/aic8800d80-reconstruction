// sub_1231E4 @ 0x1231e4, size 186 bytes
int  sub_1231E4(int a1, uint8_t *a2, int a3, int a4)
{
  int v5; // r1
  int v6; // r2
  uint8_t *v7; // r5
  int v8; // r2
  uint8_t *v9; // r6
  unsigned int v10; // r7
  int v11; // r1
  int v13; // r2
  uint8_t v14[5]; // [sp+7h] [bp-5h] BYREF

  v14[0] = 0;
  v7 = (uint8_t *)sub_12CB54(124, a4, a3, 2);
  if ( *a2 )
  {
    sub_12ECB0(dword_1232A0, v5, v6);
    **(uint8_t **)off_1232A4 = 0;
  }
  else
  {
    sub_12ECB0(dword_1232B0, v5, v6);
    **(uint8_t **)off_1232A4 = 3;
  }
  sub_115180(v14);
  v8 = v14[0];
  v7[1] = v14[0];
  if ( a2[1] )
  {
    v9 = off_1232A8;
    *((uint8_t *)off_1232A8 + 188) = (v8 & 0x20) != 0;
    v10 = ((v8 ^ 0x40u) >> 6) & 1;
  }
  else
  {
    v13 = (unsigned __int8)a2[2];
    v9 = off_1232A8;
    v10 = ((v13 ^ 0x40u) >> 6) & 1;
    *((uint8_t *)off_1232A8 + 188) = (v13 & 0x20) != 0;
  }
  if ( sub_1151D4() )
  {
    v9[188] = 0;
    v11 = 0;
  }
  else
  {
    v11 = (unsigned __int8)v9[188];
  }
  if ( *a2 )
  {
    if ( a2[3] )
      *((uint16_t *)v9 + 89) |= 0x4000u;
    sub_12ECB0(dword_1232AC, v11, v10);
    LOBYTE(v11) = v9[188];
  }
  *v7 = v11;
  sub_12CBB4(v7);
  return 0;
}

