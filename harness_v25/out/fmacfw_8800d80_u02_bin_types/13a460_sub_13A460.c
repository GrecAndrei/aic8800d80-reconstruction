// sub_13A460 @ 0x13a460, size 64 bytes
int  sub_13A460(int a1, int a2)
{
  int v2; // r4
  uint32_t *v3; // r5
  int result; // r0

  v2 = a1 + 4 * a2;
  v3 = *(uint32_t **)(v2 + 408);
  if ( **(__int16 **)off_13A4A0 < 0 && !v3 )
    sub_12F46C(dword_13A4AC, dword_13A4A8, 3320);
  timestamp_remove((int)(v3 + 68));
  result = list_push_tail(dword_13A4A4, v3);
  *(uint32_t *)(v2 + 408) = 0;
  return result;
}

