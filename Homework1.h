/*
 Name: Jacob Stock
 Email: jstock1@crimson.ua.edu
 Course Section: Fall 2023 CS 201
 Homework #: 1
*/

#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename RandomIt>
constexpr void heapify(RandomIt first, RandomIt last, int i) {
    //Initiallize largest as root
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    //If left child is larger
    if (left < distance(first, last) && *(first + left) > *(first + largest)){
        largest = left;
    }

    //If right child is larger
    if (right < distance(first, last) && *(first + right) > *(first + largest)){
        largest = right;
    }
    
    //If largest is not the root
    if (largest != i) {
        iter_swap(first + i, first + largest);

        heapify(first, last, largest);
    }
}


template <typename RandomIt>
constexpr void heapsort(RandomIt first, RandomIt last) {
    //Find length
    int l = distance(first, last);

    for (int i = l / 2 - 1; i >= 0; i--){
        heapify(first, last, i);
    }

    for (int i = l - 1; i > 0; i--) {
        // Move current root to end
        iter_swap(first, first + i);

        // Call max heapify on the reduced heap
        heapify(first, first + i, 0);
    }
}


template <typename RandomIt>
constexpr RandomIt partition(RandomIt first, RandomIt last) {
    //Using a middle pivot
    RandomIt pivot = first + (distance(first, last)/2);
    RandomIt beg = first - 1;
    RandomIt end = last - 1;

    //Swaps the pivot to with the last element
    iter_swap(pivot, end);

    for (RandomIt i = first; i < end; i++) {
        if (*i <= *end) {
            beg++;
            iter_swap(beg, i);
        }
    }

    beg++;
    iter_swap(beg, end);

    return beg;
}


template <typename RandomIt>
constexpr void quicksort(RandomIt first, RandomIt last) {
    //return condition
    if (first >= last){
        return;
    }

    RandomIt pivot = partition(first, last);

    quicksort(first, pivot);
    quicksort(pivot + 1, last);
}