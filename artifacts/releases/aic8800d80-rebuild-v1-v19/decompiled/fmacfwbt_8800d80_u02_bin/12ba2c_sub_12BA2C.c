// sub_12BA2C @ 0x12ba2c, size 120 bytes
int sub_12BA2C()
{
  _DWORD *v0; // r1
  int v1; // r6
  int *v2; // r4
  _DWORD *v3; // r2
  _DWORD *v4; // r5
  _DWORD *v5; // r7
  int v6; // r3
  int result; // r0
  _DWORD *v8; // r4
  int v9; // r3
  int *v10; // r3
  int v11; // r3

  if ( **(__int16 **)off_12BAA4 < 0 && !(*(_DWORD *)off_12BAC0 << 28) )
    return sub_12F630(dword_12BACC, dword_12BAC8, 213, *(_DWORD *)off_12BAC0);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12BAA8 = 1;
  }
  v0 = off_12BAB0;
  v1 = *(_DWORD *)off_12BAB0;
  v2 = (int *)off_12BAB4;
  v3 = off_12BAB8;
  v4 = off_12BABC;
  v5 = off_12BAC0;
  v6 = *(_DWORD *)off_12BAAC + 25000;
  result = *(_DWORD *)off_12BAB0 + 1;
  *(_DWORD *)off_12BAB0 = result;
  *v2 = v6;
  v8 = off_12BAC4;
  *v3 = 128;
  v9 = v8[1] | 4;
  *v4 |= 0x80u;
  v8[1] = v9;
  *v5 = 0;
  if ( result )
  {
    v10 = (int *)off_12BAA8;
    *v0 = v1;
    v11 = *v10;
    if ( !v1 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}

