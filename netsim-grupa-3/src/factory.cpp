//
// Created by filip on 30.12.2020.
//

#include "factory.hpp"
#include <map>
bool has_reachable_storehouse(const PackageSender* sender, std::map<const PackageSender*, NodeColor>& node_colors){
    for (auto& colors : node_colors){
        if (colors.first == sender){
            if (colors.second == NodeColor::VERIFIED) {
                return true;
            }
        }
    }
    node_colors[sender] = NodeColor::VISITED;

    auto send = &sender->receiver_preferences_.get_preferences();
    if (send->empty()){
        throw std::logic_error("Nadawca nie posiada żadnego połączenia wyjściowego");
    }
    bool not_itself = false;
    for (auto& elem : *send){
        if (elem.first->get_receiver_type() == ReceiverType::STOREHOUSE){
            not_itself = true;
        }else if (elem.first->get_receiver_type() == ReceiverType::WORKER){
            IPackageReceiver* const *receiver_ptr = &elem.first;
            auto worker_ptr = dynamic_cast<Worker*>(*receiver_ptr);
            auto sendrecv_ptr = dynamic_cast<PackageSender*>(worker_ptr);
            if (sendrecv_ptr == sender){
                continue;
            }
            not_itself = true;
            if (node_colors[sendrecv_ptr] == NodeColor::UNVISITED){
                has_reachable_storehouse(sendrecv_ptr, node_colors);
            }
        }
    }
    node_colors[sender] = NodeColor::VERIFIED;
    if (not_itself) {return true;}
    else{throw std::logic_error("Nadawca nie ma Storehousu byczq");}
}

void Factory::do_deliveries(Time t){
    for (auto& ramps : ramps_){
        ramps.deliver_goods(t);
    }
}
void Factory::do_package_passing(void){
    for (auto& ramps : ramps_){
        ramps.send_package();
    }
    for(auto& workers : workers_){
        workers.send_package();
    }
}

void Factory::do_work(Time t){
    for (auto& workers : workers_){
        workers.do_work(t);
    }
}

bool Factory::is_consistent() {
    std::map<const PackageSender*, NodeColor> senders;
    for (auto& ramp : ramps_){
        senders.insert(std::pair<PackageSender*, NodeColor>(&ramp, NodeColor::UNVISITED));
    }
    for (auto& work : workers_){
        senders.insert(std::pair<PackageSender*, NodeColor>(&work, NodeColor::UNVISITED));
    }
    try {
        for (auto& ramp : ramps_) {
            has_reachable_storehouse(&ramp, senders);
        }
    }catch (std::logic_error&){
        return false;
    }return true;
}

