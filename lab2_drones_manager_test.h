#ifndef DRONES_MANAGER_TEST
#define DRONES_MANAGER_TEST

#include "lab2_drones_manager.h"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class DronesManagerTest {
public:
	// PURPOSE: New empty list is valid
	bool test1() {
		DronesManager manager;
		ASSERT_TRUE(manager.get_size() == 0)
		ASSERT_TRUE(manager.empty() == true)
		ASSERT_TRUE(manager.first == NULL)
		ASSERT_TRUE(manager.last == NULL)
	    return true;
	}
	
	// PURPOSE: insert_front() and insert_back() on zero-element list
	bool test2() {
		DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager2.insert_back(DronesManager::DroneRecord(100));
	    
		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 1)
		ASSERT_TRUE(manager1.first != NULL && manager1.first == manager1.last)
		ASSERT_TRUE(manager2.first != NULL && manager2.first == manager2.last)
		ASSERT_TRUE(manager1.first->prev == NULL && manager1.last->next == NULL)
		ASSERT_TRUE(manager2.first->prev == NULL && manager2.last->next == NULL)
		ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(100))		
	    return true;
	}
	
	// TODO: Implement all of the test cases below
	
	// PURPOSE: select() and search() work properly
	bool test3() {
		    manager1.insert_front(DronesManager::DroneRecord(100));

	//        ASSERT_TRUE(manager1.select(-1) == manager1.select(manager1.get_size() - 1));
	//        ASSERT_TRUE(manager1.select(2) == manager1.select(manager1.get_size() - 1));

		//rASSERT_TRUE(manager1.select(-1) == *(manager1.last));
		//ASSERT_TRUE(manager1.select(2) == *(manager1.last));//does the same things as the above line

		//ASSERT_TRUE(manager1.select(0) == DronesManager::DroneRecord(100));
		//manager1.insert_front(DronesManager::DroneRecord(200));
		//ASSERT_TRUE(manager1.select(1)== DronesManager::DroneRecord(200));

		DronesManager::DroneRecord record1;
		ASSERT_TRUE(manager1.search(record1) == manager1.get_size());//tests a record not added to the list0
		ASSERT_TRUE(manager1.search(manager1.get_size() - 1) == manager1.search(*(manager1.last))); //tests if it can find the last node
		ASSERT_TRUE(manager1.search(*(manager1.first)) == manager1.search(*(manager1.first)));

		return true;
	}
	
	// PURPOSE: remove_front() and remove_back() on one-element list
	bool test4() {
	     DronesManager manager1;
        
		ASSERT_TRUE(manager1.remove_front() == false);//tests empty lists
		ASSERT_TRUE(manager1.remove_back() == false);//tests empty lists

		manager1.insert_front(DronesManager::DroneRecord(100));

		ASSERT_TRUE(manager1.remove_front() == true);
		ASSERT_TRUE(manager1.first == NULL);
		ASSERT_TRUE(manager1.last == NULL);
		ASSERT_TRUE(manager1.size == 0);

		manager1.insert_front(DronesManager::DroneRecord(100));
		ASSERT_TRUE(manager1.remove_back() == true);
		ASSERT_TRUE(manager1.first == NULL);
		ASSERT_TRUE(manager1.last == NULL);
		ASSERT_TRUE(manager1.size == 0);
        
	    return true;
	}
	
	// PURPOSE: replace() and reverse_list() work properly
	bool test5() {
	    return false;
	}
	
	// PURPOSE: insert_front() keeps moving elements forward
	bool test6() {
	    return false;
	}
	
	// PURPOSE: inserting at different positions in the list
	bool test7() {
	    return false;
	}
	
	// PURPOSE: try to remove too many elements, then add a few elements
	bool test8() {
	    return false;
	}
	
	// PURPOSE: lots of inserts and deletes, some of them invalid
	bool test9() {
		  DronesManager manager1;
		ASSERT_TRUE (manager1.insert(DronesManager::DroneRecord(100),-1) == false);
		ASSERT_TRUE (manager1.insert(DronesManager::DroneRecord(100),2) == false);
		ASSERT_TRUE (manager1.insert(DronesManager::DroneRecord(100),0) == true);

		manager1.insert_front(DronesManager::DroneRecord(100));
		ASSERT_TRUE (manager1.insert(DronesManager::DroneRecord(100),2) == false); //is this valid?

		ASSERT_TRUE (manager1.remove(2) == false);
		ASSERT_TRUE(manager1.remove(-1) == false);
		ASSERT_TRUE(manager1.remove(0) == true);
        
		return true;
	}    
	    	
	// PURPOSE: lots of inserts, reverse the list, and then lots of removes until empty
	bool test10() {
	   return false;
	} 
};

#endif
