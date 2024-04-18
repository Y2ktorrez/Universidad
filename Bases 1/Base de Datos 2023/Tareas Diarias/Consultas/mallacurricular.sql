create database mallacurricular;
use mallacurricular;

create table materia(
	sigla varchar(6) not null primary key,
    nombre varchar(60) not null,
    semestre tinyint not null
);

create table prerequisito(
	siglamat varchar(6) not null,
    siglapre varchar(6) not null,
    primary key (siglamat,siglapre),
    foreign key(siglamat) references materia(sigla)
		on delete cascade on update cascade,
    foreign key (siglapre) references materia(sigla)
		on delete cascade on update cascade
);

-- Primer Semestre
INSERT INTO materia VALUES ('MAT101','CALCULO I',1);
INSERT INTO materia VALUES ('INF119','ESCTRUCTURAS DISCRETAS',1);
INSERT INTO materia VALUES ('INF110','INTRODUCCION A LA INFORMATICA',1);
INSERT INTO materia VALUES ('FIS100','FISICA I',1);
INSERT INTO materia VALUES ('LIN100','INGLES TECNICO I',1);

-- Segundo Semestre
INSERT INTO materia VALUES ('MAT102','CALCULO II',2);
INSERT INTO materia VALUES ('MAT103','ALGEBRA LINEAL',2);
INSERT INTO materia VALUES ('INF120','PROGRAMACION I',2);
INSERT INTO materia VALUES ('FIS102','FISICA II',2);
INSERT INTO materia VALUES ('LIN101','INGLES TECNICO II',2);

-- Prerequisito Segundo Semestre
INSERT INTO prerequisito VALUES ('MAT102','MAT101');
INSERT INTO prerequisito VALUES ('MAT103','INF119');
INSERT INTO prerequisito VALUES ('INF120','INF110');
INSERT INTO prerequisito VALUES ('FIS102','FIS100');
INSERT INTO prerequisito VALUES ('LIN101','LIN100');

-- Tercer Semestre
INSERT INTO materia VALUES ('MAT207','ECUACIONES DIFERENCIALES',3);
INSERT INTO materia VALUES ('INF210','PROGRAMACION II',3);
INSERT INTO materia VALUES('INF211', 'ARQUITECTURA DE COMPUTADORAS', 3);
INSERT INTO materia VALUES('ADM100', 'ADMINISTRACION', 3);
INSERT INTO materia VALUES('FIS200', 'FISICA III', 3); 

INSERT INTO prerequisito VALUES ('MAT207','MAT102');
INSERT INTO prerequisito VALUES ('INF210','MAT103');
INSERT INTO prerequisito VALUES ('INF210','INF120');
INSERT INTO prerequisito VALUES('INF211', 'INF120');
INSERT INTO prerequisito VALUES('INF211', 'FIS102');
INSERT INTO prerequisito VALUES ('FIS200', 'FIS102');

-- Cuarto Semestre
INSERT INTO materia VALUES('MAT202', 'PROBABILIDAD Y ESTADISTICA I', 4);
INSERT INTO materia VALUES('MAT205', 'METODOS NUMERICOS', 4);
INSERT INTO materia VALUES('INF220', 'ESTRUCTURA DE DATOS I', 4);
INSERT INTO materia VALUES('INF221', 'PROGRAMACION ENSAMBLADOR', 4);
INSERT INTO materia VALUES('ADM200', 'CONTABILIDAD', 4);

/* PREREQUISITO 4TO SEMESTRE */
INSERT INTO prerequisito VALUES('MAT202', 'MAT102');
INSERT INTO prerequisito VALUES('MAT205', 'MAT207');
INSERT INTO prerequisito VALUES('INF220', 'INF210');
INSERT INTO prerequisito VALUES('INF221', 'INF211');
INSERT INTO prerequisito VALUES('ADM200','ADM100');

-- Mostrar las materias que son prerequisito de programacion II
select  materiapre.sigla, materiapre.nombre
from materia materiallevar, prerequisito, materia materiapre
where materiallevar.sigla = prerequisito.siglamat and 
	  siglapre = materiapre.sigla and materiallevar.nombre = 'PROGRAMACION II';

select sigla, nombre
from materia
where sigla in (select siglapre
				from prerequisito
				where siglamat in (select sigla 
									from materia
									where nombre = 'PROGRAMACION II') 
);

-- Mostrar las Materias de las cuales es prerequisito PROGRAMACION II

select materias.sigla, materias.nombre
from materia materiapre, prerequisito, materia materias 
where materiapre.sigla = siglapre and siglamat = materias.sigla and
		materiapre.nombre = 'PROGRAMACION II';

select sigla, nombre
from materia
where sigla in (select siglamat
				from prerequisito
				where siglapre in (select sigla 
									from materia
									where nombre = 'PROGRAMACION II') 
);
