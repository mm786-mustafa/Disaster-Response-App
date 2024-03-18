// Notification.h
#ifndef Notification_h
#define Notification_h

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Notification 
{
	private:
	    stack <string> notifications;
	
	public:
	    void addNotification(const string& notification, int access) {
	        if (access == 2) {
	            // Admin access: Add notification to the stack
	            notifications.push(notification);
	            cout << "Notification added by admin: " << notification << endl;
	        } else {
	            cout << "User does not have permission to add notifications." << endl;
	        }
	    }
	
	    void viewNotifications() const {
	        if (!notifications.empty()) {
	            cout << "Notifications:\n";
	            stack<string> tempStack = notifications;
	
	            while (!tempStack.empty()) {
	                cout << tempStack.top() << endl;
	                tempStack.pop();
	            }
	        } else {
	            cout << "No notifications available." << endl;
	        }
	    }
};


#endif

