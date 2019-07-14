#include <bits/stdc++.h>

using namespace std;


class Heap
{
private:
    vector<int> arr;
    int heapSize = 0;
    int parent(int i )
    {
        return (i-1)/2;
    }
    int left(int i)
    {
        return 2*i+1;
    }
    int right(int i)
    {
        return 2*i+2;
    }
    void swap(int &a,int &b)
    {
        a = a ^ b ;
        b = a ^ b ;
        a = a ^ b ;
    }
    int getMin()
    {
        return arr[0];
    }
public:
    void insertKey(int k)
    {
        if (!heapSize)
        {
            arr.push_back(k);
            heapSize++;
            return;
        }
        int i = heapSize;
        arr[i]=k;
        while(i!=0 && arr[parent(i)]>arr[i])
        {
            swap(arr[i],arr[parent(i)]);
            i = parent(i);
        }
        heapSize++;
    }
    void minHeapify(int i)
    {
        int L = left(i);
        int R = right(i);
        int smallest = i;
        if (L < heapSize && arr[i]>arr[L])
        {
            smallest = L;
        }
        if (R < heapSize && arr[smallest]>arr[R])
        {
            smallest = R ;
        }
        if (smallest != i)
        {
            swap(arr[i],arr[smallest]);
            minHeapify(smallest);
        }
    }
    int pop()
    {
        if(heapSize!=0)
        {
            int res = arr[0];
            arr[0]=arr[heapSize-1];
            arr.pop_back();
            minHeapify(0);
            heapSize--;
            return res;
        }
        return INT_MIN;

    }
    void printSorted()
    {
        cout<<"[";
        while(heapSize)
        {
            cout<<pop();
            if (heapSize)
                cout<<",";
        }
        cout<<"]\n";
    }
    void printOriginal()
    {
        cout<<"[";
        for (int i = 0 ; i < heapSize-1; i++)
        {
            cout<<arr[i];
            if (i!=heapSize-2)
            {
                cout<<",";
            }
        }
        cout<<"]\n";
    }
    void decreaseKey(int idx,int newVal)
    {
        arr[idx] = newVal;
        while(idx!=0 && arr[parent(idx)]>arr[idx])
        {
            swap(arr[idx],arr[parent(idx)]);
            idx = parent(idx);
        }
    }
    void buildHeap(vector<int> values)
    {
        //for(int i =0;i<values.size();i++){
        //  cout<<values[i]<<endl;}
        arr = values;
        heapSize = values.size();
        for(int i = heapSize/2 ; i>=0; i--)
        {
            minHeapify(i);
        }


    }
    void heapSort()
    {
        for(int i = heapSize/2 ; i>=0; i--)
        {
            minHeapify(i);
        }
        //at this point only the mini is at the root
        int temp = heapSize;
        for (int i = heapSize -1 ; i>=1 ; i--)
        {
            swap(arr[0],arr[i]);
            heapSize--;
            minHeapify(0);
        }
        heapSize = temp;
        cout<<"[";
        for (int i =  heapSize-1 ; i >=0; i--)
        {
            cout<<arr[i];
            if (i!=0)
            {
                cout<<",";
            }
        }
        cout<<"]\n";
    }




};
int main()
{
    Heap h;
    vector<int> values = {10,-20,-40,444};
    h.buildHeap(values);

    h.insertKey(99999);
    h.insertKey(5);
    h.insertKey(3);

    h.decreaseKey(5,-50);
    h.printOriginal();
    h.heapSort();
    // h.printSorted();
    h.pop();
    h.printSorted();
    return 0;
}
