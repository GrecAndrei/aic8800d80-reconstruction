// sub_12C6AC @ 0x12c6ac, size 64 bytes
// Doc: mac_msg_post_4ff [mac]: Build message via KE helper and post opcode 0x4ff to MAC hardware register REG_4032_00a0.
// mac_msg_post_4ff [mac]: Build message via KE helper and post opcode 0x4ff to MAC hardware register REG_4032_00a0.
int __fastcall sub_12C6AC(char a1)
{
  int result; // r0
  unsigned int *v2; // r2
  _BYTE *(_DWORD *)(v3 + 0x1c); // [sp+7h] [bp-Dh] BYREF
  unsigned __int8 v4; // [sp+Eh] [bp-6h] BYREF
  _BYTE *(_DWORD *)(v5 + 0x14); // [sp+Fh] [bp-5h] BYREF

  *(_DWORD *)(v3 + 0x0) = a1;
  result = sub_10197C((int)v3, &v4, v5);
  v2 = (unsigned int *)off_12C6EC;
  *(_DWORD *)off_12C6EC = *(_DWORD *)off_12C6EC & 0xFFFF00FF | (v4 << 8);
  *v2 = *v2 & 0xFFFFFF00 | *(_DWORD *)(v5 + 0x0);
  return result;
}

