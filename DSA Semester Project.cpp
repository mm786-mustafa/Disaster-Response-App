#include<iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include"User.h"
#include"Admin.h"
#include"Notification.h"
#include"ContactManager.h"
#include"EmergencyTree.h"
#include"EmergencyInfoTree.h"
#include"Dashboard.h"
#include"Shortest_Route.h"

using namespace std;

int main()
{
	int ch;
	Notification notificationManager;
	ContactManager contactManager;
	EmergencyTree emergencyTree; //emergencies in your city tree
	//EmergencyInfoTree infoTree; // emergency guide information stored
	
	vector<Dashboard> emergencies;
	
	do
	{
		cout<<"\n-----WELCOME TO DISASTER RESPONSE APP-----\n";
		cout<<"1. USER \t 2. ADMIN \t 3. EXIT\n";
		cin>>ch;
		
		
		
		if(ch==1)
		{
			//user
			cin.ignore();
			cout << "ENTER YOUR NAME: ";
	        string userName;
	        getline(cin, userName);
			
			
			int opt;
			do
			{
				cout<<"\nSELECT AN OPTION:\n";
				cout<<"1. EMERGENCY REQUEST \t2. EMERGENCY NUMBERS\n"; 
				cout<<"3. EMERGENCY GUIDE \t4. REQUEST STATUS\n";
				cout<<"5. EMERGENCIES IN YOUR CITY \t6. NOTIFICATIONS\n";
				cout<<"7. EXIT\n";
				cin>>opt;
				cin.ignore();
				
				if(opt==1)
				{
					//emergencyRequest();
					int rtrn;
					do
					{
						cout << "ENTER THE TYPE OF EMERGENCY: ";
				        string emergencyType;
				        getline(cin, emergencyType);
				
				        cout << "ENTER YOUR LOCATION: ";
				        string location;
				        getline(cin, location);
						
						DijkstrasTest(location,emergencyType);
						cout<<endl;
						
						cout << "Do you want to provide additional details about the emergency? (yes/no): ";
				        string provideDetails;
				        getline(cin, provideDetails);
				
				        string additionalDetails;
				        if (provideDetails == "yes") {
				            cout << "Enter additional details: ";
				            getline(cin, additionalDetails);
				        } 
				        emergencies.push_back({emergencyType, location, "Pending", additionalDetails});
				        
				        cout << "\n\n(enter 1 to return to user board)";
				        cin>>rtrn;
				        cin.ignore();
						
					}while(rtrn!=1);

				}
				
				else if(opt==2)
				{
					contactManager.viewContacts();
				}
				
				else if(opt==3)
				{
					emergencyGuide();
				}
				else if(opt==4)
				{
					//requestStatus();
					sendApprovalMessage(userName);
				}
				else if(opt==5)
				{
					emergencyTree.displayEmergencies();
				}
				else if(opt==6)
				{
					notificationManager.viewNotifications();
				}
				
				else if(opt==7)
				{
					break;
				}
				else
				{
					cout<<"Please Select a Valid Option !!";
				}
				

			}while(opt!=7);

		}
		else if(ch==2)
		{
			//admin
			int opt;
			
			int shift = 3;

		    // Store a password
		    string storedPassword = encryptPassword("shumail12", shift);
		    //cout << "Stored Password: " << storedPassword << endl;
		
		    // Verify a user-entered password
		    int pass;
		    do
		    {
		    	string enteredPassword;
			    cout << "ENTER PASSWORD: ";
			    cin >> enteredPassword;
			    
		    	if (verifyPassword(storedPassword, enteredPassword, shift)) 
				{
			        cout << "PASSWORD CORRECT. ACCESS GRANTED." << endl;
			        
			        do
					{
						cout<<"\nSELECT AN OPTION:\n";
						cout<<"1. DASHBOARD\t2. REQUEST MANAGEMENT\n"; 
						cout<<"3. ADD/EDIT CITY EMERGENCIES \t4. EDIT EMERGENCY NUMBERS\n";
						cout<<"5. SEND NOTIFICATION\n";
						cout<<"6. EXIT\n";
						cin>>opt;
						
						if(opt==1)
						{
							//dashboard();
							displayEmergencies(emergencies, false);
							//displayEmergencies(emergencies);
							

						}
						
						else if(opt==2)
						{
							//requestManagement();
							
							int slct;
							do
							{
								cout<<"1. EMERGENCY APPROVAL \n2. ADDITIONAL INFOs\n";
								cout<<"3. exit\n";
								cin>>slct;
								
								if(slct==1)
								{
									int index;
									
									do 
									{
										
										//displayEmergencies(emergencies);
										displayEmergencies(emergencies, false);
										
										cout<<endl;
										// Ask the admin to approve an emergency request
								        cout << "\n\nENTER THE INDEX OF EMERGENCY TO APPROVE: ";
								        cout<<"   ( ENTER -1 to skip )"<<endl;
								        
								        cin >> index;
								        cin.ignore(); // Clear the newline character from the input buffer
								
							            approveEmergency(emergencies, static_cast<size_t>(index));
							            // Display emergencies on the admin dashboard after approval
							            cout<<endl;
							            //displayEmergencies(emergencies);
							            displayEmergencies(emergencies, false);
							            cout<<endl;
								        
									}while(index != -1);
								}
								
								else if(slct==2)
								{
									int index1;
									do
									{
										displayEmergencies(emergencies, false);
										cout << "\n\nEnter the index of the emergency you want to see details for (or -1 to skip): ";
								        cin >> index1;
								        cin.ignore(); // Clear the newline character from the input buffer
								        
								        if (index1 < emergencies.size())
								        {
								        	const Dashboard& selectedEmergency = emergencies[static_cast<size_t>(index1)];
								            cout << "Details for Emergency at Index " << index1 << ":\n";
								            cout << "Type: " << selectedEmergency.type << "\nLocation: " << selectedEmergency.location
								                 << "\nStatus: " << selectedEmergency.status << "\nAdditional Details: " << selectedEmergency.additionalDetails << endl;
										}
							            
							         
									}while(index1 != -1);
									
								}
								
							}while(slct!=3);
							
						}
						
						else if(opt==3)
						{
							// add edit city emergencies
							int option;
					        string emergency;
							
							do
							{
								cout << "CHOOSE AN OPTION\n";
						        cout << "1. ADD EMERGENCY\n";
						        cout << "2. DELETE EMERGENCY\n";
						        cout << "3. EXIT\n";
						        cin >> option;
						        cin.ignore();  // Ignore the newline character
						
						        if (option == 1) 
								{
						            cout << "ENTER THE EMERGENCY TO ADD: ";
						            getline(cin, emergency);
						            emergencyTree.addEmergency(emergency);
						        } 
								else if (option == 2) {
						            cout << "ENTER THE EMERGENCY TO DELETE: ";
						            getline(cin, emergency);
						            emergencyTree.deleteEmergency(emergency);
						        } 
								else 
								{
						            cout << "INVALID OPTION." << endl;
						        }
							}while(option!=3);
					        
						}
						
						else if(opt==4)
						{
							int cntct_updt;
							
							do
							{
								contactManager.updateContacts();
			        			contactManager.displayUpdatedContacts();
			        			cout<<"PRESS 1 TO UPDATE ANOTHER NO.";
			        			cin>>cntct_updt;
							}while(cntct_updt==1);
							
						}
						
						else if(opt==5)
						{
							string sendNoti;
							cout<<"SEND NOTIFICATION TO USER: ";
							cin.ignore(); 
				        	getline(cin, sendNoti);
				        	
							notificationManager.addNotification(sendNoti,2);
						}
						
						else if(opt==6)
						{
							break;
						}
						else
						{
							cout<<"Please Select a Valid Option !!";
						}
						
					}while(opt!=6);
			        break;
			    } 
				else 
				{	
			        cout << "PASSWORD INCORRECT. ACCESS DENIED. TRY AGAIN." << endl;
			        cout << "PRESS 1 TO EXIT." << endl;
			        cin>>pass;
			    }
			    
			}while(pass!=1);
			
			
		}
		else if(ch==3)
		{
			break;
		}
		else
		{
			cout<<"Please Select a Valid Option !!";
		}
		system("cls");
			
	}while(ch!=3);
	
	
	
	
	return 0;
}
