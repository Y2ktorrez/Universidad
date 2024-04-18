/*************************************************************
Institución:    Universidad Gabriel Rene Moreno

Materia:        Estructura de Datos I
Creador:        Ing. Ubaldo Perez.
Lenguaje:       C#
Herramienta:    Visual Studio 2022 - Windows Aplications
Nombre:         Andres Torrez Vaca
Registro:       220153914
*************************************************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cApp
{
    public class clsLisCola
    {
        class Nodo
        {
            public int info;
            public Nodo Sig;
        }

        private Nodo _tope, _rear;
        private int _cant;

        public clsLisCola()
        {
            _tope = null;
            _rear = null;
            _cant = 0;
        }

        public bool Vacia()
        {
            return _tope == null;
        }

        public clsLisCola Drop()
        {
            _tope = null;
            _rear = null;
            _cant = 0;
            return this;
        }

        public clsLisCola Add(int inf)
        {
            clsLisCola A = new clsLisCola();
            Nodo nuevo = new Nodo();
            nuevo.info = inf;
            nuevo.Sig = null;

            if (Vacia())
            {
                _rear = nuevo;
                _tope = nuevo;
            }
            else
            {
                _rear.Sig = nuevo;
                _rear = nuevo;
            }

            _cant++;
            A._rear = _rear;
            A._tope = _tope;
            A._cant = _cant;
            return A;
        }

        public clsLisCola Delete()
        {
            if (Vacia())
            {
                return this;
            }

            clsLisCola A = new clsLisCola();
            Nodo nuevo = _tope;

            if (_tope == _rear)
            {
                _tope = null;
                _rear = null;
            }
            else
            {
                _rear.Sig = _tope.Sig;
                _tope = _tope.Sig;
            }

            _cant--;
            A._rear = _rear;
            A._tope = _tope;
            A._cant = _cant;
            return A;
        }

        public int Long()
        {
            return _cant;
        }

        public void InsertarDespuesDe(int valorBuscado, int valorNuevo)
        {
            if (Vacia())
            {
                return;
            }

            Nodo actual = _tope;

            do
            {
                if (actual.info == valorBuscado)
                {
                    Nodo nuevo = new Nodo();
                    nuevo.info = valorNuevo;
                    nuevo.Sig = actual.Sig;

                    actual.Sig = nuevo;

                    if (actual == _rear) // Si el nodo actual es el último, el nuevo será el nuevo "rear".
                    {
                        _rear = nuevo;
                    }

                    _cant++;
                    return;
                }

                actual = actual.Sig;
            } while (actual != _tope);
        }

        public void InsertarAntesDe(int valorBuscado, int valorNuevo)
        {
            if (Vacia())
            {
                return;
            }

            Nodo anterior = null;
            Nodo actual = _tope;

            do
            {
                if (actual.info == valorBuscado)
                {
                    Nodo nuevo = new Nodo();
                    nuevo.info = valorNuevo;
                    nuevo.Sig = actual;

                    if (anterior == null) // Si el nodo actual es el tope, el nuevo será el nuevo "tope".
                    {
                        _tope = nuevo;
                    }
                    else
                    {
                        anterior.Sig = nuevo;
                    }

                    _cant++;
                    return;
                }

                anterior = actual;
                actual = actual.Sig;
            } while (actual != _tope);
        }

        public void InsertarAlFinal(int valorNuevo)
        {
            clsLisCola A = new clsLisCola();
            Nodo nuevo = new Nodo();
            nuevo.info = valorNuevo;
            nuevo.Sig = null;

            if (Vacia())
            {
                _rear = nuevo;
                _tope = nuevo;
            }
            else
            {
                _rear.Sig = nuevo;
                _rear = nuevo;
            }

            _cant++;
        }

        public void InsertarAlInicio(int valorNuevo)
        {
            Nodo nuevo = new Nodo();
            nuevo.info = valorNuevo;
            nuevo.Sig = _tope;

            if (Vacia())
            {
                _rear = nuevo;
            }

            _tope = nuevo;
            _rear.Sig = _tope;
            _cant++;
        }

        public void EliminarNodo(int valorEliminar)
        {
            if (Vacia())
            {
                return;
            }

            Nodo anterior = null;
            Nodo actual = _tope;

            do
            {
                if (actual.info == valorEliminar)
                {
                    if (anterior == null) // Si el nodo actual es el tope, se elimina el tope y se actualiza el tope al siguiente nodo.
                    {
                        _tope = actual.Sig;
                    }
                    else
                    {
                        anterior.Sig = actual.Sig;
                    }

                    if (actual == _rear) // Si el nodo actual es el último, se actualiza el rear al nodo anterior.
                    {
                        _rear = anterior;
                    }

                    _cant--;
                    return;
                }

                anterior = actual;
                actual = actual.Sig;
            } while (actual != _tope);
        }

        public void EliminarPrimerNodo()
        {
            if (Vacia())
            {
                return;
            }

            _tope = _tope.Sig;

            if (_rear == _tope)
            {
                _rear = null;
            }

            _cant--;
        }

        public void EliminarUltimoNodo()
        {
            if (Vacia())
            {
                return;
            }

            Nodo anterior = null;
            Nodo actual = _tope;

            while (actual.Sig != _tope)
            {
                anterior = actual;
                actual = actual.Sig;
            }

            if (anterior == null) 
            {
                _tope = null;
                _rear = null;
            }
            else
            {
                anterior.Sig = _tope;
                _rear = anterior;
            }

            _cant--;
        }
        public String Mostrar()
        {
            if (Vacia())
            {
                return "La lista está vacía.";
            }

            StringBuilder sb = new StringBuilder();
            Nodo actual = _tope;

            do
            {
                sb.Append(actual.info.ToString());
                sb.Append(" ");
                actual = actual.Sig;
            } while (actual != _tope);

            return sb.ToString();
        }

    }
}

