// sub_1103F4 @ 0x1103f4, size 260 bytes
int  sub_1103F4(int result)
{
  uint32_t *v1; // r4
  unsigned int v2; // r3
  int *v3; // r6
  int **v4; // r9
  uint32_t *v5; // r8
  int v6; // r5
  int *v7; // r7
  int v8; // r10
  int *v9; // r0
  int *v10; // r11
  int v11; // r1
  int v12; // r2
  __int16 v13; // r3
  int v14; // r1
  int v15; // r2
  int v16; // r3

  v1 = off_1104F8;
  v2 = *(unsigned __int16 *)(result + 28);
  v3 = (int *)off_1104FC;
  v4 = (int **)off_110524;
  v5 = off_110528;
  v6 = result;
LABEL_2:
  v7 = (int *)off_110500;
  while ( v2 <= 1 )
  {
    v8 = sub_1102D0();
    if ( !v8 )
    {
      result = sub_10DA6C(dword_11051C, *(uint32_t *)off_110518);
      if ( *(unsigned __int16 *)(v6 + 28) > 1u )
        return result;
      return sub_11E5E0(256);
    }
    v9 = (int *)sub_1101AC();
    v10 = v9;
    if ( !v9 )
    {
      sub_10DA6C(dword_110520);
      result = sub_110320();
      if ( *(unsigned __int16 *)(v6 + 28) > 1u )
        return result;
      return sub_11E5E0(256);
    }
    *v9 = v8;
    v9[1] = 0;
    v9[2] = 0;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_110504 = 1;
    }
    v11 = *v7 + 1;
    *v7 = v11;
    *v1 = 1024;
    while ( (*v1 & 0x800) != 0 )
      ;
    if ( (unsigned __int8)*v3 )
    {
      v16 = *(uint32_t *)(v6 + 20);
      if ( v16 )
      {
        *(uint32_t *)(v16 + 4) = v9;
      }
      else
      {
        sub_10DA6C(dword_110514);
        v11 = *v7;
      }
    }
    else
    {
      if ( **(__int16 **)off_110508 < 0 && *v4 )
      {
        sub_1219C4(dword_110510, dword_11050C, 261);
        v11 = *v7;
      }
      *v4 = v10;
    }
    v12 = *v3;
    v13 = *(uint16_t *)(v6 + 28);
    *(uint32_t *)(v6 + 20) = v10;
    v2 = (unsigned __int16)(v13 + 1);
    result = 1024;
    *(uint16_t *)(v6 + 28) = v2;
    *v3 = (unsigned __int8)(v12 + 1);
    *v5 = 1024;
    if ( v11 )
    {
      v14 = v11 - 1;
      v15 = *(uint32_t *)off_110504;
      *v7 = v14;
      if ( !v14 )
      {
        if ( v15 )
        {
          __enable_irq();
          v2 = *(unsigned __int16 *)(v6 + 28);
        }
      }
      goto LABEL_2;
    }
  }
  return result;
}

