// sub_11831C @ 0x11831c, size 56 bytes
// Doc: sub_121831C [mac]: Initialize and register a small lmac control block via memset and log_alloc
// sub_121831C [mac]: Initialize and register a small lmac control block via memset and log_alloc
int sub_11831C()
{
  int v0; // r4

  v0 = dword_118354;
  memset_thunk((int *)dword_118354, 0, 0x28u);
  bt_xtal_init_check(v0);
  bt_xtal_init_check(v0 + 8);
  bt_xtal_init_check(v0 + 16);
  bt_xtal_init_check(v0 + 24);
  return bt_xtal_init_check(v0 + 32);
}

