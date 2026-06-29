// fwstruct annotate: 118e38_sub_118E38.c
// sub_118E38 @ 0x118e38, size 102 bytes
// Doc: sub_1218E38 [util]: Initialize firmware subsystem state with constants
// sub_1218E38 [util]: Initialize firmware subsystem state with constants
int __fastcall sub_118E38(int a1, int a2)
{
  __int16 **v2; // r5
  int v3; // r7
  int v4; // r6
  int v6; // r0
  int v7; // r1
  int v8; // r3
  int v9; // r2
  int v10; // r0

  v2 = (__int16 **)off_118EA0;
  v3 = dword_118EA4;
  v4 = dword_118EA8;
LABEL_2:
  v6 = sub_12D4F8(a2);
  v7 = 2080374784;
  v8 = v6;
  if ( v6 )
  {
    while ( 1 )
    {
      v9 = *(_DWORD *)(v8 + 76);
      if ( *(_DWORD *)(v8 + 68) )
        goto LABEL_4;
      if ( *(int *)(v9 + 4) >= 0 )
        break;
LABEL_5:
      if ( !*(_WORD *)(v8 + 4) )
      {
        sub_119120(v8);
        goto LABEL_2;
      }
      if ( **v2 >= 0 )
        goto LABEL_2;
      sub_12F694(v4, v3, 1147);
      v10 = sub_12D4F8(a2);
      v7 = 2080374784;
      v8 = v10;
      if ( !v10 )
        return rx_buf_init_n168();
    }
    v7 = 0x40000000;
LABEL_4:
    *(_DWORD *)(v9 + 4) = v7;
    goto LABEL_5;
  }
  return rx_buf_init_n168();
}

