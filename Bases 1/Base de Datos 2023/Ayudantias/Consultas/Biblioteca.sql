create database biblioteca;
use biblioteca;

create table cliente(
	ci int unsigned not null primary key,
    nombre varchar(50),
    telefono int,
    direccion varchar(60)
);

create table libro(
	id int unsigned not null primary key,
    nombre varchar(60) not null
);

create table area(
	id int unsigned not null primary key,
    nombre varchar(60),
    descripcion varchar(60)
);

create table libroArea(
	idlibro int unsigned not null,
    idarea int unsigned not null,
    primary key(idlibro, idarea),
    foreign key(idlibro) references libro(id)
		on delete cascade  on update cascade,
	foreign key(idarea) references area(id)
		on delete cascade on update cascade
);

create table fichaprestamo(
	nro int not null primary key,
    fechainicio date not null,
    fechafin date not null,
    cicliente int unsigned not null,
    id_libro int unsigned not null,
    foreign key(cicliente) references cliente(ci)
		on update cascade on delete cascade,
	foreign key(id_libro) references libro(id)
		on update cascade on delete cascade
);

-- POBLACION DE LAS TABLAS 

-- Clientes
insert into cliente (ci, nombre, telefono, direccion) values
(8148205, 'Emanuel Gutierrez', 64493552, 'Alto San Pedro'),
(9128129, 'Jacinto Perez', 78923487, 'Villa Warnes'),
(4278821, 'Juanito Alcachofa', 78958734, 'Lujan'),
(9172836, 'Maria del Carmen', 78234673, 'Ramada'),
(6249217, 'Jak Nivel', 76723434, 'Cuchilla');

-- Libros
insert into libro (id, nombre) value
(1, 'Matematica Aplicada'),
(2, 'Introduccion a Pascal'),
(3, 'Fisica Mecanica'),
(4, 'Algebra Lineal'),
(5, 'Aprendiendo sql'),
(6, 'Finanzas para la empresa'),
(7, 'Economia'),
(8, 'Investigacion de las operaciones'),
(9, 'Calculo diferencial'),
(10, 'Java para ingenieros');

-- area
insert into area (id, nombre, descripcion) value
(1, 'Matematica', 'Libros de matematica'), 
(2, 'Fisica', 'Libros de fisica'),
(3, 'Finanzas', 'Libros de finanzas'),
(4, 'Programacion', 'Libros de programacion');

-- libro_area
insert into libroArea (idlibro, idarea) value
(1, 1),
(2, 4),
(3, 2),
(4, 1),
(5, 4),
(6, 3),
(7, 3),
(7, 1),
(8, 1),
(8, 3),
(9, 1),
(10, 4);

-- ficha prestamo
insert into fichaprestamo values
(1, '2023-02-15', '2023-02-20', 8148205, 1),
(2, '2023-02-17', '2023-02-25', 9128129, 3),
(3, '2023-02-25', '2023-03-01', 4278821, 2),
(4, '2023-03-01', '2023-03-24', 9172836, 1),
(5, '2023-03-07', '2023-03-11', 8148205, 1),  
(6, '2023-03-07', '2023-03-11', 6249217, 6),
(7, '2023-03-22', '2023-03-30', 8148205, 4),
(8,'2023-03-22', '2023-03-30',  6249217, 10),
(9, '2023-04-01', '2023-04-03', 6249217, 3),
(10, '2023-04-01', '2023-04-05', 4278821, 1);

-- Consultas
# 1. Listar todos los libros que pertenecen al area de 'Matematica'.

select libro. *  -- libro. 
from libro, area, libroArea
where libro.id = libroArea.idlibro and area.id = libroArea.idarea
      and area.nombre = 'Matematica';

select *
from libro
where id in (select idlibro
				from libroArea
				where idarea in (select id
									from area
									where nombre = 'Matematica'
								)
			);

# 2. Listar los clientes que se han llevado libros
select distinct(cliente.ci), cliente.nombre
from cliente, fichaprestamo
where cliente.ci=fichaprestamo.cicliente;

select distinct cliente.ci, cliente.nombre
from cliente
where cliente.ci in (select fichaprestamo.cicliente
						from fichaprestamo
);

# 3. Listar los clientes que se llevaron libros y muestren que libros se llevaron
select cliente.nombre, libro.nombre
from cliente, fichaprestamo, libro
where cliente.ci = fichaprestamo.cicliente and fichaprestamo.id_libro = libro.id;

# 4. Mostrar los clientes cuyo nombre empiezen en J
select cliente.ci, cliente.nombre  -- select *
from cliente
where nombre like 'J%';

# 5. Mostrar los clientes que llevaron el libro de 'Matematica Aplicada'
select distinct cliente.ci, cliente.nombre
from cliente, fichaprestamo, libro
where cliente.ci = fichaprestamo.cicliente and fichaprestamo.id_libro = libro.id
      and libro.nombre = 'Matematica Aplicada';

# 6. Mostrar la cantidad de clientes que llevaron el libro de 'Fisica Mecania'
select count(distinct(cliente.ci))
from libro, fichaprestamo, cliente
where libro.id = fichaprestamo.id_libro and fichaprestamo.cicliente = cliente.ci
	  and libro.nombre = 'Fisica Mecania';

# 7. Mostrar los datos del primer cliente que se llevo el libro 'Matematica Aplicada'
select cliente.*
from cliente, libro, fichaprestamo
where cliente.ci = fichaprestamo.cicliente and fichaprestamo.id_libro = libro.id
      and libro.nombre = 'Matematica Aplicada' 
      and fichaprestamo.fechainicio in (	select min(fechainicio)
											from fichaprestamo, libro
                                            where fichaprestamo.id_libro = libro.id and libro.nombre = 'Matematica Aplicada'
										);
      
# 8. Mostrar el ultimo libro que se llevo 'Emanuel Gutierrez'
select libro.*
from libro, fichaprestamo, cliente
where libro.id = fichaprestamo.id_libro and fichaprestamo.cicliente = cliente.ci
      and cliente.nombre = 'Emanuel Gutierrez' and fichaprestamo.fechainicio
      in (	select max(fechainicio)
			from fichaprestamo, cliente 
            where cliente.ci = fichaprestamo.cicliente and cliente.nombre = 'Emanuel Gutierrez'
			);

SELECT l.*
FROM libro l, fichaprestamo fp
WHERE fp.cicliente = (SELECT ci FROM cliente WHERE nombre = 'Emanuel Gutierrez')
    AND fp.id_libro = l.id
    AND fp.fechainicio = (SELECT MAX(fechainicio) FROM fichaprestamo WHERE cicliente = fp.cicliente);

# 9. Mostrar la cantidad de libros distinto que se llevo cada cliente
select cliente.*, count(distinct(libro.id)) 
from cliente, fichaprestamo, libro
where cliente.ci = fichaprestamo.cicliente and fichaprestamo.id_libro = libro.id 
group by cliente.ci;

# 10. Mostrar los libros que pertenecen a mas de una area
select distinct(libro.id), libro.nombre
from libro, libroArea, area
where libro.id = libroArea.idlibro and libroArea.idarea = area.id
	  and libro.id in (select idlibro
						from libroArea
						group by idlibro
						having count(idarea)>1);

# 11. Mostrar los clientes que se llevaron algun libro del Area de Programacion
select distinct(cliente.ci), cliente.nombre
from cliente, fichaprestamo, libro, libroArea, area
where cliente.ci = fichaprestamo.cicliente and fichaprestamo.id_libro = libro.id 
      and libro.id = libroArea.idlibro and libroArea.idarea = area.id
      and area.nombre = 'Programacion';

# 12. Mostrar al cliente que mas veces a sacado libros de la biblioteca


      

      