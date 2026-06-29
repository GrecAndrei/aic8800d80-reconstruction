// fwstruct annotate: 111270_log_enqueue.c
// log_enqueue @ 0x111270, size 118 bytes
// Doc: log_enqueue [util]: Enqueue a log entry with arg=4, saves r0/r1/r2 and calls allocator
// log_enqueue [util]: Enqueue a log entry with arg=4, saves r0/r1/r2 and calls allocator
int __fastcall log_enqueue(char a1, int a2, int a3)
{
  _DWORD *v6; // r0
  _DWORD *v7; // r4
  _DWORD *v8; // r6
  int v9; // r2
  int v10; // r3

  v6 = log_alloc(4);
  if ( !v6 )
    return sub_10DC24(dword_1112F0);
  v7 = v6;
  v8 = (_DWORD *)sub_1102BC();
  if ( v8 )
  {
    *(_BYTE *)v7 = a3;
    *((_BYTE *)v7 + 1) = BYTE1(a3) & 0xF;
    *((_BYTE *)v7 + 2) = a1;
    *((_BYTE *)v7 + 3) = 0;
    sub_143770(v7 + 1, a2, a3);
    v9 = v8[2];
    v10 = dword_1112E8;
    v8[1] = 0;
    *v8 = v7;
    v8[2] = (unsigned __int16)(a3 + 4) | v10 & v9 | 0x80000000;
    return sub_11115C((int)v8);
  }
  else
  {
    sub_10DC24(dword_1112EC);
    return log_free_dispatch_2(v7);
  }
}

