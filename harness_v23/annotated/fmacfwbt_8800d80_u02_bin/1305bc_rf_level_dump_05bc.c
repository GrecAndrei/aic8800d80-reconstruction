// v23 annotated: rf_level_dump_05bc @ 0x1305bc
// Original: 1305bc_rf_level_dump_05bc.c
// Primary struct: <unclustered>
//
// rf_level_dump_05bc @ 0x1305bc, size 118 bytes
// Doc: rf_level_dump_05bc [rf]: Dump signed RF level readings (signed bytes) to log
// rf_level_dump_05bc [rf]: Dump signed RF level readings (signed bytes) to log
int rf_level_dump_05bc()
{
  unsigned __int8 *v0; // r4
  int v1; // r4
  int v2; // r0
  int v4; // [sp+14h] [bp-4h]

  v0 = (unsigned __int8 *)off_130634;
  sub_12ECB0(
    dword_130638,
    *(char *)off_130634,
    *((char *)off_130634 + 1),
    *((char *)off_130634 + 2),
    *((char *)off_130634 + 3));
  sub_12ECB0(dword_13063C, v0[4], v0[5], v0[6]);
  sub_12ECB0(dword_130640, (char)v0[8], (char)v0[9], (char)v0[10], (char)v0[11], (char)v0[12], (char)v0[13]);
  v1 = *((unsigned __int8 *)off_130644 + 363);
  v4 = *((_DWORD *)off_130644 + 91);
  v2 = message_dispatch_n_d8(1070, 1);
  return sub_12ECB0(dword_130648, v1, v4, v2);
}

