// v23 annotated: sub_13F158 @ 0x13f158
// Original: 13f158_sub_13F158.c
// Primary struct: <unclustered>
//
// sub_13F158 @ 0x13f158, size 168 bytes
int __fastcall sub_13F158(int a1)
{
  __int16 **v1; // r7
  int v2; // r6
  __int16 *v3; // r8
  unsigned int v4; // r5
  unsigned int v6; // r0
  int v7; // r0
  _DWORD v9[10]; // [sp+0h] [bp-28h] BYREF

  v1 = (__int16 **)off_13F200;
  v2 = dword_13F204;
  v3 = *(__int16 **)off_13F200;
  v4 = *(_DWORD *)(dword_13F204 + 696 * a1 + 340);
  if ( **(__int16 **)off_13F200 < 0 && !v4 )
  {
    sub_12F694(dword_13F20C, dword_13F208, 3297);
    v3 = *v1;
  }
  v6 = sub_13D3E8(v4);
  *(_WORD *)(v4 + 184) = v6;
  if ( *v3 < 0 )
  {
    if ( !v6 )
    {
      sub_12F694(dword_13F214, dword_13F208, 3301);
      if ( **v1 >= 0 )
        goto LABEL_3;
      v6 = *(unsigned __int16 *)(v4 + 184);
    }
    if ( v6 > 0xA )
      sub_12F694(dword_13F210, dword_13F208, 3302);
  }
LABEL_3:
  sub_13E3C4(v4);
  v7 = sub_13D08C(v4, v9);
  sub_13D518(v7);
  *(_BYTE *)(v2 + 696 * a1 + 350) |= 1u;
  return 696;
}

