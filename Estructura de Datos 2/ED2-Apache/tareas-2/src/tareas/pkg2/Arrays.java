/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tareas.pkg2;
import java.util.Random;

/**
 *
 * @author DCDS
 */
public class Arrays {
       int[] vec;
    int cantElem;
    int max;

    public Arrays(int cantidadCasillas) {
        this.vec = new int[cantidadCasillas];
        this.cantElem = -1;
        this.max = cantidadCasillas - 1;
    }

    private boolean vacia() {
        return this.cantElem == -1;
    }

    private boolean lleno() {
        return this.max == this.cantElem;
    } 
    
    @Override
    public String toString() {
        String cad = "";
            
        for (int i = 0; i <= this.cantElem; i++) {
            cad = cad + "[" + this.vec[i] + "]<->";
        }
        return cad;
    }
    
    public void insertar(int x) {
        if (!lleno()) {
            this.cantElem++;
            this.vec[cantElem] = x;
        }
    }
    
    /*--------------------------------------------------------------------------------------------------------*/
    
    /****TAREA-6 Numeros Extremadamente Grandes****/
    
    /****Arrays****/
    
    /*1. sumar(L1, L2, L3) : Procedimiento que suma L2 con L3 en L1. L1 = L2 + L3.*/
    public static void sumarT6(Arrays l1, Arrays l2, Arrays l3) {
        int carry = 0;
        int maxLength = Math.max(l2.cantElem, l3.cantElem);
        for (int i = 0; i <= maxLength; i++) {
            int sum = carry;
            if (i <= l2.cantElem) {
                sum += l2.vec[i];
            }
            if (i <= l3.cantElem) {
                sum += l3.vec[i];
            }
            l1.insertar(sum % 10);
            carry = sum / 10;
        }
        if (carry != 0) {
            l1.insertar(carry);
        }
    }

    /*2. igual(L1, L2) : Función Lógica que devuelve True, si el entero L1 es igual al entero L2.  L1 == L2.*/
    public boolean igualT6(Arrays L1, Arrays L2) {
        if (L1.cantElem != L2.cantElem) {
            return false;
        }
        for (int i = 0; i <= L1.cantElem; i++) {
            if (L1.vec[i] != L2.vec[i]) {
                return false;
            }
        }
    return true;
    }
    
    /*3. menor(L1, L2) : Función Lógica que devuelve True, si el entero L1 es menor que el entero L2.  L1 < L2.*/
    public boolean menorT6(Arrays L1, Arrays L2) {
        if (L1.cantElem < L2.cantElem) {
            return true;
        }
        if (L1.cantElem > L2.cantElem) {
            return false;
        }
        for (int i = 0; i <= L1.cantElem; i++) {
            if (L1.vec[i] > L2.vec[i]) {
                return false;
            }
        }
        return true;
    }

    /*4. mayor(L1, L2) : Función Lógica que devuelve True, si el entero L1 es mayor que el entero L2.  L1 > L2.*/
    public boolean mayorT6(Arrays L1, Arrays L2) {
        if (L1.cantElem > L2.cantElem) {
            return true;
        }
        if (L1.cantElem < L2.cantElem) {
            return false;
        }
        for (int i = 0; i <= L1.cantElem; i++) {
            if (L1.vec[i] < L2.vec[i]) {
                return false;
            }
        }
        return true;
    }

    /*5. diferente(L1, L2) : Función Lógica que devuelve True, si los entero L1 y L2 son diferentes.*/
    public void diferencialT6(Arrays L1, Arrays L2, Arrays L3) {
        if (L1.igualT6(L2, L3)) {
            L1.insertar(0);
            return;
        }
        if (L1.menorT6(L2, L3)) {
            L2.diferencialT6(L1, L2, L3);
            return;
        }
        int borrow = 0;
        for (int i = 0; i <= L1.cantElem; i++) {
            int diff = borrow + L2.vec[i] - (i <= L3.cantElem ? L3.vec[i] : 0);
            if (diff < 0) {
                diff += 10;
                borrow = -1;
            } else {
                borrow = 0;
            }
            L1.insertar(diff);
        }
    }
    
    /*6. generarNumero(L1, n) : procedimiento que genera en L1, aleatoriamente n-dígitos de un entero extremadamente grado.*/
    public void generarNumeroT6(int n) {
        Random random = new Random();
        Arrays arreglo = new Arrays(n); // Crear un arreglo de tamaño n
        for (int i = 0; i < n; i++) {
            int digito = random.nextInt(10); // Generar un dígito aleatorio (0-9)
            if (!(arreglo.vacia() && digito == 0)) {
                arreglo.insertar(digito); // Agregar el dígito al arreglo (excepto si es el primer dígito y es 0)
            }
        }
    }
    
    /*7. eliminarCeros(L1) : Procedimiento que elimina los dígitos ceros del inicio de la Lista L1.*/
    public void eliminarCerosT6() {
        int cerosConsecutivos = 0;
        while (cerosConsecutivos <= this.cantElem && this.vec[cerosConsecutivos] == 0) {
            cerosConsecutivos++;
        }
        for (int i = cerosConsecutivos; i <= this.cantElem; i++) {
            this.vec[i - cerosConsecutivos] = this.vec[i];
        }
        this.cantElem -= cerosConsecutivos;
    }

    /*8. diferencia(L1, L2, L3) : Procedimiento que encuentra la diferencia en L1 del mayor entre L2 y L3. */
  
    public void diferencialT6(Arrays L2, Arrays L3) {
        Arrays L1 = new Arrays(Math.max(L2.vec.length, L3.vec.length));
        if (L1.igualT6(L2, L3)) {
            L1.insertar(0);
            System.out.println(L1.toString());
            return;
        }
        int[] p = L2.vec;
        int[] q = L3.vec;

        if (L1.menorT6(L2, L3)) {
            p = L3.vec;
            q = L2.vec;
        }

        int maxLength = Math.max(p.length, q.length);
        int carry = 0;
        for (int i = 0; i < maxLength; i++) {
            int pValue = (i < p.length) ? p[i] : 0;
            int qValue = (i < q.length) ? q[i] : 0;

            int diff = pValue - qValue - carry;
            if (diff < 0) {
                diff += 10;
                carry = 1;
            } else {
                carry = 0;
            }
            L1.insertar(diff);
        }
        System.out.println(L1.toString());
    }

    /*9. multiplicar(L1, L2, L3) : Procedimiento que encuentra la multiplicación de L2 con L3 en L1. L1 = L2 * L3.*/
    public void multiplicarT6(ListaDoble L2, ListaDoble L3) {
        Arrays resultado = new Arrays(L2.cantElem + L3.cantElem + 1);
        Nodo p = L2.prim;
        int i = 0;
        while (p != null) {
            Arrays parcial = new Arrays(L3.cantElem + 1);
            int carry = 0;
            Nodo q = L3.prim;
            for (int j = 0; j < i; j++) {
                parcial.insertar(0);
            }
            while (q != null) {
                int mult = p.elem * q.elem + carry;
                parcial.insertar(mult % 10);
                carry = mult / 10;
                q = q.prox;
            }
            if (carry != 0) {
                parcial.insertar(carry);
            }
            int j = 0;
            carry = 0;
            while (j <= parcial.cantElem || carry != 0) {
                int suma = resultado.vec[i + j] + parcial.vec[j] + carry;
                resultado.vec[i + j] = suma % 10;
                carry = suma / 10;
                j++;
            }
            p = p.prox;
            i++;
        }
        this.cantElem = resultado.cantElem;
        for (int k = 0; k <= resultado.cantElem; k++) {
            this.vec[k] = resultado.vec[k];
        }
    }

    /*10. Incluir al menos 5 operaciones adicionales cualesquiera.*/  
    
    /*10.1. reversa*/
    /*public void reversa() {
        int[] tempArr = new int[cantElem + 1];
        Nodo current = prim;
        int index = 0;
        while (current != null) {
            tempArr[index++] = current.elem;
            current = current.prox;
        }
        Arrays newArray = new Arrays(cantElem + 1);
        for (int i = cantElem; i >= 0; i--) {
            newArray.insertar(tempArr[i]);
        }
        this.vec = newArray.vec;
    }*/

    /*10.2. eliminarEnPosicion*/
    public void eliminarEnPosicion(int posicion) {
        if (posicion < 0 || posicion > cantElem) {
            return;
        }
        for (int i = posicion; i < cantElem; i++) {
            this.vec[i] = this.vec[i + 1];
        }
        cantElem--;
    }

    /*10.3. concatenar */
    public void concatenar(ListaDoble l1, ListaDoble l2) {
        int newSize = l1.obtenerTamaño() + l2.obtenerTamaño();
        Arrays newArray = new Arrays(newSize);
        Nodo current = l1.prim;
        while (current != null) {
            newArray.insertar(current.elem);
            current = current.prox;
        }
        current = l2.prim;
        while (current != null) {
            newArray.insertar(current.elem);
            current = current.prox;
        }
        this.vec = newArray.vec;
        this.cantElem = newSize - 1;
    }

    /*10.4. buscarElemento*/
    public int buscarElemento(int elemento) {
        for (int i = 0; i <= cantElem; i++) {
            if (vec[i] == elemento) {
                return i;
            }
        }
        return -1;
    }

    /*10.5.obtenerTamaño */
    public int obtenerTamaño() {
        return cantElem + 1;
    }
 

    
    
    
    
    
    
    
    
}
