#include "lab2_drones_manager.hpp"
#include <iostream>

// TODO: Implement all of the listed functions below

DronesManager::DronesManager() {
}

DronesManager::~DronesManager() {
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	return (lhs.prev == rhs.prev) && (lhs.next == rhs.next) && (lhs.droneID == rhs.droneID) 
		&& (lhs.range == rhs.range) && (lhs.yearBought == rhs.yearBought);
}

unsigned int DronesManager::get_size() const {
	DroneRecord* curr = first;
	int count = 0;
	while (curr) {
		count++;
		curr = curr->next;
	}
	return count;
}

bool DronesManager::empty() const {
	return false;
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

		temp = temp->next;
		index++;

	} while (temp != last);

	return size; //if the list is empty, size is set to zero anyway (no need for a condition operator)
}

void DronesManager::print() const {
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
	if (index > size) {
		return false;
	} else if (!first || index == 0) {
		insert_front(value);
		return true;
	} else if (index == size) {
		insert_back(value);
	} else {
		DroneRecord* val = new DroneRecord(value);
		DroneRecord* curr = first;
		for (int i = 0; i < (int)index; i++) {
			curr = curr->next;
			cout << index;
		}
		val -> prev = curr->prev;
		val -> next = curr;
		++size;
		return true;
	}
}

bool DronesManager::insert_front(DroneRecord value) {
	if (!first) {
		first = new DroneRecord(value);
		first -> next = NULL;
		first->prev = NULL;
		size++;
		cout << "hi";
		return true;
	}
	else {
		value.next = first;
		value.prev = NULL;
		first = new DroneRecord(value); //should be our default copy constructor
		first->next->prev = first;
		size++;
		return true;
	}

	return false;
}

bool DronesManager::insert_back(DroneRecord value) {
	return false;
}

bool DronesManager::remove(unsigned int index) {
	if (!first) {
		return false;
	}
	else {
		if (index == 0) {
			return remove_front();
		}
		else if (index >= size - 1) {
			return remove_back();
		} else {
			DroneRecord* curr = first;
			for (int i = 0; i <= (int)index; i++) {
				curr = curr->next;
			}
			DroneRecord* back = curr->prev;
			back->next = curr->next;
			delete curr;
			curr = NULL;
			--size;
			cout << size;
			return true;
		}
	}
}

bool DronesManager::remove_front() {
	DroneRecord* front = first;

	if (!first)
		return false;

	first = first->next;

	if (first->next)
		first->next->prev = NULL;

	delete front;
	return true;
}

bool DronesManager::remove_back() {
	return false;
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

