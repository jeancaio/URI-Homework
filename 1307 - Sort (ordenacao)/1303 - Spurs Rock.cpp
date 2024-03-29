/* by elosilva */

#include<iostream> // fixed typo here
#include<algorithm>
#include<cstdio>
#include<iomanip>

using namespace std;

struct camp {
int id, p, g, e; /// p= pontos; g=pontos feitos (goals); e=erros=pontos contra;
double ca;  // (cesta average)
};

bool comp ( camp a ,camp b ){
    if ( a.p == b.p ){             // pontos =
        if ( a.ca != b.ca ){       //cesta average !=
            return a.ca > b.ca;
        }
        else {                    //cesta average = 
            if ( a.p != b.p ){    // pontos marcados !=
                return a.g > b.g; 
            }
            else{                 //pontos marcados =
                return a.id > b.id;
            }
        }
        }
    return a.p > b.p;
}

int main(){
    cout<<fixed<<setprecision(4);  //frescura da minha parte
    //freopen("1303.in","r",stdin);
    int n, m, a, b, x, y, cont=0;

    while ( cin>>n ){
        if ( n==0 ){break;}             // se n =0 então sai fora do while;
        camp time[n+1];
        cont++;                         //contador instâncias;
        if (cont>1){cout<<"\n";}        //se tiver 2 ou + instâncias deve-se separar os casos de teste com uma linha em branco
        cout<<"Instancia "<<cont<<endl;
        for ( int i=0 ; i<=n ; i++ ){    //zera a pontuação dos times para iniciar um novo teste e usar ex.: x+=y ou x++;
            time[i].id=i;                // definição do id;
            time[i].p=time[i].g=time[i].e=time[i].ca=0;
        }
        m=n*(n-1)/2;                    // calculo do numero de jogos
        for ( int i=0 ; i<m ; i++ ){   //entrada dos placares
            cin>>a>>x>>b>>y;
            time[a].g+=x;time[a].e+=y;   //atribuição de pontos
            time[b].g+=y;time[b].e+=x;
            if (x<y){time[a].p+=1;time[b].p+=2;}
            if (x>y){time[a].p+=2;time[b].p+=1;}
        }
        for ( int i=1 ; i<=n ; i++ ){   // calculo do CA
            if ( time[i].e==0 ){
                time[i].ca=time[i].p;
            }
            else {  // multipliquei por 0.0...1 para trabalhar com double, quando eu usava int não conseguia o resultado esperado;
                time[i].ca=(time[i].g*1.00000001)/(time[i].e*1.00000001); //ca tem que ser em double!
            }
        }
        sort( time+1, time+n+1, comp ); //sort
        for ( int i=1 ; i<n ; i++ ){   //cout do problema
            cout<<time[i].id<<" ";
        }
        cout<<time[n].id;
        cout<<"\n";
    }
    return 0;
}
