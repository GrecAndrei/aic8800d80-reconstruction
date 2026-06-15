// sub_117CB4 @ 0x117cb4, size 160 bytes
// Doc: sub_1217CB4 [util]: Index/compute entry into table via stride*8 multiply
// sub_1217CB4 [util]: Index/compute entry into table via stride*8 multiply
int __fastcall sub_117CB4(int a1)
{
  int v1; // r6
  int v3; // r5
  int v4; // r5
  _DWORD *v5; // r2
  int v6; // r3
  int v7; // r1
  int v8; // r0
  int v9; // r7
  int *v11; // r0
  int v12; // r2
  int *v13; // r3

  v1 = dword_117D54;
  v3 = 19 * a1;
  sub_11F74C(256, dword_117D5C, dword_117D58, a1);
  v4 = v1 + 8 * v3;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_117D60 = 1;
  }
  v5 = off_117D64;
  v6 = v1 + 152 * a1;
  v7 = *(_DWORD *)off_117D64;
  v8 = *(_DWORD *)(v6 + 44);
  v9 = *(_DWORD *)off_117D64 + 1;
  *(_DWORD *)off_117D64 = v9;
  *(_BYTE *)(v6 + 35) = 0;
  if ( v8 )
  {
    *(_BYTE *)(v8 + 35) = 0;
    if ( !v9 )
    {
LABEL_5:
      sub_117AC8(v8);
      list_push_tail(dword_117D68);
      goto LABEL_6;
    }
    v11 = (int *)off_117D60;
    *v5 = v7;
    v12 = *v11;
    if ( v7 )
    {
      v8 = *(_DWORD *)(v6 + 44);
      goto LABEL_5;
    }
  }
  else
  {
    if ( !v9 )
      goto LABEL_6;
    v13 = (int *)off_117D60;
    *v5 = v7;
    v12 = *v13;
    if ( v7 )
      goto LABEL_6;
  }
  if ( v12 )
    __enable_irq();
  v8 = *(_DWORD *)(v1 + 152 * a1 + 44);
  if ( v8 )
    goto LABEL_5;
LABEL_6:
  sub_117AC8(v4);
  return list_push_tail(dword_117D68);
}

