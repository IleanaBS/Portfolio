CREATE TABLE contacto_emergencia (
    idContactoEmergencia INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(20),
    direccion VARCHAR(20),
    telefono BIGINT(12),
    RelacionUsuario VARCHAR(20)
);

CREATE TABLE usuario (
    idUsuario INT AUTO_INCREMENT PRIMARY KEY,
    idContactoEmergencia INT,
    nombre VARCHAR(20),
    sexo VARCHAR(20),
    peso FLOAT,
    talla FLOAT,
    IMC FLOAT,
    direccion VARCHAR(20),
    fechaNacimiento DATE,
    CONSTRAINT usuario_fk1 FOREIGN KEY (idContactoEmergencia) REFERENCES contacto_emergencia(idContactoEmergencia)
);

CREATE TABLE catalogo_mediciones
( nombre varchar(20),
  unidad varchar(20),
sensor integer,
 constraint catalogoMediciones_pk PRIMARY KEY (nombre))

CREATE TABLE mediciones
( idMedicion integer,
 idUsuario integer,
 nombre_catalogo_mediciones varchar(20),
 fecha date,
 hora time,
valor float,
 constraint signosVitales_pk PRIMARY KEY (idMedicion, fecha, hora),
 constraint Medicion_fk1 FOREIGN Key (idUsuario) REFERENCES usuario(idUsuario),
 constraint Medicion_fk2 FOREIGN Key (nombre_catalogo_mediciones) REFERENCES catalogo_mediciones(nombre)
);

INSERT VALUES catalogo_mediciones
INSERT INTO catalogo_mediciones VALUES ('Ritmo Cardíaco', 'lpm', 1);
INSERT INTO catalogo_mediciones VALUES ('SPO2', '%', 2);
INSERT INTO catalogo_mediciones VALUES ('Temperatura', '°C', 3);
INSERT INTO catalogo_mediciones VALUES ('Pasos', 'pasos por minuto', 4);
INSERT INTO catalogo_mediciones VALUES ('Tiempo luz', 'segundos', 5);
INSERT INTO catalogo_mediciones VALUES ('Ruido', 'dB', 6);


--QUERIES
--Sexo con la saturación de oxígeno más elevada
SELECT u.sexo, MAX(m.valor) AS max_saturacion_oxigeno
FROM usuario u
JOIN mediciones m ON u.idUsuario = m.idUsuario
WHERE m.nombre_catalogo_mediciones = 'SPO2'
GROUP BY u.sexo;

-- Hora del día en la que disminuye más la frecuencia cardíaca (FC)
SELECT hora, MIN(valor) AS min_fc
FROM mediciones
WHERE nombre_catalogo_mediciones = 'Ritmo Cardíaco'
GROUP BY hora
ORDER BY min_fc ASC
LIMIT 1;


--Edades de usuarios con temperatura mayor a la promedio
SELECT u.nombre, u.fechaNacimiento, TIMESTAMPDIFF(YEAR, u.fechaNacimiento, CURDATE()) AS edad
FROM usuario u
JOIN mediciones m ON u.idUsuario = m.idUsuario
WHERE m.nombre_catalogo_mediciones = 'Temperatura' AND m.valor > (SELECT AVG(valor) FROM Mediciones WHERE nombre_catalogo_mediciones = 'Temperatura');


--IMC más alto registrado
SELECT *
FROM usuario
WHERE IMC = (SELECT MAX(IMC) FROM usuario);


--Promedio de la frecuencia cardíaca por sexo
SELECT u.sexo, AVG(m.valor) AS promedio_fc
FROM usuario u
JOIN mediciones m ON u.idUsuario = m.idUsuario
WHERE m.nombre_catalogo_mediciones = 'Ritmo Cardíaco'
GROUP BY u.sexo;


--Promedio de IMC por sexo
SELECT sexo, AVG(IMC) AS promedio_imc
FROM usuario
GROUP BY sexo;


--Número de personas con 60 años o más
SELECT COUNT(*) AS num_personas
FROM usuario
WHERE TIMESTAMPDIFF(YEAR, fechaNacimiento, CURDATE()) >= 60;


--Usuarios cuya frecuencia cardíaca (FC) sea mayor a 100
SELECT *
FROM usuario u
JOIN mediciones m ON u.idUsuario = m.idUsuario
WHERE m.nombre_catalogo_mediciones = 'Ritmo Cardíaco' AND m.valor > 100;


--Usuarios cuya saturación de oxígeno (SO2) sea menor a 90
SELECT *
FROM usuario u
JOIN mediciones m ON u.idUsuario = m.idUsuario
WHERE m.nombre_catalogo_mediciones = 'SPO2' AND m.valor < 90;