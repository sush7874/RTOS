import pyrebase
import random
from time import sleep
config = {
  "apiKey": "AIzaSyCSInHptGftDqLJQ_udwDpD3zRer4WM9PA",
  "authDomain": "rtos-proj.firebaseapp.com",
  "databaseURL": "https://rtos-proj.firebaseio.com/",
  "storageBucket": "rtos-proj.appspot.com",
  "serviceAccount": "rtos-proj.json"
}

firebase = pyrebase.initialize_app(config)
auth = firebase.auth()

# Log the user in
user = auth.sign_in_with_email_and_password("me@gmail.com", "password")
db = firebase.database()
dict1 = ["HumiditySensor", "TempSensor", "UltrasoundSensor"]
for i in range(0,30):
    y = random.randint(0,2)
    x = random.randint(0,10)
    sensor_name = dict1[y] + str(x)
    #val = db.child('Sensors').child(sensor_name).child('Value').get().val()
    if(dict1[y] == "HumiditySensor"):
        humidity = random.randint(10,100)
        db.child('Sensors').child(sensor_name).update({'Value' : humidity})
    if(dict1[y] == "TempSensor"):
        temp = random.randint(0,50)
        db.child('Sensors').child(sensor_name).update({'Value' : temp})
    if(dict1[y] == "UltrasoundSensor"):

        distance = random.randint(0,200)
        db.child('Sensors').child(sensor_name).update({'Value' : distance})

    sleep(3) #
