// sub_11E66C @ 0x11e66c, size 104 bytes
void sub_11E66C()
{
  unsigned int *v0; // r6
  unsigned int v1; // r4
  __int16 **v2; // r8
  int v3; // r5
  void *v4; // r7
  int v5; // r10
  int v6; // r9
  int v7; // r4
  void (__fastcall *v8)(_DWORD); // r3

  v0 = (unsigned int *)off_11E6D4;
  v1 = *(_DWORD *)off_11E6D4;
  if ( *(_DWORD *)off_11E6D4 )
  {
    v2 = (__int16 **)off_11E6E0;
    v3 = dword_11E6D8;
    v4 = off_11E6DC;
    v5 = dword_11E6E4;
    v6 = dword_11E6E8;
    while ( 1 )
    {
      v7 = __clz(v1);
      if ( **v2 < 0 )
      {
        if ( v7 <= 23 )
        {
          v8 = *(void (__fastcall **)(_DWORD))(v3 + 8 * v7);
          if ( v8 )
            goto LABEL_5;
        }
        sub_1219C4(v6, v5, 230);
      }
      v8 = *(void (__fastcall **)(_DWORD))(v3 + 8 * v7);
LABEL_5:
      v8(*(_DWORD *)(v3 + 8 * v7 + 4));
      v1 = *v0;
      if ( *(_BYTE *)(*(_DWORD *)v4 + 3) )
      {
        sub_1138D0();
        if ( !v1 )
          return;
      }
      else if ( !v1 )
      {
        return;
      }
    }
  }
}

