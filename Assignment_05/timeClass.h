/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #5: Priority Queues
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 27 February 2019
 ******************************************************************************/
#ifndef TIMECLASS_H_
#define TIMECLASS_H_

/*******************************************************************************
 * Time Class
 * 	 This class represents a Time object. It manages two attribute: hours and
 * 	 minutes
 *******************************************************************************/
class Time
{
public:
	/******************************
	 ** CONSTRUCTOR & DESTRUCTOR **
	 ******************************/
	Time();


	/***************
	 ** MUTATORS **
	 ***************/
	void addMinutes(int min);

	/***************
	 ** ACCESSORS **
	 ***************/
	int  getMinutes()const;
	int  getHours()const;
private:
	int hour;      // Hour of the time
	int minutes;   // Minutes of the time
};

/*******************************************************************************
 * Time();
 * 	 Constructor; Initializes attributes
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * addMinutes(int min);
 * 	 Mutator; Adds minutes to the time to update time and increments hour and
 * 	          resets minutes once it hits 60 minutes
 * 	 Parameters: min (int)  // IN - how many minutes to add
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * getMinutes()const;
 * 	 Accessor; Returns the minutes of the current time
 * 	 Parameters: none
 * 	 Return: minutes
 *******************************************************************************/

/*******************************************************************************
 * getHours()const;
 * 	 Accessor; Returns the hours of the current time
 * 	 Parameters: none
 * 	 Return: hour
 *******************************************************************************/



#endif /* TIMECLASS_H_ */
