// crypto_hw_sequence_7a8c @ 0x107a8c, size 414 bytes
// Doc: crypto_hw_sequence_7a8c [util]: Program hardware crypto sequence
// crypto_hw_sequence_7a8c [util]: Program hardware crypto sequence
int __fastcall crypto_hw_sequence_7a8c(int a1)
{
  _DWORD *v1; // r4
  _DWORD *v2; // r6
  int *v3; // r5
  int v4; // r7
  _DWORD *v5; // r11
  int v7; // r1
  int v8; // r3
  bool v9; // cc
  int v10; // r2
  int v11; // r9
  int v12; // r1
  int result; // r0
  unsigned int v14; // [sp+20h] [bp-14h] BYREF
  unsigned int v15; // [sp+24h] [bp-10h]
  int v16; // [sp+28h] [bp-Ch]
  int v17; // [sp+2Ch] [bp-8h]

  v1 = off_107C2C;
  v2 = off_107C30;
  v3 = (int *)off_107C34;
  v4 = dword_107C38;
  v5 = off_107C44;
  crypto_state_dump(a1);
  v7 = dword_107C3C;
  *v1 |= 0x1000000u;
  *v1 |= 0x2000000u;
  feature_guard_check(1, v7);
  crypto_engine_clear_sram_regs();
  *v2 &= ~1u;
  delay_us_0644(20);
  *v2 |= 4u;
  *v2 |= 8u;
  delay_us_0644(20);
  *v1 |= 0x800000u;
  *v3 = *v3 & v4 | 0xC000000;
  delay_us_0644(20);
  *v1 |= 0x4000000u;
  v8 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  v14 = v8;
  *v3 = *v3 & v4 | 0x4000000;
  delay_us_0644(20);
  *v1 |= 0x4000000u;
  v15 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  v9 = v14 > v15;
  if ( v14 <= v15 )
    v10 = 234881024;
  else
    v10 = 100663296;
  *v3 = *v3 & v4 | v10;
  if ( v9 )
    v11 = 0x2000000;
  else
    v11 = 167772160;
  delay_us_0644(20);
  *v1 |= 0x4000000u;
  v16 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  *v3 = *v3 & v4 | v11;
  delay_us_0644(20);
  v12 = dword_107C40;
  *v1 |= 0x4000000u;
  v17 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  *v1 &= ~0x800000u;
  feature_guard_check(1, v12);
  result = sub_1079CC(&v14, a1);
  *v2 &= ~4u;
  *v2 &= ~8u;
  *v3 &= v4;
  *v1 &= ~0x1000000u;
  *v1 &= ~0x2000000u;
  return result;
}

