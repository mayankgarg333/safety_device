import time
from twilio.rest import TwilioRestClient   # Twilio API
import serial # connection to arduino

print 'program stated and waiting to connect to arduino'

## Boolean variable that will represent whether or not the arduino is connected
connected = False
## open the serial port that your ardiono  is connected to.
ser = serial.Serial("COM1", 9600)       # Change "COM1" to the port where arduino is connected
# loop until the arduino tells us it is ready
while not connected:
    serin = ser.read()
    connected = True

# Tell the arduino to read data!
print 'program checking for the temperature limits'

i=0 # i is just a counter so that different msg is displayed everytime, and it is not assumed that program is hanged
okay = True    # while temperatures are in control
while okay:
    serin=ser.read()
    if serin =='1':
        print 'Temperature is within limits ',i
        i=i%10
        i=i+1
    else:
        okay=False
        
print 'Temperature is out of limit, sending msg to <concerned person>'

#Establish the mobile connection
for i in range(1000):
    print 'Temperature is out of limit, sending msg to <concerned person>'
    account_sid = "<Twilio account ID>"  # Twilio account ID
    auth_token  = "<Twilio account token>"    # Twilio account authentication token
    client = TwilioRestClient(account_sid, auth_token)
    message = client.messages.create(body="Something is wrong with the experiment, need immediate attention",
	to="+<1234567980>",    # Replace with your phone number
	from_="+<1234567890>") # Replace with your Twilio number
    time.sleep(120)

ser.close()
