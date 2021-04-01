import numpy as np
import matplotlib.pyplot as plt
from time import sleep
import RPi.GPIO as GPIO
import time as vremy
 
 
 
GPIO.setmode(GPIO.BCM)
D = [10,9,11,5,6,13,19,26]
GPIO.setup(D, GPIO.OUT)
 
 
def num2dac(decNumber):
    return list(reversed([0]*(8-len(list(bin(decNumber))[2:])) + list(bin(decNumber))[2:]))
          
def lightNumber(number):
    global D
    GPIO.output(D,0)
    leds = num2dac(number)
    for i in range(len(D)):
        if int(leds[i]):
            GPIO.output(D[i],1)
            
print("Freq")
f=input()
print("Delay")
sf=input()

while f.isdigit()==0 and sf.isdigit()==0:
    print("Nums")
    f=input()
    sf=input()
t=int(1/float(f))
st=int(1/float(sf))
time = np.arange(0, t, st)
amplitude = np.sin(time)

for i in range(len(amplitude)):
    amplitude[i]=round((amplitude[i]+1)/2*255)
print(list(amplitude))

for i in list(amplitude):
    lightNumber(int(i))
    print(i)
    vremy.sleep(st)
    GPIO.output(D,0)

plt.plot(time, amplitude)
plt.title('Sinus')
plt.xlabel('Time')
plt.ylabel('Amp sin(time)')
plt.show()
