// sub_132AB8 @ 0x132ab8, size 92 bytes
int __fastcall sub_132AB8(int a1)
{
  int v2; // r0
  int v3; // r3
  int v4; // r4
  char v5; // r2
  int v6; // t1
  int v7; // r0
  int result; // r0

  v2 = *(unsigned __int8 *)(a1 + 192);
  if ( **(__int16 **)off_132B14 >= 0 )
  {
LABEL_2:
    if ( !v2 )
      goto LABEL_7;
    goto LABEL_3;
  }
  if ( !v2 )
  {
    sub_12F694(dword_132B18, dword_132B1C, 707);
    v2 = *(unsigned __int8 *)(a1 + 192);
    goto LABEL_2;
  }
LABEL_3:
  v3 = a1 + 192;
  v4 = a1 + 192 + v2;
  v2 = 0;
  do
  {
    v6 = *(unsigned __int8 *)++v3;
    v5 = v6;
    if ( (int)(v6 & 0xFFFFFF7F) > v2 )
      v2 = v5 & 0x7F;
  }
  while ( v3 != v4 );
LABEL_7:
  v7 = sub_132910(v2);
  result = sub_13F454(a1, v7);
  *(_BYTE *)(a1 + 350) = 0;
  return result;
}

