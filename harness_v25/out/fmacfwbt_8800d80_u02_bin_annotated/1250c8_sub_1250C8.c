// fwstruct annotate: 1250c8_sub_1250C8.c
// sub_1250C8 @ 0x1250c8, size 186 bytes
int sub_1250C8()
{
  _DWORD *v0; // r7
  int *v1; // r6
  int *v2; // r8
  _DWORD *v3; // r5
  void *v4; // r9
  int result; // r0
  _DWORD *v6; // r4
  int v7; // r1
  int v8; // r3
  int v9; // r3
  int v10; // r2
  void (__fastcall *v11)(_DWORD); // r3
  int *v12; // r3
  int v13; // r3
  int *v14; // r3

  v0 = off_125184;
  v1 = (int *)off_125188;
  v2 = (int *)off_12519C;
  v3 = off_12518C;
  v4 = off_125184;
  while ( 1 )
  {
    sub_12D374(0x20000000);
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *v2 = 1;
    }
    result = *v1;
    v6 = (_DWORD *)*v0;
    v7 = *v1 + 1;
    *v1 = v7;
    if ( !v6 )
      break;
    v8 = v6[3];
    if ( v8 - v3[4] - 50 >= 0 )
    {
      v3[2] = 0x40000;
      v3[12] = v8;
      v3[2] = 4;
      if ( v8 - v3[4] >= 0 )
      {
        if ( !v7 )
          return result;
        v14 = (int *)off_12519C;
        *v1 = result;
        v13 = *v14;
        if ( result )
          return result;
        goto LABEL_17;
      }
    }
    sub_12D4F8(v4);
    if ( *v1 )
    {
      v9 = *v1 - 1;
      v10 = *v2;
      *v1 = v9;
      if ( !v9 )
      {
        if ( v10 )
          __enable_irq();
      }
    }
    v11 = (void (__fastcall *)(_DWORD))v6[1];
    if ( **(__int16 **)off_125190 >= 0 || v11 )
    {
      v11(v6[2]);
    }
    else
    {
      sub_12F694(dword_125198, dword_125194, 246);
      ((void (__fastcall *)(_DWORD))v6[1])(v6[2]);
    }
  }
  *((_DWORD *)off_12518C + 2) = 1024;
  if ( !v7 )
    return result;
  v12 = (int *)off_12519C;
  *v1 = result;
  v13 = *v12;
  if ( result )
    return result;
LABEL_17:
  if ( v13 )
    __enable_irq();
  return result;
}

