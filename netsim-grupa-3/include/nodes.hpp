//
// Created by Lenovo on 22.12.2020.
//

#ifndef NETSIM_GRUPA_3_NODES_HPP
#define NETSIM_GRUPA_3_NODES_HPP


#include <optional>
#include <memory>
#include "package.hpp"
#include "types.hpp"
#include "storage_types.hpp"
class IPackageReceiver{
public:
    virtual void receive_package(Package&& p) = 0;
    virtual ElementID get_id() = 0;
};

class ReceiverPreferences{
public:
    void add_receiver(IPackageReceiver* r){};
};

class PackageSender: public ReceiverPreferences{
public:
    PackageSender(){};
    std::optional<Package> pac;
    PackageSender(PackageSender &&ps) = default;
    void send_package(){
        if(pac){
            auto receiver = receiver_preferences_.choose_receiver();
            pac.reset();
        }
    };
    std::optional<Package>& get_sending_buffer(){
        return pac;
    };
    ReceiverPreferences receiver_preferences_;
protected:
    void push_package(Package&& p){
        pac.emplace(std::move(p));
    };
};

class Ramp: public PackageSender{
public:
    Ramp(ElementID id, TimeOffset di) : _id(id), _di(di) {};
    void deliver_goods(Time t){
        if(t == 1) {
            push_package(Package());
        }
        else if (int((t-1)/_di) >= (t-1)/_di){ //t -t_ >=di_ sprawdzić czy bufor nie jest pełen
            push_package(Package());
            //t_ = t
        }
    };
    [[nodiscard]] TimeOffset get_delivery_interval() const {return _di;};
    [[nodiscard]] ElementID get_id() const {return _id;};
private:
    Time t_ = 1;
    ElementID _id;
    TimeOffset _di;
};

class Storehouse: public IPackageStockpile{
public:
    Storehouse(ElementID id, std::unique_ptr<IPackageStockpile> d): _id(id){};
    ElementID get_id() const{return _id;};
private:
    ElementID _id;
    //std::unique_ptr<IPackageStockpile> _d;
};
#endif //NETSIM_GRUPA_3_NODES_HPP