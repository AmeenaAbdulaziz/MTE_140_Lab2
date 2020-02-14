#include "lab2_drones_manager.h"

// TODO: Implement all of the listed functions below

DronesManager::DronesManager() {
}

DronesManager::~DronesManager() {
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	return false;
}

unsigned int DronesManager::get_size() const {
	return size;
}

bool DronesManager::empty() const {
	return false;
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
	return DroneRecord();
}

unsigned int DronesManager::search(DroneRecord value) const {
	DroneRecord* temp = first;
    unsigned int index = 0;
    
//    if(empty())
//        return 0;
//
    do {
        if (*temp == value)
            return index;
        
        temp = temp -> next;
        index ++;
        
    }while(temp != last);
    
    return size; //if the list is empty, size is set to zero anyway (no need for a condition operator)
}

void DronesManager::print() const {
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
	return false;
}

bool DronesManager::insert_front(DroneRecord value) {
	 if (first){
        value.next = first;
        value.prev = NULL;
        first = new DroneRecord(value); //should be our default copy constructor
        first->next->prev = first;
        size++;
        return true;
    }
    else {
        value.prev = NULL;
        value.next = NULL;
        first = last = new DroneRecord(value);
        size++;
        return true;
    }
    
	return false;
}

bool DronesManager::insert_back(DroneRecord value) {
	return false;
}

bool DronesManager::remove(unsigned int index) {
	return false;
}

bool DronesManager::remove_front() {
	DroneRecord* front = first;
    
    if (!first)
        return false;
    
    first = first -> next;
    
    if (first -> next)
        first -> next -> prev = NULL;
    
    delete front;
	size --;
    return true;
}

bool DronesManager::remove_back() {
	return false;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
	return false;
}

bool DronesManager::reverse_list() {
	return false;
}

