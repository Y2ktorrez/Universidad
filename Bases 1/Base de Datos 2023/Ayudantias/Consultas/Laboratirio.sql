create database laboratorio;
use laboratorio;

-- drop databse nombreBase
-- drop table nombreTabla
-- show tables
-- show columns from nombreTabla 
-- unisigned (para que no tome encuenta los signos)


-- tabla Software
create table software(
	id smallint unsigned not null,
	nombre varchar(50) not null,
	primary key(id)
)

-- tabla centro computo
create table centro_computo(
	cod tinyint unsigned not null,
	nombre varchar(50) not null,
	direccion varchar(50) not null,
	primary key(cod)
)

-- tabla materia
create table materia(
	sigla varchar(10) not null,
	nombre varchar(50) not null,
	primary key(sigla)
	
)

-- tabla agenda
create table agenda(
    cod_centro tinyint unsigned not null,
    sigla_materia varchar(10) not null,
    primary key(cod_centro, sigla_materia),
    foreign key (cod_centro) references centro_computo(cod)
        on delete cascade on update cascade,
    foreign key (sigla_materia) references materia(sigla)
        on delete cascade on update cascade
        
);

-- tabla horario

/*create table horario(  -- Se puede alargar las lineas de codigo o como tambine resumirlas
	cod_centro tinyint unsigned not null,
	sigla_materia varchar(10) not null,
	id smallint unsigned not null,
	dia varchar(10) not null,
	horainicio time not null,  
	horafin time not null,
	primary key(cod_centro,sigla_materia, id)
	foreign key (cod_centro) references agenda(cod_centro)
	on delete cascade on update cascade,
	foreign key (sigla_materia) references agenda(sigla_materia)
	on delete cascade on update cascade
);*/

create table horario(
    cod_centro tinyint unsigned not null,
    sigla_materia varchar(10) not null,
    id smallint unsigned not null,
    dia varchar(10) not null,
    horainicio time not null,
    horafin time not null,
    primary key(cod_centro, sigla_materia, id),
    foreign key (cod_centro, sigla_materia) references agenda(cod_centro, sigla_materia)
        on delete cascade on update cascade
);

-- tabla computadora
create table computadora(
	cod smallint unsigned not null,
	marca varchar(30) not null,
	ram tinyint unsigned not null,
	almacenamiento tinyint unsigned not null,
	cod_centro tinyint unsigned not null,
	primary key(cod),
	foreign key(cod_centro) references centro_computo(cod)
		on delete cascade on update cascade
);

-- tabla alumno
create table alumno(
	registro int unsigned not null,
	nombre varchar(50) not null,
	correo varchar(50) not null,
	primary key(registro)
);

-- tabla boleta
create table boleta(
    nro smallint unsigned not null,
    fecha date not null,
    horainicio time not null,
    horafin time not null,
    reg_alumno int unsigned not null,
    cod_computadora smallint unsigned not null,
    primary key(nro),
    foreign key(reg_alumno) references alumno(registro)
        on delete cascade on update cascade,
    foreign key(cod_computadora) references computadora(cod)
        on delete cascade on update cascade
);

-- tabla soft-compu
create table soft_compu(
    id_software smallint unsigned not null,
    cod_computadora smallint unsigned not null,
    version decimal(10,2) not null, -- Corregido "versio" a "version"
    primary key(id_software, cod_computadora)
);


/*POBLAR LAS TABLAS*/

/*select *
from nombrTabla*/
-- delete from nombreTabla(Esto elimina el insert de la tabla )

-- tabla materia
insert into materia values 
('INF110', 'Introdiccion a la Informatica'),
('INF120', 'Programacion 1'),
('INF210', 'Programacion 2'),
('INF220', 'Estructura de Datos 1'),
('INF310', 'Estructura de Datos 2'),
('INF323', 'Sistemas Operativos 1'),
('INF412', 'Sistemas Operativos 2'),
('INF312', 'Bases de Datos 1'),
('INF322', 'Bases de Datos 2'),
('INF342', 'Sistemas de Informacion 1');
  						  
-- tabla centro_computo   
insert into centro_computo values
(1, 'Centro de Computo A', 'Modulo 236-44 Modulos' ),
(2, 'Centro de Computo B', 'Aula 155 - Campues' ),
(3, 'Centro de Computo C', 'Aula 151 - Campues' ),
(4, 'Centro de Computo D', 'Modulo 236-45 Modulos' ),  						  
(5, 'Centro de Computo E', 'Modulo 236-42 Modulos' );

-- tabla agenda  						        
insert into agenda values
(1, 'INF110'),
(2, 'INF110'),
(2, 'INF120'),
(3, 'INF120'),
(3, 'INF210'),
(1, 'INF220'),
(2, 'INF220'),
(3, 'INF310'),
(5, 'INF310'),
(2, 'INF312'),
(3, 'INF312'),
(4, 'INF322'),
(1, 'INF323'),
(4, 'INF323'),
(5, 'INF323'),
(1, 'INF342'),
(5, 'INF342'),
(2, 'INF412'),
(5, 'INF412');

-- tabla horario
insert into horario(cod_centro, sigla_materia, id, dia, horainicio, horafin) values
(1, 'INF110', 1, 'Martes', '07:00:00', '09:15:00'),
(2, 'INF110', 1, 'Jueves', '07:00:00', '09:15:00'),
(2, 'INF120', 1, 'Martes', '07:00:00', '09:15:00'),
(3, 'INF120', 1, 'Jueves', '07:00:00', '09:15:00'),
(3, 'INF210', 1, 'Lunes', '10:00:00', '11:30:00'),
(3, 'INF210', 2, 'Miercoles', '10:00:00', '11:30:00'),
(3, 'INF210', 3, 'Viernes', '10:00:00', '11:30:00'),
(1, 'INF220', 1, 'Lunes', '07:00:00', '08:30:00'),
(2, 'INF220', 1, 'Miercoles', '07:00:00', '08:30:00'),
(4, 'INF220', 1, 'Viernes', '07:00:00', '08:30:00'),
(3, 'INF310', 1, 'Martes', '09:15:00', '11:30:00'),
(5, 'INF310', 1, 'Jueves', '09:15:00', '11:30:00'),
(4, 'INF322', 1, 'Martes', '18:15:00', '20:30:00'),
(4, 'INF322', 2, 'Jueves', '18:15:00', '20:30:00'),
(1, 'INF323', 1, 'Lunes', '08:30:00', '10:00:00'),
(4, 'INF323', 1, 'Miercoles', '08:30:00', '10:00:00'),
(5, 'INF323', 1, 'Viernes', '08:30:00', '10:00:00');	

-- tabla computadora
insert into computadora (cod, marca, ram, almacenamiento, cod_centro) values
(1, 'hp', 8, 1, 1),
(2, 'hp', 8, 1, 1),
(3, 'hp', 4, 1, 1),
(4, 'hp', 8, 1, 1),
(5, 'hp', 8, 1, 1),
(6, 'dell', 4, 1, 2),
(7, 'dell', 4, 1, 2),
(8, 'dell', 4, 1, 2),
(9, 'hp', 8, 1, 3),
(10, 'hp', 8, 1, 3),
(11, 'hp', 8, 1, 3),
(12, 'hp', 8, 1, 3),
(13, 'hp', 8, 1, 3),
(14, 'hp', 8, 1, 3),
(15, 'hp', 8, 1, 3),
(16, 'lenovo', 8, 1, 4),
(17, 'lenovo', 8, 1, 4),
(18, 'lenovo', 8, 1, 4),
(19, 'lenovo', 8, 1, 4),
(20, 'hp', 8, 1, 5),
(21, 'hp', 8, 1, 5),
(22, 'hp', 8, 1, 5),
(23, 'hp', 8, 1, 5),
(24, 'hp', 8, 1, 5),
(25, 'hp', 8, 1, 5),
(26, 'hp', 8, 1, 5	);
					
-- tabla software
insert  into software values
(1, 'SQL Server'),
(2, 'Visual Studio'),
(3, 'MySQL Whorkbench'),
(4, 'NeatBeans Apache'),
(5, 'Embarcadero'),
(6, 'VirtualBox');

-- tabla soft_compu
insert into soft_compu values
-- compu 1
(1,1,2.8), (2,1,1.0), (3,1,1.0), (4,1,1.0), (5,1,1.0), (6,1,1.0),
-- compu 2
(1,2,2.8), (2,2,1.0), (3,2,1.0), (4,2,1.0), (5,2,1.0), (6,2,1.0),
-- compu 3
(1,3,2.8), (2,3,1.0), (3,3,1.0), (4,3,1.0), (5,3,1.0), (6,3,1.0),
-- compu 4
(1,4,2.8), (2,4,1.0), (3,4,1.0), (4,4,1.0), (5,4,1.0), (6,4,1.0),
-- compu 5
(1,5,2.8), (2,5,1.0), (3,5,1.0), (4,5,1.0), (5,5,1.0), (6,5,1.0);


insert into soft_compu values
-- compu 6
(1, 6, 2.8), (2, 6, 1.0), (5, 6, 1.0), (6, 6, 1.0),
-- compu 7
(1, 7, 2.8), (2, 7, 1.0), (5, 7, 1.0), (6, 7, 1.0),
-- compu 8
(1, 8, 2.8), (2, 8, 1.0), (5, 8, 1.0), (6, 8, 1.0); 

insert into soft_compu values
-- compu 9
(1,9,2.8), (2,9,1.0),(3,9,1.0),(4,9,1.0), (5,9,1.0),
-- compu 10
(1,10,2.8), (2,10,1.0),(3,10,1.0),(4,10,1.0), (5,10,1.0),
-- compu 11
(1,11,2.8), (2,11,1.0),(3,11,1.0),(4,11,1.0), (5,11,1.0),
-- compu 12
(1,12,2.8), (2,12,1.0),(3,12,1.0),(4,12,1.0), (5,12,1.0),
-- compu 13
(1,13,2.8), (2,13,1.0),(3,13,1.0),(4,13,1.0), (5,13,1.0),
-- compu 14
(1,14,2.8), (2,14,1.0),(3,14,1.0),(4,14,1.0), (5,14,1.0),
-- compu 15
(1,15,2.8), (2,15,1.0),(3,15,1.0), (4,15,1.0), (5,15,1.0);

insert into soft_compu values
-- compu 16
(1,16,2.8), (2,16,1.0),(3,16,1.0),(4,16,1.0), (5,16,1.0),
-- compu 17
(1,17,2.8), (2,17,1.0),(3,17,1.0),(4,17,1.0), (5,17,1.0),
-- compu 18
(1,18,2.8), (2,18,1.0),(3,18,1.0),(4,18,1.0), (5,18,1.0),
-- compu 19
(1,19,2.8), (2,19,1.0),(3,19,1.0),(4,19,1.0), (5,19,1.0);

insert into soft_compu values
-- compu 20
(1,20,2.8), (2,20,1.0),(3,20,1.0),(4,20,1.0), (5,20,1.0),
-- compu 21
(1,21,2.8), (2,21,1.0),(3,21,1.0),(4,21,1.0), (5,21,1.0),
-- compu 22
(1,22,2.8), (2,22,1.0),(3,22,1.0),(4,22,1.0), (5,22,1.0),
-- compu 23
(1,23,2.8), (2,23,1.0),(3,23,1.0),(4,23,1.0), (5,23,1.0),
-- compu 24
(1,24,2.8), (2,24,1.0),(3,24,1.0),(4,24,1.0), (5,24,1.0),
-- compu 25
(1,25,2.8), (2,25,1.0),(3,25,1.0),(4,25,1.0), (5,25,1.0),
-- compu 26
(1,26,2.8), (2,26,1.0),(3,26,1.0),(4,26,1.0), (5,26,1.0);


-- tabla alumno
insert into alumno values
(220153914,'Andres Torrez', 'andrestorrezvaca@gmail.com'),
(220053914,'Juan Perez', 'juanperez@gmail.com'),
(221153914,'Aracely Torrez', 'aracelytorrez@gmail.com'),
(221253914,'Pepe Aguilar', 'pepeaguilar@gmail.com'),
(220000914,'Juanito Alcachofla', 'juanitoalcachofla@gmail.com'),
(220153921,'Carlos Chumasero', 'carloschumasero@gmail.com'),
(220153965,'Toto quispe', 'totoquispe@gmail.com'),
(221153414,'Gladys Vaca', 'gladysvaca@gmail.com');

-- tabla boleta 
insert into boleta values	
(1, '2023-05-24', '09:00:00', '10:30:00',220153914, 2),
(2, '2023-05-25', '14:00:00', '16:00:00',220053914, 4),
(3, '2023-05-25', '15:00:00', '17:00:00',221153914, 6),
(4, '2023-05-26', '14:00:00', '16:00:00',221253914, 1),
(5, '2023-05-27', '07:00:00', '10:00:00',220000914, 2),
(6, '2023-05-27', '10:00:00', '13:00:00',220153921, 8),
(7, '2023-05-27', '10:00:00', '14:30:00',220153965, 20),
(8, '2023-05-27', '15:00:00', '16:30:00',221153414, 23),
(9, '2023-05-28', '14:00:00', '16:00:00',220153914, 11),
(10, '2023-05-28', '07:00:00', '10:30:00',220000914, 5);						
		

/*Consultas*/

-- 1. Mostrar las computadoras del "Centro de computo A"
select computadora. *
from computadora, centro_computo 
where centro_computo.cod  = computadora.cod_centro and 
      centro_computo.nombre = 'Centro de Computo A';
-- Forma dos... 
select computadora. *
from computadora, centro_computo 
where computadora.cod_centro  = centro_computo.cod and 
      centro_computo.nombre = 'Centro de Computo A';     
     
show columns from computadora    
     
-- 2. Mostrar las materias que pasan clases en el 'Centro de Computo E'
select materia. *
from materia, agenda, centro_computo 
where materia.sigla = agenda.sigla_materia and agenda.cod_centro = centro_computo.cod and 
      centro_computo.nombre = 'Centro de Computo E';  
     
-- 3. Mostrar los Softwares que tienen las computadoras de los centros donde se pasa la materia 
--    'Estructura de Datos 2'
select software .*
from materia, agenda, centro_computo, computadora, soft_compu, software
where materia.sigla = agenda.sigla_materia and agenda.cod_centro = centro_computo.cod and
      centro_computo.cod = computadora.cod_centro and computadora.cod = soft_compu.cod_computadora 
      and soft_compu.id_software = software.id  and materia.nombre = 'Estructura de Datos 2'; 
     -- ESTA MAL (proba)
     
select distinct (software.id), software.nombre -- lo que hace aqui es mostrar solo los Softwares y no la cantidad.
from materia, agenda, centro_computo, computadora, soft_compu, software
where materia.sigla = agenda.sigla_materia and agenda.cod_centro = centro_computo.cod and
      centro_computo.cod = computadora.cod_centro and computadora.cod = soft_compu.cod_computadora 
      and soft_compu.id_software = software.id  and materia.nombre = 'Estructura de Datos 2';

-- 4. Mostar aquellos alumnos que tienen correo institucional @gmail.com
select alumno .*
from alumno   
where correo like '%@gmail.com';

-- 5. Mostrar aquellos centros de computo que se encuentra en los modulos
select*
from centro_computo 
where direccion like '%Modulo%';

-- 6. Mostrar la cantidad de computodaras de cada centro de computo
select centro_computo.*, count(computadora.cod) 
from centro_computo, computadora
where centro_computo.cod = computadora.cod_centro and ;  










