// fwstruct annotate: 11ef38_fw_version_check_n_38.c
// fw_version_check_n_38 @ 0x11ef38, size 52 bytes
// Doc: fw_version_check_n_38 [util]: Compare firmware version or build ID against expected value
// fw_version_check_n_38 [util]: Compare firmware version or build ID against expected value
unsigned int fw_version_check_n_38()
{
  int v0; // r3
  unsigned int result; // r0
  unsigned int v2; // r3
  int v3; // r3

  v0 = *((_DWORD *)off_11EF6C + 2);
  if ( v0 == *(_DWORD *)off_11EF70 )
    return 0;
  result = v0 & 0x7FFFFFFF;
  if ( *((_DWORD *)off_11EF6C + 1) - (v0 & 0x7FFFFFFFu) <= 0x9F )
  {
    v2 = v0 & 0x80000000;
    if ( result > *(_DWORD *)off_11EF6C )
      v2 += 0x80000000;
    v3 = v2 | *(_DWORD *)off_11EF6C;
    *((_DWORD *)off_11EF6C + 2) = v3;
    return v3 & 0x7FFFFFFF;
  }
  return result;
}

