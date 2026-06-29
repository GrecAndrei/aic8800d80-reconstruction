// fwstruct annotate: 125ad8_sub_125AD8.c
// sub_125AD8 @ 0x125ad8, size 158 bytes
// Doc: sub_1225AD8 [unknown]: Small helper function called from lmac context
// sub_1225AD8 [unknown]: Small helper function called from lmac context
unsigned int __fastcall sub_125AD8(unsigned int result)
{
  unsigned int v1; // r4
  char *v2; // r3
  int v3; // r1
  int *v4; // r3
  int v5; // r2
  int *v6; // r3
  int v7; // r2
  int v8; // r0
  int *v9; // r3
  int v10; // r2
  int v11; // r0
  _DWORD *v12; // r3
  int v13; // r2
  __int64 v14; // [sp+0h] [bp-8h] BYREF

  if ( result )
  {
    v1 = result;
    if ( result <= 2 )
    {
      get_cached_1828f8(&v14, 0);
      v2 = (char *)off_125B78;
      v3 = BYTE1(v14);
      *(_DWORD *)off_125B78 = dword_125B7C;
      if ( v1 == 1 )
      {
        if ( v3 )
        {
          v12 = off_125BBC;
          *(_DWORD *)off_125BB8 = 2047;
          *v12 = 341;
        }
        else
        {
          v13 = dword_125BD0;
          *(_DWORD *)off_125B80 = dword_125BCC;
          *(_DWORD *)&v2[-140] = v13;
        }
        *(_DWORD *)off_125B90 = dword_125BC0;
      }
      else
      {
        if ( v3 )
        {
          v4 = (int *)off_125BBC;
          v5 = dword_125BC8;
          *(_DWORD *)off_125BB8 = dword_125BC4;
        }
        else
        {
          v4 = (int *)off_125B84;
          v5 = dword_125B8C;
          *(_DWORD *)off_125B80 = dword_125B88;
        }
        *v4 = v5;
        *(_DWORD *)off_125B90 = dword_125B94;
      }
      v6 = (int *)off_125B9C;
      v7 = dword_125BA0;
      *(_DWORD *)off_125B98 = dword_125BA4;
      v8 = dword_125BA8;
      *v6 = v7;
      return msg_parse(v8);
    }
  }
  else
  {
    v9 = (int *)off_125B9C;
    v10 = dword_125BAC;
    *(_DWORD *)off_125B78 = dword_125BB0;
    v11 = dword_125BB4;
    *v9 = v10;
    return msg_parse(v11);
  }
  return result;
}

