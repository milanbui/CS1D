# Assignment 5 - Priority Queues Using Heaps

This program will create a priority queue of patients in an emergency room including those in critical condition. 
Those in critical condition have the highest priority while those with a longer wait time (hours before 12pm) have 
higher priority than those with shorter wait times. Each patient has a total of 25 minutes of care and if their 
care is interrupted because of a critical patient, their 25 minutes will pause then resume once the doctor has finished 
caring for the critical patient. The program will calculate the start time and end time of each patient's care based 
on this and their priority. Finally, each patient's name, their wait time (or condition), their start time, and
their end time will be displayed. The program is implemented once with the queue STL and once without.
