// v23 annotated: rx_descriptor_init @ 0x135ab0
// Original: 135ab0_rx_descriptor_init.c
// Primary struct: <unclustered>
//
// rx_descriptor_init @ 0x135ab0, size 76 bytes
// Doc: rx_descriptor_init [rx]: Initialize RX descriptor ring
// rx_descriptor_init [rx]: Initialize RX descriptor ring
_BYTE *__fastcall rx_descriptor_init(_BYTE *a1, int a2)
{
  _BYTE *result; // r0
  int v3; // r2
  unsigned int v4; // r3
  _BYTE *v5; // r0
  int v6; // r1
  unsigned int v7; // r3
  _BYTE *v8; // r0
  char v9[5]; // [sp+7h] [bp-5h] BYREF

  result = sub_12D994(a1, a2, v9);
  if ( result )
  {
    if ( (unsigned __int8)v9[0] <= 0x1Du )
      return nullptr;
    v3 = (unsigned __int16)(4 * *((_WORD *)result + 4));
    v4 = (unsigned __int8)(v9[0] - 10 - 4 * result[8]);
    if ( v4 <= 0x15 )
      return nullptr;
    v5 = result + 10;
    v6 = (unsigned __int16)(4 * *(_WORD *)&v5[v3]);
    v7 = (unsigned __int8)(v4 - 2 - 4 * v5[v3]);
    v8 = &v5[v3];
    if ( v7 <= 0x13 )
      return nullptr;
    else
      return (_BYTE *)*(unsigned __int16 *)&v8[v6 + 4];
  }
  return result;
}

