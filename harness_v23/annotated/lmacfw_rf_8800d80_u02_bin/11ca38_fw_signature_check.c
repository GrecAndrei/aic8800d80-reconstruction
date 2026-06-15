// v23 annotated: fw_signature_check @ 0x11ca38
// Original: 11ca38_fw_signature_check.c
// Primary struct: <unclustered>
//
// fw_signature_check @ 0x11ca38, size 88 bytes
// Doc: fw_signature_check [util]: Check firmware header magic against expected value 0x96c
// fw_signature_check [util]: Check firmware header magic against expected value 0x96c
int __fastcall fw_signature_check(unsigned __int16 *a1)
{
  int v1; // r3
  int result; // r0

  v1 = *a1;
  result = *(_DWORD *)(*(_DWORD *)off_11CA90 + 16);
  if ( v1 == 2412
    || v1 == 2437
    || v1 == 2462
    || v1 == 2472
    || v1 == 5180
    || v1 == 5220
    || v1 == 5765
    || v1 == 5785
    || v1 == 5805 )
  {
    result += 20000;
  }
  return result;
}

