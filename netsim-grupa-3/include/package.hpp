//
// Created by Lenovo on 18.12.2020.
//

#ifndef NET_SIMULATION_PACKAGE_HPP
#define NET_SIMULATION_PACKAGE_HPP


#include <set>
#include "types.hpp"


class Package{
public:
    Package();
    explicit Package(ElementID id): _id(id){assigned_IDs.insert(_id);}
    ElementID get_id() const {return _id;}
    Package(Package &&other);
    //Package(Package& other)= default;
    Package &operator = (Package &&other);
    ~Package();
private:
    ElementID _id;
    static std::set<ElementID> assigned_IDs;
    static std::set<ElementID> freed_IDs;
};
#endif //NET_SIMULATION_PACKAGE_HPP