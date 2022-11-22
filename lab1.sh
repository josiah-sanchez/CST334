# Name: Josiah Sanchez
# Date: 06/29/2021
# Title: Lab1 - Create a Shell Program
# Desription: This program computes the area of a rectangle
# and a circle while also implementing a loop.

#!/bin/bash
echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$
user=$USER
numusers=`who | wc -l`
echo "Hi $user! There are $numusers logged on."
#Check to see if the user matches expected user
if [ $user="josisanchez" ]
then
   echo "Now you can proceed!"
else
   echo "Check who logged in!"
   exit 1
fi

response="Yes"
#This loop will continue until user inputs No
while [ $response != "No" ]
do
   #obtain user input for both height and width
   echo "Enter height of rectangle."
   read height
   echo "Enter width of rectangle."
   read width
   #calculate the area using input from user
   area=`expr $height \* $width`
   echo "The Area of the rectangle is $area"

   #check to see if user wants to repeat rectangle area calculation
   echo "Would you like to repeat for another rectangle [Yes/No]?"
   read response

done

response="Yes"
while [ $response != "No" ]
do
   #obtain user input for radius
   echo "Enter radius of circle."
   read radius
   #calculate area of circle based on user input
   #use awk to be able to calculate floating point
   areac=`echo $radius $radius | awk '{print 3.14 * $1 * $2}'`
   echo "The area of the circle is $areac"

   echo "Would you like to repeat for another circle [Yes/No]?"
   read response

done
