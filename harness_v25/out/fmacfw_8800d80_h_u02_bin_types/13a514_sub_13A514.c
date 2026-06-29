// sub_13A514 @ 0x13a514, size 168 bytes
int  sub_13A514(int a1)
{
  __int16 v1; // r2
  int result; // r0
  int v4; // r1
  int v5; // r5
  int v6; // r3
  char v7; // r5
  __int16 v8; // r7
  int v9; // r1
  unsigned int v10; // r3
  char v11; // r5
  char v12; // r1
  int v13; // [sp+4h] [bp-8h] BYREF

  v1 = *(uint16_t *)(a1 + 30);
  result = *(unsigned __int8 *)(a1 + 29);
  v4 = *(unsigned __int8 *)(a1 + 28);
  *(uint32_t *)(a1 + 36) = 0;
  *(uint32_t *)(a1 + 40) = 0;
  if ( (v1 & 1) == 0 )
  {
    v5 = *(unsigned __int8 *)(a1 + 27);
    if ( v5 == 255 )
    {
      v7 = 24;
    }
    else
    {
      v6 = dword_13A5BC + 2 * (v5 + 348 * result + 156);
      v7 = 26;
      v8 = *(uint16_t *)(v6 + 4);
      *(uint16_t *)(v6 + 4) = (v8 + 1) & 0xFFF;
      *(uint16_t *)(a1 + 32) = v8;
    }
    v9 = dword_13A5C0 + 1320 * v4;
    if ( (v1 & 0x100) != 0 )
      v7 += 6;
    if ( !*(uint8_t *)(v9 + 106) && (*(uint32_t *)(dword_13A5BC + 696 * result + 4) & 0x20) != 0 )
      v7 += 4;
    *(uint8_t *)(a1 + 50) = v7;
    result = sub_13A3E8(a1, &v13);
    v10 = *(unsigned __int16 *)(a1 + 24);
    *(uint16_t *)(a1 + 48) = *(uint16_t *)(a1 + 4);
    v11 = v7 + result;
    *(uint8_t *)(a1 + 53) = v13;
    if ( (unsigned __int16)__rev16(v10) <= 0x600u )
    {
      v12 = 0;
    }
    else
    {
      v11 += 8;
      v12 = 8;
    }
    *(uint8_t *)(a1 + 51) = v11;
    *(uint8_t *)(a1 + 66) = v11;
    *(uint8_t *)(a1 + 52) = v12;
  }
  return result;
}

