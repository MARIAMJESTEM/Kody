//
// Created by Lenovo on 18.12.2020.
//

#ifndef NET_SIMULATION_PACKAGE_HPP
#define NET_SIMULATION_PACKAGE_HPP

#endif //NET_SIMULATION_PACKAGE_HPP
#include <set>


using ElementID = int;

class Package{
public:
    Package(){
        ElementID id_of_Package;
        if(freed_IDs.empty())
        {   if (!assigned_IDs.empty()) {
                ElementID last_element_assigned_IDs  = *assigned_IDs.rbegin();
                id_of_Package = last_element_assigned_IDs + 1;
                assigned_IDs.insert(id_of_Package);
            }
            else{
                id_of_Package = 1;
                assigned_IDs.insert(id_of_Package);
            }
        }
        else{
            std::set<ElementID>::iterator its = freed_IDs.begin();
            ElementID first_element_freed_IDs  = *its;
            freed_IDs.erase(its);
            id_of_Package = first_element_freed_IDs;
            assigned_IDs.insert(id_of_Package);
        }
        _id = id_of_Package;
    };
    explicit Package(ElementID id): _id(id){
        assigned_IDs.insert(_id);
    }
    ElementID get_id() const {return _id;}

    Package(Package&& other ){ //: _id(std::move(other._id))
        _id = other._id;
        other._id = 0;
    };
    Package& operator=(Package&& other) {
        if(this!= &other) {
            delete[] &_id;
            _id = other._id;
            other._id = 0;
        }
        return *this;
    }
    ~Package(){
        std::set<ElementID>::iterator it = assigned_IDs.find(_id);
        if(it != assigned_IDs.end())
        {
            assigned_IDs.erase(it);
        }
        freed_IDs.insert(_id);
    };
private:
    ElementID _id;
    static std::set<ElementID> assigned_IDs;
    static std::set<ElementID> freed_IDs;
};

//std::set<ElementID> Package::assigned_IDs = {};
//std::set<ElementID> Package::freed_IDs = {};
