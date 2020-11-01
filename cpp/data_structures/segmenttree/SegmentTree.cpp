//
// Created by vincent on 10/27/20.
//
#include <cassert>
#include "SegmentTree.h"

using namespace cpst;

/**
 * This function is used build the segment tree with a binary heap
 * rappresentation.
 * @tparam T is the type of structure, usually it is a int or another numeric type
 * @param inputs is the inputs array where we want build the segment tree with binary heap rappresentation
 */
template<class T>
void SegmentTree<T>::build_structure(const std::vector<T> &inputs, int left_index, int right_index)
{
    build_structure_procedure(inputs, 1, left_index, right_index - 1);
}

/**
 * This is the sub procedure that help the build_structure procedure to make the logic inside the segment tree
 * @tparam T is the type of structure, usually it is a int or another numeric type
 * @param start_index
 * @param left_index
 * @param right_index
 */
template<class T>
void SegmentTree<T>::build_structure_procedure(const std::vector<T> &inputs, int start_index, int left_index, int right_index)
{
    if (left_index == right_index) {
        structure[start_index] = left_index;
        return;
    }
    int middle_point = (left_index + right_index) / 2;
    int left_child = left_child_index(start_index);
    int right_child = right_child_index(start_index);
    build_structure_procedure(inputs, left_child, left_index, middle_point);
    build_structure_procedure(inputs, right_child, middle_point + 1, right_index);
    int segment_left = structure[left_child];
    int segment_right = structure[right_child];
    structure[start_index] = (inputs[segment_left] <= inputs[segment_right]) ? segment_left : segment_right;
}

template<class T>
int SegmentTree<T>::range_query(int start_index, int end_index) {
    //TODO implement this function
    assert(false);
    return 0;
}

template<class T>
int SegmentTree<T>::range_query_subroutine(int start_index, int end_index) {
    //TODO implement this function
    assert(false);
    return 0;
}


template class cpst::SegmentTree<int>;