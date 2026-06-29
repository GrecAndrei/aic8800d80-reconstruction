// sub_131278 @ 0x131278, size 162 bytes
unsigned __int8 * sub_131278(unsigned __int8 *a1, int a2, int a3, uint8_t *a4)
{
  unsigned __int8 *result; // r0
  unsigned __int8 v7; // r2
  unsigned int v8; // r1
  unsigned int v9; // r5
  uint64_t v10; // r2

  result = sub_12DF08(a1, a2);
  *a4 = 0;
  if ( result )
  {
    v7 = result[8];
    if ( *(uint8_t *)(a3 + 18) != (v7 & 0xF) )
    {
      *a4 = 1;
      *(uint8_t *)(a3 + 16) = v7;
      *(uint8_t *)(a3 + 18) = v7 & 0xF;
      v8 = *(uint32_t *)(result + 14);
      v9 = *(uint32_t *)(result + 10);
      HIDWORD(v10) = *(uint32_t *)(result + 22) & 0xF | (16 * (*(uint32_t *)(result + 22) >> 8));
      LODWORD(v10) = *(uint32_t *)(result + 18) & 0xF | (16 * (*(uint32_t *)(result + 18) >> 8));
      *(uint8_t *)(a3 + 17) = ((v8 & 0x10) != 0)
                          | (*(uint32_t *)(result + 18) >> 2) & 4
                          | (*(uint32_t *)(result + 22) >> 1) & 8
                          | (v9 >> 3) & 2;
      *(uint32_t *)a3 = v8 & 0xF | (16 * (v8 >> 8));
      *(uint32_t *)(a3 + 4) = v9 & 0xF | (16 * (v9 >> 8));
      *(QWORD *)(a3 + 8) = v10;
    }
    return (unsigned __int8 *)1;
  }
  else
  {
    *(uint32_t *)a3 = 2627;
    *(uint32_t *)(a3 + 4) = 2627;
    *(uint32_t *)(a3 + 8) = 2627;
    *(uint32_t *)(a3 + 12) = 2627;
  }
  return result;
}

