// sub_103A54 @ 0x103a54, size 138 bytes
int sub_103A54()
{
  _DWORD *v0; // r2
  int v1; // r3
  _DWORD *v2; // r3
  _DWORD *v3; // r2
  int v4; // r3
  _DWORD *v5; // r3
  _DWORD *v6; // r0
  int v7; // r1

  v0 = off_103AE4;
  *(_DWORD *)off_103AE0 |= 1u;
  while ( (*v0 & 0x10) == 0 )
  {
    LOWORD(v1) = 50;
    do
      v1 = (unsigned __int16)(v1 - 1);
    while ( v1 );
  }
  v2 = off_103AE8;
  v3 = off_103AE4;
  *(_DWORD *)off_103AE8 |= 0x80000u;
  *v2 |= 0x100000u;
  while ( (*v3 & 8) == 0 )
  {
    LOWORD(v4) = 50;
    do
      v4 = (unsigned __int16)(v4 - 1);
    while ( v4 );
  }
  v5 = off_103AF0;
  v6 = off_103AF4;
  v7 = dword_103AF8;
  *(_DWORD *)off_103AEC |= 0x20000u;
  *v5 |= 0x1000000u;
  *v5 |= 0x8000000u;
  *v6 |= 0x524u;
  return sub_12EB90(0x2000, v7);
}

