
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace cApp
{
    public class clsPoly
    {
        const int MAX = 50;
        float[] vCoef;
        int[] vExp;
        int nTerm;

        public clsPoly()
        {
            vCoef = new float[MAX];
            vExp = new int[MAX];
            for (int i = 0; i < MAX; i++)
                 {
                    vCoef[i] = 0;
                    vExp[i] = 0;
                 }
            nTerm = 0;
        }

        public clsPoly(clsPoly P)
        {
            vCoef = new float[MAX];
            vExp = new int[MAX];
            for (int i = 0; i <= P.nTerm; i++)
            {
                vCoef[i] = P.vCoef[i];
                vExp[i] = P.vExp[i];
            }
            this.nTerm = P.nTerm;

        }

        public clsPoly Zero()
        {
            return new clsPoly();
        }

        public bool IsZero()
        {
            return (nTerm == 0);
        }

        public clsPoly Attach(clsPoly P, float Coef, int Exp)
        {
            if ((Coef != 0) && (Exp >= 0))
            {
                P.nTerm++;
                P.vExp[Exp] = Exp;
                P.vCoef[Exp] = P.vCoef[Exp] + Coef;
            }
            return P;
        }

        public clsPoly Rem(clsPoly P, int Exp)
        {

            if (Exp >= 0)
            {
                P.vCoef[Exp] = 0;
                P.vExp[Exp] = 0;
                P.nTerm--;
            }
            return P;
        }

        public float Coef( int Exp)
        {
                return vCoef[Exp];
        }

        public int Grado()
        {
            int Exp=0;
            for (int k = 0; k < MAX; k++)
            {
                if (vExp[k]>0)
                    Exp=vExp[k];
            }
            return Exp;
        }

        public clsPoly Add(clsPoly P, clsPoly Q)
        {
            clsPoly C = new clsPoly();

            while ((P.IsZero()==true && Q.IsZero()==true)==false)
            {
                if (P.Grado() < Q.Grado())
                    {
                        C = Attach(C, Q.Coef(Q.Grado()), Q.Grado());
                        Q = Rem(Q, Q.Grado());
                    }
                if (P.Grado() > Q.Grado())
                    {
                        C = Attach(C, P.Coef(P.Grado()), P.Grado());
                        P = Rem(P, P.Grado());

                    }
                if (P.Grado() == Q.Grado())    
                    {
                        C = Attach(C, P.Coef( P.Grado()) + Q.Coef( Q.Grado()), P.Grado());
                        P = Rem(P, P.Grado());
                        Q = Rem(Q, Q.Grado());
                    }
            }
            return C;
        }

        public clsPoly SMult(clsPoly P, float Coef, int Exp)
        {
            clsPoly C = new clsPoly();
            // Desarrollar
            if (P.IsZero())
                return Zero();

            for (int i = 0; i <= P.nTerm; i++)
            {
                C.vCoef[i] = P.vCoef[i] * Coef;
                C.vExp[i] = P.vExp[i] + Exp;
                C.nTerm++;
            }

            return C;
        }
        
        public override String ToString() 
        {
            String s1 = "F(x)={ ";
            for (int i = 0; i <= nTerm; i++)
            {
                if (i>0) {
                    if (i>1) s1 += " + " ;
                    s1 += Convert.ToString(vCoef[i]) + "X" + "^" + Convert.ToString(vExp[i]);
                }
            }
            return s1 + " }";
        }

        public void CrearPoly(int n)
        {
            for (int i = 0; i < n; i++)
            {
                vCoef[i] = i;
                vExp[i] = i;               
            }
            nTerm = n - 1;
         }
        public int NumeroTerminos()
        {
            return nTerm;
        }
       
        public clsPoly Mult(clsPoly P, clsPoly Q)
        {
            if (P.IsZero() || Q.IsZero())
                return Zero();
            clsPoly C = new clsPoly();
            int aux = 1;
            for (int i = 1; i <= P.NumeroTerminos(); i++ )
            {
                for (int j = 1; j <= Q.NumeroTerminos(); j++)
                {
                    C.vCoef[aux] = P.vCoef[i] * Q.vCoef[j];
                    C.vExp[aux] = P.vExp[i] + Q.vExp[j];
                    C.nTerm++; aux++;
                }
                
            }

            return C;
        }

    }
    
}
