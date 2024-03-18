import tkinter as tk
from tkinter import messagebox
import mysql.connector
import random
from datetime import datetime

# # Conéctate a la base de datos en XAMPP LOCAL 
# conexion = mysql.connector.connect(
#     host="127.0.0.1",
#     user="root",
#     password="",
#     database="prueba2"
# )

# Conéctate a la base de datos en XAMPP GOOGLE
conexion = mysql.connector.connect(
    host="34.30.238.8",
    user="usuario1",
    password="AmongUsWatch123",
    database="AmongUsWatch"
)

# Crea el cursor para interactuar con la base de datos
cursor = conexion.cursor()

# Función para generar un número aleatorio como id y mostrarlo en el mensaje
def generar_id_contacto():
    id_contacto = random.randint(10000, 99999)
    messagebox.showinfo("ID de Contacto de Emergencia", f"El ID de contacto de emergencia generado es: {id_contacto}\nGuárdelo para futuras referencias.")
    entry_id_contacto.delete(0, tk.END)
    entry_id_contacto.insert(0, id_contacto)

    # Forzar una actualización de la interfaz para que muestre la primera ventana antes de continuar
    ventana.update()

    mostrar_ventana_registro_usuario(id_contacto)

# Función para guardar los datos de contacto de emergencia
def guardar_contacto_emergencia():
    id_contacto = entry_id_contacto.get()
    nombre_contacto = entry_nombre_contacto.get()
    direccion_contacto = entry_direccion_contacto.get()
    telefono_contacto = entry_telefono_contacto.get()
    relacion_contacto = entry_relacion_contacto.get()

    # Inserta los datos de contacto en la tabla de contacto_emergencia
    consulta = "INSERT INTO contacto_emergencia (idContactoEmergencia, nombre, direccion, telefono, relacionUsuario) VALUES (%s, %s, %s, %s, %s)"
    valores = (id_contacto, nombre_contacto, direccion_contacto, telefono_contacto, relacion_contacto)

    try:
        cursor.execute(consulta, valores)
        conexion.commit()
        messagebox.showinfo("Éxito", f"Datos de contacto de emergencia guardados correctamente. ID de Contacto: {id_contacto}")
    except Exception as e:
        messagebox.showerror("Error", f"No se pudo guardar los datos de contacto de emergencia: {e}")

# Función para mostrar la ventana de registro de datos personales del usuario
def mostrar_ventana_registro_usuario(id_contacto):
    # Configuración de la ventana principal
    ventana_usuario = tk.Toplevel(ventana)
    ventana_usuario.title("Registro de Datos de Usuario")

    # Crear etiquetas y campos de entrada para datos personales
    tk.Label(ventana_usuario, text="idUsuario:").grid(row=0, column=0, padx=10, pady=5)
    entry_id_usuario = tk.Entry(ventana_usuario)
    entry_id_usuario.grid(row=0, column=1, padx=10, pady=5)

    tk.Label(ventana_usuario, text="Nombre:").grid(row=1, column=0, padx=10, pady=5)
    entry_nombre = tk.Entry(ventana_usuario)
    entry_nombre.grid(row=1, column=1, padx=10, pady=5)

    tk.Label(ventana_usuario, text="Sexo:").grid(row=2, column=0, padx=10, pady=5)
    entry_sexo = tk.Entry(ventana_usuario)
    entry_sexo.grid(row=2, column=1, padx=10, pady=5)

    tk.Label(ventana_usuario, text="Peso (kg):").grid(row=3, column=0, padx=10, pady=5)
    entry_peso = tk.Entry(ventana_usuario)
    entry_peso.grid(row=3, column=1, padx=10, pady=5)

    tk.Label(ventana_usuario, text="Talla (m):").grid(row=4, column=0, padx=10, pady=5)
    entry_talla = tk.Entry(ventana_usuario)
    entry_talla.grid(row=4, column=1, padx=10, pady=5)

    tk.Label(ventana_usuario, text="Dirección:").grid(row=5, column=0, padx=10, pady=5)
    entry_direccion = tk.Entry(ventana_usuario)
    entry_direccion.grid(row=5, column=1, padx=10, pady=5)

    tk.Label(ventana_usuario, text="Fecha de Nacimiento (AAAA-MM-DD):").grid(row=6, column=0, padx=10, pady=5)
    entry_fecha_nacimiento = tk.Entry(ventana_usuario)
    entry_fecha_nacimiento.grid(row=6, column=1, padx=10, pady=5)

    # Agregar la entrada para el ID del contacto de emergencia
    tk.Label(ventana_usuario, text="ID del Contacto de Emergencia:").grid(row=7, column=0, padx=10, pady=5)
    entry_id_contacto_usuario = tk.Entry(ventana_usuario)
    entry_id_contacto_usuario.grid(row=7, column=1, padx=10, pady=5)

    # Botón para guardar los datos personales
    tk.Button(ventana_usuario, text="Guardar Datos Personales", command=lambda: guardar_datos_usuario(
        entry_nombre.get(),
        entry_sexo.get(),
        entry_peso.get(),
        entry_talla.get(),
        entry_direccion.get(),
        entry_fecha_nacimiento.get(),
        entry_id_usuario.get(),
        entry_id_contacto_usuario.get(),
    ), height=1, wraplength=150).grid(row=8, column=0, columnspan=2, pady=10)

# Función para calcular el IMC y guardar los datos en la base de datos
def guardar_datos_usuario(nombre, sexo, peso, talla, direccion, fecha_nacimiento, id_usuario, id_contacto_usuario):
    peso = float(peso)  # Convertir a float
    talla = float(talla)  # Convertir a float

    # Calcular el IMC
    IMC = peso / (talla * talla)

    # Inserta los datos en la tabla usuario
    consulta_usuario = "INSERT INTO usuario (idUsuario, nombre, sexo, peso, talla, direccion, fechaNacimiento, IMC, idContactoEmergencia) VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s)"
    valores_usuario = (id_usuario, nombre, sexo, peso, talla, direccion, fecha_nacimiento, IMC, id_contacto_usuario)

    try:
        cursor.execute(consulta_usuario, valores_usuario)
        conexion.commit()

        messagebox.showinfo("Éxito", f"Datos de usuario guardados correctamente.")

        # Llama a la función para guardar el idUsuario en la tabla mediciones
        guardar_id_usuario_en_mediciones(id_usuario)

    except Exception as e:
        messagebox.showerror("Error", f"No se pudo guardar los datos de usuario: {e}")

# Función para guardar el idUsuario en la tabla mediciones
def guardar_id_usuario_en_mediciones(id_usuario):
    # Insertar el idUsuario en la tabla mediciones para los valores 1-6
    for i in range(1, 7):
        # Obtener la fecha y hora actual con los formatos especificados
        fecha_actual = datetime.now().strftime("%Y-%m-%d")
        hora_actual = datetime.now().strftime("%H:%M:%S")
        consulta_mediciones = "INSERT INTO mediciones (idUsuario, idMedicion, fecha, hora) VALUES (%s, %s, %s, %s)"
        valores_mediciones = (id_usuario, i, fecha_actual, hora_actual)

        try:
            cursor.execute(consulta_mediciones, valores_mediciones)
            conexion.commit()
        except Exception as e:
            messagebox.showerror("Error", f"No se pudo registrar el idUsuario en la tabla mediciones: {e}")

# Configuración de la ventana principal
ventana = tk.Tk()
ventana.title("Registro de Datos de Contacto de Emergencia")

# Crear etiquetas y campos de entrada para contacto de emergencia
tk.Label(ventana, text="Id Contacto Emergencia:").grid(row=0, column=0, padx=10, pady=5)
entry_id_contacto = tk.Entry(ventana)
entry_id_contacto.grid(row=0, column=1, padx=10, pady=5)

tk.Label(ventana, text="Nombre:").grid(row=1, column=0, padx=10, pady=5)
entry_nombre_contacto = tk.Entry(ventana)
entry_nombre_contacto.grid(row=1, column=1, padx=10, pady=5)

tk.Label(ventana, text="Dirección:").grid(row=2, column=0, padx=10, pady=5)
entry_direccion_contacto = tk.Entry(ventana)
entry_direccion_contacto.grid(row=2, column=1, padx=10, pady=5)

tk.Label(ventana, text="Teléfono:").grid(row=3, column=0, padx=10, pady=5)
entry_telefono_contacto = tk.Entry(ventana)
entry_telefono_contacto.grid(row=3, column=1, padx=10, pady=5)

tk.Label(ventana, text="Relación:").grid(row=4, column=0, padx=10, pady=5)
entry_relacion_contacto = tk.Entry(ventana)
entry_relacion_contacto.grid(row=4, column=1, padx=10, pady=5)

# Botón para guardar los datos de contacto de emergencia
tk.Button(ventana, text="Guardar Contacto de Emergencia", command=guardar_contacto_emergencia, height=1, wraplength=150).grid(row=5, column=0, columnspan=2, pady=10)

# Generar el id de contacto de emergencia aleatoriamente
generar_id_contacto()

# Iniciar la interfaz
ventana.mainloop()