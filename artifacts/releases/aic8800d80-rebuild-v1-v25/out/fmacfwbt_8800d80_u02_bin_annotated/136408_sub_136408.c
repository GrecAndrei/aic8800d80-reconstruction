// fwstruct annotate: 136408_sub_136408.c
// sub_136408 @ 0x136408, size 52 bytes
// Doc: sub_1236408 [util]: Check shared half-word status flag from globals table and branch
// sub_1236408 [util]: Check shared half-word status flag from globals table and branch
int __fastcall sub_136408(int value)
{
  int v2; // r0

  if ( **(__int16 **)off_13643C >= 0 || (value = msg_get_value(7u), value == 3) )
  {
    sub_13697C(value);
    return 0;
  }
  else
  {
    v2 = sub_12F694(dword_136444, dword_136440, 415);
    sub_13697C(v2);
    return 0;
  }
}

