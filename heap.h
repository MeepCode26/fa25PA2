//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;          // places a new index at end
        upheap(size, weightArr);   // restores order of the heap
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()

        if (size == 0) return -1;

        int minIdx = data[0]; // the smallest element in the array will always be the root
        data[0] = data[size - 1]; // moves last element to the root
        size--;
        downheap(0, weightArr);

        return minIdx;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0) {
            int parent = (pos - 1) / 2; // parent index in array representation

            // if child weighs less than parent. swap them.
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                int temp = data[pos];
                data[pos] = data[parent];
                data[parent] = temp;

                pos = parent; // moves up to continue checking elements
            } else {
                break; // once the heap has checked and fixed all elements it can end the loop
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (true) {
            int left = 2 * pos + 1;   // left child index
            int right = 2 * pos + 2;  // right child index
            int smallest = pos;       // assuming the current node is the smallest

            // Compare left child
            if (left < size && weightArr[data[left]] < weightArr[data[smallest]]) {
                smallest = left;
            }

            // Compare right child
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]]) {
                smallest = right;
            }

            // if the smaller child was found, it will then swap and continue downward
            if (smallest != pos) {
                int temp = data[pos];
                data[pos] = data[smallest];
                data[smallest] = temp;

                pos = smallest; // Updates position, then continues checking lower levels
            } else {
                break; // if parent is smaller than both children, the heap is viable
            }
        }
    }
};

#endif