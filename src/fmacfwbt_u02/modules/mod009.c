// read_hw_status_1 @ 0x114af0
void read_hw_status_1() {
  int v0; // r3
  volatile uint32_t *v1; // r7
  volatile int *v2; // r4
  void ( **v3)(int, int); // r6
  int v4; // r5
  int v5; // r3
  volatile uint32_t *v6; // r2
  volatile uint32_t *v7; // r1
  volatile int *v8; // r4
  void ( **v9)(int, int); // r5
  volatile uint8_t *v10; // r2
  volatile uint8_t *v11; // r1
  volatile uint8_t *v12; // r3
  int v13; // r2

  v0 = *(volatile uint32_t *)off_114C50;
  if ( (*(volatile uint32_t *)off_114C50 & 0x10000) != 0 )
  {
    v8 = **(volatile int ***)off_114C70;
    *(volatile uint32_t *)off_114C54 = 0x10000;
    if ( v8 )
    {
      v9 = (void ( **)(int, int))off_114C74;
      while ( !*((volatile uint8_t *)v8 + 4) )
      {
        if ( *v9 )
          (*v9)(v8[3], v8[2]);
        v8 = (volatile int *)*v8;
        if ( !v8 )
          goto LABEL_35;
      }
      if ( **(volatile int16_t **)off_114C78 < 0 )
        mmio_irq_clear(dword_114C80, dword_114C7C, 209);
    }
    else
    {
LABEL_35:
      if ( !*(volatile uint8_t *)off_114C8C )
        *(volatile uint32_t *)off_114C6C = 0x20000;
    }
  }
  else if ( (v0 & 0x20000) != 0 )
  {
    v1 = (void *)(uintptr_t)(off_114C58);
    v2 = *(volatile int **)off_114C58;
    *(volatile uint32_t *)off_114C54 = 0x20000;
    if ( v2 )
    {
      v3 = (void ( **)(int, int))off_114C5C;
      v4 = dword_114C60;
LABEL_8:
      while ( 2 )
      {
        if ( *((volatile uint8_t *)v2 + 4) )
        {
          if ( **(volatile int16_t **)off_114C78 < 0 )
            mmio_irq_clear(dword_114C80, dword_114C90, 316);
        }
        else
        {
          if ( *v3 )
            (*v3)(v2[3], v2[2]);
          v5 = dword_114C64;
          while ( !*(volatile uint8_t *)(v5 + 16) || v2 != (volatile int *)v5 )
          {
            v5 += 20;
            if ( v5 == v4 )
            {
              v2 = (volatile int *)*v2;
              if ( v2 )
                goto LABEL_8;
              goto LABEL_16;
            }
          }
          *((volatile uint8_t *)v2 + 16) = 0;
          v2 = (volatile int *)*v2;
          if ( v2 )
            continue;
        }
        break;
      }
    }
LABEL_16:
    v6 = (void *)(uintptr_t)(off_114C68);
    if ( *(volatile uint32_t *)off_114C68 )
    {
      v7 = (void *)(uintptr_t)(off_114C6C);
      *v1 = *(volatile uint32_t *)off_114C68;
      *v6 = 0;
      *v7 = 0x10000;
    }
    else
    {
      v10 = (void *)(uintptr_t)(off_114C84);
      *v1 = 0;
      if ( *v10 )
      {
        v11 = (void *)(uintptr_t)(off_114C88);
        *v10 = 0;
        if ( *v11 )
          *v11 = 0;
      }
    }
  }
  else if ( (v0 & 0x40000) != 0 )
  {
    *(volatile uint32_t *)off_114C54 = 0x40000;
  }
  else if ( (v0 & 0x80000) != 0 )
  {
    *(volatile uint32_t *)off_114C54 = 0x80000;
  }
  else if ( (v0 & 0x400000) != 0 )
  {
    *(volatile uint32_t *)off_114C54 = 0x400000;
  }
  else
  {
    if ( (v0 & 0x4000000) != 0 )
    {
      *(volatile uint32_t *)off_114C54 = 0x4000000;
      task_poll_loop(v0 << 12, v0 << 9);
    }
    if ( (v0 & 0x8000000) != 0 )
    {
      v12 = (void *)(uintptr_t)(off_114C94);
      v13 = *((volatile uint8_t *)off_114C94 + 15);
      *(volatile uint32_t *)off_114C54 = 0x8000000;
      if ( v13 )
      {
        ll_state_error_check();
      }
      else if ( v12[14] == 1 )
      {
        rx_descriptor_reset();
      }
    }
  }
}



// command_enqueue @ 0x114c98
int command_enqueue(int a1, int a2, int a3, int a4, char a5) {
  volatile uint8_t *v5; // r8
  volatile uint32_t *v8; // r7
  volatile int *v9; // r2
  volatile char *v10; // r3
  volatile unsigned int *v11; // r2
  volatile uint32_t *v12; // r6
  volatile uint32_t *v13; // r5
  volatile uint32_t *v14; // r4
  unsigned int v16; // r3
  unsigned int v17; // r1
  unsigned int v18; // r1
  volatile uint8_t *v19; // r3
  volatile uint32_t *v20; // r4
  volatile uint32_t *v21; // r3
  volatile uint8_t *v22; // r2

  if ( a1 )
    return 1;
  if ( a2 )
    return 2;
  v5 = (void *)(uintptr_t)(off_114DB8);
  if ( *(volatile uint8_t *)off_114DB8 )
  {
    v8 = (void *)(uintptr_t)(off_114D74);
  }
  else
  {
    v21 = (void *)(uintptr_t)(off_114D98);
    v8 = (void *)(uintptr_t)(off_114D74);
    *(volatile uint32_t *)off_114DA8 = off_114D74;
    *v21 = 196608;
    ke_event_schedule_1("SetVector irq = %d\n", 38);
    v22 = (void *)(uintptr_t)(off_114DA4);
    *(volatile uint32_t *)(*((volatile uint32_t *)off_114DB0 + 2) + 216) = off_114DB4;
    v22[806] = -4;
    *v5 = 1;
  }
  *(volatile uint32_t *)off_114D78 = 196608;
  ke_event_schedule_1("enable irq = %d\n", 38);
  v9 = (volatile int *)off_114D84;
  *(volatile uint32_t *)off_114D80 = a3;
  v10 = (volatile char *)off_114D88;
  *v9 = a4;
  v11 = (volatile unsigned int *)off_114D8C;
  *v10 = a5;
  v12 = (void *)(uintptr_t)(off_114D94);
  v13 = (void *)(uintptr_t)(off_114D98);
  v14 = (void *)(uintptr_t)(off_114D9C);
  v16 = *v11 & 0xFFFFFFFC;
  *(volatile uint32_t *)off_114D90 = 0;
  *v8 = 0;
  *v11 = v16;
  v17 = *v11;
  v12[3] = 0;
  *v11 = v17 & 0xFFFFFFF3;
  *v13 = 4980736;
  *v14 = 0x10000;
  *v13 = 0x4000000;
  *v14 = 0x4000000;
  v18 = *v11;
  v19 = (void *)(uintptr_t)(off_114DA0);
  v20 = (void *)(uintptr_t)(off_114DA4);
  *((volatile uint8_t *)off_114DA0 + 16) = 0;
  *v11 = v18 & 0xFFCFFFFF;
  v19[36] = 0;
  v19[56] = 0;
  v19[76] = 0;
  v19[96] = 0;
  v19[116] = 0;
  v20[1] = 64;
  return 0;
}


// sys_control @ 0x114e60
int sys_control(int a1, int a2) {
  int v2; // r1
  int v3; // r4
  int v4; // r0
  volatile int *v5; // r4
  int v6; // r5
  volatile int *v7; // r2
  volatile int *v8; // r3
  volatile uint8_t *v9; // r2
  int v10; // r0
  volatile uint32_t *v12; // r3

  if ( !*(volatile uint8_t *)off_114E40 )
    return 3;
  v2 = dword_114E48;
  *(volatile uint32_t *)off_114E44 = 0x20000;
  v3 = v2 + 120;
  while ( 1 )
  {
    v4 = *(volatile uint8_t *)(v2 + 16);
    if ( !*(volatile uint8_t *)(v2 + 16) )
      break;
    v2 += 20;
    if ( v2 == v3 )
      return -1;
  }
  v5 = (volatile int *)off_114E4C;
  *(volatile uint32_t *)v2 = v4;
  v6 = *v5;
  *(volatile uint8_t *)(v2 + 4) = v4;
  *(volatile uint32_t *)(v2 + 8) = a2;
  *(volatile uint32_t *)(v2 + 12) = a1;
  *(volatile uint8_t *)(v2 + 16) = 1;
  if ( v6 )
  {
    v7 = (volatile int *)off_114E50;
    v8 = *(volatile int **)off_114E50;
    if ( *(volatile uint32_t *)off_114E50 )
    {
      do
      {
        v7 = v8;
        v8 = (volatile int *)*v8;
      }
      while ( v8 );
    }
    *v7 = v2;
  }
  else
  {
    v12 = (void *)(uintptr_t)(off_114E5C);
    *v5 = v2;
    *v12 = 0x10000;
  }
  if ( *(volatile uint8_t *)off_114E54 != 1 )
  {
    v9 = (void *)(uintptr_t)(off_114E58);
    v10 = *(volatile uint8_t *)off_114E58;
    *(volatile uint8_t *)off_114E54 = 1;
    if ( v10 != 1 )
      *v9 = 1;
  }
  return 0;
}



// periph_write @ 0x114e6c
int periph_write(int result) {
  if ( !result )
    *(volatile uint32_t *)off_114E78 = 0x20000;
  return result;
}



// call_vector_1fc @ 0x114e7c
int call_vector_1fc() {
  return ((int (*)())MEMD(0x1FC))();
}



// get_hw_info_bit9 @ 0x114e84
unsigned int get_hw_info_bit9() {
  return ((unsigned int)((int (*)())MEMD(0x1FC))(1) >> 9) & 1;
}



// get_hw_info_2 @ 0x114e98
int get_hw_info_2() {
  return ((int (*)())MEMD(0x1FC))(2);
}



// syscall6_get_status @ 0x114ea4
int syscall6_get_status(volatile uint8_t *a1) {
  int16_t v2; // r0

  v2 = ((int (*)())MEMD(0x1FC))(6);
  if ( (v2 & 0xFF00) != 0 )
  {
    *a1 = HIBYTE(v2);
    return 0;
  }
  else
  {
    *a1 = v2;
    if ( (uint8_t)v2 )
      return 1;
    else
      return 2;
  }
}



// syscall6_check_done @ 0x114ed0
int syscall6_check_done(volatile uint8_t *a1) {
  unsigned int v2; // r0
  char v4; // r3

  v2 = ((int (*)())MEMD(0x1FC))(6);
  if ( HIBYTE(v2) )
  {
    *a1 = HIBYTE(v2);
    return 0;
  }
  else
  {
    v4 = BYTE2(v2);
    if ( !HIWORD(v2) )
      v4 = 0;
    *a1 = v4;
    if ( HIWORD(v2) )
      return 1;
    else
      return 2;
  }
}



// syscall8_op @ 0x114f00
int syscall8_op(volatile uint32_t *a1, volatile unsigned int *a2) {
  unsigned int v4; // r4
  unsigned int v5; // r0
  unsigned int v6; // r4
  int v7; // r4
  uint16_t v8; // r0
  unsigned int v9; // r3
  int result; // r0

  v4 = ((int (*)())MEMD(0x1FC))(8);
  v5 = ((int (*)())MEMD(0x1FC))(9);
  v6 = HIWORD(v4) << 16;
  if ( v6 | v5 )
  {
    *a1 = (v5 << 16) | HIWORD(v6);
    *a2 = HIWORD(v5);
    return 0;
  }
  else
  {
    v7 = ((int (*)())MEMD(0x1FC))(7);
    v8 = ((int (*)())MEMD(0x1FC))(8);
    v9 = v8;
    if ( v7 )
    {
      *a1 = v7;
      *a2 = v8;
      return 1;
    }
    else
    {
      *a1 = 0;
      if ( v8 )
        result = 1;
      else
        result = 2;
      *a2 = v9;
    }
  }
  return result;
}



// load_calib_data @ 0x114f5c
int load_calib_data(int a1, int a2) {
  int v3; // r1
  int v4; // r2
  unsigned int v5; // r0
  int v6; // r3
  int v7; // r1
  unsigned int v8; // r2
  char v9; // r5
  unsigned int v10; // r4
  char v11; // r2
  volatile uint8_t *v12; // r2
  uint32_t v14[3]; // [sp+4h] [bp-10h]

  v3 = *(volatile uint32_t *)(dword_114FD4 + 4);
  v4 = *(volatile uint32_t *)(dword_114FD4 + 8);
  v14[0] = *(volatile uint32_t *)dword_114FD4;
  v14[1] = v3;
  v14[2] = v4;
  v5 = ((int (*)())MEMD(0x1FC))(v14[a1]);
  v6 = 0;
  v7 = 0;
  do
  {
    v8 = v5 >> (8 * v6);
    v9 = v8;
    v10 = (uint8_t)v8 >> 4;
    if ( (v8 & 0xF0) == 0 )
    {
      if ( !(uint8_t)v8 )
      {
        v7 |= 2 << (4 * v6);
        v12 = (volatile uint8_t *)(a2 + v6);
        goto LABEL_9;
      }
      v7 |= 1 << (4 * v6);
      v10 = (uint8_t)v8;
    }
    if ( (v10 & 1) != 0 )
      v11 = -1;
    else
      v11 = 1;
    v9 = (v10 >> 1) * v11;
    v12 = (volatile uint8_t *)(a2 + v6);
LABEL_9:
    ++v6;
    *v12 = v9;
  }
  while ( v6 != 3 );
  return v7;
}



// load_calib_data2 @ 0x114fd8
int load_calib_data2(int a1, int a2) {
  int v3; // r1
  int v4; // r2
  int v5; // r7
  unsigned int v6; // r4
  int v7; // r0
  int v8; // r2
  int result; // r0
  unsigned int v10; // r4
  int v11; // zf
  int v12; // r3
  unsigned int v13; // r4
  unsigned int v14; // r5
  volatile uint8_t *v15; // r4
  struct __attribute__((packed)) { int v16; // [sp+4h] [bp-18h]
  int v17; // [sp+8h] [bp-14h]
  uint32_t v18[4]; // [sp+Ch] [bp-10h] BYREF
  } _frame;
  v3 = ((volatile uint32_t *)(uintptr_t)off_115074)[1];
  v4 = ((volatile uint32_t *)(uintptr_t)off_115074)[2];
  _frame.v18[0] = ((volatile uint32_t *)(uintptr_t)off_115074)[0];
  _frame.v18[1] = v3;
  _frame.v18[2] = v4;
  v5 = _frame.v18[a1];
  _frame.v16 = ((int (*)())MEMD(0x1FC))(v5);
  v6 = _frame.v16;
  v7 = ((int (*)())MEMD(0x1FC))(v5 + 1);
  v8 = 0;
  _frame.v17 = v7;
  result = 0;
  while ( 1 )
  {
    v12 = v6 >> (8 * (v8 & 3));
    v14 = (uint8_t)v12;
    v10 = (uint8_t)v12 >> 4;
    if ( (v12 & 0xF0) == 0 )
    {
      v12 = 1 << (4 * v8);
      if ( !v14 )
      {
        result |= 2 << (4 * v8);
        v15 = (volatile uint8_t *)(a2 + v8);
        goto LABEL_8;
      }
      result |= v12;
      v10 = v14;
    }
    v11 = (v10 & 1) == 0;
    if ( (v10 & 1) != 0 )
      v12 = (v12 & ~0xFFu) | ((uint8_t)(-1) & 0xFFu);
    v13 = v10 >> 1;
    if ( v11 )
      v12 = (v12 & ~0xFFu) | ((uint8_t)(1) & 0xFFu);
    v14 = (v14 & ~0xFFu) | ((uint8_t)(v13 * v12) & 0xFFu);
    v15 = (volatile uint8_t *)(a2 + v8);
LABEL_8:
    ++v8;
    *v15 = v14;
    if ( v8 == 6 )
      return result;
    v6 = *(volatile uint32_t *)((volatile char *)&_frame.v18[-2] + (v8 & 0xFFFFFFFC));
  }
}


// syscall10_flash_erase @ 0x115078
int syscall10_flash_erase(char a1, volatile uint8_t *a2) {
  unsigned int v3; // r0
  unsigned int v4; // r3
  int result; // r0
  char v6; // r2

  v3 = (unsigned int)((int (*)())MEMD(0x1FC))(10) >> (8 * a1);
  v4 = (uint8_t)v3 >> 4;
  if ( (v3 & 0xF0) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !(uint8_t)v3 )
    {
      *a2 = 0;
      return 2;
    }
    v4 = (uint8_t)v3;
    result = 1;
  }
  if ( (v4 & 1) != 0 )
    v6 = -1;
  else
    v6 = 1;
  *a2 = (v4 >> 1) * v6;
  return result;
}



// syscall11_flash_write @ 0x1150c0
int syscall11_flash_write(char a1, volatile uint8_t *a2) {
  unsigned int v3; // r0
  unsigned int v4; // r3
  int result; // r0
  char v6; // r2

  v3 = (unsigned int)((int (*)())MEMD(0x1FC))(11) >> (8 * a1);
  v4 = (uint8_t)v3 >> 4;
  if ( (v3 & 0xF0) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !(uint8_t)v3 )
    {
      *a2 = 0;
      return 2;
    }
    v4 = (uint8_t)v3;
    result = 1;
  }
  if ( (v4 & 1) != 0 )
    v6 = -1;
  else
    v6 = 1;
  *a2 = (v4 >> 1) * v6;
  return result;
}



// syscall16_get_version @ 0x115108
int syscall16_get_version(volatile int *a1) {
  uint8_t v2; // r0
  int v3; // r2
  int result; // r0
  int v5; // r3

  v2 = ((int (*)())MEMD(0x1FC))(16);
  v3 = v2 >> 4;
  if ( (v2 & 0xF0) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !v2 )
    {
      *a1 = 0;
      return 2;
    }
    v3 = v2;
    result = 1;
  }
  if ( (v3 & 8) != 0 )
    v5 = v3 & 7;
  else
    v5 = -v3;
  if ( (v3 & 8) != 0 )
    ++v5;
  *a1 = v5;
  return result;
}



// get_hw_info_field0 @ 0x115144
int get_hw_info_field0() {
  return ((int (*)())MEMD(0x1FC))(17) & 7;
}



// get_hw_info_field1 @ 0x115158
unsigned int get_hw_info_field1() {
  return ((unsigned int)((int (*)())MEMD(0x1FC))(17) >> 3) & 7;
}



// get_hw_info_field2 @ 0x11516c
unsigned int get_hw_info_field2() {
  return ((unsigned int)((int (*)())MEMD(0x1FC))(17) >> 6) & 7;
}



// rom_call_extract_byte @ 0x115180
int rom_call_extract_byte(volatile uint8_t *a1) {
  int16_t v2; // r0

  v2 = ((int (*)())MEMD(0x1FC))(15);
  if ( (v2 & 0xFF00) != 0 )
  {
    *a1 = HIBYTE(v2);
    return 0;
  }
  else
  {
    *a1 = v2;
    if ( (uint8_t)v2 )
      return 1;
    else
      return 2;
  }
}



// get_hw_info_bit18 @ 0x1151ac
unsigned int get_hw_info_bit18() {
  return ((unsigned int)((int (*)())MEMD(0x1FC))(15) >> 18) & 1;
}



// get_hw_info_bit19 @ 0x1151c0
unsigned int get_hw_info_bit19() {
  return ((unsigned int)((int (*)())MEMD(0x1FC))(15) >> 19) & 1;
}



// get_hw_info_bit20 @ 0x1151d4
unsigned int get_hw_info_bit20() {
  return ((unsigned int)((int (*)())MEMD(0x1FC))(15) >> 20) & 1;
}



// get_hw_info_1b @ 0x1151e8
int get_hw_info_1b() {
  return ((int (*)())MEMD(0x1FC))(27);
}



// enter_critical_set_flag @ 0x1151f4
int enter_critical_set_flag() {
  volatile int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11522C = 1;
  }
  v0 = (volatile int *)off_115230;
  ++*(volatile uint32_t *)off_115230;
  result = ((int (*)())MEMD(0x1C8))();
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(volatile uint32_t *)off_11522C;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}



// check_status_flags @ 0x115234
void check_status_flags() {
  volatile int *v0; // r4

  v0 = (volatile int *)off_115260;
  if ( !*(volatile uint32_t *)off_115260 )
    *v0 = enter_critical_set_flag();
  if ( !*(volatile uint32_t *)off_115264 )
    *(volatile uint32_t *)off_115264 = *v0 + 67092480;
  *(volatile uint32_t *)off_115268 = 1;
}



