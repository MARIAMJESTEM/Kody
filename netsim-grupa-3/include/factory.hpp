//
// Created by filip on 30.12.2020.
//

#ifndef NETSIM_GRUPA_3_FACTORY_HPP
#define NETSIM_GRUPA_3_FACTORY_HPP

#include "nodes.hpp"
#include "types.hpp"

template <typename Node>
class NodeCollection{
public:
    using container_t = typename std::list<Node>;
    using iterator = typename container_t::iterator;
    using const_iterator = typename container_t::const_iterator;
    iterator begin() {return vec_.begin();};
    const_iterator cbegin() const {return vec_.cbegin();};
    iterator end() {return vec_.end();};
    const_iterator cend() const {return vec_.cend();};

    void add(Node&& node) {vec_.push_back(std::move(node));};
    void remove_by_id(ElementID id){
        for (iterator i = vec_.begin(); i == vec_.end(); i++){
            if (i -> get_id() == id){
                vec_.erase(i);
            }
        }
    };
    iterator find_by_id(ElementID id) {
        for (iterator i = vec_.begin(); i == vec_.end(); i++){
            if (i -> get_id() == id) {
                return i;
            }
        }
        return vec_.end();
    };
    const_iterator find_by_id(ElementID id) const{
        for (const_iterator i = vec_.cbegin(); i == vec_.cend(); i++){
            if (i -> get_id() == id){
                return i;
            }
        }
        return vec_.cend();
    };

private:
    container_t vec_;

};



class Factory{
public:
    Factory(){}

    void add_ramp(Ramp&& r) {ramps_.add(std::move(r));};
    void remove_ramp(ElementID id) {ramps_.remove_by_id(id);};
    NodeCollection<Ramp>::iterator find_ramp_by_id(ElementID id) {return ramps_.find_by_id(id);};
    NodeCollection<Ramp>::const_iterator find_ramp_by_id(ElementID id)const {return ramps_.find_by_id(id);};
    NodeCollection<Ramp>::const_iterator ramp_cbegin() {return ramps_.cbegin();};
    NodeCollection<Ramp>::const_iterator ramp_cend() {return ramps_.cend();};

    void add_worker(Worker&& r) {workers_.add(std::move(r));};
    void remove_worker(ElementID id) {workers_.remove_by_id(id);remove_receiver(workers_,id);};
    NodeCollection<Worker>::iterator find_worker_by_id(ElementID id) {return workers_.find_by_id(id);};
    NodeCollection<Worker>::const_iterator find_worker_by_id(ElementID id)const {return workers_.find_by_id(id);};
    NodeCollection<Worker>::const_iterator worker_cbegin() {return workers_.cbegin();};
    NodeCollection<Worker>::const_iterator worker_cend() {return workers_.cend();};

    void add_storehouse(Storehouse&& r) {storehouse_.add(std::move(r));};
    void remove_storehouse(ElementID id) {storehouse_.remove_by_id(id);remove_receiver(storehouse_,id);};
    NodeCollection<Storehouse>::iterator find_storehouse_by_id(ElementID id) {return storehouse_.find_by_id(id);};
    NodeCollection<Storehouse>::const_iterator find_storehouse_by_id(ElementID id )const {return storehouse_.find_by_id(id);};
    NodeCollection<Storehouse>::const_iterator storehouse_cbegin() {return storehouse_.cbegin();};
    NodeCollection<Storehouse>::const_iterator storehouse_cend() {return storehouse_.cend();};

    bool is_consistent();
    void do_deliveries(Time t);
    void do_package_passing(void);
    void do_work(Time t);


private:
    NodeCollection<Ramp> ramps_;
    NodeCollection<Worker> workers_;
    NodeCollection<Storehouse> storehouse_;

    template<typename Node>
    void remove_receiver(NodeCollection<Node>& collection, ElementID id) {
        auto del = collection.find_by_id(id);
        for (auto& ramp : ramps_){
            ramp.receiver_preferences_.remove_receiver(&(*del));
        }
        for (auto& worker : workers_){
            worker.receiver_preferences_.remove_receiver(&(*del));
        }
    }
};

enum class NodeColor { UNVISITED, VISITED, VERIFIED };
bool has_reachable_storehouse(const PackageSender* sender, std::map<const PackageSender*, NodeColor>& node_colors);

#endif