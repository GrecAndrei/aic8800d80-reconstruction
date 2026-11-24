// sub_1337FC @ 0x1337fc, size 58 bytes
// Doc: sub_1233806 [util]: Trampoline stub with saved r4/lr
// sub_1233806 [util]: Trampoline stub with saved r4/lr
int __fastcall sub_1337FC(int a1, int a2)
{
  if ( **(__int16 **)off_133838 >= 0 || msg_get_value(6u) == 7 )
  {
    sub_135A80(a2);
    return 1;
  }
  else
  {
    sub_12F46C(dword_133840, dword_13383C, 1012);
    sub_135A80(a2);
    return 1;
  }
}

