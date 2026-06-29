// sub_131890 @ 0x131890, size 138 bytes
int  sub_131890(int a1, uint8_t *a2, unsigned int a3, __int16 a4)
{
  uint32_t *v5; // r5
  int v6; // r7
  int v8; // r0
  int v9; // r0
  int v10; // r3
  uint8_t *v12; // r0
  int v13; // r3
  char v14; // r3
  unsigned int v15; // [sp+4h] [bp-8h]

  v5 = off_13191C;
  v6 = *((uint32_t *)off_13191C + 1);
  v8 = 1 << a2[1];
  if ( *a2 )
    v9 = v8 | v6;
  else
    v9 = v6 & ~v8;
  v10 = *((unsigned __int8 *)off_13191C + 375);
  *((uint32_t *)off_13191C + 1) = v9;
  if ( !v10 )
    goto LABEL_7;
  v15 = a3;
  if ( sub_12CD48(5u) == 1 )
    return 2;
  LOWORD(a3) = v15;
  if ( (uint8_t)v6 )
  {
    if ( *a2 )
    {
LABEL_7:
      sub_12C8D0(5146, a4, a3);
      return 0;
    }
  }
  else if ( !*a2 )
  {
    goto LABEL_7;
  }
  v12 = (uint8_t *)sub_12C7EC(49, 0, v15, 1u);
  v13 = v5[1];
  *((uint16_t *)v5 + 4) = a4;
  if ( v13 )
    v14 = 0;
  else
    v14 = *((uint8_t *)v5 + 376);
  *v12 = v14;
  sub_12C84C((int)v12);
  sub_12CBF4(v15, 1);
  return 0;
}

