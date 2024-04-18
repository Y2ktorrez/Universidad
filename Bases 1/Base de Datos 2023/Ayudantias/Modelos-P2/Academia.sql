create database academia;
use academia;

create table curso(
	codigo int unsigned not null,
	nombre varchar(60) not null,
	codigoPrerequisito int unsigned,
	primary key(codigo),
	foreign key(codigoPrerequisito) references curso(codigo)
		on delete cascade on update cascade 
);


create table edicion(
	id int unsigned not null,
	nombre varchar(60) not null,
	cupo int unsigned not null,
	codigoCurso int unsigned not null,
	ciDocente int unsigned not null,
	primary key(id),
	foreign key(codigoCurso) references curso(codigo)
		on delete cascade on update cascade,
	foreign key(ciDocente) references persona(ci)
		on delete cascade on update cascade
);

create table persona(
	ci int unsigned not null,
	nombre varchar(60) not null,
	sexo char not null,
	primary key(ci)
);

 
-- Insercion de Datos

-- Curso
insert into curso (codigo, nombre, codigoPrerequisito) values
(100, 'Introduccion a la Programacion', NULL),
(101, 'Programacion 1', 100),
(102, 'Programacion Modular', 100),
(103, 'Matematica Basica', NULL),
(104, 'Calculo 1', 103);

-- Persona 
-- Primera persona
insert into  persona (ci, nombre, sexo) values 
(111, 'Joaquin Chumacero', 'm');
-- Segunda persona
insert into persona (ci, nombre, sexo) values 
(222, 'Fabiola Mendez', 'f');
-- Tercera persona
insert into  persona (ci, nombre, sexo) values 
(333, 'Saturnimo Mamani', 'm');
-- Cuarta persona
insert into  persona (ci, nombre, sexo) values 
(444, 'Patricia Aguilera', 'f');
-- Quinta persona
insert into  persona (ci, nombre, sexo) values 
(555, 'Carla Figueroa', 'f');

-- Edicion
insert into edicion (id, nombre, cupo, codigoCurso, ciDocente) values
(1, 'A', 50, 100, 111),
(2, 'B', 60, 102, 111),
(3, 'C', 80, 102, 222);

