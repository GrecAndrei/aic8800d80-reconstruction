// fw_state_lookup_n_528 @ 0x128cf8, size 80 bytes
// Doc: fw_state_lookup_n_528 [util]: Look up state slot in 0x528-stride table indexed by byte
// fw_state_lookup_n_528 [util]: Look up state slot in 0x528-stride table indexed by byte
int __fastcall fw_state_lookup_n_528(int a1)
{
  unsigned __int8 *v1; // r6
  int v2; // r4
  _BYTE *v4; // r0

  v1 = (unsigned __int8 *)off_128D48;
  v2 = dword_128D4C + 1320 * *((unsigned __int8 *)off_128D48 + 16);
  if ( *(_DWORD *)(v2 + 72) )
  {
    sub_1287E0(*((unsigned __int8 *)off_128D48 + 16));
  }
  else
  {
    v4 = (_BYTE *)rf_bus_setup_n3a8(5143, 5, 5, 2);
    *v4 = 1;
    v4[1] = *(_BYTE *)(v2 + 107);
    sub_12CBB4(v4);
  }
  return sub_128AAC(v1[16], a1);
}

