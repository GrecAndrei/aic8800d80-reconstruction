// v23 annotated: fw_state_check_n960 @ 0x10f188
// Original: 10f188_fw_state_check_n960.c
// Primary struct: <unclustered>
//
// fw_state_check_n960 @ 0x10f188, size 82 bytes
// Doc: fw_state_check_n960 [util]: Load firmware state word from 0x182b60 and test sign
// fw_state_check_n960 [util]: Load firmware state word from 0x182b60 and test sign
int __fastcall fw_state_check_n960(int a1)
{
  unsigned int v2; // r0
  unsigned int v3; // r1

  v2 = sub_10EFBC(dword_10F1DC, 1);
  v3 = (v2 >> 20) & 0xF;
  if ( a1 )
  {
    if ( ((v2 >> 20) & 0xE) != 0 )
    {
      v3 = ((v3 - 2) << 20) & 0xF00000;
    }
    else if ( v3 )
    {
      v3 = ((v3 - 1) << 20) & 0xF00000;
    }
  }
  else if ( v3 > 0xD )
  {
    v3 = 15728640;
  }
  else
  {
    v3 = ((v3 + 2) << 20) & 0xF00000;
  }
  return sub_10F064(dword_10F1DC, v3, 15728640, 1);
}

