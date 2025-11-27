#include <windows.h>
#include <synchapi.h>
#include <stdio.h>

#pragma comment(lib,"User32.lib")

int main() {
    // 清除“保持唤醒”状态，允许自动进入连接待机
    SetThreadExecutionState(ES_CONTINUOUS);
    //SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, 2);
    Sleep(5000);
    puts("5000 elapsed");
    SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, -1);
    getchar();
    return 0;
    /*
    SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, -1);
    keybd_event(VK_SHIFT, 0, 0, 0);
    keybd_event(VK_SHIT, 0, KEYEVENTF_KEYUP, 0);
    */
}
