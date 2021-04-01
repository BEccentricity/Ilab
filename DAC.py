import RPi.GPIO as GPIO
import time
import numpy as np
import matplotlib.pyplot as plt

GPIO_pins = (26, 19, 13, 6, 5, 11, 9, 10)

def sinspace (Time, Freq):
    x = np.linspace (0, Time, Freq)
    s = np.sin(np.deg2rad(x))
    return s

def DecToBinList(number):
    return list(map(int, bin(number)[2:].zfill(8)))

def lightNumber(number):
    global GPIO_pins
    binNumberList = DecToBinList(number)
    for idx in range(8):
        GPIO.output(GPIO_pins[idx], binNumberList[idx])

def num2dac(value):
    lightNumber(value)

def Repeat ():
    j = 0
    print ("Repetitions Number")
    R = int (input ())
    while j < R:
        i = 0
        while i < 255:
            i += 1
            lightNumber (i)
            time.sleep (0.01)
        while i > 1:
            i -= 1
            lightNumber (i)
            time.sleep (0.01)

        j = j + 1
        print (j)

def sekans():
    Time = input ()
    Freq = input ()
    Period = 1/Freq
    sampFreq = input ()
    x = sinspace (Time, Freq)
    x = (x + 1) * 255 / 2
    i = 0
    while Time - Period >= 0 :
        lightNumber(int(x[i]))
        i = i + 1
        time.sleep (sampFreq)

GPIO.setmode(GPIO.BCM)

GPIO.setup(GPIO_pins, GPIO.OUT)

Repeat ()

time.sleep(1)
GPIO.cleanup()