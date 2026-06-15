// sub_11CAC8 @ 0x11cac8, size 170 bytes
int sub_11CAC8()
{
  _DWORD *v0; // r6
  int v1; // r7
  int v2; // r5
  int v3; // r4
  int v4; // r1
  int v5; // r3
  int v6; // r2
  int v7; // r1
  int v9; // r0
  int v10; // r1

  v0 = off_11CB74;
  v1 = *(_DWORD *)off_11CB74;
  v2 = *(_DWORD *)off_11CB74 + 6 * *((unsigned __int8 *)off_11CB74 + 10);
  v3 = 6 * *((unsigned __int8 *)off_11CB74 + 10);
  if ( (*(_BYTE *)(v2 + 3) & 5) != 0 )
  {
    v4 = *(_DWORD *)(*(_DWORD *)off_11CB78 + 20);
    if ( !v4 )
      v4 = dword_11CB7C;
  }
  else
  {
    v9 = fw_signature_check((unsigned __int16 *)(*(_DWORD *)off_11CB74 + 6 * *((unsigned __int8 *)off_11CB74 + 10)));
    v4 = 30000;
    if ( v9 )
      v4 = v9;
  }
  sub_11BB18((__int16 *)v2, v4, *(_BYTE *)(v1 + 366));
  v5 = v0[1];
  if ( v5 )
  {
    v6 = *(unsigned __int8 *)(v2 + 2);
    v7 = *(unsigned __int16 *)(v1 + v3);
    if ( *(_BYTE *)(v2 + 2) )
    {
      if ( v6 == 1 && (v10 = v7 - 4992, (unsigned __int16)(v10 - 13) <= 0x370u) )
        *(_BYTE *)(v5 + 2) = (unsigned int)(((unsigned int)dword_11CB80 * (unsigned __int64)(unsigned int)(v10 - 8)) >> 32) >> 2;
      else
        *(_BYTE *)(v5 + 2) = 0;
    }
    else
    {
      if ( (unsigned int)(v7 - 2412) <= 0x48 )
      {
        if ( v7 == 2484 )
        {
          *(_BYTE *)(v5 + 2) = 14;
          return sub_11E1E4(2);
        }
        LOBYTE(v6) = (unsigned int)(((unsigned int)dword_11CB80 * (unsigned __int64)(unsigned int)(v7 - 2407)) >> 32) >> 2;
      }
      *(_BYTE *)(v5 + 2) = v6;
    }
  }
  return sub_11E1E4(2);
}

