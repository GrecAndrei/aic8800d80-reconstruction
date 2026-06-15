// v23 annotated: sub_119E3C @ 0x119e3c
// Original: 119e3c_sub_119E3C.c
// Primary struct: <unclustered>
//
// sub_119E3C @ 0x119e3c, size 184 bytes
void __fastcall __noreturn sub_119E3C(int a1, int a2, int a3)
{
  int v3; // r0
  int v4; // [sp+Ch] [bp-14h]
  int v5; // [sp+10h] [bp-10h]
  int v6; // [sp+14h] [bp-Ch]
  int v7; // [sp+18h] [bp-8h]
  int v8; // [sp+1Ch] [bp-4h]

  v3 = **(__int16 **)off_119F0C;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  if ( v3 < 0 )
  {
    if ( sub_11E34C(a3) )
      rf_cmd_send_n264(dword_119F08, dword_119F04, 337);
  }
  sub_1028B8();
}

