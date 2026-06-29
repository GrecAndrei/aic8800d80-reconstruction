// sub_119F9C @ 0x119f9c, size 130 bytes
int  sub_119F9C(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v7; // r2
  uint16_t *v8; // r5
  int result; // r0

  if ( sub_11E34C(a3) == 3 || sub_11E34C(a3) == 4 )
    return 2;
  v7 = *a2;
  v8 = off_11A020;
  *((uint8_t *)off_11A020 + 28) = v7;
  if ( !v7 )
  {
    if ( sub_11E34C(a3) != 2 )
    {
      mmio_init_clock_gate_n121();
LABEL_6:
      sub_11DED8(35, a4, a3);
      return 0;
    }
    return 2;
  }
  result = sub_11E34C(a3);
  if ( !result )
  {
    if ( **(__int16 **)off_11A024 < 0 )
    {
      if ( *(uint32_t *)off_11A028 << 28 )
        rf_cmd_send_n264(dword_11A030, dword_11A02C, 1522);
    }
    v8[8] = 0;
    goto LABEL_6;
  }
  if ( result != 2 )
  {
    sub_11D01C();
    sub_11E1E4(a3);
    return 2;
  }
  return result;
}

