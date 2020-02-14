#include "lab2_drones_manager.h"
#include <iostream>

using namespace std;
// TODO: Implement all of the listed functions below

DronesManager::DronesManager() {
    first = NULL;
    last = NULL;
    size = 0;
}

DronesManager::~DronesManager() {
    DroneRecord* curr = first;
    while (curr){
        curr = curr->next;
        delete first;
        first = curr;
    }
    first = NULL;
    last = NULL;
    size = 0;
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
    return (lhs.prev == rhs.prev) && (lhs.next == rhs.next) && (lhs.droneID == rhs.droneID)
    && (lhs.range == rhs.range) && (lhs.yearBought == rhs.yearBought);
    return false;
    
}

unsigned int DronesManager::get_size() const {
    
    return size;
//    DroneRecord* temp = first;
//    int counter = 0;
//
//    if (!empty()){
//        while (temp) {
//            counter ++;
//            temp = temp -> next;
//        }
//        return counter;
//    }
//    return 0;
}

bool DronesManager::empty() const {
	return first == NULL && last == NULL && size == 0;
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
    DroneRecord* curr = first;
    
    if (curr == NULL) {
        return DroneRecord(0);
    } else if ((int)index < 0 || (int) index >= size) {
            return *last;
    } else {
        for (int i = 1; i <= (int)index; i++) {
            if (curr -> next)
                curr = curr->next;
//            else
//                return *curr;
        }
    }
    return *curr;
}

unsigned int DronesManager::search(DroneRecord value) const {
    
    DroneRecord* temp = first;
    unsigned int index = 0;
    
    if(empty())
        return 0; //increases run time for null lists

    do {
        if (*temp == value)
            return index;
        
        temp = temp -> next;
        index ++;
        
    }while(temp);//was temp != last (change to NULL)
    
    return size; //if the list is empty, size is set to zero anyway (no need for a condition operator)
}

void DronesManager::print() const {
    DroneRecord* temp = first;
    while (temp->next != NULL) {
        cout << temp->droneID << "  " << temp->range
        << "  " << temp->yearBought << "  " << temp->droneType
        << "  " << temp->manufacturer << "  " << temp->description
        << "  " << temp->batteryType << endl;
        temp = temp->next;
    }
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
    if (!first || index == 0) {
        insert_front(value);
        ++size;
        return true;
    }
    else {
        //DroneRecord* val = new DroneRecord(value);
        DroneRecord* curr = first;
        for (int i = 0; i < (int)index; i++) {
            if (!(curr->next)) {
                return false;
            }
            curr = curr->next;
        }
        value.prev = curr->prev;
        value.next = curr;
        ++size;
        return true;
    }
}

bool DronesManager::insert_front(DroneRecord value) {
    
    DroneRecord* temp = new DroneRecord(value);
    if (first){
        temp->next = first;
        temp->prev = NULL;
        first->prev = temp;
        first = temp;
        //should be our default copy constructor
        size++;
        return true;
    }
    else {
        temp->prev = NULL;
        temp->next = NULL;
        first = last = temp;
        size++;
        return true;
    }
    
	return false;
}

bool DronesManager::insert_back(DroneRecord value) {
    DroneRecord* val = new DroneRecord(value);
    if (last == NULL)
        first = val;
    else {
        val->prev = last;
        last->next = val;
    }
    val->next = NULL;
    last = val;
    size++;
    return true;
}

bool DronesManager::remove(unsigned int index) {
    if (index == 0) {
        remove_front();
    }
    DroneRecord* curr = first;
    if (!curr) {
        return false;
    }
    for (int i = 0; i < (int)index; i ++) {
        if (!(curr->next)) {
            remove_back();
            --size;
            return true;
        }
    }
    DroneRecord* back = curr->prev;
    back->next = curr->next;
    delete curr;
    curr = NULL;
    --size;
    return true;
}

bool DronesManager::remove_front() {
    
    DroneRecord* newFront (first ? first: NULL);

    if (!first)
        return false;

    if (!first -> next){
        delete first;
        first = last = NULL;
    }
    else {
        delete first;
        first = newFront;
        newFront -> prev = NULL;
    }

    size --;
    return true;
}

bool DronesManager::remove_back() {
    if (last == NULL)
        return false;
    if (first == last){
        delete first;
        first = last = NULL;
    }
    else{
        DroneRecord* temp = last;
        last = last->prev;
        delete temp;
        temp = NULL;
        last->next = NULL;
    }
    
    size--;
    return true;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
    if (!first) {
        return false;
    }
    else {
        DroneRecord* curr = first;
        for (int i = 0; i < (int)index && curr; i++) {
            if (!curr -> next) {
                return false;
            }
            curr = curr->next;
            
        }
        *curr = value;
        
        return true;
    }
}

bool DronesManager::reverse_list() {
	bool DronesManager::reverse_list() {
	if (!first) {
		return false;
	}
	else {
		DroneRecord* curr = first;
		DroneRecord* next = NULL;
		DroneRecord* prev = curr->prev;

		while (curr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		first = prev;
		return true;
	}
}
}
