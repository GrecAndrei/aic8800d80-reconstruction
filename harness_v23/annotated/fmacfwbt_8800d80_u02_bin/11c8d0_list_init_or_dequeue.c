// v23 annotated: list_init_or_dequeue @ 0x11c8d0
// Original: 11c8d0_list_init_or_dequeue.c
// Primary struct: <unclustered>
//
// list_init_or_dequeue @ 0x11c8d0, size 74 bytes
// Doc: list_init_or_dequeue [util]: Initialize/dequeue a list node using 0x188bbc and 0xfffff000 globals
// list_init_or_dequeue [util]: Initialize/dequeue a list node using 0x188bbc and 0xfffff000 globals
int __fastcall list_init_or_dequeue(int a1)
{
  _BYTE *v1; // r6
  int v2; // r7
  int v3; // r5
  int result; // r0
  _DWORD *v5; // r1
  _DWORD *v6; // r4
  unsigned int v7; // t1
  int v8; // r3

  v1 = off_11C91C;
  v2 = dword_11C920;
  v3 = *((_DWORD *)off_11C91C + 4);
  result = a1 - 4;
  v5 = off_11C91C;
  v6 = (_DWORD *)(v3 + 8);
  do
  {
    v7 = *(_DWORD *)(result + 4);
    result += 4;
    v8 = (v7 >> 4) & 0xFF0 | v7 & 0xF;
    v5[10] = v8;
    *((_BYTE *)v5 + 44) = BYTE2(v7);
    if ( v3 )
      v5[10] = v8 | *v6 & v2;
    ++v6;
    v5 += 7;
  }
  while ( (_DWORD *)(v3 + 24) != v6 );
  v1[160] = 1;
  return result;
}

