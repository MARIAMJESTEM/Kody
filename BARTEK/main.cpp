#include "TSP.hpp"

#include <iostream>


int main() {
    cost_matrix_t cm = {{INF, 10, 1,   19, 12},
                      {10, INF, 20,  6,  3},
                      {8,   20, INF, 4,  2},
                      {19,  6,  4, INF,  7},
                      {12,  3,  2,   7, INF}};



    std::vector<std::vector<int>> mat =CostMatrix(cm).get_matrix();
    std::vector<cost_t> coli = mat[0];
    for(int i = 0; i <= coli.size() -1;i++){
        for (int j = 0; j <= mat[i].size()-1; j++){
            std::cout << mat[i][j]<<std::endl;
        }
    }
    int col;
    col = CostMatrix(cm).reduce_cols();
    std::cout << col<<std::endl;


    /* Rozwiązania:
     * 32 : 2 3 4 1 0
     * 32 : 1 4 3 2 0
     */

//    cost_matrix_t cm {
//            {INF, 12,   3,  45,   6},
//            {78, INF,  90,  21,   3},
//            { 5,  56, INF,  23,  98},
//            {12,   6,   8, INF,  34},
//            { 3,  98,   3,   2, INF}
//    };

    /* Rozwiązanie:
     * 30 : 4 3 2 0 1
    */

//    cost_matrix_t cm {
//            {INF,  3,  4,  2,  7},
//            {3,  INF,  4,  6,  3},
//            {4,  4,  INF,  5,  8},
//            {2,  6,  5,  INF,  6},
//            {7,  3,  8,  6,  INF},
//    };

    /* Rozwiązania:
     * 19 : 4 3 0 2 1
     * 19 : 1 2 0 3 4
    */

//    tsp_solutions_t solutions = solve_tsp(cm);
//
//
//    for (auto elem : solutions) {
//        std::cout << elem.lower_bound << " : ";
//        for (auto pelem : elem.path) {
//            std::cout << pelem << " ";
//        }
//        std::cout << "\n";
//    }

    return EXIT_SUCCESS;
}
