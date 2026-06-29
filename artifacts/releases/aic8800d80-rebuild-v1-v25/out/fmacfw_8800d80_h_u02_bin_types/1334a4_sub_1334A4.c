// sub_1334A4 @ 0x1334a4, size 74 bytes
uint32_t * sub_1334A4(int a1, uint32_t *a2, int a3, unsigned __int16 *a4, unsigned __int8 a5)
{
  int v5; // r7
  int v6; // r5
  int v7; // r6
  int v8; // r2
  int v9; // r6
  int v10; // r4
  uint32_t *v11; // r0
  int *v12; // r1
  uint32_t *v13; // r0
  int *v14; // r1
  uint32_t *v15; // r0
  int *v16; // r1

  v5 = *a4;
  v6 = *(uint32_t *)(a4 + 1);
  v7 = *(unsigned __int16 *)(a3 + 4);
  v8 = *(uint32_t *)a3;
  *(uint32_t *)a1 = *a2;
  *(uint32_t *)(a1 + 4) = a2[1];
  *(uint32_t *)(a1 + 8) = 0;
  *(uint8_t *)(a1 + 12) = 0;
  v9 = v7 | (v5 << 16);
  if ( a5 == 255 )
    v10 = 0;
  else
    v10 = a5 & 7;
  v11 = sub_133470((uint32_t *)a1, (int *)(a1 + 4), v8);
  v13 = sub_133470(v11, v12, v9);
  v15 = sub_133470(v13, v14, v6);
  return sub_133470(v15, v16, v10);
}

