// v23 annotated: sub_13C0A4 @ 0x13c0a4
// Original: 13c0a4_sub_13C0A4.c
// Primary struct: <unclustered>
//
// sub_13C0A4 @ 0x13c0a4, size 108 bytes
// Doc: sub_123C0A4 [util]: Boundary check: compare value against 0xff sentinel
// sub_123C0A4 [util]: Boundary check: compare value against 0xff sentinel
int __fastcall sub_13C0A4(int a1, int a2)
{
  int v3; // r7
  int v5; // r4

  if ( a2 == 255 )
    return 2;
  v3 = dword_13C110;
  v5 = *(unsigned __int8 *)(696 * (unsigned __int8)a1 + 12 * (unsigned __int8)a2 + dword_13C110 + 453);
  return v5 == 33
      || msg_get_value((v5 << 8) | 8) != 1
      || *(unsigned __int16 *)(dword_13C114 + 32 * v5 + 20) > ((*(_WORD *)(v3 + 2 * (a2 + 348 * a1) + 316)
                                                              - *(_WORD *)(*(_DWORD *)(dword_13C114 + 32 * v5 + 28) + 4))
                                                             & 0xFFFu);
}

