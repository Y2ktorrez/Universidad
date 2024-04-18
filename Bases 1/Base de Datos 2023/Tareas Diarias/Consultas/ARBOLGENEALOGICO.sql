create database ARBOLGENEALOGICO; 
use ARBOLGENEALOGICO;


create table persona(
	id int not null primary key,
    nombre varchar(60) not null,
    sexo char not null,
    idpadre int ,
    idmadre int 
);

alter table persona 
add foreign key(idmadre) references persona(id)
on update no action
on delete no action;

insert into persona values (1, 'Joaquin Chumacero', 'M', null, null);
insert into persona values (2, 'Fabiana Yapanqui', 'F', null, null);
insert into persona values (3, 'Carlos Chumacero Yapanqui', 'M', 1, 2);
insert into persona values (4, 'Priscila Aguilera', 'F', null, null);
insert into persona values (5, 'Joaquin Chumacero Aguilera', 'M', 3, 4);
insert into persona values (6, 'Fabiola Mendez', 'F', null, null);
insert into persona values (7, 'Joaquin Jr Chumacero Mendez', 'M', 5, 6);
insert into persona values (8, 'Fabiola Chumacero Mendez', 'F', 5, 6);
insert into persona values (9, 'Ana Castro', 'F', null, null);
insert into persona values (10, 'Carlos Chumacero Castro', 'M', 5, 9);

-- Mostrar los Hijos de 'Joaquin Chumacero Aguilera' 
select hijo.id, hijo.nombre
from persona padre, persona hijo
where padre.id = hijo.idpadre and padre.nombre = 'Joaquin Chumacero Aguilera';

select id, nombre
from persona
where idpadre in (select id
					from persona
                    where nombre = 'Joaquin Chumacero Aguilera'
				 );

-- Mostrar los padres de 'Joaquin Chumacero Aguilera'
select padre.id, padre.nombre
from persona hijo, persona padre
where hijo.idpadre = padre.id and hijo.nombre='Joaquin Chumacero Aguilera';

select id, nombre 
from persona 
where id in (select idpadre 
				  from persona 
                  where nombre = 'Joaquin Chumacero Aguilera'
                  );

-- Mostrar el abuelo de 'Joaquin Chumacero Aguilera'     ----PONER HIJO por NIETO
select abuelo.id, abuelo.nombre
from persona nieto, persona padre, persona abuelo
where nieto.idpadre = padre.id and padre.idpadre = abuelo.id and nieto.nombre='Joaquin Chumacero Aguilera';

select id, nombre
from persona 
where id in (select idpadre
             from persona
			 where id in (select idpadre
                          from persona 
                          where nombre='Joaquin Chumacero Aguilera'
                          )
		    );
            
-- Mostrar las persona con las cuales tuvo hijos 'Joaquin Chumacero Aguilera'
select distinct madre.id, madre.nombre
from persona padre, persona hijo, persona madre
where padre.id = hijo.idpadre and hijo.idmadre = madre.id
      and padre.nombre = 'Joaquin Chumacero Aguilera';
      

	



