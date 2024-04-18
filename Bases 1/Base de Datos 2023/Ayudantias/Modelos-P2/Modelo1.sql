create database tienda;
use tienda;

create table cliente(
	ci int unsigned not null,
	nombre varchar(60) not null,
	sexo char not null,	
	direccion varchar(100) not null,
	telefono int unsigned not null,
	primary key(ci)
);

create table notaVenta(
	nro int unsigned not null,
	fecha date not null,
	monto int not null,
	ci_cliente int unsigned not null,
	primary key(nro),
	foreign key(ci_cliente) references cliente(ci)
		on delete cascade on update cascade
);

create table vende (
	nro_notaVenta int unsigned not null,
	cod_producto int unsigned not null,
	cantidad int not null,
	precio int not null,
	primary key (nro_notaVenta, cod_producto)
);

create table producto(
	cod int unsigned not null,
	descripcion varchar(80) not null,
	precio int unsigned not null,
	id_unidadMedida int unsigned not null,
	primary key(cod),
	foreign key(id_unidadMedida) references unidadMedida(id)
		on delete cascade on update cascade
	
);

create table unidadMedida(
	id int unsigned not null,
	descripcion varchar(80) not null,
	abrebiatura char(1) not null,
	primary key(id)
);


/*Insertar datos*/

-- cliente
insert into cliente(ci, nombre, sexo, direccion, telefono) values
(111, 'Juanito Quispe','M','Plan 3000', 75212841),
(222, 'Juanita Zuruco','F','Quior', 75212842),
(333, 'Andres Torrez','M','Juana  Azurduy de Padilla', 75212843);
 






