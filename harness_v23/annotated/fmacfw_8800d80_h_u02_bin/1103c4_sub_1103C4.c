// v23 annotated: sub_1103C4 @ 0x1103c4
// Original: 1103c4_sub_1103C4.c
// Primary struct: <unclustered>
//
// sub_1103C4 @ 0x1103c4, size 258 bytes
int __fastcall sub_1103C4(int result)
{
  _DWORD *v1; // r4
  unsigned int v2; // r3
  int *v3; // r6
  int **v4; // r9
  _DWORD *v5; // r8
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

  v1 = off_1104C8;
  v2 = *(unsigned __int16 *)(result + 28);
  v3 = (int *)off_1104CC;
  v4 = (int **)off_1104F4;
  v5 = off_1104F8;
  v6 = result;
LABEL_2:
  v7 = (int *)off_1104D0;
  while ( v2 <= 1 )
  {
    v8 = sub_1102A0();
    if ( !v8 )
    {
      result = sub_10DAE4(dword_1104EC, *(_DWORD *)off_1104E8);
      if ( *(unsigned __int16 *)(v6 + 28) > 1u )
        return result;
      return sub_12CFC4(32);
    }
    v9 = (int *)sub_11017C();
    v10 = v9;
    if ( !v9 )
    {
      sub_10DAE4(dword_1104F0);
      result = sub_1102F0();
      if ( *(unsigned __int16 *)(v6 + 28) > 1u )
        return result;
      return sub_12CFC4(32);
    }
    *v9 = v8;
    v9[1] = 0;
    v9[2] = 0;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_1104D4 = 1;
    }
    v11 = *v7 + 1;
    *v7 = v11;
    *v1 = 1024;
    while ( (*v1 & 0x800) != 0 )
      ;
    if ( (unsigned __int8)*v3 )
    {
      v16 = *(_DWORD *)(v6 + 20);
      if ( v16 )
      {
        *(_DWORD *)(v16 + 4) = v9;
      }
      else
      {
        sub_10DAE4(dword_1104E4);
        v11 = *v7;
      }
    }
    else
    {
      if ( **(__int16 **)off_1104D8 < 0 && *v4 )
      {
        sub_12F32C(dword_1104E0, dword_1104DC, 261);
        v11 = *v7;
      }
      *v4 = v10;
    }
    v12 = *v3;
    v13 = *(_WORD *)(v6 + 28);
    *(_DWORD *)(v6 + 20) = v10;
    v2 = (unsigned __int16)(v13 + 1);
    result = 1024;
    *(_WORD *)(v6 + 28) = v2;
    *v3 = (unsigned __int8)(v12 + 1);
    *v5 = 1024;
    if ( v11 )
    {
      v14 = v11 - 1;
      v15 = *(_DWORD *)off_1104D4;
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

