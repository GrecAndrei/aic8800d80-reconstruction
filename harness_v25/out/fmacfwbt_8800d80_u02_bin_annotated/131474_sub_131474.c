// fwstruct annotate: 131474_sub_131474.c
// sub_131474 @ 0x131474, size 88 bytes
int __fastcall sub_131474(unsigned __int8 *a1, int a2, int a3, _BYTE *a4)
{
  int result; // r0
  char v7; // r2
  int v8; // r2
  int v9; // r7
  int v10; // r5
  int v11; // r3

  result = (int)sdio_buffer_prepare_e188(a1, a2);
  *a4 = 0;
  if ( result )
  {
    v7 = *(_BYTE *)(result + 3);
    if ( *(_BYTE *)(a3 + 17) == (v7 & 0xF) )
    {
      return 1;
    }
    else
    {
      *a4 = 1;
      *(_BYTE *)(a3 + 16) = v7;
      *(_BYTE *)(a3 + 17) = v7 & 0xF;
      v8 = *(unsigned __int16 *)(result + 8);
      v9 = *(unsigned __int16 *)(result + 11);
      v10 = *(unsigned __int16 *)(result + 14);
      *(_DWORD *)(a3 + 4) = *(unsigned __int8 *)(result + 4) | (*(unsigned __int16 *)(result + 5) << 8);
      *(_DWORD *)a3 = *(unsigned __int8 *)(result + 7) | (v8 << 8);
      *(_DWORD *)(a3 + 8) = *(unsigned __int8 *)(result + 10) | (v9 << 8);
      v11 = *(unsigned __int8 *)(result + 13) | (v10 << 8);
      result = 1;
      *(_DWORD *)(a3 + 12) = v11;
    }
  }
  return result;
}

