//
// Created by Lenovo on 22.12.2020.
//

#ifndef NETSIM_GRUPA_3_NODES_HPP
#define NETSIM_GRUPA_3_NODES_HPP
#define WITH_PROBABILITY_GENERATOR


#include <optional>
#include <memory>
#include "package.hpp"
#include "types.hpp"
#include "storage_types.hpp"
#include <map>
#include "helpers.hpp"
#include "config.hpp"

enum class ReceiverType{
    WORKER,
    STOREHOUSE
};

class IPackageReceiver{
public:
    cost_list_of_products lst_;
    using const_iterator = std::list<Package>::const_iterator;

    const_iterator begin() const {return lst_.begin();};
    const_iterator cbegin() const {return lst_.cbegin();};
    const_iterator end() const {return lst_.end();};
    const_iterator cend() const {return lst_.cend();};
    virtual void receive_package(Package&& p) = 0 ;
    virtual ElementID get_id() const = 0;

#if(defined EXERCISE_ID && EXERCISE_ID != EXERCISE_ID_NODES)
    virtual ReceiverType get_receiver_type() const = 0;
#endif
    virtual ~IPackageReceiver(){};
};


class ReceiverPreferences{
public:
    using preferences_t = std::map<IPackageReceiver*, double>;
    using const_iterator = preferences_t::const_iterator;
    ReceiverPreferences() : probability_(probability_generator), preferences_(){};
    ReceiverPreferences(ProbabilityGenerator probability) : probability_(probability), preferences_() {}

    const_iterator begin() const {return preferences_.begin();};
    const_iterator cbegin() const {return preferences_.cbegin();};
    const_iterator end() const {return preferences_.end();};
    const_iterator cend() const {return preferences_.cend();};

    void add_receiver(IPackageReceiver* add);

    void remove_receiver(IPackageReceiver* remove);

    IPackageReceiver *choose_receiver(void);

    const preferences_t& get_preferences(void) const;

    ProbabilityGenerator probability_;
    preferences_t preferences_;
};


class PackageSender{
public:
    PackageSender() : receiver_preferences_(probability_generator), pac(std::nullopt){}
    PackageSender(ProbabilityGenerator probability) : receiver_preferences_(probability), pac(std::nullopt){}
    PackageSender(PackageSender &&ps) = default;
    void send_package(){
        if(pac){
            receiver_preferences_.choose_receiver()->receive_package(std::move(pac.value()));
            pac.reset();
        }
    };
    std::optional<Package>& get_sending_buffer(){
        return pac;
    };
    ReceiverPreferences receiver_preferences_;
protected:
    std::optional<Package> pac;
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
        else if (t-t_ >=_di){ //t -t_ >=di_ sprawdzić czy bufor nie jest pełen
            push_package(Package());
            t_ = t;
        }
    };
    [[nodiscard]] TimeOffset get_delivery_interval() const {return _di;};
    [[nodiscard]] ElementID get_id() const {return _id;};
private:
    Time t_ = 1;
    ElementID _id;
    TimeOffset _di;
};



class Worker: public PackageSender, public IPackageReceiver{
public:

    Worker(ElementID id, TimeOffset pd, std::unique_ptr<IPackageQueue> q): id_(id), pd_(pd), q_(std::move(q)) {}
    cost_list_of_products lst_;
    void do_work(Time t);
    TimeOffset get_processing_duration() {return pd_;};
    Time get_package_processing_start() {return t_;};
    ElementID get_id() const {return id_;};
    void receive_package(Package&& p) {
        if (get_sending_buffer()) {
            pac_.push_back(std::move(p));
        } else {
            push_package(std::move(p));
        }
    };
#if(defined EXERCISE_ID && EXERCISE_ID != EXERCISE_ID_NODES)
    ReceiverType get_receiver_type() const {return ReceiverType::WORKER;};
#endif
private:
    ElementID id_;
    TimeOffset pd_;
    std::unique_ptr<IPackageQueue> q_;
    Time t_;
    std::vector<Package> pac_;
    int start_time_;
    int work_time_;
    std::optional<Package> w_bufor_;


};

class Storehouse: public IPackageReceiver{
public:
    Storehouse(ElementID id) : id_(id), d_(std::make_unique<PackageQueue>(PackageQueueType::LIFO)){}
    Storehouse(ElementID id, std::unique_ptr<IPackageStockpile> d): id_(id), d_(std::move(d)) {}
    ElementID get_id() const {return id_;};
    void receive_package(Package&& p) {d_->push(std::move(p));};
#if(defined EXERCISE_ID && EXERCISE_ID != EXERCISE_ID_NODES)
    ReceiverType get_receiver_type() const {return ReceiverType::STOREHOUSE;};
#endif
private:
    ElementID id_;
    std::unique_ptr<IPackageStockpile> d_;

};
#endif //NETSIM_GRUPA_3_NODES_HPP

//else if (int((t-1)/_di) >= (t-1)/_di){ //t -t_ >=di_ sprawdzić czy bufor nie jest pełen
//push_package(Package());
//t_ = t
//}