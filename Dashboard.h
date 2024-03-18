// Dashboard.h
#ifndef Dashboard_h
#define Dashboard_h

#include <iostream>
#include <stack>
#include <string>
#include <vector>


using namespace std;

struct Dashboard 
{
    string type;
    string location;
    string status;
    string additionalDetails;
};

// Function to display emergencies on the admin dashboard
void displayEmergencies(const vector<Dashboard>& emergencies, bool showDetails) {
    cout << "Admin Dashboard - Emergency Status\n";
    cout << "---------------------------------\n";
    for (size_t i = 0; i < emergencies.size(); ++i) {
        const Dashboard& e = emergencies[i];
        cout << "Index: " << i << "\tType: " << e.type << "\tLocation: " << e.location << "\tStatus: " << e.status;

        if (showDetails) {
            cout << "\tAdditional Details: " << e.additionalDetails;
        }

        cout << endl;
    }
    cout << "---------------------------------\n";
}



// Function to send approval message to the user
void sendApprovalMessage(const string& user) 
{
    cout << "Help is on the way! Emergency forwarded for user: " << user << endl;
}

// Function to approve an emergency request by changing its status
void approveEmergency(vector<Dashboard>& emergencies, size_t index) 
{
    if (index < emergencies.size()) 
	{
        emergencies[index].status = "Approved";
        cout << "Emergency request approved!\n";
    } 
	else 
	{
        cout << "Invalid index. Emergency request not found.\n";
    }
}



#endif

