#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

int bin_search(int tix[], int laxnos, int N)
{
    int last=N-1;
    int first=0;
    int i, mid=-1;

    while(first<=last)
    {
        mid=(first+last)/2;
        if(tix[mid]==laxnos)
            return mid;
        else if(tix[mid]<laxnos)
            first=mid+1;
        else
            last=mid-1;
    }
    return -1;
}


void bbsort(int L[], int N)
{
    int i;
    int temp1;
    bool sorted;
    do
    {
        sorted=true;
        for(i=0;i<N-1;i++)
        {
            if(L[i]>L[i+1])
            {
                temp1=L[i];
                L[i]=L[i+1];
                L[i+1]=temp1;

                sorted=false;
            }
        }
        N--;
    }while(sorted==false);
}

int main()
{
    int lucky[500],i, laxnoi[5], counter=0;

    cout<<"Give 5 numbers:";
    for(i=0;i<5;i++)
        cin>>laxnoi[i];

    srand (time(NULL));

    for(i=0;i<500;i++)
        lucky[i] = rand() % 900 + 100;

    bbsort(lucky, 500);

    for(i=0;i<500;i++)
        cout<<lucky[i]<<endl;


    for(int i=0;i<5;i++)
    {
       int position= bin_search(lucky, laxnoi[i], 500);
       if(position!=-1) {
          counter++;
            cout<<"The number "<<laxnoi[i]<<" won!!"<<endl;
        }
    }
    cout<<counter<<" number(s) have won"<<endl;

return 0;
}
