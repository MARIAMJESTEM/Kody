//
// Created by Lenovo on 19.12.2020.
//

#include <iostream>
#include "package.hpp"
#include "factory.hpp"
//jak chcecie to możecie odkomentować poszczególne rzeczy i sobie sprawdzić
int main() {

    Factory factory;
    factory.add_ramp(Ramp(1,1));
    factory.add_worker(Worker(1,1,std::make_unique<PackageQueue>(PackageQueueType::FIFO)));
    factory.add_storehouse(Storehouse(1));

    Ramp& r = *(factory.find_ramp_by_id(1));
    std::cout << &r;
    //dotąd działa, dopiero wyrzuca błąd pamięci przy add_receiver
    Worker& w = *(factory.find_worker_by_id(1));
    std::cout << &w;
    r.receiver_preferences_.add_receiver(&w);
    //test IsAssignedIDlowest

//    Package p1;
//    Package p2;
//    Package p3;
//    ElementID id1 = p1.get_id();
//    ElementID id2 = p2.get_id();
//    ElementID id3 = p3.get_id();
//    std::cout << id1 <<std::endl;
//    std::cout << id2 << std::endl;
//    std::cout << id3 << std::endl;


    //test na destruktor

//    Package p3;
//    p3.Package::~Package();
//    Package p4;
//    ElementID id4 = p4.get_id();
//    std::cout << id4 <<std::endl;


    //test na move constructor

//    Package p5;
//    Package p6(std::move(p5));
//    ElementID  id6 = p6.get_id();
//    std::cout << id6 << std::endl;


    //test na operator move

//    Package p7;
//    Package p8 = std::move(p7);
//    ElementID  id8 = p8.get_id();
//    ElementID  id7 = p7.get_id();
//    std::cout << id8 <<std::endl;
//    std::cout << id7 <<std::endl;

}
