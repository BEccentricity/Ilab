import RPi.GPIO as GPIO
import time
import numpy as np
import matplotlib.pyplot as plt

GPIO_pins = (26, 19, 13, 6, 5, 11, 9, 10)

GPIO.setmode (GPIO.BCM)
GPIO.setup (GPIO_pins, GPIO.OUT)
GPIO.setup(4, GPIO.IN)
GPIO.setup (17, GPIO.OUT)



def DecToBinList(number):
    return list(map(int, bin(number)[2:].zfill(8)))


def lightNumber(number):
    global GPIO_pins
    binNumberList = DecToBinList(number)
    for idx in range(8):
        GPIO.output(GPIO_pins[idx], binNumberList[idx])

def bin_adc():
	Left = -1
	Right = 256
	while Left + 1 < Right:
		Flag = GPIO.input(4) % 2
		Middle = (Left + Right) // 2
		print (Middle)
		lightNumber (Middle)
		time.sleep(0.1)
		if Flag > 0: #dac >sig 
			Right = Middle
		else:
			Left = Middle
	return Left



while True:
    x = bin_adc ()



time.sleep(1)
GPIO.cleanup()