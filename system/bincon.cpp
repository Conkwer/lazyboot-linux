


//$ bincon.exe decompiled

//Usage: bincon <0WINCEOS.BIN file> <new 1ST_READ.BIN to create> <IP.BIN filename>
//Example: bincon 0WINCEOS.BIN 1ST_READ.BIN IP.BIN

int32_t sub_401000(int32_t arg1, void* arg2)
{
    if (arg1 == 4)
    {
        int32_t* eax_2 = sub_401ee4(*(arg2 + 4), "rb");
        
        if (eax_2)
        {
            int32_t* eax_5 = sub_401ee4(*(arg2 + 0xc), "rb");
            
            if (eax_5)
            {
                sub_401d9b(eax_2, nullptr, FILE_END);
                void* eax_9 = sub_401ca6(eax_2);
                sub_401a49(eax_2);
                void* eax_10 = sub_401986(eax_9);
                void* eax_11 = sub_401986(0x8000);
                void* eax_12 = sub_401986(1);
                void* eax_13 = sub_401986(0x800);
                void* eax_14 = sub_401986(0x800);
                int32_t var_30_1;
                
                var_30_1 = eax_10 || eax_13 || eax_14 ? 1 : 0;
                
                if (var_30_1)
                {
                    sub_401d9b(eax_2, eax_9 - 0x1000, FILE_BEGIN);
                    sub_40191c(eax_13, 1, 0x800, eax_2);
                    sub_401d9b(eax_2, eax_9 - 0x800, FILE_BEGIN);
                    sub_40191c(eax_14, 1, 0x800, eax_2);
                    
                    if (*eax_13 == *eax_14)
                    {
                        sub_40139b(eax_13);
                        sub_40139b(eax_14);
                    }
                    else
                    {
                        sub_401d9b(eax_2, 0x800, FILE_BEGIN);
                        sub_40191c(eax_10, 1, eax_9, eax_2);
                        sub_401643(eax_2);
                        sub_40191c(eax_11, 1, 0x8000, eax_5);
                        sub_401643(eax_5);
                        int32_t* eax_25 = sub_401ee4(*(arg2 + 8), "wb");
                        
                        if (eax_25)
                        {
                            int32_t* eax_28 = sub_401ee4(*(arg2 + 0xc), "wb");
                            
                            if (eax_28)
                            {
                                sub_401543(eax_10, 1, eax_9 - 0x800, eax_25);
                                sub_401543(eax_10 + eax_9 - 0x1000, 1, 0x800, eax_25);
                                *eax_12 = 0x30;
                                sub_401543(eax_11, 1, 0x3e, eax_28);
                                sub_401543(eax_12, 1, 1, eax_28);
                                sub_401543(eax_11 + 0x3f, 1, 0x7fc1, eax_28);
                                sub_40139b(eax_10);
                                sub_40139b(eax_11);
                                sub_401643(eax_25);
                                sub_401643(eax_28);
                                sub_40139b(eax_13);
                                sub_40139b(eax_14);
                            }
                            else
                            {
                                int32_t var_34_13 = *(arg2 + 0xc);
                                sub_401ef7(0x40f178, "Error: cannot create %s.\n");
                            }
                        }
                        else
                        {
                            int32_t var_34_12 = *(arg2 + 8);
                            sub_401ef7(0x40f178, "Error: cannot create %s.\n");
                        }
                    }
                }
                else
                    sub_401ef7(0x40f178, "Not enough free memory or memory allocation error.\n");
            }
            else
            {
                int32_t var_34_2 = *(arg2 + 0xc);
                sub_401ef7(0x40f178, "Error: cannot open %s.\n");
            }
        }
        else
        {
            int32_t var_34_1 = *(arg2 + 4);
            sub_401ef7(0x40f178, "Error: cannot open %s.\n");
        }
    }
    else
    {
        sub_401ef7(0x40f178, 
            "\nUsage: bincon <0WINCEOS.BIN file> <new 1ST_READ.BIN to create> <IP.BIN filename>\n");
        sub_401ef7(0x40f178, "Example: bincon 0WINCEOS.BIN 1ST_READ.BIN IP.BIN\n");
    }
    
    return 0;
}

struct _EXCEPTION_REGISTRATION_RECORD** sub_40139b(void* arg1)
{
    int32_t __saved_ebp_2 = 0xc;
    int32_t var_8 = 0x40e3a0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e3a0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_3 = &data_4013a7;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    struct _EXCEPTION_REGISTRATION_RECORD** result = &ExceptionList;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    
    if (arg1)
    {
        void* lpMem;
        
        if (data_410d74 != 3)
        {
            lpMem = arg1;
        label_401403:
            result = HeapFree(data_4101b0, HEAP_NONE, lpMem);
            
            if (!result)
            {
                struct _EXCEPTION_REGISTRATION_RECORD*** eax_1 = __errno();
                result = sub_4023e6(GetLastError());
                *eax_1 = result;
            }
        }
        else
        {
            sub_402690(4);
            int32_t var_8_1 = 0;
            void* eax = sub_402709(arg1);
            
            if (eax)
                sub_402734(eax, arg1);
            
            int32_t var_8_2 = 0xfffffffe;
            result = sub_4013f1();
            
            if (!eax)
            {
                lpMem = arg1;
                goto label_401403;
            }
        }
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_1 = &data_401428;
    return result;
}

int32_t sub_4013f1()
{
    return __unlock(4);
}

uint32_t sub_401429(void* arg1, int32_t arg2, uint32_t arg3, int32_t* arg4)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t var_c = ecx;
    uint32_t eax_2 = arg2 * arg3;
    uint32_t var_c_1 = eax_2;
    void* ebx = eax_2;
    
    if (eax_2)
    {
        int32_t var_8_1;
        
        if (!(arg4[3] & 0x10c))
            var_8_1 = 0x1000;
        else
            var_8_1 = arg4[6];
        
        while (true)
        {
            int32_t ecx_3 = arg4[3] & 0x108;
            void* edi_1;
            
            if (ecx_3)
                edi_1 = arg4[1];
            
            if (ecx_3 && edi_1)
            {
                if (edi_1 < 0)
                {
                    arg4[3] |= 0x20;
                    break;
                }
                
                if (ebx < edi_1)
                    edi_1 = ebx;
                
                sub_403d70(*arg4, arg1, edi_1);
                arg4[1] -= edi_1;
                *arg4 += edi_1;
                ebx -= edi_1;
                arg1 += edi_1;
            }
            else if (ebx < var_8_1)
            {
                int32_t* var_1c_4 = arg4;
                
                if (sub_4033b6(*arg1) == 0xffffffff)
                    goto label_4014f8;
                
                arg1 += 1;
                int32_t eax_12 = arg4[6];
                ebx -= 1;
                var_8_1 = eax_12;
                
                if (eax_12 <= 0)
                    var_8_1 = 1;
            }
            else
            {
                bool cond:5_1;
                
                if (ecx_3)
                    cond:5_1 = sub_403be5(arg4);
                
                if (ecx_3 && cond:5_1)
                    goto label_4014f8;
                
                void* edi_2 = ebx;
                
                if (var_8_1)
                    edi_2 -= COMBINE(0, ebx) % var_8_1;
                
                void* eax_7 = sub_403adc(sub_403bb8(arg4), arg1, edi_2);
                
                if (eax_7 != 0xffffffff)
                {
                    void* ecx_6 = edi_2;
                    
                    if (eax_7 <= edi_2)
                        ecx_6 = eax_7;
                    
                    arg1 += ecx_6;
                    ebx -= ecx_6;
                }
                
                if (eax_7 == 0xffffffff || eax_7 < edi_2)
                {
                    arg4[3] |= 0x20;
                label_4014f8:
                    eax_2 = var_c_1;
                    break;
                    break;
                }
            }
            
            if (!ebx)
                return arg3;
            
            eax_2 = var_c_1;
        }
        
        eax_2 = COMBINE(0, eax_2 - ebx) / arg2;
    }
    
    return eax_2;
}

uint32_t sub_401543(void* arg1, int32_t arg2, uint32_t arg3, int32_t* arg4)
{
    int32_t __saved_ebp_2 = 0xc;
    int32_t var_8 = 0x40e3c0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e3c0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_2 = &data_40154f;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    uint32_t result;
    
    if (arg2 * arg3)
    {
        int32_t eax_2;
        eax_2 = arg4;
        int32_t eax_4;
        
        if (eax_2)
            eax_4 = arg1;
        
        if (!eax_2 || !eax_4)
        {
            *__errno() = 0;
            sub_4041db(0, 0, 0, 0, 0);
            result = 0;
        }
        else
        {
            sub_40211d(arg4);
            int32_t var_8_1 = 0;
            uint32_t result_1 = sub_401429(arg1, arg2, arg3, arg4);
            int32_t var_8_2 = 0xfffffffe;
            sub_4015c6(&__saved_ebp);
            result = result_1;
        }
    }
    else
        result = 0;
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_1 = &data_4015c5;
    return result;
}

int32_t sub_4015c6(void* arg1 @ ebp)
{
    return sub_40216f(*(arg1 + 0x14));
}

int32_t sub_4015d0(int32_t* arg1)
{
    int32_t result = 0xffffffff;
    
    if (!arg1)
    {
        *__errno() = 0x16;
        sub_4041db(0, 0, 0, 0, 0);
        return 0xffffffff;
    }
    
    if (arg1[3] & 0x83)
    {
        result = sub_403be5(arg1);
        sub_404360(arg1);
        
        if (sub_404293(sub_403bb8(arg1)) >= 0)
        {
            void* eax_6 = arg1[7];
            
            if (eax_6)
            {
                sub_40139b(eax_6);
                arg1[7] = 0;
            }
        }
        else
            result = 0xffffffff;
    }
    
    arg1[3] = 0;
    return result;
}

int32_t sub_401643(int32_t* arg1)
{
    int32_t __saved_ebp_2 = 0xc;
    int32_t var_8 = 0x40e3e0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e3e0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_2 = &data_40164f;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t result_1 = 0xffffffff;
    int32_t eax;
    eax = arg1;
    int32_t result;
    
    if (eax)
    {
        if (!(arg1[3] & 0x40))
        {
            sub_40211d(arg1);
            int32_t var_8_1 = 0;
            result_1 = sub_4015d0(arg1);
            int32_t var_8_2 = 0xfffffffe;
            sub_4016b7(arg1);
        }
        else
            arg1[3] = 0;
        
        result = result_1;
    }
    else
    {
        *__errno() = 0x16;
        sub_4041db(0, 0, 0, 0, 0);
        result = 0xffffffff;
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_1 = &data_401691;
    return result;
}

int32_t sub_4016b7(void* arg1 @ esi)
{
    return sub_40216f(arg1);
}

uint32_t sub_4016bf(char* arg1, void* arg2, int32_t arg3, uint32_t arg4, int32_t* arg5)
{
    char* var_c = arg1;
    void* var_8 = arg2;
    
    if (arg3 && arg4)
    {
        void* edi_1 = arg3 * arg4;
        void* var_14_1 = edi_1;
        void* ebx_1 = edi_1;
        int32_t var_10_1;
        
        if (!(arg5[3] & 0x10c))
            var_10_1 = 0x1000;
        else
            var_10_1 = arg5[6];
        
        if (!edi_1)
            return arg4;
        
        while (true)
        {
            void* eax_3;
            
            if (arg5[3] & 0x10c)
                eax_3 = arg5[1];
            
            if (arg5[3] & 0x10c && eax_3)
            {
                if (eax_3 < 0)
                {
                label_401840:
                    arg5[3] |= 0x20;
                    return COMBINE(0, edi_1 - ebx_1) / arg3;
                }
                
                void* edi_2 = ebx_1;
                
                if (ebx_1 >= eax_3)
                    edi_2 = eax_3;
                
                if (edi_2 > var_8)
                {
                    if (arg2 != 0xffffffff)
                        sub_404390(arg1, 0, arg2);
                    
                    *__errno() = 0x22;
                    int32_t var_34;
                    __builtin_memset(&var_34, 0, 0x14);
                    break;
                }
                
                sub_404ba8(var_c, var_8, *arg5, edi_2);
                arg5[1] -= edi_2;
                *arg5 += edi_2;
                var_c += edi_2;
                ebx_1 -= edi_2;
                var_8 -= edi_2;
                edi_1 = var_14_1;
            }
            else if (ebx_1 < var_10_1)
            {
                uint32_t eax_8 = sub_40440a(arg5);
                
                if (eax_8 == 0xffffffff)
                    return COMBINE(0, edi_1 - ebx_1) / arg3;
                
                if (!var_8)
                {
                label_40181a:
                    
                    if (arg2 != 0xffffffff)
                        sub_404390(arg1, 0, arg2);
                    
                    *__errno() = 0x22;
                    int32_t var_34_1;
                    __builtin_memset(&var_34_1, 0, 0x14);
                    break;
                    break;
                }
                
                char* ecx_3 = var_c;
                var_c = &var_c[1];
                *ecx_3 = eax_8;
                ebx_1 -= 1;
                var_8 -= 1;
                var_10_1 = arg5[6];
            }
            else
            {
                void* eax_4 = ebx_1;
                
                if (var_10_1)
                    eax_4 = ebx_1 - COMBINE(0, eax_4) % var_10_1;
                
                if (eax_4 > var_8)
                    goto label_40181a;
                
                int32_t eax_7 = sub_404acc(sub_403bb8(arg5), var_c, eax_4);
                
                if (!eax_7)
                {
                    arg5[3] |= 0x10;
                    return COMBINE(0, edi_1 - ebx_1) / arg3;
                }
                
                if (eax_7 == 0xffffffff)
                    goto label_401840;
                
                var_c = &var_c[eax_7];
                ebx_1 -= eax_7;
                var_8 -= eax_7;
            }
            
            if (!ebx_1)
                return arg4;
        }
        
        sub_4041db(0, 0, 0, 0, 0);
    }
    
    return 0;
}

uint32_t sub_401855(char* arg1, void* arg2, int32_t arg3, uint32_t arg4, int32_t* arg5)
{
    int32_t __saved_ebp_2 = 0xc;
    int32_t var_8 = 0x40e400;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e400 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_3 = &data_401861;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_20 = 0;
    uint32_t result;
    
    if (!arg3 || !arg4)
        result = 0;
    else
    {
        int32_t eax;
        eax = arg1;
        
        if (eax)
        {
            if (!arg5 || arg4 > COMBINE(0, 0xffffffff) / arg3)
            {
                if (arg2 != 0xffffffff)
                    sub_404390(arg1, 0, arg2);
                
                int32_t eax_4;
                eax_4 = arg5;
                
                if (!eax_4)
                    goto label_401885;
                
                uint32_t temp0_2 = COMBINE(0, 0xffffffff) / arg3;
                
                if (temp0_2 - temp0_2 == 0xffffffff)
                    goto label_401885;
            }
            
            sub_40211d(arg5);
            int32_t var_8_1 = 0;
            uint32_t result_1 = sub_4016bf(arg1, arg2, arg3, arg4, arg5);
            int32_t var_8_2 = 0xfffffffe;
            sub_401912(&__saved_ebp);
            result = result_1;
        }
        else
        {
        label_401885:
            *__errno() = 0x16;
            sub_4041db(0, 0, 0, 0, 0);
            result = 0;
        }
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_1 = &data_40189f;
    return result;
}

int32_t sub_401912(void* arg1 @ ebp)
{
    return sub_40216f(*(arg1 + 0x18));
}

uint32_t sub_40191c(char* arg1, int32_t arg2, uint32_t arg3, int32_t* arg4)
{
    return sub_401855(arg1, 0xffffffff, arg2, arg3, arg4);
}

void* sub_401937(int32_t* arg1)
{
    int32_t __saved_ebp_2 = 0xc;
    int32_t var_8 = 0x40e420;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e420 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_1 = &data_401943;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    void* result = nullptr;
    
    if (arg1 <= data_410d64)
    {
        sub_402690(4);
        int32_t var_8_1 = 0;
        result = sub_402edd(arg1);
        int32_t var_8_2 = 0xfffffffe;
        sub_40197d();
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_1 = &data_40197c;
    return result;
}

int32_t sub_40197d()
{
    return __unlock(4);
}

void* sub_401986(uint32_t arg1)
{
    if (arg1 > 0xffffffe0)
    {
        sub_40510e(arg1);
        *__errno() = 0xc;
        return 0;
    }
    
    void* result;
    
    while (true)
    {
        uint32_t edi_1 = arg1;
        
        if (!data_4101b0)
        {
            sub_4050cb();
            sub_404f2b(0x1e);
            sub_404c6d(0xff);
            /* no return */
        }
        
        int32_t eax_1 = data_410d74;
        
        if (eax_1 != 1)
        {
            if (eax_1 == 3)
                result = sub_401937(arg1);
            
            if (eax_1 != 3 || !result)
            {
                if (!arg1)
                    edi_1 = 1;
                
                result = HeapAlloc(data_4101b0, HEAP_NONE, (edi_1 + 0xf) & 0xfffffff0);
            }
        }
        else
        {
            uint32_t dwBytes;
            
            dwBytes = !arg1 ? 1 : arg1;
            
            result = HeapAlloc(data_4101b0, HEAP_NONE, dwBytes);
        }
        
        if (result)
            break;
        
        if (data_410670 == result)
            *__errno() = 0xc;
        else if (sub_40510e(arg1))
            continue;
        
        *__errno() = 0xc;
        break;
    }
    
    return result;
}

int32_t sub_401a49(int32_t* arg1)
{
    int32_t __saved_ebp_2 = 8;
    int32_t var_8 = 0x40e440;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e440 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_2c = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_2c;
    void* const var_30_2 = &data_401a55;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t* esi = arg1;
    int32_t eax;
    eax = esi;
    int32_t result;
    
    if (eax)
    {
        arg1 = esi;
        int32_t eax_2 = sub_403bb8(esi);
        sub_40211d(esi);
        int32_t var_8_1 = 0;
        sub_403be5(esi);
        esi[3] &= 0xffffffcf;
        void* eax_6;
        
        if (eax_2 == 0xffffffff || eax_2 == 0xfffffffe)
            eax_6 = &data_40f820;
        else
            eax_6 = (eax_2 & 0x1f) * 0x28 + (&data_410c40)[eax_2 >> 5];
        
        int32_t* ecx_2;
        ecx_2 = *(eax_6 + 4);
        ecx_2 &= 0xfd;
        *(eax_6 + 4) = ecx_2;
        int32_t eax_7 = esi[3];
        
        if (eax_7 < 0)
            esi[3] = eax_7 & 0xfffffffc;
        
        if (sub_4051a2(eax_2, 0, FILE_BEGIN) == 0xffffffff)
            esi[3] |= 0x20;
        
        int32_t var_8_2 = 0xfffffffe;
        result = sub_401b04(&__saved_ebp);
    }
    else
    {
        *__errno() = 0x16;
        result = sub_4041db(0, 0, 0, 0, 0);
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_1 = &data_401a82;
    return result;
}

int32_t sub_401b04(void* arg1 @ ebp)
{
    return sub_40216f(*(arg1 + 8));
}

void* sub_401b0e(int32_t* arg1)
{
    int32_t* edi = arg1;
    
    if (edi)
    {
        int32_t eax_1 = sub_403bb8(edi);
        
        if (edi[1] < 0)
            edi[1] = 0;
        
        uint32_t eax_2 = sub_4051a2(eax_1, 0, FILE_CURRENT);
        
        if (eax_2 >= 0)
        {
            int16_t edx_1 = edi[3];
            
            if (!(edx_1 & 0x108))
                return eax_2 - edi[1];
            
            int32_t eax_4 = *edi;
            char* i_2 = edi[2];
            void* var_10_1 = eax_4 - i_2;
            
            if (edx_1 & 3)
            {
                if (*((&data_410c40)[eax_1 >> 5] + (eax_1 & 0x1f) * 0x28 + 4) & 0x80)
                {
                    for (char* i = i_2; i < eax_4; i = &i[1])
                    {
                        if (*i == 0xa)
                            var_10_1 += 1;
                    }
                }
                
                goto label_401bbc;
            }
            
            if (edx_1 < 0)
            {
            label_401bbc:
                
                if (!eax_2)
                    return var_10_1;
                
                if (!(edi[3] & 1))
                    return var_10_1 + eax_2;
                
                int32_t edx_5 = edi[1];
                
                if (!edx_5)
                    return eax_2;
                
                int32_t esi_9 = (eax_1 & 0x1f) * 0x28;
                arg1 = eax_4 - i_2 + edx_5;
                
                if (!(*((&data_410c40)[eax_1 >> 5] + esi_9 + 4) & 0x80))
                    return var_10_1 + eax_2 - arg1;
                
                bool cond:3_1;
                
                if (sub_4051a2(eax_1, 0, FILE_END) == eax_2)
                {
                    char* i_1 = edi[2];
                    
                    for (void* ecx_3 = arg1 + i_1; i_1 < ecx_3; i_1 = &i_1[1])
                    {
                        if (*i_1 == 0xa)
                            arg1 += 1;
                    }
                    
                    cond:3_1 = !(edi[3] & 0x2000);
                    goto label_401c8e;
                }
                
                if (sub_4051a2(eax_1, eax_2, FILE_BEGIN) >= 0)
                {
                    int32_t* eax_11 = 0x200;
                    int16_t ecx_4;
                    
                    if (arg1 <= 0x200)
                        ecx_4 = edi[3];
                    
                    if (arg1 > 0x200 || !(ecx_4 & 8) || ecx_4 & 0x400)
                        eax_11 = edi[6];
                    
                    arg1 = eax_11;
                    cond:3_1 = !(*((&data_410c40)[eax_1 >> 5] + esi_9 + 4) & 4);
                label_401c8e:
                    
                    if (cond:3_1)
                        return var_10_1 + eax_2 - arg1;
                    
                    return var_10_1 + eax_2 - (arg1 + 1);
                }
            }
            else
                *__errno() = 0x16;
        }
    }
    else
    {
        *__errno() = 0x16;
        sub_4041db(0, 0, 0, 0, 0);
    }
    
    return 0xffffffff;
}

void* sub_401ca6(int32_t* arg1)
{
    int32_t __saved_ebp_2 = 0xc;
    int32_t var_8 = 0x40e460;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e460 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_2 = &data_401cb2;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t eax;
    eax = arg1;
    void* result;
    
    if (eax)
    {
        sub_40211d(arg1);
        int32_t var_8_1 = 0;
        void* result_1 = sub_401b0e(arg1);
        int32_t var_8_2 = 0xfffffffe;
        sub_401d0a(&__saved_ebp);
        result = result_1;
    }
    else
    {
        *__errno() = 0x16;
        sub_4041db(0, 0, 0, 0, 0);
        result = 0xffffffff;
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_1 = &data_401d09;
    return result;
}

int32_t sub_401d0a(void* arg1 @ ebp)
{
    return sub_40216f(*(arg1 + 8));
}

int32_t sub_401d14(int32_t* arg1, void* arg2, enum SET_FILE_POINTER_MOVE_METHOD arg3)
{
    int32_t eax = arg1[3];
    
    if (!(eax & 0x83))
    {
        *__errno() = 0x16;
        return 0xffffffff;
    }
    
    arg1[3] = eax & 0xffffffef;
    
    if (arg3 == FILE_CURRENT)
    {
        arg2 += sub_401b0e(arg1);
        arg3 = FILE_BEGIN;
    }
    
    sub_403be5(arg1);
    int32_t eax_5 = arg1[3];
    
    if (eax_5 < 0)
        arg1[3] = eax_5 & 0xfffffffc;
    else if (eax_5 & 1 && eax_5 & 8 && !(eax_5 & 0x400))
        arg1[6] = 0x200;
    
    int32_t ecx_4;
    ecx_4 = sub_4051a2(sub_403bb8(arg1), arg2, arg3) != 0xffffffff;
    return ecx_4 - 1;
}

int32_t sub_401d9b(int32_t* arg1, void* arg2, enum SET_FILE_POINTER_MOVE_METHOD arg3)
{
    int32_t __saved_ebp_2 = 0xc;
    int32_t var_8 = 0x40e480;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e480 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_2 = &data_401da7;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t eax;
    eax = arg1;
    int32_t result;
    
    if (eax && (!arg3 || arg3 == FILE_CURRENT || arg3 == FILE_END))
    {
        sub_40211d(arg1);
        int32_t var_8_1 = 0;
        int32_t result_1 = sub_401d14(arg1, arg2, arg3);
        int32_t var_8_2 = 0xfffffffe;
        sub_401e16(&__saved_ebp);
        result = result_1;
    }
    else
    {
        *__errno() = 0x16;
        sub_4041db(0, 0, 0, 0, 0);
        result = 0xffffffff;
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_1 = &data_401e15;
    return result;
}

int32_t sub_401e16(void* arg1 @ ebp)
{
    return sub_40216f(*(arg1 + 8));
}

int32_t* sub_401e20(int32_t* arg1, char* arg2, int32_t arg3)
{
    int32_t __saved_ebp_2 = 0xc;
    int32_t var_8 = 0x40e4a0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e4a0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_1 = &data_401e2c;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_20 = 0;
    int32_t* edi = arg1;
    int32_t eax;
    eax = edi;
    int32_t* result;
    
    if (eax)
    {
        int32_t eax_2;
        eax_2 = arg2;
        
        if (!eax_2)
            goto label_401e44;
        
        int32_t eax_3;
        eax_3 = *arg2;
        
        if (!eax_3)
            goto label_401e44;
        
        int32_t* eax_4 = sub_405760();
        arg1 = eax_4;
        
        if (eax_4)
        {
            int32_t var_8_1 = 0;
            
            if (*edi)
            {
                int32_t* result_1 = sub_4054be(edi, arg2, arg3, eax_4);
                int32_t var_8_2 = 0xfffffffe;
                sub_401eda(&__saved_ebp);
                result = result_1;
            }
            else
            {
                *__errno() = 0x16;
                __local_unwind4(&__security_cookie, &ExceptionList, 0xfffffffe);
                result = nullptr;
            }
        }
        else
        {
            *__errno() = 0x18;
            result = nullptr;
        }
    }
    else
    {
    label_401e44:
        *__errno() = 0x16;
        sub_4041db(0, 0, 0, 0, 0);
        result = nullptr;
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_1 = &data_401ed9;
    return result;
}

int32_t sub_401eda(void* arg1 @ ebp)
{
    return sub_40216f(*(arg1 + 8));
}

int32_t* sub_401ee4(int32_t* arg1, char* arg2)
{
    return sub_401e20(arg1, arg2, 0x40);
}

void* sub_401ef7(int32_t* arg1, char* arg2)
{
    int32_t __saved_ebp_2 = 0xc;
    int32_t var_8 = 0x40e4c0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e4c0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_8 = &data_401f03;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    void* result_1 = nullptr;
    int32_t* esi = arg1;
    int32_t eax;
    eax = esi;
    int32_t eax_2;
    
    if (eax)
        eax_2 = arg2;
    
    void* result;
    
    if (!eax || !eax_2)
    {
        *__errno() = 0x16;
        sub_4041db(0, 0, 0, 0, 0);
        result = 0xffffffff;
    }
    else
    {
        arg1 = esi;
        sub_40211d(esi);
        int32_t var_8_1 = 0;
        
        if (!(esi[3] & 0x40))
        {
            int32_t eax_3 = sub_403bb8(esi);
            int32_t eax_4;
            
            if (eax_3 != 0xffffffff)
                eax_4 = sub_403bb8(esi);
            
            void* eax_10;
            
            if (eax_3 == 0xffffffff || eax_4 == 0xfffffffe)
                eax_10 = &data_40f820;
            else
            {
                void* edi_1 = &(&data_410c40)[sub_403bb8(esi) >> 5];
                eax_10 = (sub_403bb8(esi) & 0x1f) * 0x28 + *edi_1;
            }
            
            void* eax_18;
            
            if (!(*(eax_10 + 0x24) & 0x7f))
            {
                int32_t eax_11 = sub_403bb8(esi);
                int32_t eax_12;
                
                if (eax_11 != 0xffffffff)
                    eax_12 = sub_403bb8(esi);
                
                if (eax_11 == 0xffffffff || eax_12 == 0xfffffffe)
                    eax_18 = &data_40f820;
                else
                {
                    void* edi_2 = &(&data_410c40)[sub_403bb8(esi) >> 5];
                    eax_18 = (sub_403bb8(esi) & 0x1f) * 0x28 + *edi_2;
                }
            }
            
            if (*(eax_10 + 0x24) & 0x7f || *(eax_18 + 0x24) & 0x80)
            {
                *__errno() = 0x16;
                sub_4041db(0, 0, 0, 0, 0);
                result_1 = 0xffffffff;
            }
        }
        
        if (!result_1)
        {
            int32_t eax_20 = sub_4059db(esi);
            void arg_c;
            result_1 = sub_405bc3(esi, arg2, nullptr, &arg_c);
            sub_405a71(eax_20, esi);
        }
        
        int32_t var_8_2 = 0xfffffffe;
        sub_40203c(&__saved_ebp);
        result = result_1;
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_1 = &data_40203b;
    return result;
}

int32_t sub_40203c(void* arg1 @ ebp)
{
    return sub_40216f(*(arg1 + 8));
}

int32_t sub_402046() __pure
{
    return 0x40f138;
}

int32_t sub_40204c()
{
    uint32_t eax = data_411d80;
    
    if (!eax)
    {
        eax = 0x200;
        data_411d80 = eax;
    }
    else if (eax < 0x14)
    {
        eax = 0x14;
        data_411d80 = eax;
    }
    
    void* eax_1 = sub_40659b(eax, 4);
    data_410d7c = eax_1;
    
    if (!eax_1)
    {
        data_411d80 = 0x14;
        eax_1 = sub_40659b(0x14, 4);
        data_410d7c = eax_1;
        
        if (!eax_1)
            return 0x1a;
    }
    
    int32_t* edx = nullptr;
    int32_t ecx_2 = 0x40f138;
    
    while (true)
    {
        *(edx + eax_1) = ecx_2;
        ecx_2 += 0x20;
        edx = &edx[1];
        
        if (ecx_2 >= &data_40f3b8)
            break;
        
        eax_1 = data_410d7c;
    }
    
    int32_t edx_1 = 0;
    
    for (void* i = &data_40f148; i < 0x40f1a8; )
    {
        int32_t eax_6 = *((edx_1 & 0x1f) * 0x28 + (&data_410c40)[edx_1 >> 5]);
        
        if (eax_6 == 0xffffffff || eax_6 == 0xfffffffe || !eax_6)
            *i = 0xfffffffe;
        
        i += 0x20;
        edx_1 += 1;
    }
    
    return 0;
}

struct _EXCEPTION_REGISTRATION_RECORD** sub_4020fd()
{
    sub_403d63();
    
    if (data_41034c)
        sub_40662e();
    
    return sub_40139b(data_410d7c);
}

int32_t sub_40211d(void* arg1)
{
    if (arg1 >= 0x40f138 && arg1 <= 0x40f398)
        return sub_402690(((arg1 - 0x40f138) >> 5) + 0x10);
    
    return EnterCriticalSection(arg1 + 0x20);
}

int32_t sub_40214c(int32_t arg1, void* arg2)
{
    if (arg1 >= 0x14)
        return EnterCriticalSection(arg2 + 0x20);
    
    return sub_402690(arg1 + 0x10);
}

int32_t sub_40216f(void* arg1)
{
    if (arg1 >= 0x40f138 && arg1 <= 0x40f398)
        return __unlock(((arg1 - 0x40f138) >> 5) + 0x10);
    
    return LeaveCriticalSection(arg1 + 0x20);
}

int32_t sub_40219e(int32_t arg1, void* arg2)
{
    if (arg1 >= 0x14)
        return LeaveCriticalSection(arg2 + 0x20);
    
    return __unlock(arg1 + 0x10);
}

void sub_4021c1(int32_t arg1) __noreturn
{
    if (data_4101ac != 2)
        sub_4050cb();
    
    sub_404f2b(arg1);
    sub_404c6d(0xff);
    /* no return */
}

int32_t sub_4021e5() __pure
{
    return 0;
}

int32_t sub_402226()
{
    int32_t __saved_ebp_2 = 0x1c;
    int32_t var_8 = 0x40e4e0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t ebx;
    int32_t var_34 = ebx;
    int32_t esi;
    int32_t var_38 = esi;
    int32_t edi;
    int32_t var_3c = edi;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e4e0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    void* var_40 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_40;
    void* const var_44 = &data_402232;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    var_44 = 0x94;
    int32_t* eax_1 = HeapAlloc(GetProcessHeap(), HEAP_NONE, var_44);
    
    if (!eax_1)
    {
        var_44 = 0x12;
        sub_4021c1(var_44);
        /* no return */
    }
    
    *eax_1 = 0x94;
    var_44 = eax_1;
    BOOL eax_2 = GetVersionExA(var_44);
    var_44 = eax_1;
    int32_t result;
    void* const* esp;
    
    if (eax_2)
    {
        int32_t eax_4 = eax_1[4];
        int32_t eax_5 = eax_1[1];
        int32_t eax_6 = eax_1[2];
        int32_t edi_2 = eax_1[3] & 0x7fff;
        HeapFree(GetProcessHeap(), HEAP_NONE, var_44);
        
        if (eax_4 != 2)
            edi_2 |= 0x8000;
        
        data_410314 = eax_4;
        data_41031c = (eax_5 << 8) + eax_6;
        data_410320 = eax_5;
        data_410324 = eax_6;
        data_410318 = edi_2;
        int32_t var_24_2 = 0;
        var_44 = 1;
        
        if (!sub_4024c0(var_44))
        {
            var_44 = 0x1c;
            sub_4021c1(var_44);
            /* no return */
        }
        
        if (!sub_407095())
        {
            var_44 = 0x10;
            sub_4021c1(var_44);
            /* no return */
        }
        
        sub_406c9e();
        int32_t var_8_1 = 0;
        
        if (sub_40527e() < 0)
        {
            var_44 = 0x1b;
            sub_404c23(var_44);
        }
        
        data_410d78 = GetCommandLineA();
        data_4101a4 = sub_406b69();
        
        if (sub_406ab0() < 0)
        {
            var_44 = 8;
            sub_404c23(var_44);
        }
        
        if (sub_40683d() < 0)
        {
            var_44 = 9;
            sub_404c23(var_44);
        }
        
        var_44 = 1;
        void* eax_18 = sub_404d3f(var_44);
        
        if (eax_18)
        {
            var_44 = eax_18;
            sub_404c23(var_44);
        }
        
        void* eax_19 = data_410334;
        data_410338 = eax_19;
        var_44 = eax_19;
        sub_401000(data_410328, data_41032c);
        esp = &var_40;
        int32_t result_1 = 0;
        
        if (!var_24_2)
        {
            var_44 = nullptr;
            esp = &var_44;
            sub_404e9f(var_44);
        }
        
        __cexit();
        int32_t var_8_2 = 0xfffffffe;
        result = result_1;
    }
    else
    {
        HeapFree(GetProcessHeap(), HEAP_NONE, var_44);
        esp = &var_40;
        result = 0xff;
    }
    
    *(esp - 4) = &data_4023db;
    fsbase->NtTib.ExceptionList = ExceptionList;
    esp[1];
    esp[2];
    esp[3];
    int32_t __saved_ebp_1 = *(esp - 4);
    return result;
}

int32_t sub_40239e(void* arg1 @ ebp)
{
    int32_t* eax_1 = *(arg1 - 0x14);
    int32_t ecx_1 = **eax_1;
    *(arg1 - 0x2c) = ecx_1;
    return sub_4066ce(ecx_1, eax_1);
}

int32_t sub_4023b2(int32_t* arg1 @ ebp)
{
    int32_t esp_1 = arg1[-6];
    int32_t eax = arg1[-0xb];
    arg1[-7] = eax;
    
    if (!arg1[-8])
    {
        *(esp_1 - 4) = eax;
        esp_1 -= 4;
        sub_404eb0();
    }
    
    __c_exit();
    arg1[-1] = 0xfffffffe;
    int32_t result = arg1[-7];
    *(esp_1 - 4) = &data_4023db;
    TEB* fsbase;
    fsbase->NtTib.ExceptionList = arg1[-4];
    *(esp_1 + 4);
    *(esp_1 + 8);
    *(esp_1 + 0xc);
    *arg1;
    *arg1 = *(esp_1 - 4);
    *arg1;
    return result;
}

int32_t _start()
{
    sub_407219();
    /* tailcall */
    return sub_402226();
}

int32_t sub_4023e6(int32_t arg1)
{
    for (int32_t i = 0; i < 0x2d; i += 1)
    {
        if (arg1 == *((i << 3) + &data_40f3c0))
            return *((i << 3) + &data_40f3c4);
    }
    
    if (arg1 - 0x13 > 0x11)
        return ((arg1 - 0xbc - (arg1 - 0xbc)) & 0xe) + 8;
    
    return 0xd;
}

void* __errno()
{
    void* eax_2 = sub_406ed9();
    
    if (eax_2)
        return eax_2 + 8;
    
    return 0x40f528;
}

void* ___doserrno()
{
    void* eax_2 = sub_406ed9();
    
    if (eax_2)
        return eax_2 + 0xc;
    
    return 0x40f52c;
}

void* sub_402447(int32_t arg1)
{
    *___doserrno() = arg1;
    int32_t eax_1 = sub_4023e6(arg1);
    void* result = __errno();
    *result = eax_1;
    return result;
}

int32_t __fastcall sub_402465(int32_t arg1)
{
    int32_t var_8 = arg1;
    int32_t var_c = arg1;
    var_8 = 0;
    var_c = 0;
    
    if (sub_404ccc(&var_8))
    {
        int32_t var_24;
        __builtin_memset(&var_24, 0, 0x14);
        sub_4040df();
        /* no return */
    }
    
    if (sub_404d03(&var_c))
    {
        int32_t var_24_1;
        __builtin_memset(&var_24_1, 0, 0x14);
        sub_4040df();
        /* no return */
    }
    
    if (var_8 == 2 && var_c >= 5)
        return 1;
    
    return 3;
}

int32_t sub_4024c0(int32_t arg1)
{
    enum HEAP_FLAGS flOptions;
    flOptions = !arg1;
    HANDLE eax;
    int32_t ecx;
    eax = HeapCreate(flOptions, 0x1000, 0);
    data_4101b0 = eax;
    
    if (eax)
    {
        int32_t eax_2 = sub_402465(ecx);
        data_410d74 = eax_2;
        bool cond:3_1;
        
        if (eax_2 == 3)
            cond:3_1 = sub_4026c1(0x3f8);
        
        if (eax_2 != 3 || cond:3_1)
            return 1;
        
        HeapDestroy(data_4101b0);
        data_4101b0 = 0;
    }
    
    return 0;
}

int32_t sub_40251a()
{
    int32_t i = 0;
    int32_t edi = 0x4101b8;
    
    do
    {
        if (*((i << 3) + &data_40f53c) == 1)
        {
            *((i << 3) + &data_40f538) = edi;
            edi += 0x18;
            
            if (!sub_4072c7(*((i << 3) + &data_40f538), 0xfa0))
            {
                *((i << 3) + &data_40f538) = 0;
                return 0;
            }
        }
        
        i += 1;
    } while (i < 0x24);
    
    return 1;
}

CRITICAL_SECTION* sub_402563()
{
    for (void* i = &data_40f538; i < 0x40f658; i += 8)
    {
        CRITICAL_SECTION* lpCriticalSection_1 = *i;
        
        if (lpCriticalSection_1 && *(i + 4) != 1)
        {
            DeleteCriticalSection(lpCriticalSection_1);
            sub_40139b(lpCriticalSection_1);
            *i = 0;
        }
    }
    
    CRITICAL_SECTION* lpCriticalSection;
    
    for (void* i_1 = &data_40f538; i_1 < 0x40f658; i_1 += 8)
    {
        lpCriticalSection = *i_1;
        
        if (lpCriticalSection && *(i_1 + 4) == 1)
            lpCriticalSection = DeleteCriticalSection(lpCriticalSection);
    }
    
    return lpCriticalSection;
}

int32_t __unlock(int32_t arg1)
{
    return LeaveCriticalSection(*((arg1 << 3) + &data_40f538));
}

int32_t sub_4025cd(int32_t arg1)
{
    int32_t __saved_ebp_2 = 0xc;
    int32_t var_8 = 0x40e500;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e500 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_2 = &data_4025d9;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t result_1 = 1;
    
    if (!data_4101b0)
    {
        sub_4050cb();
        sub_404f2b(0x1e);
        sub_404c6d(0xff);
        /* no return */
    }
    
    int32_t result;
    
    if (!*((arg1 << 3) + &data_40f538))
    {
        void* eax = sub_40655b(0x18);
        
        if (eax)
        {
            sub_402690(0xa);
            int32_t var_8_1 = 0;
            
            if (*((arg1 << 3) + &data_40f538))
                sub_40139b(eax);
            else if (sub_4072c7(eax, 0xfa0))
                *((arg1 << 3) + &data_40f538) = eax;
            else
            {
                sub_40139b(eax);
                *__errno() = 0xc;
                result_1 = 0;
            }
            
            int32_t var_8_2 = 0xfffffffe;
            sub_402687();
            result = result_1;
        }
        else
        {
            *__errno() = 0xc;
            result = 0;
        }
    }
    else
        result = 1;
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_1 = &data_402686;
    return result;
}

int32_t sub_402687()
{
    return __unlock(0xa);
}

int32_t sub_402690(int32_t arg1)
{
    if (!*((arg1 << 3) + &data_40f538) && !sub_4025cd(arg1))
        sub_404c23(0x11);
    
    return EnterCriticalSection(*((arg1 << 3) + &data_40f538));
}

int32_t sub_4026c1(int32_t arg1)
{
    int32_t result = HeapAlloc(data_4101b0, HEAP_NONE, 0x140);
    data_410d60 = result;
    
    if (!result)
        return result;
    
    data_410308 = 0;
    data_410d5c = 0;
    data_410d68 = result;
    data_410d64 = arg1;
    data_410d6c = 0x10;
    return 1;
}

void* sub_402709(int32_t arg1)
{
    void* result = data_410d60;
    void* ecx_1 = data_410d5c * 0x14 + result;
    
    while (true)
    {
        if (result >= ecx_1)
            return nullptr;
        
        if (arg1 - *(result + 0xc) < 0x100000)
            break;
        
        result += 0x14;
    }
    
    return result;
}

int32_t* sub_402734(void* arg1, void* arg2)
{
    int32_t* result = *(arg1 + 0x10);
    int32_t* esi_1 = arg2 - 4;
    uint32_t edi_2 = (arg2 - *(arg1 + 0xc)) >> 0xf;
    void* ecx_5 = *esi_1 - 1;
    void* var_8 = ecx_5;
    
    if (!(ecx_5 & 1))
    {
        void* ebx_1 = ecx_5 + esi_1;
        int32_t edx_1 = *ebx_1;
        int32_t edx_2 = esi_1[-1];
        arg2 = ebx_1;
        
        if (!(edx_1 & 1))
        {
            int32_t edx_5 = (edx_1 >> 4) - 1;
            
            if (edx_5 > 0x3f)
                edx_5 = 0x3f;
            
            if (*(ebx_1 + 4) == *(ebx_1 + 8))
            {
                if (edx_5 >= 0x20)
                {
                    uint32_t ebx_5 = ~(0x80000000 >> (edx_5 - 0x20));
                    result[edi_2 + 0x31] &= ebx_5;
                    char temp0_1 = *(edx_5 + result + 4);
                    *(edx_5 + result + 4) -= 1;
                    
                    if (temp0_1 == 1)
                        *(arg1 + 4) &= ebx_5;
                }
                else
                {
                    uint32_t ebx_3 = ~(0x80000000 >> edx_5);
                    result[edi_2 + 0x11] &= ebx_3;
                    char temp1_1 = *(edx_5 + result + 4);
                    *(edx_5 + result + 4) -= 1;
                    
                    if (temp1_1 == 1)
                    {
                        int32_t* ecx_9 = arg1;
                        *ecx_9 &= ebx_3;
                    }
                }
                
                ebx_1 = arg2;
            }
            
            ecx_5 = var_8 + edx_1;
            *(*(ebx_1 + 8) + 4) = *(ebx_1 + 4);
            *(*(arg2 + 4) + 8) = *(arg2 + 8);
            var_8 = ecx_5;
        }
        
        int32_t edx_11 = (ecx_5 >> 4) - 1;
        
        if (edx_11 > 0x3f)
            edx_11 = 0x3f;
        
        int32_t ebx_9 = edx_2 & 1;
        void* ebx_12;
        
        if (ebx_9)
            ebx_12 = arg1;
        else
        {
            void* esi_2 = esi_1 - edx_2;
            ebx_12 = (edx_2 >> 4) - 1;
            
            if (ebx_12 > 0x3f)
                ebx_12 = 0x3f;
            
            void* ecx_14 = ecx_5 + edx_2;
            edx_11 = (ecx_14 >> 4) - 1;
            var_8 = ecx_14;
            
            if (edx_11 > 0x3f)
                edx_11 = 0x3f;
            
            if (ebx_12 != edx_11)
            {
                if (*(esi_2 + 4) == *(esi_2 + 8))
                {
                    if (ebx_12 >= 0x20)
                    {
                        uint32_t esi_7 = ~(0x80000000 >> (ebx_12 - 0x20));
                        result[edi_2 + 0x31] &= esi_7;
                        char temp3_1 = *(ebx_12 + result + 4);
                        *(ebx_12 + result + 4) -= 1;
                        
                        if (temp3_1 == 1)
                            *(arg1 + 4) &= esi_7;
                    }
                    else
                    {
                        uint32_t esi_5 = ~(0x80000000 >> ebx_12);
                        result[edi_2 + 0x11] &= esi_5;
                        char temp4_1 = *(ebx_12 + result + 4);
                        *(ebx_12 + result + 4) -= 1;
                        
                        if (temp4_1 == 1)
                        {
                            int32_t* ecx_17 = arg1;
                            *ecx_17 &= esi_5;
                        }
                    }
                }
                
                *(*(esi_2 + 8) + 4) = *(esi_2 + 4);
                *(*(esi_2 + 4) + 8) = *(esi_2 + 8);
            }
            
            esi_1 = esi_2;
        }
        
        if (ebx_9 || ebx_12 != edx_11)
        {
            void* ecx_25 = &result[edi_2 * 0x81 + 0x51 + edx_11 * 2];
            int32_t ebx_13 = *(ecx_25 + 4);
            esi_1[2] = ecx_25;
            esi_1[1] = ebx_13;
            *(ecx_25 + 4) = esi_1;
            *(esi_1[1] + 8) = esi_1;
            
            if (esi_1[1] == esi_1[2])
            {
                int32_t ecx_27;
                ecx_27 = *(edx_11 + result + 4);
                *arg2[3] = ecx_27;
                ecx_27 += 1;
                *(edx_11 + result + 4) = ecx_27;
                
                if (edx_11 >= 0x20)
                {
                    if (!*arg2[3])
                        *(arg1 + 4) |= 0x80000000 >> (edx_11 - 0x20);
                    
                    result[edi_2 + 0x31] |= 0x80000000 >> (edx_11 - 0x20);
                }
                else
                {
                    if (!*arg2[3])
                    {
                        int32_t* ecx_29 = arg1;
                        *ecx_29 |= 0x80000000 >> edx_11;
                    }
                    
                    result[edi_2 + 0x11] |= 0x80000000 >> edx_11;
                }
            }
        }
        
        *esi_1 = var_8;
        *(var_8 + esi_1 - 4) = var_8;
        result = &result[edi_2 * 0x81 + 0x51];
        int32_t temp2_1 = *result;
        *result -= 1;
        
        if (temp2_1 == 1)
        {
            int32_t eax_3 = data_410308;
            
            if (eax_3)
            {
                VirtualFree((data_410d70 << 0xf) + *(eax_3 + 0xc), 0x8000, MEM_DECOMMIT);
                void* eax_4 = data_410308;
                *(eax_4 + 8) |= 0x80000000 >> data_410d70;
                *(*(data_410308 + 0x10) + (data_410d70 << 2) + 0xc4) = 0;
                void* eax_8 = *(data_410308 + 0x10);
                *(eax_8 + 0x43) -= 1;
                void* eax_9 = data_410308;
                
                if (!*(*(eax_9 + 0x10) + 0x43))
                {
                    *(eax_9 + 4) &= 0xfffffffe;
                    eax_9 = data_410308;
                }
                
                if (*(eax_9 + 8) == 0xffffffff)
                {
                    VirtualFree(*(eax_9 + 0xc), 0, MEM_RELEASE);
                    HeapFree(data_4101b0, HEAP_NONE, *(data_410308 + 0x10));
                    int128_t* eax_11 = data_410308;
                    sub_407390(eax_11, eax_11 + 0x14, 
                        data_410d5c * 0x14 - eax_11 + data_410d60 - 0x14);
                    data_410d5c -= 1;
                    
                    if (arg1 > data_410308)
                        arg1 -= 0x14;
                    
                    data_410d68 = data_410d60;
                }
            }
            
            result = arg1;
            data_410308 = result;
            data_410d70 = edi_2;
        }
    }
    
    return result;
}

int32_t* sub_402a48()
{
    int32_t eax_7 = data_410d6c;
    int32_t esi = data_410d5c;
    
    if (esi != eax_7)
        goto label_402a92;
    
    int32_t eax_2 = HeapReAlloc(data_4101b0, HEAP_NONE, data_410d60, (eax_7 + 0x10) * 0x14);
    
    if (eax_2)
    {
        data_410d6c += 0x10;
        esi = data_410d5c;
        data_410d60 = eax_2;
    label_402a92:
        int32_t* result = esi * 0x14 + data_410d60;
        int32_t eax_3 = HeapAlloc(data_4101b0, HEAP_ZERO_MEMORY, 0x41c4);
        result[4] = eax_3;
        
        if (eax_3)
        {
            int32_t eax_4 = VirtualAlloc(nullptr, 0x100000, MEM_RESERVE, PAGE_READWRITE);
            result[3] = eax_4;
            
            if (eax_4)
            {
                result[2] = 0xffffffff;
                *result = 0;
                result[1] = 0;
                data_410d5c += 1;
                *result[4] = 0xffffffff;
                return result;
            }
            
            HeapFree(data_4101b0, HEAP_NONE, result[4]);
        }
    }
    
    return nullptr;
}

int32_t sub_402af8(void* arg1)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t var_c = ecx;
    int32_t i = *(arg1 + 8);
    void* esi = *(arg1 + 0x10);
    int32_t result = 0;
    
    while (i >= 0)
    {
        i *= 2;
        result += 1;
    }
    
    void* eax_2 = result * 0x204 + esi + 0x144;
    void* var_c_1 = eax_2;
    int32_t i_4 = 0x3f;
    int32_t i_1;
    
    do
    {
        *(eax_2 + 8) = eax_2;
        *(eax_2 + 4) = eax_2;
        eax_2 += 8;
        i_1 = i_4;
        i_4 -= 1;
    } while (i_1 != 1);
    void* lpAddress = (result << 0xf) + *(arg1 + 0xc);
    
    if (!VirtualAlloc(lpAddress, 0x8000, MEM_COMMIT, PAGE_READWRITE))
        return 0xffffffff;
    
    void* edx = lpAddress + 0x7000;
    
    if (lpAddress <= edx)
    {
        void* eax_5 = lpAddress + 0x10;
        int32_t i_3 = ((edx - lpAddress) >> 0xc) + 1;
        int32_t i_2;
        
        do
        {
            *(eax_5 - 8) = 0xffffffff;
            *(eax_5 + 0xfec) = 0xffffffff;
            *eax_5 = eax_5 + 0xffc;
            *(eax_5 - 4) = 0xff0;
            *(eax_5 + 4) = eax_5 - 0x1004;
            *(eax_5 + 0xfe8) = 0xff0;
            eax_5 += 0x1000;
            i_2 = i_3;
            i_3 -= 1;
        } while (i_2 != 1);
    }
    
    *(var_c_1 + 0x1fc) = lpAddress + 0xc;
    *(lpAddress + 0x14) = var_c_1 + 0x1f8;
    *(var_c_1 + 0x200) = edx + 0xc;
    *(edx + 0x10) = var_c_1 + 0x1f8;
    *(esi + (result << 2) + 0x44) = 0;
    *(esi + (result << 2) + 0xc4) = 1;
    void* eax_7;
    eax_7 = *(esi + 0x43);
    void* ecx_6;
    ecx_6 = eax_7;
    ecx_6 += 1;
    *(esi + 0x43) = ecx_6;
    
    if (!eax_7)
        *(arg1 + 4) |= 1;
    
    *(arg1 + 8) &= ~(0x80000000 >> result);
    return result;
}

int32_t sub_402bfe(int32_t* arg1, void** arg2, void* arg3)
{
    int32_t eax = arg1[4];
    uint32_t edx_2 = (arg2 - arg1[3]) >> 0xf;
    void* esi_2 = (arg3 + 0x17) & 0xfffffff0;
    void* ecx_5 = arg2[-1] - 1;
    void* edi_1 = ecx_5 + arg2 - 4;
    void* ebx = *edi_1;
    
    if (esi_2 > ecx_5)
    {
        if (ebx & 1 || esi_2 > ebx + ecx_5)
            return 0;
        
        int32_t ecx_8 = (ebx >> 4) - 1;
        int32_t var_c_1 = ecx_8;
        
        if (ecx_8 > 0x3f)
        {
            ecx_8 = 0x3f;
            var_c_1 = 0x3f;
        }
        
        if (*(edi_1 + 4) == *(edi_1 + 8))
        {
            if (ecx_8 >= 0x20)
            {
                uint32_t ebx_6 = ~(0x80000000 >> (ecx_8 - 0x20));
                *(eax + (edx_2 << 2) + 0xc4) &= ebx_6;
                char temp0_1 = *(var_c_1 + eax + 4);
                *(var_c_1 + eax + 4) -= 1;
                
                if (temp0_1 == 1)
                    arg1[1] &= ebx_6;
            }
            else
            {
                uint32_t ebx_4 = ~(0x80000000 >> ecx_8);
                *(eax + (edx_2 << 2) + 0x44) &= ebx_4;
                char temp1_1 = *(var_c_1 + eax + 4);
                *(var_c_1 + eax + 4) -= 1;
                
                if (temp1_1 == 1)
                    *arg1 &= ebx_4;
            }
        }
        
        *(*(edi_1 + 8) + 4) = *(edi_1 + 4);
        *(*(edi_1 + 4) + 8) = *(edi_1 + 8);
        void* var_8_1 = ebx + ecx_5 - esi_2;
        void** edx_4;
        
        if (var_8_1 <= 0)
            edx_4 = arg2;
        else
        {
            int32_t edi_5 = (var_8_1 >> 4) - 1;
            
            if (edi_5 > 0x3f)
                edi_5 = 0x3f;
            
            void* ebx_9 = edx_2 * 0x204 + eax + 0x144 + (edi_5 << 3);
            *(arg2 + esi_2) = *(ebx_9 + 4);
            *(arg2 + esi_2 + 4) = ebx_9;
            *(ebx_9 + 4) = arg2 + esi_2 - 4;
            *(*(arg2 + esi_2) + 8) = arg2 + esi_2 - 4;
            
            if (*(arg2 + esi_2) == *(arg2 + esi_2 + 4))
            {
                void* ecx_21;
                ecx_21 = *(edi_5 + eax + 4);
                *arg3[3] = ecx_21;
                ecx_21 += 1;
                *(edi_5 + eax + 4) = ecx_21;
                int32_t* eax_1;
                char ecx_24;
                
                if (edi_5 >= 0x20)
                {
                    if (!*arg3[3])
                        arg1[1] |= 0x80000000 >> (edi_5 - 0x20);
                    
                    eax_1 = eax + (edx_2 << 2) + 0xc4;
                    ecx_24 = edi_5 - 0x20;
                }
                else
                {
                    if (!*arg3[3])
                        *arg1 |= 0x80000000 >> edi_5;
                    
                    eax_1 = eax + (edx_2 << 2) + 0x44;
                    ecx_24 = edi_5;
                }
                
                *eax_1 |= 0x80000000 >> ecx_24;
            }
            
            edx_4 = arg2;
            *(edx_4 + esi_2 - 4) = var_8_1;
            *(var_8_1 + edx_4 + esi_2 - 4 - 4) = var_8_1;
        }
        
        edx_4[-1] = esi_2 + 1;
        *(edx_4 + esi_2 - 8) = esi_2 + 1;
    }
    else if (esi_2 < ecx_5)
    {
        arg3 = ecx_5 - esi_2;
        arg2[-1] = esi_2 + 1;
        void** ebx_17 = arg2 + esi_2 - 4;
        int32_t esi_5 = (arg3 >> 4) - 1;
        ebx_17[-1] = esi_2 + 1;
        
        if (esi_5 > 0x3f)
            esi_5 = 0x3f;
        
        if (!(ebx & 1))
        {
            int32_t esi_8 = (ebx >> 4) - 1;
            
            if (esi_8 > 0x3f)
                esi_8 = 0x3f;
            
            if (*(edi_1 + 4) == *(edi_1 + 8))
            {
                if (esi_8 >= 0x20)
                {
                    uint32_t ebx_21 = ~(0x80000000 >> (esi_8 - 0x20));
                    *(eax + (edx_2 << 2) + 0xc4) &= ebx_21;
                    char temp2_1 = *(esi_8 + eax + 4);
                    *(esi_8 + eax + 4) -= 1;
                    
                    if (temp2_1 == 1)
                        arg1[1] &= ebx_21;
                }
                else
                {
                    uint32_t ebx_19 = ~(0x80000000 >> esi_8);
                    *(eax + (edx_2 << 2) + 0x44) &= ebx_19;
                    char temp3_1 = *(esi_8 + eax + 4);
                    *(esi_8 + eax + 4) -= 1;
                    
                    if (temp3_1 == 1)
                        *arg1 &= ebx_19;
                }
            }
            
            *(*(edi_1 + 8) + 4) = *(edi_1 + 4);
            *(*(edi_1 + 4) + 8) = *(edi_1 + 8);
            void* esi_13 = arg3 + ebx;
            arg3 = esi_13;
            esi_5 = (esi_13 >> 4) - 1;
            
            if (esi_5 > 0x3f)
                esi_5 = 0x3f;
        }
        
        void* ecx_38 = edx_2 * 0x204 + eax + 0x144 + (esi_5 << 3);
        int32_t edi_6 = *(ecx_38 + 4);
        ebx_17[2] = ecx_38;
        ebx_17[1] = edi_6;
        *(ecx_38 + 4) = ebx_17;
        *(ebx_17[1] + 8) = ebx_17;
        
        if (ebx_17[1] == ebx_17[2])
        {
            int32_t ecx_40;
            ecx_40 = *(esi_5 + eax + 4);
            *arg2[3] = ecx_40;
            ecx_40 += 1;
            *(esi_5 + eax + 4) = ecx_40;
            int32_t* eax_5;
            char ecx_43;
            
            if (esi_5 >= 0x20)
            {
                if (!*arg2[3])
                    arg1[1] |= 0x80000000 >> (esi_5 - 0x20);
                
                eax_5 = eax + (edx_2 << 2) + 0xc4;
                ecx_43 = esi_5 - 0x20;
            }
            else
            {
                if (!*arg2[3])
                    *arg1 |= 0x80000000 >> esi_5;
                
                eax_5 = eax + (edx_2 << 2) + 0x44;
                ecx_43 = esi_5;
            }
            
            *eax_5 |= 0x80000000 >> ecx_43;
        }
        
        *ebx_17 = arg3;
        *(arg3 + ebx_17 - 4) = arg3;
    }
    
    return 1;
}

void* sub_402edd(int32_t* arg1)
{
    int32_t eax_2 = data_410d5c * 0x14 + data_410d60;
    void* ecx_2 = (arg1 + 0x17) & 0xfffffff0;
    uint32_t var_c;
    uint32_t esi;
    
    if ((ecx_2 >> 4) - 1 >= 0x20)
    {
        esi = 0;
        var_c = 0xffffffff >> (((ecx_2 >> 4) - 1) - 0x20);
    }
    else
    {
        esi = 0xffffffff >> ((ecx_2 >> 4) - 1);
        var_c = 0xffffffff;
    }
    
    int32_t* ecx_6 = data_410d68;
    int32_t* ebx = ecx_6;
    
    while (true)
    {
        arg1 = ebx;
        
        if (ebx >= eax_2)
            break;
        
        if ((ebx[1] & var_c) | (*ebx & esi))
            break;
        
        ebx = &ebx[5];
    }
    
    if (ebx == eax_2)
    {
        ebx = data_410d60;
        
        while (true)
        {
            arg1 = ebx;
            
            if (ebx >= ecx_6)
                break;
            
            if ((ebx[1] & var_c) | (*ebx & esi))
                break;
            
            ebx = &ebx[5];
        }
        
        if (ebx == ecx_6)
        {
            while (ebx < eax_2)
            {
                if (ebx[2])
                    break;
                
                ebx = &ebx[5];
                arg1 = ebx;
            }
            
            if (ebx == eax_2)
            {
                ebx = data_410d60;
                
                while (true)
                {
                    arg1 = ebx;
                    
                    if (ebx >= ecx_6)
                        break;
                    
                    if (ebx[2])
                        break;
                    
                    ebx = &ebx[5];
                }
                
                if (ebx == ecx_6)
                {
                    ebx = sub_402a48();
                    arg1 = ebx;
                    
                    if (!ebx)
                        return nullptr;
                }
            }
            
            *ebx[4] = sub_402af8(ebx);
            
            if (*ebx[4] == 0xffffffff)
                return nullptr;
        }
    }
    
    data_410d68 = ebx;
    int32_t* eax_6 = ebx[4];
    int32_t edx_8 = *eax_6;
    int32_t var_8_1 = edx_8;
    
    if (edx_8 == 0xffffffff || !((eax_6[edx_8 + 0x31] & var_c) | (eax_6[edx_8 + 0x11] & esi)))
    {
        var_8_1 = 0;
        int32_t edx_9 = eax_6[0x31];
        void* ecx_11 = &eax_6[0x11];
        
        while (!((edx_9 & var_c) | (*ecx_11 & esi)))
        {
            var_8_1 += 1;
            edx_9 = *(ecx_11 + 0x84);
            ecx_11 += 4;
        }
        
        edx_8 = var_8_1;
    }
    
    int32_t edi_9 = 0;
    int32_t i = eax_6[edx_8 + 0x11] & esi;
    
    if (!i)
    {
        i = eax_6[edx_8 + 0x31] & var_c;
        edi_9 = 0x20;
    }
    
    while (i >= 0)
    {
        i *= 2;
        edi_9 += 1;
    }
    
    int32_t* edx_12 = eax_6[edx_8 * 0x81 + 0x51 + edi_9 * 2 + 1];
    void* ecx_19 = *edx_12 - ecx_2;
    int32_t esi_3 = (ecx_19 >> 4) - 1;
    
    if (esi_3 > 0x3f)
        esi_3 = 0x3f;
    
    if (esi_3 == edi_9)
    {
    label_40316e:
        
        if (ecx_19)
        {
            *edx_12 = ecx_19;
            *(ecx_19 + edx_12 - 4) = ecx_19;
        }
    }
    else
    {
        if (edx_12[1] == edx_12[2])
        {
            if (edi_9 >= 0x20)
            {
                uint32_t ebx_5 = ~(0x80000000 >> (edi_9 - 0x20));
                eax_6[var_8_1 + 0x31] &= ebx_5;
                char temp0_1 = *(eax_6 + edi_9 + 4);
                *(eax_6 + edi_9 + 4) -= 1;
                
                if (temp0_1 != 1)
                    ebx = arg1;
                else
                {
                    ebx = arg1;
                    ebx[1] &= ebx_5;
                }
            }
            else
            {
                uint32_t ebx_2 = ~(0x80000000 >> edi_9);
                eax_6[var_8_1 + 0x11] &= ebx_2;
                char temp1_1 = *(eax_6 + edi_9 + 4);
                *(eax_6 + edi_9 + 4) -= 1;
                
                if (temp1_1 != 1)
                    ebx = arg1;
                else
                {
                    ebx = arg1;
                    *ebx &= ebx_2;
                }
            }
        }
        
        *(edx_12[2] + 4) = edx_12[1];
        *(edx_12[1] + 8) = edx_12[2];
        
        if (ecx_19)
        {
            void* ecx_31 = &eax_6[edx_8 * 0x81 + 0x51 + esi_3 * 2];
            int32_t edi_14 = *(ecx_31 + 4);
            edx_12[2] = ecx_31;
            edx_12[1] = edi_14;
            *(ecx_31 + 4) = edx_12;
            *(edx_12[1] + 8) = edx_12;
            
            if (edx_12[1] == edx_12[2])
            {
                int32_t ecx_33;
                ecx_33 = *(esi_3 + eax_6 + 4);
                *arg1[3] = ecx_33;
                ecx_33 += 1;
                *(esi_3 + eax_6 + 4) = ecx_33;
                
                if (esi_3 >= 0x20)
                {
                    if (!*arg1[3])
                        ebx[1] |= 0x80000000 >> (esi_3 - 0x20);
                    
                    eax_6[var_8_1 + 0x31] |= 0x80000000 >> (esi_3 - 0x20);
                }
                else
                {
                    if (!*arg1[3])
                        *ebx |= 0x80000000 >> esi_3;
                    
                    eax_6[var_8_1 + 0x11] |= 0x80000000 >> esi_3;
                }
            }
            
            goto label_40316e;
        }
    }
    
    void** edx_13 = edx_12 + ecx_19;
    *edx_13 = ecx_2 + 1;
    *(edx_13 + ecx_2 - 4) = ecx_2 + 1;
    int32_t ecx_41 = eax_6[edx_8 * 0x81 + 0x51];
    eax_6[edx_8 * 0x81 + 0x51] = ecx_41 + 1;
    
    if (!ecx_41 && ebx == data_410308 && var_8_1 == data_410d70)
        data_410308 = 0;
    
    *eax_6 = var_8_1;
    return &edx_13[1];
}

void __SEH_prolog4(int32_t arg1 @ esi, int32_t arg2 @ edi, void* arg3)
{
    int32_t (* var_4)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t arg_8;
    int32_t eax = arg_8;
    int32_t ebp;
    arg_8 = ebp;
    void* esp = &ExceptionList - eax;
    int32_t entry_ebx;
    *(esp - 4) = entry_ebx;
    *(esp - 8) = arg1;
    *(esp - 0xc) = arg2;
    uint32_t __security_cookie_1 = __security_cookie;
    *(esp - 0x10) = __security_cookie_1 ^ &arg_8;
    void* var_10 = esp - 0x10;
    *(esp - 0x14) = __return_addr;
    void* __return_addr_1 = arg3 ^ __security_cookie_1;
    arg3 = 0xfffffffe;
    __return_addr = __return_addr_1;
    fsbase->NtTib.ExceptionList = &ExceptionList;
}

int32_t __SEH_epilog4(int32_t* arg1 @ ebp, int32_t arg2, int32_t arg3, int32_t arg4)
{
    TEB* fsbase;
    fsbase->NtTib.ExceptionList = arg1[-4];
    *arg1;
    *arg1 = __return_addr;
}

int32_t sub_403220(int32_t* arg1, void* arg2, int32_t arg3)
{
    int32_t* esi_1 = *(arg2 + 8) ^ __security_cookie;
    int32_t eax = *esi_1;
    char var_11 = 0;
    int32_t result = 1;
    
    if (eax != 0xfffffffe)
        sub_4076f5((esi_1[1] + arg2 + 0x10) ^ *(eax + arg2 + 0x10));
    
    sub_4076f5((esi_1[3] + arg2 + 0x10) ^ *(esi_1[2] + arg2 + 0x10));
    
    if (!(arg1[1] & 0x66))
    {
        int32_t i_1 = *(arg2 + 0xc);
        int32_t* var_8 = arg1;
        int32_t var_4_1 = arg3;
        *(arg2 - 4) = &var_8;
        
        if (i_1 != 0xfffffffe)
        {
            int32_t i;
            
            do
            {
                int32_t eax_3 = i_1 * 3;
                i = esi_1[eax_3 + 4];
                
                if (esi_1[eax_3 + 5])
                {
                    int32_t eax_4 = @_EH4_CallFilterFunc@8();
                    var_11 = 1;
                    
                    if (eax_4 < 0)
                    {
                        result = 0;
                        goto label_4032cb;
                    }
                    
                    if (eax_4 > 0)
                    {
                        if (*arg1 == 0xe06d7363 && data_410d58 && sub_407782(&data_410d58))
                            data_410d58(arg1, 1);
                        
                        sub_4059aa(arg2);
                        void* eax_9 = arg2;
                        
                        if (*(eax_9 + 0xc) != i_1)
                        {
                            @_EH4_LocalUnwind@16(eax_9, i_1, arg2 + 0x10, &__security_cookie);
                            eax_9 = arg2;
                        }
                        
                        *(eax_9 + 0xc) = i;
                        int32_t eax_10 = *esi_1;
                        
                        if (eax_10 != 0xfffffffe)
                            sub_4076f5((esi_1[1] + arg2 + 0x10) ^ *(eax_10 + arg2 + 0x10));
                        
                        sub_4076f5((esi_1[3] + arg2 + 0x10) ^ *(esi_1[2] + arg2 + 0x10));
                        int32_t ecx_25 = esi_1[eax_3 + 6];
                        __NLG_Notify(ecx_25, arg2 + 0x10, 1);
                        /* jump -> ecx_25 */
                    }
                }
                
                i_1 = i;
            } while (i != 0xfffffffe);
            
            if (var_11)
                goto label_4032cb;
        }
    }
    else if (*(arg2 + 0xc) != 0xfffffffe)
    {
        @_EH4_LocalUnwind@16(arg2, 0xfffffffe, arg2 + 0x10, &__security_cookie);
    label_4032cb:
        int32_t eax_5 = *esi_1;
        
        if (eax_5 != 0xfffffffe)
            sub_4076f5((esi_1[1] + arg2 + 0x10) ^ *(eax_5 + arg2 + 0x10));
        
        sub_4076f5((esi_1[3] + arg2 + 0x10) ^ *(esi_1[2] + arg2 + 0x10));
    }
    
    return result;
}

uint32_t sub_4033b6(int32_t* arg1)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t* eax = sub_403bb8(arg1);
    int32_t eax_1 = arg1[3];
    
    if (eax_1 & 0x82)
    {
        if (!(eax_1 & 0x40))
        {
            if (eax_1 & 1)
            {
                arg1[1] = 0;
                
                if (!(eax_1 & 0x10))
                {
                    arg1[3] = eax_1 | 0x20;
                    return 0xffffffff;
                }
                
                *arg1 = arg1[2];
                arg1[3] = eax_1 & 0xfffffffe;
            }
            
            int32_t eax_8 = (arg1[3] & 0xffffffef) | 2;
            arg1[3] = eax_8;
            arg1[1] = 0;
            void* var_8_1 = nullptr;
            
            if (!(eax_8 & 0x10c))
            {
                bool cond:5_1;
                
                if (arg1 == 0x40f158 || arg1 == 0x40f178)
                    cond:5_1 = sub_4079ce(eax);
                
                if ((arg1 != 0x40f158 && arg1 != 0x40f178) || !cond:5_1)
                    sub_40798a(arg1);
            }
            
            int32_t arg_4;
            uint32_t edi_2;
            
            if (!(arg1[3] & 0x108))
            {
                edi_2 = 1;
                var_8_1 = sub_403adc(eax, &arg_4, 1);
            label_4034fb:
                
                if (var_8_1 == edi_2)
                    return arg_4;
            }
            else
            {
                uint8_t* eax_10 = arg1[2];
                int32_t edi_1 = *arg1;
                *arg1 = &eax_10[1];
                edi_2 = edi_1 - eax_10;
                arg1[1] = arg1[6] - 1;
                int32_t* ecx_8;
                
                if (edi_2 > 0)
                {
                    void* eax_11;
                    eax_11 = sub_403adc(eax, eax_10, edi_2);
                    var_8_1 = eax_11;
                label_4034de:
                    ecx_8 = arg_4;
                    *arg1[2] = ecx_8;
                    goto label_4034fb;
                }
                
                void* eax_16;
                
                if (eax == 0xffffffff || eax == 0xfffffffe)
                    eax_16 = &data_40f820;
                else
                    eax_16 = (eax & 0x1f) * 0x28 + (&data_410c40)[eax >> 5];
                
                if (!(*(eax_16 + 4) & 0x20))
                    goto label_4034de;
                
                uint32_t eax_17;
                int32_t edx_3;
                eax_17 = sub_407871(eax, 0, 0, FILE_END);
                
                if ((eax_17 & edx_3) != 0xffffffff)
                    goto label_4034de;
            }
            arg1[3] |= 0x20;
            return 0xffffffff;
        }
        
        *__errno() = 0x22;
    }
    else
        *__errno() = 9;
    
    arg1[3] |= 0x20;
    return 0xffffffff;
}

void* sub_403516(int32_t arg1, uint8_t* arg2, uint32_t arg3)
{
    void var_51c;
    int32_t eax_1 = __security_cookie ^ &var_51c;
    void* numberOfBytesWritten_8 = nullptr;
    int32_t var_584 = 0;
    void* result;
    
    if (!arg3)
        result = nullptr;
    else if (arg2)
    {
        int32_t* ebx_3 = (arg1 & 0x1f) * 0x28;
        void* edi_1 = &(&data_410c40)[arg1 >> 5];
        void* eax_8 = *edi_1 + ebx_3;
        int32_t ecx;
        ecx = *(eax_8 + 0x24);
        ecx *= 2;
        ecx s>>= 1;
        void* var_58c_1 = edi_1;
        char var_571_1 = ecx;
        
        if (ecx == 2 || ecx == 1)
        {
            ecx = ~arg3;
            
            if (ecx & 1)
                goto label_4035eb;
            
            *___doserrno() = 0;
            *__errno() = 0x16;
            sub_4041db(0, 0, 0, 0, 0);
            result = 0xffffffff;
        }
        else
        {
        label_4035eb:
            int32_t edx;
            
            if (*(eax_8 + 4) & 0x20)
                sub_4077ee(eax_8, edx, ecx, arg1, 0, 0, FILE_END);
            bool cond:2_1 = !sub_4079ce(arg1);
            enum CONSOLE_MODE var_598;
            BOOL eax_16;
            int32_t ecx_3;
            
            if (!cond:2_1 && *(ebx_3 + *edi_1 + 4) & 0x80)
            {
                ecx_3 = !*(*(__getptd() + 0x6c) + 0x14);
                eax_16 = GetConsoleMode(*(ebx_3 + *edi_1), &var_598);
            }
            
            enum WIN32_ERROR wideCharStr;
            uint32_t numberOfBytesWritten_1;
            
            if (!cond:2_1 && *(ebx_3 + *edi_1 + 4) & 0x80 && eax_16 && (!ecx_3 || var_571_1))
            {
                uint32_t eax_17 = GetConsoleCP();
                numberOfBytesWritten_1 = 0;
                char* esi_3 = arg2;
                var_598 = eax_17;
                void* var_590_1 = esi_3;
                
                if (arg3 <= 0)
                    goto label_403a6e;
                
                int32_t var_578_1 = 0;
                
                while (true)
                {
                    eax_17 = var_571_1;
                    int32_t var_594;
                    
                    if (eax_17)
                    {
                        if (eax_17 == 1 || eax_17 == 2)
                        {
                            enum WIN32_ERROR wideCharStr_3 = *esi_3;
                            int32_t edx_1;
                            edx_1 = wideCharStr_3 == 0xa;
                            var_578_1 += 2;
                            wideCharStr = wideCharStr_3;
                            var_590_1 = &esi_3[2];
                            var_594 = edx_1;
                        }
                        
                        if (eax_17 == 1 || eax_17 == 2)
                        {
                            enum WIN32_ERROR wideCharStr_2 = wideCharStr;
                            
                            if (sub_407a2c() != wideCharStr)
                                goto label_403a61;
                            
                            numberOfBytesWritten_8 += 1;
                            
                            if (var_594)
                            {
                                wideCharStr = ERROR_INVALID_DATA;
                                
                                if (sub_407a2c() != wideCharStr)
                                    goto label_403a61;
                                
                                numberOfBytesWritten_8 += 1;
                                var_584 += 1;
                            }
                        }
                    }
                    else
                    {
                        eax_17 = *esi_3;
                        int32_t ecx_4;
                        ecx_4 = eax_17 == 0xa;
                        var_594 = ecx_4;
                        
                        if (sub_407c4e(eax_17))
                        {
                            if (arg2 - esi_3 + arg3 <= 1)
                                break;
                            
                            if (sub_407c01(&wideCharStr, esi_3, 2) == 0xffffffff)
                                break;
                            
                            esi_3 = &esi_3[1];
                            var_578_1 += 1;
                        }
                        else if (sub_407c01(&wideCharStr, esi_3, 1) == 0xffffffff)
                            break;
                        
                        var_578_1 += 1;
                        var_590_1 = &esi_3[1];
                        uint8_t var_10;
                        int32_t nNumberOfBytesToWrite = WideCharToMultiByte(var_598, 0, 
                            &wideCharStr, 1, &var_10, 5, nullptr, nullptr);
                        
                        if (!nNumberOfBytesToWrite)
                            break;
                        
                        if (!WriteFile(*(ebx_3 + *edi_1), &var_10, nNumberOfBytesToWrite, 
                                &numberOfBytesWritten_1, nullptr))
                            goto label_403a61;
                        
                        uint32_t numberOfBytesWritten_2 = numberOfBytesWritten_1;
                        numberOfBytesWritten_8 += numberOfBytesWritten_2;
                        
                        if (numberOfBytesWritten_2 < nNumberOfBytesToWrite)
                            break;
                        
                        if (var_594)
                        {
                            int32_t eax_27 = *edi_1;
                            var_10 = 0xd;
                            
                            if (!WriteFile(*(ebx_3 + eax_27), &var_10, 1, &numberOfBytesWritten_1, 
                                    nullptr))
                                goto label_403a61;
                            
                            if (numberOfBytesWritten_1 < 1)
                                break;
                            
                            var_584 += 1;
                            numberOfBytesWritten_8 += 1;
                        }
                    }
                    
                    if (var_578_1 >= arg3)
                        break;
                    
                    esi_3 = var_590_1;
                }
                
                goto label_403a67;
            }
            
            HANDLE* eax_32 = *edi_1 + ebx_3;
            uint32_t numberOfBytesWritten;
            int32_t esi_8;
            
            if (!(eax_32[1] & 0x80))
            {
                if (!WriteFile(*eax_32, arg2, arg3, &numberOfBytesWritten, nullptr))
                {
                label_403a61:
                    wideCharStr = GetLastError();
                    goto label_403a67;
                }
                
                void* numberOfBytesWritten_5 = numberOfBytesWritten;
                wideCharStr = NO_ERROR;
                numberOfBytesWritten_8 = numberOfBytesWritten_5;
            label_403a67:
                
                if (numberOfBytesWritten_8)
                    result = numberOfBytesWritten_8 - var_584;
                else
                {
                    edi_1 = var_58c_1;
                label_403a6e:
                    esi_8 = 0;
                    
                    if (!wideCharStr)
                        goto label_403a97;
                    
                    if (wideCharStr != ERROR_ACCESS_DENIED)
                    {
                        sub_402447(wideCharStr);
                        result = 0xffffffff;
                    }
                    else
                    {
                        *__errno() = 9;
                        *___doserrno() = 5;
                        result = 0xffffffff;
                    }
                }
            }
            else
            {
                esi_8 = 0;
                wideCharStr = NO_ERROR;
                uint8_t buffer[0x4c];
                
                if (var_571_1)
                {
                    if (var_571_1 == 2)
                    {
                        numberOfBytesWritten_1 = arg2;
                        
                        if (arg3 <= 0)
                            goto label_403a97;
                        
                        do
                        {
                            int32_t esi_10 = 0;
                            void* ecx_11 = numberOfBytesWritten_1 - arg2;
                            uint8_t (* eax_39)[0x4c] = &buffer;
                            
                            while (ecx_11 < arg3)
                            {
                                uint32_t numberOfBytesWritten_7 = numberOfBytesWritten_1;
                                numberOfBytesWritten_1 += 2;
                                int16_t edx_2 = *numberOfBytesWritten_7;
                                ecx_11 += 2;
                                
                                if (edx_2 == 0xa)
                                {
                                    var_584 += 2;
                                    *eax_39 = 0xd;
                                    eax_39 = &(*eax_39)[2];
                                    esi_10 += 2;
                                }
                                
                                edi_1 = var_58c_1;
                                *eax_39 = edx_2;
                                eax_39 = &(*eax_39)[2];
                                esi_10 += 2;
                                
                                if (esi_10 >= 0x3ff)
                                    break;
                            }
                            
                            uint32_t nNumberOfBytesToWrite_2 = eax_39 - &buffer;
                            
                            if (!WriteFile(*(ebx_3 + *edi_1), &buffer, nNumberOfBytesToWrite_2, 
                                    &numberOfBytesWritten, nullptr))
                                goto label_403a61;
                            
                            uint32_t numberOfBytesWritten_4 = numberOfBytesWritten;
                            numberOfBytesWritten_8 += numberOfBytesWritten_4;
                            
                            if (numberOfBytesWritten_4 < nNumberOfBytesToWrite_2)
                                break;
                        } while (numberOfBytesWritten_1 - arg2 < arg3);
                        
                        goto label_403a67;
                    }
                    
                    uint8_t* var_578_3 = arg2;
                    
                    if (arg3 <= 0)
                        goto label_403a97;
                    
                    void* numberOfBytesWritten_9;
                    
                    do
                    {
                        numberOfBytesWritten_1 = 0;
                        void* ecx_14 = var_578_3 - arg2;
                        wchar16 wideCharStr_1[0xaa];
                        wchar16 (* eax_46)[0xaa] = &wideCharStr_1;
                        
                        while (ecx_14 < arg3)
                        {
                            int16_t edx_4 = *var_578_3;
                            var_578_3 = &var_578_3[2];
                            ecx_14 += 2;
                            
                            if (edx_4 == 0xa)
                            {
                                *eax_46 = 0xd;
                                eax_46 = &(*eax_46)[1];
                                numberOfBytesWritten_1 += 2;
                            }
                            
                            numberOfBytesWritten_1 += 2;
                            *eax_46 = edx_4;
                            eax_46 = &(*eax_46)[1];
                            
                            if (numberOfBytesWritten_1 >= 0x152)
                                break;
                        }
                        
                        int32_t esi_14 = 0;
                        int32_t eax_48;
                        int32_t edx_5;
                        edx_5 = HIGHD(eax_46 - &wideCharStr_1);
                        eax_48 = LOWD(eax_46 - &wideCharStr_1);
                        void multiByteStr;
                        int32_t eax_51 = WideCharToMultiByte(0xfde9, 0, &wideCharStr_1, 
                            (eax_48 - edx_5) >> 1, &multiByteStr, 0x2ab, nullptr, nullptr);
                        
                        if (!eax_51)
                            goto label_403a61;
                        
                        do
                        {
                            if (!WriteFile(*(ebx_3 + *var_58c_1), &var_51c + esi_14 + 0x108, 
                                eax_51 - esi_14, &numberOfBytesWritten, nullptr))
                            {
                                wideCharStr = GetLastError();
                                break;
                            }
                            
                            esi_14 += numberOfBytesWritten;
                        } while (eax_51 > esi_14);
                        
                        if (eax_51 > esi_14)
                            break;
                        
                        numberOfBytesWritten_9 = var_578_3 - arg2;
                        numberOfBytesWritten_8 = numberOfBytesWritten_9;
                    } while (numberOfBytesWritten_9 < arg3);
                    goto label_403a67;
                }
                
                numberOfBytesWritten_1 = arg2;
                
                if (arg3 > 0)
                {
                    do
                    {
                        int32_t var_578_2 = 0;
                        void* ecx_9 = numberOfBytesWritten_1 - arg2;
                        uint8_t (* eax_34)[0x4c] = &buffer;
                        
                        while (ecx_9 < arg3)
                        {
                            uint32_t numberOfBytesWritten_6 = numberOfBytesWritten_1;
                            numberOfBytesWritten_1 += 1;
                            numberOfBytesWritten_6 = *numberOfBytesWritten_6;
                            ecx_9 += 1;
                            
                            if (numberOfBytesWritten_6 == 0xa)
                            {
                                var_584 += 1;
                                *eax_34 = 0xd;
                                eax_34 = &(*eax_34)[1];
                                var_578_2 += 1;
                            }
                            
                            *eax_34 = numberOfBytesWritten_6;
                            eax_34 = &(*eax_34)[1];
                            var_578_2 += 1;
                            
                            if (var_578_2 >= 0x400)
                                break;
                        }
                        
                        uint32_t nNumberOfBytesToWrite_1 = eax_34 - &buffer;
                        
                        if (!WriteFile(*(ebx_3 + *edi_1), &buffer, nNumberOfBytesToWrite_1, 
                                &numberOfBytesWritten, nullptr))
                            goto label_403a61;
                        
                        uint32_t numberOfBytesWritten_3 = numberOfBytesWritten;
                        numberOfBytesWritten_8 += numberOfBytesWritten_3;
                        
                        if (numberOfBytesWritten_3 < nNumberOfBytesToWrite_1)
                            break;
                    } while (numberOfBytesWritten_1 - arg2 < arg3);
                    
                    goto label_403a67;
                }
                
            label_403a97:
                
                if (!(*(ebx_3 + *edi_1 + 4) & 0x40) || *arg2 != 0x1a)
                {
                    *__errno() = 0x1c;
                    *___doserrno() = esi_8;
                    result = 0xffffffff;
                }
                else
                    result = nullptr;
            }
        }
    }
    else
    {
        *___doserrno() = 0;
        *__errno() = 0x16;
        sub_4041db(0, 0, 0, 0, 0);
        result = 0xffffffff;
    }
    
    sub_4076f5(eax_1 ^ &var_51c);
    return result;
}

void* sub_403adc(int32_t arg1, uint8_t* arg2, uint32_t arg3)
{
    int32_t __saved_ebp_1 = 0x10;
    int32_t var_8 = 0x40e520;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e520 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_34 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_34;
    void* const var_38_2 = &data_403ae8;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    void* result;
    
    if (arg1 != 0xfffffffe)
    {
        int32_t esi_3;
        
        if (arg1 >= 0 && arg1 < data_410c24)
            esi_3 = (arg1 & 0x1f) * 0x28;
        
        if (arg1 < 0 || arg1 >= data_410c24 || !(*((&data_410c40)[arg1 >> 5] + esi_3 + 4) & 1))
        {
            *___doserrno() = 0;
            *__errno() = 9;
            sub_4041db(0, 0, 0, 0, 0);
            result = 0xffffffff;
        }
        else
        {
            sub_407dcb(arg1);
            int32_t var_8_1 = 0;
            void* result_1;
            
            if (!(*((&data_410c40)[arg1 >> 5] + esi_3 + 4) & 1))
            {
                *__errno() = 9;
                *___doserrno() = 0;
                result_1 = 0xffffffff;
            }
            else
                result_1 = sub_403516(arg1, arg2, arg3);
            
            int32_t var_8_2 = 0xfffffffe;
            sub_403bae(&__saved_ebp);
            result = result_1;
        }
    }
    else
    {
        *___doserrno() = 0;
        *__errno() = 9;
        result = 0xffffffff;
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_403bad;
    return result;
}

int32_t sub_403bae(void* arg1 @ ebp)
{
    return sub_407e6b(*(arg1 + 8));
}

int32_t sub_403bb8(void* arg1)
{
    if (arg1)
        return *(arg1 + 0x10);
    
    *__errno() = 0x16;
    sub_4041db(0, 0, 0, 0, 0);
    return 0xffffffff;
}

int32_t sub_403be5(int32_t* arg1)
{
    int16_t eax = arg1[3];
    int32_t result = 0;
    
    if ((eax & 3) == 2 && eax & 0x108)
    {
        uint8_t* eax_1 = arg1[2];
        uint32_t edi_2 = *arg1 - eax_1;
        
        if (edi_2 > 0)
        {
            if (sub_403adc(sub_403bb8(arg1), eax_1, edi_2) != edi_2)
            {
                arg1[3] |= 0x20;
                result = 0xffffffff;
            }
            else
            {
                int32_t eax_4 = arg1[3];
                
                if (eax_4 < 0)
                    arg1[3] = eax_4 & 0xfffffffd;
            }
        }
    }
    
    int32_t eax_6 = arg1[2];
    arg1[1] = 0;
    *arg1 = eax_6;
    return result;
}

int32_t sub_403c47(int32_t* arg1)
{
    if (!arg1)
        return sub_403c89(arg1);
    
    if (sub_403be5(arg1))
        return 0xffffffff;
    
    if (!(arg1[3] & 0x4000))
        return 0;
    
    enum WIN32_ERROR eax_4 = sub_40802c(sub_403bb8(arg1));
    int32_t eax_5 = -(eax_4);
    return eax_5 - eax_5;
}

int32_t sub_403c89(int32_t arg1)
{
    int32_t __saved_ebp_1 = 0x14;
    int32_t var_8 = 0x40e540;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_5 = 0x40e540 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_38 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_38;
    void* const var_3c_3 = &data_403c95;
    int32_t var_8_6 = 0xfffffffe;
    int32_t var_c = var_8_5;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t result_2 = 0;
    int32_t result_1 = 0;
    sub_402690(1);
    int32_t var_8_1 = 0;
    int32_t esi = 0;
    
    while (true)
    {
        int32_t var_24_1 = esi;
        
        if (esi >= data_411d80)
            break;
        
        int32_t* eax_1 = data_410d7c + (esi << 2);
        
        if (*eax_1)
        {
            int32_t eax_2 = *eax_1;
            
            if (*(eax_2 + 0xc) & 0x83)
            {
                sub_40214c(esi, eax_2);
                int32_t var_8_2 = 1;
                int32_t* eax_4 = *(data_410d7c + (esi << 2));
                char ecx_1 = eax_4[3];
                
                if (ecx_1 & 0x83)
                {
                    if (arg1 == 1)
                    {
                        if (sub_403c47(eax_4) != 0xffffffff)
                            result_2 += 1;
                    }
                    else if (!arg1 && ecx_1 & 2)
                    {
                        int32_t eax_6 = sub_403c47(eax_4);
                        
                        if (eax_6 == 0xffffffff)
                            result_1 |= eax_6;
                    }
                }
                
                int32_t var_8_3 = 0;
                sub_403d2b(esi);
            }
        }
        
        esi += 1;
    }
    
    int32_t var_8_4 = 0xfffffffe;
    sub_403d5a();
    int32_t result = result_2;
    
    if (arg1 != 1)
        result = result_1;
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_403d59;
    return result;
}

int32_t sub_403d2b(int32_t arg1 @ esi)
{
    return sub_40219e(arg1, *(data_410d7c + (arg1 << 2)));
}

int32_t sub_403d5a()
{
    return __unlock(1);
}

int32_t sub_403d63()
{
    return sub_403c89(1);
}

int128_t* sub_403d70(int128_t* arg1, int128_t* arg2, void* arg3)
{
    char* esi = arg2;
    char* edi = arg1;
    uint32_t eax_1;
    
    if (edi > esi && edi < arg3 + esi)
    {
        void* esi_2 = arg3 + esi - 4;
        void* edi_2 = arg3 + edi - 4;
        uint32_t ecx_5;
        
        if (!(edi_2 & 3))
        {
            ecx_5 = arg3 >> 2;
            
            if (ecx_5 < 8)
                /* jump -> (&jump_table_404030)[-(ecx_5)] */
            
            edi_2 = __builtin_memcpy(edi_2 - (ecx_5 << 2), esi_2 - (ecx_5 << 2), ecx_5 << 2);
            
            switch (arg3 & 3)
            {
                case nullptr:
                {
                    return arg1;
                    break;
                }
                case 1:
                {
                    goto label_404098;
                }
                case 2:
                {
                    goto label_4040a8;
                }
                case 3:
                {
                    goto label_4040bc;
                }
            }
        }
        else if (arg3 < 4)
            switch (arg3)
            {
                case nullptr:
                {
                    return arg1;
                    break;
                }
                case 1:
                {
                label_404098:
                    eax_1 = *(esi_2 + 3);
                    *(edi_2 + 3) = eax_1;
                    return arg1;
                    break;
                }
                case 2:
                {
                label_4040a8:
                    eax_1 = *(esi_2 + 3);
                    *(edi_2 + 3) = eax_1;
                    eax_1 = *(esi_2 + 2);
                    *(edi_2 + 2) = eax_1;
                    return arg1;
                    break;
                }
                case 3:
                {
                label_4040bc:
                    eax_1 = *(esi_2 + 3);
                    *(edi_2 + 3) = eax_1;
                    eax_1 = *(esi_2 + 2);
                    *(edi_2 + 2) = eax_1;
                    eax_1 = *(esi_2 + 1);
                    *(edi_2 + 1) = eax_1;
                    return arg1;
                    break;
                }
            }
        else
        {
            eax_1 = edi_2 & 3;
            void* ecx_7 = arg3 - eax_1;
            
            switch (jump_table_403f84[eax_1])
            {
                case 0x403f94:
                {
                    eax_1 = *(esi_2 + 3);
                    *(edi_2 + 3) = eax_1;
                    ecx_5 = ecx_7 >> 2;
                    
                    if (ecx_5 < 8)
                        /* jump -> (&jump_table_404030)[-(ecx_5)] */
                    
                    edi_2 = __builtin_memcpy(edi_2 - 1 - (ecx_5 << 2), esi_2 - 1 - (ecx_5 << 2), 
                        ecx_5 << 2);
                    
                    switch (3 & ecx_7)
                    {
                        case nullptr:
                        {
                            return arg1;
                            break;
                        }
                        case 1:
                        {
                            goto label_404098;
                        }
                        case 2:
                        {
                            goto label_4040a8;
                        }
                        case 3:
                        {
                            goto label_4040bc;
                        }
                    }
                    break;
                }
                case 0x403fb8:
                {
                    eax_1 = *(esi_2 + 3);
                    *(edi_2 + 3) = eax_1;
                    eax_1 = *(esi_2 + 2);
                    ecx_5 = ecx_7 >> 2;
                    *(edi_2 + 2) = eax_1;
                    
                    if (ecx_5 < 8)
                        /* jump -> (&jump_table_404030)[-(ecx_5)] */
                    
                    edi_2 = __builtin_memcpy(edi_2 - 2 - (ecx_5 << 2), esi_2 - 2 - (ecx_5 << 2), 
                        ecx_5 << 2);
                    
                    switch (3 & ecx_7)
                    {
                        case nullptr:
                        {
                            return arg1;
                            break;
                        }
                        case 1:
                        {
                            goto label_404098;
                        }
                        case 2:
                        {
                            goto label_4040a8;
                        }
                        case 3:
                        {
                            goto label_4040bc;
                        }
                    }
                    break;
                }
                case 0x403fe0:
                {
                    eax_1 = *(esi_2 + 3);
                    *(edi_2 + 3) = eax_1;
                    eax_1 = *(esi_2 + 2);
                    *(edi_2 + 2) = eax_1;
                    eax_1 = *(esi_2 + 1);
                    ecx_5 = ecx_7 >> 2;
                    *(edi_2 + 1) = eax_1;
                    
                    if (ecx_5 < 8)
                        /* jump -> (&jump_table_404030)[-(ecx_5)] */
                    
                    edi_2 = __builtin_memcpy(edi_2 - 3 - (ecx_5 << 2), esi_2 - 3 - (ecx_5 << 2), 
                        ecx_5 << 2);
                    
                    switch (3 & ecx_7)
                    {
                        case nullptr:
                        {
                            return arg1;
                            break;
                        }
                        case 1:
                        {
                            goto label_404098;
                        }
                        case 2:
                        {
                            goto label_4040a8;
                        }
                        case 3:
                        {
                            goto label_4040bc;
                        }
                    }
                    break;
                }
            }
        }
    }
    
    if (arg3 >= 0x100 && data_410c20 && (edi & 0xf) == (esi & 0xf))
        /* tailcall */
        return sub_408194(arg1, arg2, arg3);
    
    uint32_t ecx_2;
    void* edx_2;
    
    if (edi & 3)
    {
        if (arg3 < 4)
            /* jump -> *(((arg3 - 4) << 2) + &data_403ef4) */
        
        eax_1 = edi & 3;
        void* ecx_4 = arg3 - 4 + eax_1;
        
        switch (jump_table_403df8[eax_1])
        {
            case 0x403e08:
            {
                edx_2 = 3 & ecx_4;
                eax_1 = *esi;
                *edi = eax_1;
                eax_1 = esi[1];
                edi[1] = eax_1;
                eax_1 = esi[2];
                ecx_2 = ecx_4 >> 2;
                edi[2] = eax_1;
                esi = &esi[3];
                edi = &edi[3];
                
                if (ecx_2 >= 8)
                {
                    edi = __builtin_memcpy(edi, esi, ecx_2 << 2);
                    
                    switch (edx_2)
                    {
                        case nullptr:
                        {
                            return arg1;
                            break;
                        }
                        case 1:
                        {
                            goto label_403efc;
                        }
                        case 2:
                        {
                            goto label_403f08;
                        }
                        case 3:
                        {
                            goto label_403f1c;
                        }
                    }
                }
                break;
            }
            case 0x403e34:
            {
                edx_2 = 3 & ecx_4;
                eax_1 = *esi;
                *edi = eax_1;
                eax_1 = esi[1];
                ecx_2 = ecx_4 >> 2;
                edi[1] = eax_1;
                esi = &esi[2];
                edi = &edi[2];
                
                if (ecx_2 >= 8)
                {
                    edi = __builtin_memcpy(edi, esi, ecx_2 << 2);
                    
                    switch (edx_2)
                    {
                        case nullptr:
                        {
                            return arg1;
                            break;
                        }
                        case 1:
                        {
                            goto label_403efc;
                        }
                        case 2:
                        {
                            goto label_403f08;
                        }
                        case 3:
                        {
                            goto label_403f1c;
                        }
                    }
                }
                break;
            }
            case 0x403e58:
            {
                edx_2 = 3 & ecx_4;
                eax_1 = *esi;
                *edi = eax_1;
                esi = &esi[1];
                ecx_2 = ecx_4 >> 2;
                edi = &edi[1];
                
                if (ecx_2 >= 8)
                {
                    edi = __builtin_memcpy(edi, esi, ecx_2 << 2);
                    
                    switch (edx_2)
                    {
                        case nullptr:
                        {
                            return arg1;
                            break;
                        }
                        case 1:
                        {
                            goto label_403efc;
                        }
                        case 2:
                        {
                            goto label_403f08;
                        }
                        case 3:
                        {
                            goto label_403f1c;
                        }
                    }
                }
                break;
            }
        }
    }
    else
    {
        ecx_2 = arg3 >> 2;
        edx_2 = arg3 & 3;
        
        if (ecx_2 >= 8)
        {
            edi = __builtin_memcpy(edi, esi, ecx_2 << 2);
            
            switch (edx_2)
            {
                case nullptr:
                {
                    return arg1;
                    break;
                }
                case 1:
                {
                    goto label_403efc;
                }
                case 2:
                {
                    goto label_403f08;
                }
                case 3:
                {
                    goto label_403f1c;
                }
            }
        }
    }
    
    switch (ecx_2)
    {
        case 0:
        {
            goto label_403edb;
        }
        case 1:
        {
            goto label_403ecc;
        }
        case 2:
        {
            goto label_403ec4;
        }
        case 3:
        {
            goto label_403ebc;
        }
        case 4:
        {
            goto label_403eb4;
        }
        case 5:
        {
            goto label_403eac;
        }
        case 6:
        {
            goto label_403ea4;
        }
        case 7:
        {
            *(edi + (ecx_2 << 2) - 0x1c) = *(esi + (ecx_2 << 2) - 0x1c);
        label_403ea4:
            *(edi + (ecx_2 << 2) - 0x18) = *(esi + (ecx_2 << 2) - 0x18);
        label_403eac:
            *(edi + (ecx_2 << 2) - 0x14) = *(esi + (ecx_2 << 2) - 0x14);
        label_403eb4:
            *(edi + (ecx_2 << 2) - 0x10) = *(esi + (ecx_2 << 2) - 0x10);
        label_403ebc:
            *(edi + (ecx_2 << 2) - 0xc) = *(esi + (ecx_2 << 2) - 0xc);
        label_403ec4:
            *(edi + (ecx_2 << 2) - 8) = *(esi + (ecx_2 << 2) - 8);
        label_403ecc:
            *(edi + (ecx_2 << 2) - 4) = *(esi + (ecx_2 << 2) - 4);
            eax_1 = ecx_2 << 2;
            esi = &esi[eax_1];
            edi = &edi[eax_1];
        label_403edb:
            
            switch (edx_2)
            {
                case nullptr:
                {
                    return arg1;
                    break;
                }
                case 1:
                {
                label_403efc:
                    eax_1 = *esi;
                    *edi = eax_1;
                    return arg1;
                    break;
                }
                case 2:
                {
                label_403f08:
                    eax_1 = *esi;
                    *edi = eax_1;
                    eax_1 = esi[1];
                    edi[1] = eax_1;
                    return arg1;
                    break;
                }
                case 3:
                {
                label_403f1c:
                    eax_1 = *esi;
                    *edi = eax_1;
                    eax_1 = esi[1];
                    edi[1] = eax_1;
                    eax_1 = esi[2];
                    edi[2] = eax_1;
                    return arg1;
                    break;
                }
            }
            break;
        }
    }
}

int32_t __convention("regparm") sub_404034(int32_t arg1, int32_t arg2, int32_t arg3, void* arg4 @ ebp, void* arg5 @ esi, void* arg6 @ edi, int32_t arg7)
{
    *(arg6 + (arg3 << 2) + 0x1c) = *(arg5 + (arg3 << 2) + 0x1c);
    *(arg6 + (arg3 << 2) + 0x18) = *(arg5 + (arg3 << 2) + 0x18);
    *(arg6 + (arg3 << 2) + 0x14) = *(arg5 + (arg3 << 2) + 0x14);
    *(arg6 + (arg3 << 2) + 0x10) = *(arg5 + (arg3 << 2) + 0x10);
    *(arg6 + (arg3 << 2) + 0xc) = *(arg5 + (arg3 << 2) + 0xc);
    *(arg6 + (arg3 << 2) + 8) = *(arg5 + (arg3 << 2) + 8);
    *(arg6 + (arg3 << 2) + 4) = *(arg5 + (arg3 << 2) + 4);
    int32_t eax_6 = arg3 << 2;
    void* esi = arg5 + eax_6;
    void* edi = arg6 + eax_6;
    
    switch (arg2)
    {
        case 0:
        {
            *arg4;
            return *(arg4 + 8);
            break;
        }
        case 1:
        {
            eax_6 = *(esi + 3);
            *(edi + 3) = eax_6;
            *arg4;
            return *(arg4 + 8);
            break;
        }
        case 2:
        {
            eax_6 = *(esi + 3);
            *(edi + 3) = eax_6;
            eax_6 = *(esi + 2);
            *(edi + 2) = eax_6;
            *arg4;
            return *(arg4 + 8);
            break;
        }
        case 3:
        {
            eax_6 = *(esi + 3);
            *(edi + 3) = eax_6;
            eax_6 = *(esi + 2);
            *(edi + 2) = eax_6;
            eax_6 = *(esi + 1);
            *(edi + 1) = eax_6;
            *arg4;
            return *(arg4 + 8);
            break;
        }
    }
}

int32_t sub_4040d5(int32_t arg1)
{
    data_41030c = arg1;
    return arg1;
}

void sub_4040df() __noreturn
{
    uint32_t __security_cookie_1 = __security_cookie;
    void var_2ac;
    int32_t eax = __security_cookie_1 ^ &var_2ac;
    bool p = /* bool p = unimplemented  {xor eax, ebp} */;
    bool a = /* undefined */;
    int32_t var_8 = eax;
    int32_t esi;
    int32_t var_330 = esi;
    int32_t var_224 = eax;
    int32_t var_234 = esi;
    int16_t ss;
    int16_t var_20c = ss;
    int16_t cs;
    int16_t var_218 = cs;
    int16_t ds;
    int16_t var_23c = ds;
    int16_t es;
    int16_t var_240 = es;
    int16_t fs;
    int16_t var_244 = fs;
    int16_t gs;
    int16_t var_248 = gs;
    bool d;
    int32_t var_214 = (d ? 1 : 0) << 0xa | ((__security_cookie_1 ^ &var_2ac) < 0 ? 1 : 0) << 7
        | (__security_cookie_1 == &var_2ac ? 1 : 0) << 6 | (a ? 1 : 0) << 4 | (p ? 1 : 0) << 2;
    int32_t var_2d4 = 0x10001;
    void* const __return_addr_2 = __return_addr;
    int32_t ebp;
    int32_t var_220 = ebp;
    int32_t var_32c;
    sub_404390(&var_32c, 0, 0x50);
    EXCEPTION_POINTERS ExceptionInfo;
    ExceptionInfo.ExceptionRecord = &var_32c;
    var_32c = 0xc000000d;
    void* const __return_addr_1 = __return_addr;
    ExceptionInfo.ContextRecord = &var_2d4;
    BOOL eax_2 = IsDebuggerPresent();
    SetUnhandledExceptionFilter(0);
    
    if (!UnhandledExceptionFilter(&ExceptionInfo) && !eax_2)
        sub_40828b();
    
    TerminateProcess(GetCurrentProcess(), 0xc000000d);
    /* no return */
}

int32_t sub_4041db()
{
    int32_t eax = sub_406d52(data_41030c);
    
    if (eax)
        /* jump -> eax */
    
    sub_40828b();
    /* tailcall */
    return sub_4040df();
}

int32_t sub_4041ff(int32_t arg1)
{
    enum WIN32_ERROR edi_2;
    
    if (sub_407d5a(arg1) == 0xffffffff)
        edi_2 = NO_ERROR;
    else
    {
        void* eax_1 = data_410c40;
        
        if ((arg1 != 1 || !(*(eax_1 + 0x54) & 1)) && (arg1 != 2 || !(*(eax_1 + 0x2c) & 1)))
        {
        label_40424a:
            
            if (CloseHandle(sub_407d5a(arg1)))
                edi_2 = NO_ERROR;
            else
                edi_2 = GetLastError();
        }
        else
        {
            int32_t eax_2 = sub_407d5a(2);
            
            if (sub_407d5a(1) != eax_2)
                goto label_40424a;
            
            edi_2 = NO_ERROR;
        }
    }
    
    sub_407cd9(arg1);
    *((&data_410c40)[arg1 >> 5] + (arg1 & 0x1f) * 0x28 + 4) = 0;
    
    if (!edi_2)
        return 0;
    
    sub_402447(edi_2);
    return 0xffffffff;
}

int32_t sub_404293(int32_t arg1)
{
    int32_t __saved_ebp_1 = 0x10;
    int32_t var_8 = 0x40e568;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e568 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_34 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_34;
    void* const var_38_2 = &data_40429f;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t result;
    
    if (arg1 != 0xfffffffe)
    {
        int32_t esi_3;
        
        if (arg1 >= 0 && arg1 < data_410c24)
            esi_3 = (arg1 & 0x1f) * 0x28;
        
        if (arg1 < 0 || arg1 >= data_410c24 || !(*((&data_410c40)[arg1 >> 5] + esi_3 + 4) & 1))
        {
            *___doserrno() = 0;
            *__errno() = 9;
            sub_4041db(0, 0, 0, 0, 0);
            result = 0xffffffff;
        }
        else
        {
            sub_407dcb(arg1);
            int32_t var_8_1 = 0;
            int32_t result_1;
            
            if (!(*((&data_410c40)[arg1 >> 5] + esi_3 + 4) & 1))
            {
                *__errno() = 9;
                result_1 = 0xffffffff;
            }
            else
                result_1 = sub_4041ff(arg1);
            
            int32_t var_8_2 = 0xfffffffe;
            sub_404356(&__saved_ebp);
            result = result_1;
        }
    }
    else
    {
        *___doserrno() = 0;
        *__errno() = 9;
        result = 0xffffffff;
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_404355;
    return result;
}

int32_t sub_404356(void* arg1 @ ebp)
{
    return sub_407e6b(*(arg1 + 8));
}

char sub_404360(int32_t* arg1)
{
    char result = arg1[3];
    
    if (result & 0x83 && result & 8)
    {
        sub_40139b(arg1[2]);
        arg1[3] &= 0xfffffbf7;
        result = 0;
        *arg1 = 0;
        arg1[2] = 0;
        arg1[1] = 0;
    }
    
    return result;
}

char* sub_404390(char* arg1, char arg2, int32_t arg3)
{
    int32_t i_3 = arg3;
    
    if (!i_3)
        return arg1;
    
    int32_t eax;
    eax = arg2;
    
    if (!eax && i_3 >= 0x100 && data_410c20)
        /* tailcall */
        return sub_4082ea(arg1, arg2);
    
    char* edi = arg1;
    
    if (i_3 < 4)
    {
    label_4043fd:
        int32_t i;
        
        do
        {
            *edi = eax;
            edi = &edi[1];
            i = i_3;
            i_3 -= 1;
        } while (i != 1);
    }
    else
    {
        int32_t i_2 = -(arg1) & 3;
        
        if (i_2)
        {
            i_3 -= i_2;
            int32_t i_1;
            
            do
            {
                *edi = eax;
                edi = &edi[1];
                i_1 = i_2;
                i_2 -= 1;
            } while (i_1 != 1);
        }
        
        eax *= 0x1010101;
        int32_t i_4 = i_3;
        i_3 &= 3;
        uint32_t ecx_5 = i_4 >> 2;
        
        if (!ecx_5)
            goto label_4043fd;
        
        int32_t ecx_6;
        edi = __memfill_u32(edi, eax, ecx_5);
        
        if (i_3)
            goto label_4043fd;
    }
    
    return arg1;
}

uint32_t sub_40440a(int32_t* arg1)
{
    if (arg1)
    {
        int32_t eax_1 = arg1[3];
        
        if (eax_1 & 0x83 && !(eax_1 & 0x40))
        {
            if (!(eax_1 & 2))
            {
                int32_t eax_3 = eax_1 | 1;
                arg1[3] = eax_3;
                
                if (eax_3 & 0x10c)
                    *arg1 = arg1[2];
                else
                    sub_40798a(arg1);
                
                int32_t eax_6 = sub_404acc(sub_403bb8(arg1), arg1[2], arg1[6]);
                arg1[1] = eax_6;
                
                if (eax_6 && eax_6 != 0xffffffff)
                {
                    if (!(arg1[3] & 0x82))
                    {
                        bool cond:2_1 = sub_403bb8(arg1) == 0xffffffff;
                        bool cond:3_1;
                        
                        if (!cond:2_1)
                            cond:3_1 = sub_403bb8(arg1) == 0xfffffffe;
                        
                        void* eax_14;
                        
                        if (cond:2_1 || cond:3_1)
                            eax_14 = &data_40f820;
                        else
                        {
                            void* edi_1 = &(&data_410c40)[sub_403bb8(arg1) >> 5];
                            eax_14 = (sub_403bb8(arg1) & 0x1f) * 0x28 + *edi_1;
                        }
                        
                        eax_14 = *(eax_14 + 4);
                        eax_14 &= 0x82;
                        
                        if (eax_14 == 0x82)
                            arg1[3] |= 0x2000;
                    }
                    
                    if (arg1[6] == 0x200)
                    {
                        int16_t eax_15 = arg1[3];
                        
                        if (eax_15 & 8 && !(eax_15 & 0x400))
                            arg1[6] = 0x1000;
                    }
                    
                    char* ecx_6 = *arg1;
                    arg1[1] -= 1;
                    uint32_t result = *ecx_6;
                    *arg1 = &ecx_6[1];
                    return result;
                }
                
                int32_t eax_16 = -(eax_6);
                arg1[3] |= ((eax_16 - eax_16) & 0x10) + 0x10;
                arg1[1] = 0;
            }
            else
                arg1[3] = eax_1 | 0x20;
        }
    }
    else
    {
        *__errno() = 0x16;
        sub_4041db(0, 0, 0, 0, 0);
    }
    
    return 0xffffffff;
}

int32_t sub_40452a(int32_t arg1, wchar16* arg2, uint32_t arg3)
{
    int32_t var_18 = 0xfffffffe;
    uint32_t var_20 = arg3;
    
    if (arg1 == 0xfffffffe)
    {
        *___doserrno() = 0;
        *__errno() = 9;
        return 0xffffffff;
    }
    
    if (arg1 < 0 || arg1 >= data_410c24)
    {
        *___doserrno() = 0;
        *__errno() = 9;
        sub_4041db(0, 0, 0, 0, 0);
        return 0xffffffff;
    }
    
    HANDLE* esi_2 = (arg1 & 0x1f) * 0x28;
    void* eax_8 = (&data_410c40)[arg1 >> 5] + esi_2;
    char ecx = *(eax_8 + 4);
    
    if (!(ecx & 1))
    {
        *___doserrno() = 0;
        *__errno() = 9;
        sub_4041db(0, 0, 0, 0, 0);
        return 0xffffffff;
    }
    
    int32_t var_14_1 = 0;
    
    if (!arg3 || ecx & 2)
        return 0;
    
    if (arg2)
    {
        eax_8 = *(eax_8 + 0x24);
        eax_8 *= 2;
        eax_8 s>>= 1;
        char var_6_1 = eax_8;
        int32_t eax_11 = eax_8;
        uint32_t lpMultiByteStr;
        
        if (eax_11 != 1)
        {
            if (eax_11 != 2)
                goto label_404613;
            
            if (~arg3 & 1)
            {
                arg3 &= 0xfffffffe;
            label_404613:
                lpMultiByteStr = arg2;
            label_404618:
                char* lpBuffer = lpMultiByteStr;
                void* edi_1 = esi_2 + (&data_410c40)[arg1 >> 5];
                
                if (*(edi_1 + 4) & 0x48)
                {
                    int32_t ecx_2;
                    ecx_2 = *(edi_1 + 5);
                    
                    if (ecx_2 != 0xa && arg3)
                    {
                        *lpBuffer = ecx_2;
                        lpBuffer = &lpBuffer[1];
                        arg3 -= 1;
                        var_14_1 = 1;
                        *(esi_2 + (&data_410c40)[arg1 >> 5] + 5) = 0xa;
                        
                        if (var_6_1)
                        {
                            int32_t ecx_4;
                            ecx_4 = *(esi_2 + (&data_410c40)[arg1 >> 5] + 0x25);
                            
                            if (ecx_4 != 0xa && arg3)
                            {
                                *lpBuffer = ecx_4;
                                lpBuffer = &lpBuffer[1];
                                arg3 -= 1;
                                var_14_1 = 2;
                                *(esi_2 + (&data_410c40)[arg1 >> 5] + 0x25) = 0xa;
                                
                                if (var_6_1 == 1)
                                {
                                    int32_t ecx_6;
                                    ecx_6 = *(esi_2 + (&data_410c40)[arg1 >> 5] + 0x26);
                                    
                                    if (ecx_6 != 0xa && arg3)
                                    {
                                        *lpBuffer = ecx_6;
                                        lpBuffer = &lpBuffer[1];
                                        arg3 -= 1;
                                        var_14_1 = 3;
                                        *(esi_2 + (&data_410c40)[arg1 >> 5] + 0x26) = 0xa;
                                    }
                                }
                            }
                        }
                    }
                }
                
                uint32_t numberOfBytesRead;
                BOOL eax_17;
                char* ecx_8;
                int32_t edx_2;
                eax_17 = ReadFile(*(esi_2 + (&data_410c40)[arg1 >> 5]), lpBuffer, arg3, 
                    &numberOfBytesRead, nullptr);
                uint32_t numberOfBytesRead_1;
                
                if (eax_17)
                    numberOfBytesRead_1 = numberOfBytesRead;
                
                if (!eax_17 || numberOfBytesRead_1 < 0 || numberOfBytesRead_1 > arg3)
                {
                    enum WIN32_ERROR eax_49 = GetLastError();
                    
                    if (eax_49 == ERROR_ACCESS_DENIED)
                    {
                        *__errno() = 9;
                        *___doserrno() = 5;
                        var_18 = 0xffffffff;
                    }
                    else if (eax_49 != ERROR_BROKEN_PIPE)
                    {
                        sub_402447(eax_49);
                        var_18 = 0xffffffff;
                    }
                    else
                        var_18 = 0;
                }
                else
                {
                    var_14_1 += numberOfBytesRead_1;
                    void* eax_19 = esi_2 + (&data_410c40)[arg1 >> 5] + 4;
                    
                    if (*eax_19 & 0x80)
                    {
                        if (var_6_1 == 2)
                        {
                            if (!numberOfBytesRead_1 || *lpMultiByteStr != 0xa)
                                *eax_19 &= 0xfb;
                            else
                                *eax_19 |= 4;
                            
                            uint32_t lpMultiByteStr_3 = lpMultiByteStr;
                            int32_t eax_53 = var_14_1 + lpMultiByteStr_3;
                            arg3 = lpMultiByteStr_3;
                            
                            if (lpMultiByteStr_3 < eax_53)
                            {
                                do
                                {
                                    int16_t ecx_22 = *arg3;
                                    
                                    if (ecx_22 == 0x1a)
                                    {
                                        void* esi_3 = esi_2 + (&data_410c40)[arg1 >> 5] + 4;
                                        
                                        if (*esi_3 & 0x40)
                                        {
                                            uint32_t eax_65;
                                            eax_65 = *arg3;
                                            *lpMultiByteStr_3 = eax_65;
                                            lpMultiByteStr_3 += 2;
                                        }
                                        else
                                            *esi_3 |= 2;
                                        
                                        break;
                                    }
                                    
                                    if (ecx_22 != 0xd)
                                    {
                                        *lpMultiByteStr_3 = ecx_22;
                                        lpMultiByteStr_3 += 2;
                                        arg3 += 2;
                                    }
                                    else if (arg3 >= eax_53 - 2)
                                    {
                                        arg3 += 2;
                                        int16_t buffer;
                                        BOOL eax_58;
                                        int32_t ecx_26;
                                        int32_t edx_4;
                                        eax_58 = ReadFile(*(esi_2 + (&data_410c40)[arg1 >> 5]), 
                                            &buffer, 2, &numberOfBytesRead, nullptr);
                                        
                                        if (eax_58)
                                        {
                                            if (numberOfBytesRead)
                                                goto label_404a03;
                                            
                                            *lpMultiByteStr_3 = 0xd;
                                            lpMultiByteStr_3 += 2;
                                        }
                                        else
                                        {
                                            enum WIN32_ERROR eax_59;
                                            eax_59 = GetLastError();
                                            
                                            if (eax_59 || !numberOfBytesRead)
                                            {
                                                *lpMultiByteStr_3 = 0xd;
                                                lpMultiByteStr_3 += 2;
                                            }
                                            else
                                            {
                                            label_404a03:
                                                int32_t eax_60 = (&data_410c40)[arg1 >> 5];
                                                
                                                if (!(*(esi_2 + eax_60 + 4) & 0x48))
                                                {
                                                    if (lpMultiByteStr_3 != lpMultiByteStr
                                                        || buffer != 0xa)
                                                    {
                                                        sub_4077ee(eax_60, edx_4, ecx_26, arg1, 
                                                            0xfffffffe, 0xffffffff, FILE_CURRENT);
                                                        
                                                        if (buffer != 0xa)
                                                        {
                                                            *lpMultiByteStr_3 = 0xd;
                                                            lpMultiByteStr_3 += 2;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        *lpMultiByteStr_3 = 0xa;
                                                        lpMultiByteStr_3 += 2;
                                                    }
                                                }
                                                else if (buffer == 0xa)
                                                {
                                                    *lpMultiByteStr_3 = 0xa;
                                                    lpMultiByteStr_3 += 2;
                                                }
                                                else
                                                {
                                                    *lpMultiByteStr_3 = 0xd;
                                                    ecx_26 = buffer;
                                                    *(esi_2 + (&data_410c40)[arg1 >> 5] + 5) =
                                                        ecx_26;
                                                    ecx_26 = *buffer[1];
                                                    *(esi_2 + (&data_410c40)[arg1 >> 5] + 0x25) =
                                                        ecx_26;
                                                    *(esi_2 + (&data_410c40)[arg1 >> 5] + 0x26) =
                                                        0xa;
                                                    lpMultiByteStr_3 += 2;
                                                }
                                            }
                                        }
                                    }
                                    else if (*(arg3 + 2) != 0xa)
                                    {
                                        arg3 += 2;
                                        *lpMultiByteStr_3 = 0xd;
                                        lpMultiByteStr_3 += 2;
                                    }
                                    else
                                    {
                                        arg3 += 4;
                                        *lpMultiByteStr_3 = 0xa;
                                        lpMultiByteStr_3 += 2;
                                    }
                                } while (arg3 < eax_53);
                            }
                            
                            var_14_1 = lpMultiByteStr_3 - lpMultiByteStr;
                        }
                        else
                        {
                            if (!numberOfBytesRead_1 || *lpMultiByteStr != 0xa)
                                *eax_19 &= 0xfb;
                            else
                                *eax_19 |= 4;
                            
                            uint32_t lpMultiByteStr_2 = lpMultiByteStr;
                            int32_t eax_29 = var_14_1 + lpMultiByteStr_2;
                            arg3 = lpMultiByteStr_2;
                            int32_t var_14_2 = eax_29;
                            
                            if (lpMultiByteStr_2 < eax_29)
                            {
                                do
                                {
                                    ecx_8 = arg3;
                                    eax_29 = *ecx_8;
                                    
                                    if (eax_29 == 0x1a)
                                    {
                                        void* eax_39 = esi_2 + (&data_410c40)[arg1 >> 5] + 4;
                                        
                                        if (*eax_39 & 0x40)
                                        {
                                            eax_39 = *ecx_8;
                                            *lpMultiByteStr_2 = eax_39;
                                            lpMultiByteStr_2 += 1;
                                        }
                                        else
                                            *eax_39 |= 2;
                                        
                                        break;
                                    }
                                    
                                    if (eax_29 != 0xd)
                                    {
                                        *lpMultiByteStr_2 = eax_29;
                                        lpMultiByteStr_2 += 1;
                                        arg3 = &ecx_8[1];
                                    }
                                    else if (ecx_8 >= var_14_2 - 1)
                                    {
                                        arg3 += 1;
                                        uint8_t buffer_1;
                                        BOOL eax_34;
                                        eax_34 = ReadFile(*(esi_2 + (&data_410c40)[arg1 >> 5]), 
                                            &buffer_1, 1, &numberOfBytesRead, nullptr);
                                        
                                        if (eax_34)
                                        {
                                            if (numberOfBytesRead)
                                                goto label_4047e7;
                                            
                                            *lpMultiByteStr_2 = 0xd;
                                            lpMultiByteStr_2 += 1;
                                        }
                                        else
                                        {
                                            enum WIN32_ERROR eax_35;
                                            eax_35 = GetLastError();
                                            
                                            if (eax_35 || !numberOfBytesRead)
                                            {
                                                *lpMultiByteStr_2 = 0xd;
                                                lpMultiByteStr_2 += 1;
                                            }
                                            else
                                            {
                                            label_4047e7:
                                                int32_t eax_36 = (&data_410c40)[arg1 >> 5];
                                                
                                                if (!(*(esi_2 + eax_36 + 4) & 0x48))
                                                {
                                                    if (lpMultiByteStr_2 != lpMultiByteStr
                                                        || buffer_1 != 0xa)
                                                    {
                                                        ecx_8 = sub_4077ee(eax_36, edx_2, ecx_8, 
                                                            arg1, 0xffffffff, 0xffffffff, 
                                                            FILE_CURRENT);
                                                        
                                                        if (buffer_1 != 0xa)
                                                        {
                                                            *lpMultiByteStr_2 = 0xd;
                                                            lpMultiByteStr_2 += 1;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        *lpMultiByteStr_2 = 0xa;
                                                        lpMultiByteStr_2 += 1;
                                                    }
                                                }
                                                else if (buffer_1 == 0xa)
                                                {
                                                    *lpMultiByteStr_2 = 0xa;
                                                    lpMultiByteStr_2 += 1;
                                                }
                                                else
                                                {
                                                    *lpMultiByteStr_2 = 0xd;
                                                    ecx_8 = buffer_1;
                                                    *(esi_2 + (&data_410c40)[arg1 >> 5] + 5) =
                                                        ecx_8;
                                                    lpMultiByteStr_2 += 1;
                                                }
                                            }
                                        }
                                    }
                                    else if (ecx_8[1] != 0xa)
                                    {
                                        arg3 = &ecx_8[1];
                                        *lpMultiByteStr_2 = 0xd;
                                        lpMultiByteStr_2 += 1;
                                    }
                                    else
                                    {
                                        arg3 = &ecx_8[2];
                                        *lpMultiByteStr_2 = 0xa;
                                        lpMultiByteStr_2 += 1;
                                    }
                                } while (arg3 < var_14_2);
                            }
                            
                            uint32_t eax_41 = lpMultiByteStr_2 - lpMultiByteStr;
                            var_14_1 = eax_41;
                            
                            if (var_6_1 == 1 && eax_41)
                            {
                                char* edi_2 = lpMultiByteStr_2 - 1;
                                ecx_8 = *edi_2;
                                
                                if (ecx_8 < 0)
                                {
                                    int32_t eax_42 = 1;
                                    uint32_t ecx_11 = ecx_8;
                                    
                                    while (!*(ecx_11 + 0x40f660))
                                    {
                                        if (eax_42 > 4)
                                            break;
                                        
                                        if (edi_2 < lpMultiByteStr)
                                            break;
                                        
                                        edi_2 -= 1;
                                        ecx_11 = *edi_2;
                                        eax_42 += 1;
                                    }
                                    
                                    edx_2 = *edi_2;
                                    int32_t ecx_13 = *(edx_2 + 0x40f660);
                                    
                                    if (ecx_13)
                                    {
                                        if (ecx_13 + 1 != eax_42)
                                        {
                                            void* ecx_16 = (&data_410c40)[arg1 >> 5] + esi_2;
                                            
                                            if (!(*(ecx_16 + 4) & 0x48))
                                            {
                                                int32_t eax_45;
                                                int32_t edx_3;
                                                edx_3 = HIGHD(-(eax_42));
                                                eax_45 = LOWD(-(eax_42));
                                                sub_4077ee(eax_45, edx_3, ecx_16, arg1, eax_45, 
                                                    edx_3, FILE_CURRENT);
                                            }
                                            else
                                            {
                                                void* edi_3 = &edi_2[1];
                                                *(ecx_16 + 5) = edx_2;
                                                
                                                if (eax_42 >= 2)
                                                {
                                                    edx_2 = *edi_3;
                                                    *(esi_2 + (&data_410c40)[arg1 >> 5] + 0x25) =
                                                        edx_2;
                                                    edi_3 += 1;
                                                }
                                                
                                                if (eax_42 == 3)
                                                {
                                                    edx_2 = *edi_3;
                                                    *(esi_2 + (&data_410c40)[arg1 >> 5] + 0x26) =
                                                        edx_2;
                                                    edi_3 += 1;
                                                }
                                                
                                                edi_2 = edi_3 - eax_42;
                                            }
                                        }
                                        else
                                            edi_2 = &edi_2[eax_42];
                                        
                                        goto label_404911;
                                    }
                                    
                                    *__errno() = 0x2a;
                                    var_18 = 0xffffffff;
                                }
                                else
                                {
                                    edi_2 = &edi_2[1];
                                label_404911:
                                    int32_t eax_48 = MultiByteToWideChar(0xfde9, 0, lpMultiByteStr, 
                                        edi_2 - lpMultiByteStr, arg2, var_20 >> 1);
                                    var_14_1 = eax_48;
                                    
                                    if (eax_48)
                                        var_14_1 = eax_48 * 2;
                                    else
                                    {
                                        sub_402447(GetLastError());
                                        var_18 = 0xffffffff;
                                    }
                                }
                            }
                        }
                    }
                }
                
                if (lpMultiByteStr != arg2)
                    sub_40139b(lpMultiByteStr);
                
                if (var_18 != 0xfffffffe)
                    return var_18;
                
                return var_14_1;
            }
        }
        else if (~arg3 & 1)
        {
            uint32_t eax_25 = arg3 >> 1;
            arg3 = 4;
            
            if (eax_25 >= 4)
                arg3 = eax_25;
            
            uint32_t lpMultiByteStr_1 = sub_40655b(arg3);
            lpMultiByteStr = lpMultiByteStr_1;
            
            if (lpMultiByteStr_1)
                goto label_404618;
            
            *__errno() = 0xc;
            *___doserrno() = 8;
            return 0xffffffff;
        }
    }
    
    *___doserrno() = 0;
    *__errno() = 0x16;
    sub_4041db(0, 0, 0, 0, 0);
    return 0xffffffff;
}

int32_t sub_404acc(int32_t arg1, wchar16* arg2, uint32_t arg3)
{
    int32_t __saved_ebp_1 = 0x10;
    int32_t var_8 = 0x40e588;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e588 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_34 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_34;
    void* const var_38_2 = &data_404ad8;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t result;
    
    if (arg1 != 0xfffffffe)
    {
        int32_t esi_3;
        
        if (arg1 >= 0 && arg1 < data_410c24)
            esi_3 = (arg1 & 0x1f) * 0x28;
        
        if (arg1 < 0 || arg1 >= data_410c24 || !(*((&data_410c40)[arg1 >> 5] + esi_3 + 4) & 1))
        {
            *___doserrno() = 0;
            *__errno() = 9;
            sub_4041db(0, 0, 0, 0, 0);
            result = 0xffffffff;
        }
        else
        {
            sub_407dcb(arg1);
            int32_t var_8_1 = 0;
            int32_t result_1;
            
            if (!(*((&data_410c40)[arg1 >> 5] + esi_3 + 4) & 1))
            {
                *__errno() = 9;
                *___doserrno() = 0;
                result_1 = 0xffffffff;
            }
            else
                result_1 = sub_40452a(arg1, arg2, arg3);
            
            int32_t var_8_2 = 0xfffffffe;
            sub_404b9e(&__saved_ebp);
            result = result_1;
        }
    }
    else
    {
        *___doserrno() = 0;
        *__errno() = 9;
        result = 0xffffffff;
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_404b9d;
    return result;
}

int32_t sub_404b9e(void* arg1 @ ebp)
{
    return sub_407e6b(*(arg1 + 8));
}

int32_t sub_404ba8(char* arg1, int32_t arg2, int128_t* arg3, void* arg4)
{
    if (arg4)
    {
        if (!arg1)
        {
        label_404bc6:
            *__errno() = 0x16;
            sub_4041db(0, 0, 0, 0, 0);
            return 0x16;
        }
        
        if (!arg3 || arg2 < arg4)
        {
            sub_404390(arg1, 0, arg2);
            
            if (!arg3)
                goto label_404bc6;
            
            if (arg2 >= arg4)
                return 0x16;
            
            *__errno() = 0x22;
            sub_4041db(0, 0, 0, 0, 0);
            return 0x22;
        }
        
        sub_403d70(arg1, arg3, arg4);
    }
    
    return 0;
}

int32_t sub_404c23(int32_t arg1)
{
    sub_4050cb();
    sub_404f2b(arg1);
    return sub_406d52(data_40f760)(0xff);
}

HMODULE sub_404c47(int32_t arg1)
{
    HMODULE hModule = GetModuleHandleA("mscoree.dll");
    
    if (hModule)
    {
        hModule = GetProcAddress(hModule, "CorExitProcess");
        
        if (hModule)
            return hModule(arg1);
    }
    
    return hModule;
}

void sub_404c6d(uint32_t arg1) __noreturn
{
    sub_404c47(arg1);
    ExitProcess(arg1);
    /* no return */
}

int32_t sub_404c82()
{
    return sub_402690(8);
}

int32_t sub_404c8b()
{
    return __unlock(8);
}

void __convention("regparm") sub_404c94(int32_t* arg1, int32_t arg2)
{
    for (int32_t* i = arg1; i < arg2; i = &i[1])
    {
        arg1 = *i;
        
        if (arg1)
            arg1();
    }
}

int32_t sub_404cac(int32_t* arg1, int32_t arg2)
{
    int32_t* i = arg1;
    int32_t result = 0;
    
    for (; i < arg2; i = &i[1])
    {
        if (result)
            break;
        
        int32_t ecx_1 = *i;
        
        if (ecx_1)
            result = ecx_1();
    }
    
    return result;
}

int32_t sub_404ccc(int32_t* arg1)
{
    if (arg1)
    {
        int32_t eax_3 = data_410314;
        
        if (eax_3)
        {
            *arg1 = eax_3;
            return 0;
        }
    }
    
    *__errno() = 0x16;
    sub_4041db(0, 0, 0, 0, 0);
    return 0x16;
}

int32_t sub_404d03(int32_t* arg1)
{
    if (arg1 && data_410314)
    {
        *arg1 = data_410320;
        return 0;
    }
    
    *__errno() = 0x16;
    sub_4041db(0, 0, 0, 0, 0);
    return 0x16;
}

int32_t sub_404d3f(int32_t arg1)
{
    if (data_410d50 && sub_407782(&data_410d50))
        data_410d50(arg1);
    
    sub_4084a3();
    int32_t result = sub_404cac(0x40d128, 0x40d140);
    
    if (result)
        return result;
    
    sub_408491(sub_406cc2);
    
    for (void* const i = &data_40d120; i < 0x40d124; i += 4)
    {
        int32_t eax_2 = *i;
        
        if (eax_2)
            eax_2();
    }
    
    if (data_410d54 && sub_407782(&data_410d54))
        data_410d54(0, 2, 0);
    
    return 0;
}

int32_t sub_404dd1(uint32_t arg1, int32_t arg2, int32_t arg3)
{
    int32_t __saved_ebp_1 = 0xc;
    int32_t var_8 = 0x40e5a8;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e5a8 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_2 = &data_404ddd;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t edx = sub_402690(8);
    int32_t var_8_1 = 0;
    
    if (data_410354 != 1)
    {
        data_410350 = 1;
        data_41034c = arg3;
        
        if (!arg2)
        {
            int32_t eax_1 = sub_406d52(data_410d48);
            int32_t* eax_2;
            int32_t edx_1;
            eax_2 = sub_406d52(data_410d44);
            int32_t* var_20_1 = eax_2;
            
            if (eax_1)
            {
                while (true)
                {
                    var_20_1 -= 4;
                    
                    if (var_20_1 < eax_1)
                        break;
                    
                    int32_t eax_4 = *var_20_1;
                    
                    if (eax_4)
                        edx_1 = eax_4();
                }
            }
            
            edx = sub_404c94(0x40d144, edx_1);
        }
        
        sub_404c94(0x40d154, edx);
    }
    
    int32_t var_8_2 = 0xfffffffe;
    int32_t result = $LN17(&__saved_ebp);
    
    if (arg3)
    {
        fsbase->NtTib.ExceptionList = ExceptionList;
        void* const __saved_ebp_2 = &data_404e9e;
        return result;
    }
    
    data_410354 = 1;
    __unlock(8);
    sub_404c6d(arg1);
    /* no return */
}

void $LN17(void* arg1 @ ebp)
{
    if (*(arg1 + 0x10))
        __unlock(8);
}

int32_t sub_404e9f(uint32_t arg1)
{
    return sub_404dd1(arg1, 0, 0);
}

int32_t sub_404eb0(uint32_t arg1)
{
    return sub_404dd1(arg1, 1, 0);
}

int32_t __cexit()
{
    return sub_404dd1(0, 0, 1);
}

int32_t __c_exit()
{
    return sub_404dd1(0, 1, 1);
}

void* sub_404edf()
{
    int32_t eax = sub_406d49();
    sub_405104(eax);
    sub_4072ad(eax);
    sub_4040d5(eax);
    sub_408720(eax);
    sub_408716(eax);
    sub_40850c(eax);
    int32_t var_20 = eax;
    int32_t var_24 = eax;
    sub_4084fb();
    void* result = sub_406ce6(sub_404eb0);
    data_40f760 = result;
    return result;
}

void sub_404f2b(int32_t arg1)
{
    int32_t edi = 0;
    
    while (arg1 != *((edi << 3) + &data_40f768))
    {
        edi += 1;
        
        if (edi >= 0x17)
            break;
    }
    
    if (edi >= 0x17)
        return;
    
    bool cond:0_1 = sub_408ae0(3) == 1;
    bool cond:1_1;
    
    if (!cond:0_1)
        cond:1_1 = sub_408ae0(3);
    
    if (cond:0_1 || (!cond:1_1 && data_40f3b8 == 1))
    {
        HANDLE hFile = GetStdHandle(STD_ERROR_HANDLE);
        
        if (hFile && hFile != 0xffffffff)
        {
            uint32_t nNumberOfBytesToWrite = _strlen((&data_40f76c)[edi * 2]);
            uint32_t __saved_ecx;
            WriteFile(hFile, (&data_40f76c)[edi * 2], nNumberOfBytesToWrite, &__saved_ecx, nullptr);
        }
    }
    else if (arg1 != 0xfc)
    {
        if (sub_408a7b(0x410358, 0x314, "Runtime Error!\n\nProgram: "))
        {
            int32_t var_28_1;
            __builtin_memset(&var_28_1, 0, 0x14);
            sub_4040df();
            /* no return */
        }
        
        data_410475 = 0;
        
        if (!GetModuleFileNameA(nullptr, &data_410371, 0x104)
            && sub_408a7b(&data_410371, 0x2fb, "<program name unknown>"))
        {
            int32_t var_28_2;
            __builtin_memset(&var_28_2, 0, 0x14);
            sub_4040df();
            /* no return */
        }
        
        if (_strlen(&data_410371) + 1 > 0x3c)
        {
            char* eax_7 = _strlen(&data_410371) + &*(data_410334 + 2);
            
            if (sub_408939(eax_7, &data_41066c - eax_7, "...", 3))
            {
                int32_t var_28_4;
                __builtin_memset(&var_28_4, 0, 0x14);
                sub_4040df();
                /* no return */
            }
        }
        
        if (sub_4088c8(0x410358, 0x314, "\n\n"))
        {
            int32_t var_28_5;
            __builtin_memset(&var_28_5, 0, 0x14);
            sub_4040df();
            /* no return */
        }
        
        if (sub_4088c8(0x410358, 0x314, (&data_40f76c)[edi * 2]))
        {
            int32_t var_28_6;
            __builtin_memset(&var_28_6, 0, 0x14);
            sub_4040df();
            /* no return */
        }
        
        sub_40872a(0x410358, "Microsoft Visual C++ Runtime Library", 0x12010);
    }
}

int32_t sub_4050cb()
{
    int32_t result;
    
    if (sub_408ae0(3) == 1)
    {
        sub_404f2b(0xfc);
        result = sub_404f2b(0xff);
    }
    else
    {
        result = sub_408ae0(3);
        
        if (!result && data_40f3b8 == 1)
        {
            sub_404f2b(0xfc);
            result = sub_404f2b(0xff);
        }
    }
    
    return result;
}

int32_t sub_405104(int32_t arg1)
{
    data_41066c = arg1;
    return arg1;
}

int32_t sub_40510e(int32_t arg1)
{
    int32_t eax = sub_406d52(data_41066c);
    
    if (eax && eax(arg1))
        return 1;
    
    return 0;
}

uint32_t sub_405130(int32_t arg1, int32_t arg2, enum SET_FILE_POINTER_MOVE_METHOD arg3)
{
    HANDLE hFile = sub_407d5a(arg1);
    
    if (hFile == 0xffffffff)
    {
        *__errno() = 9;
        return 0xffffffff;
    }
    
    uint32_t result = SetFilePointer(hFile, arg2, nullptr, arg3);
    enum WIN32_ERROR eax_2;
    
    if (result != 0xffffffff)
        eax_2 = NO_ERROR;
    else
        eax_2 = GetLastError();
    
    if (eax_2)
    {
        sub_402447(eax_2);
        return 0xffffffff;
    }
    
    char* eax_7 = (&data_410c40)[arg1 >> 5] + (arg1 & 0x1f) * 0x28 + 4;
    *eax_7 &= 0xfd;
    return result;
}

uint32_t sub_4051a2(int32_t arg1, int32_t arg2, enum SET_FILE_POINTER_MOVE_METHOD arg3)
{
    int32_t __saved_ebp_1 = 0x10;
    int32_t var_8 = 0x40e5c8;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e5c8 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_34 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_34;
    void* const var_38_2 = &data_4051ae;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    uint32_t result;
    
    if (arg1 != 0xfffffffe)
    {
        int32_t esi_3;
        
        if (arg1 >= 0 && arg1 < data_410c24)
            esi_3 = (arg1 & 0x1f) * 0x28;
        
        if (arg1 < 0 || arg1 >= data_410c24 || !(*((&data_410c40)[arg1 >> 5] + esi_3 + 4) & 1))
        {
            *___doserrno() = 0;
            *__errno() = 9;
            sub_4041db(0, 0, 0, 0, 0);
            result = 0xffffffff;
        }
        else
        {
            sub_407dcb(arg1);
            int32_t var_8_1 = 0;
            uint32_t result_1;
            
            if (!(*((&data_410c40)[arg1 >> 5] + esi_3 + 4) & 1))
            {
                *__errno() = 9;
                *___doserrno() = 0;
                result_1 = 0xffffffff;
            }
            else
                result_1 = sub_405130(arg1, arg2, arg3);
            
            int32_t var_8_2 = 0xfffffffe;
            sub_405274(&__saved_ebp);
            result = result_1;
        }
    }
    else
    {
        *___doserrno() = 0;
        *__errno() = 9;
        result = 0xffffffff;
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_405273;
    return result;
}

int32_t sub_405274(void* arg1 @ ebp)
{
    return sub_407e6b(*(arg1 + 8));
}

int32_t sub_40527e()
{
    int32_t __saved_ebp_1 = 0x54;
    int32_t var_8 = 0x40e5e8;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e5e8 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_78 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_78;
    void* const var_7c_6 = &data_40528a;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_8_1 = 0;
    STARTUPINFOA startupInfo;
    GetStartupInfoA(&startupInfo);
    int32_t var_8_2 = 0xfffffffe;
    int32_t var_80 = 0x20;
    void* eax = sub_40659b(0x20, 0x28);
    int32_t result;
    
    if (!eax)
    {
    label_4054b5:
        result = 0xffffffff;
    }
    else
    {
        data_410c40 = eax;
        data_410c24 = 0x20;
        
        for (void* i = eax + 0x500; eax < i; i = data_410c40 + 0x500)
        {
            *(eax + 4) = 0;
            *eax = 0xffffffff;
            *(eax + 5) = 0xa;
            *(eax + 8) = 0;
            *(eax + 0x24) = 0;
            *(eax + 0x25) = 0xa;
            *(eax + 0x26) = 0xa;
            eax += 0x28;
        }
        
        if (startupInfo.cbReserved2)
        {
            BYTE* lpReserved2 = startupInfo.lpReserved2;
            
            if (lpReserved2)
            {
                int32_t i_1 = *lpReserved2;
                void* ebx_1 = &lpReserved2[4];
                void* var_20_1 = ebx_1 + i_1;
                
                if (i_1 >= 0x800)
                    i_1 = 0x800;
                
                int32_t esi_1 = 1;
                
                while (data_410c24 < i_1)
                {
                    void* eax_2 = sub_40659b(0x20, 0x28);
                    
                    if (!eax_2)
                    {
                        i_1 = data_410c24;
                        break;
                    }
                    
                    (&data_410c40)[esi_1] = eax_2;
                    data_410c24 += 0x20;
                    
                    for (void* j = eax_2 + 0x500; eax_2 < j; j = (&data_410c40)[esi_1] + 0x500)
                    {
                        *(eax_2 + 4) = 0;
                        *eax_2 = 0xffffffff;
                        *(eax_2 + 5) = 0xa;
                        *(eax_2 + 8) = 0;
                        *(eax_2 + 0x24) &= 0x80;
                        *(eax_2 + 0x25) = 0xa;
                        *(eax_2 + 0x26) = 0xa;
                        eax_2 += 0x28;
                    }
                    
                    esi_1 += 1;
                }
                
                int32_t var_24_1 = 0;
                
                if (i_1 > 0)
                {
                    do
                    {
                        HANDLE hFile_1 = *var_20_1;
                        
                        if (hFile_1 != 0xffffffff && hFile_1 != 0xfffffffe)
                        {
                            void* eax_3;
                            eax_3 = *ebx_1;
                            
                            if (eax_3 & 1)
                            {
                                enum FILE_TYPE eax_4;
                                
                                if (!(eax_3 & 8))
                                    eax_4 = GetFileType(hFile_1);
                                
                                if (eax_3 & 8 || eax_4)
                                {
                                    int32_t* esi_5 =
                                        (var_24_1 & 0x1f) * 0x28 + (&data_410c40)[var_24_1 >> 5];
                                    *esi_5 = *var_20_1;
                                    int32_t eax_8;
                                    eax_8 = *ebx_1;
                                    esi_5[1] = eax_8;
                                    
                                    if (!sub_4072c7(&esi_5[3], 0xfa0))
                                        goto label_4054b5;
                                    
                                    esi_5[2] += 1;
                                }
                            }
                        }
                        
                        var_24_1 += 1;
                        ebx_1 += 1;
                        var_20_1 += 4;
                    } while (var_24_1 < i_1);
                }
            }
        }
        
        for (int32_t i_2 = 0; i_2 < 3; i_2 += 1)
        {
            int32_t* esi_8 = i_2 * 0x28 + data_410c40;
            int32_t eax_11 = *esi_8;
            
            if (eax_11 == 0xffffffff || eax_11 == 0xfffffffe)
            {
                esi_8[1] = 0x81;
                enum STD_HANDLE nStdHandle;
                
                if (i_2)
                {
                    int32_t eax_14 = -((i_2 - 1));
                    nStdHandle = eax_14 - eax_14 - 0xb;
                }
                else
                {
                    int32_t var_7c_2 = 0xfffffff6;
                    nStdHandle = STD_INPUT_HANDLE;
                }
                
                HANDLE hFile = GetStdHandle(nStdHandle);
                enum FILE_TYPE eax_16;
                
                if (hFile != 0xffffffff && hFile)
                    eax_16 = GetFileType(hFile);
                
                if (hFile == 0xffffffff || !hFile || !eax_16)
                {
                    esi_8[1] |= 0x40;
                    *esi_8 = 0xfffffffe;
                }
                else
                {
                    *esi_8 = hFile;
                    int32_t eax_17 = eax_16 & 0xff;
                    
                    if (eax_17 == 2)
                        esi_8[1] |= 0x40;
                    else if (eax_17 == 3)
                        esi_8[1] |= 8;
                    
                    if (!sub_4072c7(&esi_8[3], 0xfa0))
                        goto label_4054b5;
                    
                    esi_8[2] += 1;
                }
            }
            else
                esi_8[1] |= 0x80;
        }
        
        SetHandleCount(data_410c24);
        result = 0;
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_4054bd;
    return result;
}

int32_t sub_4054a7() __pure
{
    return 1;
}

int32_t* sub_4054be(int32_t arg1, char* arg2, int32_t arg3, int32_t* arg4)
{
    char* esi = arg2;
    int32_t var_8 = data_4107dc;
    int32_t var_10 = 0;
    int32_t var_c = 0;
    int32_t var_14 = 0;
    
    while (*esi == 0x20)
        esi = &esi[1];
    
    int32_t eax;
    eax = *esi;
    int32_t var_8_1;
    
    if (eax == 0x61)
    {
        arg2 = 0x109;
        var_8_1 = var_8 | 2;
    }
    else if (eax == 0x72)
    {
        var_8_1 = var_8 | 1;
        arg2 = nullptr;
    }
    else
    {
        if (eax != 0x77)
        {
            *__errno() = 0x16;
            sub_4041db(0, 0, 0, 0, 0);
            return nullptr;
        }
        
        arg2 = 0x301;
        var_8_1 = var_8 | 2;
    }
    
    int32_t ecx_1 = 1;
    void* esi_1 = &esi[1];
    eax = *esi_1;
    
    if (eax)
    {
        while (true)
        {
            if (ecx_1)
            {
                eax = eax;
                
                if (eax > 0x53)
                {
                    if (eax != 0x54)
                    {
                        if (eax != 0x62)
                        {
                            if (eax != 0x63)
                            {
                                if (eax != 0x6e)
                                {
                                    if (eax != 0x74)
                                        goto label_405709;
                                    
                                    if (arg2 & 0xc000)
                                        ecx_1 = 0;
                                    else
                                        arg2 |= 0x4000;
                                }
                                else if (var_10)
                                    ecx_1 = 0;
                                else
                                {
                                    var_8_1 &= 0xffffbfff;
                                    var_10 = 1;
                                }
                            }
                            else if (var_10)
                                ecx_1 = 0;
                            else
                            {
                                var_8_1 |= 0x4000;
                                var_10 = 1;
                            }
                        }
                        else if (arg2 & 0xc000)
                            ecx_1 = 0;
                        else
                            arg2 |= 0x8000;
                    }
                    else if (!(arg2 & 0x1000))
                        arg2 |= 0x1000;
                    else
                        ecx_1 = 0;
                }
                else if (eax != 0x53)
                {
                    if (eax != 0x20)
                    {
                        if (eax != 0x2b)
                        {
                            if (eax == 0x2c)
                            {
                                var_14 = 1;
                                ecx_1 = 0;
                            }
                            else if (eax != 0x44)
                            {
                                if (eax == 0x4e)
                                    arg2 |= 0x80;
                                else
                                {
                                    if (eax != 0x52)
                                        goto label_405709;
                                    
                                    if (var_c)
                                        ecx_1 = 0;
                                    else
                                    {
                                        arg2 |= 0x10;
                                        var_c = 1;
                                    }
                                }
                            }
                            else if (arg2 & 0x40)
                                ecx_1 = 0;
                            else
                                arg2 |= 0x40;
                        }
                        else if (arg2 & 2)
                            ecx_1 = 0;
                        else
                        {
                            arg2 = (arg2 & 0xfffffffe) | 2;
                            var_8_1 = (var_8_1 & 0xfffffffc) | 0x80;
                        }
                    }
                }
                else if (var_c)
                    ecx_1 = 0;
                else
                {
                    arg2 |= 0x20;
                    var_c = 1;
                }
                
                esi_1 += 1;
                eax = *esi_1;
                
                if (eax)
                    continue;
            }
            
            if (!var_14)
                break;
            
            while (*esi_1 == 0x20)
                esi_1 += 1;
            
            if (sub_4095e4("ccs=", esi_1, 4))
                goto label_405709;
            
            if (!sub_409468(esi_1 + 4, "UTF-8"))
            {
                esi_1 += 9;
                arg2 |= 0x40000;
                break;
            }
            
            if (!sub_409468(esi_1 + 4, "UTF-16LE"))
            {
                esi_1 += 0xc;
                arg2 |= 0x20000;
                break;
            }
            
            if (sub_409468(esi_1 + 4, "UNICODE"))
                goto label_405709;
            
            esi_1 += 0xb;
            arg2 |= 0x10000;
            break;
        }
    }
    
    while (*esi_1 == 0x20)
        esi_1 += 1;
    
    if (!*esi_1)
    {
        if (!sub_409230(&var_14, arg1, arg2, arg3, 0x180))
        {
            data_4101a0 += 1;
            arg4[3] = var_8_1;
            int32_t ecx_6 = var_14;
            arg4[1] = 0;
            *arg4 = 0;
            arg4[2] = 0;
            arg4[7] = 0;
            arg4[4] = ecx_6;
            return arg4;
        }
    }
    else
    {
    label_405709:
        *__errno() = 0x16;
        sub_4041db(0, 0, 0, 0, 0);
    }
    
    return nullptr;
}

int32_t* sub_405760()
{
    int32_t __saved_ebp_1 = 0x10;
    int32_t var_8 = 0x40e608;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e608 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_34 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_34;
    void* const var_38_5 = &data_40576c;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t* result = nullptr;
    int32_t var_20 = 0;
    sub_402690(1);
    int32_t var_8_1 = 0;
    int32_t esi = 0;
    
    while (true)
    {
        int32_t var_24_1 = esi;
        
        if (esi >= data_411d80)
            break;
        
        int32_t* eax_1 = data_410d7c + (esi << 2);
        
        if (!*eax_1)
        {
            int32_t** esi_1 = esi << 2;
            *(esi_1 + data_410d7c) = sub_40655b(0x38);
            void* eax_10 = data_410d7c + esi_1;
            
            if (!*eax_10)
                break;
            
            bool cond:0_1 = sub_4072c7(*eax_10 + 0x20, 0xfa0);
            int32_t eax_14 = data_410d7c;
            
            if (!cond:0_1)
            {
                sub_40139b(*(esi_1 + eax_14));
                *(esi_1 + data_410d7c) = 0;
                break;
            }
            
            EnterCriticalSection(*(esi_1 + eax_14) + 0x20);
            result = *(esi_1 + data_410d7c);
        }
        else
        {
            int32_t* result_2;
            
            if (*(*eax_1 + 0xc) & 0x83)
            {
                esi += 1;
                continue;
            }
            else
            {
                if (esi - 3 <= 0x10 && !sub_4025cd(esi + 0x10))
                    break;
                
                sub_40214c(esi, *(data_410d7c + (esi << 2)));
                result_2 = *(data_410d7c + (esi << 2));
                
                if (result_2[3] & 0x83)
                {
                    sub_40219e(esi, result_2);
                    esi += 1;
                    continue;
                }
            }
            
            result = result_2;
        }
        
        int32_t* result_1 = result;
        break;
    }
    
    if (result)
    {
        result[1] = 0;
        result[3] = 0;
        result[2] = 0;
        *result = 0;
        result[7] = 0;
        result[4] = 0xffffffff;
    }
    
    int32_t var_8_2 = 0xfffffffe;
    sub_40587d();
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_405879;
    return result;
}

int32_t sub_40587d()
{
    return __unlock(1);
}

void* __local_unwind4(int32_t arg1, void* arg2, int32_t arg3)
{
    int32_t ebp;
    int32_t var_10 = ebp;
    int32_t var_14 = arg1;
    void* var_18 = arg2;
    int32_t var_1c = arg3;
    int32_t var_20 = arg3;
    int32_t (* var_24)(int32_t arg1, void* arg2, void** arg3) = __unwind_handler4;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t var_20_1 = __security_cookie ^ &ExceptionList;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    
    while (true)
    {
        int32_t esi_1 = *(arg2 + 0xc);
        
        if (esi_1 == 0xfffffffe)
        {
            fsbase->NtTib.ExceptionList = ExceptionList;
            return arg2;
        }
        
        if (arg3 != 0xfffffffe && esi_1 <= arg3)
        {
            fsbase->NtTib.ExceptionList = ExceptionList;
            return arg2;
        }
        
        int32_t* ebx_3 = (*(arg2 + 8) ^ *arg1) + esi_1 * 0xc + 0x10;
        *(arg2 + 0xc) = *ebx_3;
        
        if (!ebx_3[1])
        {
            __NLG_Notify(ebx_3[2], ebp, 0x101);
            ebx_3[2];
            __NLG_Call();
        }
    }
}

int32_t __unwind_handler4(int32_t arg1, void* arg2, void** arg3)
{
    if (!(*(arg1 + 4) & 6))
        return 1;
    
    sub_4076f5(*(arg2 + 8) ^ arg2);
    *(arg2 + 0x18);
    __local_unwind4(*(arg2 + 0x14), *(arg2 + 0x10), *(arg2 + 0xc));
    *arg3 = arg2;
    return 3;
}

void* __stdcall __seh_longjmp_unwind4@4(int32_t* arg1)
{
    *arg1;
    return __local_unwind4(arg1[0xa], arg1[6], arg1[7]);
}

int32_t @_EH4_CallFilterFunc@8()
{
    int32_t ecx;
    return ecx();
}

int32_t __fastcall sub_4059aa(int32_t arg1)
{
    return RtlUnwind(arg1, 0x4059bf, nullptr, nullptr);
}

void* __fastcall @_EH4_LocalUnwind@16(void* arg1, int32_t arg2, int32_t arg3, int32_t arg4)
{
    return __local_unwind4(arg4, arg1, arg2);
}

int32_t sub_4059db(int32_t* arg1)
{
    if (sub_4079ce(sub_403bb8(arg1)))
    {
        int32_t eax_2;
        
        if (arg1 == 0x40f158)
        {
            eax_2 = 0;
        label_405a11:
            data_4101a0 += 1;
            
            if (!(arg1[3] & 0x10c))
            {
                void* eax_3;
                
                if (!*((eax_2 << 2) + &data_410674))
                {
                    eax_3 = sub_40655b(0x1000);
                    *((eax_2 << 2) + &data_410674) = eax_3;
                }
                
                if (*((eax_2 << 2) + &data_410674) || eax_3)
                {
                    int32_t edi_1 = *((eax_2 << 2) + &data_410674);
                    arg1[2] = edi_1;
                    *arg1 = edi_1;
                    arg1[6] = 0x1000;
                    arg1[1] = 0x1000;
                }
                else
                {
                    arg1[2] = &arg1[5];
                    *arg1 = &arg1[5];
                    arg1[6] = 2;
                    arg1[1] = 2;
                }
                
                arg1[3] |= 0x1102;
                return 1;
            }
        }
        else if (arg1 == 0x40f178)
        {
            eax_2 = 1;
            goto label_405a11;
        }
    }
    
    return 0;
}

void sub_405a71(int32_t arg1, int32_t* arg2)
{
    if (!arg1 || !(arg2[3] & 0x1000))
        return;
    
    sub_403be5(arg2);
    arg2[3] &= 0xffffeeff;
    arg2[6] = 0;
    *arg2 = 0;
    arg2[2] = 0;
}

int32_t* __thiscall sub_405aa0(int32_t* arg1, int32_t* arg2)
{
    arg1[3] = 0;
    
    if (arg2)
    {
        *arg1 = *arg2;
        arg1[1] = arg2[1];
    }
    else
    {
        void* eax = __getptd();
        arg1[2] = eax;
        *arg1 = *(eax + 0x6c);
        arg1[1] = *(eax + 0x68);
        
        if (*arg1 != data_40ff38 && !(*(eax + 0x70) & data_40fe54))
            *arg1 = sub_40a052();
        
        if (arg1[1] != data_40fd58 && !(*(arg1[2] + 0x70) & data_40fe54))
            arg1[1] = sub_409941();
        
        void* eax_5 = arg1[2];
        
        if (!(*(eax_5 + 0x70) & 2))
        {
            *(eax_5 + 0x70) |= 2;
            arg1[3] = 1;
        }
    }
    
    return arg1;
}

void __convention("regparm") sub_405b22(uint32_t arg1, int32_t arg2, int32_t* arg3, int32_t* arg4 @ esi)
{
    if (!(arg3[3] & 0x40) || arg3[2])
    {
        int32_t temp0_1 = arg3[1];
        arg3[1] -= 1;
        
        if (temp0_1 - 1 < 0)
        {
            int32_t* var_4_1 = arg3;
            arg1 = sub_4033b6(arg1);
        }
        else
        {
            **arg3 = arg1;
            *arg3 += 1;
            arg1 = arg1;
        }
        
        if (arg1 == 0xffffffff)
        {
            *arg4 |= arg1;
            return;
        }
    }
    
    *arg4 += 1;
}

void __convention("regparm") sub_405b55(uint32_t arg1, char arg2, int32_t arg3, int32_t* arg4)
{
    int32_t* esi = arg1;
    
    while (arg3 > 0)
    {
        arg1 = arg2;
        arg3 -= 1;
        int32_t edx;
        arg1 = sub_405b22(arg1, edx, arg4, esi);
        
        if (*esi == 0xffffffff)
            break;
    }
}

void __convention("regparm") sub_405b79(uint32_t arg1, int32_t arg2, char* arg3, int32_t* arg4 @ edi, uint32_t arg5)
{
    int32_t* esi = arg1;
    char* ebx = arg3;
    
    if (arg4[3] & 0x40 && !arg4[2])
    {
        *esi += arg5;
        return;
    }
    
    while (arg5 > 0)
    {
        arg1 = *ebx;
        arg5 -= 1;
        arg1 = sub_405b22(arg1, arg2, arg4, esi);
        ebx = &ebx[1];
        
        if (*esi == 0xffffffff)
        {
            int32_t edx;
            arg1 = __errno();
            
            if (*arg1 != 0x2a)
                break;
            
            arg1 = 0x3f;
            arg1 = sub_405b22(arg1, edx, arg4, esi);
        }
    }
}

void* sub_405bc3(int32_t* arg1, char* arg2, int32_t* arg3, int32_t* arg4)
{
    void var_1fc;
    int32_t eax_1 = __security_cookie ^ &var_1fc;
    char* ebx = arg2;
    int32_t* edi = arg4;
    void* var_228 = edi;
    int32_t var_248 = 0;
    int16_t* i_4 = nullptr;
    int32_t var_23c = 0;
    int16_t* i_3 = nullptr;
    uint32_t var_238 = 0;
    int32_t var_24c = 0;
    int32_t var_240 = 0;
    void var_260;
    sub_405aa0(&var_260, arg3);
    void* result;
    void* var_258;
    char var_254;
    
    if (arg1)
    {
        void* eax_5 = arg1;
        int32_t edx;
        
        if (!(*(eax_5 + 0xc) & 0x40))
        {
            bool cond:0_1 = sub_403bb8(eax_5) == 0xffffffff;
            bool cond:2_1;
            
            if (!cond:0_1)
                cond:2_1 = sub_403bb8(arg1) == 0xfffffffe;
            
            void* eax_13;
            
            if (cond:0_1 || cond:2_1)
                eax_13 = &data_40f820;
            else
            {
                void* esi_1 = &(&data_410c40)[sub_403bb8(arg1) >> 5];
                eax_13 = (sub_403bb8(arg1) & 0x1f) * 0x28 + *esi_1;
            }
            
            if (*(eax_13 + 0x24) & 0x7f)
                goto label_405c2c;
            
            int32_t eax_14;
            eax_14 = sub_403bb8(arg1);
            int32_t eax_15;
            
            if (eax_14 != 0xffffffff)
                eax_15 = sub_403bb8(arg1);
            
            if (eax_14 == 0xffffffff || eax_15 == 0xfffffffe)
                eax_5 = &data_40f820;
            else
            {
                void* esi_2 = &(&data_410c40)[sub_403bb8(arg1) >> 5];
                int32_t eax_18;
                eax_18 = sub_403bb8(arg1);
                eax_5 = (eax_18 & 0x1f) * 0x28 + *esi_2;
            }
            
            if (*(eax_5 + 0x24) & 0x80 || !ebx)
                goto label_405c2c;
        }
        else if (!ebx)
            goto label_405c2c;
        
        edx = *ebx;
        void* ecx_7 = nullptr;
        void* result_1 = nullptr;
        void* var_224 = nullptr;
        void* i_14 = nullptr;
        char var_215_1 = edx;
        
        if (edx)
        {
            while (true)
            {
                void* var_244_1 = &ebx[1];
                
                if (result_1 < 0)
                    break;
                
                eax_5 = edx;
                eax_5 -= 0x20;
                int32_t eax_23;
                
                if (eax_5 > 0x58)
                    eax_23 = 0;
                else
                    eax_23 = data_40d750[edx] & 0xf;
                
                eax_5 = *(ecx_7 + (eax_23 << 3) + 0x40d770) >> 4;
                int16_t* i = 7;
                void* var_270_1 = eax_5;
                int32_t var_274;
                
                switch (eax_5)
                {
                    case nullptr:
                    {
                        goto label_405f0d;
                    }
                    case 1:
                    {
                        i_3 = 0xffffffff;
                        var_274 = 0;
                        var_24c = 0;
                        var_23c = 0;
                        var_238 = 0;
                        i_4 = nullptr;
                        var_240 = 0;
                        break;
                    }
                    case 2:
                    {
                        int32_t eax_25 = edx;
                        
                        if (eax_25 == 0x20)
                            i_4 |= 2;
                        else if (eax_25 == 0x23)
                            i_4 |= 0x80;
                        else if (eax_25 == 0x2b)
                            i_4 |= 1;
                        else if (eax_25 == 0x2d)
                            i_4 |= 4;
                        else if (eax_25 == 0x30)
                            i_4 |= 8;
                        break;
                    }
                    case 3:
                    {
                        if (edx != 0x2a)
                            var_23c = var_23c * 0xa + edx - 0x30;
                        else
                        {
                            var_228 = &edi[1];
                            int32_t edi_2 = *edi;
                            var_23c = edi_2;
                            
                            if (edi_2 < 0)
                            {
                                i_4 |= 4;
                                var_23c = -(var_23c);
                            }
                        }
                        break;
                    }
                    case 4:
                    {
                        i_3 = nullptr;
                        break;
                    }
                    case 5:
                    {
                        if (edx != 0x2a)
                            i_3 = i_3 * 0xa + edx - 0x30;
                        else
                        {
                            var_228 = &edi[1];
                            int16_t* i_12 = *edi;
                            i_3 = i_12;
                            
                            if (i_12 < 0)
                                i_3 = 0xffffffff;
                        }
                        break;
                    }
                    case 6:
                    {
                        if (edx == 0x49)
                        {
                            eax_5 = ebx[1];
                            
                            if (eax_5 == 0x36 && ebx[2] == 0x34)
                            {
                                i_4 |= 0x8000;
                                var_244_1 = &ebx[3];
                            }
                            else if (eax_5 == 0x33 && ebx[2] == 0x32)
                            {
                                i_4 &= 0xffff7fff;
                                var_244_1 = &ebx[3];
                            }
                            else if (eax_5 != 0x64 && eax_5 != 0x69 && eax_5 != 0x6f
                                && eax_5 != 0x75 && eax_5 != 0x78 && eax_5 != 0x58)
                            {
                                var_270_1 = nullptr;
                            label_405f0d:
                                var_240 = 0;
                                uint32_t eax_32;
                                int32_t edx_1;
                                eax_32 = sub_407c18(edx, &var_260);
                                bool cond:8_1 = !eax_32;
                                eax_32 = var_215_1;
                                
                                if (!cond:8_1)
                                {
                                    eax_32 = sub_405b22(eax_32, edx_1, arg1, &result_1);
                                    eax_32 = ebx[1];
                                    var_244_1 = &ebx[2];
                                }
                                
                                if (!cond:8_1 && !eax_32)
                                {
                                label_4064fe:
                                    *__errno() = 0x16;
                                    int32_t var_29c_3;
                                    __builtin_memset(&var_29c_3, 0, 0x14);
                                    goto label_405c33;
                                }
                                
                                eax_5 = sub_405b22(eax_32, edx_1, arg1, &result_1);
                            }
                        }
                        else if (edx == 0x68)
                            i_4 |= 0x20;
                        else if (edx == 0x6c)
                        {
                            if (ebx[1] != 0x6c)
                                i_4 |= 0x10;
                            else
                            {
                                i_4 |= 0x1000;
                                var_244_1 = &ebx[2];
                            }
                        }
                        else if (edx == 0x77)
                            i_4 |= 0x800;
                        break;
                    }
                    case 7:
                    {
                        eax_5 = edx;
                        char var_234;
                        int16_t* i_2;
                        
                        if (eax_5 > 0x64)
                        {
                            if (eax_5 > 0x70)
                            {
                                if (eax_5 != 0x73)
                                {
                                    if (eax_5 == 0x75)
                                        goto label_406148;
                                    
                                    if (eax_5 != 0x78)
                                        goto label_4063c8;
                                    
                                    var_248 = 0x27;
                                    goto label_406279;
                                }
                                
                            label_405fcd:
                                i = i_3;
                                
                                if (i == 0xffffffff)
                                    i = 0x7fffffff;
                                
                                var_228 = &edi[1];
                                int16_t* i_13 = *edi;
                                i_2 = i_13;
                                
                                if (!(i_4 & 0x810))
                                {
                                    if (!i_13)
                                        i_2 = data_40f850;
                                    
                                    int16_t* i_9 = i_2;
                                    
                                    while (i)
                                    {
                                        i -= 1;
                                        
                                        if (!*i_9)
                                            break;
                                        
                                        i_9 += 1;
                                    }
                                    
                                    eax_5 = i_9 - i_2;
                                }
                                else
                                {
                                    if (!i_13)
                                        i_2 = data_40f854;
                                    
                                    int16_t* i_8 = i_2;
                                    var_240 = 1;
                                    
                                    while (i)
                                    {
                                        i -= 1;
                                        
                                        if (!*i_8)
                                            break;
                                        
                                        i_8 = &i_8[1];
                                    }
                                    
                                    eax_5 = (i_8 - i_2) >> 1;
                                }
                                
                                goto label_4063c5;
                            }
                            
                            if (eax_5 == 0x70)
                            {
                                i_3 = 8;
                            label_40624f:
                                var_248 = 7;
                            label_406279:
                                var_224 = 0x10;
                                
                                if (i_4 & 0x80)
                                {
                                    eax_5 = var_248;
                                    eax_5 += 0x51;
                                    var_234 = 0x30;
                                    char var_233_1 = eax_5;
                                    var_238 = 2;
                                }
                                
                                goto label_40614f;
                            }
                            
                            if (eax_5 < 0x65)
                                goto label_4063c8;
                            
                            if (eax_5 <= 0x67)
                                goto label_405f86;
                            
                            if (eax_5 == 0x69)
                                goto label_406144;
                            
                            if (eax_5 != 0x6e)
                            {
                                if (eax_5 != 0x6f)
                                    goto label_4063c8;
                                
                                var_224 = 8;
                                
                                if (i_4 & 0x80)
                                    i_4 |= 0x200;
                                
                                goto label_40614f;
                            }
                            
                            int16_t* esi_5 = *edi;
                            var_228 = &edi[1];
                            
                            if (!sub_40a0c8())
                                goto label_4064fe;
                            
                            if (!(i_4 & 0x20))
                                *esi_5 = result_1;
                            else
                            {
                                eax_5 = result_1;
                                *esi_5 = eax_5;
                            }
                            
                            var_24c = 1;
                        }
                        else
                        {
                            if (eax_5 == 0x64)
                            {
                            label_406144:
                                i_4 |= 0x40;
                            label_406148:
                                var_224 = 0xa;
                            label_40614f:
                                i = i_4;
                                uint32_t eax_48;
                                
                                if (i >= 0 && !(i & 0x1000))
                                {
                                    void* edi_8 = &edi[1];
                                    
                                    if (!(i & 0x20))
                                    {
                                        eax_48 = *(edi_8 - 4);
                                        
                                        if (!(i & 0x40))
                                            edx = 0;
                                        else
                                            edx = HIGHD(eax_48);
                                            eax_48 = LOWD(eax_48);
                                        
                                        var_228 = edi_8;
                                    }
                                    else
                                    {
                                        var_228 = edi_8;
                                        int32_t eax_58;
                                        
                                        if (!(i & 0x40))
                                            eax_58 = *(edi_8 - 4);
                                        else
                                            eax_58 = *(edi_8 - 4);
                                        
                                        edx = HIGHD(eax_58);
                                        eax_48 = LOWD(eax_58);
                                    }
                                }
                                else
                                {
                                    eax_48 = *edi;
                                    edx = edi[1];
                                    var_228 = &edi[2];
                                }
                                
                                if (i & 0x40 && edx <= 0 && (edx < 0 || eax_48 < 0))
                                {
                                    uint32_t temp17_1 = eax_48;
                                    eax_48 = -(eax_48);
                                    edx = -((edx + 0));
                                    i_4 |= 0x100;
                                }
                                
                                uint32_t ebx_8 = edx;
                                uint32_t edi_12 = eax_48;
                                
                                if (!(i_4 & 0x9000))
                                    ebx_8 = 0;
                                
                                if (i_3 >= 0)
                                {
                                    i_4 &= 0xfffffff7;
                                    
                                    if (i_3 > 0x200)
                                        i_3 = 0x200;
                                }
                                else
                                    i_3 = 1;
                                
                                if (!(edi_12 | ebx_8))
                                    var_238 = 0;
                                
                                void var_11;
                                char* esi_8 = &var_11;
                                
                                while (true)
                                {
                                    int16_t* i_7 = i_3;
                                    i_3 -= 1;
                                    
                                    if (i_7 <= 0 && !(edi_12 | ebx_8))
                                        break;
                                    
                                    int32_t eax_64;
                                    uint32_t edx_3;
                                    edx_3 = HIGHD(var_224);
                                    eax_64 = LOWD(var_224);
                                    uint32_t eax_65;
                                    void* ecx_19;
                                    eax_65 = __aulldvrm(edi_12, ebx_8, eax_64, edx_3);
                                    i = ecx_19 + 0x30;
                                    uint32_t var_264_2 = ebx_8;
                                    edi_12 = eax_65;
                                    ebx_8 = edx;
                                    
                                    if (i > 0x39)
                                        i += var_248;
                                    
                                    *esi_8 = i;
                                    esi_8 -= 1;
                                }
                                
                                eax_5 = &var_11 - esi_8;
                                var_224 = eax_5;
                                i_2 = &esi_8[1];
                                
                                if (!(i_4 & 0x200))
                                    goto label_4063c8;
                                
                                if (eax_5)
                                    i = &esi_8[1];
                                
                                if (eax_5 && *i == 0x30)
                                    goto label_4063c8;
                                
                                i_2 -= 1;
                                i = i_2;
                                *i = 0x30;
                                eax_5 += 1;
                                goto label_4063c5;
                            }
                            
                            char* i_1;
                            char var_210;
                            
                            if (eax_5 <= 0x53)
                            {
                                if (eax_5 == 0x53)
                                {
                                    if (!(i_4 & 0x830))
                                        i_4 |= 0x800;
                                    
                                    goto label_405fcd;
                                }
                                
                                if (eax_5 != 0x41)
                                {
                                    void* eax_34 = eax_5 - 0x42;
                                    
                                    if (eax_34 == 1)
                                    {
                                        if (!(i_4 & 0x830))
                                            i_4 |= 0x800;
                                        
                                        goto label_406033;
                                    }
                                    
                                    if (eax_34 == 3 || eax_34 == 5)
                                        goto label_405f79;
                                    
                                    goto label_4063c8;
                                }
                                
                            label_405f79:
                                edx += 0x20;
                                var_274 = 1;
                                var_215_1 = edx;
                            label_405f86:
                                i_4 |= 0x40;
                                char* i_10 = &var_210;
                                i_2 = &var_210;
                                uint32_t var_264_1 = 0x200;
                                
                                if (i_3 < 0)
                                    i_3 = 6;
                                else if (i_3)
                                {
                                    if (i_3 > 0x200)
                                        i_3 = 0x200;
                                    
                                    if (i_3 > 0xa3)
                                    {
                                        void* i_6;
                                        i_6 = sub_40655b(i_3 + 0x15d);
                                        edx = var_215_1;
                                        i_14 = i_6;
                                        
                                        if (!i_6)
                                            i_3 = 0xa3;
                                        else
                                        {
                                            i_2 = i_6;
                                            var_264_1 = i_3 + 0x15d;
                                            i_10 = i_6;
                                        }
                                    }
                                }
                                else if (edx == 0x67)
                                    i_3 = 1;
                                
                                int32_t var_27c = *edi;
                                int32_t var_278_1 = edi[1];
                                var_228 = &edi[2];
                                sub_406d52(data_40f90c)(&var_27c, i_10, var_264_1, edx, i_3, 
                                    var_274, &var_260);
                                void* edi_11 = i_4 & 0x80;
                                
                                if (edi_11 && !i_3)
                                    sub_406d52(data_40f918)(i_10, &var_260);
                                
                                if (var_215_1 == 0x67 && !edi_11)
                                    sub_406d52(data_40f914)(i_10, &var_260);
                                
                                if (*i_10 == 0x2d)
                                {
                                    i_4 |= 0x100;
                                    i_10 = &i_10[1];
                                    i_2 = i_10;
                                }
                                
                                i_1 = i_10;
                                goto label_4060ba;
                            }
                            
                            if (eax_5 == 0x58)
                                goto label_40624f;
                            
                            void* eax_39 = eax_5 - 0x59;
                            
                            if (eax_39 != 1)
                            {
                                if (eax_39 == 8)
                                    goto label_405f86;
                                
                                if (eax_39 != 0xa)
                                    goto label_4063c8;
                                
                            label_406033:
                                var_228 = &edi[1];
                                
                                if (!(i_4 & 0x810))
                                {
                                    eax_5 = *edi;
                                    var_210 = eax_5;
                                    var_224 = 1;
                                }
                                else
                                {
                                    int32_t eax_44;
                                    eax_44 = sub_40a23d(&var_224, &var_210, 0x200, *edi);
                                    
                                    if (eax_44)
                                        var_24c = 1;
                                }
                                
                                i_2 = &var_210;
                                goto label_4063c8;
                            }
                            
                            int16_t* eax_45 = *edi;
                            var_228 = &edi[1];
                            
                            if (eax_45)
                                i = *(eax_45 + 4);
                            
                            if (eax_45 && i)
                            {
                                eax_5 = *eax_45;
                                i_2 = i;
                                
                                if (!(i_4 & 0x800))
                                    var_240 = 0;
                                else
                                {
                                    int32_t eax_46;
                                    edx = HIGHD(eax_5);
                                    eax_46 = LOWD(eax_5);
                                    eax_5 = (eax_46 - edx) >> 1;
                                    var_240 = 1;
                                }
                                
                                goto label_4063c5;
                            }
                            
                            char* i_5 = data_40f850;
                            i_2 = i_5;
                            i_1 = i_5;
                        label_4060ba:
                            eax_5 = _strlen(i_1);
                            i = i_1;
                        label_4063c5:
                            var_224 = eax_5;
                        label_4063c8:
                            
                            if (!var_24c)
                            {
                                int16_t eax_69 = i_4;
                                
                                if (eax_69 & 0x40)
                                {
                                    if (eax_69 & 0x100)
                                    {
                                        var_234 = 0x2d;
                                        var_238 = 1;
                                    }
                                    else if (eax_69 & 1)
                                    {
                                        var_234 = 0x2b;
                                        var_238 = 1;
                                    }
                                    else if (eax_69 & 2)
                                    {
                                        var_234 = 0x20;
                                        var_238 = 1;
                                    }
                                }
                                
                                void* ebx_11 = var_23c - var_224 - var_238;
                                
                                if (!(i_4 & 0xc))
                                {
                                    int32_t* var_28c_14 = arg1;
                                    void* var_290_8 = ebx_11;
                                    edx = sub_405b55(&result_1, edx, i, 0x20);
                                }
                                
                                int32_t edx_4 = sub_405b79(&result_1, edx, &var_234, arg1, var_238);
                                
                                if (i_4 & 8 && !(i_4 & 4))
                                {
                                    int32_t* var_28c_16 = arg1;
                                    void* var_290_9 = ebx_11;
                                    edx_4 = sub_405b55(&result_1, edx_4, var_238, 0x30);
                                }
                                
                                void* eax_73 = var_224;
                                uint32_t ecx_22;
                                
                                if (!var_240 || eax_73 <= 0)
                                {
                                    eax_5 = sub_405b79(&result_1, edx_4, i_2, arg1, eax_73);
                                    ecx_22 = eax_73;
                                }
                                else
                                {
                                    int16_t* i_11 = i_2;
                                    void* var_264_3 = eax_73;
                                    
                                    while (true)
                                    {
                                        int32_t* eax_74 = *i_11;
                                        var_264_3 -= 1;
                                        i_11 = &i_11[1];
                                        uint32_t var_26c;
                                        char var_10;
                                        eax_5 = sub_40a23d(&var_26c, &var_10, 6, eax_74);
                                        
                                        if (eax_5 || var_26c == eax_5)
                                        {
                                            result_1 = 0xffffffff;
                                            break;
                                        }
                                        
                                        uint32_t var_28c_18 = var_26c;
                                        eax_5 =
                                            sub_405b79(&result_1, edx, &var_10, arg1, var_28c_18);
                                        ecx_22 = var_28c_18;
                                        
                                        if (!var_264_3)
                                            break;
                                        
                                        continue;
                                    }
                                }
                                
                                if (result_1 >= 0 && i_4 & 4)
                                {
                                    int32_t* var_28c_20 = arg1;
                                    void* var_290_10 = ebx_11;
                                    eax_5 = sub_405b55(&result_1, edx, ecx_22, 0x20);
                                }
                                
                                goto label_4064cd;
                            }
                        }
                    label_4064cd:
                        
                        if (i_14)
                        {
                            eax_5 = sub_40139b(i_14);
                            i_14 = nullptr;
                        }
                        break;
                    }
                }
                
                ebx = var_244_1;
                eax_5 = *ebx;
                var_215_1 = eax_5;
                
                if (!eax_5)
                    break;
                
                ecx_7 = var_270_1;
                edi = var_228;
                edx = eax_5;
            }
        }
        
        if (var_254)
            *(var_258 + 0x70) &= 0xfffffffd;
        
        result = result_1;
    }
    else
    {
    label_405c2c:
        *__errno() = 0x16;
        int32_t var_29c_1;
        __builtin_memset(&var_29c_1, 0, 0x14);
    label_405c33:
        sub_4041db(0, 0, 0, 0, 0);
        
        if (var_254)
            *(var_258 + 0x70) &= 0xfffffffd;
        
        result = 0xffffffff;
    }
    sub_4076f5(eax_1 ^ &var_1fc);
    return result;
}

void* sub_40655b(uint32_t arg1)
{
    uint32_t dwMilliseconds = 0;
    void* result;
    uint32_t i;
    
    do
    {
        result = sub_401986(arg1);
        
        if (result)
            break;
        
        if (data_41067c <= result)
            break;
        
        Sleep(dwMilliseconds);
        i = dwMilliseconds + 0x3e8;
        
        if (i > data_41067c)
            i = 0xffffffff;
        
        dwMilliseconds = i;
    } while (i != 0xffffffff);
    return result;
}

void* sub_40659b(uint32_t arg1, uint32_t arg2)
{
    uint32_t dwMilliseconds = 0;
    void* result;
    uint32_t i;
    
    do
    {
        result = sub_40a2f5(arg1, arg2, nullptr);
        
        if (result)
            break;
        
        if (data_41067c <= result)
            break;
        
        Sleep(dwMilliseconds);
        i = dwMilliseconds + 0x3e8;
        
        if (i > data_41067c)
            i = 0xffffffff;
        
        dwMilliseconds = i;
    } while (i != 0xffffffff);
    return result;
}

void* sub_4065e3(void* arg1, uint32_t arg2)
{
    uint32_t dwMilliseconds = 0;
    void* result;
    uint32_t i;
    
    do
    {
        result = sub_40a413(arg1, arg2);
        
        if (result)
            break;
        
        if (arg2 == result)
            break;
        
        if (data_41067c <= result)
            break;
        
        Sleep(dwMilliseconds);
        i = dwMilliseconds + 0x3e8;
        
        if (i > data_41067c)
            i = 0xffffffff;
        
        dwMilliseconds = i;
    } while (i != 0xffffffff);
    return result;
}

int32_t sub_40662e()
{
    int32_t __saved_ebp_1 = 0x10;
    int32_t var_8 = 0x40e628;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e628 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_34 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_34;
    void* const var_38_4 = &data_40663a;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t result = 0;
    sub_402690(1);
    int32_t var_8_1 = 0;
    int32_t var_38 = 3;
    int32_t edi = 3;
    
    while (true)
    {
        int32_t var_24_1 = edi;
        
        if (edi >= data_411d80)
            break;
        
        int32_t esi_2 = edi << 2;
        int32_t* eax_1 = data_410d7c + esi_2;
        
        if (*eax_1)
        {
            int32_t* eax_2 = *eax_1;
            
            if (eax_2[3] & 0x83 && sub_401643(eax_2) != 0xffffffff)
                result += 1;
            
            if (edi >= 0x14)
            {
                DeleteCriticalSection(*(esi_2 + data_410d7c) + 0x20);
                sub_40139b(*(esi_2 + data_410d7c));
                *(esi_2 + data_410d7c) = 0;
            }
        }
        
        edi += 1;
    }
    
    int32_t var_8_2 = 0xfffffffe;
    sub_4066c4();
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_4066c3;
    return result;
}

int32_t sub_4066c4()
{
    return __unlock(1);
}

int32_t sub_4066cd() __pure
{
    return;
}

int32_t sub_4066ce(int32_t arg1, EXCEPTION_POINTERS* arg2)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t var_c = ecx;
    int32_t esi;
    int32_t var_10 = esi;
    void* eax = sub_406ed9();
    int32_t result;
    int32_t* esp;
    EXCEPTION_POINTERS* ExceptionInfo;
    
    if (eax)
    {
        int32_t* edx_1 = *(eax + 0x5c);
        int32_t eax_1 = data_40f8dc;
        EXCEPTION_POINTERS* ExceptionInfo_1;
        ExceptionInfo = ExceptionInfo_1;
        int32_t* ecx_1 = edx_1;
        int32_t ebx;
        int32_t var_18 = ebx;
        int32_t* esp_1 = &var_18;
        
        while (*ecx_1 != arg1)
        {
            ecx_1 = &ecx_1[3];
            
            if (ecx_1 >= eax_1 * 0xc + edx_1)
                break;
        }
        
        int32_t* eax_4;
        
        if (ecx_1 >= eax_1 * 0xc + edx_1 || *ecx_1 != arg1)
            eax_4 = nullptr;
        else
            eax_4 = ecx_1;
        
        int32_t ebx_4;
        
        if (eax_4)
            ebx_4 = eax_4[2];
        
        if (!eax_4 || !ebx_4)
        {
            result = UnhandledExceptionFilter(arg2);
            esp_1 = &var_18;
        }
        else if (ebx_4 != 5)
        {
            if (ebx_4 != 1)
            {
                int32_t ecx_2 = *(eax + 0x60);
                *(eax + 0x60) = arg2;
                int32_t ecx_4 = eax_4[1];
                
                if (ecx_4 != 8)
                {
                    eax_4[2] = 0;
                    ebx_4(ecx_4);
                }
                else
                {
                    int32_t i_1 = data_40f8d0;
                    int32_t i = i_1;
                    
                    if (i < data_40f8d4 + i_1)
                    {
                        int32_t ecx_5 = i_1 * 0xc;
                        
                        do
                        {
                            *(ecx_5 + *(eax + 0x5c) + 8) = 0;
                            i += 1;
                            ecx_5 += 0xc;
                        } while (i < data_40f8d4 + data_40f8d0);
                    }
                    
                    int32_t edi_5 = *(eax + 0x64);
                    
                    switch (*eax_4)
                    {
                        case 0xc000008d:
                        {
                            *(eax + 0x64) = 0x82;
                            break;
                        }
                        case 0xc000008e:
                        {
                            *(eax + 0x64) = 0x83;
                            break;
                        }
                        case 0xc000008f:
                        {
                            *(eax + 0x64) = 0x86;
                            break;
                        }
                        case 0xc0000090:
                        {
                            *(eax + 0x64) = 0x81;
                            break;
                        }
                        case 0xc0000091:
                        {
                            *(eax + 0x64) = 0x84;
                            break;
                        }
                        case 0xc0000092:
                        {
                            *(eax + 0x64) = 0x8a;
                            break;
                        }
                        case 0xc0000093:
                        {
                            *(eax + 0x64) = 0x85;
                            break;
                        }
                    }
                    
                    int32_t var_1c_2 = *(eax + 0x64);
                    ebx_4(8);
                    *(eax + 0x64) = edi_5;
                }
                
                esp_1 = &ExceptionInfo;
                *(eax + 0x60) = ecx_2;
            }
            
            result = 0xffffffff;
        }
        else
        {
            eax_4[2] = 0;
            result = 1;
        }
        
        *esp_1;
        esp_1[1];
        esp = &esp_1[2];
    }
    else
    {
        ExceptionInfo = arg2;
        result = UnhandledExceptionFilter(ExceptionInfo);
        esp = &var_10;
    }
    *esp;
    return result;
}

int32_t sub_40683d()
{
    if (!data_410d4c)
        ___initmbctable();
    
    char* esi = data_4101a4;
    int32_t edi = 0;
    
    if (esi)
    {
        while (true)
        {
            void* eax;
            eax = *esi;
            
            if (!eax)
                break;
            
            if (eax != 0x3d)
                edi += 1;
            
            esi = esi + _strlen(esi) + 1;
        }
        
        void* edi_2 = sub_40659b(edi + 1, 4);
        data_410334 = edi_2;
        
        if (edi_2)
        {
            char* esi_1 = data_4101a4;
            int32_t result;
            
            while (true)
            {
                if (!*esi_1)
                {
                    sub_40139b(data_4101a4);
                    data_4101a4 = 0;
                    *edi_2 = 0;
                    data_410d40 = 1;
                    result = 0;
                    break;
                }
                
                uint32_t ebp_2 = _strlen(esi_1) + 1;
                
                if (*esi_1 != 0x3d)
                {
                    char* eax_3 = sub_40659b(ebp_2, 1);
                    *edi_2 = eax_3;
                    
                    if (!eax_3)
                    {
                        sub_40139b(data_410334);
                        data_410334 = 0;
                        result = 0xffffffff;
                        break;
                    }
                    
                    if (sub_408a7b(eax_3, ebp_2, esi_1))
                    {
                        int32_t var_24;
                        __builtin_memset(&var_24, 0, 0x14);
                        sub_4040df();
                        /* no return */
                    }
                    
                    edi_2 += 4;
                }
                
                esi_1 = &esi_1[ebp_2];
            }
            
            return result;
        }
    }
    
    return 0xffffffff;
}

void* __convention("regparm") sub_406918(int32_t arg1, char* arg2, int32_t* arg3 @ edi, void* arg4, char* arg5, int32_t* arg6)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t* ecx_1 = arg6;
    int32_t* ebx;
    int32_t* var_c = ebx;
    *arg3 = 0;
    char* esi = arg2;
    char* edx = arg5;
    *ecx_1 = 1;
    
    if (arg4)
    {
        ebx = arg4;
        arg4 += 4;
        *ebx = edx;
    }
    
    void* var_8_1 = nullptr;
    void* eax;
    
    while (true)
    {
        if (*esi != 0x22)
        {
            *arg3 += 1;
            
            if (edx)
            {
                eax = *esi;
                *edx = eax;
                arg5 = &edx[1];
            }
            
            ebx = *esi;
            esi = &esi[1];
            
            if (sub_40a67f(ebx))
            {
                *arg3 += 1;
                
                if (arg5)
                {
                    char* ecx_3 = arg5;
                    eax = *esi;
                    arg5 = &arg5[1];
                    *ecx_3 = eax;
                }
                
                esi = &esi[1];
            }
            
            edx = arg5;
            ecx_1 = arg6;
            
            if (!ebx)
            {
                esi -= 1;
                break;
            }
        }
        else
        {
            ebx = 0x22;
            eax = !var_8_1;
            esi = &esi[1];
            var_8_1 = eax;
        }
        
        if (!var_8_1)
        {
            if (ebx != 0x20 && ebx != 9)
                continue;
            
            if (!edx)
                break;
            
            edx[0xffffffff] = 0;
            break;
        }
    }
    
    void* var_8_2 = nullptr;
    
    while (*esi)
    {
        while (true)
        {
            eax = *esi;
            
            if (eax != 0x20 && eax != 9)
                break;
            
            esi = &esi[1];
        }
        
        if (!*esi)
            break;
        
        if (arg4)
        {
            eax = arg4;
            arg4 += 4;
            *eax = edx;
        }
        
        *ecx_1 += 1;
        
        while (true)
        {
            int32_t ebx_1 = 1;
            uint32_t i = 0;
            
            while (*esi == 0x5c)
            {
                esi = &esi[1];
                i += 1;
            }
            
            if (*esi == 0x22)
            {
                if (!(i & 1))
                {
                    if (!var_8_2 || esi[1] != 0x22)
                    {
                        ebx_1 = 0;
                        eax = !var_8_2;
                        var_8_2 = eax;
                    }
                    else
                        esi = &esi[1];
                }
                
                i u>>= 1;
            }
            
            if (i)
            {
                do
                {
                    i -= 1;
                    
                    if (edx)
                    {
                        *edx = 0x5c;
                        edx = &edx[1];
                    }
                    
                    *arg3 += 1;
                } while (i);
                
                arg5 = edx;
            }
            
            eax = *esi;
            
            if (!eax)
                break;
            
            if (!var_8_2)
            {
                if (eax == 0x20)
                    break;
                
                if (eax == 9)
                    break;
            }
            
            if (ebx_1)
            {
                int32_t eax_2 = eax;
                
                if (!edx)
                {
                    if (sub_40a67f(eax_2))
                    {
                        esi = &esi[1];
                        *arg3 += 1;
                    }
                }
                else
                {
                    if (sub_40a67f(eax_2))
                    {
                        eax = *esi;
                        char* ecx_5 = arg5;
                        arg5 = &arg5[1];
                        *ecx_5 = eax;
                        esi = &esi[1];
                        *arg3 += 1;
                    }
                    
                    char* ecx_6 = arg5;
                    eax = *esi;
                    arg5 = &arg5[1];
                    *ecx_6 = eax;
                }
                
                *arg3 += 1;
                edx = arg5;
            }
            
            esi = &esi[1];
        }
        
        if (edx)
        {
            *edx = 0;
            edx = &edx[1];
            arg5 = edx;
        }
        
        *arg3 += 1;
        ecx_1 = arg6;
    }
    
    if (arg4)
        *arg4 = 0;
    
    *ecx_1 += 1;
    return arg4;
}

int32_t sub_406ab0()
{
    if (!data_410d4c)
        ___initmbctable();
    
    data_410784 = 0;
    void* ecx = GetModuleFileNameA(nullptr, &data_410680, 0x104);
    void* eax = data_410d78;
    data_410344 = &data_410680;
    void* var_8_1;
    
    if (eax)
        var_8_1 = eax;
    
    if (!eax || !*eax)
        var_8_1 = &data_410680;
    
    int32_t var_c;
    int32_t* var_20 = &var_c;
    int32_t var_10;
    sub_406918(&var_c, var_8_1, &var_10, ecx, nullptr, nullptr);
    int32_t eax_2 = var_c;
    
    if (eax_2 < 0x3fffffff)
    {
        int32_t ecx_1 = var_10;
        
        if (ecx_1 < 0xffffffff)
        {
            int32_t edi_2 = eax_2 << 2;
            uint32_t eax_3 = edi_2 + ecx_1;
            
            if (eax_3 >= ecx_1)
            {
                void* eax_4 = sub_40655b(eax_3);
                
                if (eax_4)
                {
                    int32_t* var_20_2 = &var_c;
                    sub_406918(&var_c, var_8_1, &var_10, eax_3, eax_4, edi_2 + eax_4);
                    data_410328 = var_c - 1;
                    data_41032c = eax_4;
                    return 0;
                }
            }
        }
    }
    
    return 0xffffffff;
}

void* sub_406b69()
{
    int32_t ecx;
    int32_t var_4 = ecx;
    int32_t var_8 = ecx;
    int32_t eax = data_410788;
    void* lpMultiByteStr_2 = nullptr;
    PWSTR esi = nullptr;
    
    if (eax)
    {
    label_406bb2:
        
        if (eax != 1)
        {
            if (eax == 2 || !eax)
            {
                int128_t* penv_1 = GetEnvironmentStrings();
                int128_t* penv = penv_1;
                
                if (penv)
                {
                    if (*penv)
                    {
                        while (true)
                        {
                            penv_1 += 1;
                            
                            if (!*penv_1)
                            {
                                penv_1 += 1;
                                
                                if (!*penv_1)
                                    break;
                            }
                        }
                    }
                    
                    void* eax_12 = sub_40655b(penv_1 - penv + 1);
                    
                    if (eax_12)
                    {
                        sub_403d70(eax_12, penv, penv_1 - penv + 1);
                        FreeEnvironmentStringsA(penv);
                        return eax_12;
                    }
                    
                    FreeEnvironmentStringsA(penv);
                }
            }
            
            return nullptr;
        }
    }
    else
    {
        esi = GetEnvironmentStringsW();
        
        if (!esi)
        {
            if (GetLastError() != ERROR_CALL_NOT_IMPLEMENTED)
                eax = data_410788;
            else
            {
                eax = 2;
                data_410788 = 2;
            }
            
            goto label_406bb2;
        }
        
        data_410788 = 1;
    }
    
    if (!esi)
    {
        esi = GetEnvironmentStringsW();
        
        if (!esi)
            return nullptr;
    }
    
    PWSTR eax_4 = esi;
    
    if (*esi)
    {
        while (true)
        {
            eax_4 = &eax_4[1];
            
            if (!*eax_4)
            {
                eax_4 = &eax_4[1];
                
                if (!*eax_4)
                    break;
            }
        }
    }
    
    int32_t cbMultiByte =
        WideCharToMultiByte(0, 0, esi, ((eax_4 - esi) >> 1) + 1, nullptr, 0, nullptr, nullptr);
    
    if (cbMultiByte)
    {
        void* lpMultiByteStr = sub_40655b(cbMultiByte);
        void* lpMultiByteStr_1 = lpMultiByteStr;
        
        if (lpMultiByteStr)
        {
            if (!WideCharToMultiByte(0, 0, esi, ((eax_4 - esi) >> 1) + 1, lpMultiByteStr, 
                cbMultiByte, nullptr, nullptr))
            {
                sub_40139b(lpMultiByteStr_1);
                lpMultiByteStr_1 = nullptr;
            }
            
            lpMultiByteStr_2 = lpMultiByteStr_1;
        }
    }
    
    FreeEnvironmentStringsW(esi);
    return lpMultiByteStr_2;
}

void* const sub_406c9e()
{
    return &data_40e390;
}

void* const sub_406cc2()
{
    return &data_40e398;
}

int32_t sub_406ce6(int32_t arg1)
{
    int32_t eax_4;
    
    if (TlsGetValue(data_40f8e4))
    {
        int32_t eax_1 = data_40f8e0;
        
        if (eax_1 == 0xffffffff)
            goto label_406d1f;
        
        void* eax_3 = TlsGetValue(data_40f8e4)(eax_1);
        
        if (!eax_3)
            goto label_406d1f;
        
        eax_4 = *(eax_3 + 0x1f8);
        goto label_406d35;
    }
    
label_406d1f:
    HMODULE hModule = GetModuleHandleA("KERNEL32.DLL");
    
    if (hModule)
    {
        eax_4 = GetProcAddress(hModule, "EncodePointer");
    label_406d35:
        
        if (eax_4)
            return eax_4(arg1);
    }
    
    return arg1;
}

int32_t sub_406d49()
{
    return sub_406ce6(0);
}

int32_t sub_406d52(int32_t arg1)
{
    int32_t eax_4;
    
    if (TlsGetValue(data_40f8e4))
    {
        int32_t eax_1 = data_40f8e0;
        
        if (eax_1 == 0xffffffff)
            goto label_406d8b;
        
        void* eax_3 = TlsGetValue(data_40f8e4)(eax_1);
        
        if (!eax_3)
            goto label_406d8b;
        
        eax_4 = *(eax_3 + 0x1fc);
        goto label_406da1;
    }
    
label_406d8b:
    HMODULE hModule = GetModuleHandleA("KERNEL32.DLL");
    
    if (hModule)
    {
        eax_4 = GetProcAddress(hModule, "DecodePointer");
    label_406da1:
        
        if (eax_4)
            return eax_4(arg1);
    }
    
    return arg1;
}

uint32_t sub_406db5()
{
    return TlsAlloc();
}

BOOL sub_406dbe()
{
    BOOL result = TlsGetValue(data_40f8e4);
    
    if (result)
        return result;
    
    int32_t lpTlsValue = sub_406d52(data_410790);
    return TlsSetValue(data_40f8e4, lpTlsValue);
}

int32_t sub_406de8()
{
    int32_t eax_2 = data_40f8e0;
    
    if (eax_2 != 0xffffffff)
    {
        sub_406d52(data_410798)(eax_2);
        data_40f8e0 = 0xffffffff;
    }
    
    uint32_t dwTlsIndex = data_40f8e4;
    
    if (dwTlsIndex != 0xffffffff)
    {
        TlsFree(dwTlsIndex);
        data_40f8e4 = 0xffffffff;
    }
    
    /* tailcall */
    return sub_402563();
}

int32_t sub_406e25(void* arg1, int32_t arg2)
{
    int32_t __saved_ebp_1 = 0xc;
    int32_t var_8 = 0x40e648;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e648 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_1 = &data_406e31;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    HMODULE hModule = GetModuleHandleA("KERNEL32.DLL");
    *(arg1 + 0x5c) = 0x40f858;
    *(arg1 + 0x14) = 1;
    
    if (hModule)
    {
        *(arg1 + 0x1f8) = GetProcAddress(hModule, "EncodePointer");
        *(arg1 + 0x1fc) = GetProcAddress(hModule, "DecodePointer");
    }
    
    *(arg1 + 0x70) = 1;
    *(arg1 + 0xc8) = 0x43;
    *(arg1 + 0x14b) = 0x43;
    *(arg1 + 0x68) = 0x40f930;
    InterlockedIncrement(0x40f930);
    sub_402690(0xc);
    int32_t var_8_1 = 0;
    *(arg1 + 0x6c) = arg2;
    
    if (!arg2)
        *(arg1 + 0x6c) = data_40ff38;
    
    sub_409f02(*(arg1 + 0x6c));
    int32_t var_8_2 = 0xfffffffe;
    int32_t result = sub_406ed0();
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_406ecf;
    return result;
}

int32_t sub_406ed0()
{
    return __unlock(0xc);
}

void* sub_406ed9()
{
    enum WIN32_ERROR dwErrCode = GetLastError();
    sub_406dbe();
    void* result = TlsGetValue(data_40f8e4)(data_40f8e0);
    
    if (!result)
    {
        result = sub_40659b(1, 0x214);
        
        if (result)
        {
            if (!sub_406d52(data_410794)(data_40f8e0, result))
            {
                sub_40139b(result);
                result = nullptr;
            }
            else
            {
                sub_406e25(result, 0);
                uint32_t eax_5 = GetCurrentThreadId();
                *(result + 4) = 0xffffffff;
                *result = eax_5;
            }
        }
    }
    
    SetLastError(dwErrCode);
    return result;
}

void* __getptd()
{
    void* result = sub_406ed9();
    
    if (!result)
        sub_404c23(0x10);
    
    return result;
}

struct _EXCEPTION_REGISTRATION_RECORD** __stdcall sub_406f74(void* arg1)
{
    int32_t __saved_ebp_1 = 8;
    int32_t var_8 = 0x40e668;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_5 = 0x40e668 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_2c = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_2c;
    void* const var_30_12 = &data_406f80;
    int32_t var_8_6 = 0xfffffffe;
    int32_t var_c = var_8_5;
    struct _EXCEPTION_REGISTRATION_RECORD** result = &ExceptionList;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    
    if (arg1)
    {
        void* eax = *(arg1 + 0x24);
        
        if (eax)
            sub_40139b(eax);
        
        void* eax_1 = *(arg1 + 0x2c);
        
        if (eax_1)
            sub_40139b(eax_1);
        
        void* eax_2 = *(arg1 + 0x34);
        
        if (eax_2)
            sub_40139b(eax_2);
        
        void* eax_3 = *(arg1 + 0x3c);
        
        if (eax_3)
            sub_40139b(eax_3);
        
        void* eax_4 = *(arg1 + 0x44);
        
        if (eax_4)
            sub_40139b(eax_4);
        
        void* eax_5 = *(arg1 + 0x48);
        
        if (eax_5)
            sub_40139b(eax_5);
        
        void* eax_6 = *(arg1 + 0x5c);
        
        if (eax_6 != 0x40f858)
            sub_40139b(eax_6);
        
        sub_402690(0xd);
        int32_t var_8_1 = 0;
        void* edi_1 = *(arg1 + 0x68);
        
        if (edi_1 && !InterlockedDecrement(edi_1) && edi_1 != 0x40f930)
            sub_40139b(edi_1);
        
        int32_t var_8_2 = 0xfffffffe;
        sub_407080();
        sub_402690(0xc);
        int32_t var_8_3 = 1;
        int32_t* edi_2 = *(arg1 + 0x6c);
        
        if (edi_2)
        {
            sub_409f88(edi_2);
            
            if (edi_2 != data_40ff38 && edi_2 != 0x40fe60 && !*edi_2)
                sub_409dc2(edi_2);
        }
        
        int32_t var_8_4 = 0xfffffffe;
        sub_40708c();
        result = sub_40139b(arg1);
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_40707a;
    return result;
}

int32_t sub_40707d(void* arg1 @ ebp)
{
    *(arg1 + 8);
    /* tailcall */
    return sub_407080();
}

int32_t sub_407080()
{
    return __unlock(0xd);
}

int32_t sub_407089(void* arg1 @ ebp)
{
    *(arg1 + 8);
    /* tailcall */
    return sub_40708c();
}

int32_t sub_40708c()
{
    return __unlock(0xc);
}

int32_t sub_407095()
{
    HMODULE hModule = GetModuleHandleA("KERNEL32.DLL");
    
    if (!hModule)
    {
        sub_406de8();
        return 0;
    }
    
    data_41078c = GetProcAddress(hModule, "FlsAlloc");
    data_410790 = GetProcAddress(hModule, "FlsGetValue");
    data_410794 = GetProcAddress(hModule, "FlsSetValue");
    int32_t eax_4 = GetProcAddress(hModule, "FlsFree");
    bool cond:0 = !data_41078c;
    data_410798 = eax_4;
    
    if (cond:0 || !data_410790 || !data_410794 || !eax_4)
    {
        data_410790 = TlsGetValue;
        data_41078c = sub_406db5;
        data_410794 = TlsSetValue;
        data_410798 = TlsFree;
    }
    
    uint32_t dwTlsIndex = TlsAlloc();
    data_40f8e4 = dwTlsIndex;
    
    if (dwTlsIndex != 0xffffffff && TlsSetValue(dwTlsIndex, data_410790))
    {
        sub_404edf();
        int32_t eax_6 = sub_406ce6(data_41078c);
        int32_t var_10_5 = data_410790;
        data_41078c = eax_6;
        int32_t eax_7 = sub_406ce6(var_10_5);
        int32_t var_14_1 = data_410794;
        data_410790 = eax_7;
        int32_t eax_8 = sub_406ce6(var_14_1);
        int32_t var_18_1 = data_410798;
        data_410794 = eax_8;
        data_410798 = sub_406ce6(var_18_1);
        
        if (sub_40251a())
        {
            int32_t eax_12 = sub_406d52(data_41078c)(sub_406f74);
            data_40f8e0 = eax_12;
            
            if (eax_12 != 0xffffffff)
            {
                void* eax_13 = sub_40659b(1, 0x214);
                
                if (eax_13 && sub_406d52(data_410794)(data_40f8e0, eax_13))
                {
                    sub_406e25(eax_13, 0);
                    uint32_t eax_16 = GetCurrentThreadId();
                    *(eax_13 + 4) = 0xffffffff;
                    *eax_13 = eax_16;
                    return 1;
                }
            }
        }
        
        sub_406de8();
    }
    
    return 0;
}

uint32_t sub_407219()
{
    uint32_t __security_cookie_1 = __security_cookie;
    FILETIME systemTimeAsFileTime;
    __builtin_memset(&systemTimeAsFileTime, 0, 8);
    uint32_t result;
    
    if (__security_cookie_1 == 0xbb40e64e || !(0xffff0000 & __security_cookie_1))
    {
        GetSystemTimeAsFileTime(&systemTimeAsFileTime);
        uint32_t esi_5 = systemTimeAsFileTime.dwHighDateTime ^ systemTimeAsFileTime.dwLowDateTime
            ^ GetCurrentProcessId() ^ GetCurrentThreadId() ^ GetTickCount();
        int32_t performanceCount;
        QueryPerformanceCounter(&performanceCount);
        int32_t var_10;
        result = var_10 ^ performanceCount;
        uint32_t esi_6 = esi_5 ^ result;
        
        if (esi_6 == 0xbb40e64e)
            esi_6 = 0xbb40e64f;
        else if (!(0xffff0000 & esi_6))
        {
            result = esi_6 << 0x10;
            esi_6 |= result;
        }
        
        __security_cookie = esi_6;
        data_40f84c = ~esi_6;
    }
    else
    {
        result = ~__security_cookie_1;
        data_40f84c = result;
    }
    
    return result;
}

int32_t sub_4072ad(int32_t arg1)
{
    data_41079c = arg1;
    return arg1;
}

int32_t __stdcall sub_4072b7(CRITICAL_SECTION* arg1)
{
    InitializeCriticalSection(arg1);
    return 1;
}

int32_t sub_4072c7(int32_t arg1, int32_t arg2)
{
    int32_t __saved_ebp_1 = 0x14;
    int32_t var_8 = 0x40e690;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e690 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_38 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_38;
    void* const var_3c_4 = &data_4072d3;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_20 = 0;
    int32_t (__stdcall* esi)(CRITICAL_SECTION* arg1) = sub_406d52(data_41079c);
    
    if (!esi)
    {
        if (sub_404ccc(&var_20))
        {
            int32_t var_4c;
            __builtin_memset(&var_4c, 0, 0x14);
            sub_4040df();
            /* no return */
        }
        
        if (var_20 == 1)
            esi = sub_4072b7;
        else
        {
            HMODULE hModule = GetModuleHandleA("kernel32.dll");
            
            if (!hModule)
                esi = sub_4072b7;
            else
            {
                esi = GetProcAddress(hModule, "InitializeCriticalSectionAndSpinCount");
                
                if (!esi)
                    esi = sub_4072b7;
            }
        }
        
        data_41079c = sub_406ce6(esi);
    }
    
    int32_t var_8_1 = 0;
    int32_t result = esi(arg1, arg2);
    int32_t var_8_2 = 0xfffffffe;
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_40738b;
    return result;
}

int32_t sub_40734d(void* arg1 @ ebp)
{
    int32_t eax_1 = ***(arg1 - 0x14);
    *(arg1 - 0x24) = eax_1;
    int32_t result;
    result = eax_1 == 0xc0000017;
    return result;
}

int32_t sub_407364(int32_t* arg1 @ ebp)
{
    int32_t esp_2 = arg1[-6];
    
    if (arg1[-9] == 0xc0000017)
    {
        *(esp_2 - 4) = 8;
        SetLastError();
    }
    
    arg1[-8] = 0;
    arg1[-1] = 0xfffffffe;
    int32_t result = arg1[-8];
    *(esp_2 - 4) = &data_40738b;
    TEB* fsbase;
    fsbase->NtTib.ExceptionList = arg1[-4];
    *(esp_2 + 4);
    *(esp_2 + 8);
    *(esp_2 + 0xc);
    *arg1;
    *arg1 = *(esp_2 - 4);
    *arg1;
    return result;
}

int128_t* sub_407390(int128_t* arg1, int128_t* arg2, void* arg3)
{
    char* esi = arg2;
    char* edi = arg1;
    uint32_t eax_1;
    
    if (edi > esi && edi < arg3 + esi)
    {
        void* esi_2 = arg3 + esi - 4;
        void* edi_2 = arg3 + edi - 4;
        uint32_t ecx_5;
        
        if (!(edi_2 & 3))
        {
            ecx_5 = arg3 >> 2;
            
            if (ecx_5 < 8)
                /* jump -> (&jump_table_407650)[-(ecx_5)] */
            
            edi_2 = __builtin_memcpy(edi_2 - (ecx_5 << 2), esi_2 - (ecx_5 << 2), ecx_5 << 2);
            
            switch (arg3 & 3)
            {
                case nullptr:
                {
                    return arg1;
                    break;
                }
                case 1:
                {
                    goto label_4076b8;
                }
                case 2:
                {
                    goto label_4076c8;
                }
                case 3:
                {
                    goto label_4076dc;
                }
            }
        }
        else if (arg3 < 4)
            switch (arg3)
            {
                case nullptr:
                {
                    return arg1;
                    break;
                }
                case 1:
                {
                label_4076b8:
                    eax_1 = *(esi_2 + 3);
                    *(edi_2 + 3) = eax_1;
                    return arg1;
                    break;
                }
                case 2:
                {
                label_4076c8:
                    eax_1 = *(esi_2 + 3);
                    *(edi_2 + 3) = eax_1;
                    eax_1 = *(esi_2 + 2);
                    *(edi_2 + 2) = eax_1;
                    return arg1;
                    break;
                }
                case 3:
                {
                label_4076dc:
                    eax_1 = *(esi_2 + 3);
                    *(edi_2 + 3) = eax_1;
                    eax_1 = *(esi_2 + 2);
                    *(edi_2 + 2) = eax_1;
                    eax_1 = *(esi_2 + 1);
                    *(edi_2 + 1) = eax_1;
                    return arg1;
                    break;
                }
            }
        else
        {
            eax_1 = edi_2 & 3;
            void* ecx_7 = arg3 - eax_1;
            
            switch (jump_table_4075a4[eax_1])
            {
                case 0x4075b4:
                {
                    eax_1 = *(esi_2 + 3);
                    *(edi_2 + 3) = eax_1;
                    ecx_5 = ecx_7 >> 2;
                    
                    if (ecx_5 < 8)
                        /* jump -> (&jump_table_407650)[-(ecx_5)] */
                    
                    edi_2 = __builtin_memcpy(edi_2 - 1 - (ecx_5 << 2), esi_2 - 1 - (ecx_5 << 2), 
                        ecx_5 << 2);
                    
                    switch (3 & ecx_7)
                    {
                        case nullptr:
                        {
                            return arg1;
                            break;
                        }
                        case 1:
                        {
                            goto label_4076b8;
                        }
                        case 2:
                        {
                            goto label_4076c8;
                        }
                        case 3:
                        {
                            goto label_4076dc;
                        }
                    }
                    break;
                }
                case 0x4075d8:
                {
                    eax_1 = *(esi_2 + 3);
                    *(edi_2 + 3) = eax_1;
                    eax_1 = *(esi_2 + 2);
                    ecx_5 = ecx_7 >> 2;
                    *(edi_2 + 2) = eax_1;
                    
                    if (ecx_5 < 8)
                        /* jump -> (&jump_table_407650)[-(ecx_5)] */
                    
                    edi_2 = __builtin_memcpy(edi_2 - 2 - (ecx_5 << 2), esi_2 - 2 - (ecx_5 << 2), 
                        ecx_5 << 2);
                    
                    switch (3 & ecx_7)
                    {
                        case nullptr:
                        {
                            return arg1;
                            break;
                        }
                        case 1:
                        {
                            goto label_4076b8;
                        }
                        case 2:
                        {
                            goto label_4076c8;
                        }
                        case 3:
                        {
                            goto label_4076dc;
                        }
                    }
                    break;
                }
                case 0x407600:
                {
                    eax_1 = *(esi_2 + 3);
                    *(edi_2 + 3) = eax_1;
                    eax_1 = *(esi_2 + 2);
                    *(edi_2 + 2) = eax_1;
                    eax_1 = *(esi_2 + 1);
                    ecx_5 = ecx_7 >> 2;
                    *(edi_2 + 1) = eax_1;
                    
                    if (ecx_5 < 8)
                        /* jump -> (&jump_table_407650)[-(ecx_5)] */
                    
                    edi_2 = __builtin_memcpy(edi_2 - 3 - (ecx_5 << 2), esi_2 - 3 - (ecx_5 << 2), 
                        ecx_5 << 2);
                    
                    switch (3 & ecx_7)
                    {
                        case nullptr:
                        {
                            return arg1;
                            break;
                        }
                        case 1:
                        {
                            goto label_4076b8;
                        }
                        case 2:
                        {
                            goto label_4076c8;
                        }
                        case 3:
                        {
                            goto label_4076dc;
                        }
                    }
                    break;
                }
            }
        }
    }
    
    if (arg3 >= 0x100 && data_410c20 && (edi & 0xf) == (esi & 0xf))
        /* tailcall */
        return sub_408194(arg1, arg2, arg3);
    
    uint32_t ecx_2;
    void* edx_2;
    
    if (edi & 3)
    {
        if (arg3 < 4)
            /* jump -> *(((arg3 - 4) << 2) + &data_407514) */
        
        eax_1 = edi & 3;
        void* ecx_4 = arg3 - 4 + eax_1;
        
        switch (jump_table_407418[eax_1])
        {
            case 0x407428:
            {
                edx_2 = 3 & ecx_4;
                eax_1 = *esi;
                *edi = eax_1;
                eax_1 = esi[1];
                edi[1] = eax_1;
                eax_1 = esi[2];
                ecx_2 = ecx_4 >> 2;
                edi[2] = eax_1;
                esi = &esi[3];
                edi = &edi[3];
                
                if (ecx_2 >= 8)
                {
                    edi = __builtin_memcpy(edi, esi, ecx_2 << 2);
                    
                    switch (edx_2)
                    {
                        case nullptr:
                        {
                            return arg1;
                            break;
                        }
                        case 1:
                        {
                            goto label_40751c;
                        }
                        case 2:
                        {
                            goto label_407528;
                        }
                        case 3:
                        {
                            goto label_40753c;
                        }
                    }
                }
                break;
            }
            case 0x407454:
            {
                edx_2 = 3 & ecx_4;
                eax_1 = *esi;
                *edi = eax_1;
                eax_1 = esi[1];
                ecx_2 = ecx_4 >> 2;
                edi[1] = eax_1;
                esi = &esi[2];
                edi = &edi[2];
                
                if (ecx_2 >= 8)
                {
                    edi = __builtin_memcpy(edi, esi, ecx_2 << 2);
                    
                    switch (edx_2)
                    {
                        case nullptr:
                        {
                            return arg1;
                            break;
                        }
                        case 1:
                        {
                            goto label_40751c;
                        }
                        case 2:
                        {
                            goto label_407528;
                        }
                        case 3:
                        {
                            goto label_40753c;
                        }
                    }
                }
                break;
            }
            case 0x407478:
            {
                edx_2 = 3 & ecx_4;
                eax_1 = *esi;
                *edi = eax_1;
                esi = &esi[1];
                ecx_2 = ecx_4 >> 2;
                edi = &edi[1];
                
                if (ecx_2 >= 8)
                {
                    edi = __builtin_memcpy(edi, esi, ecx_2 << 2);
                    
                    switch (edx_2)
                    {
                        case nullptr:
                        {
                            return arg1;
                            break;
                        }
                        case 1:
                        {
                            goto label_40751c;
                        }
                        case 2:
                        {
                            goto label_407528;
                        }
                        case 3:
                        {
                            goto label_40753c;
                        }
                    }
                }
                break;
            }
        }
    }
    else
    {
        ecx_2 = arg3 >> 2;
        edx_2 = arg3 & 3;
        
        if (ecx_2 >= 8)
        {
            edi = __builtin_memcpy(edi, esi, ecx_2 << 2);
            
            switch (edx_2)
            {
                case nullptr:
                {
                    return arg1;
                    break;
                }
                case 1:
                {
                    goto label_40751c;
                }
                case 2:
                {
                    goto label_407528;
                }
                case 3:
                {
                    goto label_40753c;
                }
            }
        }
    }
    
    switch (ecx_2)
    {
        case 0:
        {
            goto label_4074fb;
        }
        case 1:
        {
            goto label_4074ec;
        }
        case 2:
        {
            goto label_4074e4;
        }
        case 3:
        {
            goto label_4074dc;
        }
        case 4:
        {
            goto label_4074d4;
        }
        case 5:
        {
            goto label_4074cc;
        }
        case 6:
        {
            goto label_4074c4;
        }
        case 7:
        {
            *(edi + (ecx_2 << 2) - 0x1c) = *(esi + (ecx_2 << 2) - 0x1c);
        label_4074c4:
            *(edi + (ecx_2 << 2) - 0x18) = *(esi + (ecx_2 << 2) - 0x18);
        label_4074cc:
            *(edi + (ecx_2 << 2) - 0x14) = *(esi + (ecx_2 << 2) - 0x14);
        label_4074d4:
            *(edi + (ecx_2 << 2) - 0x10) = *(esi + (ecx_2 << 2) - 0x10);
        label_4074dc:
            *(edi + (ecx_2 << 2) - 0xc) = *(esi + (ecx_2 << 2) - 0xc);
        label_4074e4:
            *(edi + (ecx_2 << 2) - 8) = *(esi + (ecx_2 << 2) - 8);
        label_4074ec:
            *(edi + (ecx_2 << 2) - 4) = *(esi + (ecx_2 << 2) - 4);
            eax_1 = ecx_2 << 2;
            esi = &esi[eax_1];
            edi = &edi[eax_1];
        label_4074fb:
            
            switch (edx_2)
            {
                case nullptr:
                {
                    return arg1;
                    break;
                }
                case 1:
                {
                label_40751c:
                    eax_1 = *esi;
                    *edi = eax_1;
                    return arg1;
                    break;
                }
                case 2:
                {
                label_407528:
                    eax_1 = *esi;
                    *edi = eax_1;
                    eax_1 = esi[1];
                    edi[1] = eax_1;
                    return arg1;
                    break;
                }
                case 3:
                {
                label_40753c:
                    eax_1 = *esi;
                    *edi = eax_1;
                    eax_1 = esi[1];
                    edi[1] = eax_1;
                    eax_1 = esi[2];
                    edi[2] = eax_1;
                    return arg1;
                    break;
                }
            }
            break;
        }
    }
}

int32_t __convention("regparm") sub_407634(char arg1)
{
    bool c;
    bool z;
    
    if (z || c)
        /* undefined */
    
    /* jump -> 0x407637 */
}

int32_t __convention("regparm") sub_407654(int32_t arg1, int32_t arg2, int32_t arg3, void* arg4 @ ebp, void* arg5 @ esi, void* arg6 @ edi, int32_t arg7)
{
    *(arg6 + (arg3 << 2) + 0x1c) = *(arg5 + (arg3 << 2) + 0x1c);
    *(arg6 + (arg3 << 2) + 0x18) = *(arg5 + (arg3 << 2) + 0x18);
    *(arg6 + (arg3 << 2) + 0x14) = *(arg5 + (arg3 << 2) + 0x14);
    *(arg6 + (arg3 << 2) + 0x10) = *(arg5 + (arg3 << 2) + 0x10);
    *(arg6 + (arg3 << 2) + 0xc) = *(arg5 + (arg3 << 2) + 0xc);
    *(arg6 + (arg3 << 2) + 8) = *(arg5 + (arg3 << 2) + 8);
    *(arg6 + (arg3 << 2) + 4) = *(arg5 + (arg3 << 2) + 4);
    int32_t eax_6 = arg3 << 2;
    void* esi = arg5 + eax_6;
    void* edi = arg6 + eax_6;
    
    switch (arg2)
    {
        case 0:
        {
            *arg4;
            return *(arg4 + 8);
            break;
        }
        case 1:
        {
            eax_6 = *(esi + 3);
            *(edi + 3) = eax_6;
            *arg4;
            return *(arg4 + 8);
            break;
        }
        case 2:
        {
            eax_6 = *(esi + 3);
            *(edi + 3) = eax_6;
            eax_6 = *(esi + 2);
            *(edi + 2) = eax_6;
            *arg4;
            return *(arg4 + 8);
            break;
        }
        case 3:
        {
            eax_6 = *(esi + 3);
            *(edi + 3) = eax_6;
            eax_6 = *(esi + 2);
            *(edi + 2) = eax_6;
            eax_6 = *(esi + 1);
            *(edi + 1) = eax_6;
            *arg4;
            return *(arg4 + 8);
            break;
        }
    }
}

void __fastcall sub_4076f5(int32_t arg1)
{
    int32_t eax;
    int32_t edx;
    int32_t ebp;
    int32_t esi;
    int32_t edi;
    
    if (arg1 != __security_cookie)
        /* tailcall */
        return sub_40a692(eax, edx, arg1, ebp, esi, edi);
}

int32_t sub_407710(int16_t* arg1)
{
    if (*arg1 == 0x5a4d)
    {
        void* eax_3 = *(arg1 + 0x3c) + arg1;
        
        if (*eax_3 == 0x4550)
        {
            int32_t result;
            result = *(eax_3 + 0x18) == 0x10b;
            return result;
        }
    }
    
    return 0;
}

void* sub_407740(void* arg1, int32_t arg2)
{
    void* ecx_1 = *(arg1 + 0x3c) + arg1;
    uint32_t esi = *(ecx_1 + 6);
    int32_t edx = 0;
    void* result = *(ecx_1 + 0x14) + ecx_1 + 0x18;
    
    if (esi > 0)
    {
        do
        {
            int32_t ecx_2 = *(result + 0xc);
            
            if (arg2 >= ecx_2 && arg2 < *(result + 8) + ecx_2)
                return result;
            
            edx += 1;
            result += 0x28;
        } while (edx < esi);
    }
    
    return nullptr;
}

int32_t sub_407782(int32_t arg1)
{
    int32_t __saved_ebp_1 = 8;
    int32_t var_8 = 0x40e6b0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_4 = 0x40e6b0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_2c = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_2c;
    void* const var_30_1 = &data_40778e;
    int32_t var_8_5 = 0xfffffffe;
    int32_t var_c = var_8_4;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_8_1 = 0;
    int32_t eax = sub_407710(&__dos_header);
    void* eax_3;
    
    if (eax)
        eax_3 = sub_407740(&__dos_header, arg1 - &__dos_header);
    
    int32_t result;
    
    if (!eax || !eax_3)
    {
        int32_t var_8_3 = 0xfffffffe;
        result = 0;
    }
    else
    {
        result = ~(*(eax_3 + 0x24) >> 0x1f) & 1;
        int32_t var_8_2 = 0xfffffffe;
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_4077ed;
    return result;
}

int32_t sub_4077c8(void* arg1 @ ebp)
{
    int32_t result;
    result = ***(arg1 - 0x14) == 0xc0000005;
    return result;
}

uint32_t __convention("regparm") sub_4077ee(int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4, int32_t arg5, int32_t arg6, enum SET_FILE_POINTER_MOVE_METHOD arg7)
{
    int32_t distanceToMoveHigh = arg3;
    int32_t var_c = arg3;
    distanceToMoveHigh = arg6;
    HANDLE hFile = sub_407d5a(arg4);
    uint32_t result;
    
    if (hFile != 0xffffffff)
    {
        uint32_t result_1 = SetFilePointer(hFile, arg5, &distanceToMoveHigh, arg7);
        enum WIN32_ERROR eax_3;
        
        if (result_1 == 0xffffffff)
            eax_3 = GetLastError();
        
        if (result_1 != 0xffffffff || !eax_3)
        {
            char* eax_7 = (&data_410c40)[arg4 >> 5] + (arg4 & 0x1f) * 0x28 + 4;
            *eax_7 &= 0xfd;
            result = result_1;
        }
        else
        {
            sub_402447(eax_3);
            result = 0xffffffff;
        }
    }
    else
    {
        *__errno() = 9;
        result = 0xffffffff;
    }
    
    return result;
}

uint32_t sub_407871(int32_t arg1, int32_t arg2, int32_t arg3, enum SET_FILE_POINTER_MOVE_METHOD arg4)
{
    int32_t __saved_ebp_1 = 0x14;
    int32_t var_8 = 0x40e6d0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e6d0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_38 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_38;
    void* const var_3c_2 = &data_40787d;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_28 = 0xffffffff;
    int32_t var_24 = 0xffffffff;
    uint32_t result;
    
    if (arg1 == 0xfffffffe)
    {
        *___doserrno() = 0;
        *__errno() = 9;
        result = 0xffffffff;
    }
    else if (arg1 < 0 || arg1 >= data_410c24)
    {
        *___doserrno() = 0;
        *__errno() = 9;
        sub_4041db(0, 0, 0, 0, 0);
        result = 0xffffffff;
    }
    else
    {
        int32_t esi_3 = (arg1 & 0x1f) * 0x28;
        
        if (*((&data_410c40)[arg1 >> 5] + esi_3 + 4) & 1)
        {
            int32_t edx_2 = sub_407dcb(arg1);
            int32_t var_8_1 = 0;
            int32_t eax_7 = (&data_410c40)[arg1 >> 5];
            uint32_t result_1;
            int32_t var_24_1;
            
            if (!(*(eax_7 + esi_3 + 4) & 1))
            {
                *__errno() = 9;
                *___doserrno() = 0;
                result_1 = 0xffffffff;
                var_24_1 = 0xffffffff;
            }
            else
            {
                uint32_t result_2;
                int32_t edx_3;
                result_2 = sub_4077ee(eax_7, edx_2, arg1, arg1, arg2, arg3, arg4);
                result_1 = result_2;
                var_24_1 = edx_3;
            }
            int32_t var_8_2 = 0xfffffffe;
            sub_407980(&__saved_ebp);
            result = result_1;
        }
        else
        {
            *___doserrno() = 0;
            *__errno() = 9;
            sub_4041db(0, 0, 0, 0, 0);
            result = 0xffffffff;
        }
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_40797f;
    return result;
}

int32_t sub_407980(void* arg1 @ ebp)
{
    return sub_407e6b(*(arg1 + 8));
}

int32_t sub_40798a(int32_t* arg1)
{
    data_4101a0 += 1;
    void* eax = sub_40655b(0x1000);
    arg1[2] = eax;
    
    if (!eax)
    {
        arg1[3] |= 4;
        arg1[2] = &arg1[5];
        arg1[6] = 2;
    }
    else
    {
        arg1[3] |= 8;
        arg1[6] = 0x1000;
    }
    
    int32_t result = arg1[2];
    arg1[1] = 0;
    *arg1 = result;
    return result;
}

int32_t sub_4079ce(int32_t arg1)
{
    if (arg1 == 0xfffffffe)
    {
        *__errno() = 9;
        return 0;
    }
    
    if (arg1 >= 0 && arg1 < data_410c24)
        return *((&data_410c40)[arg1 >> 5] + (arg1 & 0x1f) * 0x28 + 4) & 0x40;
    
    *__errno() = 9;
    sub_4041db(0, 0, 0, 0, 0);
    return 0;
}

BOOL sub_407a2c()
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    
    if (!data_40f8f0)
        goto label_407aab;
    
    if (data_40ff54 == 0xfffffffe)
        ___initconout();
    
    BOOL result = data_40ff54;
    uint32_t numberOfCharsWritten;
    wchar16 arg_4;
    
    if (result != 0xffffffff)
    {
        if (WriteConsoleW(result, &arg_4, 1, &numberOfCharsWritten, nullptr))
        {
            data_40f8f0 = 1;
            result = arg_4;
        }
        else if (data_40f8f0 != 2)
            result = 0xffff;
        else if (GetLastError() != 0x78)
            result = 0xffff;
        else
        {
            data_40f8f0 = 0;
        label_407aab:
            void var_10;
            result = WideCharToMultiByte(GetConsoleOutputCP(), 0, &arg_4, 1, &var_10, 5, nullptr, 
                nullptr);
            HANDLE hConsoleOutput = data_40ff54;
            
            if (hConsoleOutput == 0xffffffff)
                result = 0xffff;
            else if (
                    !WriteConsoleA(hConsoleOutput, &var_10, result, &numberOfCharsWritten, nullptr))
                result = 0xffff;
            else
                result = arg_4;
        }
    }
    else
        result = 0xffff;
    sub_4076f5(eax_1 ^ &__saved_ebp);
    return result;
}

int32_t sub_407aee(int16_t* arg1, char* arg2, int32_t arg3, int32_t* arg4)
{
    if (arg2 && arg3)
    {
        if (*arg2)
        {
            void* var_14;
            sub_405aa0(&var_14, arg4);
            void* var_c;
            char var_8;
            
            if (*(var_14 + 0x14))
            {
                if (sub_407c18(*arg2, &var_14))
                {
                    void* eax_7 = var_14;
                    int32_t cbMultiByte = *(eax_7 + 0xac);
                    
                    if (cbMultiByte <= 1 || arg3 < cbMultiByte)
                    {
                    label_407b93:
                        
                        if (arg3 >= *(eax_7 + 0xac) && arg2[1])
                            goto label_407ba3;
                        
                        goto label_407bc0;
                    }
                    
                    int32_t cchWideChar_1;
                    cchWideChar_1 = arg1;
                    bool cond:1_1 = MultiByteToWideChar(*(eax_7 + 4), 
                        MB_ERR_INVALID_CHARS | MB_PRECOMPOSED, arg2, cbMultiByte, arg1, 
                        cchWideChar_1);
                    eax_7 = var_14;
                    
                    if (!cond:1_1)
                        goto label_407b93;
                    
                label_407ba3:
                    int32_t result = *(eax_7 + 0xac);
                    
                    if (var_8)
                        *(var_c + 0x70) &= 0xfffffffd;
                    
                    return result;
                }
                
                int32_t cchWideChar;
                cchWideChar = arg1;
                
                if (!MultiByteToWideChar(*(var_14 + 4), MB_ERR_INVALID_CHARS | MB_PRECOMPOSED, 
                    arg2, 1, arg1, cchWideChar))
                {
                label_407bc0:
                    *__errno() = 0x2a;
                    
                    if (var_8)
                        *(var_c + 0x70) &= 0xfffffffd;
                    
                    return 0xffffffff;
                }
            }
            else if (arg1)
                *arg1 = *arg2;
            
            if (var_8)
                *(var_c + 0x70) &= 0xfffffffd;
            
            return 1;
        }
        
        if (arg1)
            *arg1 = 0;
    }
    
    return 0;
}

int32_t sub_407c01(int16_t* arg1, char* arg2, int32_t arg3)
{
    return sub_407aee(arg1, arg2, arg3, nullptr);
}

int32_t sub_407c18(char arg1, int32_t* arg2)
{
    void* var_14;
    sub_405aa0(&var_14, arg2);
    int32_t result = *(*(var_14 + 0xc8) + (arg1 << 1)) & 0x8000;
    char var_8;
    void* var_c;
    
    if (var_8)
        *(var_c + 0x70) &= 0xfffffffd;
    return result;
}

int32_t sub_407c4e(char arg1)
{
    return sub_407c18(arg1, nullptr);
}

int32_t sub_407c5c(int32_t arg1, HANDLE arg2)
{
    if (arg1 >= 0 && arg1 < data_410c24)
    {
        int32_t* esi_3 = (arg1 & 0x1f) * 0x28;
        
        if (*(esi_3 + (&data_410c40)[arg1 >> 5]) == 0xffffffff)
        {
            if (data_40f3b8 == 1)
            {
                if (!arg1)
                    SetStdHandle(STD_INPUT_HANDLE, arg2);
                else if (arg1 == 1)
                    SetStdHandle(STD_OUTPUT_HANDLE, arg2);
                else if (arg1 == 2)
                    SetStdHandle(STD_ERROR_HANDLE, arg2);
            }
            
            *(esi_3 + (&data_410c40)[arg1 >> 5]) = arg2;
            return 0;
        }
    }
    
    *__errno() = 9;
    *___doserrno() = 0;
    return 0xffffffff;
}

int32_t sub_407cd9(int32_t arg1)
{
    if (arg1 >= 0 && arg1 < data_410c24)
    {
        int32_t* esi_3 = (arg1 & 0x1f) * 0x28;
        int32_t* eax_4 = (&data_410c40)[arg1 >> 5] + esi_3;
        
        if (eax_4[1] & 1 && *eax_4 != 0xffffffff)
        {
            if (data_40f3b8 == 1)
            {
                if (!arg1)
                {
                    int32_t var_10_3 = 0;
                    SetStdHandle(STD_INPUT_HANDLE, nullptr);
                }
                else if (arg1 == 1)
                {
                    int32_t var_10_2 = 0;
                    SetStdHandle(STD_OUTPUT_HANDLE, nullptr);
                }
                else if (arg1 == 2)
                {
                    int32_t var_10_1 = 0;
                    SetStdHandle(STD_ERROR_HANDLE, nullptr);
                }
            }
            
            *(esi_3 + (&data_410c40)[arg1 >> 5]) = 0xffffffff;
            return 0;
        }
    }
    
    *__errno() = 9;
    *___doserrno() = 0;
    return 0xffffffff;
}

int32_t sub_407d5a(int32_t arg1)
{
    if (arg1 == 0xfffffffe)
    {
        *___doserrno() = 0;
        *__errno() = 9;
        return 0xffffffff;
    }
    
    if (arg1 >= 0 && arg1 < data_410c24)
    {
        int32_t* eax_5 = (arg1 & 0x1f) * 0x28 + (&data_410c40)[arg1 >> 5];
        
        if (eax_5[1] & 1)
            return *eax_5;
    }
    
    *___doserrno() = 0;
    *__errno() = 9;
    sub_4041db(0, 0, 0, 0, 0);
    return 0xffffffff;
}

int32_t sub_407dcb(int32_t arg1)
{
    int32_t __saved_ebp_1 = 0xc;
    int32_t var_8 = 0x40e6f0;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e6f0 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_1 = &data_407dd7;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    void* esi_3 = (arg1 & 0x1f) * 0x28 + (&data_410c40)[arg1 >> 5];
    int32_t result = 1;
    
    if (!*(esi_3 + 8))
    {
        sub_402690(0xa);
        int32_t var_8_1 = 0;
        
        if (!*(esi_3 + 8))
        {
            if (!sub_4072c7(esi_3 + 0xc, 0xfa0))
                result = 0;
            
            *(esi_3 + 8) += 1;
        }
        
        int32_t var_8_2 = 0xfffffffe;
        sub_407e62();
    }
    
    if (result)
        EnterCriticalSection((&data_410c40)[arg1 >> 5] + (arg1 & 0x1f) * 0x28 + 0xc);
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_407e5c;
    return result;
}

int32_t sub_407e62()
{
    return __unlock(0xa);
}

int32_t sub_407e6b(int32_t arg1)
{
    return LeaveCriticalSection((&data_410c40)[arg1 >> 5] + (arg1 & 0x1f) * 0x28 + 0xc);
}

int32_t sub_407e8d()
{
    int32_t __saved_ebp_1 = 0x18;
    int32_t var_8 = 0x40e710;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_5 = 0x40e710 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_3c = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_3c;
    void* const var_40_4 = &data_407e99;
    int32_t var_8_6 = 0xfffffffe;
    int32_t var_c = var_8_5;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t result_1 = 0xffffffff;
    int32_t edi = 0;
    int32_t var_28 = 0;
    int32_t result;
    
    if (sub_4025cd(0xb))
    {
        sub_402690(0xb);
        int32_t var_8_1 = 0;
        
        while (true)
        {
            int32_t var_2c_1 = edi;
            
            if (edi >= 0x40)
                break;
            
            int32_t* esi_1 = (&data_410c40)[edi];
            
            if (!esi_1)
            {
                void* i = sub_40659b(0x20, 0x28);
                void* i_1 = i;
                
                if (i)
                {
                    (&data_410c40)[edi] = i;
                    data_410c24 += 0x20;
                    
                    while (i < (&data_410c40)[edi] + 0x500)
                    {
                        *(i + 4) = 0;
                        *i = 0xffffffff;
                        *(i + 5) = 0xa;
                        *(i + 8) = 0;
                        i += 0x28;
                        void* i_2 = i;
                    }
                    
                    int32_t result_2 = edi << 5;
                    result_1 = result_2;
                    *((&data_410c40)[result_2 >> 5] + (result_2 & 0x1f) * 0x28 + 4) = 1;
                    
                    if (!sub_407dcb(result_2))
                        result_1 = 0xffffffff;
                }
                
                break;
            }
            
            while (true)
            {
                int32_t* var_24_1 = esi_1;
                
                if (esi_1 >= (&data_410c40)[edi] + 0x500)
                    break;
                
                if (!(esi_1[1] & 1))
                {
                    if (!esi_1[2])
                    {
                        sub_402690(0xa);
                        int32_t var_8_2 = 1;
                        
                        if (!esi_1[2])
                        {
                            if (sub_4072c7(&esi_1[3], 0xfa0))
                                esi_1[2] += 1;
                            else
                                var_28 = 1;
                        }
                        
                        int32_t var_8_3 = 0;
                        sub_407f60();
                    }
                    
                    if (!var_28)
                    {
                        EnterCriticalSection(&esi_1[3]);
                        
                        if (esi_1[1] & 1)
                            LeaveCriticalSection(&esi_1[3]);
                        else if (!var_28)
                        {
                            esi_1[1] = 1;
                            *esi_1 = 0xffffffff;
                            int32_t var_40_2 = 0x28;
                            result_1 = (esi_1 - (&data_410c40)[edi]) / 0x28 + (edi << 5);
                            break;
                        }
                    }
                }
                
                esi_1 = &esi_1[0xa];
            }
            
            if (result_1 != 0xffffffff)
                break;
            
            edi += 1;
        }
        
        int32_t var_8_4 = 0xfffffffe;
        sub_408023();
        result = result_1;
    }
    else
        result = 0xffffffff;
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_408022;
    return result;
}

int32_t sub_407f60()
{
    return __unlock(0xa);
}

int32_t sub_408023()
{
    return __unlock(0xb);
}

enum WIN32_ERROR sub_40802c(int32_t arg1)
{
    int32_t __saved_ebp_1 = 0x10;
    int32_t var_8 = 0x40e738;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e738 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_34 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_34;
    void* const var_38_3 = &data_408038;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    enum WIN32_ERROR result;
    
    if (arg1 != 0xfffffffe)
    {
        int32_t esi_3;
        
        if (arg1 >= 0 && arg1 < data_410c24)
            esi_3 = (arg1 & 0x1f) * 0x28;
        
        if (arg1 < 0 || arg1 >= data_410c24 || !(*(esi_3 + (&data_410c40)[arg1 >> 5] + 4) & 1))
        {
            *__errno() = 9;
            sub_4041db(0, 0, 0, 0, 0);
            result = ~NO_ERROR;
        }
        else
        {
            sub_407dcb(arg1);
            int32_t var_8_1 = 0;
            enum WIN32_ERROR result_1;
            
            if (!(*(esi_3 + (&data_410c40)[arg1 >> 5] + 4) & 1))
            {
                *__errno() = 9;
                result_1 = ~NO_ERROR;
            }
            else
            {
                if (FlushFileBuffers(sub_407d5a(arg1)))
                    result_1 = NO_ERROR;
                else
                    result_1 = GetLastError();
                
                if (result_1)
                {
                    *___doserrno() = result_1;
                    *__errno() = 9;
                    result_1 = ~NO_ERROR;
                }
            }
            
            int32_t var_8_2 = 0xfffffffe;
            sub_408103(&__saved_ebp);
            result = result_1;
        }
    }
    else
    {
        *__errno() = 9;
        result = ~NO_ERROR;
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_408102;
    return result;
}

int32_t sub_408103(void* arg1 @ ebp)
{
    return sub_407e6b(*(arg1 + 8));
}

int32_t sub_40810d(int128_t* arg1, int128_t* arg2, int32_t arg3)
{
    int128_t* esi = arg2;
    int128_t* edi = arg1;
    uint32_t i_1 = arg3 >> 7;
    uint32_t i;
    
    do
    {
        int128_t xmm1_1 = esi[1];
        int128_t xmm2_1 = esi[2];
        int128_t xmm3_1 = esi[3];
        *edi = *esi;
        edi[1] = xmm1_1;
        edi[2] = xmm2_1;
        edi[3] = xmm3_1;
        int128_t xmm5_1 = esi[5];
        int128_t xmm6_1 = esi[6];
        int128_t xmm7_1 = esi[7];
        edi[4] = esi[4];
        edi[5] = xmm5_1;
        edi[6] = xmm6_1;
        edi[7] = xmm7_1;
        esi = &esi[8];
        edi = &edi[8];
        i = i_1;
        i_1 -= 1;
    } while (i != 1);
}

int128_t* sub_408194(int128_t* arg1, int128_t* arg2, void* arg3)
{
    int32_t eax_1;
    int32_t edx;
    edx = HIGHD(arg2);
    eax_1 = LOWD(arg2);
    int32_t ecx_5 = ((((eax_1 ^ edx) - edx) & 0xf) ^ edx) - edx;
    int128_t* eax_3;
    int32_t edx_1;
    edx_1 = HIGHD(arg1);
    eax_3 = LOWD(arg1);
    int32_t edi_5 = ((((eax_3 ^ edx_1) - edx_1) & 0xf) ^ edx_1) - edx_1;
    
    if (ecx_5 | edi_5)
    {
        if (ecx_5 == edi_5)
        {
            __builtin_memcpy(arg1, arg2, -(ecx_5) + 0x10);
            sub_408194(arg1 + -(ecx_5) + 0x10, arg2 + -(ecx_5) + 0x10, arg3 - (-(ecx_5) + 0x10), 
                -(ecx_5) + 0x10);
            return arg1;
        }
        
        int32_t esi_5;
        int32_t edi_9;
        edi_9 = __builtin_memcpy(arg1, arg2, arg3 >> 2 << 2);
        __builtin_memcpy(edi_9, esi_5, arg3 & 3);
        return arg1;
    }
    
    void* count_1 = arg3 & 0x7f;
    void* count = count_1;
    
    if (arg3 != count_1)
    {
        sub_40810d(eax_3, arg2, arg3 - count_1);
        eax_3 = arg1;
        count_1 = count;
    }
    
    if (!count_1)
        return eax_3;
    
    __builtin_memcpy(arg3 + eax_3 - count_1, arg2 + arg3 - count_1, count);
    return arg1;
}

int32_t sub_408277()
{
    data_410c1c = 0;
    int32_t eax;
    data_410c1c = sub_40a832(eax);
    return 0;
}

int32_t sub_40828b()
{
    data_410c18 = 0;
}

int32_t sub_408293(int32_t arg1, int32_t arg2)
{
    int32_t edi = arg1;
    uint32_t i_1 = arg2 >> 7;
    uint32_t i;
    
    do
    {
        __builtin_memset(edi, 0, 0x80);
        edi += 0x80;
        i = i_1;
        i_1 -= 1;
    } while (i != 1);
}

int32_t sub_4082ea(int32_t arg1, int32_t arg2)
{
    int32_t eax_1;
    int32_t edx;
    edx = HIGHD(arg1);
    eax_1 = LOWD(arg1);
    int32_t edi_5 = ((((eax_1 ^ edx) - edx) & 0xf) ^ edx) - edx;
    
    if (edi_5)
    {
        __builtin_memset(arg1, 0, -(edi_5) + 0x10);
        sub_4082ea(arg1 + -(edi_5) + 0x10, 0, arg2 - (-(edi_5) + 0x10), -(edi_5) + 0x10);
        return arg1;
    }
    
    int32_t count_1 = arg2 & 0x7f;
    int32_t count = count_1;
    
    if (arg2 != count_1)
    {
        sub_408293(eax_1, arg2 - count_1);
        eax_1 = arg1;
        count_1 = count;
    }
    
    if (!count_1)
        return eax_1;
    
    __builtin_memset(eax_1 + arg2 - count_1, 0, count);
    return arg1;
}

int32_t sub_408379(int32_t arg1)
{
    int32_t ecx;
    int32_t var_4_1 = ecx;
    void* eax = sub_406d52(data_410d48);
    void* edi = sub_406d52(data_410d44);
    
    if (edi >= eax)
    {
        void* ebx_2 = edi - eax;
        
        if (ebx_2 + 4 >= 4)
        {
            uint32_t eax_2 = sub_40a89f(eax);
            
            if (eax_2 >= ebx_2 + 4)
                goto label_408409;
            
            uint32_t eax_3 = 0x800;
            
            if (eax_2 < 0x800)
                eax_3 = eax_2;
            
            uint32_t eax_4 = eax_3 + eax_2;
            void* eax_5;
            
            if (eax_4 >= eax_2)
                eax_5 = sub_4065e3(eax, eax_4);
            
            if (eax_4 >= eax_2 && eax_5)
            {
            label_4083f7:
                edi = eax_5 + (ebx_2 >> 2 << 2);
                data_410d48 = sub_406ce6(eax_5);
            label_408409:
                *edi = arg1;
                data_410d44 = sub_406ce6(edi + 4);
                return arg1;
            }
            
            if (eax_2 + 0x10 >= eax_2)
            {
                eax_5 = sub_4065e3(eax, eax_2 + 0x10);
                
                if (eax_5)
                    goto label_4083f7;
            }
        }
    }
    
    return 0;
}

int32_t sub_408426()
{
    void* eax = sub_40659b(0x20, 4);
    int32_t eax_1 = sub_406ce6(eax);
    data_410d48 = eax_1;
    data_410d44 = eax_1;
    
    if (!eax)
        return 0x18;
    
    *eax = 0;
    return 0;
}

int32_t sub_408455(int32_t arg1)
{
    int32_t __saved_ebp_1 = 0xc;
    int32_t var_8 = 0x40e758;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e758 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_1 = &data_408461;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    sub_404c82();
    int32_t var_8_1 = 0;
    int32_t result = sub_408379(arg1);
    int32_t var_8_2 = 0xfffffffe;
    sub_40848b();
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_40848a;
    return result;
}

int32_t sub_40848b()
{
    return sub_404c8b();
}

int32_t sub_408491(int32_t arg1)
{
    int32_t eax = sub_408455(arg1);
    int32_t eax_1 = -(eax);
    return -((eax_1 - eax_1)) - 1;
}

int32_t sub_4084a3()
{
    int32_t result;
    
    for (int32_t i = 0; i < 0x28; )
    {
        void* esi_1 = i + &data_40f8f4;
        result = sub_406ce6(*esi_1);
        i += 4;
        *esi_1 = result;
    }
    
    return result;
}

void terminate() __noreturn
{
    int32_t var_4 = 8;
    int32_t var_8 = 0x40e778;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t ebp;
    var_4 = ebp;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e778 ^ __security_cookie_1;
    int32_t var_2c = __security_cookie_1 ^ &var_4;
    int32_t* var_1c = &var_2c;
    void* const var_30 = &data_4084ce;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t eax_1 = *(__getptd() + 0x78);
    
    if (eax_1)
    {
        int32_t var_8_1 = 0;
        eax_1();
        int32_t var_8_2 = 0xfffffffe;
    }
    
    sub_40a94b();
    /* no return */
}

int32_t sub_4084e2() __pure
{
    return 1;
}

void sub_4084e6(void* arg1 @ ebp) __noreturn
{
    *(arg1 - 4) = 0xfffffffe;
    sub_40a94b();
    /* no return */
}

int32_t sub_4084fb()
{
    int32_t result = sub_406ce6(terminate);
    data_4107a0 = result;
    return result;
}

int32_t sub_40850c(int32_t arg1)
{
    data_4107a4 = arg1;
    data_4107a8 = arg1;
    data_4107ac = arg1;
    data_4107b0 = arg1;
    return arg1;
}

void* __convention("regparm") sub_408525(int32_t arg1, int32_t arg2, void* arg3)
{
    void* result = arg3;
    int32_t ecx = data_40f8dc;
    
    while (*(result + 4) != arg2)
    {
        result += 0xc;
        
        if (result >= ecx * 0xc + arg3)
            break;
    }
    
    if (result < ecx * 0xc + arg3 && *(result + 4) == arg2)
        return result;
    
    return nullptr;
}

int32_t sub_408559()
{
    return sub_406d52(data_4107ac);
}

int32_t sub_408566(int32_t arg1)
{
    int32_t __saved_ebp_1 = 0x20;
    int32_t var_8 = 0x40e798;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t __saved_ebp_4;
    int32_t __saved_ebp_2 = __saved_ebp_4;
    int32_t ebx;
    int32_t var_38 = ebx;
    int32_t esi;
    int32_t var_3c = esi;
    int32_t edi;
    int32_t var_40 = edi;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e798 ^ __security_cookie_1;
    int32_t __saved_ebp;
    void* var_44 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_44;
    void* const var_48 = &data_408572;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c_1 = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    void* const* esp_1 = &var_44;
    void* edi_1 = nullptr;
    int32_t var_20 = 0;
    int32_t var_2c = 0;
    int32_t result;
    void* eax_6;
    int32_t eax_8;
    void* esi_1;
    
    if (arg1 <= 0xb)
    {
        if (arg1 != 0xb)
        {
            var_48 = 2;
            esp_1 = &var_44;
            
            if (arg1 == 2)
            {
                esi_1 = &data_4107a4;
                eax_6 = data_4107a4;
                goto label_40861b;
            }
            
            if (arg1 == 4)
                goto label_408599;
            
            if (arg1 == 6)
                goto label_4085f9;
            
            if (arg1 != 8)
                goto label_4085e2;
            
            goto label_408599;
        }
        
    label_408599:
        void* eax_5;
        void* ecx_1;
        eax_5 = sub_406ed9();
        edi_1 = eax_5;
        void* var_2c_1 = edi_1;
        
        if (edi_1)
        {
            var_48 = *(edi_1 + 0x5c);
            esi_1 = sub_408525(eax_5, arg1, ecx_1) + 8;
            eax_8 = *esi_1;
            goto label_40862b;
        }
        
        result = 0xffffffff;
    }
    else if (arg1 == 0xf)
    {
        esi_1 = &data_4107b0;
        eax_6 = data_4107b0;
    label_40861b:
        var_20 = 1;
        var_48 = eax_6;
        eax_8 = sub_406d52(var_48);
    label_40862b:
        esp_1 = &var_44;
        result = 0;
        
        if (eax_8 != 1)
        {
            if (!eax_8)
            {
                var_48 = 3;
                esp_1 = &var_48;
                result = sub_404eb0(var_48);
            }
            
            if (var_20 != result)
            {
                *(esp_1 - 4) = result;
                sub_402690();
                *(esp_1 - 4);
            }
            
            int32_t var_8_1 = 0;
            
            if (arg1 != 8 && arg1 != 0xb && arg1 != 4)
                goto label_40867f;
            
            int32_t var_30 = *(edi_1 + 0x60);
            *(edi_1 + 0x60) = 0;
            int32_t var_34;
            
            if (arg1 != 8)
                *esi_1 = sub_406d49();
            else
            {
                var_34 = *(edi_1 + 0x64);
                *(edi_1 + 0x64) = 0x8c;
            label_40867f:
                
                if (arg1 != 8)
                    *esi_1 = sub_406d49();
                else
                {
                    for (int32_t i = data_40f8d0; i < data_40f8d4 + data_40f8d0; i += 1)
                        *(i * 0xc + *(edi_1 + 0x5c) + 8) = 0;
                }
            }
            
            int32_t var_8_2 = 0xfffffffe;
            sub_4086da(&__saved_ebp);
            void* esp_6;
            
            if (arg1 != 8)
            {
                *(esp_1 - 4) = arg1;
                eax_8();
                esp_6 = esp_1;
            }
            else
            {
                *(esp_1 - 4) = *(edi_1 + 0x64);
                *(esp_1 - 8) = arg1;
                eax_8();
                *(esp_1 - 4);
                esp_6 = esp_1;
            }
            
            *esp_6;
            esp_1 = esp_6 + 4;
            
            if (arg1 == 8 || arg1 == 0xb || arg1 == 4)
            {
                *(edi_1 + 0x60) = var_30;
                
                if (arg1 == 8)
                    *(edi_1 + 0x64) = var_34;
            }
            
            result = 0;
        }
    }
    else
    {
        if (arg1 == 0x15)
        {
            esi_1 = &data_4107a8;
            eax_6 = data_4107a8;
            goto label_40861b;
        }
        
        if (arg1 == 0x16)
        {
        label_4085f9:
            esi_1 = &data_4107ac;
            eax_6 = data_4107ac;
            goto label_40861b;
        }
        
    label_4085e2:
        *__errno() = 0x16;
        int32_t var_58;
        __builtin_memset(&var_58, 0, 0x14);
        sub_4041db(0, 0, 0, 0, var_48);
        esp_1 = &var_44;
        result = 0xffffffff;
    }
    *(esp_1 - 4) = &data_408715;
    fsbase->NtTib.ExceptionList = ExceptionList;
    esp_1[1];
    esp_1[2];
    esp_1[3];
    int32_t __saved_ebp_3 = *(esp_1 - 4);
    return result;
}

int32_t sub_4086d4(void* arg1 @ ebp)
{
    *(arg1 + 8);
    *(arg1 - 0x28);
    /* tailcall */
    return sub_4086da(arg1);
}

void sub_4086da(void* arg1 @ ebp)
{
    if (*(arg1 - 0x1c))
        __unlock(0);
}

int32_t sub_408716(int32_t arg1)
{
    data_4107b8 = arg1;
    return arg1;
}

int32_t sub_408720(int32_t arg1)
{
    data_4107c4 = arg1;
    return arg1;
}

int32_t sub_40872a(int32_t arg1, int32_t arg2, int32_t arg3)
{
    int32_t eax = sub_406d49();
    bool cond:0 = data_4107c8;
    int32_t var_8 = 0;
    int32_t var_c = 0;
    int32_t var_10 = 0;
    
    if (!cond:0)
    {
        HMODULE hModule = LoadLibraryA("USER32.DLL");
        int32_t eax_1;
        
        if (hModule)
            eax_1 = GetProcAddress(hModule, "MessageBoxA");
        
        if (!hModule || !eax_1)
            return 0;
        
        data_4107c8 = sub_406ce6(eax_1);
        data_4107cc = sub_406ce6(GetProcAddress(hModule, "GetActiveWindow"));
        data_4107d0 = sub_406ce6(GetProcAddress(hModule, "GetLastActivePopup"));
        
        if (sub_404ccc(&var_c))
        {
            int32_t var_44_1;
            __builtin_memset(&var_44_1, 0, 0x14);
            sub_4040df();
            /* no return */
        }
        
        if (var_c == 2)
        {
            int32_t eax_9 = sub_406ce6(GetProcAddress(hModule, "GetUserObjectInformationA"));
            data_4107d8 = eax_9;
            
            if (eax_9)
                data_4107d4 = sub_406ce6(GetProcAddress(hModule, "GetProcessWindowStation"));
        }
    }
    
    int32_t eax_12 = data_4107d4;
    int32_t eax_14;
    int32_t eax_16;
    
    if (eax_12 != eax && data_4107d8 != eax)
    {
        eax_14 = sub_406d52(eax_12)();
        void var_24;
        void var_18;
        
        if (eax_14)
            eax_16 = sub_406d52(data_4107d8)(eax_14, 1, &var_24, 0xc, &var_18);
    }
    
    char var_1c;
    
    if (eax_12 != eax && data_4107d8 != eax && (!eax_14 || !eax_16 || !(var_1c & 1)))
    {
        if (sub_404d03(&var_10))
        {
            int32_t var_44_3;
            __builtin_memset(&var_44_3, 0, 0x14);
            sub_4040df();
            /* no return */
        }
        
        arg3 = var_10 < 4 ? arg3 | 0x40000 : arg3 | 0x200000;
    }
    else
    {
        int32_t eax_18 = data_4107cc;
        
        if (eax_18 != eax)
        {
            int32_t eax_20 = sub_406d52(eax_18)();
            var_8 = eax_20;
            
            if (eax_20)
            {
                int32_t eax_21 = data_4107d0;
                
                if (eax_21 != eax)
                    var_8 = sub_406d52(eax_21)(var_8);
            }
        }
    }
    
    return sub_406d52(data_4107c8)(var_8, arg1, arg2, arg3);
}

int32_t sub_4088c8(char* arg1, int32_t arg2, char* arg3)
{
    int32_t result;
    
    if (!arg1)
    {
        result = 0x16;
        *__errno() = 0x16;
    }
    else
    {
        int32_t i_1 = arg2;
        
        if (i_1 > 0)
        {
            char* esi_1 = arg3;
            char* edx_1;
            
            if (esi_1)
            {
                edx_1 = arg1;
                
                while (*edx_1)
                {
                    edx_1 = &edx_1[1];
                    int32_t i_2 = i_1;
                    i_1 -= 1;
                    
                    if (i_2 == 1)
                        break;
                }
            }
            
            if (!esi_1 || !i_1)
            {
                *arg1 = 0;
                result = 0x16;
                *__errno() = 0x16;
            }
            else
            {
                int32_t i;
                
                do
                {
                    char ecx = *esi_1;
                    *edx_1 = ecx;
                    edx_1 = &edx_1[1];
                    esi_1 = &esi_1[1];
                    
                    if (!ecx)
                        break;
                    
                    i = i_1;
                    i_1 -= 1;
                } while (i != 1);
                
                if (i_1)
                    return 0;
                
                *arg1 = 0;
                *__errno() = 0x22;
                result = 0x22;
            }
        }
        else
        {
            result = 0x16;
            *__errno() = 0x16;
        }
    }
    
    sub_4041db(0, 0, 0, 0, 0);
    return result;
}

int32_t sub_408939(char* arg1, int32_t arg2, char* arg3, int32_t arg4)
{
    if (arg4)
    {
        if (!arg1)
            goto label_40896b;
        
    label_40895d:
        int32_t i_2 = arg2;
        
        if (i_2 <= 0)
            goto label_40896b;
        
        if (arg4)
        {
            char* edx_1 = arg3;
            
            if (!edx_1)
            {
                *arg1 = 0;
            label_40896b:
                *__errno() = 0x16;
                sub_4041db(0, 0, 0, 0, 0);
                return 0x16;
            }
            
            char* eax_3 = arg1;
            char ecx;
            
            if (arg4 != 0xffffffff)
            {
                int32_t i;
                
                do
                {
                    ecx = *edx_1;
                    *eax_3 = ecx;
                    eax_3 = &eax_3[1];
                    edx_1 = &edx_1[1];
                    
                    if (!ecx)
                        break;
                    
                    int32_t i_3 = i_2;
                    i_2 -= 1;
                    
                    if (i_3 == 1)
                        break;
                    
                    i = arg4;
                    arg4 -= 1;
                } while (i != 1);
                
                if (!arg4)
                    *eax_3 = 0;
            }
            else
            {
                int32_t i_1;
                
                do
                {
                    ecx = *edx_1;
                    *eax_3 = ecx;
                    eax_3 = &eax_3[1];
                    edx_1 = &edx_1[1];
                    
                    if (!ecx)
                        break;
                    
                    i_1 = i_2;
                    i_2 -= 1;
                } while (i_1 != 1);
            }
            
            if (!i_2)
            {
                if (arg4 == 0xffffffff)
                {
                    arg1[arg2 - 1] = 0;
                    return 0x50;
                }
                
                *arg1 = 0;
                *__errno() = 0x22;
                sub_4041db(0, 0, 0, 0, 0);
                return 0x22;
            }
        }
        else
            *arg1 = 0;
    }
    else
    {
        if (arg1)
            goto label_40895d;
        
        if (arg2)
            goto label_40896b;
    }
    
    return 0;
}

void* _strlen(char* arg1)
{
    char* ecx = arg1;
    
    while (ecx & 3)
    {
        int32_t eax;
        eax = *ecx;
        ecx = &ecx[1];
        
        if (!eax)
            return &ecx[0xffffffff] - arg1;
    }
    
    while (true)
    {
        int32_t eax_2 = *ecx;
        ecx = &ecx[4];
        
        if ((eax_2 ^ 0xffffffff ^ (0x7efefeff + eax_2)) & 0x81010100)
        {
            int32_t eax_5 = *(ecx - 4);
            
            if (!eax_5)
                return &ecx[0xfffffffc] - arg1;
            
            if (!*eax_5[1])
                return &ecx[0xfffffffd] - arg1;
            
            if (!(eax_5 & 0xff0000))
                return &ecx[0xfffffffe] - arg1;
            
            if (!(eax_5 & 0xff000000))
                break;
        }
    }
    
    return &ecx[0xffffffff] - arg1;
}

int32_t sub_408a7b(char* arg1, int32_t arg2, char* arg3)
{
    int32_t result;
    
    if (!arg1)
    {
        result = 0x16;
        *__errno() = 0x16;
    }
    else
    {
        int32_t i_1 = arg2;
        
        if (i_1 > 0)
        {
            char* esi_1 = arg3;
            
            if (esi_1)
            {
                char* edx_1 = arg1;
                int32_t i;
                
                do
                {
                    char eax = *esi_1;
                    *edx_1 = eax;
                    edx_1 = &edx_1[1];
                    esi_1 = &esi_1[1];
                    
                    if (!eax)
                        break;
                    
                    i = i_1;
                    i_1 -= 1;
                } while (i != 1);
                
                if (i_1)
                    return 0;
                
                *arg1 = 0;
                *__errno() = 0x22;
                result = 0x22;
            }
            else
            {
                *arg1 = 0;
                result = 0x16;
                *__errno() = 0x16;
            }
        }
        else
        {
            result = 0x16;
            *__errno() = 0x16;
        }
    }
    
    sub_4041db(0, 0, 0, 0, 0);
    return result;
}

int32_t sub_408ae0(int32_t arg1)
{
    if (arg1 >= 0)
    {
        if (arg1 <= 2)
        {
            int32_t result = data_4101ac;
            data_4101ac = arg1;
            return result;
        }
        
        if (arg1 == 3)
            return data_4101ac;
    }
    
    *__errno() = 0x16;
    sub_4041db(0, 0, 0, 0, 0);
    return 0xffffffff;
}

int32_t __convention("regparm") sub_408b26(int32_t* arg1, int32_t* arg2, PSTR arg3, char arg4, int32_t arg5, char arg6)
{
    int32_t var_18 = 0;
    int32_t var_1c = 0;
    char var_6 = 0;
    SECURITY_ATTRIBUTES securityAttributes;
    securityAttributes.nLength = 0xc;
    securityAttributes.lpSecurityDescriptor = 0;
    char var_5;
    
    if (!(arg4 & 0x80))
    {
        securityAttributes.bInheritHandle = 1;
        var_5 = 0;
    }
    else
    {
        securityAttributes.bInheritHandle = 0;
        var_5 = 0x10;
    }
    
    if (sub_40acc9(&var_18))
    {
        int32_t var_4c_1;
        __builtin_memset(&var_4c_1, 0, 0x14);
        sub_4040df();
        /* no return */
    }
    
    if (sub_404ccc(&var_1c))
    {
        int32_t var_4c_2;
        __builtin_memset(&var_4c_2, 0, 0x14);
        sub_4040df();
        /* no return */
    }
    
    if (!(arg4 & 0x8000) && (arg4 & 0x74000 || var_18 != 0x8000))
        var_5 |= 0x80;
    
    int32_t eax_3 = arg4 & 3;
    uint32_t dwDesiredAccess;
    
    if (!eax_3)
    {
        dwDesiredAccess = 0x80000000;
    label_408c09:
        uint32_t dwShareMode;
        
        if (arg5 != 0x10)
        {
            if (arg5 == 0x20)
            {
                dwShareMode = 1;
                goto label_408c4d;
            }
            
            if (arg5 == 0x30)
            {
                dwShareMode = 2;
                goto label_408c4d;
            }
            
            if (arg5 == 0x40)
            {
                dwShareMode = 3;
                goto label_408c4d;
            }
            
            if (arg5 != 0x80)
                goto label_408bd0;
            
            uint32_t dwShareMode_1;
            dwShareMode_1 = dwDesiredAccess == 0x80000000;
            dwShareMode = dwShareMode_1;
            goto label_408c4d;
        }
        
        dwShareMode = 0;
    label_408c4d:
        int32_t eax_16 = arg4 & 0x700;
        enum FILE_CREATION_DISPOSITION dwCreationDisposition;
        
        if (eax_16 > 0x400)
        {
            if (eax_16 == 0x500)
                dwCreationDisposition = CREATE_NEW;
            else if (eax_16 == 0x600)
                dwCreationDisposition = TRUNCATE_EXISTING;
            else
            {
                if (eax_16 != 0x700)
                    goto label_408bd0;
                
                dwCreationDisposition = CREATE_NEW;
            }
        }
        else if (eax_16 == 0x400 || !eax_16)
            dwCreationDisposition = OPEN_EXISTING;
        else if (eax_16 == 0x100)
            dwCreationDisposition = OPEN_ALWAYS;
        else if (eax_16 == 0x200)
            dwCreationDisposition = TRUNCATE_EXISTING;
        else
        {
            if (eax_16 != 0x300)
                goto label_408bd0;
            
            dwCreationDisposition = CREATE_ALWAYS;
        }
        
        int32_t ecx_2 = arg4;
        enum FILE_FLAGS_AND_ATTRIBUTES dwFlagsAndAttributes = FILE_ATTRIBUTE_NORMAL;
        
        if (0x100 & ecx_2 && (~data_410310 & arg6) >= 0)
            dwFlagsAndAttributes = FILE_ATTRIBUTE_READONLY;
        
        if (ecx_2 & 0x40)
        {
            dwDesiredAccess |= 0x10000;
            dwFlagsAndAttributes |= FILE_FLAG_DELETE_ON_CLOSE;
            
            if (var_1c == 2)
                dwShareMode |= 4;
        }
        
        if (ecx_2 & 0x1000)
            dwFlagsAndAttributes |= FILE_ATTRIBUTE_TEMPORARY;
        
        if (ecx_2 & 0x20)
            dwFlagsAndAttributes |= FILE_FLAG_SEQUENTIAL_SCAN;
        else if (ecx_2 & 0x10)
            dwFlagsAndAttributes |= FILE_FLAG_RANDOM_ACCESS;
        
        int32_t eax_17 = sub_407e8d();
        *arg1 = eax_17;
        
        if (eax_17 == 0xffffffff)
        {
            *___doserrno() = 0;
            *arg1 = 0xffffffff;
            *__errno() = 0x18;
            return *__errno();
        }
        
        *arg2 = 1;
        HANDLE eax_21 = CreateFileA(arg3, dwDesiredAccess, dwShareMode, &securityAttributes, 
            dwCreationDisposition, dwFlagsAndAttributes, nullptr);
        
        if (eax_21 == 0xffffffff)
        {
            int32_t esi_1 = *arg1;
            char* eax_25 = (&data_410c40)[esi_1 >> 5] + (esi_1 & 0x1f) * 0x28 + 4;
            *eax_25 &= 0xfe;
            sub_402447(GetLastError());
            return *__errno();
        }
        
        enum FILE_TYPE eax_29 = GetFileType(eax_21);
        
        if (!eax_29)
        {
            int32_t esi_4 = *arg1;
            char* eax_33 = (&data_410c40)[esi_4 >> 5] + (esi_4 & 0x1f) * 0x28 + 4;
            *eax_33 &= 0xfe;
            CloseHandle(eax_21);
            sub_402447(GetLastError());
            return *__errno();
        }
        
        if (eax_29 == FILE_TYPE_CHAR)
            var_5 |= 0x40;
        else if (eax_29 == FILE_TYPE_PIPE)
            var_5 |= 8;
        
        sub_407c5c(*arg1, eax_21);
        int32_t eax_34 = *arg1;
        char ecx_4 = var_5 | 1;
        *((&data_410c40)[eax_34 >> 5] + (eax_34 & 0x1f) * 0x28 + 4) = ecx_4;
        int32_t eax_37 = *arg1;
        int32_t edx_9 = (&data_410c40)[eax_37 >> 5];
        *(edx_9 + (eax_37 & 0x1f) * 0x28 + 0x24) &= 0x80;
        char temp8_1 = ecx_4 & 0x48;
        
        if (!temp8_1)
        {
            if (!(ecx_4 & 0x80))
                goto label_4090eb;
            
            if (!(arg4 & 2))
                goto label_408eb1;
            
            uint32_t dwShareMode_2 = sub_405130(*arg1, 0xffffffff, FILE_END);
            dwShareMode = dwShareMode_2;
            
            if (dwShareMode_2 != 0xffffffff)
            {
                int32_t var_44_3 = *arg1;
                char var_8 = 0;
                
                if (!sub_40452a(var_44_3, &var_8, 1) && var_8 == 0x1a)
                {
                    int32_t eax_44;
                    int32_t edx_10;
                    edx_10 = HIGHD(dwShareMode);
                    eax_44 = LOWD(dwShareMode);
                    
                    if (sub_40aa59(*arg1, eax_44, edx_10) == 0xffffffff)
                    {
                        sub_4041ff(*arg1);
                        return *__errno();
                    }
                }
                
                uint32_t eax_46;
                eax_46 = sub_405130(*arg1, 0, FILE_BEGIN);
                
                if (eax_46 == 0xffffffff)
                {
                    sub_4041ff(*arg1);
                    return *__errno();
                }
            }
            else
            {
                void* eax_41;
                eax_41 = ___doserrno();
                
                if (*eax_41 != 0x83)
                {
                    sub_4041ff(*arg1);
                    return *__errno();
                }
            }
        }
        
    label_408eb1:
        
        if (!(ecx_4 & 0x80))
            goto label_4090eb;
        
        if (!(arg4 & 0x74000))
        {
            int32_t eax_48 = var_18 & 0x74000;
            
            if (eax_48)
                arg4 |= eax_48;
            else
                arg4 |= 0x4000;
        }
        
        int32_t eax_50 = arg4 & 0x74000;
        
        if (eax_50 == 0x4000)
            var_6 = 0;
        else if (eax_50 == 0x10000 || eax_50 == 0x14000)
        {
            if ((arg4 & 0x301) == 0x301)
                var_6 = 2;
        }
        else if (eax_50 == 0x20000 || eax_50 == 0x24000)
            var_6 = 2;
        else if (eax_50 == 0x40000 || eax_50 == 0x44000)
            var_6 = 1;
        
        if (!(arg4 & 0x70000))
            goto label_4090eb;
        
        dwShareMode = 0;
        
        if (ecx_4 & 0x40)
            goto label_4090eb;
        
        int32_t eax_52 = dwDesiredAccess & 0xc0000000;
        enum FILE_CREATION_DISPOSITION dwCreationDisposition_1;
        uint32_t eax_64;
        
        if (eax_52 == 0x40000000)
        {
            dwCreationDisposition_1 = dwCreationDisposition;
            
            if (dwCreationDisposition_1 <= 0)
                goto label_4090eb;
            
            if (dwCreationDisposition_1 > CREATE_ALWAYS)
            {
                if (dwCreationDisposition_1 > OPEN_ALWAYS)
                {
                label_408f7c:
                    
                    if (dwCreationDisposition_1 != TRUNCATE_EXISTING)
                        goto label_4090eb;
                    
                    goto label_408f85;
                }
                
                uint32_t eax_61;
                int32_t ecx_8;
                eax_61 =
                    sub_4077ee(dwCreationDisposition_1, edx_9, 0xc0000000, *arg1, 0, 0, FILE_END);
                int32_t eax_62 = eax_61 | edx_9;
                
                if (!eax_62)
                    goto label_408f85;
                
                uint32_t eax_63;
                eax_63 = sub_4077ee(eax_62, edx_9, ecx_8, *arg1, 0, 0, FILE_BEGIN);
                eax_64 = eax_63 & edx_9;
            label_409051:
                
                if (eax_64 != 0xffffffff)
                    goto label_4090eb;
                
                sub_4041ff(*arg1);
                return *__errno();
            }
            
        label_408f85:
            int32_t eax_53 = var_6;
            void* edi_2 = nullptr;
            int32_t var_14_1;
            
            if (eax_53 == 1)
            {
                dwShareMode = 0xbfbbef;
                var_14_1 = 3;
            }
            else
            {
                if (eax_53 != 2)
                    goto label_4090eb;
                
                dwShareMode = 0xfeff;
                var_14_1 = 2;
            }
            
            while (true)
            {
                int32_t __saved_ebp;
                void* eax_72;
                eax_72 = sub_403adc(*arg1, &__saved_ebp + edi_2 - 8, var_14_1 - edi_2);
                
                if (eax_72 == 0xffffffff)
                    break;
                
                edi_2 += eax_72;
                
                if (var_14_1 <= edi_2)
                    goto label_4090eb;
            }
            
            sub_4041ff(*arg1);
            return *__errno();
        }
        
        if (eax_52 != 0x80000000)
        {
            if (eax_52 != 0xc0000000)
                goto label_4090eb;
            
            dwCreationDisposition_1 = dwCreationDisposition;
            
            if (dwCreationDisposition_1 <= 0)
                goto label_4090eb;
            
            if (dwCreationDisposition_1 <= CREATE_ALWAYS)
                goto label_408f85;
            
            if (dwCreationDisposition_1 > OPEN_ALWAYS)
                goto label_408f7c;
            
            uint32_t eax_56;
            int32_t ecx_7;
            eax_56 = sub_4077ee(dwCreationDisposition_1, edx_9, 0xc0000000, *arg1, 0, 0, FILE_END);
            int32_t eax_57 = eax_56 | edx_9;
            
            if (!eax_57)
                goto label_408f85;
            
            uint32_t eax_58;
            int32_t edx_11;
            eax_58 = sub_4077ee(eax_57, edx_9, ecx_7, *arg1, 0, 0, FILE_BEGIN);
            
            if ((eax_58 & edx_11) != 0xffffffff)
                goto label_408fde;
            
            sub_4041ff(*arg1);
            return *__errno();
        }
        
    label_408fde:
        int32_t eax_60;
        eax_60 = sub_40452a(*arg1, &dwShareMode, 3);
        
        if (eax_60 == 0xffffffff)
        {
            sub_4041ff(*arg1);
            return *__errno();
        }
        
        if (eax_60 != 2)
        {
            if (eax_60 != 3)
            {
            label_4090ae:
                eax_64 = sub_405130(*arg1, 0, FILE_BEGIN);
                goto label_409051;
            }
            
            if (dwShareMode != 0xbfbbef)
                goto label_409062;
            
            var_6 = 1;
        label_4090eb:
            int32_t eax_73 = *arg1;
            char* eax_76 = (&data_410c40)[eax_73 >> 5] + (eax_73 & 0x1f) * 0x28 + 0x24;
            int32_t ecx_12;
            ecx_12 = *eax_76;
            ecx_12 ^= var_6;
            ecx_12 &= 0x7f;
            *eax_76 ^= ecx_12;
            int32_t eax_77 = *arg1;
            char* eax_80 = (&data_410c40)[eax_77 >> 5] + (eax_77 & 0x1f) * 0x28 + 0x24;
            edx_9 = *eax_80;
            edx_9 &= 0x7f;
            *eax_80 = arg4 >> 0x10 << 7 | edx_9;
            
            if (!temp8_1 && arg4 & 8)
            {
                int32_t esi_7 = *arg1;
                char* eax_84 = (&data_410c40)[esi_7 >> 5] + (esi_7 & 0x1f) * 0x28 + 4;
                *eax_84 |= 0x20;
            }
            
            return 0;
        }
        
    label_409062:
        uint32_t eax_66 = dwShareMode;
        
        if (eax_66 != 0xfffe)
        {
            if (eax_66 != 0xfeff)
                goto label_4090ae;
            
            uint32_t eax_68;
            eax_68 = sub_405130(*arg1, 2, FILE_BEGIN);
            
            if (eax_68 == 0xffffffff)
            {
                sub_4041ff(*arg1);
                return *__errno();
            }
            
            var_6 = 2;
            goto label_4090eb;
        }
        
        sub_4041ff(*arg1);
        *__errno() = 0x16;
    }
    else
    {
        if (eax_3 == 1)
        {
            dwDesiredAccess = 0x40000000;
            goto label_408c09;
        }
        
        if (eax_3 == 2)
        {
            dwDesiredAccess = 0xc0000000;
            goto label_408c09;
        }
        
    label_408bd0:
        *___doserrno() = 0;
        *arg1 = 0xffffffff;
        *__errno() = 0x16;
        sub_4041db(0, 0, 0, 0, 0);
    }
    return 0x16;
}

int32_t sub_409164(int32_t arg1, char arg2, int32_t arg3, int32_t arg4, int32_t* arg5, int32_t arg6)
{
    int32_t __saved_ebp_1 = 0x14;
    int32_t var_8 = 0x40e7b8;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e7b8 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_38 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_38;
    void* const var_3c_2 = &data_409170;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_20 = 0;
    int32_t eax;
    eax = arg5;
    int32_t result;
    
    if (eax)
    {
        *arg5 = 0xffffffff;
        int32_t eax_2;
        eax_2 = arg1;
        
        if (!eax_2)
            goto label_409188;
        
        int32_t eax_4;
        int32_t eax_5;
        
        if (arg6)
        {
            eax_4 = arg4 & 0xfffffe7f;
            eax_5 = -(eax_4);
        }
        
        if (arg6 && eax_5 - eax_5 == 0xffffffff)
            goto label_409188;
        
        int32_t var_8_1 = 0;
        int32_t var_3c_1 = arg4;
        int32_t var_40_1 = arg3;
        PSTR ecx;
        int32_t* edx;
        int32_t result_1 = sub_408b26(arg5, edx, ecx, &var_20, arg1, arg2);
        int32_t var_8_2 = 0xfffffffe;
        sub_409202(&__saved_ebp, 0, arg5);
        result = result_1;
        
        if (result)
            *arg5 = 0xffffffff;
    }
    else
    {
    label_409188:
        int32_t var_3c = 0x16;
        *__errno() = 0x16;
        sub_4041db(0, 0, 0, 0, 0);
        result = 0x16;
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_4091fc;
    return result;
}

void sub_409202(void* arg1 @ ebp, int32_t arg2 @ esi, int32_t* arg3 @ edi)
{
    if (*(arg1 - 0x1c) == arg2)
        return;
    
    if (*(arg1 - 0x20) != arg2)
    {
        int32_t eax_1 = *arg3;
        char* eax_4 = (&data_410c40)[eax_1 >> 5] + (eax_1 & 0x1f) * 0x28 + 4;
        *eax_4 &= 0xfe;
    }
    
    sub_407e6b(*arg3);
}

int32_t sub_409230(int32_t* arg1, int32_t arg2, char arg3, int32_t arg4, int32_t arg5)
{
    return sub_409164(arg2, arg3, arg4, arg5, arg1, 1);
}

uint32_t sub_40924e(void* arg1, char* arg2, int32_t* arg3)
{
    void var_18;
    sub_405aa0(&var_18, arg3);
    char* edx = arg1;
    void* var_10;
    char var_c;
    
    if (!edx)
    {
        *__errno() = 0x16;
        sub_4041db(0, 0, 0, 0, 0);
        
        if (var_c)
            *(var_10 + 0x70) &= 0xfffffffd;
        
        return 0x7fffffff;
    }
    
    char* ebx_1 = arg2;
    
    if (!ebx_1)
    {
        *__errno() = 0x16;
        sub_4041db(0, 0, 0, 0, 0);
        
        if (var_c)
            *(var_10 + 0x70) &= 0xfffffffd;
        
        return 0x7fffffff;
    }
    
    void* var_14;
    void* eax_4 = var_14;
    uint32_t result;
    
    if (*(eax_4 + 8))
    {
        while (true)
        {
            uint32_t ecx_3 = *edx;
            arg1 = &edx[1];
            int16_t esi_2;
            
            if (!(*(ecx_3 + eax_4 + 0x1d) & 4))
            {
                uint32_t edx_3 = ecx_3;
                ecx_3 = edx_3 + eax_4;
                
                if (!(*(ecx_3 + 0x1d) & 0x10))
                    esi_2 = edx_3;
                else
                {
                    ecx_3 = *(ecx_3 + 0x11d);
                    esi_2 = ecx_3;
                }
                
                goto label_40938b;
            }
            
            char var_8;
            char var_7;
            
            if (edx[1])
            {
                int32_t eax_5;
                eax_5 =
                    sub_40b09f(&var_18, *(eax_4 + 0xc), 0x200, edx, 2, &var_8, 2, *(eax_4 + 4), 1);
                
                if (eax_5 == 1)
                {
                    eax_5 = var_8;
                label_409364:
                    arg1 += 1;
                    esi_2 = eax_5;
                    eax_4 = var_14;
                    goto label_40938b;
                }
                
                if (eax_5 == 2)
                {
                    eax_5 = var_8;
                    ecx_3 = var_7;
                    eax_5 <<= 8;
                    eax_5 += ecx_3;
                    goto label_409364;
                }
            }
            else
            {
                esi_2 = 0;
            label_40938b:
                ecx_3 = *ebx_1;
                int16_t ecx_4 = ecx_3;
                ebx_1 = &ebx_1[1];
                uint16_t ecx_1;
                
                if (!(*(ecx_4 + eax_4 + 0x1d) & 4))
                {
                    uint32_t edx_5 = ecx_4;
                    void* ecx_7 = edx_5 + eax_4;
                    
                    if (!(*(ecx_7 + 0x1d) & 0x10))
                        ecx_1 = edx_5;
                    else
                    {
                        ecx_7 = *(ecx_7 + 0x11d);
                        ecx_1 = ecx_7;
                    }
                    
                    goto label_409411;
                }
                
                if (*ebx_1)
                {
                    int32_t eax_6 = sub_40b09f(&var_18, *(eax_4 + 0xc), 0x200, &ebx_1[0xffffffff], 
                        2, &var_8, 2, *(eax_4 + 4), 1);
                    
                    if (eax_6 == 1)
                    {
                        eax_6 = var_8;
                    label_4093e9:
                        ecx_1 = eax_6;
                        eax_4 = var_14;
                        ebx_1 = &ebx_1[1];
                        goto label_409411;
                    }
                    
                    if (eax_6 == 2)
                    {
                        eax_6 = var_8;
                        eax_6 <<= 8;
                        eax_6 += var_7;
                        goto label_4093e9;
                    }
                }
                else
                {
                    ecx_1 = 0;
                label_409411:
                    
                    if (ecx_1 != esi_2)
                    {
                        result = ((eax_4 - eax_4) & 2) - 1;
                        
                        if (var_c)
                            *(var_10 + 0x70) &= 0xfffffffd;
                        
                        break;
                    }
                    
                    if (esi_2)
                    {
                        edx = arg1;
                        continue;
                    }
                    
                    if (var_c)
                        *(var_10 + 0x70) &= 0xfffffffd;
                    
                    return 0;
                }
            }
            *__errno() = 0x16;
            
            if (var_c)
                *(var_10 + 0x70) &= 0xfffffffd;
            
            return 0x7fffffff;
        }
    }
    else
    {
        result = sub_40b117(edx, ebx_1, &var_18);
        
        if (var_c)
            *(var_10 + 0x70) &= 0xfffffffd;
    }
    
    return result;
}

uint32_t sub_409468(void* arg1, char* arg2)
{
    return sub_40924e(arg1, arg2, nullptr);
}

uint32_t sub_40947b(char* arg1, char* arg2, int32_t arg3, int32_t* arg4)
{
    if (!arg3)
        return 0;
    
    void var_14;
    sub_405aa0(&var_14, arg4);
    void* var_10;
    uint32_t result;
    void* var_c;
    char var_8;
    
    if (*(var_10 + 8))
    {
        if (!arg1)
        {
            *__errno() = 0x16;
            sub_4041db(0, 0, 0, 0, 0);
            
            if (var_8)
                *(var_c + 0x70) &= 0xfffffffd;
            
            return 0x7fffffff;
        }
        
        char* esi_1 = arg2;
        
        if (!esi_1)
        {
            *__errno() = 0x16;
            sub_4041db(0, 0, 0, 0, 0);
            
            if (var_8)
                *(var_c + 0x70) &= 0xfffffffd;
            
            return 0x7fffffff;
        }
        
        uint32_t eax_8;
        uint16_t ecx_2;
        
        while (true)
        {
            arg3 -= 1;
            ecx_2 = *arg1;
            void* eax_6 = &arg1[1];
            arg1 = eax_6;
            
            if (!(*(ecx_2 + var_10 + 0x1d) & 4))
            {
            label_40957a:
                eax_6 = *esi_1;
                eax_8 = eax_6;
                esi_1 = &esi_1[1];
                
                if (*(eax_8 + var_10 + 0x1d) & 4)
                {
                    if (arg3)
                    {
                        uint32_t edx_3;
                        edx_3 = *esi_1;
                        arg3 -= 1;
                        
                        if (!edx_3)
                            eax_8 = 0;
                        else
                        {
                            int16_t ebx_1;
                            *ebx_1[1] = eax_8;
                            esi_1 = &esi_1[1];
                            ebx_1 = edx_3;
                            eax_8 = ebx_1;
                        }
                    }
                    else
                        eax_8 = 0;
                }
                
                goto label_4095ad;
            }
            
            if (arg3)
            {
                eax_6 = *eax_6;
                
                if (eax_6)
                {
                    arg1 = &arg1[1];
                    uint16_t edx_2;
                    *edx_2[1] = ecx_2;
                    edx_2 = eax_6;
                    ecx_2 = edx_2;
                }
                else
                    ecx_2 = 0;
                
                goto label_40957a;
            }
            
            uint32_t eax_7 = *esi_1;
            ecx_2 = 0;
            
            if (!(*(eax_7 + var_10 + 0x1d) & 4))
            {
                eax_8 = eax_7;
            label_4095ad:
                
                if (eax_8 != ecx_2)
                    break;
                
                if (ecx_2 && arg3)
                    continue;
            }
            
            if (var_8)
                *(var_c + 0x70) &= 0xfffffffd;
            
            return 0;
        }
        
        result = ((eax_8 - eax_8) & 2) - 1;
        
        if (var_8)
            *(var_c + 0x70) &= 0xfffffffd;
    }
    else
    {
        result = sub_40b1ea(arg1, arg2, arg3);
        
        if (var_8)
            *(var_c + 0x70) &= 0xfffffffd;
    }
    return result;
}

uint32_t sub_4095e4(char* arg1, char* arg2, int32_t arg3)
{
    return sub_40947b(arg1, arg2, arg3, nullptr);
}

int32_t sub_4095fc(int32_t arg1)
{
    int32_t ebp;
    int32_t var_4 = ebp;
    int32_t result = RtlUnwind(arg1, 0x409614, nullptr, nullptr);
    var_4;
    return result;
}

int32_t __unwind_handler(int32_t arg1, int32_t arg2, int32_t* arg3, void* arg4)
{
    if (!(*(arg1 + 4) & 6))
        return 1;
    
    sub_4076f5(*(arg4 - 4) ^ arg4);
    *(arg4 + 0x10);
    __local_unwind2(*(arg4 + 0x24), *(arg4 + 0x28));
    *arg3 = arg2;
    return 3;
}

void* __local_unwind2(void* arg1, int32_t arg2)
{
    int32_t ebp;
    int32_t var_10 = ebp;
    void* var_14 = arg1;
    int32_t var_18 = 0xfffffffe;
    int32_t (* var_1c)(int32_t arg1, int32_t arg2, int32_t* arg3, void* arg4) = __unwind_handler;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t var_24 = __security_cookie ^ &ExceptionList;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    
    while (true)
    {
        int32_t ebx_1 = *(arg1 + 8);
        int32_t esi_1 = *(arg1 + 0xc);
        
        if (esi_1 == 0xffffffff)
        {
            fsbase->NtTib.ExceptionList = ExceptionList;
            return arg1;
        }
        
        if (arg2 != 0xffffffff && esi_1 <= arg2)
        {
            fsbase->NtTib.ExceptionList = ExceptionList;
            return arg1;
        }
        
        int32_t esi_2 = esi_1 * 3;
        int32_t ecx_1 = *(ebx_1 + (esi_2 << 2));
        int32_t var_18_1 = ecx_1;
        *(arg1 + 0xc) = ecx_1;
        
        if (!*(ebx_1 + (esi_2 << 2) + 4))
        {
            __NLG_Notify(*(ebx_1 + (esi_2 << 2) + 8), ebp, 0x101);
            *(ebx_1 + (esi_2 << 2) + 8);
            __NLG_Call();
        }
    }
}

int32_t __abnormal_termination()
{
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    
    if (ExceptionList->Handler == __unwind_handler
            && *(ExceptionList + 8) == *(*(ExceptionList + 0xc) + 0xc))
        return 1;
    
    return 0;
}

int32_t __stdcall __NLG_Notify(int32_t arg1 @ eax, int32_t arg2 @ ebp, int32_t arg3)
{
    data_40f928 = arg3;
    data_40f924 = arg1;
    data_40f92c = arg2;
    int32_t var_c = arg2;
    int32_t var_10 = arg3;
    return arg1;
}

int32_t __NLG_Call()
{
    int32_t eax;
    return eax();
}

int32_t __convention("regparm") sub_409733(int32_t arg1) __pure
{
    if (arg1 == 0x3a4)
        return 0x411;
    
    if (arg1 == 0x3a8)
        return 0x804;
    
    if (arg1 == 0x3b5)
        return 0x412;
    
    if (arg1 == 0x3b6)
        return 0x404;
    
    return 0;
}

void* __convention("regparm") sub_409762(void* arg1)
{
    int32_t i_2 = 0x101;
    char* ebx = arg1 + 0x1c;
    sub_404390(ebx, 0, 0x101);
    *(arg1 + 4) = 0;
    *(arg1 + 8) = 0;
    *(arg1 + 0xc) = 0;
    *(arg1 + 0x10) = 0;
    void* edi_1 = arg1 + 0x14;
    *edi_1 = 0;
    *(edi_1 + 4) = 0;
    int32_t i;
    
    do
    {
        *ebx = *(0x40f930 - arg1 + ebx);
        ebx = &ebx[1];
        i = i_2;
        i_2 -= 1;
    } while (i != 1);
    void* ecx_2 = arg1 + 0x11d;
    int32_t i_3 = 0x100;
    int32_t i_1;
    
    do
    {
        *ecx_2 = *(ecx_2 + 0x40f930 - arg1);
        ecx_2 += 1;
        i_1 = i_3;
        i_3 -= 1;
    } while (i_1 != 1);
    return 0x40f930 - arg1;
}

void* sub_4097b7(void* arg1 @ esi)
{
    void var_4a0;
    int32_t eax_1 = __security_cookie ^ &var_4a0;
    CPINFO cPInfo;
    void* i_2;
    
    if (!GetCPInfo(*(arg1 + 4), &cPInfo))
    {
        for (int32_t i = 0; i < 0x100; i += 1)
        {
            i_2 = arg1 + i + 0x11d;
            void* edx_3 = 0xffffff9f - (arg1 + 0x11d) + i_2;
            
            if (edx_3 + 0x20 <= 0x19)
            {
                *(arg1 + i + 0x1d) |= 0x10;
                edx_3 = i;
                edx_3 += 0x20;
                *i_2 = edx_3;
            }
            else if (edx_3 > 0x19)
                *i_2 = 0;
            else
            {
                *(arg1 + i + 0x1d) |= 0x20;
                edx_3 = i;
                edx_3 -= 0x20;
                *i_2 = edx_3;
            }
        }
    }
    else
    {
        char var_108[0x100];
        uint32_t i_1;
        
        for (i_1 = 0; i_1 < 0x100; i_1 += 1)
            var_108[i_1] = i_1;
        
        i_1 = cPInfo.LeadByte[0];
        var_108[0] = 0x20;
        
        if (i_1)
        {
            var_515;
            void* ebx_1 = &var_515;
            
            do
            {
                uint32_t ecx_1 = i_1;
                i_1 = *ebx_1;
                
                if (ecx_1 <= i_1)
                    sub_404390(&var_4a0 + ecx_1 + 0x398, 0x20, i_1 - ecx_1 + 1);
                
                i_1 = *(ebx_1 + 1);
                ebx_1 += 2;
            } while (i_1);
        }
        
        int16_t var_508[0x34];
        sub_40b460(nullptr, 1, &var_108, 0x100, &var_508, *(arg1 + 4), *(arg1 + 0xc), 0);
        char var_208[0x100];
        sub_40b09f(nullptr, *(arg1 + 0xc), 0x100, &var_108, 0x100, &var_208, 0x100, *(arg1 + 4), 0);
        char var_308[0x100];
        sub_40b09f(nullptr, *(arg1 + 0xc), 0x200, &var_108, 0x100, &var_308, 0x100, *(arg1 + 4), 0);
        
        for (i_2 = nullptr; i_2 < 0x100; i_2 += 1)
        {
            char ecx_2 = var_508[i_2];
            
            if (ecx_2 & 1)
            {
                *(arg1 + i_2 + 0x1d) |= 0x10;
                *(arg1 + i_2 + 0x11d) = *(&var_208 + i_2);
            }
            else if (!(ecx_2 & 2))
                *(arg1 + i_2 + 0x11d) = 0;
            else
            {
                *(arg1 + i_2 + 0x1d) |= 0x20;
                *(arg1 + i_2 + 0x11d) = *(&var_308 + i_2);
            }
        }
    }
    
    sub_4076f5(eax_1 ^ &var_4a0);
    return i_2;
}

void* sub_409941()
{
    int32_t __saved_ebp_1 = 0xc;
    int32_t var_8 = 0x40e7d8;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e7d8 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_3 = &data_40994d;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    void* eax = __getptd();
    void* result;
    
    if (!(*(eax + 0x70) & data_40fe54) || !*(eax + 0x6c))
    {
        sub_402690(0xd);
        int32_t var_8_1 = 0;
        result = *(eax + 0x68);
        void* result_1 = result;
        
        if (result != data_40fd58)
        {
            if (result && !InterlockedDecrement(result) && result != 0x40f930)
                sub_40139b(result);
            
            *(eax + 0x68) = data_40fd58;
            result = data_40fd58;
            void* result_2 = result;
            InterlockedIncrement(result);
        }
        
        int32_t var_8_2 = 0xfffffffe;
        sub_4099dc();
    }
    else
        result = *(eax + 0x68);
    
    if (!result)
        sub_404c23(0x20);
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_40997a;
    return result;
}

int32_t sub_4099dc()
{
    return __unlock(0xd);
}

uint32_t sub_4099e5(uint32_t arg1 @ esi)
{
    void* var_14;
    sub_405aa0(&var_14, nullptr);
    data_4107e0 = 0;
    void* var_c;
    char var_8;
    uint32_t eax_1;
    
    if (arg1 == 0xfffffffe)
    {
        data_4107e0 = 1;
        eax_1 = GetOEMCP();
    }
    else if (arg1 != 0xfffffffd)
    {
        if (arg1 != 0xfffffffc)
        {
            if (var_8)
                *(var_c + 0x70) &= 0xfffffffd;
            
            return arg1;
        }
        
        eax_1 = *(var_14 + 4);
        data_4107e0 = 1;
    }
    else
    {
        data_4107e0 = 1;
        eax_1 = GetACP();
    }
    
    if (var_8)
        *(var_c + 0x70) &= 0xfffffffd;
    
    return eax_1;
}

int32_t sub_409a5f(uint32_t arg1, void* arg2)
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    uint32_t CodePage = sub_4099e5(arg1);
    arg1 = CodePage;
    int32_t result;
    
    if (CodePage)
    {
        int32_t var_20_1 = 0;
        void* eax_4 = nullptr;
        
        while (true)
        {
            if (*(eax_4 + 0x40fd60) == CodePage)
            {
                sub_404390(arg2 + 0x1c, 0, 0x101);
                void* ecx_3 = var_20_1 * 0x30;
                void* var_24_1 = nullptr;
                void* esi_2 = ecx_3 + 0x40fd70;
                void* var_20_2 = esi_2;
                
                while (true)
                {
                    if (*esi_2)
                    {
                        char* eax_8;
                        eax_8 = *(esi_2 + 1);
                        
                        if (eax_8)
                        {
                            uint32_t i = *esi_2;
                            
                            for (eax_8 = eax_8; i <= eax_8; i += 1)
                            {
                                void* eax_9;
                                eax_9 = *(var_24_1 + 0x40fd5c);
                                *(arg2 + i + 0x1d) |= eax_9;
                                eax_8 = *(esi_2 + 1);
                            }
                            
                            CodePage = arg1;
                            esi_2 += 2;
                            continue;
                        }
                    }
                    
                    var_24_1 += 1;
                    esi_2 = var_20_2 + 8;
                    var_20_2 = esi_2;
                    
                    if (var_24_1 >= 4)
                        break;
                }
                
                *(arg2 + 4) = CodePage;
                *(arg2 + 8) = 1;
                *(arg2 + 0xc) = sub_409733(CodePage);
                void* eax_12 = arg2 + 0x10;
                int16_t* ecx_4 = ecx_3 + 0x40fd64;
                int32_t i_5 = 6;
                int32_t i_1;
                
                do
                {
                    esi_2 = *ecx_4;
                    *eax_12 = esi_2;
                    ecx_4 = &ecx_4[1];
                    eax_12 += 2;
                    i_1 = i_5;
                    i_5 -= 1;
                } while (i_1 != 1);
            label_409ba0:
                sub_4097b7(arg2);
                break;
            }
            
            var_20_1 += 1;
            eax_4 += 0x30;
            
            if (eax_4 >= 0xf0)
            {
                CPINFO cPInfo;
                
                if (!GetCPInfo(CodePage, &cPInfo))
                {
                    if (data_4107e0)
                        goto label_409a8a;
                    
                    result = 0xffffffff;
                    goto label_409c03;
                }
                
                sub_404390(arg2 + 0x1c, 0, 0x101);
                bool cond:2_1 = cPInfo.MaxCharSize <= 1;
                *(arg2 + 4) = CodePage;
                *(arg2 + 0xc) = 0;
                
                if (cond:2_1)
                    *(arg2 + 8) = 0;
                else
                {
                    if (cPInfo.LeadByte[0])
                    {
                        var_15;
                        void* esi_1 = &var_15;
                        
                        do
                        {
                            uint32_t ecx_1;
                            ecx_1 = *esi_1;
                            
                            if (!ecx_1)
                                break;
                            
                            for (uint32_t i_2 = *(esi_1 - 1); i_2 <= ecx_1; i_2 += 1)
                                *(arg2 + i_2 + 0x1d) |= 4;
                            
                            esi_1 += 2;
                        } while (*(esi_1 - 1));
                    }
                    
                    void* eax_14 = arg2 + 0x1e;
                    int32_t i_4 = 0xfe;
                    int32_t i_3;
                    
                    do
                    {
                        *eax_14 |= 8;
                        eax_14 += 1;
                        i_3 = i_4;
                        i_4 -= 1;
                    } while (i_3 != 1);
                    *(arg2 + 0xc) = sub_409733(*(arg2 + 4));
                    *(arg2 + 8) = 1;
                }
                
                *(arg2 + 0x10) = 0;
                void* edi_1 = arg2 + 0x14;
                *edi_1 = 0;
                *(edi_1 + 4) = 0;
                goto label_409ba0;
            }
        }
    }
    else
    {
    label_409a8a:
        sub_409762(arg2);
    }
    
    result = 0;
label_409c03:
    sub_4076f5(eax_1 ^ &__saved_ebp);
    return result;
}

int32_t sub_409c0a(uint32_t arg1)
{
    int32_t __saved_ebp_1 = 0x14;
    int32_t var_8 = 0x40e7f8;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e7f8 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_38 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_38;
    void* const var_3c_8 = &data_409c16;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t result = 0xffffffff;
    void* eax = __getptd();
    sub_409941();
    void* ebx = *(eax + 0x68);
    uint32_t eax_1 = sub_4099e5(arg1);
    
    if (eax_1 == *(ebx + 4))
        result = 0;
    else
    {
        void* eax_2 = sub_40655b(0x220);
        
        if (eax_2)
        {
            __builtin_memcpy(eax_2, *(eax + 0x68), 0x220);
            *eax_2 = 0;
            int32_t result_1 = sub_409a5f(eax_1, eax_2);
            result = result_1;
            
            if (!result_1)
            {
                if (!InterlockedDecrement(*(eax + 0x68)))
                {
                    void* eax_4 = *(eax + 0x68);
                    
                    if (eax_4 != 0x40f930)
                        sub_40139b(eax_4);
                }
                
                *(eax + 0x68) = eax_2;
                InterlockedIncrement(eax_2);
                
                if (!(*(eax + 0x70) & 2) && !(*data_40fe54 & 1))
                {
                    sub_402690(0xd);
                    int32_t var_8_1 = 0;
                    data_4107f0 = *(eax_2 + 4);
                    data_4107f4 = *(eax_2 + 8);
                    data_4107f8 = *(eax_2 + 0xc);
                    int32_t eax_8 = 0;
                    
                    while (true)
                    {
                        int32_t var_20_1 = eax_8;
                        
                        if (eax_8 >= 5)
                            break;
                        
                        *((eax_8 << 1) + &data_4107e4) = *(eax_2 + (eax_8 << 1) + 0x10);
                        eax_8 += 1;
                    }
                    
                    void* eax_9 = nullptr;
                    int16_t ecx_4;
                    
                    while (true)
                    {
                        void* var_20_2 = eax_9;
                        
                        if (eax_9 >= 0x101)
                            break;
                        
                        ecx_4 = *(eax_9 + eax_2 + 0x1c);
                        *(eax_9 + 0x40fb50) = ecx_4;
                        eax_9 += 1;
                    }
                    
                    void* eax_10 = nullptr;
                    
                    while (true)
                    {
                        void* var_20_3 = eax_10;
                        
                        if (eax_10 >= 0x100)
                            break;
                        
                        ecx_4 = *(eax_10 + eax_2 + 0x11d);
                        *(eax_10 + 0x40fc58) = ecx_4;
                        eax_10 += 1;
                    }
                    
                    if (!InterlockedDecrement(data_40fd58))
                    {
                        void* eax_12 = data_40fd58;
                        
                        if (eax_12 != 0x40f930)
                            sub_40139b(eax_12);
                    }
                    
                    data_40fd58 = eax_2;
                    InterlockedIncrement(eax_2);
                    int32_t var_8_2 = 0xfffffffe;
                    sub_409d6b();
                }
            }
            else if (result_1 == 0xffffffff)
            {
                if (eax_2 != 0x40f930)
                    sub_40139b(eax_2);
                
                *__errno() = 0x16;
            }
        }
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_409da3;
    return result;
}

int32_t sub_409d6b()
{
    return __unlock(0xd);
}

int32_t ___initmbctable()
{
    if (!data_410d4c)
    {
        sub_409c0a(0xfffffffd);
        data_410d4c = 1;
    }
    
    return 0;
}

struct _EXCEPTION_REGISTRATION_RECORD** sub_409dc2(void* arg1)
{
    int32_t eax = *(arg1 + 0xbc);
    
    if (eax && eax != &data_410028)
    {
        int32_t* eax_1 = *(arg1 + 0xb0);
        
        if (eax_1 && !*eax_1)
        {
            int32_t* eax_2 = *(arg1 + 0xb8);
            
            if (eax_2 && !*eax_2)
            {
                sub_40139b(eax_2);
                sub_40b670(*(arg1 + 0xbc));
            }
            
            int32_t* eax_3 = *(arg1 + 0xb4);
            
            if (eax_3 && !*eax_3)
            {
                sub_40139b(eax_3);
                sub_40b630(*(arg1 + 0xbc));
            }
            
            sub_40139b(*(arg1 + 0xb0));
            sub_40139b(*(arg1 + 0xbc));
        }
    }
    
    int32_t* eax_4 = *(arg1 + 0xc0);
    
    if (eax_4 && !*eax_4)
    {
        sub_40139b(*(arg1 + 0xc4) - 0xfe);
        sub_40139b(*(arg1 + 0xcc) - 0x80);
        sub_40139b(*(arg1 + 0xd0) - 0x80);
        sub_40139b(*(arg1 + 0xc0));
    }
    
    int32_t* eax_11 = *(arg1 + 0xd4);
    
    if (eax_11 != 0x40ff68 && !eax_11[0x2d])
    {
        sub_40b4a0(eax_11);
        sub_40139b(*(arg1 + 0xd4));
    }
    
    void* edi_1 = arg1 + 0x50;
    int32_t i_1 = 6;
    int32_t i;
    
    do
    {
        if (*(edi_1 - 8) != &data_40fe58)
        {
            int32_t* eax_12 = *edi_1;
            
            if (eax_12 && !*eax_12)
                sub_40139b(eax_12);
        }
        
        if (*(edi_1 - 4))
        {
            int32_t* eax_13 = *(edi_1 + 4);
            
            if (eax_13 && !*eax_13)
                sub_40139b(eax_13);
        }
        
        edi_1 += 0x10;
        i = i_1;
        i_1 -= 1;
    } while (i != 1);
    return sub_40139b(arg1);
}

int32_t sub_409f02(void* arg1)
{
    InterlockedIncrement(arg1);
    int32_t eax = *(arg1 + 0xb0);
    
    if (eax)
        InterlockedIncrement(eax);
    
    int32_t eax_1 = *(arg1 + 0xb8);
    
    if (eax_1)
        InterlockedIncrement(eax_1);
    
    int32_t eax_2 = *(arg1 + 0xb4);
    
    if (eax_2)
        InterlockedIncrement(eax_2);
    
    int32_t eax_3 = *(arg1 + 0xc0);
    
    if (eax_3)
        InterlockedIncrement(eax_3);
    
    void* ebx = arg1 + 0x50;
    int32_t i_1 = 6;
    int32_t i;
    
    do
    {
        if (*(ebx - 8) != &data_40fe58)
        {
            int32_t eax_4 = *ebx;
            
            if (eax_4)
                InterlockedIncrement(eax_4);
        }
        
        if (*(ebx - 4))
        {
            int32_t eax_5 = *(ebx + 4);
            
            if (eax_5)
                InterlockedIncrement(eax_5);
        }
        
        ebx += 0x10;
        i = i_1;
        i_1 -= 1;
    } while (i != 1);
    return InterlockedIncrement(*(arg1 + 0xd4) + 0xb4);
}

void* sub_409f88(void* arg1)
{
    if (arg1)
    {
        InterlockedDecrement(arg1);
        int32_t eax_1 = *(arg1 + 0xb0);
        
        if (eax_1)
            InterlockedDecrement(eax_1);
        
        int32_t eax_2 = *(arg1 + 0xb8);
        
        if (eax_2)
            InterlockedDecrement(eax_2);
        
        int32_t eax_3 = *(arg1 + 0xb4);
        
        if (eax_3)
            InterlockedDecrement(eax_3);
        
        int32_t eax_4 = *(arg1 + 0xc0);
        
        if (eax_4)
            InterlockedDecrement(eax_4);
        
        void* ebx_1 = arg1 + 0x50;
        int32_t i_1 = 6;
        int32_t i;
        
        do
        {
            if (*(ebx_1 - 8) != &data_40fe58)
            {
                int32_t eax_5 = *ebx_1;
                
                if (eax_5)
                    InterlockedDecrement(eax_5);
            }
            
            if (*(ebx_1 - 4))
            {
                int32_t eax_6 = *(ebx_1 + 4);
                
                if (eax_6)
                    InterlockedDecrement(eax_6);
            }
            
            ebx_1 += 0x10;
            i = i_1;
            i_1 -= 1;
        } while (i != 1);
        InterlockedDecrement(*(arg1 + 0xd4) + 0xb4);
    }
    
    return arg1;
}

void* __convention("regparm") sub_40a014(int32_t* arg1, void* arg2 @ edi)
{
    if (!arg2 || !arg1)
        return 0;
    
    void* esi = *arg1;
    
    if (esi != arg2)
    {
        *arg1 = arg2;
        sub_409f02(arg2);
        
        if (esi)
        {
            sub_409f88(esi);
            
            if (!*esi && esi != 0x40fe60)
                sub_409dc2(esi);
        }
    }
    
    return arg2;
}

void* sub_40a052()
{
    int32_t __saved_ebp_1 = 0xc;
    int32_t var_8 = 0x40e818;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e818 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34 = &data_40a05e;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    void* result = __getptd();
    
    if (!(*(result + 0x70) & data_40fe54) || !*(result + 0x6c))
    {
        sub_402690(0xc);
        int32_t var_8_1 = 0;
        void* var_20_1 = sub_40a014(result + 0x6c, data_40ff38);
        int32_t var_8_2 = 0xfffffffe;
        sub_40a0bc(&__saved_ebp);
    }
    else
        result = *(__getptd() + 0x6c);
    
    if (!result)
        sub_404c23(0x20);
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_40a090;
    return result;
}

int32_t sub_40a0bc(void* arg1 @ ebp)
{
    int32_t result = __unlock(0xc);
    *(arg1 - 0x1c);
    return result;
}

int32_t sub_40a0c8()
{
    int32_t result;
    result = data_410820 == (__security_cookie | 1);
    return result;
}

int32_t sub_40a0de(int32_t* arg1, BOOL arg2, int32_t arg3, int32_t* arg4)
{
    BOOL lpMultiByteStr = arg2;
    
    if (!lpMultiByteStr && arg3 > 0)
    {
        if (arg1)
            *arg1 = 0;
        
        return 0;
    }
    
    if (arg1)
        *arg1 = 0xffffffff;
    
    if (arg3 > 0x7fffffff)
    {
        *__errno() = 0x16;
        sub_4041db(0, 0, 0, 0, 0);
        return 0x16;
    }
    
    void* var_14;
    sub_405aa0(&var_14, arg4);
    void* eax_3 = var_14;
    void* var_c;
    char var_8;
    wchar16 wideCharStr;
    
    if (*(eax_3 + 0x14))
    {
        arg2 = 0;
        int32_t eax_10 = WideCharToMultiByte(*(eax_3 + 4), 0, &wideCharStr, 1, lpMultiByteStr, 
            arg3, nullptr, &arg2);
        
        if (!eax_10)
        {
            if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
            {
                if (lpMultiByteStr && arg3 > 0)
                    sub_404390(lpMultiByteStr, 0, arg3);
                
                goto label_40a197;
            }
            
        label_40a16a:
            *__errno() = 0x2a;
            int32_t result = *__errno();
            
            if (var_8)
                *(var_c + 0x70) &= 0xfffffffd;
            
            return result;
        }
        
        if (arg2)
            goto label_40a16a;
        
        if (arg1)
            *arg1 = eax_10;
    }
    else
    {
        eax_3 = wideCharStr;
        
        if (eax_3 > 0xff)
        {
            if (lpMultiByteStr && arg3 > 0)
                sub_404390(lpMultiByteStr, 0, arg3);
            
            goto label_40a16a;
        }
        
        if (!lpMultiByteStr)
            goto label_40a1bd;
        
        if (arg3 <= 0)
        {
        label_40a197:
            *__errno() = 0x22;
            sub_4041db(0, 0, 0, 0, 0);
            
            if (var_8)
                *(var_c + 0x70) &= 0xfffffffd;
            
            return 0x22;
        }
        
        *lpMultiByteStr = eax_3;
    label_40a1bd:
        
        if (arg1)
            *arg1 = 1;
    }
    
    if (!var_8)
        return 0;
    
    *(var_c + 0x70) &= 0xfffffffd;
    return 0;
}

int32_t sub_40a23d(int32_t* arg1, BOOL arg2, int32_t arg3, int32_t* arg4)
{
    int32_t var_4 = 0;
    return sub_40a0de(arg1, arg2, arg3, arg4);
}

uint32_t __stdcall __aulldvrm(int32_t arg1, uint32_t arg2, int32_t arg3, uint32_t arg4) __pure
{
    uint32_t result;
    
    if (arg4)
    {
        uint32_t i = arg4;
        int32_t ebx_1 = arg3;
        uint32_t edx_4 = arg2;
        int32_t eax_10 = arg1;
        
        do
        {
            ebx_1 = RRCD(ebx_1, 1, i & 1);
            uint32_t temp4_1 = edx_4;
            edx_4 u>>= 1;
            eax_10 = RRCD(eax_10, 1, temp4_1 & 1);
            i u>>= 1;
        } while (i);
        
        uint32_t result_1 = COMBINE(edx_4, eax_10) / ebx_1;
        result = result_1;
        int32_t eax_12 = result_1 * arg4;
        int32_t eax_9;
        int32_t edx_5;
        edx_5 = HIGHD(arg3 * result);
        eax_9 = LOWD(arg3 * result);
        int32_t edx_3 = edx_5 + eax_12;
        
        if (edx_5 + eax_12 < edx_5 || edx_3 > arg2)
            result -= 1;
        else if (edx_3 >= arg2 && eax_9 > arg1)
            result -= 1;
    }
    else
        result = COMBINE(COMBINE(0, arg2) % arg3, arg1) / arg3;
    
    return result;
}

void* sub_40a2f5(uint32_t arg1, uint32_t arg2, int32_t* arg3)
{
    int32_t __saved_ebp_1 = 0xc;
    int32_t var_8 = 0x40e838;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e838 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_30 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_30;
    void* const var_34_5 = &data_40a301;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    uint32_t temp0_1;
    
    if (arg1 > 0)
    {
        int32_t var_34 = 0xffffffe0;
        temp0_1 = COMBINE(0, 0xffffffe0) / arg1;
    }
    
    void* result;
    
    if (arg1 <= 0 || temp0_1 - temp0_1 != 0xffffffff)
    {
        uint32_t dwBytes = arg1 * arg2;
        arg1 = dwBytes;
        
        if (!dwBytes)
            dwBytes = 1;
        
        while (true)
        {
            void* result_1 = nullptr;
            int32_t var_20_1 = 0;
            
            if (dwBytes > 0xffffffe0)
                goto label_40a3bb;
            
            if (data_410d74 == 3)
            {
                dwBytes = (dwBytes + 0xf) & 0xfffffff0;
                arg2 = dwBytes;
                
                if (arg1 <= data_410d64)
                {
                    sub_402690(4);
                    int32_t var_8_1 = 0;
                    void* result_2 = sub_402edd(arg1);
                    int32_t var_8_2 = 0xfffffffe;
                    sub_40a3f1();
                    result_1 = result_2;
                    
                    if (!result_1)
                        goto label_40a3b9;
                    
                    sub_404390(result_1, 0, arg1);
                }
            }
            
            if (!result_1)
            {
            label_40a3b9:
                result_1 = HeapAlloc(data_4101b0, HEAP_ZERO_MEMORY, dwBytes);
            label_40a3bb:
                
                if (!result_1)
                {
                    if (data_410670)
                    {
                        if (sub_40510e(dwBytes))
                            continue;
                        
                        if (arg3)
                            *arg3 = 0xc;
                        
                        goto label_40a331;
                    }
                    else if (!result_1 && arg3)
                        *arg3 = 0xc;
                }
            }
            
            result = result_1;
            break;
        }
    }
    else
    {
        *__errno() = 0xc;
        sub_4041db(0, 0, 0, 0, 0);
    label_40a331:
        result = nullptr;
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_40a412;
    return result;
}

int32_t sub_40a3f1()
{
    return __unlock(4);
}

void* sub_40a413(void* arg1, uint32_t arg2)
{
    int32_t __saved_ebp_1 = 0x10;
    int32_t var_8 = 0x40e858;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e858 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_34 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_34;
    void* const var_38_15 = &data_40a41f;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    void* result;
    
    if (arg1)
    {
        uint32_t dwBytes = arg2;
        
        if (dwBytes)
        {
            void* eax_10;
            void* result_1;
            void* eax_7;
            
            if (data_410d74 != 3)
            {
                while (true)
                {
                    if (dwBytes > 0xffffffe0)
                    {
                    label_40a5ed:
                        sub_40510e(dwBytes);
                        eax_7 = __errno();
                    label_40a5f8:
                        *eax_7 = 0xc;
                        goto label_40a5fe;
                    }
                    
                    if (!dwBytes)
                        dwBytes += 1;
                    
                    void* result_3 = HeapReAlloc(data_4101b0, HEAP_NONE, arg1, dwBytes);
                    result_1 = result_3;
                    
                    if (result_1)
                        goto label_40a62a;
                    
                    if (data_410670 == result_3)
                    {
                        if (result_1)
                            goto label_40a62a;
                        
                        eax_10 = __errno();
                        break;
                    }
                    
                    if (!sub_40510e(dwBytes))
                    {
                        eax_7 = __errno();
                    label_40a59b:
                        *eax_7 = sub_4023e6(GetLastError());
                        goto label_40a5fe;
                    }
                }
            }
            else
            {
                while (true)
                {
                    void* result_2 = nullptr;
                    
                    if (dwBytes > 0xffffffe0)
                        goto label_40a5ed;
                    
                    sub_402690(4);
                    int32_t var_8_1 = 0;
                    void* eax = sub_402709(arg1);
                    void* var_24_1 = eax;
                    
                    if (eax)
                    {
                        if (dwBytes <= data_410d64)
                        {
                            if (!sub_402bfe(eax, arg1, dwBytes))
                            {
                                void* result_4 = sub_402edd(dwBytes);
                                result_2 = result_4;
                                
                                if (result_4)
                                {
                                    uint32_t dwBytes_1 = *(arg1 - 4) - 1;
                                    
                                    if (dwBytes_1 >= dwBytes)
                                        dwBytes_1 = dwBytes;
                                    
                                    sub_403d70(result_2, arg1, dwBytes_1);
                                    void* eax_3 = sub_402709(arg1);
                                    var_24_1 = eax_3;
                                    sub_402734(eax_3, arg1);
                                }
                            }
                            else
                                result_2 = arg1;
                        }
                        
                        if (!result_2)
                        {
                            if (!dwBytes)
                            {
                                dwBytes = 1;
                                arg2 = 1;
                            }
                            
                            dwBytes = (dwBytes + 0xf) & 0xfffffff0;
                            arg2 = dwBytes;
                            void* result_5 = HeapAlloc(data_4101b0, HEAP_NONE, dwBytes);
                            result_2 = result_5;
                            
                            if (result_5)
                            {
                                uint32_t dwBytes_2 = *(arg1 - 4) - 1;
                                
                                if (dwBytes_2 >= dwBytes)
                                    dwBytes_2 = dwBytes;
                                
                                sub_403d70(result_2, arg1, dwBytes_2);
                                sub_402734(var_24_1, arg1);
                            }
                        }
                    }
                    
                    int32_t var_8_2 = 0xfffffffe;
                    sub_40a557();
                    
                    if (var_24_1)
                        result_1 = result_2;
                    else
                    {
                        if (!dwBytes)
                            dwBytes += 1;
                        
                        dwBytes = (dwBytes + 0xf) & 0xfffffff0;
                        arg2 = dwBytes;
                        result_1 = HeapReAlloc(data_4101b0, HEAP_NONE, arg1, dwBytes);
                    }
                    
                    if (result_1)
                        goto label_40a62a;
                    
                    if (data_410670 == result_1)
                    {
                        if (result_1)
                            goto label_40a62a;
                        
                        eax_10 = __errno();
                        
                        if (var_24_1 == result_1)
                            break;
                        
                        *eax_10 = 0xc;
                        goto label_40a62a;
                    }
                    
                    if (!sub_40510e(dwBytes))
                    {
                        eax_7 = __errno();
                        
                        if (var_24_1 != result_1)
                            goto label_40a5f8;
                        
                        goto label_40a59b;
                    }
                }
            }
            *eax_10 = sub_4023e6(GetLastError());
        label_40a62a:
            result = result_1;
        }
        else
        {
            sub_40139b(arg1);
        label_40a5fe:
            result = nullptr;
        }
    }
    else
        result = sub_401986(arg2);
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_40a605;
    return result;
}

int32_t sub_40a557()
{
    return __unlock(4);
}

int32_t sub_40a62e(int32_t* arg1, char arg2, int32_t arg3, char arg4)
{
    void* var_14;
    sub_405aa0(&var_14, arg1);
    uint32_t eax = arg2;
    int32_t var_10;
    int32_t result;
    
    if (!(*(var_10 + eax + 0x1d) & arg4))
    {
        if (!arg3)
            result = 0;
        else
            result = *(*(var_14 + 0xc8) + (eax << 1)) & arg3;
    }
    
    if (*(var_10 + eax + 0x1d) & arg4 || result)
        result = 1;
    
    char var_8;
    void* var_c;
    
    if (var_8)
        *(var_c + 0x70) &= 0xfffffffd;
    return result;
}

int32_t sub_40a67f(char arg1)
{
    return sub_40a62e(nullptr, arg1, 0, 4);
}

void __convention("regparm") sub_40a692(int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4 @ ebp, int32_t arg5 @ esi, int32_t arg6 @ edi) __noreturn
{
    bool p = /* bool p = unimplemented  {sub esp, 0x328} */;
    bool a = /* bool a = unimplemented  {sub esp, 0x328} */;
    data_410930 = arg1;
    data_41092c = arg3;
    data_410928 = arg2;
    int32_t entry_ebx;
    data_410924 = entry_ebx;
    data_410920 = arg5;
    data_41091c = arg6;
    int16_t ss;
    data_410948 = ss;
    int16_t cs;
    data_41093c = cs;
    int16_t ds;
    data_410918 = ds;
    int16_t es;
    data_410914 = es;
    int16_t fs;
    data_410910 = fs;
    int16_t gs;
    data_41090c = gs;
    int32_t var_32c;
    int32_t var_4;
    bool d;
    int32_t var_330 = (&var_4 - 0x328 ? 1 : 0) << 0xb | (d ? 1 : 0) << 0xa
        | (&var_32c < 0 ? 1 : 0) << 7 | (&var_4 == 0x328 ? 1 : 0) << 6 | (a ? 1 : 0) << 4
        | (p ? 1 : 0) << 2 | (&var_4 < 0x328 ? 1 : 0);
    data_410940 = var_330;
    data_410934 = arg4;
    data_410938 = __return_addr;
    void arg_4;
    data_410944 = &arg_4;
    data_410880 = 0x10001;
    data_410834 = data_410938;
    data_410828 = 0xc0000409;
    data_41082c = 1;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_328 = data_40f84c;
    data_410878 = IsDebuggerPresent();
    sub_40828b();
    SetUnhandledExceptionFilter(0);
    UnhandledExceptionFilter(&data_40d9ac);
    
    if (!data_410878)
        sub_40828b();
    
    TerminateProcess(GetCurrentProcess(), 0xc0000409);
    /* no return */
}

int32_t sub_40a794(int32_t* arg1 @ ebp)
{
    *arg1;
}

HANDLE ___initconout()
{
    HANDLE result = CreateFileA("CONOUT$", 0x40000000, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, 
        OPEN_EXISTING, SECURITY_ANONYMOUS, nullptr);
    data_40ff54 = result;
    return result;
}

BOOL sub_40a7b5()
{
    HANDLE hObject_1 = data_40ff54;
    
    if (hObject_1 != 0xffffffff && hObject_1 != 0xfffffffe)
        CloseHandle(hObject_1);
    
    BOOL hObject = data_40ff50;
    
    if (hObject != 0xffffffff && hObject != 0xfffffffe)
        return CloseHandle(hObject);
    
    return hObject;
}

int32_t sub_40a7e2(int32_t arg1 @ esi, int32_t arg2 @ edi)
{
    int32_t var_4 = 0xc;
    int32_t var_8 = 0x40e878;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    int32_t ebp;
    var_4 = ebp;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_2 = 0x40e878 ^ __security_cookie_1;
    int32_t var_30 = __security_cookie_1 ^ &var_4;
    int32_t* var_1c = &var_30;
    void* const var_34 = &data_40a7ee;
    int32_t var_8_3 = 0xfffffffe;
    int32_t var_c = var_8_2;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t var_8_1 = 0;
    int32_t var_20 = 1;
    int32_t entry_ebx;
    /* tailcall */
    return sub_40a822(&var_4, arg2, arg1, entry_ebx);
}

int32_t sub_40a7ff(void* arg1 @ ebp)
{
    int32_t eax_1 = ***(arg1 - 0x14);
    
    if (eax_1 != 0xc0000005 && eax_1 != 0xc000001d)
        return 0;
    
    return 1;
}

int32_t sub_40a822(int32_t* arg1 @ ebp, int32_t arg2, int32_t arg3, int32_t arg4)
{
    arg1[-1] = 0xfffffffe;
    int32_t result = arg1[-7];
    TEB* fsbase;
    fsbase->NtTib.ExceptionList = arg1[-4];
    *arg1;
    *arg1 = &data_40a831;
    *arg1;
    return result;
}

int32_t __convention("regparm") sub_40a832(int32_t arg1)
{
    int32_t ebp;
    int32_t var_4 = ebp;
    int32_t* ebp_1 = &var_4;
    bool p = /* bool p = unimplemented  {xor eax, eax} */;
    bool a = /* undefined */;
    int32_t ebx;
    int32_t var_20 = ebx;
    int32_t var_8 = 0;
    int32_t var_10 = 0;
    int32_t var_c = 0;
    int32_t var_24 = ebx;
    bool d;
    int32_t var_28 = (d ? 1 : 0) << 0xa | (0 < 0 ? 1 : 0) << 7 | (arg1 == arg1 ? 1 : 0) << 6
        | (a ? 1 : 0) << 4 | (p ? 1 : 0) << 2;
    int32_t eax_1 = var_28 ^ 0x200000;
    int32_t var_28_2 = (TEST_BITD(eax_1, 0xb) ? 1 : 0) << 0xb
        | (TEST_BITD(eax_1, 0xa) ? 1 : 0) << 0xa | (TEST_BITD(eax_1, 7) ? 1 : 0) << 7
        | (TEST_BITD(eax_1, 6) ? 1 : 0) << 6 | (TEST_BITD(eax_1, 4) ? 1 : 0) << 4
        | (TEST_BITD(eax_1, 2) ? 1 : 0) << 2 | (TEST_BITD(eax_1, 0) ? 1 : 0);
    
    if (var_28_2 != var_28)
    {
        int32_t var_28_3 = var_28;
        int32_t eax_2;
        int32_t ecx_1;
        int32_t edx_2;
        int32_t ebx_1;
        eax_2 = __cpuid(0, var_28);
        int32_t var_10_1 = eax_2;
        int32_t var_1c_1 = ebx_1;
        int32_t var_18_1 = edx_2;
        int32_t var_14_1 = ecx_1;
        int32_t eax_3;
        int32_t ecx_2;
        int32_t edx_3;
        int32_t ebx_2;
        eax_3 = __cpuid(1, ecx_1);
        var_8 = edx_3;
        int32_t var_c_1 = eax_3;
    }
    
    int32_t result;
    
    if (!(var_8 & 0x4000000))
        result = 0;
    else
    {
        int32_t eax_4;
        int32_t esi;
        int32_t edi;
        eax_4 = sub_40a7e2(esi, edi);
        
        result = !eax_4 ? 0 : 1;
    }
    
    *ebp_1;
    return result;
}

int32_t sub_40a892()
{
    int32_t eax;
    data_410c20 = sub_40a832(eax);
    return 0;
}

uint32_t sub_40a89f(void* arg1)
{
    int32_t __saved_ebp_1 = 0x10;
    int32_t var_8 = 0x40e898;
    int32_t (* var_10)(int32_t* arg1, void* arg2, int32_t arg3) = sub_403220;
    TEB* fsbase;
    struct _EXCEPTION_REGISTRATION_RECORD* ExceptionList = fsbase->NtTib.ExceptionList;
    uint32_t __security_cookie_1 = __security_cookie;
    int32_t var_8_3 = 0x40e898 ^ __security_cookie_1;
    int32_t __saved_ebp;
    int32_t var_34 = __security_cookie_1 ^ &__saved_ebp;
    int32_t* var_1c = &var_34;
    void* const var_38_2 = &data_40a8ab;
    int32_t var_8_4 = 0xfffffffe;
    int32_t var_c = var_8_3;
    fsbase->NtTib.ExceptionList = &ExceptionList;
    int32_t eax;
    eax = arg1;
    uint32_t result;
    
    if (eax)
    {
        void* eax_2;
        uint32_t result_1;
        
        if (data_410d74 == 3)
        {
            sub_402690(4);
            int32_t var_8_1 = 0;
            eax_2 = sub_402709(arg1);
            uint32_t result_2;
            
            if (!eax_2)
                result_1 = result_2;
            else
            {
                result_1 = *(arg1 - 4) - 9;
                uint32_t result_3 = result_1;
            }
            int32_t var_8_2 = 0xfffffffe;
            sub_40a939();
        }
        
        if (data_410d74 != 3 || !eax_2)
            result_1 = HeapSize(data_4101b0, HEAP_NONE, arg1);
        
        result = result_1;
    }
    else
    {
        *__errno() = 0x16;
        sub_4041db(0, 0, 0, 0, 0);
        result = 0xffffffff;
    }
    
    fsbase->NtTib.ExceptionList = ExceptionList;
    void* const __saved_ebp_2 = &data_40a930;
    return result;
}

int32_t sub_40a939()
{
    return __unlock(4);
}

int32_t sub_40a942()
{
    return sub_404c23(2);
}

void sub_40a94b() __noreturn
{
    void var_2ac;
    int32_t var_8 = __security_cookie ^ &var_2ac;
    int32_t esi;
    int32_t var_330 = esi;
    
    if (data_40ff58 & 1)
        sub_404f2b(0xa);
    
    int32_t eax_2;
    int32_t ecx_2;
    int32_t edx;
    eax_2 = sub_408559();
    
    if (eax_2)
    {
        eax_2 = sub_408566(0x16);
        ecx_2 = 0x16;
    }
    
    char temp0 = data_40ff58;
    bool p = /* bool p = unimplemented  {test byte [&data_40ff58], 0x2} */;
    bool a = /* undefined */;
    bool z = !(temp0 & 2);
    
    if (!z)
    {
        int32_t var_224_1 = eax_2;
        int32_t var_228_1 = ecx_2;
        int32_t var_22c_1 = edx;
        int32_t ebx;
        int32_t var_230_1 = ebx;
        int32_t var_234_1 = esi;
        int32_t edi;
        int32_t var_238_1 = edi;
        int16_t ss;
        int16_t var_20c_1 = ss;
        int16_t cs;
        int16_t var_218_1 = cs;
        int16_t ds;
        int16_t var_23c_1 = ds;
        int16_t es;
        int16_t var_240_1 = es;
        int16_t fs;
        int16_t var_244_1 = fs;
        int16_t gs;
        int16_t var_248_1 = gs;
        bool d;
        int32_t var_214_1 = (d ? 1 : 0) << 0xa | ((temp0 & 2) < 0 ? 1 : 0) << 7 | (z ? 1 : 0) << 6
            | (a ? 1 : 0) << 4 | (p ? 1 : 0) << 2;
        int32_t var_2d4 = 0x10001;
        void* const __return_addr_2 = __return_addr;
        int32_t ebp;
        int32_t var_220_1 = ebp;
        int32_t var_32c;
        sub_404390(&var_32c, 0, 0x50);
        EXCEPTION_POINTERS ExceptionInfo;
        ExceptionInfo.ExceptionRecord = &var_32c;
        var_32c = 0x40000015;
        void* const __return_addr_1 = __return_addr;
        ExceptionInfo.ContextRecord = &var_2d4;
        SetUnhandledExceptionFilter(nullptr);
        UnhandledExceptionFilter(&ExceptionInfo);
    }
    
    sub_404eb0(3);
    breakpoint();
}

int32_t* sub_40aa3e(int32_t* arg1)
{
    int32_t* result = arg1;
    
    if (result)
    {
        result -= 8;
        
        if (*result == 0xdddd)
            result = sub_40139b(result);
    }
    
    return result;
}

int32_t sub_40aa59(int32_t arg1, int32_t arg2, int32_t arg3)
{
    int32_t var_10 = 0;
    int32_t eax;
    uint32_t eax_1;
    int32_t ecx;
    int32_t ecx_1;
    int32_t edx;
    int32_t edx_1;
    eax_1 = sub_4077ee(eax, edx, ecx, arg1, 0, 0, FILE_CURRENT);
    int32_t eax_2 = eax_1 & edx_1;
    
    if (eax_2 != 0xffffffff)
    {
        uint32_t eax_3;
        int32_t edx_2;
        eax_3 = sub_4077ee(eax_2, edx_1, ecx_1, arg1, 0, 0, FILE_END);
        int32_t ecx_3 = eax_3 & edx_2;
        
        if (ecx_3 != 0xffffffff)
        {
            int32_t esi_2 = arg2 - eax_3;
            bool c_1 = arg2 < eax_3;
            int32_t edi_2 = arg3 - edx_2;
            bool s_1 = arg3 - edx_2 < 0;
            bool o_1 = /* bool o_1 = unimplemented  {sbb edi, edx} */;
            int32_t esi_3;
            
            if (!s_1 && ((arg3 - edx_2 && s_1 == o_1) || esi_2 > 0))
            {
                uint8_t* lpMem = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 0x1000);
                
                if (lpMem)
                {
                    int32_t eax_8 = sub_40ac0d(arg1, 0x8000);
                    
                    while (true)
                    {
                        int32_t eax_9;
                        
                        eax_9 = edi_2 < 0 || (edi_2 <= 0 && esi_2 < 0x1000) ? esi_2 : 0x1000;
                        
                        void* eax_10 = sub_403516(arg1, lpMem, eax_9);
                        
                        if (eax_10 == 0xffffffff)
                        {
                            if (*___doserrno() == 5)
                                *__errno() = 0xd;
                            
                            esi_3 = 0xffffffff;
                            var_10 = 0xffffffff;
                            break;
                        }
                        
                        int32_t eax_11;
                        int32_t edx_3;
                        edx_3 = HIGHD(eax_10);
                        eax_11 = LOWD(eax_10);
                        int32_t temp4_1 = esi_2;
                        esi_2 -= eax_11;
                        bool c_2 = temp4_1 < eax_11;
                        int32_t temp5_1 = edi_2;
                        edi_2 = temp5_1 - edx_3;
                        bool s_2 = temp5_1 - edx_3 < 0;
                        bool o_2 = /* bool o_2 = unimplemented  {sbb edi, edx} */;
                        
                        if (!s_2)
                        {
                            if (temp5_1 - edx_3 && s_2 == o_2)
                                continue;
                            else if (esi_2 > 0)
                                continue;
                        }
                        
                        esi_3 = 0;
                        break;
                    }
                    
                    sub_40ac0d(arg1, eax_8);
                    eax_3 = HeapFree(GetProcessHeap(), HEAP_NONE, lpMem);
                    goto label_40abe0;
                }
                
                *__errno() = 0xc;
            }
            else if (edi_2 > 0 || (edi_2 >= 0 && esi_2 >= 0))
            {
            label_40abf3:
                uint32_t eax_26;
                int32_t edx_5;
                eax_26 = sub_4077ee(eax_3, edx_2, ecx_3, arg1, eax_1, edx_1, FILE_BEGIN);
                
                if ((eax_26 & edx_5) != 0xffffffff)
                    return 0;
            }
            else
            {
                uint32_t eax_15;
                int32_t edx_4;
                eax_15 = sub_4077ee(eax_3, edx_2, ecx_3, arg1, arg2, arg3, FILE_BEGIN);
                
                if ((eax_15 & edx_4) != 0xffffffff)
                {
                    BOOL eax_18;
                    eax_18 = SetEndOfFile(sub_407d5a(arg1));
                    int32_t eax_19 = -(eax_18);
                    int32_t eax_23;
                    edx_2 = HIGHD(-((eax_19 - eax_19)) - 1);
                    eax_23 = LOWD(-((eax_19 - eax_19)) - 1);
                    eax_3 = eax_23 & edx_2;
                    var_10 = edx_2;
                    
                    if (eax_3 != 0xffffffff)
                        goto label_40abf3;
                    
                    *__errno() = 0xd;
                    uint32_t* eax_25 = ___doserrno();
                    eax_3 = GetLastError();
                    *eax_25 = eax_3;
                    esi_3 = eax_23;
                label_40abe0:
                    
                    if ((esi_3 & var_10) != 0xffffffff)
                        goto label_40abf3;
                }
            }
        }
    }
    
    return *__errno();
}

int32_t sub_40ac0d(int32_t arg1, int32_t arg2)
{
    int32_t edx_2 = (arg1 & 0x1f) * 0x28;
    void* esi = &(&data_410c40)[arg1 >> 5];
    void* ecx = *esi + edx_2;
    arg1 = *(ecx + 4) & 0x80;
    int32_t eax_4;
    eax_4 = *(ecx + 0x24);
    eax_4 *= 2;
    int32_t eax_6 = eax_4 >> 1;
    
    if (arg2 == 0x4000)
    {
        *(ecx + 4) |= 0x80;
        char* ecx_5 = *esi + edx_2 + 0x24;
        *ecx_5 &= 0x80;
    }
    else if (arg2 == 0x8000)
        *(ecx + 4) &= 0x7f;
    else
    {
        char* ecx_2;
        
        if (arg2 == 0x10000 || arg2 == 0x20000)
        {
            *(ecx + 4) |= 0x80;
            ecx_2 = *esi + edx_2 + 0x24;
            edx_2 = *ecx_2;
            edx_2 &= 0x82;
            edx_2 |= 2;
            *ecx_2 = edx_2;
        }
        else if (arg2 == 0x40000)
        {
            *(ecx + 4) |= 0x80;
            ecx_2 = *esi + edx_2 + 0x24;
            edx_2 = *ecx_2;
            edx_2 &= 0x81;
            edx_2 |= 1;
            *ecx_2 = edx_2;
        }
    }
    
    if (!arg1)
        return 0x8000;
    
    int32_t eax_8 = -(eax_6);
    return ((eax_8 - eax_8) & 0xc000) + 0x4000;
}

int32_t sub_40acc9(int32_t* arg1)
{
    if (arg1)
    {
        *arg1 = data_410b58;
        return 0;
    }
    
    *__errno() = 0x16;
    sub_4041db(0, 0, 0, 0, 0);
    return 0x16;
}

int32_t __convention("regparm") sub_40acfd(int32_t arg1, int32_t arg2, int32_t* arg3, uint32_t arg4, uint32_t arg5, char* arg6, PSTR arg7, int32_t arg8, uint32_t arg9, int32_t arg10)
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    bool cond:0 = data_410b4c;
    int32_t edi;
    int32_t var_24 = edi;
    
    if (!cond:0)
    {
        if (!LCMapStringW(0, 0x100, &data_40d9bc, 1, nullptr, 0))
        {
            if (GetLastError() == ERROR_CALL_NOT_IMPLEMENTED)
                data_410b4c = 2;
        }
        else
            data_410b4c = 1;
    }
    
    int32_t arg_10;
    
    if (arg_10 > 0)
    {
        int32_t ecx = arg_10;
        char* eax_4 = arg6;
        
        while (true)
        {
            ecx -= 1;
            
            if (!*eax_4)
                break;
            
            eax_4 = &eax_4[1];
            
            if (!ecx)
            {
                ecx = 0xffffffff;
                break;
            }
        }
        
        int32_t eax_7 = arg_10 - ecx - 1;
        
        if (eax_7 < arg_10)
            eax_7 += 1;
        
        arg_10 = eax_7;
    }
    
    int32_t eax_8 = data_410b4c;
    int32_t result;
    int32_t __saved_ebx;
    int32_t result_1;
    
    if (eax_8 == 2 || !eax_8)
    {
        uint8_t* lpSrcStr = nullptr;
        void* var_14_1 = nullptr;
        
        if (!arg4)
            arg4 = *(*arg3 + 0x14);
        
        if (!arg9)
            arg9 = *(*arg3 + 4);
        
        uint32_t eax_29 = sub_40bb5c(arg4);
        
        if (eax_29 == 0xffffffff)
            result = 0;
        else
        {
            int32_t result_2;
            
            if (eax_29 == arg9)
            {
                result_2 = LCMapStringA(arg4, arg5, arg6, arg_10, arg7, arg8);
            label_40b06d:
                
                if (lpSrcStr)
                    sub_40139b(lpSrcStr);
                
                if (var_14_1 && arg7 != var_14_1)
                    sub_40139b(var_14_1);
                
                result = result_2;
            }
            else
            {
                uint8_t* lpSrcStr_1 = sub_40bba3(arg9, eax_29, arg6, &arg_10, nullptr, 0);
                lpSrcStr = lpSrcStr_1;
                
                if (lpSrcStr_1)
                {
                    int32_t result_4 = LCMapStringA(arg4, arg5, lpSrcStr_1, arg_10, nullptr, 0);
                    result_1 = result_4;
                    
                    if (!result_4)
                        result_2 = 0;
                    else
                    {
                        PSTR lpDestStr;
                        
                        if (result_4 <= 0 || result_4 > 0xffffffe0)
                        {
                            lpDestStr = nullptr;
                        label_40aff4:
                            
                            if (!lpDestStr)
                                result_2 = 0;
                            else
                            {
                                sub_404390(lpDestStr, 0, result_1);
                                int32_t result_5 =
                                    LCMapStringA(arg4, arg5, lpSrcStr, arg_10, lpDestStr, result_1);
                                result_1 = result_5;
                                
                                if (result_5)
                                {
                                    PSTR eax_31 =
                                        sub_40bba3(eax_29, arg9, lpDestStr, &result_1, arg7, arg8);
                                    var_14_1 = eax_31;
                                    int32_t esi_3 = -(eax_31);
                                    result_2 = (esi_3 - esi_3) & result_1;
                                }
                                else
                                    result_2 = 0;
                                
                                sub_40aa3e(lpDestStr);
                            }
                        }
                        else
                        {
                            if (result_4 + 8 > 0x400)
                            {
                                PSTR lpDestStr_1 = sub_401986(result_4 + 8);
                                
                                if (lpDestStr_1)
                                {
                                    *lpDestStr_1 = 0xdddd;
                                    lpDestStr_1 = &lpDestStr_1[8];
                                }
                                
                                lpDestStr = lpDestStr_1;
                                goto label_40aff4;
                            }
                            
                            __alloca_probe_16(result_4 + 8);
                            
                            if (&var_24)
                            {
                                var_24 = 0xcccc;
                                lpDestStr = &__saved_ebx;
                                goto label_40aff4;
                            }
                            
                            result_2 = 0;
                        }
                    }
                    
                    goto label_40b06d;
                }
                
                result = 0;
            }
        }
    }
    else if (eax_8 != 1)
        result = 0;
    else
    {
        result_1 = 0;
        
        if (!arg9)
            arg9 = *(*arg3 + 4);
        
        int32_t eax_11;
        eax_11 = arg10;
        int32_t eax_13 = MultiByteToWideChar(arg9, (eax_11 << 3) + 1, arg6, arg_10, nullptr, 0);
        
        if (!eax_13)
            result = 0;
        else
        {
            int32_t* var_10_1;
            
            if (eax_13 <= 0 || COMBINE(0, 0xffffffe0) / eax_13 < 2)
                var_10_1 = nullptr;
            else
            {
                int32_t* eax_17;
                
                if (eax_13 * 2 + 8 > 0x400)
                {
                    eax_17 = sub_401986(eax_13 * 2 + 8);
                    
                    if (eax_17)
                    {
                        *eax_17 = 0xdddd;
                        eax_17 = &eax_17[2];
                    }
                }
                else
                {
                    __alloca_probe_16(eax_13 * 2 + 8);
                    eax_17 = &var_24;
                    
                    if (&var_24)
                    {
                        var_24 = 0xcccc;
                        eax_17 = &eax_17[2];
                    }
                }
                
                var_10_1 = eax_17;
            }
            
            if (!var_10_1)
                result = 0;
            else
            {
                if (MultiByteToWideChar(arg9, MB_PRECOMPOSED, arg6, arg_10, var_10_1, eax_13))
                {
                    int32_t result_3 = LCMapStringW(arg4, arg5, var_10_1, eax_13, nullptr, 0);
                    result_1 = result_3;
                    
                    if (result_3)
                    {
                        if (!(arg5 & 0x400))
                        {
                            int32_t* esi_1;
                            
                            if (result_3 <= 0 || COMBINE(0, 0xffffffe0) / result_3 < 2)
                            {
                                esi_1 = nullptr;
                            label_40aede:
                                
                                if (esi_1)
                                {
                                    if (LCMapStringW(arg4, arg5, var_10_1, eax_13, esi_1, result_1))
                                    {
                                        PSTR lpMultiByteStr;
                                        int32_t cbMultiByte;
                                        
                                        if (arg8)
                                        {
                                            cbMultiByte = arg8;
                                            lpMultiByteStr = arg7;
                                        }
                                        else
                                        {
                                            cbMultiByte = 0;
                                            lpMultiByteStr = nullptr;
                                        }
                                        
                                        result_1 = WideCharToMultiByte(arg9, 0, esi_1, result_1, 
                                            lpMultiByteStr, cbMultiByte, nullptr, nullptr);
                                    }
                                    
                                    sub_40aa3e(esi_1);
                                }
                            }
                            else
                            {
                                if (result_3 * 2 + 8 > 0x400)
                                {
                                    int32_t* eax_22 = sub_401986(result_3 * 2 + 8);
                                    
                                    if (eax_22)
                                    {
                                        *eax_22 = 0xdddd;
                                        eax_22 = &eax_22[2];
                                    }
                                    
                                    esi_1 = eax_22;
                                    goto label_40aede;
                                }
                                
                                __alloca_probe_16(result_3 * 2 + 8);
                                
                                if (&var_24)
                                {
                                    var_24 = 0xcccc;
                                    esi_1 = &__saved_ebx;
                                    goto label_40aede;
                                }
                            }
                        }
                        else if (arg8 && result_3 <= arg8)
                            LCMapStringW(arg4, arg5, var_10_1, eax_13, arg7, arg8);
                    }
                }
                
                sub_40aa3e(var_10_1);
                result = result_1;
            }
        }
    }
    sub_4076f5(eax_1 ^ &__saved_ebp);
    return result;
}

int32_t sub_40b09f(int32_t* arg1, uint32_t arg2, uint32_t arg3, char* arg4, PSTR arg5, int32_t arg6, uint32_t arg7, int32_t arg8, int32_t arg9)
{
    void var_14;
    int32_t* eax;
    int32_t edx;
    eax = sub_405aa0(&var_14, arg1);
    int32_t var_18_1 = arg9;
    int32_t result = sub_40acfd(eax, edx, &var_14, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    char var_8;
    void* var_c;
    
    if (var_8)
        *(var_c + 0x70) &= 0xfffffffd;
    return result;
}

uint32_t sub_40b0e2(char* arg1, char* arg2)
{
    char* edx = arg2;
    char* esi = arg1;
    uint32_t eax_1;
    uint32_t ecx_2;
    
    do
    {
        eax_1 = *esi;
        esi = &esi[1];
        
        if (eax_1 - 0x41 <= 0x19)
            eax_1 += 0x20;
        
        ecx_2 = *edx;
        edx = &edx[1];
        
        if (ecx_2 - 0x41 <= 0x19)
            ecx_2 += 0x20;
        
        if (!eax_1)
            break;
    } while (eax_1 == ecx_2);
    
    return eax_1 - ecx_2;
}

uint32_t sub_40b117(char* arg1, char* arg2, int32_t* arg3)
{
    void* var_14;
    sub_405aa0(&var_14, arg3);
    void* var_c;
    char var_8;
    
    if (!arg1)
    {
        *__errno() = 0x16;
        sub_4041db(0, 0, 0, 0, 0);
        
        if (var_8)
            *(var_c + 0x70) &= 0xfffffffd;
        
        return 0x7fffffff;
    }
    
    char* edi_1 = arg2;
    
    if (!edi_1)
    {
        *__errno() = 0x16;
        sub_4041db(0, 0, 0, 0, 0);
        
        if (var_8)
            *(var_c + 0x70) &= 0xfffffffd;
        
        return 0x7fffffff;
    }
    
    uint32_t result;
    
    if (*(var_14 + 0x14))
    {
        uint32_t eax_7;
        uint32_t eax_9;
        
        do
        {
            eax_7 = sub_40bd55(*arg1, &var_14);
            arg1 = &arg1[1];
            eax_9 = sub_40bd55(*edi_1, &var_14);
            edi_1 = &edi_1[1];
            
            if (!eax_7)
                break;
        } while (eax_7 == eax_9);
        
        result = eax_7 - eax_9;
    }
    else
        result = sub_40b0e2(arg1, edi_1);
    
    if (var_8)
        *(var_c + 0x70) &= 0xfffffffd;
    
    return result;
}

uint32_t sub_40b1ea(char* arg1, char* arg2, int32_t arg3)
{
    int32_t ecx;
    int32_t var_8 = ecx;
    int32_t var_8_1 = 0;
    
    if (!arg3)
        return 0;
    
    char* eax_1;
    char* ecx_1;
    char edx;
    
    if (arg3 < 4 || arg3 - 4 <= 0)
    {
        ecx_1 = arg2;
        eax_1 = arg1;
    }
    else
    {
        ecx_1 = arg2;
        eax_1 = arg1;
        
        while (true)
        {
            edx = *eax_1;
            eax_1 = &eax_1[4];
            ecx_1 = &ecx_1[4];
            
            if (!edx || edx != ecx_1[0xfffffffc])
                return eax_1[0xfffffffc] - ecx_1[0xfffffffc];
            
            edx = eax_1[0xfffffffd];
            
            if (!edx || edx != ecx_1[0xfffffffd])
                return eax_1[0xfffffffd] - ecx_1[0xfffffffd];
            
            edx = eax_1[0xfffffffe];
            
            if (!edx || edx != ecx_1[0xfffffffe])
                return eax_1[0xfffffffe] - ecx_1[0xfffffffe];
            
            edx = eax_1[0xffffffff];
            
            if (!edx || edx != ecx_1[0xffffffff])
                return eax_1[0xffffffff] - ecx_1[0xffffffff];
            
            var_8_1 += 4;
            
            if (var_8_1 >= arg3 - 4)
                break;
            
            continue;
        }
    }
    
    while (true)
    {
        if (var_8_1 >= arg3)
            return 0;
        
        edx = *eax_1;
        
        if (!edx)
            break;
        
        if (edx != *ecx_1)
            break;
        
        eax_1 = &eax_1[1];
        ecx_1 = &ecx_1[1];
        var_8_1 += 1;
    }
    
    return *eax_1 - *ecx_1;
}

int32_t* __convention("regparm") sub_40b2a8(int32_t arg1, int32_t arg2, int32_t* arg3, uint32_t arg4, uint8_t* arg5, uint16_t* arg6, uint32_t arg7, uint32_t arg8, int32_t arg9)
{
    int32_t* var_8 = arg3;
    int32_t* charType = arg3;
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    int32_t eax_2 = data_410b50;
    int32_t* ebx = nullptr;
    int32_t edi;
    int32_t var_18 = edi;
    int32_t* result;
    int32_t arg_c;
    
    if (eax_2)
    {
    label_40b301:
        
        if (eax_2 == 2 || !eax_2)
        {
            PSTR esi_1 = nullptr;
            
            if (!arg8)
                arg8 = *(*arg3 + 0x14);
            
            if (!arg7)
                arg7 = *(*arg3 + 4);
            
            int32_t eax_17 = sub_40bb5c(arg8);
            
            if (eax_17 != 0xffffffff)
            {
                if (eax_17 == arg7)
                    goto label_40b439;
                
                esi_1 = sub_40bba3(arg7, eax_17, arg5, &arg_c, nullptr, 0);
                
                if (!esi_1)
                    result = nullptr;
                else
                {
                    arg5 = esi_1;
                label_40b439:
                    BOOL result_1 = GetStringTypeA(arg8, arg4, arg5, arg_c, arg6);
                    
                    if (esi_1)
                        sub_40139b(esi_1);
                    
                    result = result_1;
                }
            }
            else
                result = nullptr;
        }
        else
        {
            if (eax_2 == 1)
                goto label_40b31e;
            
            result = nullptr;
        }
    }
    else
    {
        if (!GetStringTypeW(1, &data_40d9bc, 1, &charType))
        {
            if (GetLastError() != ERROR_CALL_NOT_IMPLEMENTED)
                eax_2 = data_410b50;
            else
            {
                eax_2 = 2;
                data_410b50 = 2;
            }
            
            goto label_40b301;
        }
        
        data_410b50 = 1;
    label_40b31e:
        charType = nullptr;
        
        if (!arg7)
            arg7 = *(*arg3 + 4);
        
        int32_t eax_7;
        eax_7 = arg9;
        int32_t cchWideChar = MultiByteToWideChar(arg7, (eax_7 << 3) + 1, arg5, arg_c, nullptr, 0);
        
        if (!cchWideChar)
            result = nullptr;
        else
        {
            if (cchWideChar > 0 && cchWideChar <= 0x7ffffff0)
            {
                int32_t* eax_10;
                
                if (cchWideChar * 2 + 8 > 0x400)
                {
                    eax_10 = sub_401986(cchWideChar * 2 + 8);
                    
                    if (eax_10)
                    {
                        *eax_10 = 0xdddd;
                        eax_10 = &eax_10[2];
                    }
                }
                else
                {
                    __alloca_probe_16(cchWideChar * 2 + 8);
                    eax_10 = &var_18;
                    
                    if (&var_18)
                    {
                        var_18 = 0xcccc;
                        eax_10 = &eax_10[2];
                    }
                }
                
                ebx = eax_10;
            }
            
            if (!ebx)
                result = nullptr;
            else
            {
                sub_404390(ebx, 0, cchWideChar * 2);
                int32_t cchSrc =
                    MultiByteToWideChar(arg7, MB_PRECOMPOSED, arg5, arg_c, ebx, cchWideChar);
                
                if (cchSrc)
                    charType = GetStringTypeW(arg4, ebx, cchSrc, arg6);
                
                sub_40aa3e(ebx);
                result = charType;
            }
        }
    }
    sub_4076f5(eax_1 ^ &__saved_ebp);
    return result;
}

int32_t* sub_40b460(int32_t* arg1, uint32_t arg2, uint8_t* arg3, uint16_t* arg4, uint32_t arg5, uint32_t arg6, int32_t arg7, int32_t arg8)
{
    void var_14;
    int32_t* eax;
    int32_t edx;
    eax = sub_405aa0(&var_14, arg1);
    int32_t var_18_1 = arg8;
    int32_t* result = sub_40b2a8(eax, edx, &var_14, arg2, arg3, arg4, arg5, arg6, arg7);
    char var_8;
    void* var_c;
    
    if (var_8)
        *(var_c + 0x70) &= 0xfffffffd;
    return result;
}

void sub_40b4a0(int32_t* arg1)
{
    if (!arg1)
        return;
    
    sub_40139b(arg1[1]);
    sub_40139b(arg1[2]);
    sub_40139b(arg1[3]);
    sub_40139b(arg1[4]);
    sub_40139b(arg1[5]);
    sub_40139b(arg1[6]);
    sub_40139b(*arg1);
    sub_40139b(arg1[8]);
    sub_40139b(arg1[9]);
    sub_40139b(arg1[0xa]);
    sub_40139b(arg1[0xb]);
    sub_40139b(arg1[0xc]);
    sub_40139b(arg1[0xd]);
    sub_40139b(arg1[7]);
    sub_40139b(arg1[0xe]);
    sub_40139b(arg1[0xf]);
    sub_40139b(arg1[0x10]);
    sub_40139b(arg1[0x11]);
    sub_40139b(arg1[0x12]);
    sub_40139b(arg1[0x13]);
    sub_40139b(arg1[0x14]);
    sub_40139b(arg1[0x15]);
    sub_40139b(arg1[0x16]);
    sub_40139b(arg1[0x17]);
    sub_40139b(arg1[0x18]);
    sub_40139b(arg1[0x19]);
    sub_40139b(arg1[0x1a]);
    sub_40139b(arg1[0x1b]);
    sub_40139b(arg1[0x1c]);
    sub_40139b(arg1[0x1d]);
    sub_40139b(arg1[0x1e]);
    sub_40139b(arg1[0x1f]);
    sub_40139b(arg1[0x20]);
    sub_40139b(arg1[0x21]);
    sub_40139b(arg1[0x22]);
    sub_40139b(arg1[0x23]);
    sub_40139b(arg1[0x24]);
    sub_40139b(arg1[0x25]);
    sub_40139b(arg1[0x26]);
    sub_40139b(arg1[0x27]);
    sub_40139b(arg1[0x28]);
    sub_40139b(arg1[0x29]);
    sub_40139b(arg1[0x2a]);
}

void sub_40b630(int32_t* arg1)
{
    if (!arg1)
        return;
    
    void* eax_1 = *arg1;
    
    if (eax_1 != data_410028)
        sub_40139b(eax_1);
    
    struct _EXCEPTION_REGISTRATION_RECORD** eax = arg1[1];
    
    if (eax != data_41002c)
        sub_40139b(eax);
    
    void* esi_1 = arg1[2];
    
    if (esi_1 != data_410030)
        sub_40139b(esi_1);
}

void sub_40b670(void* arg1)
{
    if (!arg1)
        return;
    
    void* eax_1 = *(arg1 + 0xc);
    
    if (eax_1 != data_410034)
        sub_40139b(eax_1);
    
    void* eax_2 = *(arg1 + 0x10);
    
    if (eax_2 != data_410038)
        sub_40139b(eax_2);
    
    void* eax_3 = *(arg1 + 0x14);
    
    if (eax_3 != data_41003c)
        sub_40139b(eax_3);
    
    void* eax_4 = *(arg1 + 0x18);
    
    if (eax_4 != data_410040)
        sub_40139b(eax_4);
    
    void* eax_5 = *(arg1 + 0x1c);
    
    if (eax_5 != data_410044)
        sub_40139b(eax_5);
    
    struct _EXCEPTION_REGISTRATION_RECORD** eax = *(arg1 + 0x20);
    
    if (eax != data_410048)
        sub_40139b(eax);
    
    void* esi_1 = *(arg1 + 0x24);
    
    if (esi_1 != data_41004c)
        sub_40139b(esi_1);
}

int32_t _strcspn(char* arg1, char* arg2)
{
    int32_t var_28_1;
    __builtin_memset(&var_28_1, 0, 0x20);
    char* edx = arg2;
    int32_t eax;
    
    while (true)
    {
        eax = *edx;
        eax = eax;
        
        if (!eax)
            break;
        
        edx = &edx[1];
        var_28_1 |= 1 << (eax % 0x20);
    }
    
    char* esi = arg1;
    int32_t result = 0xffffffff;
    
    do
    {
        result += 1;
        eax = *esi;
        eax = eax;
        
        if (!eax)
            break;
        
        esi = &esi[1];
    } while (!TEST_BITD(var_28_1, eax));
    
    return result;
}

int32_t sub_40b750(int32_t* arg1, char* arg2)
{
    int32_t* edx = arg1;
    char* ecx = arg2;
    uint32_t eax;
    
    if (edx & 3)
    {
        if (!(edx & 1))
        {
        label_40b7bc:
            eax = *edx;
            edx += 2;
            char temp1_1 = *ecx;
            
            if (eax != temp1_1)
                return ((eax - eax) << 1) + 1;
            
            eax = eax;
            
            if (!eax)
                return 0;
            
            char temp4_1 = ecx[1];
            
            if (*eax[1] != temp4_1)
                return ((eax - eax) << 1) + 1;
            
            *eax[1] = *eax[1];
            
            if (!*eax[1])
                return 0;
            
            ecx = &ecx[2];
        }
        else
        {
            eax = *edx;
            edx += 1;
            char temp2_1 = *ecx;
            
            if (eax != temp2_1)
                return ((eax - eax) << 1) + 1;
            
            ecx = &ecx[1];
            eax = eax;
            
            if (!eax)
                return 0;
            
            if (edx & 2)
                goto label_40b7bc;
        }
    }
    
    while (true)
    {
        eax = *edx;
        char temp0_1 = *ecx;
        
        if (eax != temp0_1)
            return ((eax - eax) << 1) + 1;
        
        eax = eax;
        
        if (!eax)
            return 0;
        
        char temp3_1 = ecx[1];
        
        if (*eax[1] != temp3_1)
            return ((eax - eax) << 1) + 1;
        
        *eax[1] = *eax[1];
        
        if (!*eax[1])
            return 0;
        
        eax u>>= 0x10;
        char temp5_1 = ecx[2];
        
        if (eax != temp5_1)
            return ((eax - eax) << 1) + 1;
        
        eax = eax;
        
        if (!eax)
            return 0;
        
        char temp6_1 = ecx[3];
        
        if (*eax[1] != temp6_1)
            return ((eax - eax) << 1) + 1;
        
        ecx = &ecx[4];
        edx = &edx[1];
        *eax[1] = *eax[1];
        
        if (!*eax[1])
            return 0;
    }
}

void* _strpbrk(char* arg1, char* arg2)
{
    int32_t var_28_1;
    __builtin_memset(&var_28_1, 0, 0x20);
    char* edx = arg2;
    void* result;
    
    while (true)
    {
        result = *edx;
        result = result;
        
        if (!result)
            break;
        
        edx = &edx[1];
        var_28_1 |= 1 << (result % 0x20);
    }
    
    char* esi = arg1;
    
    do
    {
        result = *esi;
        result = result;
        
        if (!result)
            return result;
        
        esi = &esi[1];
    } while (!TEST_BITD(var_28_1, result));
    
    return &esi[0xffffffff];
}

int32_t sub_40b820(int32_t* arg1, void* arg2, int32_t* arg3, int32_t arg4, int32_t arg5)
{
    void* var_18;
    sub_405aa0(&var_18, arg1);
    char* esi = arg2;
    
    if (arg3)
        *arg3 = esi;
    
    void* var_10;
    char var_c;
    
    if (esi)
    {
        if (!arg4)
        {
        label_40b882:
            void* ecx_1 = var_18;
            int32_t ebx;
            ebx = *esi;
            int32_t result = 0;
            void* edi_1 = &esi[1];
            
            while (true)
            {
                int32_t eax_4;
                
                if (*(ecx_1 + 0xac) <= 1)
                    eax_4 = *(*(ecx_1 + 0xc8) + (ebx << 1)) & 8;
                else
                {
                    eax_4 = sub_40ba74(ebx, 8, &var_18);
                    ecx_1 = var_18;
                }
                
                if (!eax_4)
                    break;
                
                ebx = *edi_1;
                edi_1 += 1;
            }
            
            if (ebx == 0x2d)
            {
                arg5 |= 2;
                ebx = *edi_1;
                edi_1 += 1;
            }
            else if (ebx == 0x2b)
            {
                ebx = *edi_1;
                edi_1 += 1;
            }
            
            if (arg4 < 0 || arg4 == 1 || arg4 > 0x24)
            {
                if (arg3)
                    *arg3 = esi;
                
                if (var_c)
                    *(var_10 + 0x70) &= 0xfffffffd;
                
                return 0;
            }
            
            if (arg4)
            {
                if (arg4 == 0x10 && ebx == 0x30)
                    goto label_40b92f;
            }
            else if (ebx == 0x30)
            {
                int32_t eax_7;
                eax_7 = *edi_1;
                
                if (eax_7 == 0x78 || eax_7 == 0x58)
                {
                    arg4 = 0x10;
                label_40b92f:
                    eax_7 = *edi_1;
                    
                    if (eax_7 == 0x78 || eax_7 == 0x58)
                    {
                        ebx = *(edi_1 + 1);
                        edi_1 += 2;
                    }
                }
                else
                    arg4 = 8;
            }
            else
                arg4 = 0xa;
            
            int32_t eax_8 = 0xffffffff;
            int32_t edx_2 = 0;
            uint32_t temp0_1 = COMBINE(edx_2, eax_8) / arg4;
            
            while (true)
            {
                int16_t ecx_3 = *(*(ecx_1 + 0xc8) + (ebx << 1));
                int32_t ecx_5;
                
                if (!(ecx_3 & 4))
                {
                    if (!(ecx_3 & 0x103))
                        break;
                    
                    ecx_3 = ebx;
                    ecx_3 -= 0x61;
                    int32_t ecx_6 = ebx;
                    
                    if (ecx_3 <= 0x19)
                        ecx_6 -= 0x20;
                    
                    ecx_5 = ecx_6 - 0x37;
                }
                else
                    ecx_5 = ebx - 0x30;
                
                if (ecx_5 >= arg4)
                    break;
                
                arg5 |= 8;
                
                if (result < temp0_1
                        || (result == temp0_1 && ecx_5 <= COMBINE(edx_2, eax_8) % arg4))
                    result = result * arg4 + ecx_5;
                else
                {
                    arg5 |= 4;
                    
                    if (!arg3)
                        break;
                }
                
                ebx = *edi_1;
                edi_1 += 1;
            }
            
            void* edi_3 = edi_1 - 1;
            
            if (!(arg5 & 8))
            {
                if (arg3)
                    edi_3 = arg2;
                
                result = 0;
            }
            else if (arg5 & 4)
            {
            label_40b9ec:
                *__errno() = 0x22;
                
                if (!(arg5 & 1))
                {
                    void* eax_12;
                    eax_12 = arg5;
                    eax_12 &= 2;
                    char temp4_1 = eax_12;
                    eax_12 = -(eax_12);
                    result = -((eax_12 - eax_12)) + 0x7fffffff;
                }
                else
                    result = 0xffffffff;
            }
            else if (!(arg5 & 1))
            {
                int32_t eax_11 = arg5 & 2;
                
                if (eax_11 && result > 0x80000000)
                    goto label_40b9ec;
                
                if (!eax_11 && result > 0x7fffffff)
                    goto label_40b9ec;
            }
            
            if (arg3)
                *arg3 = edi_3;
            
            if (arg5 & 2)
                result = -(result);
            
            if (var_c)
                *(var_10 + 0x70) &= 0xfffffffd;
            
            return result;
        }
        
        if (arg4 >= 2 && arg4 <= 0x24)
            goto label_40b882;
    }
    
    *__errno() = 0x16;
    sub_4041db(0, 0, 0, 0, 0);
    
    if (var_c)
        *(var_10 + 0x70) &= 0xfffffffd;
    
    return 0;
}

int32_t sub_40ba4b(void* arg1, int32_t* arg2, int32_t arg3)
{
    void* var_18;
    
    if (data_4107fc)
        var_18 = nullptr;
    else
        var_18 = &data_40ff40;
    
    return sub_40b820(var_18, arg1, arg2, arg3, 0);
}

int32_t sub_40ba74(int32_t arg1, int32_t arg2, int32_t* arg3)
{
    void* var_1c;
    sub_405aa0(&var_1c, arg3);
    int32_t ebx = arg1;
    void* var_14;
    char var_10;
    uint32_t eax_3;
    
    if (ebx + 1 > 0x100)
    {
        arg1 = ebx >> 8;
        uint8_t var_c;
        uint16_t* ecx_2;
        
        if (!sub_407c18(arg1, &var_1c))
        {
            var_c = ebx;
            char var_b_2 = 0;
            ecx_2 = 1;
        }
        else
        {
            int32_t eax_6;
            eax_6 = arg1;
            var_c = eax_6;
            char var_b_1 = ebx;
            char var_a_1 = 0;
            ecx_2 = 2;
        }
        
        void* eax_7 = var_1c;
        int16_t var_8;
        int32_t* eax_8 =
            sub_40b460(&var_1c, 1, &var_c, ecx_2, &var_8, *(eax_7 + 4), *(eax_7 + 0x14), 1);
        
        if (!eax_8)
        {
            if (var_10 != eax_8)
                *(var_14 + 0x70) &= 0xfffffffd;
            
            return 0;
        }
        
        eax_3 = var_8;
    }
    else
        eax_3 = *(*(var_1c + 0xc8) + (ebx << 1));
    
    if (var_10)
        *(var_14 + 0x70) &= 0xfffffffd;
    
    return eax_3 & arg2;
}

int32_t __convention("regparm") __alloca_probe_16(void* arg1)
{
    void arg_4;
    void* ecx_1 = (&arg_4 - arg1) & 0xf;
    /* tailcall */
    return __chkstk((arg1 + ecx_1) | (ecx_1 - ecx_1));
}

int32_t __convention("regparm") sub_40bb46(void* arg1)
{
    void arg_4;
    void* ecx_1 = (&arg_4 - arg1) & 7;
    /* tailcall */
    return __chkstk((arg1 + ecx_1) | (ecx_1 - ecx_1));
}

int32_t sub_40bb5c(uint32_t arg1)
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    char var_a = 0;
    uint8_t lCData;
    int32_t result;
    
    if (GetLocaleInfoA(arg1, 0x1004, &lCData, 6))
        result = sub_40be6c(&lCData);
    else
        result = 0xffffffff;
    
    sub_4076f5(eax_1 ^ &__saved_ebp);
    return result;
}

PSTR sub_40bba3(uint32_t arg1, uint32_t arg2, uint8_t* arg3, int32_t* arg4, PSTR arg5, int32_t arg6)
{
    int32_t __saved_ebp;
    int32_t eax_1 = __security_cookie ^ &__saved_ebp;
    int32_t cbMultiByte = *arg4;
    int32_t edi;
    int32_t var_44 = edi;
    PSTR var_24 = nullptr;
    int32_t var_30 = 0;
    PSTR result;
    
    if (arg1 == arg2)
        result = var_24;
    else
    {
        CPINFO cPInfo;
        void* cbMultiByte_1;
        bool cond:2_1;
        
        if (GetCPInfo(arg1, &cPInfo) && cPInfo.MaxCharSize == 1)
        {
            if (!GetCPInfo(arg2, &cPInfo) || cPInfo.MaxCharSize != 1)
                goto label_40bc65;
            
            cbMultiByte_1 = cbMultiByte;
            var_30 = 1;
            
            if (cbMultiByte_1 == 0xffffffff)
                cbMultiByte_1 = _strlen(arg3) + 1;
            
            cond:2_1 = cbMultiByte_1 <= 0;
            goto label_40bc36;
        }
        
    label_40bc65:
        cbMultiByte_1 = MultiByteToWideChar(arg1, MB_PRECOMPOSED, arg3, cbMultiByte, nullptr, 0);
        cond:2_1 = cbMultiByte_1 <= 0;
        
        if (cbMultiByte_1)
        {
        label_40bc36:
            int32_t* lpWideCharStr;
            
            if (cond:2_1 || cbMultiByte_1 > 0x7ffffff0)
                lpWideCharStr = nullptr;
            else
            {
                int32_t* lpWideCharStr_1;
                
                if (cbMultiByte_1 * 2 + 8 > 0x400)
                {
                    lpWideCharStr_1 = sub_401986(cbMultiByte_1 * 2 + 8);
                    
                    if (lpWideCharStr_1)
                    {
                        *lpWideCharStr_1 = 0xdddd;
                        lpWideCharStr_1 = &lpWideCharStr_1[2];
                    }
                }
                else
                {
                    __alloca_probe_16(cbMultiByte_1 * 2 + 8);
                    lpWideCharStr_1 = &var_44;
                    
                    if (&var_44)
                    {
                        var_44 = 0xcccc;
                        lpWideCharStr_1 = &lpWideCharStr_1[2];
                    }
                }
                
                lpWideCharStr = lpWideCharStr_1;
            }
            
            if (!lpWideCharStr)
                result = nullptr;
            else
            {
                sub_404390(lpWideCharStr, 0, cbMultiByte_1 * 2);
                
                if (MultiByteToWideChar(arg1, MB_PRECOMPOSED, arg3, cbMultiByte, lpWideCharStr, 
                    cbMultiByte_1))
                {
                    if (arg5)
                    {
                        if (WideCharToMultiByte(arg2, 0, lpWideCharStr, cbMultiByte_1, arg5, arg6, 
                                nullptr, nullptr))
                            var_24 = arg5;
                    }
                    else if (var_30)
                    {
                    label_40bcfe:
                        PSTR lpMultiByteStr = sub_40659b(1, cbMultiByte_1);
                        var_24 = lpMultiByteStr;
                        
                        if (lpMultiByteStr)
                        {
                            int32_t eax_14 = WideCharToMultiByte(arg2, 0, lpWideCharStr, 
                                cbMultiByte_1, lpMultiByteStr, cbMultiByte_1, nullptr, nullptr);
                            
                            if (!eax_14)
                            {
                                sub_40139b(var_24);
                                var_24 = nullptr;
                            }
                            else if (cbMultiByte != 0xffffffff)
                                *arg4 = eax_14;
                        }
                    }
                    else
                    {
                        cbMultiByte_1 = WideCharToMultiByte(arg2, 0, lpWideCharStr, cbMultiByte_1, 
                            nullptr, 0, nullptr, nullptr);
                        
                        if (cbMultiByte_1)
                            goto label_40bcfe;
                    }
                }
                
                sub_40aa3e(lpWideCharStr);
                result = var_24;
            }
        }
        else
            result = nullptr;
    }
    
    sub_4076f5(eax_1 ^ &__saved_ebp);
    return result;
}

uint32_t sub_40bd55(uint32_t arg1, int32_t* arg2)
{
    void* var_1c;
    sub_405aa0(&var_1c, arg2);
    uint32_t ebx = arg1;
    uint32_t eax_4;
    
    if (ebx < 0x100)
    {
        void* ecx_1 = var_1c;
        int32_t eax;
        
        if (*(ecx_1 + 0xac) <= 1)
            eax = *(*(ecx_1 + 0xc8) + (ebx << 1)) & 1;
        else
        {
            eax = sub_40ba74(ebx, 1, &var_1c);
            ecx_1 = var_1c;
        }
        
        void* var_14;
        char var_10;
        
        if (!eax)
        {
        label_40bdb8:
            
            if (var_10)
                *(var_14 + 0x70) &= 0xfffffffd;
            
            return ebx;
        }
        
        eax_4 = *(*(ecx_1 + 0xcc) + ebx);
    label_40be5f:
        
        if (var_10)
            *(var_14 + 0x70) &= 0xfffffffd;
        
        return eax_4;
    }
    
    char var_8;
    PSTR ecx_3;
    
    if (*(var_1c + 0xac) <= 1)
    {
    label_40be0a:
        *__errno() = 0x2a;
        var_8 = ebx;
        char var_7_2 = 0;
        ecx_3 = 1;
    }
    else
    {
        arg1 = ebx >> 8;
        
        if (!sub_407c18(arg1, &var_1c))
            goto label_40be0a;
        
        int32_t eax_9;
        eax_9 = arg1;
        var_8 = eax_9;
        char var_7_1 = ebx;
        char var_6_1 = 0;
        ecx_3 = 2;
    }
    
    void* eax_11 = var_1c;
    char var_c;
    int32_t eax_12 =
        sub_40b09f(&var_1c, *(eax_11 + 0x14), 0x100, &var_8, ecx_3, &var_c, 3, *(eax_11 + 4), 1);
    
    if (!eax_12)
        goto label_40bdb8;
    
    if (eax_12 != 1)
    {
        int32_t eax_13;
        *eax_13[1] = var_c;
        char var_b;
        eax_4 = eax_13 | var_b;
    }
    else
        eax_4 = var_c;
    
    goto label_40be5f;
}

int32_t sub_40be6c(void* arg1)
{
    return sub_40ba4b(arg1, nullptr, 0xa);
}

void* const __convention("regparm") __chkstk(int32_t arg1)
{
    void* ecx_1 = (&__return_addr - arg1) & ~(arg1 - arg1);
    int32_t __saved_ecx;
    void* eax_2 = &__saved_ecx & 0xfffff000;
    
    while (ecx_1 < eax_2)
    {
        eax_2 -= 0x1000;
        *eax_2;
    }
    
    void* const result = __return_addr;
    *ecx_1 = result;
    return result;
}

int32_t ___ascii_strnicmp(char* arg1, char* arg2, int32_t arg3)
{
    int32_t result = arg3;
    
    if (result)
    {
        char* esi_1 = arg1;
        char* edi_1 = arg2;
        int32_t result_1 = result;
        
        while (true)
        {
            int16_t eax;
            *eax[1] = *esi_1;
            *eax[1] = *eax[1];
            bool cond:1_1 = !*eax[1];
            eax = *edi_1;
            bool cond:0_1;
            
            if (cond:1_1)
            {
            label_40befb:
                result = 0;
                cond:0_1 = *eax[1] < eax;
                
                if (*eax[1] == eax)
                    break;
            }
            else
            {
                eax = eax;
                
                if (!eax)
                    goto label_40befb;
                
                esi_1 = &esi_1[1];
                edi_1 = &edi_1[1];
                
                if (*eax[1] >= 0x41 && *eax[1] <= 0x5a)
                    *eax[1] += 0x20;
                
                if (eax >= 0x41 && eax <= 0x5a)
                    eax += 0x20;
                
                cond:0_1 = *eax[1] < eax;
                
                if (*eax[1] == eax)
                {
                    int32_t result_2 = result_1;
                    result_1 -= 1;
                    
                    if (result_2 != 1)
                        continue;
                    
                    goto label_40befb;
                }
            }
            
            result = 0xffffffff;
            
            if (!cond:0_1)
                return 1;
            
            break;
        }
    }
    
    return result;
}

int32_t __stdcall __allmul(int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4) __pure
{
    if (!(arg4 | arg2))
        return arg1 * arg3;
    
    int32_t result;
    int32_t edx;
    edx = HIGHD(arg1 * arg3);
    result = LOWD(arg1 * arg3);
    return result;
}

int32_t __fastcall sub_40bf60(int32_t, int32_t arg2) __pure
{
    return arg2 - 1;
}

void* sub_40bf70(char* arg1, char arg2)
{
    int32_t eax;
    eax = arg2;
    char* edx = arg1;
    
    while (edx & 3)
    {
        int32_t ecx;
        ecx = *edx;
        edx = &edx[1];
        
        if (ecx == eax)
            /* tailcall */
            return sub_40bf60(ecx, edx);
        
        if (!ecx)
            return 0;
    }
    
    int32_t ebx_2 = eax | eax << 8;
    int32_t ebx_4 = ebx_2 << 0x10 | ebx_2;
    
    while (true)
    {
        int32_t ecx_1 = *edx;
        int32_t ecx_2 = ecx_1 ^ ebx_4;
        edx = &edx[4];
        
        if ((ecx_2 ^ 0xffffffff ^ (0x7efefeff + ecx_2)) & 0x81010100)
        {
            int32_t eax_10 = *(edx - 4);
            
            if (eax_10 == ebx_4)
                return &edx[0xfffffffc];
            
            if (!eax_10)
                break;
            
            if (*eax_10[1] == ebx_4)
                return &edx[0xfffffffd];
            
            if (!*eax_10[1])
                break;
            
            uint16_t eax_11 = eax_10 >> 0x10;
            
            if (eax_11 == ebx_4)
                return &edx[0xfffffffe];
            
            if (!eax_11)
                break;
            
            if (*eax_11[1] == ebx_4)
                return &edx[0xffffffff];
            
            if (!*eax_11[1])
                break;
        }
        else
        {
            int32_t eax_7 = (ecx_1 ^ 0xffffffff ^ (0x7efefeff + ecx_1)) & 0x81010100;
            
            if (eax_7)
            {
                if (eax_7 & 0x1010100)
                    break;
                
                if (!((0x7efefeff + ecx_1) & 0x80000000))
                    break;
            }
        }
    }
    
    return 0;
}

void __stdcall RtlUnwind(void* TargetFrame, void* TargetIp, EXCEPTION_RECORD* ExceptionRecord, void* ReturnValue)
{
    /* tailcall */
    return RtlUnwind(TargetFrame, TargetIp, ExceptionRecord, ReturnValue);
}

