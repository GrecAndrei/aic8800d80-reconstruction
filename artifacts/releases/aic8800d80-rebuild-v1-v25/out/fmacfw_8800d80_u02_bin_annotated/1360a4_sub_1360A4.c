// fwstruct annotate: 1360a4_sub_1360A4.c
// sub_1360A4 @ 0x1360a4, size 148 bytes
int __fastcall sub_1360A4(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  __int16 v6; // r2
  int v7; // r0
  int value; // r0
  _DWORD *v10; // r1
  _DWORD *v11; // r4
  int v12; // r6
  int v13; // r0
  unsigned int v14; // r3
  int *v15; // r3
  int v16; // r3

  msg_parse(dword_13613C, dword_136138);
  v6 = a3;
  v7 = dword_136140 + 1320 * *a2;
  if ( *(_BYTE *)(v7 + 106) == 2 && !*(_BYTE *)(v7 + 108) )
  {
    value = msg_get_value(7u);
    v6 = a3;
    if ( !value )
    {
      sub_1285BC(*a2);
      *(_BYTE *)off_136144 = 0;
      v6 = a3;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(_DWORD *)off_136148 = 1;
      }
      v10 = off_13614C;
      v11 = off_136150;
      v12 = *(_DWORD *)off_13614C;
      v13 = *(_DWORD *)off_13614C + 1;
      v14 = *((_DWORD *)off_136150 + 1) & 0xFFFFFFEF;
      *(_DWORD *)off_13614C = v13;
      v11[1] = v14;
      if ( v13 )
      {
        v15 = (int *)off_136148;
        *v10 = v12;
        v16 = *v15;
        if ( !v12 )
        {
          if ( v16 )
            __enable_irq();
        }
      }
    }
  }
  sub_12CA10(7175, a4, v6);
  return 0;
}

