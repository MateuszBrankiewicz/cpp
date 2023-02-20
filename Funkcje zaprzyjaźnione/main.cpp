#include <iostream>
#include "przyjaciele.h"
using namespace std;
void sedzia(Punkt pkt, Prostokat p){
    if((pkt.x>=p.x)&&(pkt.x<=p.x+p.szerokosc)&&(pkt.y>=p.y)&&(pkt.y<=p.y+p.wysokosc)) cout<<endl<<"Punkt: "<<pkt.nazwa<<" nalezy do porstokata "<<pkt.nazwa;
    else cout<<endl<<"Punkt: "<<pkt.nazwa<<" nie nalezy do porstokata "<<pkt.nazwa;
}
int main(){
    Punkt pk1("A",3,1);
    Prostokat p1("Prostokat",0,0,6,4);
}