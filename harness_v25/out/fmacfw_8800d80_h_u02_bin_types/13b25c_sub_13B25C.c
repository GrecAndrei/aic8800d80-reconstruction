// sub_13B25C @ 0x13b25c, size 414 bytes
int  sub_13B25C(int a1, char *a2, unsigned int a3)
{
  char *v6; // r8
  char v7; // r10
  char v8; // r5
  unsigned __int8 v9; // r6
  uint8_t *v10; // r0
  unsigned __int16 v11; // r3
  char *v12; // r5
  int v13; // r0
  int v14; // r2
  uint32_t *v15; // r6

  if ( sub_12CD48(a3) == 3 )
  {
    v6 = (char *)off_13B400 + 32 * (a3 >> 8);
    if ( v6[17] )
    {
      if ( v6[17] == 1 )
      {
        if ( a2[2] )
        {
          sub_13B8E4(a3 >> 8);
          sub_12D108(dword_13B41C, v6);
          sub_12CBF4(a3, 0);
        }
        else
        {
          v7 = v6[20];
          sub_13C26C((char *)off_13B400 + 32 * (a3 >> 8));
          *((uint32_t *)v6 + 2) = *((uint32_t *)off_13B404 + 4);
          v8 = *a2;
          v9 = a2[1];
          v10 = (uint8_t *)sub_12C7EC(5131, 13, 5, 3u);
          v10[2] = v7 - 4;
          *v10 = v8;
          v10[1] = v9;
          sub_12C84C((int)v10);
          sub_13B8CC(a3 >> 8);
          sub_12CBF4(a3, 1);
        }
      }
      else if ( **(__int16 **)off_13B3FC < 0 )
      {
        sub_12F35C(dword_13B40C, dword_13B408, 218);
      }
    }
    else
    {
      v11 = *((unsigned __int8 *)off_13B410 + 371);
      if ( *((uint8_t *)off_13B410 + 371) )
        v11 = *(unsigned __int8 *)(dword_13B418
                                 + 1320
                                 * *(unsigned __int8 *)(dword_13B414 + 696 * *((unsigned __int8 *)off_13B400 + 16) + 34)
                                 + 106) == 0;
      v12 = (char *)off_13B400 + 32 * (a3 >> 8);
      if ( a2[2] )
      {
        sub_13B558(
          (unsigned __int8)v12[16],
          v12,
          1,
          (unsigned __int8)v12[23],
          v11
        | (unsigned __int16)((4 * (unsigned __int8)v12[22])
                           | (2 * (unsigned __int8)v12[18])
                           | (*((uint16_t *)v12 + 10) << 6)),
          37,
          0);
        sub_12D108(dword_13B420, v12);
        sub_12CBF4(a3, 0);
      }
      else
      {
        sub_13B558(
          (unsigned __int8)v12[16],
          v12,
          1,
          (unsigned __int8)v12[23],
          v11
        | (unsigned __int16)((4 * (unsigned __int8)v12[22])
                           | (2 * (unsigned __int8)v12[18])
                           | (*((uint16_t *)v12 + 10) << 6)),
          (unsigned __int8)a2[2],
          (unsigned __int8)a2[2]);
        v13 = (unsigned __int8)*a2;
        v14 = (unsigned __int8)a2[1];
        v15 = off_13B404;
        *(uint8_t *)(696 * v13 + 12 * v14 + dword_13B414 + 452) = BYTE1(a3);
        *((uint32_t *)v12 + 2) = v15[4];
        sub_13B8CC(a3 >> 8);
        sub_12CBF4(a3, 1);
      }
    }
    return 0;
  }
  if ( **(__int16 **)off_13B3FC >= 0 )
    return 0;
  sub_12F35C(dword_13B40C, dword_13B408, 109);
  return 0;
}

