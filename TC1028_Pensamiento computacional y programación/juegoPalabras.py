import random
import time 
def seleccionar_palabra():
    '''Función para seleccionar una palabra aleatoria del arreglo'''
    palabras = [
        ['ballena', 'leon', 'pantera', 'elefante', 'aguila', 'conejo', 'avestruz'],
        ['alemania','dinamarca', 'japon', 'rumania', 'vietnam', 'egipto', 'ecuador'],
        ['toronja', 'aguacate', 'durazno', 'naranja', 'guayaba', 'mango', 'sandia'],
        ['atletismo', 'ciclismo', 'hockey', 'voleibol', 'natacion', 'rugby', 'golf'],
        ['trompeta', 'bombo', 'violin', 'guitarra', 'arpa', 'piano', 'clarinete']
        ]
    renglon = random.randint(0, len(palabras)-1)
    columna = random.randint(0, len(palabras[0])-1)
    palabra = palabras[renglon][columna]
    
    if renglon == 0:
        categ = 'Animales'
    elif renglon == 1:
        categ = 'Países'
    elif renglon == 2:
        categ = 'Frutas'
    elif renglon == 3:
        categ = 'Deportes'
    elif renglon == 4:
        categ = 'Instrumentos'
    return palabra, categ

def revolver_palabra(palabra):
    '''Función para revolver la palabra seleccionada'''
    palabra_revuelta = ''.join(random.sample(palabra, len(palabra)))
    return palabra_revuelta

def registro_jugadores():
    '''Función para registrar cantidad de jugadores y sus nombres'''
    cant_jugadores = int(input('Cantidad de jugadores: '))
    while cant_jugadores > 4 or cant_jugadores < 2:
        print('Número no válido de jugadores')
        cant_jugadores = int(input('Cantidad de jugadores: '))
    
    '''registro de jugadores'''
    jugadores = []
    for i in range(1,cant_jugadores+1):
        nom = input('Nombre de jugador ' +str(i) + ': ')
        jugadores.append(nom)
    return jugadores

def partida(jugadores):
    '''Función para definir nivel de partida'''
    nivel = input('''a) Nivel principiante: categoría
b) Nivel fácil: sin categoría
c) Nivel intermedio: categoría y tiempo contado
d) Nivel difícil: sin categoría y tiempo contado
 ''')
    nivel = nivel.lower()
    if nivel == 'a':
        return nivel_principiante(jugadores)
    elif nivel == 'b':
        return nivel_facil(jugadores)
    elif nivel == 'c':
        return nivel_intermedio(jugadores)
    elif nivel == 'd':
        return nivel_dificil(jugadores)
        
def nivel_principiante(jugadores):
    '''Función nivel principiante'''
    puntaje_total = []
    # Iteración de rondas
    for i in range(5):
        # Iteración de jugadores
        puntaje_ronda = []
        for nombre in jugadores:
            palabra_ordenada,categoria = seleccionar_palabra()
            palabra_revuelta = revolver_palabra(palabra_ordenada)
            print('La categoría para tu palabra es:', categoria)
            print('Tu palabra es:', palabra_revuelta)
            print('Tienes dos intentos para ingresar la respuesta correcta\n')
            # Iteración de intentos
            for k in range(2):
                resp = input('Turno de '+str(nombre)+': ')
                resp = resp.lower()
                resp = resp.split()
                resp = ''.join(resp)
                if resp == palabra_ordenada and k == 0:
                    puntaje_ronda.append(5)
                    print('¡¡¡Respuesta correcta!!!\n')
                    break
                elif resp == palabra_ordenada and k == 1:
                    puntaje_ronda.append(3)
                    print('¡¡¡Respuesta correcta!!!\n')
                elif resp != palabra_ordenada and k == 0:
                    print('Respuesta incorrecta')
                    print('Te queda un intento\n')
                else:
                    print('Respuesta incorrecta\n')
                    puntaje_ronda.append(0)
        puntaje_total.append(puntaje_ronda)
    return puntaje_total

def nivel_facil(jugadores):
    '''Función nivel fácil'''
    puntaje_total = []
    # Iteración de rondas
    for i in range(5):
        # Iteración de jugadores
        puntaje_ronda = []
        for nombre in jugadores:
            palabra_ordenada,categoria = seleccionar_palabra()
            palabra_revuelta = revolver_palabra(palabra_ordenada)
            print('Tu palabra es:', palabra_revuelta)
            print('Tienes dos intentos para ingresar la respuesta correcta')
            # Iteración de intentos
            for k in range(2):
                resp = input('Turno de '+str(nombre)+': ')
                resp = resp.lower()
                resp = resp.split()
                resp = ''.join(resp)
                if resp == palabra_ordenada and k == 0:
                    puntaje_ronda.append(5)
                    print('¡¡¡Respuesta correcta!!!\n')
                    break
                elif resp == palabra_ordenada and k == 1:
                    puntaje_ronda.append(3)
                    print('¡¡¡Respuesta correcta!!!\n')
                elif resp != palabra_ordenada and k == 0:
                    print('Respuesta incorrecta')
                    print('Te queda un intento\n')
                else:
                    print('Respuesta incorrecta\n')
                    puntaje_ronda.append(0)
        puntaje_total.append(puntaje_ronda)
    return puntaje_total

def nivel_intermedio(jugadores):
    '''Función nivel intermedio'''
    puntaje_total = []
    # Iteración de rondas
    for i in range(5):
        # Iteración de jugadores
        puntaje_ronda = []
        for nombre in jugadores:
            palabra_ordenada,categoria = seleccionar_palabra()
            palabra_revuelta = revolver_palabra(palabra_ordenada)
            print('La categoría para tu palabra es:', categoria)
            print('Tu palabra es:', palabra_revuelta)
            print('Tienes dos intentos y 10 segundos \
para ingresar la respuesta correcta')
            correcta = 'no'
            # Iteración de intentos
            for k in range(2):
                inicio = time.time()
                difer = 0
                while difer <= 10:
                    resp = input('Turno de '+str(nombre)+': ')
                    resp = resp.lower()
                    resp = resp.split()
                    resp = ''.join(resp)
                    fin = time.time()
                    difer = fin - inicio
                    if resp == palabra_ordenada:
                        correcta = 'si'
                        break
                    
                if correcta == 'si' and difer <= 10 and k == 0:
                    puntaje_ronda.append(5)
                    print('¡¡¡Respuesta correcta!!!\n')
                    break
                elif correcta == 'si' and difer <= 10 and k == 1:
                    puntaje_ronda.append(3)
                    print('¡¡¡Respuesta correcta!!!\n')
                elif difer > 10 and k == 0:
                    print('Se acabó el tiempo')
                    print('Te queda un intento\n')
                elif difer > 10 and k == 1:
                    print('Se acabó el tiempo')
                    print('Ya no tienes más intentos\n')
                    puntaje_ronda.append(0)
        puntaje_total.append(puntaje_ronda)
    return puntaje_total

def nivel_dificil(jugadores):
    '''Función nivel difícil'''
    puntaje_total = []
    # Iteración de rondas
    for i in range(5):
        # Iteración de jugadores
        puntaje_ronda = []
        for nombre in jugadores:
            palabra_ordenada,categoria = seleccionar_palabra()
            palabra_revuelta = revolver_palabra(palabra_ordenada)
            print('Tu palabra es:', palabra_revuelta)
            print('Tienes dos intentos y 10 segundos \
para ingresar la respuesta correcta')
            correcta = 'no'
            # Iteración de intentos
            for k in range(2):
                inicio = time.time()
                difer = 0
                while difer <= 10:
                    resp = input('Turno de '+str(nombre)+': ')
                    resp = resp.lower()
                    resp = resp.split()
                    resp = ''.join(resp)
                    fin = time.time()
                    difer = fin - inicio
                    if resp == palabra_ordenada:
                        correcta = 'si'
                        break
                    
                if correcta == 'si' and difer <= 10 and k == 0:
                    puntaje_ronda.append(5)
                    print('¡¡¡Respuesta correcta!!!\n')
                    break
                elif correcta == 'si' and difer <= 10 and k == 1:
                    puntaje_ronda.append(3)
                    print('¡¡¡Respuesta correcta!!!\n')
                elif difer > 10 and k == 0:
                    print('Se acabó el tiempo')
                    print('Te queda un intento\n')
                elif difer > 10 and k == 1:
                    print('Se acabó el tiempo')
                    print('Ya no tienes más intentos\n')
                    puntaje_ronda.append(0)
        puntaje_total.append(puntaje_ronda)
    return puntaje_total

def generar_marcador(matriz_puntaje,lista_jugadores):
    '''Función para generar marcador'''
    lista_jugadores.insert(0,'Rondas')
    r = len(matriz_puntaje)
    c = len(matriz_puntaje[0])
    
    matriz_str = []
    for reng in range(r):
        renglon = []
        for col in range(c):
            num = str(matriz_puntaje[reng][col])
            renglon.append(num)
        matriz_str.append(renglon)
            
    c = c*10 + 16 
    print('MARCADOR\n'.center(c))
    for reng in lista_jugadores: # Imprime renglón de jugadores
        renglon = ''.join(reng)
        print(renglon.center(11),end=' ')
    print('')

    cont = 1    
    for reng in matriz_str: #Imprime renglones de rondas
        renglon = '     |     '.join(reng)
        print('_'*c)
        print('Ronda  ',cont,'|     ',renglon)
        cont+= 1
    print('_'*c,'\n')
    del lista_jugadores[0] 
    
    
def conteo_puntaje(matriz_puntaje):
    '''Función para sumar los puntos de cada ronda'''
    r = len(matriz_puntaje)
    c = len(matriz_puntaje[0])
    
    puntaje_final = []
    for col in range(c):
        columna = []
        suma = 0
        for reng in range(r):
            suma += matriz_puntaje[reng][col]
        puntaje_final.append(suma)
    return puntaje_final

def jugador_ganador(puntaje_final,arreglo_jugadores):
    '''Función para definir al ganador'''
    r = len(puntaje_final)
    mayor = 0
    cont = 0
    for puntaje in puntaje_final:
        # Identificar ganador o empate
        if puntaje > mayor: 
            mayor = puntaje
        elif puntaje == mayor:
            cont+=1
        
    if mayor != 0 and cont > 0:
        ganador_final = 'EMPATE'
    elif mayor != 0 :
        num_ganador = puntaje_final.index(mayor)
        ganador_final = arreglo_jugadores[num_ganador]
    elif mayor == 0:
        ganador_final = 'No hubieron respuestas correctas'

    return ganador_final

        
def continuacion():
    '''Función para decidir si termina y continúa el juego'''
    print('''1) Terminar juego
2) Otra partida
''')
    dec_partida = int(input())
    if dec_partida == 2:
        main()
    else:
        print('¡Gracias por jugar!')
        
def main():
    '''Función principal que llama a las demás funciones'''
    jugadores = registro_jugadores()
    palabra_seleccionada, categoria = seleccionar_palabra()
    palabra_partida = revolver_palabra(palabra_seleccionada)
    
    marcador = partida(jugadores)
    puntos_contados = conteo_puntaje(marcador)
    generar_marcador(marcador, jugadores)
    
    ganador = jugador_ganador(puntos_contados,jugadores)
    if ganador != 'EMPATE' and ganador != 'No hubieron respuestas correctas':
        print('¡El ganador es ' + str(ganador).upper() + '!\n')
    else:
        print(ganador)
    continuacion()

main()