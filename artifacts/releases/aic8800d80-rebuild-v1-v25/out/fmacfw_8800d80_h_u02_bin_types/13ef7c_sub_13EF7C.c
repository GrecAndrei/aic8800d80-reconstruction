// sub_13EF7C @ 0x13ef7c, size 168 bytes
int  sub_13EF7C(int a1)
{
  __int16 **v1; // r7
  int v2; // r6
  __int16 *v3; // r8
  unsigned int v4; // r5
  unsigned int v6; // r0
  int v7; // r0
  uint32_t v9[10]; // [sp+0h] [bp-28h] BYREF

  v1 = (__int16 **)off_13F024;
  v2 = dword_13F028;
  v3 = *(__int16 **)off_13F024;
  v4 = *(uint32_t *)(dword_13F028 + 696 * a1 + 340);
  if ( **(__int16 **)off_13F024 < 0 && !v4 )
  {
    sub_12F32C(dword_13F030, dword_13F02C, 3297);
    v3 = *v1;
  }
  v6 = sub_13D20C(v4);
  *(uint16_t *)(v4 + 184) = v6;
  if ( *v3 < 0 )
  {
    if ( !v6 )
    {
      sub_12F32C(dword_13F038, dword_13F02C, 3301);
      if ( **v1 >= 0 )
        goto LABEL_3;
      v6 = *(unsigned __int16 *)(v4 + 184);
    }
    if ( v6 > 0xA )
      sub_12F32C(dword_13F034, dword_13F02C, 3302);
  }
LABEL_3:
  sub_13E1E8(v4);
  v7 = sub_13CEB0(v4, v9);
  sub_13D33C(v7);
  *(uint8_t *)(v2 + 696 * a1 + 350) |= 1u;
  return 696;
}

