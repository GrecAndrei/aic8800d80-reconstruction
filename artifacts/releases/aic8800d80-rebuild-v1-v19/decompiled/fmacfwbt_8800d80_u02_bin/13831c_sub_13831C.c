// sub_13831C @ 0x13831c, size 86 bytes
// Doc: sub_123831C [util]: Loads pointer from 0x192d84, accesses +0xf00 offset byte
// sub_123831C [util]: Loads pointer from 0x192d84, accesses +0xf00 offset byte
int __fastcall sub_13831C(unsigned __int16 *a1)
{
  int v1; // r3
  int v2; // r1

  v1 = dword_138374;
  v2 = dword_138374 + 3840;
  while ( !*(_BYTE *)v1 )
  {
    v1 += 60;
    if ( v1 == v2 )
      return 0;
  }
  if ( *(unsigned __int16 *)(v1 + 2) == *a1 )
    goto LABEL_7;
  while ( 1 )
  {
    v1 += 60;
    if ( v1 == v2 )
      break;
    if ( *(_BYTE *)v1 && *(unsigned __int16 *)(v1 + 2) == *a1 )
    {
LABEL_7:
      if ( *(unsigned __int16 *)(v1 + 4) == a1[1] && *(unsigned __int16 *)(v1 + 6) == a1[2] )
        return v1;
    }
  }
  return 0;
}

