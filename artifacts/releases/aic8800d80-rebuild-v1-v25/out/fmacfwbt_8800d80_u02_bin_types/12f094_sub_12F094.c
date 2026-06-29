// sub_12F094 @ 0x12f094, size 178 bytes
int  sub_12F094(int a1, int *a2, __int16 a3, __int16 a4)
{
  QWORD *v5; // r0
  int v6; // r5
  uint32_t *v7; // r0
  uint64_t v8; // r2
  int v9; // r0

  v5 = (QWORD *)rf_bus_setup_n3a8(1042, a4, a3, 8u);
  v6 = (int)v5;
  if ( (unsigned int)**(unsigned __int8 **)off_12F148 - 1 <= 1 )
  {
    LODWORD(v8) = *a2;
    if ( *a2 == dword_12F150 || (uint32_t)v8 == dword_12F150 - 36184 )
    {
      *(uint32_t *)v8 ^= (a2[2] ^ *(uint32_t *)v8) & a2[1];
      HIDWORD(v8) = a2[2];
      LODWORD(v8) = *a2;
      v9 = HIDWORD(v8);
      *(QWORD *)v6 = v8;
    }
    else
    {
      HIDWORD(v8) = a2[2];
      *v5 = v8;
      v9 = HIDWORD(v8);
    }
  }
  else
  {
    v7 = (uint32_t *)*a2;
    if ( (((unsigned int)*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      rf_reg_write_guard((int)v7, a2[2], a2[1], 1);
      v9 = sub_10EBDC(*a2, 1);
      LODWORD(v8) = *a2;
    }
    else
    {
      *v7 ^= (a2[2] ^ *v7) & a2[1];
      LODWORD(v8) = *a2;
      v9 = *(uint32_t *)*a2;
    }
    *(uint32_t *)(v6 + 4) = v9;
    HIDWORD(v8) = a2[2];
    *(uint32_t *)v6 = v8;
  }
  sub_12ECB0(dword_12F14C, a2[1], HIDWORD(v8), HIDWORD(v8), (uint32_t)v8, v9, v9);
  sub_12CBB4(v6);
  return 0;
}

