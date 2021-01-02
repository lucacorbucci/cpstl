//
// Created by vincent on 9/23/20.
//
#include <vector>

namespace cpstl {

    template<typename T, typename R>
    R binary_search(std::vector<T> const &inputs, T key, R start,
                                R end)
    {
        if(start > end) return -1;
        // We go to te middle of algorithm
        auto middle_pos = start + (end - start) / 2;
        if (inputs[middle_pos] > key) {
            //sub array [start, middle_pos]
            return binary_search(inputs, key, start, middle_pos - 1);
        } else if (inputs[middle_pos] < key) {
            // sub array [middle_pos - end]
            return binary_search(inputs, key, middle_pos + 1, end);
        }
        return middle_pos;
    }

    template <typename T, typename R>
    R exponential_search(std::vector<T> const &inputs, T key)
    {
        if (inputs[0] == key) return 0;
        R size_sub_array = 1;
        while (size_sub_array < inputs.size()
               && inputs[size_sub_array] < key) {
            size_sub_array *= 2;
        }
        R start = size_sub_array;
        R end = std::min(size_sub_array, static_cast<R>(inputs.size() - 1));
        return binary_search<T, R>(inputs, key, start, end);
    }
};
