// sub_12EF48 @ 0x12ef48, size 118 bytes
// Doc: fmac_txq_alloc_init [tx]: allocate/init TX queue slot via 0x410 call
// fmac_txq_alloc_init [tx]: allocate/init TX queue slot via 0x410 call
int  sub_12EF48(int a1, int a2, __int16 a3, __int16 a4)
{
  int v5; // r0
  int v6; // r1
  uint32_t *v7; // r4
  int v8; // r0
  uint32_t *v10; // r2
  uint8_t *v11; // r0
  uint32_t *v12; // r3
  uint32_t *v13; // r3

  v5 = rf_bus_setup_n3a8(1040, a4, a3, 4u);
  v6 = *(unsigned __int16 *)(a2 + 4);
  v7 = (uint32_t *)v5;
  if ( *((uint8_t *)off_12EFC0 + 177) )
  {
    if ( (unsigned int)(v6 - 1) > 1 )
      goto LABEL_3;
    v10 = off_12EFCC;
    *(uint32_t *)off_12EFC8 |= 0x2000000u;
    v11 = off_12EFD0;
    v10[14] |= 0x10u;
    *v11 = 1;
  }
  if ( v6 == 1 )
  {
    v12 = off_12EFCC;
    *((uint32_t *)off_12EFCC + 18) = *(uint32_t *)a2;
    v12[75] = 64;
    goto LABEL_5;
  }
LABEL_3:
  if ( v6 == 2 )
  {
    v13 = off_12EFCC;
    *((uint32_t *)off_12EFCC + 19) = *(uint32_t *)a2;
    v13[75] = 128;
  }
LABEL_5:
  v8 = dword_12EFC4;
  *v7 = 0;
  sub_12ECB0(v8);
  sub_12CBB4((int)v7);
  return 0;
}

