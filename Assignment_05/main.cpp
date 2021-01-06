/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #5: Priority Queues
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 27 February 2019
 * SCORE        : 8/10
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include "timeClass.h"
#include "printHeader.h"
#include "priorityQueueClass.h"
using namespace std;

/*******************************************************************************
 * PRIORITY QUEUES USING HEAPS
 * _____________________________________________________________________________
 *
 * This program will create a priority queue of patients in an emergency room
 * including those in critical condition. Those in critical condition have the
 * highest priority while those with a longer wait time (hours before 12pm) have
 * higher priority than those with shorter wait times. Each patient has a total
 * of 25 minutes of care and if their care is interrupted because of a critical
 * patient, their 25 minutes will pause then resume once the doctor has finished
 * caring for the critical patient. The program will calculate the start time
 * and end time of each patient's care based on this and their priority. Finally,
 * each patient's name, their wait time (or condition), their start time, and
 * their end time will be displayed. The program is implemented once with the
 * queue STL and once without.
 * _____________________________________________________________________________
 * INPUT:
 *	    Patient patients[]    - an array of the struct Patient containing the
 *	                            information (hours waited and name) of the
 *	                            non-critical patients
 *	    Patient emergencies[] - an array of the struct Patient containing the
 *	                            information (time arrived and name) of the
 *	                            critical patients.
 *
 * OUTPUT:
 *	    Patient patients[]    - an array of the struct Patient containing the
 *	                            information (hours waited and name) of the
 *	                            non-critical patients
 *	    Patient emergencies[] - an array of the struct Patient containing the
 *	                            information (time arrived and name) of the
 *	                            critical patients.
 *	    string  time          - a string consisting of the hour and the minute
 *	                            of the patient's start of care and end of care
 *
 ******************************************************************************/

struct Patient
{
	string name;  // Name of patient
	int waitTime; // Patient's wait time or time of arrival
};

// Class for comparator of non-STL implementation
class GreaterThan
{
public:
	// Is the value of a > b (wait time a longer than wait time b) op overload
	bool operator()(Patient &a, Patient& b)
	{
		return (a.waitTime > b.waitTime);
	}
};
// Class for comparator of STL implementation
class LessThan
{
public:
	// Is the value of a > b (wait time a shorter than wait time b)
	bool operator()(Patient &a, Patient& b)
	{
		return (a.waitTime < b.waitTime);
	}
};


int main()
{
	// DECLARING VARIABLES HERE

	priority_queue<Patient,                  // IN/OUT - patient queue using STL
	               vector<Patient>,
				   LessThan> patientQueueSTL;

	PriorityQueue<Patient,                   // IN/OUT - patient queue w/o STL
	              GreaterThan> patientQueue;

	Time currentTime;     // PROC - time object to keep track of time for the
	                      //        no STL implementation
	Time currentTimeSTL;  // PROC - time object to keep track of time for the
	                      //        STL implementation

	bool emergency1;      // PROC - whether or not the first emergency patient
	                      //        has arrived
	bool emergency2;      // PROC - whether or not the second emergency patient
                          //        has arrived

	int emergencyHour1;   // PROC - the hour that the first emergency patient
	                      //        started their care
	int emergencyMin1;    // PROC - the minutes that the first emergency patient
	                      //        started their care

	int emergencyHour2;   // PROC - the hour that the second emergency patient
	                      //        started their care
	int emergencyMin2;    // PROC - the minutes that the second emergency patient
	                      //        started their care

	int endEmergencyHour1;// PROC - the hour the first emergency patient ended
	                      //        their care
	int endEmergencyMin1; // PROC - the minute the first emergency patient ended
	                      //        their care

	int endEmergencyHour2;// PROC - the hour the second emergency patient ended
	                      //        their care
	int endEmergencyMin2; // PROC - the minute the second emergency patient ended
	                      //        their care

	int startHour;        // PROC - the time the non-critical patients start
	                      //        their care
	int startMinute;      // PROC - the time the non-critical patients end their
	                      //        care

	string time;          // PROC/OUT - a string containing the hour and the
	                      //            minutes the patients started/ended their
	                      //            care (the time)

	// IN/OUT - array of struct Patient containing the information of the non-
	//          critical patients (name and wait time in hours)
	Patient patients[7] = {{"Bob Bleeding"    , (6)},
	                       {"Frank Feelingbad", (5)},
	                       {"Cathy Coughing"  , (3)},
	                       {"Sam Sneezing"    , (4)},
	                       {"Alice Ailment"   , (8)},
	                       {"Irene Ill"       , (1)},
	                       {"Tom Temperature" , (7)}};

	// IN/OUT - array of struct Patient containing time of arrival in minutes)
	Patient emergencies[2] = {{"Paula Pain", (720+19)},
			                  {"Sid Sickly", (720+(60*2)+21)}};


	// PROCESSING -- calculating the hour and the minutes the first and the
	//               second critical patient arrived
	//               (convert minutes to hours and minutes)
	emergencyHour1 = static_cast<int>((emergencies[0].waitTime/60));
	emergencyMin1  = emergencies[0].waitTime - (emergencyHour1*60);

	emergencyHour2 = static_cast<int>((emergencies[1].waitTime/60));
	emergencyMin2  = emergencies[1].waitTime - (emergencyHour2*60);


	// OUTPUT -- outputs class header and program description
	cout << printHeader("Priority Queues", 5);

	cout << "THIS PROGRAM WILL:" << endl;
	cout << "1. Create a priority queue of patients without an STL and with an STL"
	     << endl;
	cout << "2. Create the queue with those with longer wait time higher in"
			"\n   priority and those in critical condition in highest priority"
			<< endl;
	cout << "3. Calculate the start and end time of their care with each patient"
			"\n   receiving 25 minutes of care excluding the time when their"
			"\n   care is interrupted if it is interrupted" << endl;
	cout << "4. Display the patients, their wait time or if in critical condition,"
			"\n   their start time, and their end time" << endl << endl << endl;

	/**************************************************************************
	 *
	 * IMPLEMENTATION OF PRIORITY QUEUE WITH STL
	 *
	 **************************************************************************/

	// OUTPUT -- outputs the header
	cout << left << setw(18) << setfill('*') << "*";
	cout << setfill(' ');
	cout << "EMERGENCY ROOM PRIORITY QUEUE USING STL";
	cout << left << setw(18) << setfill('*') << "*" << endl << endl;
	cout << setfill(' ');

	// INPUT -- inputs the array elements into the patient queue
	for(int i = 0; i < 7; i++)
	{
		patientQueueSTL.push(patients[i]);
	}

	// OUTPUT -- outputs labels for the information
	cout << left << setw(25) << "PATIENT NAME";
	cout << left << setw(25) << "WAIT TIME (HOURS)";
	cout << left << setw(15) << "START TIME";
	cout << left             << "END TIME" << endl;

	cout << left << setw(75) << setfill('-') << "-" << endl;
	cout << setfill(' ');


	// PROCESSING & OUTPUT -- displays the patients as they are deleted from the
	//                        queue (as they are treated) until the queue is
	//                        empty
	while(!patientQueueSTL.empty())
	{
		// Initializing variables
		emergency1 = false;
		emergency2 = false;
		time = "";
		startHour   = currentTimeSTL.getHours();
		startMinute = currentTimeSTL.getMinutes();

		// PROC - increments the minutes until it has reached 25 minutes
		//        (to track how many minutes of care)
		for(int j = 0; j <= 25; j++)
		{

			// If it is time that the first critical patient arrives
			if((currentTimeSTL.getHours() == emergencyHour1)
				&& (currentTimeSTL.getMinutes() == emergencyMin1))
			{
				// Adds 25 minutes to current time to represent the critical
				// patient's 25 minutes of care and the time passing
				currentTimeSTL.addMinutes(25);

				// Sets the end of their care to the current time
				endEmergencyHour1 = currentTimeSTL.getHours();
				endEmergencyMin1  = currentTimeSTL.getMinutes();

				// Sets emergency1 to true signaling that there was an emergency
				// patient who arrived (the first one)
				emergency1 = true;
			}
			// If it is time that the second critical patient arrives
			else if((currentTimeSTL.getHours() == emergencyHour2)
					&& (currentTimeSTL.getMinutes() == emergencyMin2))
			{
				// Adds 25 minutes to current time to represent the critical
				// patient's 25 minutes of care and the time passing
				currentTimeSTL.addMinutes(25);

				// Sets the end of their care to the current time
				endEmergencyHour2 = currentTimeSTL.getHours();
				endEmergencyMin2  = currentTimeSTL.getMinutes();

				// Sets emergency2 to true signaling that there was an emergency
				// patient who arrived (the second one)
				emergency2 = true;
			}
			else
			{
				// If there are no critical patients, increment current time
				// (continue care uninterrupted)
				currentTimeSTL.addMinutes(1);
			}
		}

		// PROCESSING -- converts the start time to a string
		time += to_string(startHour);
		time += ":";
		if(startMinute < 10)
		{
			time += "0";
		}
		time += to_string(startMinute);
		time += " PM";

		// OUTPUT -- outputs the patient's name, wait time, and their start of
		//           care time
		cout << left << setw(25) << (patientQueueSTL.top()).name;
		cout << left << setw(25) << (patientQueueSTL.top()).waitTime;
		cout << left << setw(15) << time;

		// PROCESSING -- converts the end time to a string
		time = "";
		time += to_string(currentTimeSTL.getHours());
		time += ":";
		if(currentTimeSTL.getMinutes() < 10)
		{
			time += "0";
		}
		time += to_string(currentTimeSTL.getMinutes());
		time += " PM";

		// OUTPUT -- outputs the patient's end of care time.
		cout << left << setw(15) << time << endl;

		// If there was an emergency
		if(emergency1 || emergency2)
		{
			// OUTPUT -- outputs the critical patient's name and signal that
			//           they are a critical patient
			cout << left << setw(25)
				 << (emergency1?emergencies[0].name:emergencies[1].name);
			cout << left << setw(25) << "- LIFE THREATENING -";

			// PROCESSING -- converts the patient's start time to a string
			time = "";
			time += to_string(emergency1?emergencyHour1:emergencyHour2);
			time += ":";
			if(emergency1?(emergencyMin1 < 10):(emergencyMin2 < 10))
			{
				time += "0";
			}
			time += to_string(emergency1?emergencyMin1:emergencyMin2);
			time += " PM";

			// OUTPUT -- outputs the patient's start of care time
			cout << left << setw(15) << time;

			// PROCESSING -- converts the patient's end time to a string
			time = "";
			time += to_string(emergency1?endEmergencyHour1:endEmergencyHour2);
			time += ":";
			if(emergency1?(endEmergencyMin1 < 10):(endEmergencyMin2 < 10))
			{
				time += "0";
			}
			time += to_string(emergency1?endEmergencyMin1:endEmergencyMin2);
			time += " PM";

			// OUTPUT -- outputs the patient's end of care time
			cout << left << setw(15) << time << endl;
		}

		// PROCESSING -- removes patients from the queue
		patientQueueSTL.pop();

	}

	cout << endl;

	cout << left << setw(75) << setfill('*') << "*" << endl << endl;
	cout << setfill(' ');

	cout << endl << endl << endl;



	/**************************************************************************
	 *
	 * IMPLEMENTATION OF PRIORITY QUEUE USING AUTHOR'S CODE (NO STL)
	 *
	 **************************************************************************/

	cout << left << setw(17) << setfill('*') << "*";
	cout << setfill(' ');
	cout << "EMERGENCY ROOM PRIORITY QUEUE WITHOUT STL";
	cout << left << setw(17) << setfill('*') << "*" << endl << endl;
	cout << setfill(' ');

	// INPUT -- inputting the patient array elements into the queue
	for(int i = 0; i < 7; i++)
	{

		patientQueue.insert(patients[i]);

	}

	// OUTPUT -- outputs info labels
	cout << left << setw(25) << "PATIENT NAME";
	cout << left << setw(25) << "WAIT TIME (HOURS)";
	cout << left << setw(15) << "START TIME";
	cout << left             << "END TIME" << endl;

	cout << left << setw(75) << setfill('-') << "-" << endl;
	cout << setfill(' ');

	// PROCESSING & OUTPUT -- displays the patients as they are deleted from the
	//                        queue (as they are treated) until the queue is
	//                        empty
	while(!patientQueue.empty())
	{
		// Initializing variables
		emergency1 = false;
		emergency2 = false;
		time = "";
		startHour   = currentTime.getHours();
		startMinute = currentTime.getMinutes();


		// PROC - increments the minutes until it has reached 25 minutes
		//        (to track how many minutes of care)
		for(int j = 0; j <= 25; j++)
		{
			// If it is time that the first critical patient arrives
			if((currentTime.getHours() == emergencyHour1)
				&& (currentTime.getMinutes() == emergencyMin1))
			{
				// Adds 25 minutes to current time to represent the critical
				// patient's 25 minutes of care and the time passing
				currentTime.addMinutes(25);

				// Sets the end of their care to the current time
				endEmergencyHour1 = currentTime.getHours();
				endEmergencyMin1  = currentTime.getMinutes();

				// Sets emergency1 to true signaling that there was an emergency
				// patient who arrived (the first one)
				emergency1 = true;
			}
			// If it is time that the second critical patient arrives
			else if((currentTime.getHours() == emergencyHour2)
					&& (currentTime.getMinutes() == emergencyMin2))
			{
				// Adds 25 minutes to current time to represent the critical
				// patient's 25 minutes of care and the time passing
				currentTime.addMinutes(25);

				// Sets the end of their care to the current time
				endEmergencyHour2 = currentTime.getHours();
				endEmergencyMin2  = currentTime.getMinutes();

				// Sets emergency2 to true signaling that there was an emergency
				// patient who arrived (the second one)
				emergency2 = true;
			}
			else
			{
				// If there are no critical patients, increment current time
				// (continue care uninterrupted)
				currentTime.addMinutes(1);
			}
		}

		// PROCESSING -- converts start time to a string
		time += to_string(startHour);
		time += ":";

		if(startMinute < 10)
		{
			time += "0";
		}
		time += to_string(startMinute);
		time += " PM";

		// OUTPUT -- outputs the patient's name, wait time, and start time
		cout << left << setw(25) << (patientQueue.max()).name;
		cout << left << setw(25) << (patientQueue.max()).waitTime;
		cout << left << setw(15) << time;

		// PROCESSING -- converts the end time to a string
		time = "";
		time += to_string(currentTime.getHours());
		time += ":";
		if(currentTime.getMinutes() < 10)
		{
			time += "0";
		}
		time += to_string(currentTime.getMinutes());
		time += " PM";

		// OUTPUT -- outputs the end time
		cout << left << setw(15) << time << endl;

		// If there was an emergency
		if(emergency1 || emergency2)
		{
			// OUTPUT -- outputs the emergency patient's name and their status
			//           as a critical patient
			cout << left << setw(25)
				 << (emergency1?emergencies[0].name:emergencies[1].name);
			cout << left << setw(25) << "- LIFE THREATENING -";

			// PROCESSING -- outputs the start time to a string
			time = "";
			time += to_string(emergency1?emergencyHour1:emergencyHour2);
			time += ":";
			if(emergency1?(emergencyMin1 < 10):(emergencyMin2 < 10))
			{
				time += "0";
			}
			time += to_string(emergency1?emergencyMin1:emergencyMin2);
			time += " PM";

			// OUTPUT -- outputs the start time
			cout << left << setw(15) << time;

			// PROCESSING -- converts the end time to a string
			time = "";
			time += to_string(emergency1?endEmergencyHour1:endEmergencyHour2);
			time += ":";
			if(emergency1?(endEmergencyMin1 < 10):(endEmergencyMin2 < 10))
			{
				time += "0";
			}
			time += to_string(emergency1?endEmergencyMin1:endEmergencyMin2);
			time += " PM";

			// OUTPUT -- outputs end time
			cout << left << setw(15) << time << endl;
		}

		// PROCESSING -- removes patients from queue
		patientQueue.removeMax();

	}


	cout << endl;

	cout << left << setw(75) << setfill('*') << "*" << endl << endl;
	cout << setfill(' ');

	return 0;
}


