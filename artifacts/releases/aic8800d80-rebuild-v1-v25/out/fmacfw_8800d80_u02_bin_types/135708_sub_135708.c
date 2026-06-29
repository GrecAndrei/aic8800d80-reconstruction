// sub_135708 @ 0x135708, size 316 bytes
// Doc: sub_1235708 [mac]: Accesses entry in indexed table (0x528 stride) by ID
// sub_1235708 [mac]: Accesses entry in indexed table (0x528 stride) by ID
int  sub_135708(int result)
{
  int v1; // r4
  int v2; // r2
  int v3; // r3
  int v4; // r5
  int v5; // r2
  int v6; // r6
  __int16 v7; // r8
  int v8; // r7
  __int16 v9; // r3
  uint16_t *v10; // r12
  int v11; // r3
  __int16 v12; // r1
  int v13; // r2
  int v14; // r0
  __int16 v15; // r6
  int v16; // r4
  int v17; // r4
  int v18; // r3
  int v19; // r2
  int v20; // r1
  uint64_t v21; // r2
  int v22; // [sp+4h] [bp-10h] BYREF
  int v23; // [sp+8h] [bp-Ch]
  __int16 v24; // [sp+Ch] [bp-8h]

  v1 = dword_135844 + 1320 * *(unsigned __int8 *)(result + 8);
  v2 = *(unsigned __int8 *)(v1 + 108);
  v22 = 0;
  v23 = 0;
  v24 = 0;
  if ( v2 )
  {
    if ( !*(uint8_t *)(v1 + 106) )
    {
      v3 = *(unsigned __int8 *)(result + 7);
      v4 = result;
      if ( v3 != 255 )
      {
        v5 = *(unsigned __int8 *)(v1 + 116);
        if ( v5 == v3 )
        {
          v6 = dword_135848 + 696 * v5;
          if ( *(uint8_t *)(v6 + 52) == 2 && !*(uint8_t *)(result + 13) )
          {
            v7 = *(uint16_t *)(result + 14);
            result = sub_118C44(*(unsigned __int8 *)(result + 6) != 0, 512);
            v8 = result;
            if ( result )
            {
              v9 = *(uint16_t *)(v4 + 4);
              LOBYTE(v22) = *(uint8_t *)(v4 + 6);
              LOWORD(v23) = v9;
              HIWORD(v22) = v9;
              sub_12C538(v1, result, (unsigned __int8 *)&v22);
              v10 = off_13584C;
              v11 = *(uint32_t *)(v8 + 72);
              v12 = *((uint16_t *)off_13584C + 254);
              v13 = v6 + 38;
              *(uint32_t *)(v11 + 112) = *(uint32_t *)(v6 + 38);
              *(uint8_t *)(v11 + 108) = -48;
              *(uint16_t *)(v11 + 116) = *(uint16_t *)(v6 + 42);
              ++v12;
              v14 = *(uint32_t *)(v1 + 100);
              v15 = *(uint16_t *)(v1 + 104);
              v16 = *(uint32_t *)v13;
              *(uint32_t *)(v11 + 118) = v14;
              LOWORD(v14) = *(uint16_t *)(v13 + 4);
              *(uint8_t *)(v11 + 109) = 0;
              *(uint8_t *)(v11 + 110) = 0;
              *(uint8_t *)(v11 + 111) = 0;
              *(uint16_t *)(v11 + 122) = v15;
              *(uint32_t *)(v11 + 124) = v16;
              *(uint16_t *)(v11 + 128) = v14;
              v10[254] = v12;
              *(uint16_t *)(v11 + 130) = 16 * v12;
              *(uint8_t *)(v8 + 28) = *(uint8_t *)(v4 + 8);
              *(uint8_t *)(v8 + 29) = *(uint8_t *)(v4 + 7);
              v17 = v11 + 108;
              *(uint8_t *)(v8 + 51) = 0;
              *(uint8_t *)(v8 + 53) = 0;
              rf_msg_process_body_n37(v8, 208, 8);
              fmac_main_loop_0a0(v8, v17, 24);
              v18 = *(unsigned __int8 *)(v8 + 51) + 24;
              v19 = v18 + v17;
              *(uint8_t *)(v18 + v17) = 8;
              *(uint8_t *)(v19 + 1) = 1;
              v20 = *(uint32_t *)(v8 + 76);
              *(uint16_t *)(v19 + 2) = v7;
              HIDWORD(v21) = v18 + *(unsigned __int8 *)(v8 + 53) + 4;
              LODWORD(v21) = *(uint32_t *)(v20 + 28) - 1 + HIDWORD(v21);
              HIDWORD(v21) += 4;
              *(QWORD *)(v20 + 32) = v21;
              return rf_param_get_status(v8, 5);
            }
          }
        }
      }
    }
  }
  return result;
}

