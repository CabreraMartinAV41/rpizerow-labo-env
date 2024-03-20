from gpiozero import LED, Button
from signal import pause
#importo las librerias que usere (led, botón y pausa)
led = LED(13)
#armo una variable para el led de la placa
button = Button(18)
#armo una variable para el botón
button.when_pressed = led.on
#uso la funcion when_pressed para cambiar el estado del LED a ON cuando 
#se presiona el botón
button.when_released = led.off
#uso la funcion when_released para cambiar el estado del led a OFF cuando
#se suelta el botón

