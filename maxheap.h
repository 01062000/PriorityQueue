#include<bits/stdc++.h>

/*i'm designing a templated class so that heap can able to store the different data types like int, float and double */
template<typename T>

class maxHeap
{
private:
    //only data member in this class
    std::vector<T> heap;
    //member functions
    void upHeapify(int idx);
    void downHeapify(int idx);
    //return the parent of the given index
    int getParent(int idx);
    //return the right child of the given index
    int getRightChild(int idx);
    //return the left child of the given index
    int getLeftChild(int idx);

public:
    //add new element in max-heap : o(logn)
    void push(T data);
    //always pop the largest element from max-heap : o(logn)
    void pop();
    //return the largest element from max-heap : o(1) this is the beauty of max-heap(priority_queue)
    T top();
    //return true if max-heap(binary tree) is empty, false otherwise
    bool empty();
};

template<typename T> void maxHeap<T>::push(T data){
    heap.push_back(data);
    int idxData = heap.size()-1;
    upHeapify(idxData);
}

template<typename T> void maxHeap<T>::pop(){
    std::swap(heap[0], heap[heap.size()-1]);
    heap.pop_back();
    downHeapify(0);
}

template<typename T> T maxHeap<T>::top(){
    return heap.at(0);
}

template<typename T> bool maxHeap<T>::empty(){
    return (heap.size()) ? false : true;
}

template<typename T> int maxHeap<T>::getParent(int idx){
    return (idx-1)/2;
}

template<typename T> int maxHeap<T>::getRightChild(int idx){
    return (2*idx + 2);
}

template<typename T> int maxHeap<T>::getLeftChild(int idx){
    return (2*idx + 1);
}

template<typename T> void maxHeap<T>::upHeapify(int idx){
    if(idx == 0){
        return;
    }
    int p = getParent(idx);
    if(heap[p] < heap[idx]){
        std::swap(heap[p], heap[idx]);
        upHeapify(p);
    }else{
        return;
    }
}

template<typename T> void maxHeap<T>::downHeapify(int idx){
    int rightChild = getRightChild(idx);
    int leftChild = getLeftChild(idx);

    if( rightChild >= heap.size() && leftChild >= heap.size() ){
        return;
    }
    int largestIdx = idx;
    if(rightChild < heap.size() && heap[largestIdx] < heap[rightChild]){
        largestIdx = rightChild;
    }
    if(leftChild < heap.size() && heap[largestIdx] < heap[leftChild]){
        largestIdx = leftChild;
    }
    if(largestIdx == idx){
        return;
    }else{
        std::swap(heap[idx], heap[largestIdx]);
        downHeapify(largestIdx);
    }
}