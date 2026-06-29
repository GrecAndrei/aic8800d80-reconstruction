// fwstruct annotate: 1306c0_mac_frame_hdr_init.c
// mac_frame_hdr_init @ 0x1306c0, size 204 bytes
// Doc: mac_frame_hdr_init [mac]: Initializes MAC frame header with type/length bytes
// mac_frame_hdr_init [mac]: Initializes MAC frame header with type/length bytes
char *__fastcall mac_frame_hdr_init(int a1)
{
  int v1; // r2
  _WORD *v2; // r5
  _BYTE *v4; // r3
  int v5; // r0
  char v6; // t1
  int v7; // r2
  int v8; // r4
  int v9; // r0
  int v10; // r3
  char v11; // t1
  int v12; // r3
  __int16 v13; // r2
  _WORD *v14; // r7
  __int16 v15; // r1
  __int16 v16; // r3
  char *result; // r0
  int v18; // r0
  int v19; // r3
  int v20; // r1
  int v21; // r2
  int v22; // r3
  char v23; // t1

  v1 = dword_13078C;
  **(_BYTE **)a1 = -1;
  *(_BYTE *)(*(_DWORD *)a1 + 2) = 35;
  v2 = *(_WORD **)a1;
  v4 = (_BYTE *)(*(_DWORD *)a1 + 3);
  v5 = *(_DWORD *)a1 + 9;
  do
  {
    v6 = *(_BYTE *)++v1;
    *v4++ = v6;
  }
  while ( v4 != (_BYTE *)v5 );
  v7 = dword_130790;
  v8 = dword_130790 - 65;
  v9 = dword_130790 + 11;
  do
  {
    v10 = v7 - 56;
    v11 = *(_BYTE *)++v7;
    *((_BYTE *)v2 + v10 - v8) = v11;
  }
  while ( v7 != v9 );
  v12 = *(unsigned __int8 *)(v8 + 0x42);
  v13 = *(_WORD *)(v8 + 0x4E);
  v2[11] = *(_WORD *)(v8 + 0x50);
  v2[10] = v13;
  v14 = v2 + 12;
  if ( (v12 & 8) != 0 )
  {
    v15 = *(_WORD *)(v8 + 0x52);
    v2[13] = *(_WORD *)(v8 + 0x54);
    v2[12] = v15;
    v14 = v2 + 14;
  }
  if ( ((v12 >> 1) & 8) != 0 )
  {
    v16 = *(_WORD *)(v8 + 0x56);
    *v14 = v16;
    v14[1] = v16;
    v14 += 2;
  }
  if ( *(unsigned __int8 *)(v8 + 0x48) >> 7 )
  {
    v18 = sub_1325CC();
    v19 = v18 + 1 + *(unsigned __int8 *)(v8 + 0x175) * (v18 + 1);
    v20 = (unsigned __int8)((unsigned int)(6 * v19 + 14) >> 3);
    if ( (unsigned __int8)((unsigned int)(6 * v19 + 14) >> 3) )
    {
      v21 = dword_130794;
      do
      {
        v22 = v21 - 89;
        v23 = *(_BYTE *)++v21;
        *((_BYTE *)v14 + v22 - v8) = v23;
      }
      while ( v8 + 89 + v20 != v21 );
      v14 = (_WORD *)((char *)v14 + v20);
    }
  }
  result = (char *)v14 - *(_DWORD *)a1;
  *(_BYTE *)(*(_DWORD *)a1 + 1) = (_BYTE)result - 2;
  *(_DWORD *)a1 += result;
  return result;
}

