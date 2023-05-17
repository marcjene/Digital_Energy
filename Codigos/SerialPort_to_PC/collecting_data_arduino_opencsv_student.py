# -*- coding: utf-8 -*-
"""
Created on Wed Nov 13 13:54:24 2019

@authors: Ingrid, Cristian, Marc - CITCEA
"""

# importing libraries 
import serial
import datetime as dt 
import re
import csv 

# creating communications object using Serial 
arduino = serial.Serial('COMX', BAUD_RATE) "Change X for number of COM channel, Change BAUD_RATE for baudrate"
print("Starting!")

# try-except-finally loop for data acquisition
try:
    while True:
        now = dt.datetime.CLASSMETHOD() "Change CLASSMETHOD for classmethod of library datetime that gives the current local date and time"
        # SEND MESSAGE
        """if (now.second%10<5):
            arduino.write('H'.encode())
            print ('LED ON')
        else:
            arduino.write('L'.encode())
            print ('LED OFF')"""
            
        # READ DATA    
        # Check if there is new info from the Arduino and read it
        data_bytes = arduino.readline() 
        # Decoding the message into UTF-8         
        data = data_bytes.decode("utf-8")
        
        # SAVE DATA
        # if data has been read, print and save it
        if data:
            # strip data string into 2, 3 or as many different values for each reading   
            v1,v2 = re.findall(pattern=r"[-+]?\d*\.\d+|[-+]?\d+", string=data)  # to understand pattern: https://regex101.com/
            # store date and readings (change them to float!) into a list
            row = [#date, #variable1, #variable2]
            # save reading row into the csv file. File needs to be open with "a" (append) mode.
            with open('FILE_NAME.csv', 'a', newline='') as csvFile:  "Change FILE_NAME to whatever you want (e.g.: 1103_test)"
                writer = csv.writer(csvFile)
                writer.writerow(row)
                csvFile.close()
              
# handling KeyboardInterrupt by the end-user (CTRL+C)
except KeyboardInterrupt:
    # closing communications port
    arduino.close() 
    print('Communications closed')
    