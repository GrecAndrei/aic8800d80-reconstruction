// fwstruct annotate: 123a94_sub_123A94.c
// sub_123A94 @ 0x123a94, size 182 bytes
void __fastcall __noreturn sub_123A94(int a1, int a2, int a3)
{
  int v3; // r0
  int v4; // [sp+10h] [bp-18h]
  int v5; // [sp+14h] [bp-14h]
  int v6; // [sp+18h] [bp-10h]
  int v7; // [sp+1Ch] [bp-Ch]
  int v8; // [sp+20h] [bp-8h]
  int v9; // [sp+24h] [bp-4h]

  v3 = **(__int16 **)off_123B64;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  if ( v3 < 0 )
  {
    if ( msg_get_value(a3) )
      sub_12F46C(dword_123B60, dword_123B5C, 337);
  }
  fmac_init_step();
}

