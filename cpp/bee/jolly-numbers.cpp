//
// Created by higor on 25/04/2023.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;

    std::cin >> n;

    std::vector<int> in;
    in.reserve(n);

    int val;

    while(n--) {
        std::cin >> val;
        in.push_back(val);
    }

    std::sort(in.begin(), in.end());

    auto it = in.begin();
    auto last = *it;

    while(it != in.end()) {
        auto diff = *it - last;
        if(last > 1) {
            std::cout << "Not jolly";
            break;
        }
        last = *it++;
    }

    if(it == in.end()) {
        std::cout << "Jolly";
    }

    return 0;
}
