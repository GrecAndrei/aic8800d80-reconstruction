// fwstruct annotate: 13bae8_sub_13BAE8.c
// sub_13BAE8 @ 0x13bae8, size 168 bytes
_DWORD *__fastcall sub_13BAE8(unsigned int a1)
{
  int v1; // r5
  int v3; // r1
  unsigned __int8 *v4; // r3
  int v5; // r2
  int v6; // r0
  int v7; // r3
  _DWORD *v8; // r1
  _DWORD *v10; // [sp+4h] [bp-8h]

  v1 = (a1 << 8) | 8;
  sub_12C5FC(0x2000, v1);
  sub_12C5FC(8194, v1);
  v3 = dword_13BB90;
  v4 = (unsigned __int8 *)(dword_13BB90 + 32 * a1);
  v5 = v4[17];
  v6 = v4[16];
  v7 = v4[22];
  if ( v5 )
  {
    if ( v5 == 1 )
      *(_BYTE *)(696 * v6 + 12 * v7 + dword_13BB94 + 453) = 33;
    v8 = (_DWORD *)(v3 + 32 * a1);
    v10 = v8;
    if ( a1 <= 0xF )
      goto LABEL_5;
LABEL_7:
    sub_12D1A8(dword_13BBA0, v8);
    sub_12D108(dword_13BBA4, v10);
    return sub_12CBF4(v1, 0);
  }
  v8 = (_DWORD *)(dword_13BB90 + 32 * a1);
  *(_BYTE *)(696 * v6 + 12 * v7 + dword_13BB94 + 452) = 33;
  v10 = v8;
  if ( a1 > 0xF )
    goto LABEL_7;
LABEL_5:
  sub_12D1A8(dword_13BB98, v8);
  sub_12D108(dword_13BB9C, v10);
  return sub_12CBF4(v1, 0);
}

