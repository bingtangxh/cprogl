#include <iostream>

class Horse








int main()
{
    Horse *p1 = new Horse; //输出：Horse 申请了空间...
    Horse *p2 = new Pegasus; /*  输出两行：
                                 Horse 申请了空间...
                                 Pegasus 申请了空间...   
                     */    
    cout << endl; 
    
    p1->Fly(); //输出：Just a horse.
    p2->Fly(); //输出：I can fly!
    cout << endl; 
    
    delete p1; //输出：Horse 释放了空间...
    delete p2;  /* 输出两行：
                   Pegasus 释放了空间... 
                   Horse 释放了空间... 
            */
    return 0;
}