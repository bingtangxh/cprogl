#include <stdio.h>
#include <string.h>
#include <Windows.h>
#pragma comment(lib,"User32.lib")
#pragma comment(lib,"Advapi32.lib")
#pragma comment(lib,"Kernel32.lib")
#ifdef _ARM
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#ifndef UNICODE
#define UNICODE
#endif

const signed char KEY_CHARSET[]="BCDFGHJKMPQRTVWXY2346789";

#define HEXVAL(hex) (hex-((hex>'9') ? ((hex<'a') ? 55 : 87) : 48))

// int getHexVal(const char hex) { return hex-((hex>'9') ? ((hex<'a') ? 55 : 87) : 48); }
void removeFrom(char *str,char remv);
int string2ByteArrayFastest(const char * hex,char * result);
void decodePID(const unsigned char *digitalProductId,char *productKey);
void about(void);
void help(void);
void printW(const wchar_t* wstr);

int main(int argc,char **argv)
{
    HKEY hKey;
    DWORD size=UCHAR_MAX;
    char buf[UCHAR_MAX]="";
    char rawInput[329];
    char productKey[30];
    wchar_t wProductKey[30];
    wchar_t result[154]=L"本程序也可以从命令行运行，使用 /? 查看用法。\n你的产品密钥为： ";
    char command[41];
    unsigned char digitalProductId[164]="";
    long unsigned int lpType=REG_BINARY;
    switch (argc)
    {
        case 1:
        {
            about();
            long ORet=RegOpenKeyExA(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion",0,KEY_READ,&hKey);
            if (ORet!=ERROR_SUCCESS)
            {
                printf("Failed to open the registry: \n%s\n%s\n","SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion","DigitalProductId");
                return 3;
            } else
            {
                long QRet=RegQueryValueExA(hKey,"DigitalProductId",NULL,&lpType,(BYTE*) buf,&size);
                decodePID(buf,productKey);
                MultiByteToWideChar(CP_ACP,0,productKey,-1,wProductKey,30);
                wcsncat_s(result,154,wProductKey,29);
                wcsncat_s(result,154,L"\n要将它复制到剪贴板吗？",35);
                RegCloseKey(hKey);
                if (MessageBoxW(NULL,(LPCWSTR) result,L"DPIDDC",MB_ICONINFORMATION+MB_YESNO)==IDYES)
                {
                    snprintf(command,41,"echo %s| clip",productKey);
                    system(command);
                }
                return 0;
            }
            break;
        }
        case 2:
            if (!strncmp(argv[1],"/?",3))
            {
                help();
                return 0;
            } else {
                printW(L"参数错误，使用 /? 查看用法。\n");
                return 1;
            }
            break;
        case 3:
            if (!_stricmp(argv[1],"/F"))
            {
                if (strlen(argv[2])==328)
                {
                    strncpy_s(rawInput,329,argv[2],328);
                    // 本来这里设置的 _DstSizeInChars 和 rawInput 的长度都是 328 
                    // 但是这样的话， strncpy_s 会将 rawInput 弄成空字符串，所以只好 329 了
                    // printf("%s\n%d\n",rawInput,strcmp(rawInput,argv[2]));
                    string2ByteArrayFastest(rawInput,digitalProductId);
                    decodePID(digitalProductId,productKey);
                    puts(productKey);
                    return 0;
                } else
                {
                    printW(L"输入的 DigitalProductId 长度错误，应当是 328 。\n");
                    return 2;
                }
            } else {
                printW(L"参数错误，使用 /? 查看用法。\n");
                return 1;
            }
            break;
        default:
            printW(L"参数数量错误，使用 /? 查看用法。\n");
            return 1;
    }
    return 0;
}

void removeFrom(char *str,char remv)
{
    int i,j=0;
    for (i=0; str[i]!='\0'; i++)
    {
        if (str[i]!=remv)
        {
            str[j++]=str[i];
        }
    }
    str[j]='\0';
}

int string2ByteArrayFastest(const char * hex,char * result)
{
    if (strlen(hex)%2==0)
    {
        for (int i=0; i<(int) strlen(hex)/2; i++)
        {
            result[i]=(char) ((HEXVAL(hex[i*2])*16)+HEXVAL(hex[(i*2)+1]));
        }
        return 0;
    } else
    {
        puts(hex);
        printW(L"十六进制的原字符串的长度不能是奇数\n");
        return -1;
    }
}

void decodePID(const unsigned char *digitalProductId,char *productKey) {
    // int bp=0;
    unsigned char pidBlock[16]="";
    signed char decodedKey[30];
    // unsigned char digitalProductId2[164];
    // strcpy_s(digitalProductId2,164,digitalProductId);
    int isNKey=(digitalProductId[66]>>3)&1;

    //digitalProductId2[66]=(unsigned char)((digitalProductId2[66]&0xF7)|((isNKey&2)<<2));

    // 复制 PID 相关的 15 个字节
    for (int i=52; i<=67; i++) {
        pidBlock[i-52]=digitalProductId[i];
    }

    // 特殊位操作  
    pidBlock[14]=(pidBlock[14]&247)|((isNKey%4>=2 ? 2 : 0)<<2);

    // 初始化 Key 结果数组
    memset(decodedKey,0,sizeof(decodedKey));

    // Base24 解码
    for (int i=28; i>=0; i--) {
        if (((i+1)%6==0)&&1) {
            decodedKey[i]='-';
        } else {
            int num=0;
            for (int j=14; j>=0; j--) {
                int temp=(num<<8)|pidBlock[j];
                pidBlock[j]=(unsigned char) (temp/24);
                num=temp%24;
                decodedKey[i]=(signed char) KEY_CHARSET[num];
            }
        }
    }
    if (isNKey!=0)
    {
        int nPos=0;
        for (int i=0; i<24; i++) {
            if (decodedKey[0]==KEY_CHARSET[i]) {
                nPos=i;
                break;
            }
        }
        decodedKey[29]='\0';
        removeFrom(decodedKey,'-');
        memmove(decodedKey,decodedKey+1,strlen(decodedKey));
        size_t currentLength=strlen(decodedKey);
        if (nPos>currentLength) nPos=(int) currentLength;
        memmove(decodedKey+nPos+1,decodedKey+nPos,currentLength-nPos+1);
        decodedKey[nPos]='N';
    }
    decodedKey[29]='\0';
    snprintf(productKey,30,"%5.5s-%5.5s-%5.5s-%5.5s-%5.5s",
             decodedKey,decodedKey+5,decodedKey+10,decodedKey+15,decodedKey+20);
}

void about(void){
    wchar_t aboutText[]=
        L"Digital Product Id Decoder Console Edition Bugfixed\n"
        L"\n"
        L"Copyright (C) bingtangxh.\n"
        L"\n"
        L"May the Anemo God bless you.\n"
        L"\n"
        ;
    printW(aboutText);
}

void help(void){
    wchar_t helpText[]=
        L"将 DigitalProductId 注册表 DWORD 数值解码得到产品密钥。\n"
        L"\n"
        L"Copyright (C) bingtangxh.\n"
        L"\n"
        L"DPIDDC [ /F digitalproductid | /? ]\n"
        L"\n"
        L"/F                 表示进行解码用户给定的 DigitalProductId。\n"
        L"digitalproductid   注册表中长度为 328 的 DWORD 数值。\n"
        L"\n"
        L"/?                 显示此帮助信息。\n"
        L"\n"
        L"也可以直接双击（不带任何参数）运行本程序，只能查询当前系统的产品密钥。\n"
        L"\n"
        L"如果想要从一个批处理脚本调用本程序，你可以这样使用：\n"
        L"\n"
        L"FOR /F \"tokens=1-3\" %%A IN ('reg query \"HKLM\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\" /v DigitalProductId') DO @IF /I %%A==DigitalProductId DPIDDC /F %%C\n"
        ;
    printW(helpText);
}

void printW(const wchar_t* wstr) {
#ifdef _WIN32
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD written;
    WriteConsoleW(hConsole,wstr,(DWORD) wcslen(wstr),&written,NULL);
#else
    printf("%ls",wstr);
#endif
}