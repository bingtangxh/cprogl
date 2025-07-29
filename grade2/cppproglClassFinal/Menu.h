#ifndef MENU_H
#define MENU_H

#include "Info.h"
#include <cstdlib>
#include <conio.h>
#include <limits>
class Menu {
private:
    Info info;

public:
    static void display(int isWaitRequired=0) {
        if(isWaitRequired) {
            cout << "\n按任意键清除屏幕并回到主菜单……\n";
            _getch();
            
        }
        system("cls");
        cout << "\n";
        cout << "╔════════════════════════════════════════════╗\n";
        cout << "║            C. & A. 工资管理系统             \n";
        cout << "╟─────────┬──────────────────────────────────╢\n";
        cout << "║   [1]   │    添加员工信息                   \n";
        cout << "║   [2]   │    显示所有员工                   \n";               
        cout << "║   [3]   │    保存员工信息到文件        \n";       
        cout << "║   [4]   │    从文件读取员工信息        \n";
        cout << "║   [0]   │    退出系统                  \n";
        cout << "╚═════════╧══════════════════════════════════╝\n\n";
        cout << "\n请输入选项: ";
    }

    void handle_menu() {
        int choice;
        int isWaitRequired=0;
        do {
            choice=-1;
            display(isWaitRequired);
            cin >> choice;
            switch (choice) {
                case 1: info.addInfo(); break;
                case 2: info.showInfo(); isWaitRequired=1; break;
                case 3: info.writeInfo(); isWaitRequired=1; break;
                case 4: info.readInfo(); isWaitRequired=1; break;
                case 0: cout << "你选择了退出系统，那么，👋 再见！\n"; break;
                default:
                    cout << "❗你的输入有误，请重新输入。\n"; 
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                    isWaitRequired=1;
            }
        } while (choice != 0);
    }
};

#endif
