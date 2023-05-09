//
// Created by higor on 27/04/2023.
//

#include <iostream>
#include <vector>

struct Car {
    int number = 0, position = 0;
};

int main() {
    int n;
    using Cars = std::vector<Car>;

    while (std::cin >> n) {
        if (n == 0) {
            break;
        }

        Car c;
        Cars cars;
        Cars end;

        cars.reserve(n);

        for (int i = 0; i < n; i++) {
            end.emplace_back();
        }

        while (n--) {
            std::cin >> c.number >> c.position;
            cars.push_back(c);
        }

        bool fatal = false;

        for (int i = 0; i < cars.size(); i++) {
            Car car = cars.at(i);

            int sum = i + car.position;

            if (sum < 0 || sum > cars.size() - 1 || end.at(sum).number != 0) {
                fatal = true;
                break;
            }

            end.at(sum) = car;
        }

        if (fatal)
            std::cout << -1;
        else
            for(int i = 0; i < end.size(); i++) {
                std::cout << end.at(i).number;

                if(i != end.size() - 1) {
                    std::cout << ' ';
                }
            }
        std::cout << std::endl;
    }

    return 0;
}