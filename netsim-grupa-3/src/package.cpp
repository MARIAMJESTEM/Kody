//
// Created by Lenovo on 28.12.2020.
//

#include "package.hpp"

std::set<ElementID> Package::assigned_IDs = {};
std::set<ElementID> Package::freed_IDs = {};
//jeśli id =-1 to wtedy nie wstawiamy do freedids ewentualnie możemy wstawić ale wtedy w konstruktorze trzeba obsłużyć ten przypadek

Package::Package() {
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
}
Package::Package(Package&& other){
    _id = other._id;
    other._id = -1;
}

Package::~Package(){
    std::set<ElementID>::iterator it = assigned_IDs.find(_id);
    if(it != assigned_IDs.end())
    {
        assigned_IDs.erase(it);
    }
    freed_IDs.insert(_id);
}
Package& Package::operator = (Package&& other){
    if(this!= &other) {
        //delete[] &other._id;
        _id = other._id;
        other._id = -1;
    }
    return *this;
}
