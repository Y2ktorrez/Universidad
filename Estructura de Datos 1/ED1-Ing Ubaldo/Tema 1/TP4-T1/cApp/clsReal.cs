using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace cApp
{
    public class clsReal
    {

        public double suma(double a, double b)
        {
            double s;
            s = a + b;
            return s;
        }

        public double restar(double a, double b)
        {
            double r;
            r = a - b;
            return r;
        }

        public double multiplicacion(double a, double b)
        {
            double m;
            m = a * b;
            return m;
        }

        public double potencia(double a, double exp)
        {
            double p;
            p = Math.Pow(a, exp);
            return p;
        }
    }
}
