import machine
from machine import Pin, PWM
import time

sensor_temp = machine.ADC(4)
conversion_factor = 3.3 / (65535)


led = machine.Pin(25, machine.Pin.OUT)

button = Pin(12,Pin.IN, Pin.PULL_DOWN)


s = PWM(Pin(15))
s.freq(50)

led.on()


while True:
    reading = sensor_temp.read_u16() * conversion_factor 
    temperature = 27 - (reading - 0.706)/0.001721
    print(temperature)
    #Oculto
    if button.value() == 0:
        led.on()
        ton = ((105 + 45) * 100000) / 9
        s.duty_ns(int(ton))
        time.sleep(0.1)
    #Normal
    else:
        led.off()
        ton = ((70 + 45) * 100000) / 9
        s.duty_ns(int(ton))
        time.sleep(0.1)
        


    

    
    

    
    
