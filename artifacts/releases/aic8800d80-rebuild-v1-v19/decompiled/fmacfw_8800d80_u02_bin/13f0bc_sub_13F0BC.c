// sub_13F0BC @ 0x13f0bc, size 168 bytes
int __fastcall sub_13F0BC(int a1)
{
  __int16 **v1; // r7
  int v2; // r6
  __int16 *v3; // r8
  unsigned int v4; // r5
  unsigned int v6; // r0
  int v7; // r0
  _DWORD v9[10]; // [sp+0h] [bp-28h] BYREF

  v1 = (__int16 **)off_13F164;
  v2 = dword_13F168;
  v3 = *(__int16 **)off_13F164;
  v4 = *(_DWORD *)(dword_13F168 + 696 * a1 + 340);
  if ( **(__int16 **)off_13F164 < 0 && !v4 )
  {
    sub_12F46C(dword_13F170, dword_13F16C, 3297);
    v3 = *v1;
  }
  v6 = sub_13D34C(v4);
  *(_WORD *)(v4 + 184) = v6;
  if ( *v3 < 0 )
  {
    if ( !v6 )
    {
      sub_12F46C(dword_13F178, dword_13F16C, 3301);
      if ( **v1 >= 0 )
        goto LABEL_3;
      v6 = *(unsigned __int16 *)(v4 + 184);
    }
    if ( v6 > 0xA )
      sub_12F46C(dword_13F174, dword_13F16C, 3302);
  }
LABEL_3:
  sub_13E328(v4);
  v7 = sub_13CFF0(v4, v9);
  sub_13D47C(v7);
  *(_BYTE *)(v2 + 696 * a1 + 350) |= 1u;
  return 696;
}

