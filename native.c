//======================================================================
//
// This is a demonstration of a Native NT program. These programs
// run outside of the Win32 environment and must rely on the raw
// services provided by NTDLL.DLL. AUTOCHK (the program that executes
// a chkdsk activity during the system boot) is an example of a
// native NT application.
//
// This example is a native 'hello world' program. When installed with
// the regedit file associated with it, you will see it print 
// "hello world" on the initialization blue screen during the system
// boot. This program cannot be run from inside the Win32 environment.
//
//======================================================================
#include "ntddk.h"
#include "stdio.h"

//Environment information, which includes command line and image file name
typedef struct 
{
    ULONG            Unknown[21];     
    UNICODE_STRING   CommandLine;
    UNICODE_STRING   ImageFile;
} ENVIRONMENT_INFORMATION, *PENVIRONMENT_INFORMATION;
 
// This structure is passed as NtProcessStartup's parameter
typedef struct 
{
    ULONG                     Unknown[3];
    PENVIRONMENT_INFORMATION  Environment;
} STARTUP_ARGUMENT, *PSTARTUP_ARGUMENT;
 
// Data structure for heap definition. 
// This includes various sizing parameters and callback routines, 
// which, if left NULL, result in default behavior
typedef struct 
{
    ULONG     Length;
    ULONG     Unknown[11];
} RTL_HEAP_DEFINITION, *PRTL_HEAP_DEFINITION;
 
// Native NT api function to write something to the boot-time
// blue screen
NTSTATUS NTAPI NtDisplayString(
    PUNICODE_STRING String
    );
 
// Native applications must kill themselves when done - 
// the job of this native API
NTSTATUS NTAPI NtTerminateProcess(
    HANDLE ProcessHandle, 
    LONG ExitStatus 
    );
 
// Definition to represent current process
#define NtCurrentProcess() ( (HANDLE) -1 )
 
// Heap creation routine
HANDLE NTAPI RtlCreateHeap(
    ULONG Flags, 
    PVOID BaseAddress, 
    ULONG SizeToReserve, 
    ULONG SizeToCommit, 
    PVOID Unknown,
    PRTL_HEAP_DEFINITION Definition
    );
 
// Heap allocation function (ala "malloc")
PVOID NTAPI RtlAllocateHeap(
    HANDLE Heap, 
    ULONG Flags, 
    ULONG Size 
    );
 
// Heap free function (ala "free")
BOOLEAN NTAPI RtlFreeHeap(
    HANDLE Heap, 
    ULONG Flags, 
    PVOID Address 
    );
 
// Our heap
HANDLE Heap;
//----------------------------------------------------------------------
// NtProcessStartup
// Instead of a 'main', NT applications are entered via this entry point.  
//----------------------------------------------------------------------
void NtProcessStartup( PSTARTUP_ARGUMENT Argument )
{
    PUNICODE_STRING commandLine;
    PWCHAR stringBuffer;
    PWCHAR argPtr;
    UNICODE_STRING helloWorld;
    RTL_HEAP_DEFINITION  heapParams;
    
    // Initialize some heap
    memset( &heapParams, 0, sizeof( RTL_HEAP_DEFINITION ));
    heapParams.Length = sizeof( RTL_HEAP_DEFINITION );
    Heap = RtlCreateHeap( 2, 0, 0x100000, 0x1000, 0, &heapParams );
    
    // Point at command line
    commandLine = &Argument->Environment->CommandLine;
    // Locate the argument
    argPtr = commandLine->Buffer;
    while( *argPtr != L' ' )
    {
        argPtr++;
    }
    argPtr++;
    
    // Print out the argument
    stringBuffer = RtlAllocateHeap( Heap, 0, 256 );
    swprintf( stringBuffer, L"\n%s", argPtr );
 
    helloWorld.Buffer = stringBuffer;
    helloWorld.Length = wcslen( stringBuffer ) * sizeof(WCHAR);
    helloWorld.MaximumLength = helloWorld.Length + sizeof(WCHAR);
 
    NtDisplayString( &helloWorld );
    
    // Free heap
    RtlFreeHeap( Heap, 0, stringBuffer );
 
    // Terminate
    NtTerminateProcess( NtCurrentProcess(), 0 );
}