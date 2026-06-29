// sub_122D9C @ 0x122d9c, size 76 bytes
int  sub_122D9C(int a1, int *a2, int a3, uint32_t *a4)
{
  int v4; // r4
  uint32_t *v6; // r1
  char *v7; // r7
  int v8; // r6
  int v9; // r4
  int v10; // r12
  int v11; // r5
  int v12; // r6

  v4 = *(unsigned __int8 *)a2;
  v6 = a4;
  if ( v4 )
  {
    v7 = (char *)off_122DEC;
    if ( (*((uint8_t *)off_122DE8 + 1) & 1) == 0
      || (a4 = (uint32_t *)(*((uint32_t *)off_122DEC + 98) << 31), (*((uint32_t *)off_122DEC + 98) & 1) != 0) )
    {
      a4 = off_122DF0;
      v8 = *a2;
      v9 = a2[2];
      v10 = a2[3];
      *((uint32_t *)off_122DF0 + 1) = a2[1];
      *(uint32_t *)(v7 + 266) = v8;
      v11 = a2[5];
      v12 = a2[4];
      a4[2] = v9;
      a4[6] = a2[6];
      a4[3] = v10;
      a4[4] = v12;
      a4[5] = v11;
    }
  }
  message_dispatch_n84(122, v6, a3, a4);
  return 0;
}

