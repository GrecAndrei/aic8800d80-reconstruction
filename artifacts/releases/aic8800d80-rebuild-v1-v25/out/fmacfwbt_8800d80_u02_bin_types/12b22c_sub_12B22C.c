// sub_12B22C @ 0x12b22c, size 98 bytes
int sub_12B22C()
{
  int v0; // r5
  int v1; // r4
  int v2; // r0
  int v3; // r2

  v0 = *(uint32_t *)off_12B290;
  v1 = *((unsigned __int8 *)off_12B290 + 10);
  if ( sub_12D0B0(2) != 2 )
  {
    v2 = sub_12D0B0(2);
    sub_12ECB0(dword_12B294, v2, v3);
  }
  if ( **(__int16 **)off_12B298 < 0 && sub_12D0B0(2) != 2 )
    sub_12F694(dword_12B2A0, dword_12B29C, 163);
  if ( (*(uint8_t *)(v0 + 6 * v1 + 3) & 1) == 0 )
    sub_12B5BC();
  sub_12CF5C(2);
  return 0;
}

