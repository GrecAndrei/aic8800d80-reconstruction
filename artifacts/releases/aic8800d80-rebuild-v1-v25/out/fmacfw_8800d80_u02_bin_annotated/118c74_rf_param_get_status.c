// fwstruct annotate: 118c74_rf_param_get_status.c
// rf_param_get_status @ 0x118c74, size 94 bytes
// Doc: rf_param_get_status [rf]: Read RF status fields from structure at offset 0x48 and 0x1c
// rf_param_get_status [rf]: Read RF status fields from structure at offset 0x48 and 0x1c
int __fastcall rf_param_get_status(int a1, int a2)
{
  __int64 v2; // kr00_8
  int v3; // r2
  int v6; // r12
  int v7; // r3
  char v8; // r2

  v2 = *(_QWORD *)(a1 + 72);
  v3 = *(_DWORD *)(HIDWORD(v2) + 28);
  if ( **(__int16 **)off_118CD4 < 0 && (v3 & 1) != 0 )
  {
    sub_12F46C(dword_118CDC, dword_118CD8, 389);
    v3 = *(_DWORD *)(HIDWORD(v2) + 28);
  }
  v6 = *(_DWORD *)(HIDWORD(v2) + 44);
  *(_DWORD *)(HIDWORD(v2) + 68) &= 0xFF87FFFF;
  v7 = 0;
  *(_QWORD *)(HIDWORD(v2) + 16) = 0;
  v8 = *(_BYTE *)(v3 + 4);
  *(_DWORD *)(HIDWORD(v2) + 72) = 0;
  if ( (v8 & 1) == 0 )
    v7 = 512;
  *(_DWORD *)(HIDWORD(v2) + 64) = v7;
  *(_DWORD *)(v2 + 96) = v7;
  *(_DWORD *)(v2 + 100) = v6;
  return sub_1176A0(a1, a2);
}

