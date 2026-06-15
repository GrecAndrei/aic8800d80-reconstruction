// v23 annotated: sub_11C320 @ 0x11c320
// Original: 11c320_sub_11C320.c
// Primary struct: <unclustered>
//
// sub_11C320 @ 0x11c320, size 174 bytes
// Doc: sub_121C320 [util]: Initialization/utility routine loading global state at 0x188bbc
// sub_121C320 [util]: Initialization/utility routine loading global state at 0x188bbc
int sub_11C320()
{
  _DWORD *v0; // r4
  int v1; // r6
  int v2; // r7
  int v3; // r5
  char v4; // r8
  char *v5; // r3
  _DWORD *v6; // r2
  int result; // r0
  char v8; // r1
  int v9; // r3
  int v10; // r1
  void *v11; // r0
  _DWORD v12[28]; // [sp+0h] [bp-90h] BYREF
  char v13; // [sp+70h] [bp-20h] BYREF

  v0 = off_11C3D0;
  v1 = *((_DWORD *)off_11C3D0 + 1);
  if ( v1 )
  {
    v2 = *((_DWORD *)off_11C3D0 + 2);
    timestamp_remove_058(off_11C3D0);
    v3 = v0[4];
    if ( v3 )
      goto LABEL_3;
  }
  else
  {
    v3 = *((_DWORD *)off_11C3D0 + 4);
    v2 = 0;
    if ( v3 )
    {
LABEL_3:
      sub_14380C(v12, dword_11C3D4, 144);
      v4 = *((_BYTE *)v0 + 160);
      if ( v12[1] )
        timestamp_remove_058(dword_11C3D4);
      if ( v12[8] )
        timestamp_remove_058(dword_11C3D8);
      if ( v12[15] )
        timestamp_remove_058(dword_11C3DC);
      if ( v12[22] )
        timestamp_remove_058(dword_11C3E0);
      sub_11C1C8();
      v0[4] = v3;
      *((_BYTE *)v0 + 160) = v4;
      v0 = off_11C3D0;
      v5 = (char *)v12;
      v6 = off_11C3D0;
      do
      {
        result = *((_DWORD *)v5 + 5);
        v8 = v5[24];
        v6[10] = result;
        v5 += 28;
        *((_BYTE *)v6 + 44) = v8;
        v6 += 7;
      }
      while ( &v13 != v5 );
      if ( v1 )
        goto LABEL_14;
      return result;
    }
  }
  result = sub_11C1C8();
  v0[4] = v3;
  if ( v1 )
  {
LABEL_14:
    v9 = dword_11C3E8;
    v10 = *((_DWORD *)off_11C3E4 + 4);
    v11 = off_11C3D0;
    v0[2] = v2;
    v0[1] = v9;
    return timestamp_update_4f60(v11, v10 + 5000);
  }
  return result;
}

