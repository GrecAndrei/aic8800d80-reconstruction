// fwstruct annotate: 128ca0_sub_128CA0.c
// sub_128CA0 @ 0x128ca0, size 64 bytes
int __fastcall sub_128CA0(int a1, int a2)
{
  int result; // r0
  unsigned __int16 *v5; // r2
  char v6; // r3

  feature_guard_check(2, dword_128CE4);
  result = sub_128B2C(a1, a2, dword_128CE8);
  if ( result )
  {
    v5 = (unsigned __int16 *)off_128CEC;
    if ( !*((_BYTE *)off_128CEC + 8) || (v6 = *((_BYTE *)off_128CEC + 8) - 1, (*((_BYTE *)off_128CEC + 8) = v6) == 0) )
    {
      *(_BYTE *)v5 = 1;
      return sub_12CA10(50, v5[1], 0);
    }
  }
  return result;
}

