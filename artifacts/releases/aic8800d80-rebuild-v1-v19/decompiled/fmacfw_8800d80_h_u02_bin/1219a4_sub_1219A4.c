// sub_1219A4 @ 0x1219a4, size 230 bytes
int sub_1219A4()
{
  int *v0; // r8
  int *v1; // r4
  _DWORD *v2; // r5
  int v3; // r3
  int v4; // r7
  int v5; // r9
  _DWORD *v6; // r0
  _DWORD *v7; // r1
  int v8; // r4
  int v9; // r3
  int result; // r0
  int v11; // r3
  int v12; // r3
  int v13; // r2

  if ( **(__int16 **)off_121A8C < 0 && sub_12CD48(0) == 4 )
    sub_12F32C(dword_121AC0, dword_121ABC, 1799);
  sub_12EB90(4, dword_121A90);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_121A94 = 1;
  }
  v0 = (int *)off_121AC4;
  v1 = (int *)off_121A98;
  v2 = off_121A9C;
  ++*(_DWORD *)off_121AC4;
  v3 = *v1;
  *v1 = 0;
  v4 = v2[4];
  v5 = v3 & 0xF;
  while ( *v1 << 28 )
  {
    sub_1178B4();
    if ( (unsigned int)(v2[4] - v4) > 0x7530 )
      sub_12EB90(4, dword_121AB8);
  }
  v6 = off_121AA4;
  v7 = off_121AA8;
  v8 = *(_DWORD *)off_121AA4;
  *((_DWORD *)off_121AA0 + 1) &= ~4u;
  if ( v5 && (*v7 & v8 & 4) == 0 )
  {
    while ( (*v7 & *v6 & 4) == 0 )
      ;
  }
  v9 = *((unsigned __int8 *)off_121AAC + 90);
  *(_DWORD *)off_121AB0 = 4;
  if ( v9 )
    sub_1178E4();
  result = sub_12CBF4(0);
  v11 = *v0;
  *((_WORD *)off_121AB4 + 9) = 0;
  if ( v11 )
  {
    v12 = v11 - 1;
    v13 = *(_DWORD *)off_121A94;
    *v0 = v12;
    if ( !v12 )
    {
      if ( v13 )
        __enable_irq();
    }
  }
  return result;
}

