// fwstruct annotate: 12acf8_sub_12ACF8.c
// sub_12ACF8 @ 0x12acf8, size 156 bytes
int __fastcall sub_12ACF8(int result, int a2)
{
  int *v2; // r7
  _DWORD *v3; // r9
  int *v4; // r8
  int v5; // r10
  int v6; // r5
  int v8; // r6
  int v9; // r4
  int v10; // r1
  int v11; // r3
  int v12; // r2
  int v13; // r2
  int v14; // r3

  v2 = (int *)off_12AD98;
  v3 = off_12AD9C;
  v4 = (int *)off_12ADA0;
  v5 = dword_12AD94 + 140 * *(unsigned __int8 *)(result + 1225);
  v6 = 0;
  v8 = result;
  v9 = v5;
  v10 = 0;
  while ( 1 )
  {
    if ( !*(_BYTE *)(v9 + 32) && *(_BYTE *)(v9 + 16) )
    {
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v4 = 1;
      }
      result = *(_DWORD *)(v9 + 12) + a2;
      v11 = result - v3[4];
      v12 = *v2 + 1;
      *v2 = v12;
      if ( v11 - 62 >= 0 )
      {
        *(_DWORD *)(v8 + 88) = 0;
        result = sub_124F60(v9, result);
        v12 = *v2;
        v10 = 1;
        if ( !*v2 )
          goto LABEL_8;
      }
      else if ( !v12 )
      {
        goto LABEL_8;
      }
      v13 = v12 - 1;
      v14 = *v4;
      *v2 = v13;
      if ( !v13 && v14 )
        __enable_irq();
    }
LABEL_8:
    v9 += 48;
    if ( v6 )
      break;
    v6 = 1;
  }
  if ( v10 )
    return sub_1297BC(v5);
  return result;
}

