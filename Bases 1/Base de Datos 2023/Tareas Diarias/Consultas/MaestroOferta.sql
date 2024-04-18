create database maestrooferta;
use maestrooferta;

create table materia(
	sigla varchar(6) not null primary key,
    nombre varchar(60) not null
);

create table docente(
	codigo int not null primary key,
    nombre varchar(60) not null 
);

create table periodo(
	id tinyint not null primary key,
    nombre varchar(60) not null,
    año smallint not null
);

create table grupo(
	id int not null primary key,
    nombre varchar(2) not null,
    siglamateria varchar(6) not null,
    codocente int not null,
    idperiodo tinyint not null,
    foreign key(siglamateria) references materia(sigla)
		on delete cascade on update cascade,
	foreign key(codocente) references docente(codigo)
		on delete cascade on update cascade,
	foreign key(idperiodo) references periodo(id)
		on delete cascade on update cascade
);

create table horario(
	idgrupo int not null,
    id tinyint not null,
    dia varchar(9) not null,
    horaI time not null,
    horaF time not null,
    primary key(idgrupo, id),
    foreign key(idgrupo) references grupo(id)
		on delete cascade on update cascade
);

-- insert de datos

-- MATERIA
insert into materia(sigla, nombre) values ('FIS100','FISICA I');
insert into materia(sigla, nombre) values ('INF110','INTRODUCCION A LA INFORMATICA');
insert into materia(sigla, nombre) values ('INF119','ESTRUCTURAS DISCRETAS');
insert into materia(sigla, nombre) values ('LIN100','INGLES TECNICO I');
insert into materia(sigla, nombre) values ('MAT101','CALCULO I');
insert into materia(sigla, nombre) values ('FIS102','FISICA II');
insert into materia(sigla, nombre) values ('INF120','PROGRAMACION I');
insert into materia(sigla, nombre) values ('MAT102','CALCULO II');
insert into materia(sigla, nombre) values ('MAT103','ALGEBRA LINEAL');
insert into materia(sigla, nombre) values ('FIS200','FISICA III');
insert into materia(sigla, nombre) values ('INF210','PROGRAMACION II');
insert into materia(sigla, nombre) values ('MAT207','ECUACIONES DIFERENCIALES');
insert into materia(sigla, nombre) values ('INF220','ESTRUCTURA DE DATOS I');

-- DOCENTES
insert into docente(codigo, nombre) values (100,'SALAZAR PEREZ TOMAS ALBERTO');
insert into docente(codigo, nombre) values (101,'VEIZAGA GONZALES JOSUE OBED');
insert into docente(codigo, nombre) values (102,'JUAN CARLOS CONTRERAS');
insert into docente(codigo, nombre) values (103,'CACERES CHACON BRAULIO');
insert into docente(codigo, nombre) values (104,'GUTIERREZ BRUNO KATIME ESTHER');
insert into docente(codigo, nombre) values (105,'GUZMAN MOLINA ISABEL MIRIAM');
insert into docente(codigo, nombre) values (106,'ZUÑIGA RUIZ WILMA');
insert into docente(codigo, nombre) values (107,'VALDELOMAR ORELLANA TOMAS');
insert into docente(codigo, nombre) values (108,'MIRANDA CARRASCO CARLOS');
insert into docente(codigo, nombre) values (109,'ZEBALLOS PAREDES DANIEL LUIS');
insert into docente(codigo, nombre) values (110,'PEINADO PEREIRA MIGUEL JESUS');
insert into docente(codigo, nombre) values (111,'MOLLO MAMANI ALBERTO');
insert into docente(codigo, nombre) values (112,'LAZO ARTEAGA CARLOS ROBERTO');
insert into docente(codigo, nombre) values (113,'CORTEZ UZEDA JULIO MARTIN');
insert into docente(codigo, nombre) values (114,'ROSALES FUENTES JORGE MARCELO');
insert into docente(codigo, nombre) values (115,'AVENDAÑO GONZALES EUDAL');
insert into docente(codigo, nombre) values (116,'CAMPOS BARRERA MARIO');

-- PERIODO
insert into periodo values (1,2,2023);

-- GRUPO
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values (1,'Z6','FIS100',100,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (2,'SI','INF110',101,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (3,'SZ','INF110',102,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (4,'Z2','INF119',103,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (5,'SK','INF119',104,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (6,'NX','LIN100',105,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (7,'Z3','LIN100',106,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (8,'Z4','MAT101',107,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (9,'Z3','MAT101',108,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (10,'BI','FIS102',109,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (12,'SH','INF120',110,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (13,'SI','INF120',111,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (14,'SB','MAT102',112,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (15,'SA','MAT103',113,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (16,'SB','MAT103',113,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values (17,'SC','MAT103',113,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (18,'SD','MAT103',113,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (19,'SA','INF210',102,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (20,'SB','INF210',102,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (21,'SC','INF210',102,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (22,'SC','FIS200',114,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values  (23,'SC','MAT207',115,1);
insert into grupo(id, nombre, siglamateria, codocente, idperiodo) values (24,'SB','INF220',116,1);

-- HORARIO
insert into horario(idgrupo, id, dia, horaI, horaF) values (1,1,'LUNES','10:00','11:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (1,2,'MIERCOLES','10:00','11:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (1,3,'VIERNES','10:00','11:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (1,4,'SABADO','18:15','19:45');
insert into horario(idgrupo, id, dia, horaI, horaF) values (2,1,'MARTES','09:15','11:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (2,2,'JUEVES','09:15','11:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (3,1,'LUNES','07:00','08:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (3,2,'MIERCOLES','07:00','08:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (3,3,'VIERNES','07:00','08:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (4,1,'LUNES','08:30','10:00');
insert into horario(idgrupo, id, dia, horaI, horaF) values (4,2,'MIERCOLES','08:30','10:00');
insert into horario(idgrupo, id, dia, horaI, horaF) values (4,3,'VIERNES','08:30','10:00');
insert into horario(idgrupo, id, dia, horaI, horaF) values (5,1,'MARTES','07:00','09:15');
insert into horario(idgrupo, id, dia, horaI, horaF) values (5,2,'JUEVES','07:00','09:15');
insert into horario(idgrupo, id, dia, horaI, horaF) values (6,1,'MARTES','07:00','09:15');
insert into horario(idgrupo, id, dia, horaI, horaF) values (6,2,'JUEVES','07:00','09:15');
insert into horario(idgrupo, id, dia, horaI, horaF) values (7,1,'MARTES','13:45','16:00');
insert into horario(idgrupo, id, dia, horaI, horaF) values (7,2,'JUEVES','13:45','16:00');
insert into horario(idgrupo, id, dia, horaI, horaF) values (8,1,'MARTES','13:45','16:00');
insert into horario(idgrupo, id, dia, horaI, horaF) values (8,2,'JUEVES','13:45','16:00');
insert into horario(idgrupo, id, dia, horaI, horaF) values (9,1,'MARTES','16:00','18:15');
insert into horario(idgrupo, id, dia, horaI, horaF) values (9,2,'JUEVES','16:00','18:15');
insert into horario(idgrupo, id, dia, horaI, horaF) values (10,1,'MARTES','07:00','09:15');
insert into horario(idgrupo, id, dia, horaI, horaF) values (10,2,'JUEVES','07:00','09:15');
insert into horario(idgrupo, id, dia, horaI, horaF) values (10,3,'VIERNES','18:15','19:45');
insert into horario(idgrupo, id, dia, horaI, horaF) values (11,1,'MARTES','18:15','20:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (11,2,'MIERCOLES','20:30','22:00');
insert into horario(idgrupo, id, dia, horaI, horaF) values (11,3,'JUEVES','18:15','20:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (12,1,'MARTES','16:00','18:15');
insert into horario(idgrupo, id, dia, horaI, horaF) values (12,2,'JUEVES','16:00','18:15');
insert into horario(idgrupo, id, dia, horaI, horaF) values (13,1,'LUNES','07:00','08:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (13,2,'MIERCOLES','07:00','08:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (13,3,'VIERNES','07:00','08:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (14,1,'MARTES','20:30','22:45');
insert into horario(idgrupo, id, dia, horaI, horaF) values (14,2,'JUEVES','20:30','22:45');
insert into horario(idgrupo, id, dia, horaI, horaF) values (15,1,'LUNES','08:30','10:00');
insert into horario(idgrupo, id, dia, horaI, horaF) values (15,2,'MIERCOLES','08:30','10:00');
insert into horario(idgrupo, id, dia, horaI, horaF) values (15,3,'VIERNES','08:30','10:00');
insert into horario(idgrupo, id, dia, horaI, horaF) values (16,1,'LUNES','10:00','11:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (16,2,'MIERCOLES','10:00','11:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (16,3,'VIERNES','10:00','11:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (17,1,'LUNES','07:00','08:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (17,2,'MIERCOLES','07:00','08:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (17,3,'VIERNES','07:00','08:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (18,1,'LUNES','11:30','13:00');
insert into horario(idgrupo, id, dia, horaI, horaF) values (18,2,'MIERCOLES','11:30','13:00');
insert into horario(idgrupo, id, dia, horaI, horaF) values (18,3,'VIERNES','11:30','13:00');
insert into horario(idgrupo, id, dia, horaI, horaF) values (19,1,'MARTES','13:45','16:00');
insert into horario(idgrupo, id, dia, horaI, horaF) values (19,2,'JUEVES','13:45','16:00');
insert into horario(idgrupo, id, dia, horaI, horaF) values (20,1,'MARTES','09:15','11:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (20,2,'JUEVES','09:15','11:30');
insert into horario(idgrupo, id, dia, horaI, horaF) values (21,1,'MARTES','07:00','09:15');
insert into horario(idgrupo, id, dia, horaI, horaF) values (21,2,'JUEVES','07:00','09:15');
insert into horario(idgrupo, id, dia, horaI, horaF) values (22,1,'LUNES','15:15','16:45');
insert into horario(idgrupo, id, dia, horaI, horaF) values (22,2,'MIERCOLES','15:15','16:45');
insert into horario(idgrupo, id, dia, horaI, horaF) values (22,3,'VIERNES','15:15','16:45');
insert into horario(idgrupo, id, dia, horaI, horaF) values (22,4,'VIERNES','21:15','22:45');
insert into horario(idgrupo, id, dia, horaI, horaF) values (23,1,'MARTES','20:30','22:45');
insert into horario(idgrupo, id, dia, horaI, horaF) values (23,2,'JUEVES','20:30','22:45');
insert into horario(idgrupo, id, dia, horaI, horaF) values (24,1,'MARTES','20:30','22:45');
insert into horario(idgrupo, id, dia, horaI, horaF) values (24,2,'JUEVES','20:30','22:45');


