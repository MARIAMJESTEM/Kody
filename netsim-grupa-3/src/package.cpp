//
// Created by Lenovo on 28.12.2020.
//

#include "package.hpp"

std::set<ElementID> Package::assigned_IDs = {};
std::set<ElementID> Package::freed_IDs = {};
//jeśli id =-1 to wtedy nie wstawiamy do freedids ewentualnie możemy wstawić ale wtedy w konstruktorze trzeba obsłużyć ten przypadek

Package::Package() {
    if(freed_IDs.empty())
    {   if (!assigned_IDs.empty()) {
            ElementID last_element_assigned_IDs  = *assigned_IDs.rbegin();
            _id = last_element_assigned_IDs + 1;
            assigned_IDs.insert(_id);
        }
        else{
            _id =1;
            assigned_IDs.insert(_id);
        }
    }
    else{
        std::set<ElementID>::iterator its = freed_IDs.begin();
        ElementID first_element_freed_IDs  = *its;
        freed_IDs.erase(its);
        _id = first_element_freed_IDs;
        assigned_IDs.insert(_id);
    }

}

Package::Package(Package&& other) noexcept {
    _id = other._id;
    other._id = -1;
}


Package& Package::operator = (Package&& other){
    _id =other._id;
    other._id = -1;
    return *this;
}

Package::Package(ElementID id):_id(id){
        assigned_IDs.insert(_id);
}

Package::~Package() {
    if (_id != -1) {
        freed_IDs.insert(_id);
        assigned_IDs.erase(_id);
    }else{
        assigned_IDs.erase(_id);
    }

}

