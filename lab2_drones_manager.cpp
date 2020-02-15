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
        if (first)
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
    if (index > size) {
        return false;
    } else if (!first || index == 0) {
        return insert_front(value);
    } else if (index == size) {
        return insert_back(value);
    } else {
        DroneRecord* val = new DroneRecord(value);
        DroneRecord* curr = first;
        for (int i = 1; i <= (int)index; i++) {
            curr = curr->next;
        }
        val -> prev = curr->prev;
        val -> next = curr;
        ++size;
        return true;
    }
}

bool DronesManager::insert_front(DroneRecord value) {
    
    DroneRecord* temp = new DroneRecord(value);
    if (first) {
        temp->next = first;
        temp->prev = NULL;
        first->prev = temp;
        first = temp;
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
        if (!first) {
            return false;
        } else if (index == 0) {
            return remove_front();
        } else if ((int)index < 0 || (int) index >= size) {
            return false;
        } else if ((int)index == size - 1) {
            return remove_back();
        } else{
            DroneRecord* curr = first;
            for (int i = 1; i < (int)index; i ++) {
                curr = curr -> next;
            }
            DroneRecord* back = curr -> prev;
            back->next = curr->next;
            delete curr;
            curr = NULL;
        }
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
    if (!first || index >= size || index < 0) {
        return false;
    }
    else {
        DroneRecord* curr = first;
        DroneRecord* val = new DroneRecord(value);
        
        for (int i = 0; i < (int)index; i++) {
            curr = curr->next;
        }
        
        val->next = curr->next;
        val->prev = curr->prev;
        if (val->prev)
            val->prev->next = val;
        if (val->next)
            val->next->prev = val;
        delete curr;
        
        curr = NULL;
        if (index == 0)
            first = val;
        if (index == size - 1)
            last = val;
        return true;
    }
}

bool DronesManager::reverse_list() {
    if (!first) {
        return false;
    }
    else {
        DroneRecord* curr = first;
        DroneRecord* tempNext = NULL;
        DroneRecord* tempPrev = curr->prev;
        last = first;
        
        while (curr) {
            tempNext = curr->next;
            curr->next = tempPrev;
            curr->prev = tempNext;
            tempPrev = curr;
            curr = tempNext;
        }
        first = tempPrev;
        first->prev = NULL;
        last->next = NULL;
        
    }
    return true;
}


