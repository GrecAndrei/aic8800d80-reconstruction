// sub_1289EC @ 0x1289ec, size 154 bytes
int  sub_1289EC(int a1, int a2, int a3)
{
  int v4; // r0
  int v5; // r1
  int v6; // r5
  uint8_t *v7; // r3
  int v8; // r2
  int v9; // r0
  int v11; // r1

  if ( (a2 & 0x800000) != 0 )
  {
    if ( a1 )
      *(uint8_t *)(a1 + 115) = 0;
    return 1;
  }
  else
  {
    v4 = (unsigned __int8)(*(uint8_t *)(a1 + 115) + 1);
    v5 = *(uint32_t *)off_128A88;
    *(uint8_t *)(a1 + 115) = v4;
    if ( *(unsigned __int8 *)(v5 + 1) == v4 )
    {
      v11 = dword_128A9C;
      *(uint8_t *)(a1 + 115) = 0;
      sub_12EB90(1024, v11);
      sub_121ED4(a1);
      return 1;
    }
    else
    {
      v6 = *(unsigned __int8 *)(a1 + 108);
      if ( *(uint8_t *)(a1 + 108) )
      {
        sub_118C84(*(unsigned __int8 *)(a1 + 116), a3, a1);
        return 0;
      }
      else
      {
        v7 = off_128A90;
        v8 = *((unsigned __int8 *)off_128A8C + 2);
        *((uint8_t *)off_128A90 + 28) = 1;
        if ( v8 )
          *(uint32_t *)off_128A94 &= ~0x80000000;
        if ( v7[8] )
          --v7[8];
        v9 = dword_128A98;
        v7[29] = 0;
        sub_124CF4(v9);
        *(uint32_t *)(a1 + 4) &= ~0x200u;
        return v6;
      }
    }
  }
}

