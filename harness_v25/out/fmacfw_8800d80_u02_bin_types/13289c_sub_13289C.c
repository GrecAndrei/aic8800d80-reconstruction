// sub_13289C @ 0x13289c, size 92 bytes
// Doc: sub_123289C [mac]: FMAC helper: check channel/band state and dispatch
// sub_123289C [mac]: FMAC helper: check channel/band state and dispatch
int  sub_13289C(int a1)
{
  int v2; // r0
  int v3; // r3
  int v4; // r4
  int v5; // r0
  char v6; // r2
  int v7; // t1
  int v8; // r0
  int result; // r0

  v2 = *(unsigned __int8 *)(a1 + 192);
  if ( **(__int16 **)off_1328F8 >= 0 )
  {
LABEL_2:
    if ( !v2 )
      goto LABEL_7;
    goto LABEL_3;
  }
  if ( !v2 )
  {
    sub_12F46C(dword_1328FC, dword_132900, 707);
    v2 = *(unsigned __int8 *)(a1 + 192);
    goto LABEL_2;
  }
LABEL_3:
  v3 = a1 + 192;
  v4 = a1 + 192 + v2;
  v5 = 0;
  do
  {
    v7 = *(unsigned __int8 *)++v3;
    v6 = v7;
    if ( (int)(v7 & 0xFFFFFF7F) > v5 )
      v5 = v6 & 0x7F;
  }
  while ( v3 != v4 );
LABEL_7:
  sub_1326F4();
  result = sub_13F3B8(a1, v8);
  *(uint8_t *)(a1 + 350) = 0;
  return result;
}

