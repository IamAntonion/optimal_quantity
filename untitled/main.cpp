#include <algorithm>
#include <functional>
#include <iostream>
#include <cmath>
#include <array>
#include <stdio.h>
#include <vector>
#include <utility>
#include <cstdio>
#include <cinttypes>

int main()
{
    unsigned int N, X;
    uint64_t T;

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N;
    std::cin >> X;
    std::cin >> T;

    std::vector<std::pair<unsigned, unsigned>> a;
    a.reserve(2 * 100000);
    for (unsigned int i = 0; i < N; i++) {
        unsigned t;
        std::cin >> t;
        a.push_back({t,i});
    }

    std::sort(a.begin(), a.end(), [&](std::pair<unsigned, unsigned> a, std::pair<unsigned, unsigned> b)
                                      {
                                          return std::llabs((int64_t) a.first - (int64_t)X) < std::llabs((int64_t)b.first - (int64_t)X);
                                      });

    unsigned K = 0;
    uint64_t t = 0;

    for (unsigned int i = 0; (i < N) /*&& (t <= T)*/; ++i){
        uint64_t time = std::llabs((int64_t)a[i].first - (int64_t)X);
        if (t + time > T){
            break;
        }
        t += time;
        K++;
    }

    std::cout << K << std::endl;
    for (int i = 0; i < K; i++) {
        std::cout << a[i].second + 1 << " ";
    }

    return 0;
}
