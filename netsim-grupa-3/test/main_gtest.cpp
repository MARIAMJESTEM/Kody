//
// Created by Lenovo on 18.12.2020.
//

// Dołącz plik nagłówkowy Googletest.
#include "gtest/gtest.h"
#include "package.hpp"
#include "gmock/gmock.h"

// Aby testy zostały uruchomione, Googletest wymaga funkcji
// main() o poniżej zawartości.
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}