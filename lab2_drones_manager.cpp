#include "lab2_drones_manager.h"

// TODO: Implement all of the listed functions below

DronesManager::DronesManager() {
}

DronesManager::~DronesManager() {
	delete first;
	first = NULL;
	delete last;
	last = NULL;
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	return (lhs.prev == rhs.prev) && (lhs.next == rhs.next) && (lhs.droneID == rhs.droneID) 
		&& (lhs.range == rhs.range) && (lhs.yearBought == rhs.yearBought);
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
	} else {
		for (int i = 1; i < (int)index && curr; i++) {
			curr = curr->next;
		}
	}
	return *curr;
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
		DroneRecord* val = new DroneRecord(value);
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
	if (last == NULL)
		return false;
	DroneRecord* temp = last;
	last = last->prev;
	last->next = NULL;
	delete temp;
	temp = NULL;
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
	return false;
}

