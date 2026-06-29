// sub_1165B0 @ 0x1165b0, size 78 bytes
// Doc: sub_12165B0 [rf]: LMAC RF helper, checks flag and dispatches operation
// sub_12165B0 [rf]: LMAC RF helper, checks flag and dispatches operation
int  sub_1165B0(int a1, int a2)
{
  uint64_t v2; // kr00_8
  int v5; // r2

  v2 = *(QWORD *)(a1 + 28);
  if ( **(__int16 **)off_116600 < 0 && (*(uint32_t *)(HIDWORD(v2) + 24) & 1) != 0 )
    rf_cmd_send_n264(dword_116608, dword_116604, 389);
  v5 = *(uint32_t *)(HIDWORD(v2) + 40);
  *(uint32_t *)(HIDWORD(v2) + 64) &= 0xFF87FFFF;
  *(QWORD *)(HIDWORD(v2) + 12) = 0;
  *(uint32_t *)(HIDWORD(v2) + 60) = 0;
  *(uint32_t *)(HIDWORD(v2) + 68) = 0;
  *(uint32_t *)(v2 + 96) = 0;
  *(uint32_t *)(v2 + 100) = v5;
  return rf_subcmd_dispatch_n5b60(a1, a2);
}

