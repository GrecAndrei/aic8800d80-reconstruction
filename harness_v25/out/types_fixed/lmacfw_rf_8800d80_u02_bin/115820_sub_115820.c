// sub_115820 @ 0x115820, size 108 bytes
int sub_115820()
{
  int *v0; // r4
  int v1; // r0
  int v2; // r0
  int result; // r0

  v0 = (int *)off_11588C;
  v1 = sub_11522C();
  v2 = nullsub_4(v1);
  sub_115FBC(v2);
  sub_11639C(0);
  sub_100200(v0, 0, 0x94u);
  sub_11E71C(v0 + 3);
  *v0 = 0;
  *((_BYTE *)v0 + 26) = 0;
  sub_11E71C(v0 + 10);
  *(_DWORD *)(v0 + 0x1c) = 0;
  *((_BYTE *)v0 + 54) = 0;
  sub_11E71C(v0 + 17);
  *(_DWORD *)(v0 + 0x38) = 0;
  *((_BYTE *)v0 + 82) = 0;
  sub_11E71C(v0 + 24);
  *(_DWORD *)(v0 + 0x54) = 0;
  *((_BYTE *)v0 + 110) = 0;
  result = sub_11E71C(v0 + 31);
  *(_DWORD *)(v0 + 0x70) = 0;
  *((_BYTE *)v0 + 138) = 0;
  *((_WORD *)v0 + 70) = 0;
  return result;
}

