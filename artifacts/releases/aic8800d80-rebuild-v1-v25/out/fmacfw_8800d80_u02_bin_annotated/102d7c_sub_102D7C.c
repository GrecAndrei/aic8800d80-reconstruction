// fwstruct annotate: 102d7c_sub_102D7C.c
// sub_102D7C @ 0x102d7c, size 282 bytes
int __fastcall sub_102D7C(int a1, unsigned __int16 *a2)
{
  unsigned int v4; // r11
  int v5; // r9
  int v6; // r8
  int v7; // r10
  int *v8; // r6
  int v9; // r5
  unsigned __int16 *v10; // r7
  int v11; // r4
  int v12; // t1
  int v13; // r1
  int result; // r0
  int v15; // r4
  __int16 v16; // r12
  char *v17; // r7
  int v18; // r6
  char *v19; // r12
  int v20; // r3
  unsigned __int16 *v21; // r1
  int v22; // t1
  int v23; // [sp+8h] [bp-24h]
  unsigned __int16 *v24; // [sp+Ch] [bp-20h]
  __int64 v25; // [sp+14h] [bp-18h] BYREF
  int v26; // [sp+1Ch] [bp-10h]

  while ( !*(_DWORD *)off_102E98 )
    ;
  v4 = 0;
  sub_102CA8(0);
  v5 = dword_102EB4;
  v6 = dword_102EA8;
  v23 = 0;
  v24 = a2;
  v7 = a1;
  while ( ((1 << v4) & v7) == 0 )
  {
    if ( (unsigned __int16)v4 == 5 )
      goto LABEL_10;
LABEL_4:
    ++v4;
  }
  v8 = (int *)(dword_102E9C + (v4 << 9));
  v9 = 0;
  v10 = v24 - 1;
  do
  {
    v11 = *v8;
    sub_12ECD0(0x2000, v5);
    v12 = v10[1];
    ++v10;
    v13 = dword_102EA0;
    *v8 = v11 & v6 | (v12 << 11);
    v8 += 8;
    ++v9;
    sub_12ECD0(0x2000, v13);
  }
  while ( v9 != 16 );
  if ( v4 <= 1 )
    goto LABEL_4;
  v23 = 1;
  if ( (unsigned __int16)v4 != 5 )
    goto LABEL_4;
LABEL_10:
  result = sub_102D0C(0);
  *(_DWORD *)off_102E98 = 1;
  if ( v23 )
  {
    v15 = *(_DWORD *)off_102EA4;
    v25 = *(_QWORD *)off_102EA4;
    v26 = *((_DWORD *)off_102EA4 + 2);
    v16 = 3;
  }
  else
  {
    v15 = qword_102EAC;
    v26 = 0;
    HIDWORD(v25) = HIDWORD(qword_102EAC);
    v16 = 2;
  }
  v17 = (char *)&v25 + 4;
  v18 = dword_102EA8;
  v19 = (char *)&v25 + 4 * (unsigned __int16)(v16 - 1) + 4;
  while ( 1 )
  {
    v20 = v15;
    v21 = v24;
    do
    {
      if ( v15 )
      {
        result = *v21;
        *(_DWORD *)(v20 + 16) = *(_DWORD *)(v20 + 16) & v18 | (result << 11);
      }
      v20 += 20;
      ++v21;
    }
    while ( v15 + 320 != v20 );
    if ( v19 == v17 )
      break;
    v22 = *(_DWORD *)v17;
    v17 += 4;
    v15 = v22;
  }
  return result;
}

