// sub_141B70 @ 0x141b70, size 256 bytes
int  sub_141B70(int a1, int a2, int a3, int a4, char a5)
{
  int v6; // r1
  int v10; // r3
  BOOL v11; // r0
  int result; // r0
  int v13; // r4
  char v14; // r3
  char v15; // r3
  uint16_t *v16; // r12
  __int16 v17; // r3
  int v18; // r2
  int v19; // r6
  __int16 v20; // r7
  __int16 v21; // r3
  __int16 v22; // r7

  v6 = *(uint32_t *)(a2 + 72);
  if ( v6 )
  {
    v10 = *(unsigned __int8 *)(v6 + 4);
    if ( **(__int16 **)off_141C70 >= 0 || v10 != 2 )
    {
      v11 = (v10 | *(unsigned __int8 *)(a2 + 1224)) != 0;
      goto LABEL_4;
    }
  }
  else if ( **(__int16 **)off_141C70 >= 0 )
  {
    goto LABEL_16;
  }
  sub_12F46C(dword_141C78, dword_141C74, 520);
LABEL_16:
  v11 = 1;
LABEL_4:
  result = sub_118C44(v11, 512);
  *(uint32_t *)a1 = result;
  if ( result )
  {
    v13 = *(uint32_t *)(result + 72);
    v14 = *(uint8_t *)(a2 + 107);
    *(uint8_t *)(result + 28) = v14;
    if ( a3 )
      v15 = *(uint8_t *)(a3 + 35);
    else
      v15 = v14 + 32;
    v16 = off_141C7C;
    *(uint8_t *)(*(uint32_t *)a1 + 29) = v15;
    *(uint8_t *)(*(uint32_t *)a1 + 51) = 0;
    *(uint8_t *)(*(uint32_t *)a1 + 53) = 0;
    v17 = v16[254];
    v18 = a3 + 38;
    v19 = *(uint32_t *)(a3 + 38);
    *(uint8_t *)(v13 + 109) = 0;
    v20 = *(uint16_t *)(v18 + 4);
    LOWORD(v18) = *(uint16_t *)(a2 + 104);
    *(uint8_t *)(v13 + 110) = 0;
    *(uint8_t *)(v13 + 111) = 0;
    v21 = v17 + 1;
    *(uint32_t *)(v13 + 118) = *(uint32_t *)(a2 + 100);
    *(uint16_t *)(v13 + 116) = v20;
    result = *(uint32_t *)(a2 + 100);
    v22 = *(uint16_t *)(a2 + 104);
    *(uint32_t *)(v13 + 112) = v19;
    *(uint16_t *)(v13 + 122) = v18;
    *(uint32_t *)(v13 + 124) = result;
    *(uint16_t *)(v13 + 128) = v22;
    *(uint8_t *)(v13 + 108) = -48;
    if ( a4 == 6 )
      result = 27;
    v16[254] = v21;
    if ( a4 != 6 )
      result = 26;
    *(uint16_t *)(v13 + 130) = 16 * v21;
    *(uint8_t *)(v13 + 133) = a4;
    *(uint8_t *)(v13 + 132) = 22;
    if ( a4 == 6 )
      *(uint8_t *)(v13 + 136) = a5;
  }
  return result;
}

