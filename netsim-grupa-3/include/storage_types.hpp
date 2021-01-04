//
// Created by filip on 18.12.2020.
//

#ifndef NET_SIMULATION_STORAGE_TYPES_HPP
#define NET_SIMULATION_STORAGE_TYPES_HPP


#include <list>
#include <algorithm>
#include <iterator>
#include "package.hpp"


enum class PackageQueueType{
    FIFO,
    LIFO
};


using cost_list_of_products = std::list<Package>;


class IPackageStockpile{
public:
    using const_iterator = std::list<Package>::const_iterator;

    const_iterator begin() const {return lst_.begin();};
    const_iterator cbegin() const {return lst_.cbegin();};
    const_iterator end() const {return lst_.end();};
    const_iterator cend() const {return lst_.cend();};

    virtual void push(Package&&) = 0;
    virtual bool empty() = 0;
    virtual std::size_t size() = 0;

    ~IPackageStockpile() = default;
protected:
    std::list<Package> lst_;
};

class IPackageQueue: public IPackageStockpile{
public:
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() = 0;
};


class PackageQueue : public IPackageQueue {
public:
    PackageQueue(PackageQueueType s) : queue_type_(s) {}

    std::size_t size() { return lst_.size(); };
    bool empty() { return lst_.empty(); };
    void push(Package&& p) { lst_.emplace_back(std::move(p)); };
    Package pop();
    PackageQueueType get_queue_type() {return queue_type_; };


private:
    cost_list_of_products lst_;
    PackageQueueType queue_type_;

};
#endif //NET_SIMULATION_STORAGE_TYPES_HPP