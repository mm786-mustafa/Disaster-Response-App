//user

#include<iostream>
#include<iomanip>
#include<fstream>
#include <string>

//#include"Admin.h"
//#include"kmp.h"
//#include"emerg_req.h"
#include"Notification.h"
#include"EmergencyInfoTree.h"

using namespace std;



//void emergencyGuide(EmergencyInfoTree infoTree, string searchtxt)
void emergencyGuide()
{
	EmergencyInfoTree infoTree;
	
	infoTree.insert("Earthquakes", "Drop, cover, and hold on during shaking. Move to an open area away from buildings, trees, and streetlights after the shaking stops.");
    infoTree.insert("Hurricanes", "Evacuate if instructed. Board up windows and secure outdoor objects. Stay indoors in a designated safe room during the storm.");
    infoTree.insert("Floods", "Move to higher ground immediately. Avoid flooded areas, and do not drive through flooded roads. Listen to weather alerts for updates.");
	infoTree.insert("Landslides","Move away from the path of the landslide. Take shelter in a sturdy building. Avoid river valleys and steep slopes during heavy rainfall.");
	infoTree.insert("Vehicle Accidents","Check for injuries, call emergency services, and provide first aid if trained. Exchange information with involved parties and report the incident");
    infoTree.insert("Electrical Shocks","Disconnect power if possible. Do not touch the person directly. Call for emergency medical assistance");
    infoTree.insert("Poisoning","Call emergency services immediately. Provide information about the substance ingested. Do not induce vomiting without professional advice.");
    infoTree.insert("Terrorism Incidents","Run, hide, or fight, depending on the situation. Follow emergency alerts and cooperate with law enforcement.");
    infoTree.insert("Robberies","Stay calm and cooperate with the robber's demands. Avoid sudden movements. Remember details for a later police report");
    infoTree.insert("Wildlife Encounters","Stay calm, back away slowly, and avoid direct eye contact. Do not run from predators. Make noise to alert animals of your presence.");
    infoTree.insert("House Fires","Exit the building immediately. Crawl under smoke if necessary. Call the fire department and do not re-enter until cleared.");
    infoTree.insert("Gas Leaks","Evacuate the area immediately. Do not use electronic devices or light switches. Call the gas company and emergency services.");
    infoTree.insert("Plane Crashes","Move away from the crash site to a safe location. Follow emergency personnel instructions. Call for medical help if needed");
    infoTree.insert("Bus Accidents","Stay calm, remain seated if possible, and follow the driver's instructions. Evacuate calmly in an orderly manner if necessary.");
    infoTree.insert("Domestic Violence","Call emergency services for assistance. If safe, leave the premises. Seek support from friends, family, or domestic violence hotlines.");


	string searchTitle;
	
    cout << "ENTER TITLE TO SEARCH: ";
    getline(cin, searchTitle);

    //Searching and displaying the information
    infoTree.search(searchTitle);
}



		

