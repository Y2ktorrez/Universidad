create database universidad;
use universidad;

-- drop databse nombreBase
-- drop table nombreTabla
-- show table
-- show columns from nombreTabla 

create table estudiante(
	registro int unsigned not null, 
	nombre varchar(50) not null,
	sexo varchar(1) not null,
	telefono int not null,
	direccion varchar(50) not null,
	estadoCivil varchar(30) not null,
	primary key(registro)
)

-- como lo hace el ing
create table alumno(
	Registro int not null primary key, -- se puede poner diractamente
	Nombre varchar(60) not null,
	Sexo char not null,
	EstadoCivil char not null,
	Telefono int,
	Direccion varchar(50)
);


/*Insertar Datos*/

-- estudiante
insert into  alumno values
(111, 'Juanito Alcachofla', 'M', 'S', 75212841, 'Plan 3000');

insert into alumno (Registro, Nombre, Sexo, EstadoCivil, Telefono, Direccion) values
(222, 'Saturdino Mamani', 'M', 'C', 75212842, null);

insert into alumno(Registro, Nombre, Sexo, EstadoCivil, Telefono, Direccion) values
(333, 'Fabiola Mendez', 'F', 'S', 75212843, 'Loz Pozos');

insert into alumno (Registro, Nombre, Sexo, EstadoCivil, Telefono, Direccion) values
(444, 'Carlos Camacho', 'M', 'S', null, 'Mutualista');

insert into alumno (Registro, Nombre, Sexo, EstadoCivil, Telefono, Direccion) values
(555, 'Patricia Aguilera', 'F', 'C', 75312844, 'Canal Isuto');


/*CONSULTA*/ 

-- Mostrar todos los alumnos varones
select *
from alumno  
where Sexo = 'M';

-- Mostrar el registro y nombre de todos los alumnos varones
select Registro, Nombre
from alumno  
where Sexo = 'M';

-- Mostrar todos los alumnos varones casados 
select *
from alumno 
where Sexo = 'M' and EstadoCivil = 'C';

-- Mostrar todos aquellos alumnos que no tienen telefono
select *
from alumno 
where telefono is null;

-- Mostrar todos los alumnos que tienen telefono
select *
from alumno 
where telefono is not null;
  
-- Mostrar todos aquellos alumnos que su nombre comienza con la letra F
select *
from alumno 
where nombre like 'F%';

-- Mostrar todos aquellos alumnos que tengan en su nombre completo la MA*
select *
from alumno 
where nombre like '%ma%';  -- no importa lo que hay antes y despues %(Ma) ma %(ni) %(Ca)  ma &(cho)

-- Mostrar la cantidad de alumnos 
select count(*) -- (*).- contador de filas, tambien se puede usar con atributos 
from alumno;

select count(telefono)  -- Mostrar la cantidad de telefonos 
from alumno; 

select count(telefono)  as cant_tele -- sirve para darle  nombre  
from alumno; 

-- Mostrar todos los alumnos ordenados de forma ascendente/descendente por nombre
select *
from alumno 
order by nombre asc; -- ordenar de manera que nosotros querramos

select *
from alumno 
order by nombre desc; -- ordena de manera descendente

-- Mostrar la cantidad de alumnos varones que existe
select count(sexo) as cant_varones
from alumno
where sexo like 'M';

select count(*) 
from alumno 
where sexo='M';

-- Mostrar todos los casados ordenados de manera descendente por nombre
select *
from alumno 
where estadoCivil like 'C'
order by estadoCivil desc;

select *
from alumno 
where estadoCivil='C'
order  by estadoCivil desc;

-- Cambiar el Apellido de Joaquin Chumasero por chumager
update alumno -- actualiza
set nombre='Joaquin Chumager' -- coloque
where registro=111; -- donde 

-- Eliminar al alumno que tiene el  registro 222
delete from alumno -- elimina 
where nombre=222; -- donde

-- Aumentar el atributo Correo electronico a la tabla alumno
alter table alumno -- alterar
add correo varchar(40); -- adicionar

-- Borrar la tabla alumno 
drop table alumno;

-- Borrar la Base de Datos Universidad
drop database universidad;





