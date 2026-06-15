// v23 annotated: sub_122AB8 @ 0x122ab8
// Original: 122ab8_sub_122AB8.c
// Primary struct: phy_reg_param (cluster 12, 6 funcs)
// Fields: addr=0x0, status=0x6a
//
// sub_122AB8 @ 0x122ab8, size 76 bytes
// Doc: ipc_msg_status_check [ipc]: Inspect IPC message field mask 0x1800000 and branch on r3
// ipc_msg_status_check [ipc]: Inspect IPC message field mask 0x1800000 and branch on r3
char *sub_122AB8()
{
  int v0; // r4

  v0 = *(_DWORD *)off_122B08 & 0x1800000;
  if ( **(__int16 **)off_122B04 < 0 && v0 == 25165824 )
    sub_12F694(dword_122B18, dword_122B14, 1308);
  sub_12D374(v0);
  if ( *((_BYTE *)off_122B0C + 18) )
    return (char *)sub_121430();
  else
    return sub_1229C8(*((char **)off_122B10 + 8));
}

