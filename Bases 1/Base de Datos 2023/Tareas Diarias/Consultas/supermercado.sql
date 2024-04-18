create database supermercado;
use supermercado;


create table cliente(
	ci int unsigned not null primary key,
	nombre varchar(60) not null,
	sexo varchar(1), -- char not null 
	telefono int
);

create table nota_venta(
	nro int unsigned not null primary key,
	fecha date,
	monto float, 
	ci_cliente int unsigned not null,
	foreign key(ci_cliente) references cliente(ci)
		on delete cascade on update cascade
);

create table vende (
	nroventa int unsigned not null,
	codigo_prod int unsigned not null ,
	cantidad int unsigned not null,
	precio float not null,
	primary key(nroventa, codigo_prod),
	foreign key (nroventa) references nota_venta(nro)
		on delete cascade on update cascade,
	foreign key(codigo_prod) references producto(codigo)
		on delete cascade on update cascade
);

create table categoria(
	id smallint unsigned not null primary key,
	nombre varchar(60) not null
);

create table producto(
	codigo int unsigned not null primary key,
	nombre varchar(60) not null,
	precio float not null,  -- numeros reales 
	id_categoria smallint unsigned not null,
	foreign key(id_categoria) references categoria(id)
		on delete cascade  on update cascade -- se actualiza dependiendo del cambio que realice
);

/****Insertar Datos****/

-- tabla cliente 
insert into cliente values
(111, 'Joaquin Chumacero', 'M', 7102030),
(222, 'Saturdino Mamani', 'M', 3562221),
(333, 'Fabiola Mendez', 'F', 7002020);

-- tabla nota_venta
insert into nota_venta values -- YYYY-MM-DD
(100, '2023-1-10', 45, 111),
(101, '2023-1-10', 64, 222),
(102, '2023-1-11', 10, 333),
(103, '2023-1-11', 50, 111); -- cambiar a 5

-- tabla vende 
insert into vende values (100, 1001, 2, 10);
insert into vende values (100, 1006, 5, 5);
insert into vende values (101, 1003, 2, 7);
insert into vende values (101, 1007, 3, 10);
insert into vende values (101, 1001, 2, 10);
insert into vende values (102, 1006, 2, 5);
insert into vende values (103, 1001, 3, 10);
insert into vende values(103, 1005, 2, 10);

-- tabla categoria
insert into categoria values 
(1,'Gaseosa'),
(2,'Carne'),
(3,'Energizante'),
(4,'Abarrotes');

-- tabla producto
insert into producto values  
(1001,'Coca-Cola 2 lts', 10, 1),
(1002,'Coca-Cola 3 lts', 15, 1),
(1003,'Arroz 1 kg', 7, 4),
(1004,'Carne de Res', 40, 2),
(1005,'Red Bull 1 lts', 12, 3),
(1006,'Azucar 1 kg', 5, 4),
(1007,'Fanta de 2 lts', 10, 1);




-- Actualizamos datos 
update categoria set id = 5
where id=1;

-- Eliminar datos
delete from categoria 
where id = 5;

delete from categoria 



/****Consultas****/

-- Mostrar los productos de la categoria 'Gaseosa'
select codigo, nombre, precio
from producto 
where id_categoria  in (select id   -- la forma mas correcta es 'in' en vez de = 
						from categoria 
						where nombre = 'Gaseosa');
	
-- metodo del ing
select codigo, producto.nombre, precio
from producto, categoria 
where id_categoria = id and categoria.nombre ='Gaseosa'
						
-- Mostrar los productos con un precio mayor a 10 de la categoria 'Gaseosa'

select codigo, producto.nombre, precio
from producto, categoria 
where id_categoria = id and categoria.nombre ='Gaseosa' and precio > 10;

select codigo, nombre, precio
from producto 
where precio > 10 and id_categoria  in (select id   
						from categoria 
						where nombre = 'Gaseosa');

-- Mostrar todas las notas de ventas que pertenecen a 'Joaquin chumacero'
select nro, fecha, monto
from nota_venta, cliente  				            -- primer paso, identificar las tablas 
where ci_cliente=ci and nombre='Joaquin chumacero';	-- segundo paso, buscar las relaciones de las tablas 
					
select nro, fecha, monto
from nota_venta
where ci_cliente in (select ci
							from cliente 
							where nombre='Joaquin chumacero');
			
--  Mostrar la cantidad de total de notas de ventas de 'Joaquin Chumacero'				
select count(*) 
from nota_venta, cliente  				             
where ci_cliente=ci and nombre='Joaquin chumacero';	 
					
-- Mostrar el monto total pagado por 'Joaquin Chumacero'
select sum(monto)
from nota_venta, cliente  				             
where ci_cliente=ci and nombre='Joaquin chumacero';	
				
-- Mostrar el monto total vendido
select sum(monto)
from nota_venta;

-- Mostrar el monto maximo vendido
select max(monto)
from nota_venta; 

-- Mostrar el monto minimo vendido
select min(monto)
from nota_venta; 

-- Mostrar el monto promedio vendido
select avg(monto) -- avg=promedio
from nota_venta; 
					
-- Mostrar los productos comprados por 'Joaquin Chumacero' en todas sus notas de venta
select  nro, fecha, codigo, producto.nombre, cantidad, vende.precio 
from cliente, nota_venta, vende, producto  
where ci_cliente= ci and nro=nroventa and codigo_prod=codigo
      and cliente.nombre = 'Joaquin Chumacero';
						
-- Mostrar la cantidad total comprado de 'Coca-Cola 2 lts', por 'Joaquin Chumacero'						
select  sum(cantidad) as cantidad
from cliente, nota_venta, vende, producto  
where ci_cliente= ci and nro=nroventa and codigo_prod=codigo
      and cliente.nombre = 'Joaquin Chumacero'
      and producto.nombre  = 'Coca-Cola 2 lts';

-- Mostrar la Monto total pagado por 'Coca-Cola 2 lts', por 'Joaquin Chumacero'						
select  sum(cantidad * vende.precio) as Monto -- vende.precio, especifica de donde quiere sacar dicha informacion
from cliente, nota_venta, vende, producto  
where ci_cliente= ci and nro=nroventa and codigo_prod=codigo
      and cliente.nombre = 'Joaquin Chumacero'
      and producto.nombre  = 'Coca-Cola 2 lts';

-- Mostrar todas las notas de venta donde se  haya vendido algun producto de la categoria 'Gaseosa'
select distinct  nro, fecha, monto 
from producto, categoria, vende, nota_venta
where categoria.id = producto.id_categoria  and producto.codigo = vende.codigo_prod 
	  and nota_venta.nro = vende.nroventa  
      and categoria.nombre = 'Gaseosa';

-- Consulta Anidada
select nro, fecha, monto
from nota_venta
where nota_venta.nro in (select nroventa 
						 from vende 
						 where vende.codigo_prod in ( select codigo
													  from producto
													  where producto.id_categoria in (select id
															from categoria
															where categoria.nombre = 'Gaseosa')
													)
                           );
					
-- Mostrar los porductos vendidos
select distinct codigo, nombre
from producto,  vende
where producto.codigo = vende.codigo_prod
order by nombre asc;

-- Anidado
select  *
from producto
where producto.codigo in (select distinct codigo_prod
                          from vende)
order by nombre asc;

-- Mostrar los productos que no se han vendido
select  *
from producto
where producto.codigo not in (select distinct codigo_prod
								from vende);

-- Mostrar la cantidad de productos que existen en la categoria 'Gaseosa'
select count(*) 
from producto, categoria
where categoria.id = producto.id_categoria
      and categoria.nombre = 'Gaseosa';
			
-- Mostrar la cantidad de productos existentes por categoria
select id_categoria, categoria.nombre , count(*) 
from producto, categoria
where id_categoria = id -- entenderle  a que hace la referencia con el id 
group by id_categoria;

-- Mostrar la cantidad de notas de ventas realizadas por cada cliente
select ci_cliente, cliente.nombre, count(*)
from cliente, nota_venta
where ci_cliente = ci
group by ci_cliente;
		
-- Mostrar la cantidad de productos que existen en la categoria 'Abarrote'
select count(*) 
from producto, categoria
where categoria.id = producto.id_categoria
      and categoria.nombre = 'Abarrotes';
        
        
