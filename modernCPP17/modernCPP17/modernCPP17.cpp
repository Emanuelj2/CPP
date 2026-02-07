#include <iostream>
#include <optional>

// Function must be outside main
std::optional<int> getValue(bool ok) {
    if (ok) return 42;
    return std::nullopt;
}

int main() {
    auto result = getValue(true);

    if (result) {
        std::cout << "Value: " << *result << '\n';
    }
    else {
        std::cout << "No value\n";
    }

    std::cout << __cplusplus << '\n';

    return 0;
}

