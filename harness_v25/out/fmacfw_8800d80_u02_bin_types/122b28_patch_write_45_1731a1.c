// patch_write_45_1731a1 @ 0x122b28, size 28 bytes
// Doc: patch_write_45_1731a1 [patch]: Call patch helper with marker 0x1731a1 and value 0x45
// patch_write_45_1731a1 [patch]: Call patch helper with marker 0x1731a1 and value 0x45
int  patch_write_45_1731a1(int a1, int a2, int a3, int a4)
{
  sub_143770(dword_122B44, a2, 69);
  sub_12CA10(120, a4, a3);
  return 0;
}

