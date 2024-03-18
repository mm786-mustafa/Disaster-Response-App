//contactManager.h

#ifndef ContactManager_h
#define ContactManager_h
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class ContactManager 
{
	private:
	    struct ContactInfo {
	        string name;
	        int number;
	    };
	
	    string EmergDepsArr[11] = {"EMERGENCY-HELPLINE", "POLICE", "FIRE-BRIGADE",
	                               "NACTA-HELPLINE",
	                               "BOMB-DISPOSAL", "EDHI-AMBULANCE", "EDHI-CENTRE",
	                               "PIMS-HOSPITAL", "CDA-HOSPITAL", "SHIFA-HOSPITAL",
	                               "ALI-MEDICAL"};
	
	    int EmergNumsArr[11] = {15, 9100008, 16, 1717, 1332, 115, 2827844, 9261223, 9230418, 4603666, 2255315};
	
	    queue<ContactInfo> contacts;  // Queue to store and update contact information
	
	public:
	    void viewContacts() const {
	        cout << "--------------------EMERGENCY CONTACT--------------------\n";
	        for (int i = 0; i < 11; ++i) {
	            cout << EmergDepsArr[i] << ": " << EmergNumsArr[i] << endl;
	        }
	        cout<<endl;
	    }
	
	    void updateContacts() {
	        string contactName;
	        int newContactNumber;
	
	        cout<<"\nENTER NAME OF CONTACT TO UPDATE: ";
	        cin >> contactName;
	
	        int index = -1;
	        for (int i = 0; i < 11; ++i) {
	            if (EmergDepsArr[i] == contactName) {
	                index = i;
	                break;
	            }
	        }
	
	        if (index != -1) 
			{
	            cout << "ENTER NEW CONTACT NO. FOR " << contactName << ": ";
	            cin >> newContactNumber;
	
	            EmergNumsArr[index] = newContactNumber;
	
	            // Update the contact number in the queue
	            ContactInfo updatedContact = {contactName, newContactNumber};
	            contacts.push(updatedContact);
	
	            cout << "CONTACT UPDATED SUCCESSFULLY" << endl;
	        } else {
	            cout << "CONTACT NOT FOUND." << endl;
	        }
	    }
	
	    void displayUpdatedContacts()  {
	        if (!contacts.empty()) {
	            cout << "\n-----------UPDATED CONTACTS-----------\n";
	            queue<ContactInfo> tempQueue = contacts;  // Create a copy to avoid modifying the original
	            while (!tempQueue.empty()) {
	                ContactInfo contact = tempQueue.front();
	                cout << contact.name << ": " << contact.number << endl;
	                tempQueue.pop();
	            }
	        } else {
	            cout << "NO CONTACTS HAVE BEEN UPDATED" << endl;
	        }
	    }
};



#endif


