// sub_11482C @ 0x11482c, size 70 bytes
int  sub_11482C(int a1)
{
  int *v1; // r4
  int result; // r0
  int v3; // r2
  int v4; // r5
  int v5; // r1
  int v6; // r2
  int v7; // r0
  int v8; // r1
  int v9; // r0

  v1 = (int *)off_114874;
  result = j_buffer_pool_get(a1 - 16);
  v3 = *v1;
  if ( *v1 )
  {
    v4 = v3 + 4;
    v5 = sub_114790((unsigned __int8 *)(v3 + 4));
    if ( v5 < 0 )
    {
      v8 = *(unsigned __int8 *)(v6 + 4);
      v9 = dword_11487C;
      return sub_12ECB0(v9, v8, v6);
    }
    v7 = sub_114E60(v4, v5);
    if ( v7 )
    {
      v8 = v7;
      v9 = dword_114878;
      return sub_12ECB0(v9, v8, v6);
    }
    return sub_12D4F8(v1);
  }
  return result;
}

