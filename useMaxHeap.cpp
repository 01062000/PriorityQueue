#include<bits/stdc++.h>
//include the max-heap library
#include "maxheap.h"

using namespace std;

int main(){
    //creating an object of max-heap(priority_queue)
    maxHeap<int> pq;
    //Adding elements
    pq.push(50);
    pq.push(20);
    pq.push(25);
    pq.push(19);
    pq.push(89);
    //this will give us all the elements from max-heap in deceasing order, bcz it's max-heap
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
    
    return 0;
}