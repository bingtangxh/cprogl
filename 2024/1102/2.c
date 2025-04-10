void rollArray(int arr[],int length,int delta)
{
    
    for(int i=0,curr=1,st=1,prev=curr-delta,temp=arr[1];i<length&&st<=delta;i++)
    {
        /*这里i表示已处理多少个元素，而curr是当前要处理的*/
        if(curr<=0){curr+=length;}
        else{curr=curr;}
        if(prev<=0){prev+=length;}
        else{prev=prev;}
        if(prev!=st)
        {
            arr[curr]=arr[prev];
            curr=prev;
            prev=curr-delta;
        }
        else
        /*到1了*/
        {
            arr[curr]=temp;
            if(length%delta==0)
            {
                st++;
                temp=arr[st];
                curr=st;
                prev=curr-delta;
            }
            else
            {
                break;
            }
        }
        
    }
}

int main()
{
    return 0;
}
