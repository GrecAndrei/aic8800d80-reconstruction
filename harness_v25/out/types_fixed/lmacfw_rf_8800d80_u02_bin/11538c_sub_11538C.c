// sub_11538C @ 0x11538c, size 90 bytes
int __fastcall sub_11538C(int result)
{
  __int64 v1; // kr00_8
  int v2; // r2
  int v3; // r3
  int v4; // r2
  unsigned int v5; // r3
  int v6; // r3

  v1 = *(_QWORD *)(result + 28);
  v2 = *(_DWORD *)(HIDWORD(v1) + 24);
  v3 = *(_DWORD *)(v1 + 96);
  *(_DWORD *)(HIDWORD(v1) + 60) = v3;
  *(_DWORD *)(HIDWORD(v1) + 44) = v1 + 44;
  if ( !v2 )
  {
    v4 = *(_DWORD *)(HIDWORD(v1) + 20);
    if ( **(__int16 **)off_1153E8 < 0 && !v4 )
    {
      result = rf_cmd_send_n264(dword_1153F0, dword_1153EC, 525);
      v4 = *(_DWORD *)(HIDWORD(v1) + 20);
      v3 = *(_DWORD *)(HIDWORD(v1) + 60);
    }
    v2 = *(_DWORD *)(v4 + 8);
  }
  v5 = v3 & 0xFFFFF9FF;
  *(_DWORD *)(HIDWORD(v1) + 60) = v5;
  if ( (*(_BYTE *)(v2 + 4) & 1) == 0 )
    *(_DWORD *)(HIDWORD(v1) + 60) = v5 | 0x200;
  v6 = *(_DWORD *)(v1 + 48);
  *(_DWORD *)(HIDWORD(v1) + 40) = *(_DWORD *)(v1 + 100);
  *(_DWORD *)(v1 + 48) = v6 | 2;
  return result;
}

