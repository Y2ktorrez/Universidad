create database tienda_libros;
use tienda_libros;

-- area
create table area(
	id tinyint unsigned not null,
	descripcion varchar(30) not null,
	primary key(id)
);

-- lector
create table lector(
	ci int unsigned not null,
	nombre varchar(50) not null,
	sexo char(1) not null,
	telefono int unsigned not null,
	primary key(ci)
);

-- libro
create table libro(
	codigo varchar(5) not null primary key,
	titulo varchar(80) not null,
	año smallint not null,
	id_area tinyint unsigned not null,
	foreign key(id_area) references area(id)
		on delete cascade on update cascade
);

-- prestamo
create table prestamo(
	nro tinyint unsigned not null primary key,
	fecha tinyint unsigned not null,
	dias smallint unsigned not null,
	monto smallint unsigned not null,
	ci_lector int unsigned not null,
	foreign key(ci_lector) references lector(ci)
		on delete cascade on update cascade 
);

-- detalle_prestamo
create table detalle_prestamo(
	nro_prestamo tinyint unsigned not null,
	cod_libro varchar(5) not null,
	primary key(nro_prestamo, cod_libro),
	foreign key(nro_prestamo) references prestamo(nro)
		on delete cascade on update cascade,
	foreign key(cod_libro) references libro(codigo)
		on delete cascade on update cascade
);

/***INSERTAR DATOS***/

-- area
insert into area(id, descripcion) values
(1,'Matematicas'),
(2,'Computacion'),
(3,'Fisica');

-- libro
insert into libro(codigo, titulo, año, id_area) values
('L01', 'Matematica Aplicada', 2010, 1),
('L02', 'Algoritmos y Programas', 2010, 2),
('L03', 'Excel Avanzado', 2007, 2),
('L04', 'Introduccion a la Fisica', 2010, 3),
('L05', 'Matematica 1', 2009, 1);

-- prestamo
insert into prestamo values
(1, 15/05/2011, 2, 10, 103),
(2, 17/05/2011, 2, 20, 101),
(3, 17/05/2011, 1 , 15, 102),
(4, 19/05/2011, 2, 20, 103);

-- lector 
insert into lector(ci, nombre, sexo, telefono) values
(101, 'Joaquin Chumacero Yapacani', 'M', 3567587),
(102, 'Patricia Aguilera Candia', 'F', 7098899),
(103, 'Saturdino Mamani Rodriguez','M',5677765);

-- detalle_prestamo
insert into detalle_prestamo(nro_prestamo, cod_libro) values 
(1, 'L01'),
(2, 'L02'),
(2, 'L03'),
(3, 'L01'),
(3, 'L03'),
(4, 'L03');

/***CONSULTAS***/

-- Mostrar todos los libros prestados del area de computacion mayores al año 2009 a 'Saturdino Mamani Rodriguez'

select libro.*
from lector, prestamo, detalle_prestamo, libro, area
where lector.ci = prestamo.ci_lector and prestamo.nro = detalle_prestamo.nro_prestamo and 
	  detalle_prestamo.cod_libro = libro.codigo and libro.id_area = area.id and 
	  area.descripcion = 'Computacion' and libro.año > 2009 and lector.nombre = 'Saturdino Mamani Rodriguez';
	  
select *
from libro 
order by codigo 


