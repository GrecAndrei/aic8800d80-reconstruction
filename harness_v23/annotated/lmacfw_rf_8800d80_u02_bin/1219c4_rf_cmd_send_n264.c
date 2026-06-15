// v23 annotated: rf_cmd_send_n264 @ 0x1219c4
// Original: 1219c4_rf_cmd_send_n264.c
// Primary struct: <unclustered>
//
// rf_cmd_send_n264 @ 0x1219c4, size 36 bytes
// Doc: rf_cmd_send_n264 [rf]: Send RF command (n264 variant) via MMIO
// rf_cmd_send_n264 [rf]: Send RF command (n264 variant) via MMIO
int __fastcall rf_cmd_send_n264(int a1, int a2, int a3)
{
  int v4; // r0
  int result; // r0

  __disable_irq();
  v4 = dword_1219EC;
  *(_DWORD *)off_1219E8 = 0;
  result = msg_parse(v4, a1, a2, a3 & 0xFFFFF);
  while ( *(_DWORD *)off_1219F0 )
    ;
  return result;
}

