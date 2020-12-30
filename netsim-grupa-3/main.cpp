//
// Created by Lenovo on 18.12.2020.
//

#include <iostream>
#include "package.hpp"
#include "nodes.hpp"

int main() {
    //test IsAssignedIDlowest
    /*
    Package p1;
    Package p2;
    ElementID id1 = p1.get_id();
    ElementID id2 = p2.get_id();
    std::cout << id1 <<std::endl;
    std::cout << id2 << std::endl;
*/

    //test na destruktor
    /*
    Package p3;
    p3.Package::~Package();
    Package p4;
    ElementID id4 = p4.get_id();
    std::cout << id4 <<std::endl;
    */

    //test na move constructor
    /*
    Package p5;
    Package p6(std::move(p5));
    ElementID  id6 = p6.get_id();
    std::cout << id6 << std::endl;
     */

    //test na operator move
    /*
    Package p7;
    Package p8 = std::move(p7);
    ElementID  id8 = p8.get_id();
    ElementID  id7 = p7.get_id();
    std::cout << id8 <<std::endl;
    std::cout << id7 <<std::endl;
     */
    return 0;
}
