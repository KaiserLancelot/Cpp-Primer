//
// Created by kaiser on 18-12-17.
//

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

void ElimDups(std::vector<std::string> &words) {
    std::sort(std::begin(words), std::end(words));
    words.erase(std::unique(std::begin(words), std::end(words)), std::end(words));
}

void Biggies(std::vector<std::string> &words,
             std::vector<std::string>::size_type sz) {
    ElimDups(words);
    std::stable_sort(std::begin(words), std::end(words),
                     [](const auto &s1, const auto &s2) { return std::size(s1) < std::size(s2); });
    auto wc{std::find_if(std::begin(words), std::end(words),
                         [sz](const auto s) { return std::size(s) >= sz; })};
    std::for_each(wc, std::end(words), [](const auto &s) { std::cout << s << ' '; });
    std::cout << '\n';
}

int main() {
    std::vector<std::string> vs{"aaaaa", "aaaaaa", "cc", "cc", "b"};
    Biggies(vs, 3);
}