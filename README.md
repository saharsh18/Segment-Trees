# Segment-Trees
Mentor Name - Neeraj Dwivedi
Project Members :
Hiten Goel  - 2022MCB1380
Saharsh Saxena - 2022CSB1116


We have created a program that takes data from multiple servers , that at what time they receive a click or a signal , and then stores that information using a segment tree . It also updates this , as new data and updates are received from the servers. Queries can be run to get the total number of clicks received during a particular duration from a particular server or from all the servers combined.


We have used CSV file type to input the data.

In our code , we have taken the data of 3 servers (Which is for demonstration purposes and can be extended to any number of severs with minor changes in the code).

In the CSV file , the columns correspond to the server number (starting from 0).
For each server , the CSV file must contain the timestamps of its clicks in the corresponding column.

The format for the timestamp must me : “MM:SS:mm”
Where M is minutes
	   S is seconds
	   m is milli seconds

For eg, a timestamp of 2 Minutes , 30 seconds , and 15 milli seconds must be given as : “02:30:15”

In our demonstration the time stamp must be less than 60 minutes (Which is again , just for demo purposes , and can be extended with minor changes in the code.)

First , we need to give an initial file to initialise the segment tree. The filename must be entered along with the .csv extension.

Then , A menu will be provided , With options to Update the server data , to run queries or to quit.

For updation , select the first option and then enter the csv file name with the updated data.(again .csv extension must be included in the name).
This update file must also follow the above mentioned constraints.

For running queries , 2 options will be provided , to calculate sum of clicks in a given duration from a particular server , or to calculate the sum of clicks from all the servers in a particular duration.

For the 1st option , Enter the server number (starting from 0) and then enter the starting and ending duration (both should be in seconds ).

For the 2nd option , just enter the starting and ending duration (Again , both should be in seconds ).
We have added 2 files for input just for reference  
