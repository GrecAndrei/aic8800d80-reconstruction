// sub_11BE18 @ 0x11be18, size 446 bytes
void sub_11BE18()
{
  uint32_t *v0; // r4
  int v1; // r3
  int v2; // r2
  uint8_t *v3; // r6
  int v4; // r0
  unsigned int v5; // lr
  char v6; // r1
  int v7; // r7
  uint32_t *v8; // r2
  int v9; // r12
  int v10; // r8
  __int16 v11; // r0
  int v12; // r1
  int v13; // r0
  uint32_t *v14; // lr
  uint32_t *v15; // r1
  uint32_t *v16; // r1
  uint32_t *v17; // r6
  int v18; // r5
  int v19; // r0
  uint32_t *v20; // r3
  uint32_t *v21; // r0
  int v22; // r0
  int *v23; // r7
  char *v24; // r2
  int v25; // r5
  int v26; // r6
  __int16 v27; // r12
  int v28; // r1
  int v29; // r0
  int v30; // r0
  int v31; // r1
  int v32; // r3
  uint32_t *v33; // r6
  uint32_t *v34; // r0
  int v35; // [sp+4h] [bp-4h] BYREF

  v0 = off_11BFD8;
  v1 = *((uint32_t *)off_11BFD8 + 52);
  v35 = 0;
  if ( (v1 & 4) != 0 )
  {
    *((uint32_t *)off_11BFD8 + 52) = v1 & 0xFFFFFFFB;
  }
  else
  {
    v2 = *((unsigned __int8 *)off_11BFD8 + 200);
    if ( *((uint8_t *)off_11BFD8 + 200) )
    {
      if ( *((uint8_t *)off_11BFD8 + 191) == 4 )
      {
        sub_11B9B8((int)off_11BFD8 + 168);
      }
      else
      {
        v3 = off_11BFDC;
        if ( *((uint8_t *)off_11BFDC + 1) )
        {
          v4 = *((uint32_t *)off_11BFD8 + 42);
          v5 = *((unsigned __int8 *)off_11BFDC + 2);
          v6 = *(uint8_t *)(v4 + 34);
          if ( ((v5 >> v6) & 1) != 0 )
          {
            v7 = *(unsigned __int16 *)(v4 + 32);
            v8 = off_11BFE0;
            *((uint32_t *)off_11BFE0 + 303) = *((uint32_t *)off_11BFD8 + 45);
            v9 = v0[4];
            v10 = v8[300] & 0xFF00;
            v11 = ~((unsigned int)~(v7 << 18) >> 18);
            LOBYTE(v7) = v5 & ~(unsigned __int8)(1 << v6);
            v12 = v0[46];
            *((uint16_t *)v8 + 605) = v11;
            *((uint16_t *)v8 + 608) = v12;
            v13 = *(uint32_t *)(v9 + 100);
            v14 = off_11BFE8;
            LOWORD(v9) = *(uint16_t *)(v9 + 104);
            v15 = off_11BFE4;
            *(uint32_t *)((char *)v8 + 1218) = v13;
            v0[52] = v1 | 2;
            *((uint16_t *)v8 + 611) = v9;
            v8[286] = 0;
            *((uint8_t *)v0 + 200) = 0;
            v8[300] = v10;
            v3[2] = v7;
            *v14 = v8 + 285;
            *v15 = 0x2000;
            return;
          }
        }
        if ( (v1 & 1) == 0 )
        {
          v21 = (uint32_t *)sub_11B680(&v35);
          if ( v21 )
          {
            mmio_rf_table_init(v21);
            v22 = v35;
            *(uint32_t *)off_11BFEC &= ~0x200u;
            bt_hci_cmd_send(v22);
            return;
          }
          v1 = v0[52];
        }
        v23 = (int *)dword_11BFF0;
        v24 = (char *)off_11BFE0;
        v25 = v0[4];
        v26 = *((uint32_t *)off_11BFE0 + 244);
        v27 = *(uint16_t *)(v25 + 104);
        v28 = *(uint32_t *)(dword_11BFF0 + 4);
        *((uint32_t *)off_11BFE0 + 248) = *(uint32_t *)dword_11BFF0;
        v29 = *(uint32_t *)(v25 + 100);
        *((uint16_t *)v24 + 498) = v28;
        *(uint32_t *)(v24 + 998) = v29;
        v30 = *v23;
        v31 = v23[1];
        v0[52] = v1 | 2;
        v32 = *((uint32_t *)v24 + 245);
        *((uint32_t *)v24 + 244) = v26 | 0x100;
        v33 = off_11BFE8;
        *((uint32_t *)v24 + 251) = v30;
        *((uint16_t *)v24 + 504) = v31;
        v34 = off_11BFE4;
        *(uint32_t *)(v24 + 1014) = v0[43];
        *((uint16_t *)v24 + 501) = v27;
        *((uint32_t *)v24 + 245) = v32 & 0xFF00;
        *v33 = v24 + 920;
        *((uint32_t *)v24 + 275) = 0;
        *((uint32_t *)v24 + 276) = 0;
        *((uint32_t *)v24 + 231) = 0;
        *((uint8_t *)v0 + 200) = 0;
        *v34 = 0x2000;
      }
    }
    else
    {
      v16 = off_11BFE0;
      v17 = off_11BFE8;
      v18 = *((uint32_t *)off_11BFE0 + 269);
      v19 = *((uint32_t *)off_11BFE0 + 270);
      *((uint8_t *)off_11BFD8 + 200) = v2;
      v0[52] = v1 | 2;
      v20 = off_11BFE4;
      v16[275] = v2;
      v16[276] = v2;
      v16[256] = v2;
      v16[269] = v18 | 0x100;
      v16[270] = v19 & 0xFF00;
      *v17 = v16 + 255;
      *v20 = 0x2000;
    }
  }
}

