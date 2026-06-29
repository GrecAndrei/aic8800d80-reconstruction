// fwstruct annotate: 117af8_rf_init_subsystem_7af8.c
// rf_init_subsystem_7af8 @ 0x117af8, size 74 bytes
// Doc: rf_init_subsystem_7af8 [rf]: Initialize RF subsystem state, loop clearing slots
// rf_init_subsystem_7af8 [rf]: Initialize RF subsystem state, loop clearing slots
int rf_init_subsystem_7af8()
{
  int v0; // r5
  int v1; // r7
  int i; // r6
  int v3; // r4
  int v4; // r0
  int result; // r0

  v0 = dword_117B48;
  v1 = dword_117B44;
  sub_11E71C(dword_117B44);
  for ( i = 0; i != 76; i += 19 )
  {
    sub_117AC8(v0 - 88);
    list_push_tail(v1);
    v3 = v0 - 32;
    do
    {
      sub_11E71C(v3);
      v4 = v3 + 32;
      v3 += 8;
      result = sub_11E71C(v4);
    }
    while ( v3 != v0 );
    v0 = v3 + 152;
  }
  return result;
}

