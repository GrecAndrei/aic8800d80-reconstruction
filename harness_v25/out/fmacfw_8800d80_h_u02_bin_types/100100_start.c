// start @ 0x100100, size 236 bytes
int  start(int a1, int a2, uint32_t *a3)
{
  int v4; // r5
  int v5; // r6
  int v6; // r7
  int v7; // r2
  int v8; // r3

  do
  {
    *(uint8_t *)(a1 + 30) = v4;
    *(uint8_t *)(a1 + 30) = v4;
    *(uint8_t *)(a1 + 30) = v4;
    *(uint8_t *)(a1 + 30) = v4;
    *(uint8_t *)(a1 + 30) = v4;
  }
  while ( VF );
  *a3 = a1;
  a3[1] = a3;
  a3[2] = v4;
  a3[3] = v5;
  a3[4] = v6;
  *a3 = a1;
  a3[1] = a3 + 5;
  if ( (unsigned __int16)*(uint32_t *)off_1001EC == 49729
    || (*((uint32_t *)off_1001F0 + 23) & 3) != 2
    || (v7 = *((uint32_t *)off_1001F4 + 92), v8 = *((uint32_t *)off_1001F4 + 93), v7 >= 0)
    || v8 >= 0 )
  {
    R0 = dword_1001F8;
    __asm { MSR.W           MSP, R0 }
    return off_1001FC();
  }
  else
  {
    R2 = v7 & 0xFFFFFFF;
    __asm { MSR.W           MSP, R2 }
    return ((int (*)(void))(v8 & 0xFFFFFFF))();
  }
}

