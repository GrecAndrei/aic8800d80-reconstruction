// sub_122B68 @ 0x122b68, size 76 bytes
int  sub_122B68(int a1, int *a2, int a3, int a4)
{
  char *v7; // r7
  uint32_t *v8; // r3
  int v9; // r6
  int v10; // r4
  int v11; // r12
  int v12; // r5
  int v13; // r6

  if ( *(uint8_t *)a2 )
  {
    v7 = (char *)off_122BB8;
    if ( (*((uint8_t *)off_122BB4 + 1) & 1) == 0 || (*((uint32_t *)off_122BB8 + 98) & 1) != 0 )
    {
      v8 = off_122BBC;
      v9 = *a2;
      v10 = a2[2];
      v11 = a2[3];
      *((uint32_t *)off_122BBC + 1) = a2[1];
      *(uint32_t *)(v7 + 266) = v9;
      v12 = a2[5];
      v13 = a2[4];
      v8[2] = v10;
      v8[6] = a2[6];
      v8[3] = v11;
      v8[4] = v13;
      v8[5] = v12;
    }
  }
  sub_12CA10(122, a4, a3);
  return 0;
}

