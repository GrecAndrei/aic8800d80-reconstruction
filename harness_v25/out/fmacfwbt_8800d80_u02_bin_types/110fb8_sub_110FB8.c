// sub_110FB8 @ 0x110fb8, size 222 bytes
int  sub_110FB8(int a1)
{
  int *v2; // r5
  uint8_t *v3; // r3
  int v4; // r1
  uint32_t *v5; // r2
  int result; // r0
  uint32_t *v7; // r2
  uint32_t *v8; // r6
  int v9; // r1
  int v10; // r3
  uint8_t *v11; // r6
  uint8_t *v12; // r7
  int v13; // r3
  int v14; // r6

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_111098 = 1;
  }
  v2 = (int *)off_11109C;
  v3 = *(uint8_t **)off_1110A0;
  v4 = *(uint32_t *)off_11109C + 1;
  *(uint32_t *)off_11109C = v4;
  if ( *v3 == 1 )
  {
    v11 = off_1110BC;
    v12 = off_1110C0;
    if ( *(uint8_t *)off_1110BC )
    {
      v14 = *((unsigned __int8 *)off_1110C0 + 374);
      if ( v14 != 1 )
        goto LABEL_4;
      if ( sub_1251A0(dword_1110C4) )
        goto LABEL_18;
      if ( v12[369] )
        sub_10DB6C(v14);
      else
        sub_10DB58(v14);
    }
    else
    {
      if ( *((uint8_t *)off_1110C0 + 369) )
        sub_10DB6C(1);
      else
        sub_10DB58(1);
      v13 = (unsigned __int8)v12[374];
      *v11 = 1;
      if ( v13 != 1 )
        goto LABEL_18;
    }
    sub_124F60(dword_1110C4, *((uint32_t *)off_1110C8 + 4) + 10000);
LABEL_18:
    v4 = *v2;
  }
LABEL_4:
  v5 = off_1110A4;
  *(uint32_t *)off_1110A4 = 64;
  while ( (*v5 & 0x80) != 0 )
    ;
  if ( *(uint32_t *)off_1110A8 )
  {
    result = dword_1110AC;
    v7 = off_1110B0;
    *(uint32_t *)(*(uint32_t *)(dword_1110AC + 6164) + 4) = a1;
  }
  else
  {
    v7 = off_1110B0;
    *(uint32_t *)off_1110A8 = a1;
    result = dword_1110AC;
  }
  ++*v7;
  v8 = off_1110B8;
  *(uint8_t *)off_1110B4 |= 2u;
  *v8 = 64;
  *(uint32_t *)(result + 6164) = a1;
  if ( v4 )
  {
    v9 = v4 - 1;
    v10 = *(uint32_t *)off_111098;
    *v2 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}

