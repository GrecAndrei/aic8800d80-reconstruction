// sub_12343C @ 0x12343c, size 80 bytes
int __fastcall sub_12343C(int a1, unsigned __int8 *a2)
{
  _BYTE *v3; // r0
  _BYTE *v4; // r4
  unsigned int v5; // r0

  v3 = (_BYTE *)sub_12C7EC(84, 13, 0, 1);
  *v3 = 1;
  v4 = v3;
  v5 = *a2;
  if ( v5 > 4 || !*(_BYTE *)(dword_12348C + 1320 * v5 + 1224) )
    goto LABEL_5;
  *v4 = 0;
  if ( a2[1] )
  {
    sub_12A3E8();
LABEL_5:
    sub_12C84C(v4);
    return 0;
  }
  sub_12A424();
  sub_12C84C(v4);
  return 0;
}

