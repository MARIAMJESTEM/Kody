//
// Created by admin on 02.01.2021.
//

#include "nodes.hpp"
#include <iostream>
#include <map>
#include <vector>
#include <iterator>

void ReceiverPreferences::add_receiver(IPackageReceiver* add){
    preferences_.insert(std::pair<IPackageReceiver*, double>(add, 0));
    double y = 1.0/preferences_.size();
    for (auto& prob : preferences_){
        prob.second = y;
    }
}

void ReceiverPreferences::remove_receiver(IPackageReceiver* remove){
    preferences_.erase(remove);
    double y = 1.0/preferences_.size();
    for (auto& prob : preferences_){
        prob.second = y;
    }
}

IPackageReceiver* ReceiverPreferences::choose_receiver(void){

    double sum = 0.0;
    double chosen_one = probability_();
    for (auto& prob : preferences_) {
        sum += prob.second;
        if (sum >= chosen_one){
            return prob.first;
        }
    }return preferences_.rbegin()->first;
}

const ReceiverPreferences::preferences_t& ReceiverPreferences::get_preferences(void) const{
    return preferences_;
}
void Worker::do_work(Time t) {
    if (!w_bufor_ && !q_->empty()) {
        w_bufor_.emplace(q_->pop());
        start_time_ = t;
        work_time_ = 0;

    }

    if (w_bufor_) {
        work_time_++;
        if (t == work_time_ + start_time_) {
            push_package(std::move(w_bufor_.value()));
            w_bufor_.reset();
            work_time_ = 0;
        }
    }
}