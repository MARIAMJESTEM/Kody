//
// Created by Lenovo on 28.12.2020.
//
#include "storage_types.hpp"
#include <list>

Package PackageQueue::pop(){
    Package g;
    switch(queue_type_){
        case (PackageQueueType::FIFO) : {
            g = std::move(lst_.front());
            lst_.pop_front();
            break;
        }
        case (PackageQueueType::LIFO) : {
            g = std::move(lst_.front());
            lst_.pop_back();
            break;
        }
        default:
            throw std::logic_error("Wybrano zły typ kolejnki");

    }return g;
}
