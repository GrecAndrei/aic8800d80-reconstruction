// v23 annotated: fmac_status_check_init @ 0x133c70
// Original: 133c70_fmac_status_check_init.c
// Primary struct: <unclustered>
//
// fmac_status_check_init @ 0x133c70, size 90 bytes
// Doc: fmac_status_check_init [util]: Reads FW status word and initializes stack frame
// fmac_status_check_init [util]: Reads FW status word and initializes stack frame
int fmac_status_check_init()
{
  int v0; // r2
  int v2; // [sp+0h] [bp-Ch] BYREF
  int v3; // [sp+4h] [bp-8h] BYREF

  v0 = **(__int16 **)off_133CCC;
  v2 = 0;
  v3 = 0;
  if ( v0 < 0 && msg_get_value(6u) != 1 )
    sub_12F694(dword_133CD4, dword_133CD0, 303);
  sub_134690(&v2, &v3);
  if ( v2 && v3 )
  {
    sub_1347DC();
    return 0;
  }
  else
  {
    sub_135020(1);
    return 0;
  }
}

