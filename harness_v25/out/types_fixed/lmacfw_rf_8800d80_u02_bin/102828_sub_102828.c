// sub_102828 @ 0x102828, size 110 bytes
void __fastcall sub_102828()
{
  int *v0; // r3
  int *v1; // r2
  int *v2; // r1
  _DWORD *v3; // r4
  int *v4; // r1
  int v5; // r0

  fw_state_check_n_c0();
  v0 = (int *)off_102898;
  *(_DWORD *)off_102898 = dword_10289C;
  *v0 |= 0x80000000;
  while ( *v0 < 0 )
    ;
  *v0 = dword_1028A0;
  v1 = (int *)off_102898;
  *v0 |= 0x80000000;
  while ( *v1 < 0 )
    ;
  *v1 = dword_1028A4;
  v2 = (int *)off_102898;
  *v1 |= 0x80000000;
  while ( *v2 < 0 )
    ;
  sub_101E18((unsigned int)*v2 >> 31, 2412, 2412, (unsigned int)*v2 >> 31);
  v3 = off_1028AC;
  v4 = (int *)off_1028B0;
  v5 = dword_1028B4;
  *(_DWORD *)off_1028A8 &= ~0x200u;
  *v3 = 12;
  *v4 = v5;
}
