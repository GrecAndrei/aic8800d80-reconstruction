// sub_1402A0 @ 0x1402a0, size 284 bytes
// Doc: sub_12402A0 [bt]: Unidentified helper in BT firmware image
// sub_12402A0 [bt]: Unidentified helper in BT firmware image
int  sub_1402A0(int result)
{
  unsigned int v1; // r6
  int v2; // r4
  int v3; // r7
  int v4; // r5
  char v5; // r3
  char v6; // r3
  uint32_t *v7; // r8
  int v8; // r1
  __int16 v9; // r2
  bool v10; // nf
  unsigned int v11; // r6
  char v12; // r3
  char v13; // r3
  int v14; // r0
  char v15; // r3

  v1 = *(unsigned __int8 *)(result + 29);
  v2 = result;
  if ( v1 > 0x1F )
  {
    *(uint8_t *)(result + 54) = 0;
  }
  else
  {
    v3 = dword_1403C0;
    v4 = *(uint32_t *)(dword_1403C0 + 696 * v1 + 340);
    if ( **(__int16 **)off_1403BC < 0 && !v4 )
      sub_12F694(dword_1403CC, dword_1403C8, 2758);
    v5 = *(uint8_t *)(v4 + 166);
    if ( (*(uint32_t *)(v2 + 36) & 0x200000) != 0 && (*(uint8_t *)(v4 + 166) & 4) != 0 )
      v6 = v5 | 2;
    else
      v6 = v5 & 0xFD;
    v7 = off_1403D0;
    *(uint8_t *)(v4 + 166) = v6;
    if ( v7[4] - *(uint32_t *)v4 > (unsigned int)dword_1403C4 )
    {
      v14 = sub_13F66C(v4, 0);
      v15 = (*(uint8_t *)(v4 + 167) + 1) & 3;
      *(uint8_t *)(v4 + 167) = v15;
      *(uint8_t *)(v4 + 154) = 0;
      *(uint8_t *)(v4 + 168) = 0;
      *(uint32_t *)v4 = v7[4];
      *(uint8_t *)(v2 + 54) = 4 * v15;
      if ( v14 )
      {
        if ( !sub_13D518(v4) )
          *(uint32_t *)(v2 + 36) &= ~0x200000u;
        *(uint8_t *)(v3 + 696 * v1 + 350) |= 0x11u;
      }
    }
    else
    {
      *(uint8_t *)(v2 + 54) = *(uint8_t *)(v4 + 168) | (4 * *(uint8_t *)(v4 + 167));
    }
    result = sub_13ED0C(v4);
    if ( result )
    {
      v8 = *(uint32_t *)(v2 + 36);
      v9 = *(uint16_t *)(v2 + 30);
      *(uint8_t *)(v2 + 54) &= 0xFCu;
      v10 = (v8 & 0x200000) != 0;
      v11 = v3 + 696 * v1;
      v12 = *(uint8_t *)(v11 + 350);
      *(uint16_t *)(v2 + 30) = v9 | 0x2000;
      if ( (v8 & 0x200000) != 0 )
        v8 |= 0x280000u;
      v13 = v12 | 0x20;
      if ( v10 )
        *(uint32_t *)(v2 + 36) = v8;
      *(uint8_t *)(v11 + 350) = v13;
    }
  }
  return result;
}

