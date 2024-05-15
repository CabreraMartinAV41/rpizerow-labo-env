from gpiozero import LED, Buzzer
from time import sleep

# Declaración de componentes
led_verde = LED(13)
led_rojo = LED(19)
led_azul = LED(26)
bzz = Buzzer(22)

while True:
    # Solicitar comando al usuario
    res = input("prompt (Syntax: comando.opcion):")

    # Opciones de comando, con manejo de errores
    if res == "buzz.on":
        bzz.on()
    elif res == "buzz.off":
        bzz.off()
    elif res == "rgb.red":
      
        led_rojo.on()
    elif res == "rgb.blue":
       
        led_azul.on()
    elif res == "rgb.green":
        
        led_verde.on()
        
    else:
        # Manejo de errores para comandos incorrectos
        print("Error: no se reconoció el comando")

