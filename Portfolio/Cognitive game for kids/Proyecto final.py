#Juego donde el usuario escribe el renglón y columna que desea voltear de la matriz y dependiendo del valor de la matriz, cae en un hoyo o no.
#Si es hoyo se le da la oportunidad de salvarse si responde bien una pregunta.
#Al terminar el juego, todas las preguntas con la respuesta elegida por el usuario aparecen en el archivo txt
import random, os

#función que da inicio al juego y le pregunta al usuario si está listo
def inicio_juego():
    '''\nFunción inicio_juego: se muestra en pantalla la bienvenida al juego y te pregunta si estás listo para jugar
      
    Parámetros:
    str(comienzo): palabra para comenzar el juego
    str(bienvenida): "Okay! Juguemos!"
    str(despedida): "Adiós!"
    '''
    arch = open("Proyecto final.txt", "w") #abrimos el archivo de texto en modo write porque se agregará el texto de acuerdo a las preguntas que vaya contestando el usuario
    print("Bienvenido! Este juego es sobre cultura general.")
    comienzo = input("¿Estás listo?")
    arch.write(f"¿Estás listo? {comienzo}")
    if comienzo == "si" or comienzo == "SI" or comienzo == "Si" or comienzo == "sí" or comienzo == "Sí": #verificamos la respuesta del usuario
        bienvenida = ("\nOkay! Juguemos!\n\n")
        print(bienvenida)
        arch.write(bienvenida)
    else:
        despedida = ("\nAdiós!")
        print(despedida) #si la respuesta del usuario es diferente a sí, se imprime adiós y se cierra el programa
        arch.write(despedida)
        quit()

def limpia():
    '''\nFunción limpia: limpia la pantalla sin importar el sistema operativo de la computadora dónde se esté usando'''
    if os.name == 'nt': #Windows
        os.system('cls') 
    else:  #'posix'
        os.system('clear') #Mac/linux

def llena_tablero():
  '''\nFunción llena_tablero: llena el tablero con las "cartas volteadas"
 
 Return:
    int(matriz): regresa los valores de los renglones y columnas de la matriz
    
    Parámetros:
    int(r): número de renglones para hacer la matriz
    int(c): número de columnas para hacer la matriz
    '''
  matriz=[]
  for r in range(5):
      renglon=[]
      for c in range(5):
          # Agrega un emoji de mundo con el código unicode
          renglon.append('\U0001F30F')
      matriz.append(renglon)
  return matriz

def despliega_tablero(tablero):
  '''\nFunción despliega_tablero: despliega en la pantalla la matriz que recibe en forma de tabla desplegando un tablero
 '''
  
  print("--------"*len(tablero))
  for renglon in tablero:
    print("|", end="")
    for elemento in renglon:
        # Centra el elemento en un espacio de 5
        print(f'{elemento}'.center(5), end="")
        print("|", end="")
    print('\n'+"--------"*len(renglon))

def llena_escondido():
  '''\nFunción llena_escondido: llena una matriz de números entre 0 y 24
\n El rango (0,15,3) representa que no hay un hoyo
\n El resto de los números indican que caíste en un hoyo y necesitas responder una pregunta para salvarte
 
 Return:
    int(matriz): regresa los valores de la matriz (0, 24)
    
    Parámetros:
    int(r): número para el renglón de la matriz
    int(c): número para la columna de la matriz
    '''
  
  matriz=[]
  for r in range(5):
      renglon=[]
      for c in range(5):
          # Agrega un número de 0 a 24 de manera aleatoria
          renglon.append(random.randint(0, 24))
      matriz.append(renglon)
  return matriz

def verifica_cambia(r,c, tablero, escondido):
    '''\nFunción verifica_cambia: verifica si los valores introducidos para los renglones y columnas son válidos
 
 Return:
    int(0-1): regresa el contador caídas
    
    Parámetros:
    int(r): número para validar los renglones de la matriz
    int(c): número para validar las columnas de la matriz
    '''
  #Verifico si r y c son valores válidos entre 1 y 5
    if 1<=r<=5:
        if 1<=c<=5:
          # Si son válidos les resto 1, el usuario dará posiciones desde 1.
          r-=1
          c-=1
          #Cambio el dato de la carta destapada en el tablero
          #Si en la matriz escondida tengo un número que no sea 0,3,6,9,12,15,18,21,24 es un hoyo
          #Si el usuario cae en un hoyo le doy la opción de salvarse si responde bien una pregunta
          if escondido[r][c] == 1:
              #abrimos el archivo de texto en modo append para agregar texto hasta el final de lo que ya se había escrito anteriormente
              arch = open("Proyecto final.txt", "a") 
              print("¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:")
              pregunta1 = ("¿Cuál es el planeta más grande del sistema solar? \nA. Marte \nB. Júpiter \nC. Saturno \nD. Neptuno")
              print(pregunta1)
              arch.write(pregunta1)
              respuesta1 = input("\nRespuesta: ")
              arch.write(f"\nRespuesta: {respuesta1}")
              if respuesta1 == "b" or respuesta1 == "B" or respuesta1 == "Júpiter" or respuesta1 == "jupiter":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  #Devuelvo 0 porque se salvó y no pierde ninguna vida
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1
          #Hacemos los mismos pasos para el resto de los números
          if escondido[r][c] == 2:
              arch = open("Proyecto final.txt", "a") #abriendo el archivo para agregar más texto
              print('¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:')
              pregunta2 = ("¿Cuál es el país más grande y el más pequeño del mundo? \nA. Cánada y Mónaco \nB. China y Nauru \nC. Estados Unidos y Malta \nD. Rusia y Vaticano")
              print(pregunta2)
              arch.write(pregunta2)
              respuesta2 = input("\nRespuesta:")
              arch.write(f"\nRespuesta: {respuesta2}")
              if respuesta2 == "d" or respuesta2 =="D" or respuesta2 == "Rusia y Vaticano" or respuesta2 == "rusia y vaticano":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1
          if escondido[r][c] == 4:
              arch = open("Proyecto final.txt", "a")
              print('¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:')
              pregunta4 = ("¿Qué hora es: a quarter past six? \nA. 5:15 \nB. 6:45 \nC. 6:15 \nD. 5:55")
              print(pregunta4)
              arch.write(pregunta4)
              respuesta4 = input("\nRespuesta: ")
              arch.write(f"\nRespuesta: {respuesta4}")
              if respuesta4 == "c" or respuesta4 == "C" or respuesta4 == "6:15":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1
          if escondido[r][c] == 5:
              arch = open("Proyecto final.txt", "a")
              print('¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:')
              pregunta5 =("¿Quién ganó el campeonato de pilotos de la fórmula 1 en 2022? \nA. Max Verstappen \nB. Lewis Hamilton \nC. Sergio Pérez \nD. Charles Leclerc")
              print(pregunta5)
              arch.write(pregunta5)
              respuesta5 = input("\nRespuesta: ")
              arch.write(f"\nRespuesta: {respuesta5}")
              if respuesta5 == "a" or respuesta5 == "A" or respuesta5 == "Max Verstappen" or respuesta5 == "max verstappen" or respuesta5 == "Verstappen" or respuesta5 == "verstappen":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1
          if escondido[r][c] == 7:
              arch = open("Proyecto final.txt", "a")
              print('¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:')
              pregunta7 = ("¿Cuántos huesos tiene el cuerpo humano? \nA. 226 \nB. 216 \nC. 208 \nD. 206")
              print(pregunta7)
              arch.write(pregunta7)
              respuesta7 = input("\nRespuesta: ")
              arch.write(f"\nRespuesta: {respuesta7}")
              if respuesta7 == "d" or respuesta7 == "D" or respuesta7 == "206":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1
          if escondido[r][c] == 8:
              arch = open("Proyecto final.txt", "a")
              print("¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte: ")
              pregunta8 = ("¿Cuál es el río más largo del mundo? \nA. Nilo \nB. Misisipi \nC. Amazonas \nD. Obi")
              print(pregunta8)
              arch.write(pregunta8)
              respuesta8 = input("\nRespuesta: ")
              arch.write(f"\nRespuesta: {respuesta8}")
              if respuesta8 == "c" or respuesta8 == "C" or respuesta8 == "Amazonas" or respuesta8 == "amazonas":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1
          if escondido[r][c] == 10:
              arch = open("Proyecto final.txt", "a")
              print('¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:')
              pregunta10 = ("¿Cuál es el resultado de 3x9 ? \nA. 57 \nB. 27 \nC. 21 \nD. 17")
              print(pregunta10)
              arch.write(pregunta10)
              respuesta10 = input("\nRespuesta:")
              arch.write(f"\nRespuesta: {respuesta10}")
              if respuesta10 == "b" or respuesta10 == "B" or respuesta10 == "27":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1
          if escondido[r][c] == 11:
              arch = open("Proyecto final.txt", "a")
              print('¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:')
              pregunta11 = ("¿Cuál es la montaña más alta del mundo? \nA. Monte Everest \nB. Manaslu \nC. Lhotse \nD. Mauna Kea")
              print(pregunta11)
              arch.write(pregunta11)
              respuesta11 = input("\nRespuesta: ")
              arch.write(f"\nRespuesta: {respuesta11}")
              if respuesta11 == "a" or respuesta11 == "A" or respuesta11 == "Monte Everest" or respuesta11 == "monte everest" or respuesta11 == "Everest" or respuesta11 == "everest":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1
          if escondido[r][c] == 13:
              arch = open("Proyecto final.txt", "a")
              print('¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:')
              pregunta13 = ("¿Dónde está Machu Piccu? \nA. Colombia \nB. Perú \nC. México \nD. Paris")
              print(pregunta13)
              arch.write(pregunta13)
              respuesta13 = input("\nRespuesta: ")
              arch.write(f"\nRespuesta: {respuesta13}")
              if respuesta13 == "b" or respuesta13 == "B" or respuesta13 == "Perú" or respuesta13 == "perú" or respuesta13 == "Peru" or respuesta13 == "peru":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1  
          if escondido[r][c] == 14:
              arch = open("Proyecto final.txt", "a")
              print('¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:')
              pregunta14 = ("¿Cuál es la capital de Australia? \nA. Canberra \nB. Sydney \nC. Melbourne \nD. Perth")
              print(pregunta14)
              arch.write(pregunta14)
              respuesta14 = input("\nRespuesta: ")
              arch.write(f"\nRespuesta: {respuesta14}")
              if respuesta14 == "a" or respuesta14 == "A" or respuesta14 == "Canberra" or respuesta14 == "canberra":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1
          if escondido[r][c] == 15:
              arch = open("Proyecto final.txt", "a")
              print('¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:')
              pregunta15 = ("¿Cuál es la compañía que originalmente se llamaba 'Cadabra'? \nA. UPS \nB. Google \nC. Amazon \nD. Yahoo")
              print(pregunta15)
              arch.write(pregunta15)
              respuesta15 = input("\nRespuesta: ")
              arch.write(f"\nRespuesta: {respuesta15}")
              if respuesta15 == "c" or respuesta15 == "C" or respuesta15 == "Amazon" or respuesta15 == "amazon":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1
          if escondido[r][c] == 16:
              arch = open("Proyecto final.txt", "a")
              print('¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:')
              pregunta16 = ("¿Qué expulsan las plantas por la noche? \nA. Dióxido de carbono \nB. Oxígeno \nC. Agua \nD. Monóxido de carbono")
              print(pregunta16)
              arch.write(pregunta16)
              respuesta16 = input("\nRespuesta: ")
              arch.write(f"\nRespuesta: {respuesta16}")
              if respuesta16 == "a" or respuesta16 == "A" or respuesta16 == "Dióxido de carbono" or respuesta16 == "dioxido de carbono" or respuesta16 == "Dioxido de carbono" or respuesta16 == "dióxido de carbono":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1
          if escondido[r][c] == 17:
              arch = open("Proyecto final.txt", "a")
              print('¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:')
              pregunta17 = ("¿En qué ciudad se encuentra la torre Eiffel? \nA. Vienna \nB. París \nC. Lyon \nD. Niza")
              print(pregunta17)
              arch.write(pregunta17)
              respuesta17 = input("\nRespuesta: ")
              arch.write(f"\nRespuesta: {respuesta17}")
              if respuesta17 == "b" or respuesta17 == "B" or respuesta17 == "París" or respuesta17 == "Paris" or respuesta17 == "parís" or respuesta17 == "paris":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                 arch = open("Proyecto final.txt", "a")
                 eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                 print(eliminacion)
                 arch.write(eliminacion)
                 #Cambiamos el mundo por un corazón roto
                 tablero[r][c] = '\U0001F494'
                 #Devuelvo 1 porque caí en un agujero y perdí una vida
                 return 1
          if escondido[r][c] == 18:
              arch = open("Proyecto final.txt", "a")
              print('¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:')
              pregunta18 = ("¿Cuál es el hueso más pequeño del cuerpo humano? \nA. Yunque \nB. Martillo \nC. Estribo \nD. Fémur")
              print(pregunta18)
              arch.write(pregunta18)
              respuesta18 = input("\nRespuesta: ")
              arch.write(f"\nRespuesta: {respuesta18}")
              if respuesta18 == "c" or respuesta18 == "C" or respuesta18 == "Estribo" or respuesta18 == "estribo":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1
          if escondido[r][c] == 19:
              arch = open("Proyecto final.txt", "a")
              print('¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:')
              pregunta19 = ("¿Cuál es el edificio más alto del mundo? \nA. Empire State Building \nB. Lotte World Tower \nC. Torre de Shanghái \nD. Burj Khalifa")
              print(pregunta19)
              arch.write(pregunta19)
              respuesta19 = input("\nRespuesta: ")
              arch.write(f"\nRespuesta: {respuesta19}")
              if respuesta19 == "d" or respuesta19 == "D" or respuesta19 == "Burj Khalifa":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1
          if escondido[r][c] == 20:
              arch = open("Proyecto final.txt", "a")
              print('¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:')
              pregunta20 = ("¿Cuántos días tiene un año bisiesto? \nA. 366 \nB. 364 \nC. 365 \nD. 363")
              print(pregunta20)
              arch.write(pregunta20)
              respuesta20 = input("\nRespuesta: ")
              arch.write(f"\nRespuesta: {respuesta20}")
              if respuesta20 == "a" or respuesta20 == "A" or respuesta20 == "366":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1
          if escondido[r][c] == 21:
              arch = open("Proyecto final.txt", "a")
              print('¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:')
              pregunta21 = ("¿Cuál es el tipo de sangre que debe tener una persona para ser 'donante universal'? \nA. A+ \nB. O+ \nC. O- \nD. AB+")
              print(pregunta21)
              arch.write(pregunta21)
              respuesta21 = input("\nRespuesta: ")
              arch.write(f"\nRespuesta: {respuesta21}")
              if respuesta21 == "b" or respuesta21 == "B" or respuesta21 == "O+" or respuesta21 == "o+":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1
          if escondido[r][c] == 22:
              arch = open("Proyecto final.txt", "a")
              print('¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:')
              pregunta22 = ("¿Quién es la diosa del amor en la mitología griega? \nA. Venus \nB. Psique \nC. Afrodita \nD. Perséfone")
              print(pregunta22)
              arch.write(pregunta22)
              respuesta22 = input("\nRespuesta: ")
              arch.write(f"\nRespuesta: {respuesta22}")
              if respuesta22 == "c" or respuesta22 == "C" or respuesta22 == "Afrodita" or respuesta22 == "afrodita":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1
          if escondido[r][c] == 23:
              arch = open("Proyecto final.txt", "a")
              print('¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:')
              pregunta23 = ("¿Quién es el fundador de Apple? \nA. Steve Aoki \nB. Steve Jobs \nC. Steve Rogers \nD. Steve Carell")
              print(pregunta23)
              arch.write(pregunta23)
              respuesta23 = input("\nRespuesta: ")
              arch.write(f"\nRespuesta: {respuesta23}")
              if respuesta23 == "b" or respuesta23 == "B" or respuesta23 == "Steve Jobs" or respuesta23 == "steve jobs" or respuesta23 == "Jobs" or respuesta23 == "jobs":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1
          if escondido[r][c] == 24:
              arch = open("Proyecto final.txt", "a")
              print('¡Oh no! Has caído en un hoyo. Responde la siguiente pregunta para salvarte:')
              pregunta24 = ("¿Qué elemento mantiene los huesos fuertes? \nA. Hierro \nB. Flúor \nC. Magnesio \nD. Calcio")
              print(pregunta24)
              arch.write(pregunta24)
              respuesta24 = input("\nRespuesta: ")
              arch.write(f"\nRespuesta: {respuesta24}")
              if respuesta24 == "d" or respuesta24 == "D" or respuesta24 == "Calcio" or respuesta24 == "calcio":
                  arch = open("Proyecto final.txt", "a")
                  salvacion = ("\nCorrecto. Te has salvado!\n\n")
                  print(salvacion)
                  arch.write(salvacion)
                  #Cambiamos el mundo por un corazón
                  tablero[r][c] = '\U0001F5A4'
                  return 0
              else:
                  arch = open("Proyecto final.txt", "a")
                  eliminacion = ("\nIncorrecto. Has perdido una vida\n\n")
                  print(eliminacion)
                  arch.write(eliminacion)
                  #Cambiamos el mundo por un corazón roto
                  tablero[r][c] = '\U0001F494'
                  #Devuelvo 1 porque caí en un agujero y perdí una vida
                  return 1
        else:
            print("Columna inválida")
            return 0
    else:
        print('Renglón inválido')
        return 0
        
            
    #Si en la matriz escondida tengo un 0,3,6,9,12,15 el usuario puede continuar jugando porque no ha caído en un hoyo    
    if escondido[r][c]== 0 or escondido[r][c]== 3 or escondido[r][c]== 6 or escondido[r][c]== 9 or escondido[r][c]== 12 or escondido[r][c]== 15:
        print("Te has salvado! Continúa girando los mundos para ganar")
        #No es hoyo y por lo tanto le pongo un corazón
        tablero[r][c] = '\U0001F5A4'
        return 0

def main():
  #llamamos a la función que da inicio al juego e imprimos su documentación
  print(inicio_juego.__doc__)
  comienzo = inicio_juego()
  #imprimos la documentación de las funciones
  print(limpia.__doc__)
  print(llena_tablero.__doc__)
  print(despliega_tablero.__doc__)
  print(llena_escondido.__doc__)
  print(verifica_cambia.__doc__)
  #llamamos a las funciones que llenan las matrices
  tablero = llena_tablero()
  escondidas =llena_escondido()
  #iniciamos el número de caídas y de oportunidades
  caidas = 0
  oportunidades = 0
  while caidas <4 and oportunidades <13:
    limpia()
    despliega_tablero(tablero)
    print('Escribe la posición del mundo que quieras girar:')
    renglon=int(input('Renglón: '))
    columna=int(input('Columna: '))
    #acumulo en caidas el resultado de verifica
    caidas+=verifica_cambia(renglon,columna, tablero, escondidas)
    oportunidades+=1;
    input('Enter para continuar')
  #aquí acaba el ciclo de verificar el resultado
  limpia()
  #abrimos nuevamente el archivo de texto en modo append para seguir agregando texto
  arch = open("Proyecto final.txt", "a") 
  if caidas == 4:
    mensaje1 =("\n\nHas perdido todas tus vidas :( Mejor suerte para la próxima") 
    print(mensaje1)
    arch.write(mensaje1)
  else:
    mensaje2 =("\n\n\nFelicidades! Has ganado! Sigue demostrando así tus conocimientos :)") 
    print(mensaje2)
    arch.write(mensaje2)
  despliega_tablero(tablero)

main()